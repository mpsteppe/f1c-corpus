// Function: FUN_004710d0 @ 004710d0
// Strings:  [Medium, Minimum]


undefined4 __fastcall FUN_004710d0(int param_1)

{
  *(undefined4 **)(param_1 + 0x31c) = &DAT_007d00a4;
  *(undefined4 *)(param_1 + 0x328) = 0;
  *(undefined4 *)(param_1 + 0x324) = 4;
  *(undefined4 *)(param_1 + 0x32c) = 1;
  *(undefined4 *)(param_1 + 0x330) = 1;
  FUN_00486f30(s_Minimum_005c6ec8,0xffffffff);
  FUN_00486f30(&PTR_DAT_005c32a4,0xffffffff);
  FUN_00486f30(s_Medium_005c6eb8,0xffffffff);
  FUN_00486f30(&DAT_005c32a8,0xffffffff);
  FUN_00486f30(&DAT_005c6eb0,0xffffffff);
  return 0;
}


