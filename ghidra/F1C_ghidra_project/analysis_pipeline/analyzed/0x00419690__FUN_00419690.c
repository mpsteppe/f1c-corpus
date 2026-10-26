// Function: FUN_00419690 @ 00419690
// Size (bytes): 530


void __thiscall FUN_00419690(int param_1,int param_2,int param_3,int param_4)

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
  iVar1 = 5;
  if (DAT_007c56a4 == 5) {
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x1b0 + param_3 * 4) = 1;
      if (param_3 == *(int *)(DAT_007c54e8 + 0x4894)) {
        iVar1 = (-(uint)(param_3 == param_4) & 0xfffffffa) + 0x10;
      }
      else {
        if (DAT_007d0410 == 5) {
          return;
        }
        iVar1 = (-(uint)(param_3 == param_4) & 0xffffffe2) + 0x21;
      }
      FUN_00418a20(10);
      FUN_00418a20(0x10);
      FUN_00418a20(3);
      uVar2 = 0x21;
    }
    else {
      if (param_2 == 1) {
        if (param_3 == *(int *)(DAT_007c54e8 + 0x4894)) {
          return;
        }
        if (*(int *)(&DAT_005f0714 + param_3 * 0x48c0) < 1) {
          return;
        }
        if (DAT_007d0410 == 5) {
          return;
        }
        FUN_00418a20(4);
        iVar1 = 4;
        goto LAB_00419863;
      }
      if (param_2 != 2) {
        return;
      }
      if (param_3 == *(int *)(DAT_007c54e8 + 0x4894)) {
        return;
      }
      if (*(int *)(&DAT_005f0714 + param_3 * 0x48c0) < 1) {
        return;
      }
      if (DAT_007d0410 == 5) {
        return;
      }
      uVar2 = 5;
    }
  }
  else {
    if (DAT_007c56a4 != 7) {
      return;
    }
    if (param_2 != 0) {
      return;
    }
    if (*(int *)(&DAT_005f0714 + param_3 * 0x48c0) < 2) {
      return;
    }
    if (DAT_008acf8c + -1 <= *(int *)(&DAT_005f0714 + param_3 * 0x48c0)) {
      return;
    }
    iVar1 = ((param_3 != *(int *)(DAT_007c54e8 + 0x4894)) - 1 & 0xffffff42) + 0x106;
    FUN_00418a20(0x48);
    uVar2 = 0x106;
  }
  FUN_00418a20(uVar2);
LAB_00419863:
  FUN_004144f0(iVar1,*(undefined4 *)(&DAT_005f0f74 + param_3 * 0x48c0),0xffffffff,0xffffffff,
               0xffffffff,0xc0000000,0xc0000000);
  FUN_00418560(local_20);
  return;
}


