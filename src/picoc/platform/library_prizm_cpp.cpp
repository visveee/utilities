extern "C" {
#include "../interpreter.h"
#include "../picoc.h"
}

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

#include "../../aboutGUI.hpp"
#include "../../calendarGUI.hpp"
#include "../../calendarProvider.hpp"
#include "../../chronoGUI.hpp"
#include "../../chronoProvider.hpp"
#include "../../editorGUI.hpp"
#include "../../fileGUI.hpp"
#include "../../fileProvider.hpp"
#include "../../firstRunGUI.hpp"
#include "../../graphicsProvider.hpp"
#include "../../hardwareProvider.hpp"
#include "../../homeGUI.hpp"
#include "../../imageGUI.hpp"
#include "../../inputGUI.hpp"
#include "../../keyboardProvider.hpp"
#include "../../lightGUI.hpp"
#include "../../lockGUI.hpp"
#include "../../lockProvider.hpp"
#include "../../memsysGUI.hpp"
#include "../../powerGUI.hpp"
#include "../../selectorGUI.hpp"
#include "../../settingsGUI.hpp"
#include "../../settingsProvider.hpp"
#include "../../stringsProvider.hpp"
#include "../../tasksGUI.hpp"
#include "../../textGUI.hpp"
#include "../../textEditGUI.hpp"
#include "../../timeGUI.hpp"
#include "../../timeProvider.hpp"
#include "../../toolsGUI.hpp"
#include "../../toolsProvider.hpp"
#include "../../versionProvider.hpp"

#define pcfunc(x) picoc_##x
#define pcvoid(x) void pcfunc(x)

extern "C" void PrizmSetupFunc();

// APP

pcvoid(APP_FINANCE)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_FINANCE(Param[0]->Val->Integer, Param[0]->Val->Integer);
}

pcvoid(APP_SYSTEM_BATTERY)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_SYSTEM_BATTERY(Param[0]->Val->Integer);
}

pcvoid(APP_SYSTEM_DISPLAY)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_SYSTEM_DISPLAY(Param[0]->Val->Integer);
}

pcvoid(APP_SYSTEM_LANGUAGE)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_SYSTEM_LANGUAGE(Param[0]->Val->Integer);
}

pcvoid(APP_SYSTEM_POWER)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_SYSTEM_POWER(Param[0]->Val->Integer);
}

pcvoid(APP_SYSTEM_RESET)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_SYSTEM_RESET();
}

pcvoid(APP_SYSTEM_VERSION)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_SYSTEM_VERSION();
}

pcvoid(APP_SYSTEM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_SYSTEM();
}

pcvoid(APP_RUNMAT)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_RUNMAT(Param[0]->Val->Integer, Param[0]->Val->Integer);
}

pcvoid(APP_MEMORY)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_MEMORY();
}

pcvoid(App_Optimize)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    App_Optimize();
}

pcvoid(ResetAllDialog)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ResetAllDialog();
}

pcvoid(GetAppName)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = GetAppName((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(App_InitDlgDescriptor)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    App_InitDlgDescriptor(Param[0]->Val->Pointer, Param[1]->Val->Character);
}

pcvoid(APP_LINK_transmit_select_dialog)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_LINK_transmit_select_dialog(Param[0]->Val->Pointer, Param[1]->Val->Pointer);
}

// DISPLAY

pcvoid(Bdisp_AreaClr)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    struct display_fill* df = (struct display_fill*)Param[0]->Val->Pointer;
    Bdisp_AreaClr(df, Param[1]->Val->Character, Param[2]->Val->UnsignedShortInteger);
}

pcvoid(Bdisp_EnableColor)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_EnableColor(Param[0]->Val->Integer);
}

pcvoid(DrawFrame)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DrawFrame(Param[0]->Val->Integer);
}

pcvoid(FrameColor)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->UnsignedShortInteger = FrameColor(Param[0]->Val->Integer, Param[1]->Val->UnsignedShortInteger);
}

pcvoid(DrawFrameWorkbench)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DrawFrameWorkbench(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(GetVRAMAddress)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = GetVRAMAddress();
}

pcvoid(Bdisp_AllClr_VRAM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_AllClr_VRAM();
}

pcvoid(Bdisp_SetPoint_VRAM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_SetPoint_VRAM(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(Bdisp_SetPointWB_VRAM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_SetPointWB_VRAM(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(Bdisp_GetPoint_VRAM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->UnsignedShortInteger = Bdisp_GetPoint_VRAM(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(SaveVRAM_1)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SaveVRAM_1();
}

pcvoid(LoadVRAM_1)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    LoadVRAM_1();
}

pcvoid(Bdisp_Fill_VRAM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_Fill_VRAM(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(Bdisp_AreaClr_DD_x3)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_AreaClr_DD_x3(Param[0]->Val->Pointer);
}

pcvoid(Bdisp_DDRegisterSelect)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_DDRegisterSelect(Param[0]->Val->Integer);
}

pcvoid(Bdisp_PutDisp_DD)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_PutDisp_DD();
}

pcvoid(Bdisp_PutDisp_DD_stripe)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_PutDisp_DD_stripe(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(Bdisp_SetPoint_DD)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_SetPoint_DD(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(Bdisp_GetPoint_DD_Workbench)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->UnsignedShortInteger = Bdisp_GetPoint_DD_Workbench(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(Bdisp_GetPoint_DD)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->UnsignedShortInteger = Bdisp_GetPoint_DD(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(DirectDrawRectangle)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DirectDrawRectangle(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->UnsignedShortInteger);
}

pcvoid(HourGlass)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    HourGlass();
}

pcvoid(Bdisp_WriteGraphVRAM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    struct display_graph* dg = (struct display_graph*)Param[0]->Val->Pointer;
    Bdisp_WriteGraphVRAM(dg);
}

pcvoid(Bdisp_WriteGraphDD_WB)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    struct display_graph* dg = (struct display_graph*)Param[0]->Val->Pointer;
    Bdisp_WriteGraphDD_WB(dg);
}

pcvoid(Bdisp_ShapeBase3XVRAM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_ShapeBase3XVRAM(Param[0]->Val->Pointer);
}

pcvoid(Bdisp_ShapeBase)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_ShapeBase((unsigned char*)Param[0]->Val->Pointer, (struct display_shape*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer);
}

pcvoid(Bdisp_ShapeToVRAM16C)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_ShapeToVRAM16C(Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(Bdisp_ShapeToDD)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_ShapeToDD(Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(SetBackGround)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SetBackGround(Param[0]->Val->Integer);
}

pcvoid(WriteBackground)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    WriteBackground(Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Pointer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer);
}

pcvoid(Box)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Box(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(BoxInnerClear)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    BoxInnerClear(Param[0]->Val->Integer);
}

pcvoid(Box2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Box2(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(BoxYLimits)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    BoxYLimits(Param[0]->Val->Integer, (int*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer);
}

pcvoid(AUX_DisplayErrorMessage)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    AUX_DisplayErrorMessage(Param[0]->Val->Integer);
}

pcvoid(MsgBoxPush)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    MsgBoxPush(Param[0]->Val->Integer);
}

pcvoid(MsgBoxPop)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    MsgBoxPop();
}

pcvoid(DisplayMessageBox)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DisplayMessageBox((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(CharacterSelectDialog)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->ShortInteger = CharacterSelectDialog();
}

pcvoid(ColorIndexDialog1)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Character = ColorIndexDialog1(Param[0]->Val->Character, Param[1]->Val->UnsignedShortInteger);
}

pcvoid(MsgBoxMoveWB)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    MsgBoxMoveWB(Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer);
}

pcvoid(locate_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    locate_OS(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(Cursor_SetFlashOn)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Cursor_SetFlashOn(Param[0]->Val->Character);
}

pcvoid(Cursor_SetFlashOff)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Cursor_SetFlashOff();
}

pcvoid(SetCursorFlashToggle)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = SetCursorFlashToggle(Param[0]->Val->Integer);
}

pcvoid(Keyboard_CursorFlash)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Keyboard_CursorFlash();
}

