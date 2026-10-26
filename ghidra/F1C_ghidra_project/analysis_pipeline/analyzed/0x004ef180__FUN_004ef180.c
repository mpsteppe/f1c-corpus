// Function: FUN_004ef180 @ 004ef180
// Size (bytes): 348


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ef180(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float local_54;
  float local_50;
  float local_4c;
  undefined1 local_48 [12];
  double local_3c;
  double local_34;
  double local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  double local_14;
  int local_c;
  
  iVar4 = 0;
  iVar3 = param_1 + 0x7b8;
  piVar2 = (int *)(param_1 + 0x3668);
  do {
    local_54 = *(float *)(iVar4 + 0x82c + param_1) * *(float *)(param_1 + 0x704) +
               *(float *)(param_1 + 0x708) * *(float *)(iVar4 + 0x830 + param_1) +
               *(float *)(param_1 + 0x70c) * *(float *)(iVar4 + 0x834 + param_1);
    local_50 = *(float *)(iVar4 + 0x834 + param_1) * *(float *)(param_1 + 0x718) +
               *(float *)(param_1 + 0x714) * *(float *)(iVar4 + 0x830 + param_1) +
               *(float *)(iVar4 + 0x82c + param_1) * *(float *)(param_1 + 0x710);
    local_4c = *(float *)(param_1 + 0x71c) * *(float *)(iVar4 + 0x82c + param_1) +
               *(float *)(iVar4 + 0x830 + param_1) * *(float *)(param_1 + 0x720) +
               *(float *)(param_1 + 0x724) * *(float *)(iVar4 + 0x834 + param_1);
    FUN_004ec020(param_1 + 0x6ec);
    local_c = *piVar2;
    local_3c = (double)local_54;
    local_34 = (double)local_50;
    local_2c = (double)local_4c;
    local_24 = 0xa0000000;
    local_20 = 0x3fb99999;
    local_1c = 0x40000000;
    local_18 = 0x479e17b8;
    iVar1 = FUN_0044c550(&local_3c,local_48);
    if (iVar1 != 0) {
      local_50 = (float)local_14 + _DAT_0059e448;
      *piVar2 = iVar1;
      FUN_004ce110(iVar3,&local_54,local_48);
    }
    iVar4 = iVar4 + 0x128;
    piVar2 = piVar2 + 0x3e;
    iVar3 = iVar3 + 0x128;
  } while (iVar4 < 0x4a0);
  return;
}


