#ifndef __FILEGUI_H
#define __FILEGUI_H
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

#include "fileProvider.hpp"
#include "menuGUI.hpp"

void fileManager();
void fillMenuStatusWithClip(char* title, int itemsinclip, int ismanager);
int fileManagerSub(char* browserbasepath, int* itemsinclip, int* shownClipboardHelp, int* shownMainMemHelp, File* clipboard, char* filetoedit);
int deleteFilesGUI(File* files, Menu* menu);
int makeFolderGUI(char* browserbasepath);
int makeg3pGUI(char* browserbasepath);
int renameFileGUI(File* files, Menu* menu, char* browserbasepath);
int searchFilesGUI(char* browserbasepath, int itemsinclip);
int fileInformation(File* file, int allowEdit, int itemsinclip);
void fileViewAsText(char* filename);
void viewFilesInClipboard(File* clipboard, int *itemsinclip);
void folderStatistics(File* files, Menu* menu);
void compressSelectedFiles(File* files, Menu* menu);
void decompressSelectedFiles(File* files, Menu* menu);
void shortenDisplayPath(char* longpath, char* shortpath, int jump=1);
void buildIconTable(MenuItemIcon* icontable);

#endif