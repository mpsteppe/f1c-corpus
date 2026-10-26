// Function: FUN_004dae00 @ 004dae00
// Size (bytes): 117


undefined1 __fastcall FUN_004dae00(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  if (*(float *)(param_1 + 0x14) < DAT_0059e440 != (*(float *)(param_1 + 0x14) == DAT_0059e440)) {
    return 1;
  }
  if (*(float *)(param_1 + 0x1c) < DAT_0059e440 != (*(float *)(param_1 + 0x1c) == DAT_0059e440)) {
    iVar1 = FUN_004d1b50(0);
    uVar2 = uVar3;
    if (((*(int *)(&DAT_005f073c + iVar1 * 0x48c0) == 1) &&
        (*(int *)(DAT_007c54e8 + 0x4060) <= *(int *)(param_1 + 0x20))) &&
       (*(int *)(DAT_007c54e8 + 0x4064) != 0)) {
      uVar2 = 1;
    }
    if (*(int *)(param_1 + 0x20) == DAT_005c329c) {
      return 1;
    }
  }
  return uVar2;
}


