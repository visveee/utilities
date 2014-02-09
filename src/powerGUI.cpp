#include <fxcg/display.h>
#include <fxcg/file.h>
#include <fxcg/keyboard.h>
#include <fxcg/system.h>
#include <fxcg/misc.h>
#include <fxcg/app.h>
#include <fxcg/serial.h>
#include <fxcg/rtc.h>
#include <fxcg/heap.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "powerGUI.hpp"
#include "menuGUI.hpp"
#include "hardwareProvider.hpp"
#include "keyboardProvider.hpp"
#include "graphicsProvider.hpp"
#include "timeProvider.hpp"
#include "timeGUI.hpp"
#include "settingsProvider.hpp"
#include "settingsGUI.hpp" 
#include "selectorGUI.hpp"
#include "textGUI.hpp"
#include "sprites.h"

void changePoweroffTimeout() {
  Selector sel;
  strcpy(sel.title, "Poweroff Timeout");
  strcpy(sel.subtitle, "");
  sel.value = GetAutoPowerOffTime();
  sel.min = 1;
  sel.max = 999;
  sel.cycle = 0;
  sel.type = SELECTORTYPE_TIMEOUT_MINUTES;
  int res = doSelector(&sel);
  if (res == SELECTOR_RETURN_EXIT) return;
  SetAutoPowerOffTime(sel.value);
}

void changeBacklightTimeout() {
  Selector sel;
  strcpy(sel.title, "Backlight Duration");
  strcpy(sel.subtitle, "");
  sel.value = GetBacklightDuration();
  sel.min = 1;
  sel.max = 40;
  sel.type = SELECTORTYPE_BACKLIGHT_DURATION;
  int res = doSelector(&sel);
  if (res == SELECTOR_RETURN_EXIT) return;
  SetBacklightDuration(sel.value);
}

void changeBacklightLevel() {
  int initValue = GetBacklightSubLevel_RAW();
  Selector sel;
  strcpy(sel.title, "Backlight Level");
  strcpy(sel.subtitle, "");
  sel.value = initValue;
  sel.max = 249;
  sel.type = SELECTORTYPE_INSTANT_RETURN;
  sel.clearVRAM = 0;
  
  Bdisp_AllClr_VRAM();
  /*int textX=0; int textY=150;
  PrintMiniMini( &textX, &textY, (unsigned char*)"This setting is volatile because it is changed by the OS on", 0, TEXT_COLOR_BLACK, 0 );
  textY=textY+12; textX=0;
  PrintMiniMini( &textX, &textY, (unsigned char*)"poweroff, on backlight timeout and when the user changes", 0, TEXT_COLOR_BLACK, 0 );
  textY=textY+12; textX=0;
  PrintMiniMini( &textX, &textY, (unsigned char*)"the setting in the OS's System menu.", 0, TEXT_COLOR_BLACK, 0 );*/
  textArea text;
  text.type = TEXTAREATYPE_INSTANT_RETURN;
  text.showtitle = 0;
  text.y = 150;
  text.lineHeight=12;
  textElement elem[2];
  text.elements = elem;
  text.scrollbar=0;
  
  elem[0].text = (char*)"This setting is volatile because it is changed by the OS on poweroff, on backlight timeout and when the user changes the setting in the OS's System menu.";
  elem[0].minimini = 1;
  text.numelements = 1;
  doTextArea(&text);
  while(1) {
    switch(doSelector(&sel)) {
      case SELECTOR_RETURN_EXIT:
        SetBacklightSubLevel_RAW(initValue);
        //deliberate fallthrough: bl level was already set with the instant return, so if user is confirming, just return.
      case SELECTOR_RETURN_SELECTION:
        return;
      case SELECTOR_RETURN_INSTANT:
        SetBacklightSubLevel_RAW(sel.value);
        break;
    }
  }
}

