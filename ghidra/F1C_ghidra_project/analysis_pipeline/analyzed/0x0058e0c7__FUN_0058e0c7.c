// Function: FUN_0058e0c7 @ 0058e0c7
// Size (bytes): 103


DWORD * FUN_0058e0c7(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_005e6d40);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_0058ab58(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_005e6d40,lpTlsValue);
      if (BVar1 != 0) {
        FUN_0058e0b4(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_0058e122;
      }
    }
    __amsg_exit(0x10);
  }
LAB_0058e122:
  SetLastError(dwErrCode);
  return lpTlsValue;
}


