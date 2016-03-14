/* 
 * simpleUpload Display Demo
 * 
 * Send a RAW picture to the ILI9341 Display via commandline
 * 
 * 
 * For Windows:
 * 
 * - close the serial Monitor
 * - open a command-prompt (press "start" and enter CMD)
 * 
 * edit & run the batch file :
 * 
 * sendfile teensy.raw
 * 
 * DONT FORGET TO CLOSE THE SERIAL MONITOR 
 * 
 * (c) F.Boesing, 2016 
 * LICENCE: MIT
 */

#include "simpleUpload.h"
#include "tower.h"
#include "SPI.h"
#include "ILI9341_t3.h"

// Normal Connections
//#define TFT_DC       9
//#define TFT_CS      10
//#define TFT_RST    255  // 255 = unused, connect to 3.3V
//#define TFT_MOSI    11
//#define TFT_SCLK    13
//#define TFT_MISO    12

// Alternate Connections with Teensy Audio Shield
//#define TFT_DC      20
//#define TFT_CS      21
//#define TFT_RST    255  // 255 = unused, connect to 3.3V
//#define TFT_MOSI     7
//#define TFT_SCLK    14
//#define TFT_MISO    12

ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO);
  uint16_t line[321];
  
void picture(void) {
  int m = millis();
  int x = 0;
  int y = 0;
  int a; 
    tft.fillScreen(ILI9341_RED);  
    for (;;) {   
     a = Serial.available();  
     if (a > 63) { 
       do {     
          line[x] = (Serial.read()<<8) | Serial.read();    
          x++;          
          if (x > 319) {      
            x=0;                              
            tft.writeRect(0,y,320,1,line);            
            y++;
           if (y > 239) return;
          }        
          a = a -2;
       } while (a);
       m = millis(); 
     } else {        
       if (millis()-m > 1500) return;
       yield();
    }
  }
}

void setup() {
   initTower();
   tft.begin();
   tft.setRotation(3);
   tft.fillScreen(ILI9341_BLACK);   
   simpleUploadListen(1,picture);
}

void loop() {
  simpleUpload(true);
} 

