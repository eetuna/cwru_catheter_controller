/* Copyright 2017 Russell Jackson
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// @TODO(RCJ) If this header file is ever used outside of the arduino IDE,
// then add header guards

/* *************** */
/* pin definitions */
/* *************** */

// chip select (part of SPI) (DAC)
//int DAC_CS_pins[NCHANNELS] = {2, 3, 4, 5, 6, 7};
//int DAC_CS_pins[NCHANNELS] = {53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 44, 44, 44, 44, 44, 44}; //new design (16 channels)
int DAC_CS_pins[NCHANNELS] = {53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 44, 44, 44, 44, 44}; //new design (15 channels)


// chip select (part of SPI) (ADC)
//int ADC_CS_pins[NCHANNELS] = {8, 9, 10, 11, 12, 13};
int ADC_CS_pins[NCHANNELS] = {43, 42, 41, 40, 39, 38, 37, 36, 35}; //new design (16 channels)

// h-bridge enable pins
//int H_Enable_pins[NCHANNELS] = {22, 23, 24, 25, 26, 27};
//int H_Enable_pins [NCHANNELS] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 19, 18, 17, 16, 15, 14}; // new design (16 channels)
int H_Enable_pins [NCHANNELS] = {31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 19, 18, 17, 16, 15}; // new design (15 channels)

// H_ neg pins
<<<<<<< HEAD
int H_Neg_pins[NCHANNELS] = {28, 29, 30, 31, 32, 33};

// H_pos pins
int H_Pos_pins[NCHANNELS] = {34, 35, 36, 37, 38, 39};

=======
//int H_Neg_pins[NCHANNELS] = {28, 29, 30, 31, 32, 33};

// H_pos pins
//int H_Pos_pins[NCHANNELS] = {34, 35, 36, 37, 38, 39}; 

// H_dir pins
int H_dir_pins[NCHANNELS] = {5, 6, 7, 8, 9, 10, 11, 12, 13}; // new design. (16 channels)
>>>>>>> aaa2482c71985827747533bb44620667e398f113

// DAC buffer load pins
// (held low auto loads input buffer) (high to low loads input buffer).
//int DAC_LDAC_pins[NCHANNELS] = {46, 47, 48, 49, 50, 51};
//int DAC_LDAC_pins[NCHANNELS] = {58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 67, 67, 67, 67 ,67, 67}; // new design. (16 channels)
int DAC_LDAC_pins[NCHANNELS] = {58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 67, 67, 67, 67, 67}; // new design. (15 channels)

// Camera data pins (outputs)
//int CAMERA_PINS[3] = {64, 63, 62};
int CAMERA_PINS[3] = {55, 56, 57}; //new design. (16 channels)

// MRI pin (Input)
//int mriPin = 65;
int mriPin = 54; //new design. (16 channels)
