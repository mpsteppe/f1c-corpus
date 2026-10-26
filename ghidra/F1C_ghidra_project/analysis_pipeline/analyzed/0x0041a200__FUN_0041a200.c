// Function: FUN_0041a200 @ 0041a200
// Size (bytes): 173


void FUN_0041a200(int param_1)

{
  undefined4 uVar1;
  undefined1 local_20 [32];
  
  if ((((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) && (DAT_007c56a8 != 8)) &&
     (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894))) {
    if (*(int *)(param_1 + 0x3450) != 1) {
      FUN_00418a20(0x2a);
      return;
    }
    if ((*(int *)(param_1 + 0x4040) == 2) || (uVar1 = 0x2a, *(int *)(param_1 + 0x4040) == -1)) {
      uVar1 = 0x34;
    }
    FUN_004144f0(uVar1,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_00418560(local_20);
  }
  return;
}


