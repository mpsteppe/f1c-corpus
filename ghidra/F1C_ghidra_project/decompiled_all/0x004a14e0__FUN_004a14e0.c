// Function: FUN_004a14e0 @ 004a14e0
// Strings:  [CUBEApp, CUBERealtime]


void FUN_004a14e0(void)

{
  if (DAT_007ce2e0 == DAT_007ce2dc) {
    DAT_007ce2dc = (HWND)0x0;
  }
  if (DAT_007ce2e0 != (HWND)0x0) {
    DestroyWindow(DAT_007ce2e0);
    UnregisterClassA(s_CUBERealtime_005cd0a4,DAT_007ce2a0);
    DAT_007ce2e0 = (HWND)0x0;
  }
  if (DAT_007ce2dc != (HWND)0x0) {
    DestroyWindow(DAT_007ce2dc);
    UnregisterClassA(s_CUBEApp_005cd090,DAT_007ce2a0);
    DAT_007ce2dc = (HWND)0x0;
  }
  ClipCursor((RECT *)0x0);
  return;
}


