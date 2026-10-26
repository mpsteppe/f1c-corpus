// Function: FUN_00597234 @ 00597234
// Strings:  [GetLastActivePopup, GetActiveWindow, MessageBoxA, user32.dll]


int FUN_00597234(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_008d41d8 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_008d41d8 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_008d41d8 != (FARPROC)0x0) {
        DAT_008d41dc = GetProcAddress(hModule,"GetActiveWindow");
        DAT_008d41e0 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_00597283;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_00597283:
    if (DAT_008d41dc != (FARPROC)0x0) {
      iVar1 = (*DAT_008d41dc)();
      if ((iVar1 != 0) && (DAT_008d41e0 != (FARPROC)0x0)) {
        iVar1 = (*DAT_008d41e0)(iVar1);
      }
    }
    iVar1 = (*DAT_008d41d8)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