pcvoid(PrintLine)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintLine((const char*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(PrintLine2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintLine2(Param[0]->Val->Integer, Param[1]->Val->Integer, (const char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer);
}

pcvoid(PrintXY_2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintXY_2(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(PrintXY)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintXY(Param[0]->Val->Integer, Param[1]->Val->Integer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(PrintCXY)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintCXY(Param[0]->Val->Integer, Param[1]->Val->Integer, (const char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer);
}

pcvoid(PrintGlyph)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintGlyph(Param[0]->Val->Integer, Param[1]->Val->Integer, (unsigned char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer);
}

pcvoid(GetMiniGlyphPtr)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = GetMiniGlyphPtr(Param[0]->Val->UnsignedShortInteger, (unsigned short*)Param[1]->Val->Pointer);
}

pcvoid(PrintMiniGlyph)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintMiniGlyph(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer, Param[9]->Val->Integer, Param[10]->Val->Integer, Param[11]->Val->Integer);
}

pcvoid(PrintMini)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintMini((int*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (const char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->UnsignedInteger, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer, Param[9]->Val->Integer, Param[10]->Val->Integer);
}

pcvoid(PrintMiniMini)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PrintMiniMini((int*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (const char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer);
}

pcvoid(Print_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Print_OS((const char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(Bdisp_WriteSystemMessage)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_WriteSystemMessage(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(Bdisp_MMPrintRef)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_MMPrintRef(
        (int*)Param[0]->Val->Pointer,
        (int*)Param[1]->Val->Pointer,
        (unsigned char*)Param[2]->Val->Pointer,
        Param[3]->Val->Integer,
        Param[4]->Val->Integer,
        Param[5]->Val->Integer,
        Param[6]->Val->Integer,
        Param[7]->Val->Integer,
        Param[8]->Val->Integer,
        Param[9]->Val->Integer,
        Param[10]->Val->Integer);
}

pcvoid(Bdisp_MMPrint)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_MMPrint(
        Param[0]->Val->Integer,
        Param[1]->Val->Integer,
        (unsigned char*)Param[2]->Val->Pointer,
        Param[3]->Val->Integer,
        Param[4]->Val->Integer,
        Param[5]->Val->Integer,
        Param[6]->Val->Integer,
        Param[7]->Val->Integer,
        Param[8]->Val->Integer,
        Param[9]->Val->Integer,
        Param[10]->Val->Integer);
}

pcvoid(Scrollbar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Scrollbar((struct scrollbar*)Param[0]->Val->Pointer);
}

pcvoid(StandardScrollbar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    StandardScrollbar(Param[0]->Val->Pointer);
}

pcvoid(ProgressBar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ProgressBar(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(ProgressBar0)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ProgressBar0(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(ProgressBar2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ProgressBar2((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(DefineStatusAreaFlags)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = DefineStatusAreaFlags(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Pointer, Param[3]->Val->Pointer);
}

pcvoid(DefineStatusGlyph)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DefineStatusGlyph(Param[0]->Val->Integer, Param[1]->Val->Pointer);
}

pcvoid(DefineStatusMessage)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DefineStatusMessage((char*)Param[0]->Val->Pointer, Param[1]->Val->ShortInteger, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(DisplayStatusArea)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DisplayStatusArea();
}

pcvoid(DrawHeaderLine)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DrawHeaderLine();
}

pcvoid(EnableStatusArea)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    EnableStatusArea(Param[0]->Val->Integer);
}

pcvoid(Bdisp_HeaderFill)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_HeaderFill(Param[0]->Val->Character, Param[1]->Val->Character);
}

pcvoid(Bdisp_HeaderFill2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_HeaderFill2(Param[0]->Val->UnsignedInteger, Param[1]->Val->UnsignedInteger, Param[2]->Val->Character, Param[3]->Val->Character);
}

pcvoid(Bdisp_HeaderText)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_HeaderText();
}

pcvoid(Bdisp_HeaderText2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bdisp_HeaderText2();
}

pcvoid(EnableDisplayHeader)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    EnableDisplayHeader(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(APP_EACT_StatusIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    APP_EACT_StatusIcon(Param[0]->Val->Integer);
}

pcvoid(SetupMode_StatusIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SetupMode_StatusIcon();
}

pcvoid(d_c_Icon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    d_c_Icon(Param[0]->Val->UnsignedInteger);
}

pcvoid(BatteryIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    BatteryIcon(Param[0]->Val->UnsignedInteger);
}

pcvoid(KeyboardIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    KeyboardIcon(Param[0]->Val->UnsignedInteger);
}

pcvoid(LineIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    LineIcon(Param[0]->Val->UnsignedInteger);
}

pcvoid(NormIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    NormIcon(Param[0]->Val->UnsignedInteger);
}

pcvoid(RadIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    RadIcon(Param[0]->Val->UnsignedInteger);
}

pcvoid(RealIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    RealIcon(Param[0]->Val->UnsignedInteger);
}

pcvoid(FKey_Display)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    FKey_Display(Param[0]->Val->Integer, Param[1]->Val->Pointer);
}

pcvoid(GetFKeyPtr)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    GetFKeyPtr(Param[0]->Val->Integer, Param[1]->Val->Pointer);
}

pcvoid(DispInt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DispInt(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(LocalizeMessage1)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    LocalizeMessage1(Param[0]->Val->Integer, (char*)Param[1]->Val->Pointer);
}

pcvoid(SMEM_MapIconToExt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SMEM_MapIconToExt((unsigned char*)Param[0]->Val->Pointer, (unsigned short*)Param[1]->Val->Pointer, (unsigned int*)Param[2]->Val->Pointer, (unsigned short*)Param[3]->Val->Pointer);
}

pcvoid(VRAM_CopySprite)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    VRAM_CopySprite((unsigned short*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(VRAM_XORSprite)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    VRAM_XORSprite((unsigned short*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

// FILE

pcvoid(Bfile_CloseFile_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_CloseFile_OS(Param[0]->Val->Integer);
}

pcvoid(Bfile_CreateEntry_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_CreateEntry_OS((unsigned short*)Param[0]->Val->Pointer, Param[1]->Val->Integer, (unsigned int*)Param[2]->Val->Pointer);
}

pcvoid(Bfile_DeleteEntry)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_DeleteEntry((unsigned short*)Param[0]->Val->Pointer);
}

pcvoid(Bfile_RenameEntry)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_RenameEntry((unsigned short*)Param[0]->Val->Pointer, (unsigned short*)Param[1]->Val->Pointer);
}

pcvoid(Bfile_FindClose)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_FindClose(Param[0]->Val->Integer);
}

pcvoid(Bfile_FindFirst)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_FindFirst((char*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Pointer);
}

pcvoid(Bfile_FindFirst_NON_SMEM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_FindFirst_NON_SMEM((char*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Pointer);
}

pcvoid(Bfile_FindNext)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_FindNext(Param[0]->Val->Integer, (char*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer);
}

pcvoid(Bfile_FindNext_NON_SMEM)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_FindNext_NON_SMEM(Param[0]->Val->Integer, (char*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer);
}

pcvoid(Bfile_GetFileSize_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_GetFileSize_OS(Param[0]->Val->Integer);
}

pcvoid(Bfile_OpenFile_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_OpenFile_OS((unsigned short*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(Bfile_ReadFile_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_ReadFile_OS(Param[0]->Val->Integer, Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(Bfile_SeekFile_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_SeekFile_OS(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(Bfile_TellFile_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_TellFile_OS(Param[0]->Val->Integer);
}

pcvoid(Bfile_WriteFile_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_WriteFile_OS(Param[0]->Val->Integer, Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(Bfile_NameToStr_ncpy)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bfile_NameToStr_ncpy((char*)Param[0]->Val->Pointer, (unsigned short*)Param[1]->Val->Pointer, Param[2]->Val->UnsignedInteger);
}

pcvoid(Bfile_StrToName_ncpy)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bfile_StrToName_ncpy((unsigned short*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->UnsignedInteger);
}

pcvoid(Bfile_Name_MatchMask)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_Name_MatchMask((short*)Param[0]->Val->Pointer, (short*)Param[1]->Val->Pointer);
}

pcvoid(Bfile_GetMediaFree_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Bfile_GetMediaFree_OS((unsigned short*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer);
}

pcvoid(SMEM_FindFirst)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = SMEM_FindFirst((unsigned short*)Param[0]->Val->Pointer, (unsigned short*)Param[1]->Val->Pointer);
}

pcvoid(MCS_CreateDirectory)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCS_CreateDirectory((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(MCS_DeleteDirectory)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCS_DeleteDirectory((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(MCSDelVar2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCSDelVar2((unsigned char*)Param[0]->Val->Pointer, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(MCS_GetCapa)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCS_GetCapa((int*)Param[0]->Val->Pointer);
}

pcvoid(MCSGetData1)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCSGetData1(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Pointer);
}

pcvoid(MCSGetDlen2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCSGetDlen2((unsigned char*)Param[0]->Val->Pointer, (unsigned char*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer);
}

pcvoid(MCS_GetMainMemoryStart)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCS_GetMainMemoryStart();
}

pcvoid(MCSGetOpenItem)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCSGetOpenItem((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(MCSOvwDat2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCSOvwDat2((unsigned char*)Param[0]->Val->Pointer, (unsigned char*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Pointer, Param[4]->Val->Integer);
}

pcvoid(MCSPutVar2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCSPutVar2((unsigned char*)Param[0]->Val->Pointer, (unsigned char*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Pointer);
}

pcvoid(MCS_WriteItem)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCS_WriteItem((unsigned char*)Param[0]->Val->Pointer, (unsigned char*)Param[1]->Val->Pointer, Param[2]->Val->ShortInteger, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(MCS_GetState)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MCS_GetState((int*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer);
}

pcvoid(SaveFileDialog)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = SaveFileDialog((unsigned short*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(OverwriteConfirmation)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = OverwriteConfirmation((char*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(OpenFileDialog)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = OpenFileDialog(Param[0]->Val->ShortInteger, (unsigned short*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(ConfirmFileOverwriteDialog)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = ConfirmFileOverwriteDialog((unsigned short*)Param[0]->Val->Pointer);
}

// HEAP

pcvoid(sys_calloc)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = sys_calloc(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(sys_malloc)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = sys_malloc(Param[0]->Val->Integer);
}

pcvoid(sys_realloc)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = sys_realloc(Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(sys_free)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    sys_free(Param[0]->Val->Pointer);
}

// KEYBOARD

pcvoid(Set_FKeys2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Set_FKeys2(Param[0]->Val->UnsignedInteger);
}

pcvoid(Set_FKeys1)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Set_FKeys1(Param[0]->Val->UnsignedInteger, (unsigned int*)Param[1]->Val->Pointer);
}

pcvoid(PRGM_GetKey_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PRGM_GetKey_OS((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(GetKey)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = GetKey((int*)Param[0]->Val->Pointer);
}

pcvoid(GetKeyWait_OS)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = GetKeyWait_OS((int*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, (unsigned short*)Param[5]->Val->Pointer);
}

pcvoid(PRGM_GetKey)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = PRGM_GetKey();
}

pcvoid(DisplayMBString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DisplayMBString((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(DisplayMBString2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DisplayMBString2(Param[0]->Val->Integer, (unsigned char*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer);
}

pcvoid(EditMBStringCtrl)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    EditMBStringCtrl((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, (int*)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer, (int*)Param[4]->Val->Pointer, Param[5]->Val->Integer, Param[6]->Val->Integer);
}

pcvoid(EditMBStringCtrl2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    EditMBStringCtrl2((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, (int*)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer, (int*)Param[4]->Val->Pointer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer);
}

pcvoid(EditMBStringCtrl3)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    EditMBStringCtrl3((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Pointer, Param[3]->Val->Pointer, Param[4]->Val->Pointer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer, Param[9]->Val->Integer);
}

pcvoid(EditMBStringCtrl4)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    EditMBStringCtrl4((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Pointer, Param[3]->Val->Pointer, Param[4]->Val->Pointer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer, Param[9]->Val->Integer, Param[10]->Val->Integer);
}

pcvoid(EditMBStringChar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = EditMBStringChar((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(Bkey_ClrAllFlags)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bkey_ClrAllFlags();
}

pcvoid(Bkey_SetFlag)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bkey_SetFlag(Param[0]->Val->ShortInteger);
}

pcvoid(Keyboard_PutKeycode)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Keyboard_PutKeycode(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(Keyboard_SpyMatrixCode)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Keyboard_SpyMatrixCode((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(Bkey_SetAllFlags)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Bkey_SetAllFlags(Param[0]->Val->ShortInteger);
}

pcvoid(Bkey_GetAllFlags)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->ShortInteger = Bkey_GetAllFlags();
}

pcvoid(GetGetkeyToMainFunctionReturnFlag)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = GetGetkeyToMainFunctionReturnFlag();
}

// MISC

pcvoid(ItoA_10digit)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = ItoA_10digit(Param[0]->Val->Integer, Param[1]->Val->Pointer);
}

pcvoid(ByteToHex)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ByteToHex(Param[0]->Val->Character, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(HexToByte)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    HexToByte((unsigned char*)Param[0]->Val->Pointer, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(HexToNibble)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    HexToNibble(Param[0]->Val->Character, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(HexToWord)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    HexToWord((unsigned char*)Param[0]->Val->Pointer, (unsigned short*)Param[1]->Val->Pointer);
}

pcvoid(itoa)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    itoa(Param[0]->Val->Integer, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(LongToAscHex)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    LongToAscHex(Param[0]->Val->Integer, (unsigned char*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(NibbleToHex)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    NibbleToHex(Param[0]->Val->Character, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(WordToHex)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    WordToHex(Param[0]->Val->UnsignedShortInteger, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(BCDtoInternal)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = BCDtoInternal(Param[0]->Val->Pointer, Param[1]->Val->Pointer);
}

// RTC

pcvoid(RTC_Reset)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = RTC_Reset(Param[0]->Val->Integer);
}

pcvoid(RTC_SetDateTime)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    RTC_SetDateTime((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(RTC_GetTime)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    RTC_GetTime((unsigned int*)Param[0]->Val->Pointer, (unsigned int*)Param[1]->Val->Pointer, (unsigned int*)Param[2]->Val->Pointer, (unsigned int*)Param[3]->Val->Pointer);
}

pcvoid(RTC_GetTicks)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = RTC_GetTicks();
}

pcvoid(RTC_Elapsed_ms)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = RTC_Elapsed_ms(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

// SERIAL

pcvoid(Serial_Open)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_Open((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(Serial_IsOpen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_IsOpen();
}

pcvoid(Serial_Close)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_Close(Param[0]->Val->Integer);
}

pcvoid(Serial_Read)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_Read((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, (short*)Param[2]->Val->Pointer);
}

pcvoid(Serial_ReadSingle)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_ReadSingle((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(Serial_Peek)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_Peek(Param[0]->Val->Integer, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(Serial_PollRX)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_PollRX();
}

pcvoid(Serial_ClearRX)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_ClearRX();
}

pcvoid(Serial_Write)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_Write((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(Serial_WriteSingle)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_WriteSingle(Param[0]->Val->Character);
}

pcvoid(Serial_WriteUnbuffered)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_WriteUnbuffered(Param[0]->Val->Character);
}

pcvoid(Serial_PollTX)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_PollTX();
}

pcvoid(Serial_ClearTX)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Serial_ClearTX();
}

pcvoid(App_LINK_GetReceiveTimeout_ms)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = App_LINK_GetReceiveTimeout_ms();
}

pcvoid(App_LINK_SetReceiveTimeout_ms)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    App_LINK_SetReceiveTimeout_ms(Param[0]->Val->Integer);
}

pcvoid(Comm_Open)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Comm_Open(Param[0]->Val->UnsignedShortInteger);
}

pcvoid(Comm_Close)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Comm_Close(Param[0]->Val->Integer);
}

pcvoid(Comm_TryCheckPacket)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Comm_TryCheckPacket(Param[0]->Val->Character);
}

pcvoid(Comm_Terminate)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = Comm_Terminate(Param[0]->Val->Character);
}

pcvoid(App_LINK_SetRemoteBaud)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = App_LINK_SetRemoteBaud();
}

pcvoid(App_LINK_Send_ST9_Packet)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = App_LINK_Send_ST9_Packet();
}

pcvoid(App_LINK_GetDeviceInfo)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = App_LINK_GetDeviceInfo((unsigned int*)Param[0]->Val->Pointer, (unsigned short*)Param[1]->Val->Pointer);
}

pcvoid(App_LINK_TransmitInit)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = App_LINK_TransmitInit((struct TTransmitBuffer*)Param[0]->Val->Pointer);
}

pcvoid(App_LINK_Transmit)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = App_LINK_Transmit((struct TTransmitBuffer*)Param[0]->Val->Pointer);
}

// SYSTEM

pcvoid(SetAutoPowerOffTime)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SetAutoPowerOffTime(Param[0]->Val->Integer);
}

pcvoid(GetAutoPowerOffTime)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = GetAutoPowerOffTime();
}

pcvoid(SetBacklightDuration)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SetBacklightDuration(Param[0]->Val->Character);
}

pcvoid(GetBacklightDuration)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Character = GetBacklightDuration();
}

pcvoid(SetBatteryType)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SetBatteryType(Param[0]->Val->Integer);
}

pcvoid(GetBatteryType)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = GetBatteryType();
}

pcvoid(GetMainBatteryVoltage)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = GetMainBatteryVoltage(Param[0]->Val->Integer);
}

pcvoid(PowerOff)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    PowerOff(Param[0]->Val->Integer);
}

pcvoid(Restart)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Restart();
}

pcvoid(SpecialMatrixcodeProcessing)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SpecialMatrixcodeProcessing((int*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer);
}

pcvoid(TestMode)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    TestMode(Param[0]->Val->Integer);
}

pcvoid(GetStackPtr)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = GetStackPtr();
}

pcvoid(SetSetupSetting)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SetSetupSetting(Param[0]->Val->UnsignedInteger, Param[1]->Val->Character);
}

pcvoid(GetSetupSetting)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Character = GetSetupSetting(Param[0]->Val->UnsignedInteger);
}

pcvoid(TakeScreenshot)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    TakeScreenshot();
}

pcvoid(TakeScreenshot2)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    TakeScreenshot2();
}

pcvoid(DisplayMainMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    DisplayMainMenu();
}

pcvoid(OS_InnerWait_ms)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    OS_InnerWait_ms(Param[0]->Val->Integer);
}

pcvoid(CMT_Delay_100micros)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    CMT_Delay_100micros(Param[0]->Val->Integer);
}

pcvoid(CMT_Delay_micros)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    CMT_Delay_micros(Param[0]->Val->Integer);
}

pcvoid(Alpha_SetData)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Alpha_SetData(Param[0]->Val->Character, Param[1]->Val->Pointer);
}

pcvoid(Alpha_GetData)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Alpha_GetData(Param[0]->Val->Character, Param[1]->Val->Pointer);
}

pcvoid(CLIP_Store)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = CLIP_Store((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(MB_ElementCount)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = MB_ElementCount((char*)Param[0]->Val->Pointer);
}

pcvoid(GlibGetOSVersionInfo)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = GlibGetOSVersionInfo((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, (short*)Param[2]->Val->Pointer, (short*)Param[3]->Val->Pointer);
}

/* list of all library functions and their prototypes */

const struct LibraryFunction PrizmAppSyscalls[] =
{
    { pcfunc(APP_FINANCE),           "void APP_FINANCE(int, int);" },
    { pcfunc(APP_SYSTEM_BATTERY),    "void APP_SYSTEM_BATTERY(int);" },
    { pcfunc(APP_SYSTEM_DISPLAY),    "void APP_SYSTEM_DISPLAY(int);" },
    { pcfunc(APP_SYSTEM_LANGUAGE),   "void APP_SYSTEM_LANGUAGE(int);" },
    { pcfunc(APP_SYSTEM_POWER),      "void APP_SYSTEM_POWER(int);" },
    { pcfunc(APP_SYSTEM_RESET),      "void APP_SYSTEM_RESET(void);" },
    { pcfunc(APP_SYSTEM_VERSION),    "void APP_SYSTEM_VERSION(void);" },
    { pcfunc(APP_SYSTEM),            "void APP_SYSTEM(void);" },
    { pcfunc(APP_RUNMAT),            "void APP_RUNMAT(int, int);" },
    { pcfunc(APP_MEMORY),            "void APP_MEMORY(void);" },
    { pcfunc(App_Optimize),          "void App_Optimize(void);" },
    { pcfunc(ResetAllDialog),        "void ResetAllDialog(void);" },
    { pcfunc(GetAppName),            "unsigned char*GetAppName(unsigned char*);" },
    { pcfunc(App_InitDlgDescriptor), "void App_InitDlgDescriptor(void*, unsigned char);" },
    { pcfunc(APP_LINK_transmit_select_dialog),"void APP_LINK_transmit_select_dialog(void*, void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction PrizmDisplaySyscalls[] =
{
    { pcfunc(Bdisp_AreaClr),         "void Bdisp_AreaClr(struct display_fill*, unsigned char, unsigned short);" },
    { pcfunc(Bdisp_EnableColor),     "void Bdisp_EnableColor(int);" },
    { pcfunc(DrawFrame),             "void DrawFrame(int);" },
    { pcfunc(FrameColor),            "unsigned short FrameColor(int, unsigned short);" },
    { pcfunc(DrawFrameWorkbench),    "void DrawFrameWorkbench(int, int, int, int, int);" },
    { pcfunc(GetVRAMAddress),        "void *GetVRAMAddress(void);" },
    { pcfunc(Bdisp_AllClr_VRAM),     "void Bdisp_AllClr_VRAM(void);" },
    { pcfunc(Bdisp_SetPoint_VRAM),   "void Bdisp_SetPoint_VRAM(int, int, int);" },
    { pcfunc(Bdisp_SetPointWB_VRAM), "void Bdisp_SetPointWB_VRAM(int, int, int);" },
    { pcfunc(Bdisp_GetPoint_VRAM),   "unsigned short Bdisp_GetPoint_VRAM(int, int);" },
    { pcfunc(SaveVRAM_1),            "void SaveVRAM_1(void);" },
    { pcfunc(LoadVRAM_1),            "void LoadVRAM_1(void);" },
    { pcfunc(Bdisp_Fill_VRAM),       "void Bdisp_Fill_VRAM(int, int);" },
    { pcfunc(Bdisp_AreaClr_DD_x3),   "void Bdisp_AreaClr_DD_x3(void*);" },
    { pcfunc(Bdisp_DDRegisterSelect),"void Bdisp_DDRegisterSelect(int);" },
    { pcfunc(Bdisp_PutDisp_DD),      "void Bdisp_PutDisp_DD(void);" },
    { pcfunc(Bdisp_PutDisp_DD_stripe),"void Bdisp_PutDisp_DD_stripe(int, int);" },
    { pcfunc(Bdisp_SetPoint_DD),     "void Bdisp_SetPoint_DD(int, int, int);" },
    { pcfunc(Bdisp_GetPoint_DD_Workbench),"unsigned short Bdisp_GetPoint_DD_Workbench(int, int);" },
    { pcfunc(Bdisp_GetPoint_DD),     "unsigned short Bdisp_GetPoint_DD(int, int);" },
    { pcfunc(DirectDrawRectangle),   "void DirectDrawRectangle(int, int, int, int, unsigned short);" },
    { pcfunc(HourGlass),             "void HourGlass(void);" },
    { pcfunc(Bdisp_WriteGraphVRAM),  "void Bdisp_WriteGraphVRAM(void*);" },
    { pcfunc(Bdisp_WriteGraphDD_WB), "void Bdisp_WriteGraphDD_WB(void*);" },
    { pcfunc(Bdisp_ShapeBase3XVRAM), "void Bdisp_ShapeBase3XVRAM(void*);" },
    { pcfunc(Bdisp_ShapeBase),       "void Bdisp_ShapeBase(unsigned char*, void*, int, int, int, int);" },
    { pcfunc(Bdisp_ShapeToVRAM16C),  "void Bdisp_ShapeToVRAM16C(void*, int);" },
    { pcfunc(Bdisp_ShapeToDD),       "void Bdisp_ShapeToDD(void*, int);" },
    { pcfunc(SetBackGround),         "void SetBackGround(int);" },
    { pcfunc(WriteBackground),       "void WriteBackground(void*, int, int, void*, int, int, int);" },
    { pcfunc(Box),                   "void Box(int, int, int, int, int);" },
    { pcfunc(BoxInnerClear),         "void BoxInnerClear(int);" },
    { pcfunc(Box2),                  "void Box2(int, int);" },
    { pcfunc(BoxYLimits),            "void BoxYLimits(int, int*, int*);" },
    { pcfunc(AUX_DisplayErrorMessage),"void AUX_DisplayErrorMessage(int);" },
    { pcfunc(MsgBoxPush),            "void MsgBoxPush(int);" },
    { pcfunc(MsgBoxPop),             "void MsgBoxPop(void);" },
    { pcfunc(DisplayMessageBox),     "void DisplayMessageBox(unsigned char*);" },
    { pcfunc(CharacterSelectDialog), "short CharacterSelectDialog(void);" },
    { pcfunc(ColorIndexDialog1),     "unsigned char ColorIndexDialog1(unsigned char, unsigned short);" },
    { pcfunc(MsgBoxMoveWB),          "void MsgBoxMoveWB(void*, int, int, int, int, int);" },
    { pcfunc(locate_OS),             "void locate_OS(int, int);" },
    { pcfunc(Cursor_SetFlashOn),     "void Cursor_SetFlashOn(unsigned char);" },
    { pcfunc(Cursor_SetFlashOff),    "void Cursor_SetFlashOff(void);" },
    { pcfunc(SetCursorFlashToggle),  "int SetCursorFlashToggle(int);" },
    { pcfunc(Keyboard_CursorFlash),  "void Keyboard_CursorFlash(void);" },
    { pcfunc(PrintLine),             "void PrintLine(char*, int);" },
    { pcfunc(PrintLine2),            "void PrintLine2(int, int, char*, int, int, int, int, int);" },
    { pcfunc(PrintXY_2),             "void PrintXY_2(int, int, int, int, int);" },
    { pcfunc(PrintXY),               "void PrintXY(int, int, char*, int, int);" },
    { pcfunc(PrintCXY),              "void PrintCXY(int, int, char*, int, int, int, int, int, int);" },
    { pcfunc(PrintGlyph),            "void PrintGlyph(int, int, unsigned char*, int, int, int, int);" },
    { pcfunc(GetMiniGlyphPtr),       "void*GetMiniGlyphPtr(unsigned short, unsigned short*);" },
    { pcfunc(PrintMiniGlyph),        "void PrintMiniGlyph(int, int, void*, int, int, int, int, int, int, int, int, int);" },
    { pcfunc(PrintMini),             "void PrintMini(int*, int*, char*, int, unsigned int, int, int, int, int, int, int);" },
    { pcfunc(PrintMiniMini),         "void PrintMiniMini(int*, int*, char*, int, char, int);" },
    { pcfunc(Print_OS),              "void Print_OS(char*, int, int);" },
    { pcfunc(Bdisp_WriteSystemMessage),"void Bdisp_WriteSystemMessage(int, int, int, int, char);" },
    { pcfunc(Bdisp_MMPrintRef),      "void Bdisp_MMPrintRef(int*, int*, unsigned char*, int, int, int, int, int, int, int, int);" },
    { pcfunc(Bdisp_MMPrint),         "void Bdisp_MMPrint(int, int, unsigned char*, int, int, int, int, int, int, int, int);" },
    { pcfunc(Scrollbar),             "void Scrollbar(struct scrollbar*);" },
    { pcfunc(StandardScrollbar),     "void StandardScrollbar(void*);" },
    { pcfunc(ProgressBar),           "void ProgressBar(int, int);" },
    { pcfunc(ProgressBar0),          "void ProgressBar0(int, int, int, int, int);" },
    { pcfunc(ProgressBar2),          "void ProgressBar2(unsigned char*, int, int);" },
    { pcfunc(DefineStatusAreaFlags), "int DefineStatusAreaFlags(int, int, void*, void*);" },
    { pcfunc(DefineStatusGlyph),     "void DefineStatusGlyph(int, void*);" },
    { pcfunc(DefineStatusMessage),   "void DefineStatusMessage(char*, short, char, char);" },
    { pcfunc(DisplayStatusArea),     "void DisplayStatusArea(void);" },
    { pcfunc(DrawHeaderLine),        "void DrawHeaderLine(void);" },
    { pcfunc(EnableStatusArea),      "void EnableStatusArea(int);" },
    { pcfunc(Bdisp_HeaderFill),      "void Bdisp_HeaderFill(unsigned char, unsigned char);" },
    { pcfunc(Bdisp_HeaderFill2),     "void Bdisp_HeaderFill2(unsigned int, unsigned int, unsigned char, unsigned char);" },
    { pcfunc(Bdisp_HeaderText),      "void Bdisp_HeaderText(void);" },
    { pcfunc(Bdisp_HeaderText2),     "void Bdisp_HeaderText2(void);" },
    { pcfunc(EnableDisplayHeader),   "void EnableDisplayHeader(int, int);" },
    { pcfunc(APP_EACT_StatusIcon),   "void APP_EACT_StatusIcon(int);" },
    { pcfunc(SetupMode_StatusIcon),  "void SetupMode_StatusIcon(void);" },
    { pcfunc(d_c_Icon),              "void d_c_Icon(unsigned int);" },
    { pcfunc(BatteryIcon),           "void BatteryIcon(unsigned int);" },
    { pcfunc(KeyboardIcon),          "void KeyboardIcon(unsigned int);" },
    { pcfunc(LineIcon),              "void LineIcon(unsigned int);" },
    { pcfunc(NormIcon),              "void NormIcon(unsigned int);" },
    { pcfunc(RadIcon),               "void RadIcon(unsigned int);" },
    { pcfunc(RealIcon),              "void RealIcon(unsigned int);" },
    { pcfunc(FKey_Display),          "void FKey_Display(int, void*);" },
    { pcfunc(GetFKeyPtr),            "void GetFKeyPtr(int, void*);" },
    { pcfunc(DispInt),               "void DispInt(int, int);" },
    { pcfunc(LocalizeMessage1),      "int LocalizeMessage1(int, char*);" },
    { pcfunc(SMEM_MapIconToExt),     "int SMEM_MapIconToExt(unsigned char*, unsigned short*, unsigned int*, unsigned short*);" },
    { pcfunc(VRAM_CopySprite),       "void VRAM_CopySprite(unsigned short*, int, int, int, int);" },
    { pcfunc(VRAM_XORSprite),        "void VRAM_XORSprite(unsigned short*, int, int, int, unsigned int);" },
    { NULL,         NULL }
};

const struct LibraryFunction PrizmFileSyscalls[] =
{
    { pcfunc(Bfile_CloseFile_OS),    "int Bfile_CloseFile_OS(int);" },
    { pcfunc(Bfile_CreateEntry_OS),  "int Bfile_CreateEntry_OS(unsigned short*, int, int*);" },
    { pcfunc(Bfile_DeleteEntry),     "int Bfile_DeleteEntry(unsigned short*);" },
    { pcfunc(Bfile_RenameEntry),     "int Bfile_RenameEntry(unsigned short*, unsigned short*);" },
    { pcfunc(Bfile_FindClose),       "int Bfile_FindClose(int);" },
    { pcfunc(Bfile_FindFirst),       "int Bfile_FindFirst(char*, int*, char*, void*);" },
    { pcfunc(Bfile_FindFirst_NON_SMEM),"int Bfile_FindFirst_NON_SMEM(char*, int*, char*, void*);" },
    { pcfunc(Bfile_FindNext),        "int Bfile_FindNext(int, char*, char*);" },
    { pcfunc(Bfile_FindNext_NON_SMEM),"int Bfile_FindNext_NON_SMEM(int, char*, char*);" },
    { pcfunc(Bfile_GetFileSize_OS),  "int Bfile_GetFileSize_OS(int);" },
    { pcfunc(Bfile_OpenFile_OS),     "int Bfile_OpenFile_OS(unsigned short*, int, int);" },
    { pcfunc(Bfile_ReadFile_OS),     "int Bfile_ReadFile_OS(int, void*, int, int);" },
    { pcfunc(Bfile_SeekFile_OS),     "int Bfile_SeekFile_OS(int, int);" },
    { pcfunc(Bfile_TellFile_OS),     "int Bfile_TellFile_OS(int);" },
    { pcfunc(Bfile_WriteFile_OS),    "int Bfile_WriteFile_OS(int, void*, int);" },
    { pcfunc(Bfile_NameToStr_ncpy),  "void Bfile_NameToStr_ncpy(char*, unsigned short*, unsigned int);" },
    { pcfunc(Bfile_StrToName_ncpy),  "void Bfile_StrToName_ncpy(unsigned short*, char*, unsigned int);" },
    { pcfunc(Bfile_Name_MatchMask),  "int Bfile_Name_MatchMask(short*, short*);" },
    { pcfunc(Bfile_GetMediaFree_OS), "int Bfile_GetMediaFree_OS(unsigned short*, int*);" },
    { pcfunc(SMEM_FindFirst),        "int SMEM_FindFirst(unsigned short*, unsigned short*);" },
    { pcfunc(MCS_CreateDirectory),   "int MCS_CreateDirectory(unsigned char*);" },
    { pcfunc(MCS_DeleteDirectory),   "int MCS_DeleteDirectory(unsigned char*);" },
    { pcfunc(MCSDelVar2),            "int MCSDelVar2(unsigned char*, unsigned char*);" },
    { pcfunc(MCS_GetCapa),           "int MCS_GetCapa(int*);" },
    { pcfunc(MCSGetData1),           "int MCSGetData1(int, int, void*);" },
    { pcfunc(MCSGetDlen2),           "int MCSGetDlen2(unsigned char*, unsigned char*, int*);" },
    { pcfunc(MCS_GetMainMemoryStart),"int MCS_GetMainMemoryStart(void);" },
    { pcfunc(MCSGetOpenItem),        "int MCSGetOpenItem(unsigned char*);" },
    { pcfunc(MCSOvwDat2),            "int MCSOvwDat2(unsigned char*, unsigned char*, int, void*, int);" },
    { pcfunc(MCSPutVar2),            "int MCSPutVar2(unsigned char*, unsigned char*, int, void*);" },
    { pcfunc(MCS_WriteItem),         "int MCS_WriteItem(unsigned char*, unsigned char*, short, int, int);" },
    { pcfunc(MCS_GetState),          "int MCS_GetState(int*, int*, int*);" },
    { pcfunc(SaveFileDialog),        "int SaveFileDialog(unsigned short*, int);" },
    { pcfunc(OverwriteConfirmation), "int OverwriteConfirmation(char*, int);" },
    { pcfunc(OpenFileDialog),        "int OpenFileDialog(unsigned short, unsigned short*, int);" },
    { pcfunc(ConfirmFileOverwriteDialog),"int ConfirmFileOverwriteDialog(unsigned short*);" },
    { NULL,         NULL }
};

const struct LibraryFunction PrizmHeapSyscalls[] =
{
    { pcfunc(sys_calloc),            "void*sys_calloc(int, int);" },
    { pcfunc(sys_malloc),            "void*sys_malloc(unsigned short*, int, int*);" },
    { pcfunc(sys_realloc),           "void*sys_realloc(void*, int);" },
    { pcfunc(sys_free),              "void sys_free(void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction PrizmKeyboardSyscalls[] =
{
    { pcfunc(Set_FKeys2),            "void Set_FKeys2(unsigned int);" },
    { pcfunc(Set_FKeys1),            "void Set_FKeys1(unsigned int, unsigned int*);" },
    { pcfunc(PRGM_GetKey_OS),        "void PRGM_GetKey_OS(unsigned char*);" },
    { pcfunc(GetKey),                "int GetKey(int*);" },
    { pcfunc(GetKeyWait_OS),         "int GetKeyWait_OS(int*, int*, int, int, int, unsigned short*);" },
    { pcfunc(PRGM_GetKey),           "int PRGM_GetKey();" },
    { pcfunc(DisplayMBString),       "void DisplayMBString(unsigned char*, int, int, int, int);" },
    { pcfunc(DisplayMBString2),      "void DisplayMBString2(int, unsigned char*, int, int, int, int, int, int, int);" },
    { pcfunc(EditMBStringCtrl),      "void EditMBStringCtrl(unsigned char*, int, int*, int*, int*, int, int);" },
    { pcfunc(EditMBStringCtrl2),     "void EditMBStringCtrl2(unsigned char*, int, int*, int*, int*, int, int, int, int);" },
    { pcfunc(EditMBStringCtrl3),     "void EditMBStringCtrl3(unsigned char*, int, void*, void*, void*, int, int, int, int, int);" },
    { pcfunc(EditMBStringCtrl4),     "void EditMBStringCtrl4(unsigned char*, int, void*, void*, void*, int, int, int, int, int, int);" },
    { pcfunc(EditMBStringChar),      "int EditMBStringChar(unsigned char*, int, int, int);" },
    { pcfunc(Bkey_ClrAllFlags),      "void Bkey_ClrAllFlags(void);" },
    { pcfunc(Bkey_SetFlag),          "void Bkey_SetFlag(short);" },
    { pcfunc(Keyboard_PutKeycode),   "int Keyboard_PutKeycode(int, int, int);" },
    { pcfunc(Keyboard_SpyMatrixCode),"int Keyboard_SpyMatrixCode(char*, char*);" },
    { pcfunc(Bkey_SetAllFlags),      "void Bkey_SetAllFlags(short);" },
    { pcfunc(Bkey_GetAllFlags),      "short Bkey_GetAllFlags(void);" },
    { pcfunc(GetGetkeyToMainFunctionReturnFlag),"int GetGetkeyToMainFunctionReturnFlag(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction PrizmMiscSyscalls[] =
{
    { pcfunc(ItoA_10digit),          "int ItoA_10digit(int, void*);" },
    { pcfunc(ByteToHex),             "void ByteToHex(unsigned char, unsigned char*);" },
    { pcfunc(HexToByte),             "void HexToByte(unsigned char*, unsigned char*);" },
    { pcfunc(HexToNibble),           "void HexToNibble(unsigned char, unsigned char*);" },
    { pcfunc(HexToWord),             "void HexToWord(unsigned char*, unsigned short*);" },
    { pcfunc(itoa),                  "void itoa(int, unsigned char*);" },
    { pcfunc(LongToAscHex),          "void LongToAscHex(int, unsigned char*, int);" },
    { pcfunc(NibbleToHex),           "void NibbleToHex(unsigned char, unsigned char*);" },
    { pcfunc(WordToHex),             "void WordToHex(unsigned short, unsigned char*);" },
    { pcfunc(BCDtoInternal),         "int BCDtoInternal(void*, void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction PrizmRTCSyscalls[] =
{
    { pcfunc(RTC_Reset),             "int RTC_Reset(int);" },
    { pcfunc(RTC_SetDateTime),       "void RTC_SetDateTime(unsigned char*);" },
    { pcfunc(RTC_GetTime),           "void RTC_GetTime(unsigned int*, unsigned int*, unsigned int*, unsigned int*);" },
    { pcfunc(RTC_GetTicks),          "int RTC_GetTicks(void);" },
    { pcfunc(RTC_Elapsed_ms),        "int RTC_Elapsed_ms(int, int);" },
    { NULL,         NULL }
};

const struct LibraryFunction PrizmSerialSyscalls[] =
{
    { pcfunc(Serial_Open),           "int Serial_Open(unsigned char*);" },
    { pcfunc(Serial_IsOpen),         "int Serial_IsOpen(void);" },
    { pcfunc(Serial_Close),          "int Serial_Close(int mode);" },
    { pcfunc(Serial_Read),           "int Serial_Read(unsigned char*, int, short*);" },
    { pcfunc(Serial_ReadSingle),     "int Serial_ReadSingle(unsigned char*);" },
    { pcfunc(Serial_Peek),           "int Serial_Peek(int, unsigned char*);" },
    { pcfunc(Serial_PollRX),         "int Serial_PollRX(void);" },
    { pcfunc(Serial_ClearRX),        "int Serial_ClearRX(void);" },
    { pcfunc(Serial_Write),          "int Serial_Write(unsigned char*, int);" },
    { pcfunc(Serial_WriteSingle),    "int Serial_WriteSingle(unsigned char);" },
    { pcfunc(Serial_PollTX),         "int Serial_PollTX(void);" },
    { pcfunc(Serial_ClearTX),        "int Serial_ClearTX(void);" },
    { pcfunc(App_LINK_GetReceiveTimeout_ms),"int App_LINK_GetReceiveTimeout_ms(void);" },
    { pcfunc(App_LINK_SetReceiveTimeout_ms),"void App_LINK_SetReceiveTimeout_ms(int);" },
    { pcfunc(Comm_Open),             "int Comm_Open(unsigned short);" },
    { pcfunc(Comm_Close),            "int Comm_Close(int);" },
    { pcfunc(Comm_TryCheckPacket),   "int Comm_TryCheckPacket(unsigned char);" },
    { pcfunc(Comm_Terminate),        "int Comm_Terminate(unsigned char);" },
    { pcfunc(App_LINK_SetRemoteBaud),"int App_LINK_SetRemoteBaud(void);" },
    { pcfunc(App_LINK_Send_ST9_Packet),"int App_LINK_Send_ST9_Packet(void);" },
    { pcfunc(App_LINK_GetDeviceInfo),"int App_LINK_GetDeviceInfo(unsigned int*, unsigned int*);" },
    { pcfunc(App_LINK_TransmitInit), "int App_LINK_TransmitInit(void*);" },
    { pcfunc(App_LINK_Transmit),     "int App_LINK_Transmit(void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction PrizmSystemSyscalls[] =
{
    { pcfunc(SetAutoPowerOffTime),   "void SetAutoPowerOffTime(int);" },
    { pcfunc(GetAutoPowerOffTime),   "int GetAutoPowerOffTime();" },
    { pcfunc(SetBacklightDuration),  "void SetBacklightDuration(char);" },
    { pcfunc(GetBacklightDuration),  "char GetBacklightDuration();" },
    { pcfunc(SetBatteryType),        "void SetBatteryType(int);" },
    { pcfunc(GetBatteryType),        "int GetBatteryType(void);" },
    { pcfunc(GetMainBatteryVoltage), "int GetMainBatteryVoltage(int);" },
    { pcfunc(PowerOff),              "void PowerOff(int);" },
    { pcfunc(Restart),               "void Restart(void);" },
    { pcfunc(SpecialMatrixcodeProcessing),"void SpecialMatrixcodeProcessing(int*, int*);" },
    { pcfunc(TestMode),              "void TestMode(int);" },
    { pcfunc(GetStackPtr),           "void*GetStackPtr(void);" },
    { pcfunc(SetSetupSetting),       "void SetSetupSetting(unsigned int, unsigned char);" },
    { pcfunc(GetSetupSetting),       "unsigned char GetSetupSetting(unsigned int);" },
    // Timers TODO (func pointers not supported for timer init)
    { pcfunc(TakeScreenshot),        "void TakeScreenshot(void);" },
    { pcfunc(TakeScreenshot2),       "void TakeScreenshot2(void);" },
    { pcfunc(DisplayMainMenu),       "void DisplayMainMenu(void);" },
    { pcfunc(OS_InnerWait_ms),       "void OS_InnerWait_ms(int);" },
    { pcfunc(CMT_Delay_100micros),   "void CMT_Delay_100micros(int);" },
    { pcfunc(CMT_Delay_micros),      "void CMT_Delay_micros(int);" },
    // SetQuitHandler TODO (func pointers not supported)
    { pcfunc(Alpha_SetData),         "void Alpha_SetData(char, void*);" },
    { pcfunc(Alpha_GetData),         "void Alpha_GetData(char, void*);" },
    { pcfunc(CLIP_Store),            "int CLIP_Store(unsigned char*, int);" },
    { pcfunc(MB_ElementCount),       "int MB_ElementCount(char* buf);" },
    { pcfunc(GlibGetOSVersionInfo),  "int GlibGetOSVersionInfo(char*, char*, short*, short*);" },
    { NULL,         NULL }
};

// Utilities integration:

// aboutGUI

pcvoid(aboutScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    aboutScreen();
}

pcvoid(buildExpiredScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    buildExpiredScreen();
}

// calendarGUI

pcvoid(viewCalendar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewCalendar(Param[0]->Val->Integer);
}

pcvoid(viewMonthCalendar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = viewMonthCalendar(Param[0]->Val->Integer);
}

pcvoid(viewWeekCalendar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = viewWeekCalendar();
}

pcvoid(viewWeekCalendarChild)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = viewWeekCalendarChild((Menu*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer, (int*)Param[4]->Val->Pointer, (int*)Param[5]->Val->Pointer);
}

pcvoid(viewEvents)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewEvents(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(viewEvent)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewEvent((CalendarEvent*)Param[0]->Val->Pointer);
}

pcvoid(viewEventsChild)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = viewEventsChild((Menu*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(fillInputDate)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    fillInputDate((EventDate*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(fillInputTime)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    fillInputTime((EventTime*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(eventEditor)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = eventEditor(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, (CalendarEvent*)Param[4]->Val->Pointer, Param[5]->Val->Integer);
}

pcvoid(drawCalendar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawCalendar(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, (int*)Param[4]->Val->Pointer, (int*)Param[5]->Val->Pointer, (int*)Param[6]->Val->Pointer, (int*)Param[7]->Val->Pointer);
}

pcvoid(moveEventScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = moveEventScreen((CalendarEvent*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(deleteEventPrompt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = deleteEventPrompt((CalendarEvent*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(deleteAllEventsPrompt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = deleteAllEventsPrompt(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(selectDateScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = selectDateScreen((int*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer, (char*)Param[3]->Val->Pointer, (char*)Param[4]->Val->Pointer, Param[5]->Val->Integer);
}

pcvoid(invalidFieldMsg)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    invalidFieldMsg(Param[0]->Val->Integer);
}

pcvoid(setReminderScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setReminderScreen((CalendarEvent*)Param[0]->Val->Pointer);
}

pcvoid(setCategoryPrompt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = setCategoryPrompt((CalendarEvent*)Param[0]->Val->Pointer);
}

pcvoid(viewEventAtPos)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewEventAtPos((EventDate*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(searchEventsScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    searchEventsScreen(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(drawBusymapDay)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawBusymapDay((EventDate*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer);
}

pcvoid(drawBusymapWeek)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawBusymapWeek(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer);
}

pcvoid(calendarToolsMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    calendarToolsMenu(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(databaseRepairScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    databaseRepairScreen();
}

pcvoid(databaseTrimScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    databaseTrimScreen();
}

pcvoid(eventImportScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    eventImportScreen();
}

// calendarProvider

pcvoid(eventToString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = eventToString((CalendarEvent*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(stringToEvent)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stringToEvent((char*)Param[0]->Val->Pointer, (CalendarEvent*)Param[1]->Val->Pointer);
}

pcvoid(stringToSimpleEvent)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stringToSimpleEvent((char*)Param[0]->Val->Pointer, (SimpleCalendarEvent*)Param[1]->Val->Pointer);
}

pcvoid(eventDateToFilename)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    eventDateToFilename((EventDate*)Param[0]->Val->Pointer, (unsigned short*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer);
}

pcvoid(addEvent)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = addEvent((CalendarEvent*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(replaceEventFile)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = replaceEventFile((EventDate*)Param[0]->Val->Pointer, (CalendarEvent*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer);
}

pcvoid(removeEvent)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    removeEvent((EventDate*)Param[0]->Val->Pointer, (CalendarEvent*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(removeDay)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    removeDay((EventDate*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(getEvents)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getEvents((EventDate*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, (CalendarEvent*)Param[2]->Val->Pointer, Param[3]->Val->Integer, (SimpleCalendarEvent*)Param[4]->Val->Pointer);
}

pcvoid(getEventCountsForMonth)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    getEventCountsForMonth(Param[0]->Val->Integer, Param[1]->Val->Integer, (int*)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer);
}

pcvoid(searchEventsOnDay)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = searchEventsOnDay((EventDate*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, (SimpleCalendarEvent*)Param[2]->Val->Pointer, (char*)Param[3]->Val->Pointer, Param[4]->Val->Integer);
}

pcvoid(searchEventsOnYearOrMonth)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = searchEventsOnYearOrMonth(Param[0]->Val->Integer, Param[1]->Val->Integer, (char*)Param[2]->Val->Pointer, (SimpleCalendarEvent*)Param[3]->Val->Pointer, (char*)Param[4]->Val->Pointer, Param[5]->Val->Integer);
}

pcvoid(repairEventFile)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    repairEventFile((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer);
}

pcvoid(setDBcorruptFlag)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setDBcorruptFlag(Param[0]->Val->Integer);
}

pcvoid(getDBcorruptFlag)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getDBcorruptFlag();
}

// chronoGUI

pcvoid(formatChronoString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    formatChronoString((chronometer*)Param[0]->Val->Pointer, Param[1]->Val->Integer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer);
}

pcvoid(stopAndUninstallStubTimer)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stopAndUninstallStubTimer();
}

pcvoid(chronoScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    chronoScreen();
}

pcvoid(startSelectedChronos)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    startSelectedChronos((Menu*)Param[0]->Val->Pointer, (chronometer*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(stopSelectedChronos)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stopSelectedChronos((Menu*)Param[0]->Val->Pointer, (chronometer*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(clearSelectedChronos)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    clearSelectedChronos((Menu*)Param[0]->Val->Pointer, (chronometer*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(setChronoScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setChronoScreen((Menu*)Param[0]->Val->Pointer, (chronometer*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(setPresetChrono)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setPresetChrono((Menu*)Param[0]->Val->Pointer, (chronometer*)Param[1]->Val->Pointer);
}

pcvoid(getLastCompleteChrono)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getLastCompleteChrono();
}

pcvoid(checkChronoComplete)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    checkChronoComplete((chronometer*)Param[0]->Val->Pointer);
}

// chronoProvider

pcvoid(saveChronoArray)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    saveChronoArray((chronometer*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(loadChronoArray)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    loadChronoArray((chronometer*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(setChrono)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    long long int p1 = (long long int) Param[1]->Val->Integer << 32 | Param[2]->Val->Integer;
    long long int p2 = (long long int) Param[3]->Val->Integer << 32 | Param[4]->Val->Integer;
    setChrono((chronometer*)Param[0]->Val->Pointer, p1, p2);
}

pcvoid(stopChrono)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stopChrono((chronometer*)Param[0]->Val->Pointer);
}

pcvoid(startChrono)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stopChrono((chronometer*)Param[0]->Val->Pointer);
}

pcvoid(clearChrono)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    clearChrono((chronometer*)Param[0]->Val->Pointer);
}

pcvoid(getChronoArrayPtr)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer =  getChronoArrayPtr();
}

pcvoid(setChronoArrayPtr)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setChronoArrayPtr((chronometer*)Param[0]->Val->Pointer);
}

// editorGUI

pcvoid(textfileEditor)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    textfileEditor((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

// fileGUI

pcvoid(fileManager)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    fileManager();
}

pcvoid(getFileManagerStatus)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    getFileManagerStatus((char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(fileManagerChild)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = fileManagerChild((char*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Integer, (int*)Param[3]->Val->Integer, (File*)Param[4]->Val->Integer, (char*)Param[5]->Val->Integer);
}

pcvoid(deleteFilesPrompt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = deleteFilesPrompt((File*)Param[0]->Val->Pointer, (Menu*)Param[1]->Val->Pointer);
}

pcvoid(newFolderScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = newFolderScreen((char*)Param[0]->Val->Pointer);
}

pcvoid(newG3Pscreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = newG3Pscreen((char*)Param[0]->Val->Pointer);
}

pcvoid(renameFileScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = renameFileScreen((File*)Param[0]->Val->Pointer, (Menu*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer);
}

pcvoid(searchFilesScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = searchFilesScreen((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(viewFileInfo)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = viewFileInfo((File*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(viewFileAsText)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewFileAsText((char*)Param[0]->Val->Pointer);
}

pcvoid(viewClipboard)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewClipboard((File*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer);
}

pcvoid(folderStatsScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    folderStatsScreen((File*)Param[0]->Val->Pointer, (Menu*)Param[1]->Val->Pointer);
}

pcvoid(compressSelectedFiles)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    compressSelectedFiles((File*)Param[0]->Val->Pointer, (Menu*)Param[1]->Val->Pointer);
}

pcvoid(decompressSelectedFiles)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    decompressSelectedFiles((File*)Param[0]->Val->Pointer, (Menu*)Param[1]->Val->Pointer);
}

pcvoid(shortenDisplayPath)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    shortenDisplayPath((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(buildIconTable)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    buildIconTable((MenuItemIcon*)Param[0]->Val->Pointer);
}

pcvoid(overwriteFilePrompt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = overwriteFilePrompt((char*)Param[0]->Val->Pointer);
}

// fileProvider

pcvoid(sortFiles)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    sortFiles((File*)Param[0]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(getFiles)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getFiles((File*)Param[0]->Val->Pointer, (char*)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer);
}

pcvoid(searchForFiles)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = searchForFiles((File*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, (int*)Param[7]->Val->Pointer, Param[8]->Val->Integer);
}

pcvoid(deleteFiles)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    deleteFiles((File*)Param[0]->Val->Pointer, (Menu*)Param[1]->Val->Pointer);
}

pcvoid(renameFile)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    renameFile((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(filenameToName)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = filenameToName((char*)Param[0]->Val->Pointer);
}

pcvoid(copyFile)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    copyFile((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(pasteClipboard)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    pasteClipboard((File*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(filenameToIcon)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = filenameToIcon((char*)Param[0]->Val->Pointer);
}

pcvoid(stringEndsInG3A)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = stringEndsInG3A((char*)Param[0]->Val->Pointer);
}

pcvoid(stringEndsInJPG)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = stringEndsInJPG((char*)Param[0]->Val->Pointer);
}

pcvoid(createFolderRecursive)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    createFolderRecursive((const char*)Param[0]->Val->Pointer);
}

pcvoid(compressFile)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    compressFile((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(isFileCompressed)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = isFileCompressed((char*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer);
}

pcvoid(fileOpen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = fileOpen((char*)Param[0]->Val->Pointer);
}

// firstRunGUI

pcvoid(firstRunWizard)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    firstRunWizard();
}

// graphicsProvider

pcvoid(drawRectangle)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawRectangle(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->UnsignedShortInteger);
}

pcvoid(drawLine)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawLine(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(drawFilledCircle)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawFilledCircle(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->UnsignedShortInteger);
}

pcvoid(drawCircularCountdownIndicator)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawCircularCountdownIndicator(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->UnsignedShortInteger, Param[4]->Val->UnsignedShortInteger, Param[5]->Val->Integer, Param[6]->Val->Integer);
}

pcvoid(replaceColorInArea)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    replaceColorInArea(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->UnsignedShortInteger, Param[5]->Val->UnsignedShortInteger);
}

pcvoid(invertArea)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    invertArea(Param[0]->Val->ShortInteger, Param[1]->Val->ShortInteger, Param[2]->Val->ShortInteger, Param[3]->Val->ShortInteger);
}

pcvoid(darkenStatusbar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    darkenStatusbar();
}

pcvoid(darkenFkeys)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    darkenFkeys(Param[0]->Val->Integer);
}

pcvoid(drawArrowDown)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawArrowDown(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(drawFkeyPopup)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawFkeyPopup(Param[0]->Val->Integer, (char*)Param[1]->Val->Pointer);
}

pcvoid(CopySpriteMasked)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    CopySpriteMasked((unsigned short*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->UnsignedShortInteger);
}

pcvoid(CopySpriteNbitMasked)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    CopySpriteNbitMasked((unsigned char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, (unsigned short*)Param[5]->Val->Pointer, Param[6]->Val->UnsignedShortInteger, Param[7]->Val->UnsignedInteger);
}

pcvoid(drawSegvaultLogo)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawSegvaultLogo(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(textColorToFullColor)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = textColorToFullColor(Param[0]->Val->Integer);
}

pcvoid(progressMessage)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    progressMessage((char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(closeProgressMessage)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    closeProgressMessage();
}

pcvoid(clearLine)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    clearLine(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->UnsignedShortInteger);
}

pcvoid(printCentered)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    printCentered((char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(mPrintXY)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    mPrintXY(Param[0]->Val->Integer, Param[1]->Val->Integer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(multiPrintXY)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    multiPrintXY(Param[0]->Val->Integer, Param[1]->Val->Integer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(multiPrintMini)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    multiPrintMini(Param[0]->Val->Integer, Param[1]->Val->Integer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer);
}

pcvoid(mMsgBoxPush)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    mMsgBoxPush(Param[0]->Val->Integer);
}

pcvoid(mMsgBoxPop)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    mMsgBoxPop();
}

pcvoid(popAllMsgBoxes)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    popAllMsgBoxes();
}

pcvoid(getMsgBoxCount)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getMsgBoxCount();
}

pcvoid(drawScreenTitle)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawScreenTitle((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(drawFkeyLabels)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawFkeyLabels(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer);
}

pcvoid(drawRGB24toRGB565)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = drawRGB24toRGB565(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

// hardwareProvider

pcvoid(CPU_change_freq)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    CPU_change_freq(Param[0]->Val->Integer);
}

pcvoid(getRawBacklightSubLevel)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getRawBacklightSubLevel();
}

pcvoid(setRawBacklightSubLevel)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setRawBacklightSubLevel(Param[0]->Val->Integer);
}

pcvoid(getHardwareID)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    getHardwareID((char*)Param[0]->Val->Pointer);
}

pcvoid(getHardwareModel)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getHardwareModel();
}

pcvoid(getIsEmulated)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getIsEmulated();
}

pcvoid(setBrightnessToStartupSetting)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setBrightnessToStartupSetting();
}

// homeGUI

pcvoid(homeScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    homeScreen(Param[0]->Val->Integer);
}

pcvoid(powerMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    powerMenu((int*)Param[0]->Val->Pointer);
}

pcvoid(lightMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    lightMenu((int*)Param[0]->Val->Pointer);
}

pcvoid(timeMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    timeMenu((int*)Param[0]->Val->Pointer);
}

pcvoid(memsysMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    memsysMenu((int*)Param[0]->Val->Pointer);
}

pcvoid(toolsMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    toolsMenu((int*)Param[0]->Val->Pointer);
}

pcvoid(handleHomePane)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    handleHomePane(Param[0]->Val->Integer, (int*)Param[1]->Val->Pointer);
}

pcvoid(paneHandleBasicKeys)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    paneHandleBasicKeys(Param[0]->Val->Integer, (int*)Param[1]->Val->Pointer);
}

pcvoid(eventsPane)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    eventsPane(Param[0]->Val->Integer, (int*)Param[1]->Val->Pointer);
}

pcvoid(memoryUsagePane)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    memoryUsagePane(Param[0]->Val->Integer, (int*)Param[1]->Val->Pointer);
}

// imageGUI

pcvoid(viewImage)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewImage((char*)Param[0]->Val->Pointer);
}

// inputGUI

pcvoid(doTextInput)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    doTextInput((textInput*)Param[0]->Val->Pointer);
}

// keyboardProvider
pcvoid(mGetKey)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    mGetKey((int*)Param[0]->Val->Pointer, Param[1]->Val->Integer);
}

pcvoid(saveVRAMandCallSettings)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    saveVRAMandCallSettings();
}

pcvoid(setmGetKeyMode)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setmGetKeyMode(Param[0]->Val->Integer);
}

pcvoid(SetGetkeyToMainFunctionReturnFlag)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->UnsignedInteger = SetGetkeyToMainFunctionReturnFlag(Param[0]->Val->Integer);
}

// lightGUI

pcvoid(lantern)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    lantern();
}

pcvoid(flashLight)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    flashLight(Param[0]->Val->Integer);
}

pcvoid(morseLight)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    morseLight();
}

pcvoid(colorLight)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    colorLight();
}

// lockGUI

pcvoid(passwordInput)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = passwordInput(Param[0]->Val->Integer, Param[1]->Val->Integer, (unsigned char*)Param[2]->Val->Pointer);
}

pcvoid(setPassword)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = setPassword();
}

pcvoid(unlockCalc)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = unlockCalc();
}

pcvoid(lockApp)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    lockApp();
}

pcvoid(openRunMat)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    openRunMat();
}

pcvoid(returnToUtilitiesHandler)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    returnToUtilitiesHandler();
}

// lockProvider

pcvoid(hashPassword)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    hashPassword((unsigned char*)Param[0]->Val->Pointer, (unsigned char*)Param[1]->Val->Pointer);
}

pcvoid(comparePasswordHash)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = comparePasswordHash((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(savePassword)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = savePassword((unsigned char*)Param[0]->Val->Pointer);
}

pcvoid(isPasswordSet)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = isPasswordSet();
}

// memsysGUI

pcvoid(memoryCapacityScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    memoryCapacityScreen(Param[0]->Val->Integer);
}

pcvoid(getAddins)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getAddins((AddIn*)Param[0]->Val->Pointer);
}

pcvoid(addinManager)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    addinManager();
}

pcvoid(addinManagerChild)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = addinManagerChild((Menu*)Param[0]->Val->Pointer);
}

pcvoid(changeFKeyColor)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    changeFKeyColor();
}

pcvoid(systemInfo)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    systemInfo();
}

pcvoid(userInfo)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    userInfo();
}

// menuGUI

pcvoid(doMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = doMenu((Menu*)Param[0]->Val->Pointer, (MenuItemIcon*)Param[1]->Val->Pointer);
}

pcvoid(getMenuSelectionSeparators)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getMenuSelectionSeparators((Menu*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer);
}

pcvoid(closeMsgBox)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = closeMsgBox(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

// powerGUI

pcvoid(setPoweroffTimeout)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setPoweroffTimeout();
}

pcvoid(setBacklightTimeout)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setBacklightTimeout();
}

pcvoid(setBacklightLevel)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setBacklightLevel();
}

pcvoid(powerInformation)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    powerInformation();
}

pcvoid(getPLLinfo)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getPLLinfo(Param[0]->Val->UnsignedInteger, (char**)Param[1]->Val->Pointer, (char**)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer);
}

// selectorGUI

pcvoid(doSelector)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    doSelector((Selector*)Param[0]->Val->Pointer);
}

// settingsGUI

pcvoid(settingsMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    settingsMenu();
}

pcvoid(calendarSettingsMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    calendarSettingsMenu();
}

// settingsProvider

pcvoid(getSetting)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getSetting(Param[0]->Val->Integer);
}

pcvoid(setSetting)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setSetting(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(loadSettings)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = loadSettings();
}

pcvoid(saveSettings)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    saveSettings();
}

// stringsProvider

pcvoid(isMBfirst)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = isMBfirst(Param[1]->Val->Character);
}

pcvoid(toksplit)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)toksplit((char*)Param[0]->Val->Pointer, Param[1]->Val->Character, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer);
}

pcvoid(strEndsWith)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = strEndsWith((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(memmem)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = memmem((char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, (char*)Param[2]->Val->Pointer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(strncpy_retlen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = strncpy_retlen((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(strncpy_replace)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = strncpy_replace((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(stringToMini)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stringToMini((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(base32_decode)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = base32_decode((unsigned char*)Param[0]->Val->Pointer, (unsigned char*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(base32_validate)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = base32_validate((char*)Param[0]->Val->Pointer);
}

// tasksGUI

pcvoid(viewTasks)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewTasks();
}

pcvoid(viewTasksChild)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = viewTasksChild((Menu*)Param[0]->Val->Pointer);
}

// textGUI

pcvoid(doTextArea)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = doTextArea((textArea*)Param[0]->Val->Pointer);
}

// textEditGUI

pcvoid(doTextEdit)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = doTextEdit((textEdit*)Param[0]->Val->Pointer);
}

// timeGUI

pcvoid(drawLongDate)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawLongDate(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(drawAnalogChronometer)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawAnalogChronometer(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer);
}

pcvoid(drawAnalogClock)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawAnalogClock(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer);
}

pcvoid(RTCunadjustedWizard)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    RTCunadjustedWizard(Param[0]->Val->Integer);
}

pcvoid(setTimeScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setTimeScreen(Param[0]->Val->Integer);
}

pcvoid(setDateScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setDateScreen(Param[0]->Val->Integer);
}

pcvoid(currentTimeToBasicVar)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    currentTimeToBasicVar();
}

pcvoid(drawHomeClock)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    drawHomeClock(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(setTimezone)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setTimezone();
}

// timeProvider

pcvoid(getMonthDays)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getMonthDays(Param[0]->Val->Integer);
}

pcvoid(getMonthDaysWithLeap)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getMonthDaysWithLeap(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(getCurrentDOWAsString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getCurrentDOWAsString();
}

pcvoid(getCurrentDOWAsShortString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getCurrentDOWAsShortString();
}

pcvoid(getCurrentMonthAsString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getCurrentMonthAsString();
}

pcvoid(getDOWAsString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getDOWAsString(Param[0]->Val->Integer);
}

pcvoid(getDOWAsShortString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getDOWAsShortString(Param[0]->Val->Integer);
}

pcvoid(getMonthAsString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getMonthAsString(Param[0]->Val->Integer);
}

pcvoid(isLeap)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = isLeap(Param[0]->Val->Integer);
}

pcvoid(dow)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = dow(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(getDayOfYear)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getDayOfYear(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(getWeekNumber)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getWeekNumber(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(getCurrentYear)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getCurrentYear();
}

pcvoid(getCurrentMonth)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getCurrentMonth();
}

pcvoid(getCurrentDay)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getCurrentDay();
}

pcvoid(getCurrentHour)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getCurrentHour();
}

pcvoid(getCurrentMinute)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getCurrentMinute();
}

pcvoid(getCurrentSecond)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getCurrentSecond();
}

pcvoid(getCurrentMillisecond)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getCurrentMillisecond();
}

pcvoid(dateTimeToUEBT)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    long long int t = dateTimeToUEBT(Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, Param[7]->Val->Integer, Param[8]->Val->Integer);
    long long int a = t & 0x00000000ffffffffLL;
    long long int b = (long long int)(t & 0xffffffff00000000LL) >> 32;
    *(int*)Param[0]->Val->Pointer = b;
    *(int*)Param[1]->Val->Pointer = a;
}

pcvoid(setTime)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setTime(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(setDate)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setDate(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(blockForTicks)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    blockForTicks(Param[0]->Val->Integer);
}

pcvoid(blockForMilliseconds)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    blockForMilliseconds(Param[0]->Val->Integer);
}

pcvoid(tickDifferenceToMilliseconds)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = tickDifferenceToMilliseconds(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

pcvoid(isTimeValid)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = isTimeValid(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(isDateValid)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = isDateValid(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(daysToDate)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    daysToDate(Param[0]->Val->Integer, (long int*)Param[1]->Val->Pointer, (long int*)Param[2]->Val->Pointer, (long int*)Param[3]->Val->Pointer);
}

pcvoid(dateToDays)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = dateToDays(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

pcvoid(stringToDate)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stringToDate((char*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer, Param[4]->Val->Integer);
}

pcvoid(stringToTime)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    stringToTime((char*)Param[0]->Val->Pointer, (int*)Param[1]->Val->Pointer, (int*)Param[2]->Val->Pointer, (int*)Param[3]->Val->Pointer);
}

pcvoid(getInputDateFormatHint)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getInputDateFormatHint(Param[0]->Val->Integer);
}

pcvoid(isDSTchangeToday)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = isDSTchangeToday();
}

// toolsGUI

pcvoid(balanceManager)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    balanceManager();
}

pcvoid(balanceManagerChild)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = balanceManagerChild((Menu*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(addTransactionWizard)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = addTransactionWizard((char*)Param[0]->Val->Pointer);
}

pcvoid(deleteTransactionPrompt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = deleteTransactionPrompt((Transaction*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(viewTransaction)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewTransaction((Transaction*)Param[0]->Val->Pointer);
}

pcvoid(createWalletWizard)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = createWalletWizard(Param[0]->Val->Integer);
}

pcvoid(changeWalletScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = changeWalletScreen((char*)Param[0]->Val->Pointer);
}

pcvoid(deleteWalletPrompt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = deleteWalletPrompt((char*)Param[0]->Val->Pointer);
}

pcvoid(renameWalletScreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = renameWalletScreen((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(passwordGenerator)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    passwordGenerator();
}

pcvoid(totpClient)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    totpClient();
}

pcvoid(viewTOTPcode)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    viewTOTPcode((totp*)Param[0]->Val->Pointer);
}

pcvoid(addTOTPwizard)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = addTOTPwizard();
}

pcvoid(renameTOTPscreen)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = renameTOTPscreen(Param[0]->Val->Integer, (char*)Param[1]->Val->Pointer);
}

pcvoid(deleteTOTPprompt)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = deleteTOTPprompt(Param[0]->Val->Integer);
}

// toolsProvider

pcvoid(currencyToString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    currencyToString((char*)Param[0]->Val->Pointer, (Currency*)Param[1]->Val->Pointer);
}

pcvoid(stringToCurrency)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = stringToCurrency((Currency*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(addCurrency)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    addCurrency((Currency*)Param[0]->Val->Pointer, (Currency*)Param[1]->Val->Pointer);
}

pcvoid(subtractCurrency)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    subtractCurrency((Currency*)Param[0]->Val->Pointer, (Currency*)Param[1]->Val->Pointer);
}

pcvoid(walletNameToPath)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    walletNameToPath((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(getWalletBalance)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    getWalletBalance((Currency*)Param[0]->Val->Pointer, (const char*)Param[1]->Val->Pointer);
}

pcvoid(getCurrentWallet)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getCurrentWallet((char*)Param[0]->Val->Pointer);
}

pcvoid(setCurrentWallet)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    setCurrentWallet((char*)Param[0]->Val->Pointer);
}

pcvoid(transactionToCalendarEvent)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    transactionToCalendarEvent((CalendarEvent*)Param[0]->Val->Pointer, (Transaction*)Param[1]->Val->Pointer);
}

pcvoid(calendarEventToTransaction)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    calendarEventToTransaction((Transaction*)Param[0]->Val->Pointer, (CalendarEvent*)Param[1]->Val->Pointer);
}

