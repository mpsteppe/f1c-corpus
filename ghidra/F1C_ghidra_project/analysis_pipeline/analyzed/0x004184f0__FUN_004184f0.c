// Function: FUN_004184f0 @ 004184f0
// Size (bytes): 107


undefined4 __fastcall FUN_004184f0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0xaf0) != '\0') {
    return 0;
  }
  if ((*(int *)(param_1 + 0xaf4) == 0) && (DAT_008ac4c4 != (int *)0x0)) {
    iVar1 = (**(code **)(*DAT_008ac4c4 + 0x60))();
    *(int *)(param_1 + 0xaf4) = iVar1;
    if (iVar1 != 0) {
      FUN_00418970(DAT_007cf3c8);
      FUN_004116b0();
      FUN_00415090();
      *(undefined1 *)(param_1 + 0xaf0) = 1;
      return 0;
    }
  }
  return 1;
}


