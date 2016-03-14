/* 
 * simpleUpload minimal demo This one does NOT upload, but can switch the LED on and off
 * 
 * send 0x01 or 0x02 to the serial with a tool of your choice.
 * you can use the commandline too:
 * 
 * For Windows:
 * 
 * - close the serial Monitor
 * - open a command-prompt (press "start" and enter CMD)
 * 
 * Enter:
 * mode %dev%:data=8 to=off xon=off odsr=off octs=off dtr=off rts=off idsr=off
 * (replace %dev% with your comport - for example COM6:
 * mode COM6:data=8 to=off xon=off odsr=off octs=off dtr=off rts=off idsr=off
 * )
 * 
 * Enter:
 * echo ^A > %dev% 
 * or
 * echo ^B > %dev% 
 * to switch the LED on or off.
 * (HINT: Press ALT and 001 or ALT and 002 on the num-pad to get the right code)
 * 
 * For convienience, see the batchfiles which come with this example - just edit the line "set dev = COM3" to your comport.
 * 
 * DONT FORGET TO CLOSE THE SERIAL MONITOR 
 * 
 * (c) F.Boesing, 2016 
 * LICENCE: MIT
 */

#include "simpleUpload.h"

void ledOn(void) { digitalWrite(13,1); }  
void ledOff(void) { digitalWrite(13,0); } 

void setup() {
   pinMode(13, OUTPUT);
   ledOn();
   simpleUploadListen(1,ledOn);
   simpleUploadListen(2,ledOff);
}

void loop() {
  simpleUpload();
} 

