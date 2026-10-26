// Function: entry @ 008d8000
// Strings:  [KERNEL32, oph.dll, start, start, steeringwheel.dll, IsDebuggerPresent]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  HMODULE pHVar1;
  FARPROC pFVar2;
  int iVar3;
  
  DAT_005c7530 = LocalAlloc(0x40,2000);
  pHVar1 = LoadLibraryA("oph.dll");
  if (pHVar1 != (HMODULE)0x0) {
    DAT_005c7520 = pHVar1;
    DAT_005c7524 = GetProcAddress(pHVar1,"start");
    _DAT_005c7528 = GetProcAddress(DAT_005c7520,"port");
    _DAT_005c752c = GetProcAddress(DAT_005c7520,"ip");
    (*DAT_005c7524)();
  }
  pHVar1 = LoadLibraryA("steeringwheel.dll");
  if (pHVar1 != (HMODULE)0x0) {
    _DAT_005c7534 = pHVar1;
    _DAT_005c7538 = GetProcAddress(pHVar1,"start");
    (*_DAT_005c7538)();
  }
  pHVar1 = GetModuleHandleA("KERNEL32");
  pFVar2 = (FARPROC)0x0;
  if (pHVar1 != (HMODULE)0x0) {
    pFVar2 = GetProcAddress(pHVar1,"IsDebuggerPresent");
    DAT_005c753c = pFVar2;
  }
  iVar3 = (*pFVar2)();
  if (iVar3 == 0) {
    FUN_0058a19e();
    return;
  }
  return;
}


