// Function: FUN_004a13d9 @ 004a13d9
// Strings:  [CUBEApp, CUBERealtime]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a13d9(void)

{
  ATOM AVar1;
  RECT *unaff_EBX;
  code *unaff_EBP;
  
  DAT_007ce2dc = (HWND)(*unaff_EBP)(1,s_CUBEApp_005cd090,&stack0x00000058);
  _DAT_007ce288 = unaff_EBX;
  AVar1 = RegisterClassExA((WNDCLASSEXA *)&DAT_007ce270);
  if (AVar1 == 0) {
    return 1;
  }
  DAT_007ce2e0 = (*unaff_EBP)();
  ClipCursor(unaff_EBX);
  ShowWindow(DAT_007ce2dc,1);
  DAT_007ce2e4 = 1;
  return 0;
}


