// Function: FUN_004a0ba0 @ 004a0ba0
// Size (bytes): 191


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a0ba0(int param_1)

{
  int iVar1;
  
  FUN_00419c50(param_1);
  if ((*(int *)(param_1 + 13000) == 0) && (DAT_007ce814 == 0)) {
    FUN_0040cde0(5,1);
    FUN_004ef5a0(1,0);
    if (*(int *)(param_1 + 0x4060) != 1) {
      iVar1 = FUN_004d1b50(0);
      if (((*(int *)(&DAT_005f073c + iVar1 * 0x48c0) == 1) &&
          (_DAT_0059f118 <
           (*(float *)(&DAT_005f0790 + iVar1 * 0x48c0) + _DAT_008acf90) - (float)_DAT_008afea0)) &&
         (DAT_008ad298 != 0x13)) {
        FUN_004a0c60();
      }
    }
  }
  if (*(int *)(param_1 + 0x4060) == 1) {
    FUN_004d8760(0x13,0);
  }
  return 0;
}