pcvoid(getWalletTransactions)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = getWalletTransactions((char*)Param[0]->Val->Pointer, (Transaction*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(addTransaction)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    addTransaction((Transaction*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(replaceWalletTransactions)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    replaceWalletTransactions((Transaction*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer);
}

pcvoid(deleteTransaction)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    deleteTransaction((Transaction*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer, Param[2]->Val->Integer, Param[3]->Val->Integer);
}

pcvoid(createWallet)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    createWallet((char*)Param[0]->Val->Pointer, (Currency*)Param[1]->Val->Pointer);
}

pcvoid(deleteWallet)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    deleteWallet((char*)Param[0]->Val->Pointer);
}

pcvoid(generateRandomString)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    generateRandomString((char*)Param[0]->Val->Pointer, Param[1]->Val->Integer, Param[2]->Val->Integer, Param[3]->Val->Integer, Param[4]->Val->Integer, Param[5]->Val->Integer, Param[6]->Val->Integer, (int*)Param[7]->Val->Pointer);
}

pcvoid(computeTOTP)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->UnsignedInteger = computeTOTP((totp*)Param[0]->Val->Pointer);
}

pcvoid(loadTOTPs)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = loadTOTPs((totp*)Param[0]->Val->Pointer);
}

pcvoid(addTOTP)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    addTOTP((char*)Param[0]->Val->Pointer, (char*)Param[1]->Val->Pointer);
}

