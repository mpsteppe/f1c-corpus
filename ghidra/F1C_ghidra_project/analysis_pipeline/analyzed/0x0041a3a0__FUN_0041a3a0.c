// Function: FUN_0041a3a0 @ 0041a3a0
// Size (bytes): 241


void FUN_0041a3a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  if (DAT_007c56a8 == 8) {
    return;
  }
  FUN_004144d0();
  if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894)) {
    return;
  }
  if (DAT_007c56a4 < 0) {
    return;
  }
  if (6 < DAT_007c56a4) {
    if (DAT_007c56a4 != 7) {
      return;
    }
    if (DAT_007d0410 != 5) {
      if (*(int *)(param_1 + 0x3430) < *(int *)(param_1 + 0x403c) + -1) {
        return;
      }
      if (*(int *)(param_1 + 0x403c) + 1 < *(int *)(param_1 + 0x3430)) {
        return;
      }
      iVar1 = *(int *)(param_1 + 0x342c);
      if (iVar1 == 1) {
        uVar2 = 0xb4;
      }
      else if (iVar1 == 2) {
        uVar2 = 0xb5;
      }
      else {
        if (iVar1 != 3) {
          return;
        }
        uVar2 = 0xb6;
      }
      goto LAB_0041a45b;
    }
  }
  uVar2 = 6;
LAB_0041a45b:
  FUN_004144f0(uVar2,*(undefined4 *)(param_1 + 0x489c),0xffffffff,0xffffffff,0xffffffff,0xc0000000,
               0xc0000000);
  FUN_00418560(local_20);
  return;
}


