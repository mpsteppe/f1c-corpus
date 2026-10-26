// Function: FUN_004da840 @ 004da840
// Size (bytes): 330


undefined4 __fastcall FUN_004da840(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x10) = 2;
    iVar2 = FUN_004d1b50(0);
    if (((-1 < iVar2) && (iVar2 < DAT_005c329c)) && (*(int *)(&DAT_005f073c + iVar2 * 0x48c0) == 0))
    {
      *(undefined4 *)(param_1 + 0x10) = 1;
      *(undefined4 *)(param_1 + 0x18) = 0x40000000;
    }
  }
  else if (iVar2 == 1) {
    if (*(float *)(param_1 + 0x18) < DAT_0059e440 != (*(float *)(param_1 + 0x18) == DAT_0059e440)) {
      *(undefined4 *)(param_1 + 0x10) = 2;
      return 0;
    }
  }
  else if (iVar2 == 2) {
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar2 = FUN_004d1b50(0);
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(&DAT_005f0714 + iVar2 * 0x48c0);
    }
    cVar1 = FUN_004dad80();
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x1c) = 0x40000000;
    }
    uVar3 = FUN_004da990();
    *(undefined4 *)(param_1 + 0x20) = uVar3;
    cVar1 = FUN_004dae00();
    if (cVar1 != '\0') {
      if (DAT_007ce814 == 0) {
        iVar2 = FUN_004d1b50(0);
        if ((*(int *)(&DAT_005f073c + iVar2 * 0x48c0) == 1) &&
           (*(int *)(DAT_007c54e8 + 0x4064) != 0)) {
          FUN_004ef5a0(1,0);
          FUN_0040cde0(5,1);
          uVar3 = FUN_004d1b50(0);
          FUN_0040d240(uVar3);
          FUN_004d8760(0x11,0);
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}


