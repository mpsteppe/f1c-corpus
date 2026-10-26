// Function: FUN_0059a54d @ 0059a54d
// Size (bytes): 126


undefined4 __fastcall FUN_0059a54d(undefined4 param_1)

{
  LONG LVar1;
  
  if (DAT_008d4610 != 2) {
    if (DAT_008d4610 == 0) {
      LVar1 = InterlockedExchange(&DAT_008d4610,1);
      if (LVar1 == 0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_008d45f8);
        FUN_00587b3e(&LAB_0059a5cb);
        DAT_008d4610 = 2;
        goto LAB_0059a5bf;
      }
      if (LVar1 == 2) {
        DAT_008d4610 = 2;
      }
    }
    while (DAT_008d4610 == 1) {
      Sleep(1);
    }
    if (DAT_008d4610 != 2) {
      return param_1;
    }
  }
LAB_0059a5bf:
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_008d45f8);
  return param_1;
}


