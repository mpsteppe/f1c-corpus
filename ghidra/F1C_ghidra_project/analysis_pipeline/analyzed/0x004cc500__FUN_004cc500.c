// Function: FUN_004cc500 @ 004cc500
// Size (bytes): 506


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cc500(int param_1,undefined4 *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_18;
  float local_14;
  float local_10;
  
  local_18 = param_3[1] * (float)param_2[0x14] - param_3[2] * (float)param_2[0x13];
  local_14 = param_3[2] * (float)param_2[0x12] - (float)param_2[0x14] * *param_3;
  local_10 = (float)param_2[0x13] * *param_3 - param_3[1] * (float)param_2[0x12];
  fVar1 = local_18 * local_18 + local_14 * local_14 + local_10 * local_10;
  if (fVar1 < DAT_0059e440 == (fVar1 == DAT_0059e440)) {
    fVar1 = (*(float *)(param_1 + 0x10) * _DAT_0059e450) / SQRT(fVar1);
    local_18 = local_18 * fVar1;
    local_14 = local_14 * fVar1;
    local_10 = local_10 * fVar1;
  }
  else {
    local_18 = 0.0;
    local_10 = 0.0;
    local_14 = *(float *)(param_1 + 0x10) * _DAT_0059e450;
  }
  fVar1 = (float)param_2[0xb];
  fVar2 = (float)param_2[0xc];
  fVar3 = (float)param_2[0xd];
  FUN_00558e10(*param_2,1,local_18 + fVar1,local_14 + fVar2,local_10 + fVar3,param_2[0x18]);
  FUN_00558e10(*param_2,2,(local_18 + fVar1) - *param_3,(local_14 + fVar2) - param_3[1],
               (local_10 + fVar3) - param_3[2],param_2[0x18]);
  fVar1 = (float)param_2[0xb];
  fVar2 = (float)param_2[0xc];
  fVar3 = (float)param_2[0xd];
  FUN_00558e10(*param_2,0,fVar1 - local_18,fVar2 - local_14,fVar3 - local_10,param_2[0x18]);
  FUN_00558e10(*param_2,3,(fVar1 - local_18) - *param_3,(fVar2 - local_14) - param_3[1],
               (fVar3 - local_10) - param_3[2],param_2[0x18]);
  return;
}


