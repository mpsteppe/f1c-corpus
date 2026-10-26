// Function: FUN_0041a2b0 @ 0041a2b0
// Size (bytes): 235


void FUN_0041a2b0(int param_1)

{
  byte bVar1;
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
  bVar1 = *(char *)(param_1 + 0x403c) + 1;
  if (*(int *)(DAT_007c54e8 + 0x4894) != *(int *)(param_1 + 0x4894)) {
    if (DAT_007c56a4 == 5) {
      if (bVar1 < 0xc) {
        if (bVar1 == 0) goto LAB_0041a386;
        uVar2 = 0x15;
      }
      else {
        uVar2 = 0x16;
      }
    }
    else {
      if ((DAT_007c56a4 < 6) || (7 < DAT_007c56a4)) goto LAB_0041a386;
      uVar2 = 0xb2;
      if (*(int *)(param_1 + 0x4060) == 1) {
        uVar2 = 0xb3;
      }
    }
    FUN_004144f0(uVar2,*(undefined4 *)(param_1 + 0x489c),bVar1,0xffffffff,0xffffffff,0xc0000000,
                 0xc0000000);
    FUN_00418560(local_20);
  }
LAB_0041a386:
  if (DAT_007c56a4 == 5) {
    FUN_004198b0(param_1);
  }
  return;
}


