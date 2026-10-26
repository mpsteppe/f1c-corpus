// Function: FUN_0040ed10 @ 0040ed10
// Size (bytes): 398


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040ed10(int param_1)

{
  int iVar1;
  float10 fVar2;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = 0;
  switch(iVar1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    if (iVar1 == 0) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0xd0);
    }
    else if (iVar1 == 1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0xd0);
    }
    else if (iVar1 == 2) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0xd0);
    }
    else if (iVar1 == 3) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0xd0);
    }
    else if (iVar1 == 4) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0xd0);
    }
    else if (iVar1 == 5) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0xd0);
    }
    else {
      iVar1 = 0;
    }
    if (iVar1 != 0) {
LAB_0040ed9a:
      FUN_0054b420(param_1 + 0xc,param_1 + 0x10,param_1 + 0x14);
      fVar2 = (float10)FUN_004dd8f0();
      *(float *)(param_1 + 0x18) = (float)SQRT(fVar2);
      return;
    }
    break;
  case 6:
    iVar1 = *(int *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 0x34d4);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar1 + 0x34d8);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x34dc);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar1 + 0x3b70);
    return;
  case 7:
    if (*(int *)(param_1 + 0x20) != 0) {
      if (((byte)*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x3c) & 0x10) == 0x10)
      goto LAB_0040ed9a;
      FUN_004dd550(&local_24);
      *(float *)(param_1 + 0xc) = (local_24 + local_18) * _DAT_0059e450;
      *(float *)(param_1 + 0x10) = (local_20 + local_14) * _DAT_0059e450;
      *(float *)(param_1 + 0x14) = (local_1c + local_10) * _DAT_0059e450;
      local_24 = local_24 - *(float *)(param_1 + 0xc);
      local_20 = local_20 - *(float *)(param_1 + 0x10);
      local_1c = local_1c - *(float *)(param_1 + 0x14);
      *(float *)(param_1 + 0x18) =
           SQRT(local_24 * local_24 + local_20 * local_20 + local_1c * local_1c);
    }
  }
  return;
}


