// Function: FUN_0058e060 @ 0058e060
// Size (bytes): 84


undefined4 FUN_0058e060(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_0058dfc1();
  DAT_005e6d40 = TlsAlloc();
  if (DAT_005e6d40 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_0058ab58(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_005e6d40,lpTlsValue);
      if (BVar1 != 0) {
        FUN_0058e0b4(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}


