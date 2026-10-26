// Function: FUN_00589cc6 @ 00589cc6
// Size (bytes): 156


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589cc6(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  
  FUN_00589d6b();
  if (DAT_008d3eb0 == 1) {
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,param_1);
  }
  _DAT_008d3eac = 1;
  DAT_008d3ea8 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_008d5a54 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_008d5a50 - 4), DAT_008d5a54 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_008d5a54 <= puVar1);
    }
    FUN_00589d7d(&DAT_005be3dc,&DAT_005be3e4);
  }
  FUN_00589d7d(&DAT_005be3e8,&DAT_005be3f0);
  if (param_3 == 0) {
    FUN_0059d7d1();
    return;
  }
  FUN_00589d74();
  return;
}


