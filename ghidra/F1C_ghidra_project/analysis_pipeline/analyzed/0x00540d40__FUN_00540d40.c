// Function: FUN_00540d40 @ 00540d40
// Size (bytes): 87


void FUN_00540d40(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if ((param_2 & 4) != 0) {
      uVar1 = FUN_00540f00(*(undefined4 *)(param_1 + 0x1c),param_2,*(undefined4 *)(param_1 + 0x2c),
                           *(undefined4 *)(param_1 + 8));
      *(undefined4 *)(param_1 + 0x20) = uVar1;
    }
    if ((param_2 & 8) != 0) {
      uVar1 = FUN_00541090(*(undefined4 *)(param_1 + 0x24),param_2,*(undefined4 *)(param_1 + 0x30),
                           *(undefined4 *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x28) = uVar1;
    }
  }
  return;
}


