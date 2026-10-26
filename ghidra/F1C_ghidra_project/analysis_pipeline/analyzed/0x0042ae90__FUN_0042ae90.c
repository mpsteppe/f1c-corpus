// Function: FUN_0042ae90 @ 0042ae90
// Size (bytes): 29


undefined4 __fastcall FUN_0042ae90(int param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x4588) - 1;
  return *(undefined4 *)(((uVar1 & ((int)uVar1 < 0) - 1) + 0x459) * 0x10 + param_1);
}


