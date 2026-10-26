// Function: FUN_00500eac @ 00500eac
// Strings:  [DebugSetMute, DebugSetMute, d3d8.dll, d3d8.dll, d3d8.dll]


void FUN_00500eac(undefined4 param_1)

{
  HMODULE pHVar1;
  
  if (DAT_008b0094 == (FARPROC)0x0) {
    if (DAT_008b0090 != (FARPROC)0x0) goto LAB_00500f35;
    pHVar1 = GetModuleHandleA("d3d8.dll");
    if (pHVar1 != (HMODULE)0x0) {
      pHVar1 = LoadLibraryA("d3d8.dll");
      if (pHVar1 != (HMODULE)0x0) {
        DAT_008b0094 = GetProcAddress(pHVar1,"DebugSetMute");
      }
    }
    pHVar1 = GetModuleHandleA("d3d8d.dll");
    if (pHVar1 != (HMODULE)0x0) {
      pHVar1 = LoadLibraryA("d3d8d.dll");
      if (pHVar1 != (HMODULE)0x0) {
        DAT_008b0090 = GetProcAddress(pHVar1,"DebugSetMute");
      }
    }
    if (DAT_008b0094 != (FARPROC)0x0) goto LAB_00500f21;
  }
  else {
LAB_00500f21:
    (*DAT_008b0094)(param_1);
  }
  if (DAT_008b0090 == (FARPROC)0x0) {
    return;
  }
LAB_00500f35:
                    /* WARNING: Could not recover jumptable at 0x00500f35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_008b0090)();
  return;
}