pcvoid(removeTOTP)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    removeTOTP(Param[0]->Val->Integer);
}

pcvoid(renameTOTP)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    renameTOTP(Param[0]->Val->Integer, (char*)Param[1]->Val->Pointer);
}

// versionProvider.hpp

pcvoid(getVersion)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getVersion();
}

pcvoid(getTimestamp)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Pointer = (char*)getTimestamp();
}

pcvoid(isBuildExpired)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    ReturnValue->Val->Integer = isBuildExpired();
}


const struct LibraryFunction UtilitiesAboutGUI[] =
{
    { pcfunc(aboutScreen),           "void aboutScreen(void);" },
    { pcfunc(buildExpiredScreen),    "void buildExpiredScreen(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesCalendarGUI[] =
{
    { pcfunc(viewCalendar),          "void viewCalendar(int);" },
    { pcfunc(viewMonthCalendar),     "int viewMonthCalendar(int);" },
    { pcfunc(viewWeekCalendar),      "int viewWeekCalendar();" },
    { pcfunc(viewWeekCalendarChild), "int viewWeekCalendarChild(void*, int*, int*, int*, int*, int*);" },
    { pcfunc(viewEvents),            "void viewEvents(int, int, int);" },
    { pcfunc(viewEvent),             "void viewEvent(void*);" },
    { pcfunc(viewEventsChild),       "int viewEventsChild(void*, int, int, int);" },
    { pcfunc(fillInputDate),         "void fillInputDate(void*, char*);" },
    { pcfunc(fillInputTime),         "void fillInputTime(void*, char*);" },
    { pcfunc(eventEditor),           "int eventEditor(int, int, int, int, void*, int);" },
    { pcfunc(drawCalendar),          "void drawCalendar(int, int, int, int, int*, int*, int*, int*);" },
    { pcfunc(moveEventScreen),       "int moveEventScreen(void*, int, int, int);" },
    { pcfunc(deleteEventPrompt),     "int deleteEventPrompt(void*, int, int, int);" },
    { pcfunc(deleteAllEventsPrompt), "int deleteAllEventsPrompt(int, int, int, int);" },
    { pcfunc(selectDateScreen),      "int selectDateScreen(int*, int*, int*, char*, char*, int);" },
    { pcfunc(invalidFieldMsg),       "void invalidFieldMsg(int);" },
    { pcfunc(setReminderScreen),     "void setReminderScreen(void*);" },
    { pcfunc(setCategoryPrompt),     "int setCategoryPrompt(void*);" },
    { pcfunc(viewEventAtPos),        "void viewEventAtPos(void*, int);" },
    { pcfunc(searchEventsScreen),    "void searchEventsScreen(int, int, int);" },
    { pcfunc(drawBusymapDay),        "void drawBusymapDay(void*, int, int, int, int, int, int, int);" },
    { pcfunc(drawBusymapDay),        "void drawBusymapWeek(int, int, int, int, int, int, int);" },
    { pcfunc(calendarToolsMenu),     "void calendarToolsMenu(int, int, int);" },
    { pcfunc(databaseRepairScreen),  "void databaseRepairScreen(void);" },
    { pcfunc(databaseTrimScreen),    "void databaseTrimScreen(void);" },
    { pcfunc(eventImportScreen),     "void eventImportScreen(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesCalendarProvider[] =
{
    { pcfunc(eventToString),         "char* eventToString(void*, char*);" },
    { pcfunc(stringToEvent),         "void stringToEvent(char*, void*);" },
    { pcfunc(stringToSimpleEvent),   "void stringToSimpleEvent(char*, void*);" },
    { pcfunc(eventDateToFilename),   "void eventDateToFilename(void*, unsigned short*, char*);" },
    { pcfunc(addEvent),              "int addEvent(void*, char*, int);" },
    { pcfunc(replaceEventFile),      "int replaceEventFile(void*, void*, char*, int);" },
    { pcfunc(removeEvent),           "void removeEvent(void*, void*, char*, int, int);" },
    { pcfunc(removeDay),             "void removeDay(void*, char*);" },
    { pcfunc(getEvents),             "int getEvents(void*, char*, void*, int, void*);" },
    { pcfunc(getEventCountsForMonth),"void getEventCountsForMonth(int, int, int*, int*);" },
    { pcfunc(searchEventsOnDay),     "int searchEventsOnDay(void*, char*, void*, char*, int);" },
    { pcfunc(searchEventsOnYearOrMonth),"int searchEventsOnYearOrMonth(int, int, char*, void*, char*, int);" },
    { pcfunc(repairEventFile),       "void repairEventFile(char*, char*, int*, int*);" },
    { pcfunc(setDBcorruptFlag),      "void setDBcorruptFlag(int);" },
    { pcfunc(getDBcorruptFlag),      "int getDBcorruptFlag(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesChronoGUI[] =
{
    { pcfunc(formatChronoString),    "void formatChronoString(void*, int, unsigned char*, int);" },
    { pcfunc(stopAndUninstallStubTimer),"void stopAndUninstallStubTimer();" },
    { pcfunc(chronoScreen),          "void chronoScreen();" },
    { pcfunc(startSelectedChronos),  "void startSelectedChronos(void*, void*, int);" },
    { pcfunc(stopSelectedChronos),   "void stopSelectedChronos(void*, void*, int);" },
    { pcfunc(clearSelectedChronos),  "void clearSelectedChronos(void*, void*, int);" },
    { pcfunc(setChronoScreen),       "void setChronoScreen(void*, void*, int);" },
    { pcfunc(setPresetChrono),       "void setPresetChrono(void*, void*);" },
    { pcfunc(getLastCompleteChrono), "int getLastCompleteChrono(void);" },
    { pcfunc(checkChronoComplete),   "void checkChronoComplete(void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesChronoProvider[] =
{
    { pcfunc(saveChronoArray),       "void saveChronoArray(void*, int);" },
    { pcfunc(loadChronoArray),       "void loadChronoArray(void*, int);" },
    // each 64-bit int is broken into two 32-bits ints for compatibility. most significant int first
    { pcfunc(setChrono),             "void setChrono(void*, int, int, int, int);" },
    { pcfunc(stopChrono),            "void stopChrono(void*);" },
    { pcfunc(startChrono),           "void startChrono(void*);" },
    { pcfunc(clearChrono),           "void clearChrono(void*);" },
    { pcfunc(getChronoArrayPtr),     "void* getChronoArrayPtr();" },
    { pcfunc(setChronoArrayPtr),     "void setChronoArrayPtr(void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesEditorGUI[] =
{
    { pcfunc(textfileEditor),        "void textfileEditor(char*, char*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesFileGUI[] =
{
    { pcfunc(fileManager),           "void fileManager(void);" },
    { pcfunc(getFileManagerStatus),  "void getFileManagerStatus(char*, int, int);" },
    { pcfunc(fileManagerChild),      "int fileManagerChild(char*, int*, int*, int*, void*, char*);" },
    { pcfunc(deleteFilesPrompt),     "int deleteFilesPrompt(void*, void*);" },
    { pcfunc(newFolderScreen),       "int newFolderScreen(char*);" },
    { pcfunc(newG3Pscreen),          "int newG3Pscreen(char*);" },
    { pcfunc(renameFileScreen),      "int renameFileScreen(void*, void*, char*);" },
    { pcfunc(searchFilesScreen),     "int searchFilesScreen(char*, char*, int);" },
    { pcfunc(viewFileInfo),          "int viewFileInfo(void*, int, int, int);" },
    { pcfunc(viewFileAsText),        "void viewFileAsText(char*);" },
    { pcfunc(viewClipboard),         "void viewClipboard(void*, int*);" },
    { pcfunc(folderStatsScreen),     "void folderStatsScreen(void*, void*);" },
    { pcfunc(compressSelectedFiles), "void compressSelectedFiles(void*, void*);" },
    { pcfunc(decompressSelectedFiles),"void decompressSelectedFiles(void*, void*);" },
    { pcfunc(shortenDisplayPath),    "void shortenDisplayPath(char*, char*, int);" },
    { pcfunc(buildIconTable),        "void buildIconTable(void*);" },
    { pcfunc(overwriteFilePrompt),   "int overwriteFilePrompt(char*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesFileProvider[] =
{
    { pcfunc(sortFiles),             "void sortFiles(void*, int);" },
    { pcfunc(getFiles),              "int getFiles(void*, char*, int*);" },
    { pcfunc(searchForFiles),        "int searchForFiles(void*, char*, char*, int, int, int, int, int*, int);" },
    { pcfunc(deleteFiles),           "void deleteFiles(void*, void*);" },
    { pcfunc(renameFile),            "void renameFile(char*, char*);" },
    { pcfunc(filenameToName),        "char* filenameToName(char*);" },
    { pcfunc(copyFile),              "void copyFile(char*, char*);" },
    { pcfunc(pasteClipboard),        "void pasteClipboard(void*, char*, int);" },
    { pcfunc(filenameToIcon),        "int filenameToIcon(char*);" },
    { pcfunc(stringEndsInG3A),       "int stringEndsInG3A(char*);" },
    { pcfunc(stringEndsInJPG),       "int stringEndsInJPG(char*);" },
    { pcfunc(createFolderRecursive), "void createFolderRecursive(char*);" },
    { pcfunc(compressFile),          "void compressFile(char*, char*, int, int);" },
    { pcfunc(isFileCompressed),      "int isFileCompressed(char*, int*);" },
    { pcfunc(fileOpen),              "int fileOpen(char*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesFirstRunGUI[] =
{
    { pcfunc(firstRunWizard),        "void firstRunWizard(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesGraphicsProvider[] =
{
    { pcfunc(drawRectangle),         "void drawRectangle(int, int, int, int, unsigned short);" },
    { pcfunc(drawLine),              "void drawLine(int, int, int, int, int);" },
    { pcfunc(drawFilledCircle),      "void drawFilledCircle(int, int, int, unsigned short);" },
    { pcfunc(drawCircularCountdownIndicator),"void drawCircularCountdownIndicator(int, int, int, unsigned short, unsigned short, int, int);" },
    { pcfunc(replaceColorInArea),    "void replaceColorInArea(int, int, int, int, unsigned short, unsigned short);" },
    { pcfunc(invertArea),            "void invertArea(short, short, short, short);" },
    { pcfunc(darkenStatusbar),       "void darkenStatusbar(void);" },
    { pcfunc(darkenFkeys),           "void darkenFkeys(int);" },
    { pcfunc(drawArrowDown),         "void drawArrowDown(int, int, int);" },
    { pcfunc(drawFkeyPopup),         "void drawFkeyPopup(int, char*);" },
    { pcfunc(CopySpriteMasked),      "void CopySpriteMasked(unsigned short*, int, int, int, int, unsigned short);" },
    { pcfunc(CopySpriteNbitMasked),  "void CopySpriteNbitMasked(unsigned char*, int, int, int, int, unsigned short*, unsigned short, unsigned int);" },
    { pcfunc(drawSegvaultLogo),      "void drawSegvaultLogo(int, int);" },
    { pcfunc(textColorToFullColor),  "int textColorToFullColor(int);" },
    { pcfunc(progressMessage),       "void progressMessage(char*, int, int);" },
    { pcfunc(closeProgressMessage),  "void closeProgressMessage(void);" },
    { pcfunc(printCentered),         "void printCentered(char*, int, int, int);" },
    { pcfunc(clearLine),             "void clearLine(int, int, unsigned short);" },
    { pcfunc(mPrintXY),              "void mPrintXY(int, int, char*, int, int);" },
    { pcfunc(multiPrintXY),          "void multiPrintXY(int, int, char*, int, int);" },
    { pcfunc(multiPrintMini),        "void multiPrintMini(int, int, char*, int);" },
    { pcfunc(mMsgBoxPush),           "void mMsgBoxPush(int);" },
    { pcfunc(mMsgBoxPop),            "void mMsgBoxPop(void);" },
    { pcfunc(popAllMsgBoxes),        "void popAllMsgBoxes(void);" },
    { pcfunc(getMsgBoxCount),        "int getMsgBoxCount(void);" },
    { pcfunc(drawScreenTitle),       "void drawScreenTitle(char*, char*);" },
    { pcfunc(drawFkeyLabels),        "void drawFkeyLabels(int, int, int, int, int, int);" },
    { pcfunc(drawRGB24toRGB565),     "int drawRGB24toRGB565(int, int, int);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesHardwareProvider[] =
{
    { pcfunc(CPU_change_freq),       "void CPU_change_freq(int);" },
    { pcfunc(getRawBacklightSubLevel),"int getRawBacklightSubLevel(void);" },
    { pcfunc(setRawBacklightSubLevel),"void setRawBacklightSubLevel(int);" },
    { pcfunc(getHardwareID),         "void getHardwareID(char*);" },
    { pcfunc(getHardwareModel),      "int getHardwareModel(void);" },
    { pcfunc(getIsEmulated),         "int getIsEmulated(void);" },
    { pcfunc(setBrightnessToStartupSetting),"void setBrightnessToStartupSetting(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesHomeGUI[] =
{
    { pcfunc(homeScreen),            "void homeScreen(int);" },
    { pcfunc(powerMenu),             "void powerMenu(int*);" },
    { pcfunc(lightMenu),             "void lightMenu(int*);" },
    { pcfunc(timeMenu),              "void timeMenu(int*);" },
    { pcfunc(memsysMenu),            "void memsysMenu(int*);" },
    { pcfunc(toolsMenu),             "void toolsMenu(int*);" },
    { pcfunc(handleHomePane),        "void handleHomePane(int, int*)" },
    { pcfunc(paneHandleBasicKeys),   "void paneHandleBasicKeys(int, int*)" },
    { pcfunc(eventsPane),            "void eventsPane(int, int*);" },
    { pcfunc(memoryUsagePane),       "void memoryUsagePane(int, int*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesImageGUI[] =
{
    { pcfunc(viewImage),             "void viewImage(char*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesInputGUI[] =
{
    { pcfunc(doTextInput),           "int doTextInput(void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesKeyboardProvider[] =
{
    { pcfunc(saveVRAMandCallSettings),"void saveVRAMandCallSettings(void);" },
    { pcfunc(mGetKey),               "void mGetKey(int*, int);" },
    { pcfunc(setmGetKeyMode),        "void setmGetKeyMode(int);" },
    { pcfunc(SetGetkeyToMainFunctionReturnFlag),"unsigned int SetGetkeyToMainFunctionReturnFlag(unsigned int);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesLightGUI[] =
{
    { pcfunc(lantern),               "void lantern(void);" },
    { pcfunc(flashLight),            "void flashLight(int);" },
    { pcfunc(morseLight),            "void morseLight(void);" },
    { pcfunc(colorLight),            "void colorLight(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesLockGUI[] =
{
    { pcfunc(passwordInput),         "int passwordInput(int, int, unsigned char*);" },
    { pcfunc(setPassword),           "int setPassword();" },
    { pcfunc(unlockCalc),            "int unlockCalc();" },
    { pcfunc(lockApp),               "void lockApp();" },
    { pcfunc(openRunMat),            "void openRunMat();" },
    { pcfunc(returnToUtilitiesHandler),"void returnToUtilitiesHandler();" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesLockProvider[] =
{
    { pcfunc(hashPassword),          "void hashPassword(unsigned char*, unsigned char*);" },
    { pcfunc(comparePasswordHash),   "int comparePasswordHash(unsigned char*);" },
    { pcfunc(savePassword),          "int savePassword(unsigned char*);" },
    { pcfunc(isPasswordSet),         "int isPasswordSet(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesMemsysGUI[] =
{
    { pcfunc(memoryCapacityScreen),  "void memoryCapacityScreen(int);" },
    { pcfunc(getAddins),             "int getAddins(void*);" },
    { pcfunc(addinManager),          "void addinManager(void);" },
    { pcfunc(addinManagerChild),     "int addinManagerChild(void*);" },
    { pcfunc(changeFKeyColor),       "void changeFKeyColor(void);" },
    { pcfunc(systemInfo),            "void systemInfo(void);" },
    { pcfunc(userInfo),              "void userInfo(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesMenuGUI[] =
{
    { pcfunc(doMenu),                "int doMenu(void*, void*);" },
    { pcfunc(getMenuSelectionSeparators),"int getMenuSelectionSeparators(void*, int*, int*);" },
    { pcfunc(closeMsgBox),           "int closeMsgBox(int, int);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesPowerGUI[] =
{
    { pcfunc(setPoweroffTimeout),    "void setPoweroffTimeout(void);" },
    { pcfunc(setBacklightTimeout),   "void setBacklightTimeout(void);" },
    { pcfunc(setBacklightLevel),     "void setBacklightLevel(void);" },
    { pcfunc(powerInformation),      "void powerInformation(void);" },
    { pcfunc(getPLLinfo),            "int getPLLinfo(unsigned int, char**, char**, int*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesSelectorGUI[] =
{
    { pcfunc(doSelector),            "int doSelector(void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesSettingsGUI[] =
{
    { pcfunc(settingsMenu),          "void settingsMenu(void);" },
    { pcfunc(calendarSettingsMenu),  "void calendarSettingsMenu(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesSettingsProvider[] =
{
    { pcfunc(getSetting),            "unsigned char getSetting(int);" },
    { pcfunc(setSetting),            "void setSetting(int, unsigned char, int);" },
    { pcfunc(loadSettings),          "int loadSettings();" },
    { pcfunc(saveSettings),          "void saveSettings();" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesStringsProvider[] =
{
    { pcfunc(isMBfirst),             "int isMBfirst(char);" },
    { pcfunc(toksplit),              "char *toksplit(char*, char, char*, int);" },
    { pcfunc(strEndsWith),           "int strEndsWith(char*, char*);" },
    { pcfunc(memmem),                "void* memmem(char*, int, char*, int, int);" },
    { pcfunc(strncpy_retlen),        "int strncpy_retlen(char*, char*, int);" },
    { pcfunc(strncpy_replace),       "char* strncpy_replace(char*, char*, int, char, char);" },
    { pcfunc(stringToMini),          "void stringToMini(char*, char*);" },
    { pcfunc(base32_decode),         "int base32_decode(unsigned char*, unsigned char*, int);" },
    { pcfunc(base32_validate),       "int base32_validate(char*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesTasksGUI[] =
{
    { pcfunc(viewTasks),             "void viewTasks(void);" },
    { pcfunc(viewTasksChild),        "int viewTasksChild(void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesTextGUI[] =
{
    { pcfunc(doTextArea),            "int doTextArea(void*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesTextEditGUI[] =
{
    { pcfunc(doTextEdit),            "int doTextEdit(void*)" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesTimeGUI[] =
{
    { pcfunc(drawLongDate),          "void drawLongDate(int, int, int, int, int);" },
    { pcfunc(drawAnalogClock),       "void drawAnalogClock(int, int, int, int, int);" },
    { pcfunc(drawAnalogChronometer), "void drawAnalogChronometer(int, int, int, int, int, int, int, int, int);" },
    { pcfunc(RTCunadjustedWizard),   "void RTCunadjustedWizard(int);" },
    { pcfunc(setTimeScreen),         "void setTimeScreen(int);" },
    { pcfunc(setDateScreen),         "void setDateScreen(int);" },
    { pcfunc(currentTimeToBasicVar), "void currentTimeToBasicVar(void);" },
    { pcfunc(drawHomeClock),         "void drawHomeClock(int, int);" },
    { pcfunc(setTimezone),           "void setTimezone(void);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesTimeProvider[] =
{
    { pcfunc(getMonthDays),          "int getMonthDays(int);" },
    { pcfunc(getMonthDaysWithLeap),  "int getMonthDaysWithLeap(int, int);" },
    { pcfunc(getCurrentDOWAsString), "char* getCurrentDOWAsString();" },
    { pcfunc(getCurrentDOWAsShortString),"char* getCurrentDOWAsShortString();" },
    { pcfunc(getCurrentMonthAsString),"char* getCurrentMonthAsString();" },
    { pcfunc(getDOWAsString),        "char* getDOWAsString(int);" },
    { pcfunc(getDOWAsShortString),   "char* getDOWAsShortString(int);" },
    { pcfunc(getMonthAsString),      "char* getMonthAsString(int);" },
    { pcfunc(isLeap),                "int isLeap(int);" },
    { pcfunc(dow),                   "int dow(int, int, int);" },
    { pcfunc(getDayOfYear),          "int getDayOfYear(int, int, int);" },
    { pcfunc(getWeekNumber),         "int getWeekNumber(int, int, int);" },
    { pcfunc(getCurrentYear),        "int getCurrentYear();" },
    { pcfunc(getCurrentMonth),       "int getCurrentMonth();" },
    { pcfunc(getCurrentDay),         "int getCurrentDay();" },
    { pcfunc(getCurrentHour),        "int getCurrentHour();" },
    { pcfunc(getCurrentMinute),      "int getCurrentMinute();" },
    { pcfunc(getCurrentSecond),      "int getCurrentSecond();" },
    { pcfunc(getCurrentMillisecond), "int getCurrentMillisecond();" },
    { pcfunc(dateTimeToUEBT),        "void dateTimeToUEBT(int*, int*, int, int, int, int, int, int, int);" },
    { pcfunc(setTime),               "void setTime(int, int, int);" },
    { pcfunc(setDate),               "void setDate(int, int, int);" },
    { pcfunc(blockForTicks),         "void blockForTicks(int);" },
    { pcfunc(blockForMilliseconds),  "void blockForMilliseconds(int);" },
    { pcfunc(tickDifferenceToMilliseconds),"int tickDifferenceToMilliseconds(int, int);" },
    { pcfunc(isTimeValid),           "int isTimeValid(int, int, int);" },
    { pcfunc(isDateValid),           "int isDateValid(int, int, int);" },
    { pcfunc(daysToDate),            "void daysToDate(int, int*, int*, int*);" },
    { pcfunc(dateToDays),            "int dateToDays(int,,int, int);" },
    { pcfunc(stringToDate),          "void stringToDate(char*, int*, int*, int*, int);" },
    { pcfunc(stringToTime),          "void stringToTime(char*, int*, int*, int*);" },
    { pcfunc(getInputDateFormatHint),"char* getInputDateFormatHint(int);" },
    { pcfunc(isDSTchangeToday),      "int isDSTchangeToday();" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesToolsGUI[] =
{
    { pcfunc(balanceManager),        "void balanceManager(void);" },
    { pcfunc(balanceManagerChild),   "int balanceManagerChild(void*, char*);" },
    { pcfunc(addTransactionWizard),  "int addTransactionWizard(char*);" },
    { pcfunc(deleteTransactionPrompt),"int deleteTransactionPrompt(void*, char*, int, int);" },
    { pcfunc(viewTransaction),       "void viewTransaction(void*);" },
    { pcfunc(createWalletWizard),    "int createWalletWizard(int);" },
    { pcfunc(changeWalletScreen),    "int changeWalletScreen(char*);" },
    { pcfunc(deleteWalletPrompt),    "int deleteWalletPrompt(char*);" },
    { pcfunc(renameWalletScreen),    "int renameWalletScreen(char*, char*);" },
    { pcfunc(passwordGenerator),     "void passwordGenerator(void);" },
    { pcfunc(totpClient),            "void totpClient(void);" },
    { pcfunc(viewTOTPcode),          "void viewTOTPcode(void*);" },
    { pcfunc(addTOTPwizard),         "int addTOTPwizard(void);" },
    { pcfunc(renameTOTPscreen),      "int renameTOTPscreen(int, char*);" },
    { pcfunc(deleteTOTPprompt),      "int deleteTOTPprompt(int);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesToolsProvider[] =
{
    { pcfunc(currencyToString),      "void currencyToString(char*, void*);" },
    { pcfunc(stringToCurrency),      "int stringToCurrency(void*, char*);" },
    { pcfunc(addCurrency),           "void addCurrency(void*, void*);" },
    { pcfunc(subtractCurrency),      "void subtractCurrency(void*, void*);" },
    { pcfunc(walletNameToPath),      "void walletNameToPath(char*, char*);" },
    { pcfunc(getWalletBalance),      "void getWalletBalance(void*, char*);" },
    { pcfunc(getCurrentWallet),      "int getCurrentWallet(char*);" },
    { pcfunc(setCurrentWallet),      "void setCurrentWallet(char*);" },
    { pcfunc(transactionToCalendarEvent),"void transactionToCalendarEvent(void*, void*);" },
    { pcfunc(calendarEventToTransaction),"void calendarEventToTransaction(void*, void*);" },
    { pcfunc(getWalletTransactions), "int getWalletTransactions(char*, void*, int);" },
    { pcfunc(addTransaction),        "void addTransaction(void*, char*);" },
    { pcfunc(replaceWalletTransactions),"void replaceWalletTransactions(void*, char*, int);" },
    { pcfunc(deleteTransaction),     "void deleteTransaction(void*, char*, int, int);" },
    { pcfunc(createWallet),          "void createWallet(char*, void*);" },
    { pcfunc(deleteWallet),          "void deleteWallet(char*);" },
    { pcfunc(generateRandomString),  "void generateRandomString(char*, int, int, int, int, int, int, int*);" },
    { pcfunc(computeTOTP),           "unsigned int computeTOTP(void*);" },
    { pcfunc(loadTOTPs),             "int loadTOTPs(void*);" },
    { pcfunc(addTOTP),               "void addTOTP(char*, char*);" },
    { pcfunc(removeTOTP),            "void removeTOTP(int);" },
    { pcfunc(renameTOTP),            "void renameTOTP(int, char*);" },
    { NULL,         NULL }
};

const struct LibraryFunction UtilitiesVersionProvider[] =
{
    { pcfunc(getVersion),            "char* getVersion();" },
    { pcfunc(getTimestamp),          "char* getTimestamp();" },
    { pcfunc(isBuildExpired),        "int isBuildExpired();" },
    { NULL,         NULL }
};


// Struct init helpers:

pcvoid(initMenu)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Menu s;
    *(Menu*)Param[0]->Val->Pointer = s;
}

pcvoid(initMenuItem)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    MenuItem s;
    *(MenuItem*)Param[0]->Val->Pointer = s;
}

pcvoid(initEventDate)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    EventDate s;
    *(EventDate*)Param[0]->Val->Pointer = s;
}

pcvoid(initEventTime)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    EventTime s;
    *(EventTime*)Param[0]->Val->Pointer = s;
}

pcvoid(initCalendarEvent)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    CalendarEvent s;
    *(CalendarEvent*)Param[0]->Val->Pointer = s;
}

pcvoid(initSimpleCalendarEvent)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    SimpleCalendarEvent s;
    *(SimpleCalendarEvent*)Param[0]->Val->Pointer = s;
}

pcvoid(initChronometer)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    chronometer s;
    *(chronometer*)Param[0]->Val->Pointer = s;
}

pcvoid(initFile)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    File s;
    *(File*)Param[0]->Val->Pointer = s;
}

pcvoid(initTextInput)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    textInput s;
    *(textInput*)Param[0]->Val->Pointer = s;
}

pcvoid(initAddIn)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    AddIn s;
    *(AddIn*)Param[0]->Val->Pointer = s;
}

pcvoid(initSelector)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Selector s;
    *(Selector*)Param[0]->Val->Pointer = s;
}

pcvoid(initTextElement)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    textElement s;
    *(textElement*)Param[0]->Val->Pointer = s;
}

pcvoid(initTextArea)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    textArea s;
    *(textArea*)Param[0]->Val->Pointer = s;
}

pcvoid(initTextEdit)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    textEdit s;
    *(textEdit*)Param[0]->Val->Pointer = s;
}

pcvoid(initCurrency)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Currency s;
    *(Currency*)Param[0]->Val->Pointer = s;
}

pcvoid(initTransaction)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    Transaction s;
    *(Transaction*)Param[0]->Val->Pointer = s;
}

pcvoid(initTOTP)(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) {
    totp s;
    *(totp*)Param[0]->Val->Pointer = s;
}

const struct LibraryFunction UtilitiesStructInitializers[] =
{
    { pcfunc(initEventDate),         "void initEventDate(void*);" },
    { pcfunc(initEventTime),         "void initEventTime(void*);" },
    { pcfunc(initCalendarEvent),     "void initCalendarEvent(void*);" },
    { pcfunc(initSimpleCalendarEvent),"void initSimpleCalendarEvent(void*);" },
    { pcfunc(initChronometer),       "void initChronometer(void*);" },
    { pcfunc(initFile),              "void initFile(void*);" },
    { pcfunc(initTextInput),         "void initTextInput(void*);" },
    { pcfunc(initAddIn),             "void initAddIn(void*);" },
    { pcfunc(initMenu),              "void initMenu(void*);" },
    { pcfunc(initMenuItem),          "void initMenuItem(void*);" },
    { pcfunc(initSelector),          "void initSelector(void*);" },
    { pcfunc(initTextElement),       "void initTextElement(void*);" },
    { pcfunc(initTextArea),          "void initTextArea(void*);" },
    { pcfunc(initTextEdit),          "void initTextEdit(void*);" },
    { pcfunc(initCurrency),          "void initCurrency(void*);" },
    { pcfunc(initTransaction),       "void initTransaction(void*);" },
    { pcfunc(initTOTP),              "void initTOTP(void*);" },
    { NULL,         NULL }
};

extern "C" {
    void PlatformLibraryInit_cpp();
}

void PlatformLibraryInit_cpp()
{
    IncludeRegister("fxcg/app.h", &PrizmSetupFunc, &PrizmAppSyscalls[0], NULL);

    // display:
    IncludeRegister("fxcg/display.h", &PrizmSetupFunc, &PrizmDisplaySyscalls[0], "struct display_fill{int x1; int y1; int x2; int y2; unsigned char mode;};");
    
    const char* definition = "enum{TEXT_COLOR_BLACK=0,TEXT_COLOR_BLUE=1,TEXT_COLOR_GREEN=2,TEXT_COLOR_CYAN=3,TEXT_COLOR_RED=4,TEXT_COLOR_PURPLE=5,TEXT_COLOR_YELLOW=6,TEXT_COLOR_WHITE=7};";
    PicocParse("fxcg/display.h", definition, strlen(definition), TRUE, TRUE, FALSE);
    
    definition = "enum{TEXT_MODE_NORMAL=0,TEXT_MODE_INVERT=1,TEXT_MODE_TRANSPARENT_BACKGROUND=0x20,TEXT_MODE_AND=0x21};";
    PicocParse("fxcg/display.h", definition, strlen(definition), TRUE, TRUE, FALSE);
    
    definition = "struct scrollbar{unsigned int I1;unsigned int indicatormaximum;unsigned int indicatorheight;unsigned int indicatorpos;unsigned int I5;unsigned short barleft;unsigned short bartop;unsigned short barheight;unsigned short barwidth;};";
    PicocParse("fxcg/display.h", definition, strlen(definition), TRUE, TRUE, FALSE);
    // file:
    IncludeRegister("fxcg/file.h", &PrizmSetupFunc, &PrizmFileSyscalls[0], NULL);

    IncludeRegister("fxcg/heap.h", &PrizmSetupFunc, &PrizmHeapSyscalls[0], NULL);

    IncludeRegister("fxcg/keyboard.h", &PrizmSetupFunc, &PrizmKeyboardSyscalls[0], NULL);

    IncludeRegister("fxcg/misc.h", &PrizmSetupFunc, &PrizmMiscSyscalls[0], NULL);

    IncludeRegister("fxcg/rtc.h", &PrizmSetupFunc, &PrizmRTCSyscalls[0], NULL);

    IncludeRegister("fxcg/serial.h", &PrizmSetupFunc, &PrizmSerialSyscalls[0], NULL);
    
    IncludeRegister("fxcg/system.h", &PrizmSetupFunc, &PrizmSystemSyscalls[0], NULL);

    // Utilities integration:
    IncludeRegister("utilities/aboutGUI.h", &PrizmSetupFunc, &UtilitiesAboutGUI[0], NULL);
    IncludeRegister("utilities/calendarGUI.h", &PrizmSetupFunc, &UtilitiesCalendarGUI[0], NULL);
    IncludeRegister("utilities/calendarProvider.h", &PrizmSetupFunc, &UtilitiesCalendarProvider[0], NULL);
    IncludeRegister("utilities/chronoGUI.h", &PrizmSetupFunc, &UtilitiesChronoGUI[0], NULL);
    IncludeRegister("utilities/chronoProvider.h", &PrizmSetupFunc, &UtilitiesChronoProvider[0], NULL);
    IncludeRegister("utilities/editorGUI.h", &PrizmSetupFunc, &UtilitiesEditorGUI[0], NULL);
    IncludeRegister("utilities/fileGUI.h", &PrizmSetupFunc, &UtilitiesFileGUI[0], NULL);
    IncludeRegister("utilities/fileProvider.h", &PrizmSetupFunc, &UtilitiesFileProvider[0], NULL);
    IncludeRegister("utilities/firstRunGUI.h", &PrizmSetupFunc, &UtilitiesFirstRunGUI[0], NULL);
    IncludeRegister("utilities/graphicsProvider.h", &PrizmSetupFunc, &UtilitiesGraphicsProvider[0], NULL);
    IncludeRegister("utilities/hardwareProvider.h", &PrizmSetupFunc, &UtilitiesHardwareProvider[0], NULL);
    IncludeRegister("utilities/homeGUI.h", &PrizmSetupFunc, &UtilitiesHomeGUI[0], NULL);
    IncludeRegister("utilities/imageGUI.h", &PrizmSetupFunc, &UtilitiesImageGUI[0], NULL);
    IncludeRegister("utilities/inputGUI.h", &PrizmSetupFunc, &UtilitiesInputGUI[0], NULL);
    IncludeRegister("utilities/keyboardProvider.h", &PrizmSetupFunc, &UtilitiesKeyboardProvider[0], NULL);
    IncludeRegister("utilities/lightGUI.h", &PrizmSetupFunc, &UtilitiesLightGUI[0], NULL);
    IncludeRegister("utilities/lockGUI.h", &PrizmSetupFunc, &UtilitiesLockGUI[0], NULL);
    IncludeRegister("utilities/lockProvider.h", &PrizmSetupFunc, &UtilitiesLockProvider[0], NULL);
    IncludeRegister("utilities/memsysGUI.h", &PrizmSetupFunc, &UtilitiesMemsysGUI[0], NULL);
    IncludeRegister("utilities/menuGUI.h", &PrizmSetupFunc, &UtilitiesMenuGUI[0], NULL);
    IncludeRegister("utilities/powerGUI.h", &PrizmSetupFunc, &UtilitiesPowerGUI[0], NULL);
    IncludeRegister("utilities/selectorGUI.h", &PrizmSetupFunc, &UtilitiesSelectorGUI[0], NULL);
    IncludeRegister("utilities/settingsGUI.h", &PrizmSetupFunc, &UtilitiesSettingsGUI[0], NULL);
    IncludeRegister("utilities/settingsProvider.h", &PrizmSetupFunc, &UtilitiesSettingsProvider[0], NULL);
    IncludeRegister("utilities/stringsProvider.h", &PrizmSetupFunc, &UtilitiesStringsProvider[0], NULL);
    IncludeRegister("utilities/tasksGUI.h", &PrizmSetupFunc, &UtilitiesTasksGUI[0], NULL);
    IncludeRegister("utilities/textGUI.h", &PrizmSetupFunc, &UtilitiesTextGUI[0], NULL);
    IncludeRegister("utilities/textEditGUI.h", &PrizmSetupFunc, &UtilitiesTextEditGUI[0], NULL);
    IncludeRegister("utilities/timeGUI.h", &PrizmSetupFunc, &UtilitiesTimeGUI[0], NULL);
    IncludeRegister("utilities/timeProvider.h", &PrizmSetupFunc, &UtilitiesTimeProvider[0], NULL);
    IncludeRegister("utilities/toolsGUI.h", &PrizmSetupFunc, &UtilitiesToolsGUI[0], NULL);
    IncludeRegister("utilities/toolsProvider.h", &PrizmSetupFunc, &UtilitiesToolsProvider[0], NULL);
    IncludeRegister("utilities/versionProvider.h", &PrizmSetupFunc, &UtilitiesVersionProvider[0], NULL);

    IncludeRegister("utilities/structInit.h", &PrizmSetupFunc, &UtilitiesStructInitializers[0], NULL);

    definition = "#define UTILITIES_API_VERSION 1";
    PicocParse("utilities/versionProvider.h", definition, strlen(definition), TRUE, TRUE, FALSE);
    definition = "#define FXCG_API_VERSION 1";
    PicocParse("utilities/versionProvider.h", definition, strlen(definition), TRUE, TRUE, FALSE);
}
