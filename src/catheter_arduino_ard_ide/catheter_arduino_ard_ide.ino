/**************************************************************************
   Copyright {2016} {Dr. Russell C Jackson}

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <SPI.h>
#include "ard_due_defs.h"
#include "pin_defs.h"
#include "arduino_hardware.h"
#include "spi_com.h"
#include "serial_com_ard.h"
#include "cmd_support.h"
#include "cmd_parse.h"


/**
 * @brief Individual channel statuses.
 */
channelStatus channelList[NCHANNELS];


/**
 * @brief Bytes read in by the Arduino serial bus.
 */
uint8_t inputBytes[512];

/**
 * @brief Bytes returned from the Arduino serial bus.
 */
uint8_t outputBytes[512];

/**
 * @brief Used for writing data to the camera GPIO.
 *
 * Indexed from 0 to 3. The GPIO bus width is 2 bits.
 */
unsigned int camera_counter;

///**
// * @brief The previous MRI imaging status.
// *
// * The MRI indicates imaging by setting an input pin.
// */
//bool mriStatOld;

/**
 * @brief The MR scanning duration in which the currents are turned off.
 * 
 * The duration is defined in scan lines.
 */
double scanLines = 4;

volatile unsigned long scanStartTime;
unsigned long scanDuration;

/**
 * @brief The interrupt handler is meant to always ensure that the current is disabled.
 */
void disableChannels()
{
  scanStartTime = millis(); // milliseconds this has been running 
  for (int i = 0; i < NCHANNELS; i++)
    {
<<<<<<< HEAD
      set_enable(i, !H_EN);
=======
      set_enable(i, !H_EN); // turns H bridge enable channels  to low 
>>>>>>> aaa2482c71985827747533bb44620667e398f113
    }
  isScanning = true;  
}

/**
 * @brief The Arduino executes this function once when power on.
 */
void setup()
{
	pin_init(); // sets up pins.
	SPI_init(); // turns on SPI
	serial_init(); // 
	camera_counter = 0; // outdated maybe. 
  isScanning = false; // 
  //mriStatOld = false;

  // Here, the scanLines is converted to ms.
  // Each line takes 2.88 ms.
  // Also, the scan duration includes a 0.5 ms delay to wait for the current to be completely turned off
  scanDuration = ceil(scanLines*2.88+0.5);

  for ( int i = 0; i < 512; i++)
  {
    inputBytes[i] = 0;
    outputBytes[i] = 0;
  }

  attachInterrupt(mriPin, disableChannels, RISING); // attachInterrupt(pin,ISR,Mode) (not usually recommended, ISR is a function 

	delay(START_DELAY); // delay of 500 millisecons. 
}

/**
 * @brief The Arduino runs this function repeatedly.
 */
void loop()
{
  if(serial_available())
  {
    uint8_t counter = (uint8_t) serial_available(); // returns number of bytes from input
    uint8_t packetSize = read_bytes( inputBytes, counter); // how long is the bytes
    uint8_t packetIndex(0); 
    uint8_t cmdCount(0);

    // when data is available parse it.
    //If the parsing passes the checksum, then it is acted on.
    //checks if the data was transmitted and received correctly 
    
    if(cmd_check(inputBytes, packetSize, &packetIndex, &cmdCount))
    {
      camera_counter = camera_counter + 1; // not a thing


      uint8_t outputLength(0);
      // This function no longer actually changes
      outputLength = cmd_parse(inputBytes, packetSize, cmdCount, channelList,outputBytes, packetIndex);
      write_bytes(outputBytes, outputLength);
    }
    else
    {
      writeError(packetIndex);
    }
  }

  // Get MR Status.
  // TODO: The MR status should be set in a different function.
  int mriStat(camera_write(camera_counter));

  // If the MR scanner is pinging.

  // If the MR scanner is neither pinging or scanning.
  if (scanStartTime > 0 && (scanStartTime + scanDuration) <  millis())
  {
    scanStartTime = 0;
    for (int i = 0; i  < NCHANNELS; i++)
    {
      set_direction(i,channelList[i].dir);
      set_enable(i, H_EN);
    }
    isScanning = false;
  }
}

