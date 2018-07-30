# Arduino serial communication bus:

This guide is meant to elaborate on the arduino serial communication protocol:

# PC to Arduino:

    - Groups of commands sent in packets of (1 - NCHANNELS) commands
    - If a channel does not need to change, no command is sent for it
    - Global commands are represented by Channel#0

    - Packet Structure:
        byte 1: bit 1 set indicates a packet is OK and starting
        byte 1: bits 2->4 store the packet index (mod 8)
        byte 1: bits 5->8 store the number of commands to follow (up to 15)
        
        bytes 2->N-2: Channel Commands (repeated as needed)
    
	    - Channel Command Structure:
        byte A: bits 1->4 store the channel
        byte A: bits 5->8 store the command value
        - Command Value:
            MSB{ <poll? bit> <enable? bit> <update? bit> <direction? bit> }LSB
            poll: 1 := send back current value read from ADC 
            enable: 0 := deactivate this channel (equivalent-ish to sending 0 milliamps)
            update: 1 := update the H-bridge direction, but do not necessarily activate the channel
                (enable=1 --> update=1, update=1 -/-> enable=1)
        direction: 0 := negative direction
        byte B: stores the first 8 bits of DAC data
        byte C: bits 1->4 store the last 4 bits of DAC data
        byte C: bits 5->8 unused 

        byte N-1: bits 1->3 store the packet index (mod 8)
        btye N-1: bits 4->7 unused
        byte N-1: bit 8 set indicates packet is OK
        byte N: 8-bit Fletcher checksum



# Arduino to PC:

    - Send a response for each channel command received.
    - Global commands: send a response for each affected channel.
    - All bits are MSB
    - The number of bytes N = 4 + 3 * commands + 2 * polls. where polls < commands.

    -Packet form:
        byte 1: bit 1 set indicates that this is the beginning of a message
        byte 1: bit 2 set indicates that the command was executed successfully (no error)
        byte 1: bits 6->8 store the packet index (mod 8)
        byte 2: Repeats Byte 1
		byte 3: bits 1-4: indicates the number of commands being sent back.
		byte 3: bits 5-8: indicate how many of those commands also have a poll.
		
		At this point multiple Channel commands are sent.
        byte A: bits 1-4: channel number
        byte A: bits 5-8: command value (indicates if a poll is present)
		byte B: bits 1-2: don't care
		byte B: bits 3-8: MSB 6 bits of the DAC.
		byte C: bits 1-2: don't care
		byte C: bits 3-8: LSB 6 bits of the DAC.
		(Bytes D and E are only present if the Poll option is high)
		bits D: bit 1: don't care. (Set to zero) 
        bits D: bit 2: When this bit is high, there is an error in reading the ADC. 
		bits D: bits 3-8: MSB of ADC.
		bits E: bits 1-2: don't care. (Set to zero)
		bits E: bits 3-8: LSB of ADC.


        Byte N : 8 bit Fletcher checksum. (block size of 4)
        Byte N+1: A set of zero vector to avoid potential command overlap.




