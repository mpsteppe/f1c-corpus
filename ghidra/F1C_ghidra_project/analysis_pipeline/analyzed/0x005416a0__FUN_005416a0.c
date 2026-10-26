// Function: FUN_005416a0 @ 005416a0
// Size (bytes): 356


undefined4 __thiscall FUN_005416a0(int *param_1,uint *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  float local_68 [5];
  float local_54;
  float local_50;
  float local_4c;
  float local_44;
  float local_40;
  float local_3c;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((param_1[0x4f6] != 0) && (param_4 != 1)) {
    pfVar3 = local_68;
    for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar3 = 0.0;
      pfVar3 = pfVar3 + 1;
    }
    uVar1 = *param_2 & 7;
    if (uVar1 == 1) {
      local_68[0] = 4.2039e-45;
      local_1c = 0x5368d4a5;
    }
    else if (uVar1 == 2) {
      local_1c = param_2[0x14];
      local_68[0] = 1.4013e-45;
    }
    else if (uVar1 == 4) {
      local_1c = param_2[0x14];
      local_68[0] = 1.4013e-45;
    }
    local_20 = param_2[0x13];
    local_44 = (float)param_2[2] * (float)param_2[5];
    local_24 = param_2[0x12];
    local_28 = param_2[0x11];
    local_2c = param_2[0x10];
    local_40 = (float)param_2[3] * (float)param_2[5];
    local_30 = param_2[0xf];
    local_3c = (float)param_2[4] * (float)param_2[5];
    local_34 = param_2[0xe];
    local_68[1] = (float)param_2[6] * (float)param_2[9];
    local_14 = 0x3f800000;
    local_10 = 0;
    local_c = 0;
    local_68[2] = (float)param_2[7] * (float)param_2[9];
    local_68[3] = (float)param_2[8] * (float)param_2[9];
    local_54 = (float)param_2[10] * (float)param_2[0xd];
    local_50 = (float)param_2[0xb] * (float)param_2[0xd];
    local_4c = (float)param_2[0xc] * (float)param_2[0xd];
    iVar2 = (**(code **)(*(int *)param_1[0x440] + 0xb0))((int *)param_1[0x440],param_3,local_68);
    *param_1 = iVar2;
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    if ((*param_2 & 1) != 0) {
      iVar2 = (**(code **)(*(int *)param_1[0x440] + 0xb8))((int *)param_1[0x440],param_3,1);
      *param_1 = iVar2;
    }
  }
  return 0;
}


