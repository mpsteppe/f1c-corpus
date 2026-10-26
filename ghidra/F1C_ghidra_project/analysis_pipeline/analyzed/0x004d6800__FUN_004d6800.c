// Function: FUN_004d6800 @ 004d6800
// Size (bytes): 47


void __fastcall FUN_004d6800(int param_1)

{
  FUN_00566650(&DAT_005ea438);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}