void powerInformation() {
  unsigned int backlightlevel = GetBacklightSubLevel_RAW();
  volatile unsigned int*FRQCR = (unsigned int*) 0xA4150000;
  unsigned char voltbuffer[20];
  itoa(GetMainBatteryVoltage(1), voltbuffer);
  // We are gonna have fuuuuuun!
  memmove(voltbuffer+2, voltbuffer+1, 3);
  voltbuffer[1] = '.';
  strcat((char*)voltbuffer, "V");
  
  textArea text;
  strcpy(text.title, (char*)"Power Information");
  text.showtitle=1;

  textElement elem[16];
  text.elements = elem;
  text.scrollbar=0;
  
  elem[0].text = (char*)"Battery voltage:";
  elem[0].spaceAtEnd = 1;
  elem[1].text = (char*)voltbuffer;
  
  elem[2].newLine = 1;
  elem[2].color = COLOR_GRAY;
  elem[2].text = (char*)"Note: battery voltage is inaccurate when the power source is USB.";
  
  elem[3].newLine = 1;
  elem[3].text = (char*)"Power source:";
  elem[3].spaceAtEnd = 1;
  int key = *(unsigned char*)P11DR;
  if (key==0x0000) {
    elem[4].text = (char*)"Emulated";
  } else if (key==0x0008) {
    elem[4].text = (char*)"Batteries";
  } else if (key==0x000A) {
    elem[4].text = (char*)"USB";
  } else {
    elem[4].text = (char*)"Unknown";
  }
  
  elem[5].newLine = 1;
  elem[5].text = (char*)"Battery type setting:";
  elem[5].spaceAtEnd = 1;
  
  if (GetBatteryType()==1) {
    elem[6].text = (char*)"Alkaline";
  } else if (GetBatteryType()==2) {
    elem[6].text = (char*)"Ni-MH";
  } else {
    elem[6].text = (char*)"Not defined";
  }
  
  elem[7].newLine = 1;
  elem[7].text = (char*)"Screen backlight level:";
  elem[7].spaceAtEnd = 1;
  
  unsigned char blevel[5];
  itoa(backlightlevel, blevel);
  elem[8].text = (char*)blevel;

  elem[9].newLine = 1;
  elem[9].text = (char*)"Backlight timeout:";
  elem[9].spaceAtEnd = 1;
  char btimeout[20] = "";
  int btimeoutval = GetBacklightDuration();
  if(btimeoutval % 2 == 0) { //even, so timeout is X min 0 sec.
    itoa(btimeoutval/2, (unsigned char*)btimeout);
  } else { // timeout is X min 30 sec.
    itoa((btimeoutval-1)/2, (unsigned char*)btimeout);
  }
  strcat(btimeout, " Minutes");
  if(btimeoutval % 2 != 0) strcat(btimeout, " 30 Sec.");
  elem[10].text = btimeout;

  elem[11].newLine = 1;
  elem[11].text = (char*)"Power off timeout:";
  elem[11].spaceAtEnd = 1;
  char ptimeout[20] = "";
  itoa(GetAutoPowerOffTime(), (unsigned char*)ptimeout);
  strcat(ptimeout, " Minutes");
  elem[12].text = ptimeout;
  
  elem[13].newLine = 1;
  elem[13].text = (char*)"CPU clock:";
  elem[13].spaceAtEnd = 1;
  switch((*FRQCR & 0x3F000000) >> 24) {
    case PLL_28x: elem[14].text = (char*)"101.5"; break;
    case PLL_26x: elem[14].text = (char*)"94.3"; break;
    case PLL_24x: elem[14].text = (char*)"87"; break;
    case PLL_20x: elem[14].text = (char*)"72.5"; break;
    case PLL_18x: elem[14].text = (char*)"65.3"; break;
    case PLL_16x: elem[14].text = (char*)"58"; break;
    case PLL_15x: elem[14].text = (char*)"54.4"; break;
    case PLL_12x: elem[14].text = (char*)"43.5"; break;
    case PLL_8x: elem[14].text = (char*)"29"; break;
    case PLL_6x: elem[14].text = (char*)"21.7"; break;
    case PLL_4x: elem[14].text = (char*)"14.5"; break;
    case PLL_3x: elem[14].text = (char*)"10.8"; break;
    case PLL_2x: elem[14].text = (char*)"7.25"; break;
    case PLL_1x: elem[14].text = (char*)"3.6"; break;
    default: elem[14].text = (char*)"Unknown"; break;
  }
  elem[14].spaceAtEnd = 1;
  elem[15].text = (char*)"MHz";
  text.numelements = 16;
  doTextArea(&text);
}
const unsigned int PLLs[] = {PLL_1x, PLL_2x, PLL_3x, PLL_4x, PLL_6x, PLL_8x, PLL_12x, PLL_15x, PLL_16x, PLL_18x, PLL_20x, PLL_24x, PLL_26x, PLL_28x};
void updateCurrentFreq() {
  // this does not draw the VRAM contents to screen, only changes them!
  char*cur = 0x00000000;
  char*desc = 0x00000000;
  volatile unsigned int*FRQCR = (unsigned int*) 0xA4150000;
  
  int arrowBottom = 84;
  
  //Clear area where the cursor arrow appears
  drawRectangle(0, 65, 384, 20, COLOR_WHITE);
  
  switch((*FRQCR & 0x3F000000) >> 24) {
    case PLL_28x:
      cur = (char*)"101.5";
      desc = (char*)"Overclocked";
      break;
    case PLL_26x:
      cur = (char*)"94.3";
      desc = (char*)"Overclocked";
      drawArrowDown(368, arrowBottom, COLOR_ORANGE);
      break;
    case PLL_24x:
      cur = (char*)"87";
      desc = (char*)"Overclocked";
      drawArrowDown(331, arrowBottom, COLOR_ORANGE);
      break;
    case PLL_20x:
      cur = (char*)"72.5";
      desc = (char*)"Overclocked";
      drawArrowDown(274, arrowBottom, COLOR_ORANGE);
      break;
    case PLL_18x:
      cur = (char*)"65.3";
      desc = (char*)"Overclocked";
      drawArrowDown(246, arrowBottom, COLOR_ORANGE);
      break;
    case PLL_16x:
      cur = (char*)"58";
      desc = (char*)"Normal speed";
      drawArrowDown(217, arrowBottom, COLOR_LIMEGREEN);
      break;
    case PLL_15x:
      cur = (char*)"54.4";
      desc = (char*)"Underclocked";
      drawArrowDown(203, arrowBottom, COLOR_LIGHTBLUE);
      break;
    case PLL_12x:
      cur = (char*)"43.5";
      desc = (char*)"Underclocked";
      drawArrowDown(169, arrowBottom, COLOR_LIGHTBLUE);
      break;
    case PLL_8x:
      cur = (char*)"29";
      desc = (char*)"Underclocked";
      drawArrowDown(112, arrowBottom, COLOR_LIGHTBLUE);
      break;
    case PLL_6x:
      cur = (char*)"21.7";
      desc = (char*)"Underclocked";
      drawArrowDown(84, arrowBottom, COLOR_LIGHTBLUE);
      break;
    case PLL_4x:
      cur = (char*)"14.5";
      desc = (char*)"Underclocked";
      drawArrowDown(56, arrowBottom, COLOR_LIGHTBLUE);
      break;
    case PLL_3x:
      cur = (char*)"10.8";
      desc = (char*)"Underclocked";
      drawArrowDown(41, arrowBottom, COLOR_LIGHTBLUE);
      break;
    case PLL_2x:
      cur = (char*)"7.25";
      desc = (char*)"Underclocked";
      drawArrowDown(27, arrowBottom, COLOR_LIGHTBLUE);
      break;
    case PLL_1x:
      cur = (char*)"3.6";
      desc = (char*)"Underclocked";
      drawArrowDown(13, arrowBottom, COLOR_LIGHTBLUE);
      break;
    default:
      cur = (char*)"UNKNOWN";
      desc = (char*)"???";
      break;
  }
  int textX = 0; int textY = 145;
  char buffer[50] = "";
  strcpy(buffer, (char*)"Running at ");
  strcat(buffer, cur);
  strcat(buffer, (char*)" MHz");
  PrintMini(&textX, &textY, (unsigned char*)buffer, 0, 0xFFFFFFFF, 0, 0, COLOR_BLACK, COLOR_WHITE, 1, 0);
  mPrintXY(1, 8, desc, TEXT_MODE_TRANSPARENT_BACKGROUND, TEXT_COLOR_BLACK);
}

