// Function: FUN_00541b70 @ 00541b70
// Size (bytes): 295


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00541b70(int param_1,byte param_2)

{
  int iVar1;
  float *pfVar2;
  float local_40 [5];
  float local_2c;
  float local_18;
  undefined4 local_14;
  float local_8;
  undefined4 local_4;
  
  if ((param_2 & 4) != 0) {
    FUN_0053ac70(2,0);
    pfVar2 = local_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar2 = 0.0;
      pfVar2 = pfVar2 + 1;
    }
    if ((param_2 & 0x10) == 0) {
      local_40[0] = (float)_DAT_0059e420 / *(float *)(param_1 + 0x1c);
      local_2c = (float)_DAT_0059e420 / *(float *)(param_1 + 0x20);
      local_18 = *(float *)(param_1 + 8) / (*(float *)(param_1 + 8) - *(float *)(param_1 + 4));
      local_8 = -(*(float *)(param_1 + 4) * local_18);
      if ((*(byte *)(param_1 + 0x80) & 0x10) != 0) {
        local_40[0] = -local_40[0];
      }
      local_14 = 0x3f800000;
      local_4 = 0;
    }
    else {
      local_40[0] = 0.2;
      local_2c = 0.2;
      local_14 = 0;
      local_4 = 0x3f800000;
      local_18 = (float)_DAT_0059e420 / (*(float *)(param_1 + 8) - *(float *)(param_1 + 4));
      local_8 = *(float *)(param_1 + 4) * local_18;
    }
    FUN_0053ac70(1,0);
    FUN_0055ca40(4,local_40);
  }
  if ((param_2 & 2) != 0) {
    FUN_0055ca40(2,param_1 + 0x15c);
  }
  if ((param_2 & 8) != 0) {
    FUN_0055cc20(param_1);
  }
  return;
}


