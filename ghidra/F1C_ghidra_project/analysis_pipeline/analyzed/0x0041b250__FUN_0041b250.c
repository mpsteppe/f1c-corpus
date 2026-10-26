// Function: FUN_0041b250 @ 0041b250
// Size (bytes): 366


void FUN_0041b250(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_20 [8];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  if (DAT_007c56a4 != 7) {
    return;
  }
  if (DAT_007c56a8 == 8) {
    return;
  }
  if (DAT_007d0410 == 5) {
    return;
  }
  FUN_004144d0();
  if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894)) {
    iVar4 = -1;
    uVar3 = 0xffffffff;
    if (*(int *)(param_1 + 0x4068) == 1) {
      uVar2 = 0x77;
    }
    else if (*(int *)(param_1 + 0x4068) == 7) {
      uVar2 = 0x76;
    }
    else {
      uVar2 = 0x75;
    }
  }
  else {
    if (DAT_007c56a8 == 8) goto LAB_0041b3a1;
    iVar4 = 3;
    if ((DAT_0059e440 < *(float *)(param_1 + 0x4044)) &&
       (iVar4 = FUN_004d7c10(*(undefined4 *)(param_1 + 0x4044)), iVar4 == 0)) {
      iVar4 = 3;
    }
    iVar1 = *(int *)(param_1 + 0x4068);
    if (iVar1 == 1) {
      uVar3 = *(undefined4 *)(param_1 + 0x489c);
      uVar2 = 0xeb;
    }
    else if (iVar1 == 4) {
      uVar3 = *(undefined4 *)(param_1 + 0x489c);
      uVar2 = 0xee;
    }
    else if (iVar1 == 9) {
      uVar3 = *(undefined4 *)(param_1 + 0x489c);
      uVar2 = 0xec;
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x489c);
      uVar2 = 0xed;
    }
  }
  FUN_004144f0(uVar2,uVar3,iVar4,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
LAB_0041b3a1:
  if (local_20[0] != -1) {
    FUN_00418560(local_20);
  }
  return;
}