void setCPUclock() {
  int key; int textX; int textY;

  volatile unsigned int*FRQCR = (unsigned int*) 0xA4150000;
  while (1) {
    Bdisp_AllClr_VRAM();

    mPrintXY(1, 1, (char*)"CPU speed", TEXT_MODE_TRANSPARENT_BACKGROUND, TEXT_COLOR_BLUE);
    CopySpriteNbit(selector, 10, 85, 364, 43, selector_palette, 1);
    
    textX=0; textY=118;
    PrintMiniMini( &textX, &textY, (unsigned char*)"USE AT YOUR OWN RISK! NO WARRANTY PROVIDED.", 0, TEXT_COLOR_RED, 0 );
    textX=0; textY=130;
    PrintMiniMini( &textX, &textY, (unsigned char*)"Note: changes are applied instantly.", 0, TEXT_COLOR_BLACK, 0 );
    
    updateCurrentFreq();
    mGetKey(&key);
    switch (key) {
      case KEY_CTRL_RIGHT:      
      case KEY_CTRL_UP:
         for(int i = 0; i < 12; i++) {
          if(((*FRQCR & 0x3F000000) >> 24) == PLLs[i]) {
            CPU_change_freq(PLLs[i+1]);
            break;
          }
        }
         break;
      case KEY_CTRL_LEFT:
      case KEY_CTRL_DOWN:
        for(int i = 1; i < 14; i++) {
          if(((*FRQCR & 0x3F000000) >> 24) == PLLs[i]) {
            CPU_change_freq(PLLs[i-1]);
            break;
          }
        }
        break;
      case KEY_CTRL_EXIT:
      case KEY_CTRL_EXE:
        return;
        break;
    }
  }
}