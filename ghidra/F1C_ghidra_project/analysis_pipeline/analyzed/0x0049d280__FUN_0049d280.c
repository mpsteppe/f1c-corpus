// Function: FUN_0049d280 @ 0049d280
// Size (bytes): 150


void __fastcall FUN_0049d280(int param_1)

{
  uint uVar1;
  
  if ((((*(int *)(param_1 + 0x20) != 0) && (*(int *)(param_1 + 0x24) != 0)) &&
      (*(int *)(param_1 + 0x28) != 0)) &&
     ((*(int *)(param_1 + 0x2c) != 0 &&
      ((*(int *)(DAT_007c54e0 + 0xf90) != 0 || (*(int *)(DAT_007c54e0 + 0xf7c) != 0)))))) {
    uVar1 = FUN_0049b7a0();
    FUN_0049e4e0(uVar1 & 1,*(undefined4 *)(param_1 + 0x20));
    FUN_0049e4e0(uVar1 >> 1 & 1,*(undefined4 *)(param_1 + 0x24));
    FUN_0049e4e0(uVar1 >> 2 & 1,*(undefined4 *)(param_1 + 0x28));
    FUN_0049e4e0(uVar1 >> 3 & 1,*(undefined4 *)(param_1 + 0x2c));
  }
  return;
}


