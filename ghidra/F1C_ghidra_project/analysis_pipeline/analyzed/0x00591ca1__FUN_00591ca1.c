// Function: FUN_00591ca1 @ 00591ca1
// Size (bytes): 37


undefined4 FUN_00591ca1(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_005e7640;
  do {
    if (*piVar1 == param_1) {
      return *(undefined4 *)(iVar2 * 8 + 0x5e7644);
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x5e7718);
  return 0;
}


