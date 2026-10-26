// Function: FUN_004efbd0 @ 004efbd0
// Size (bytes): 784


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004efbd0(int param_1,float param_2)

{
  float fVar1;
  undefined4 *puVar2;
  float *pfVar3;
  float *pfVar4;
  float10 fVar5;
  float10 fVar6;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  local_30 = *(float *)((int)param_2 + 0x24);
  local_2c = *(float *)((int)param_2 + 0x28);
  local_28 = *(float *)((int)param_2 + 0x2c);
  pfVar4 = (float *)(param_1 + 0x34b0);
  pfVar3 = (float *)(param_1 + 0x3ab8 + *(int *)((int)param_2 + 0x14) * 0xc);
  fVar1 = *(float *)((int)param_2 + 0x30) * local_30 +
          *(float *)((int)param_2 + 0x34) * local_2c + *(float *)((int)param_2 + 0x38) * local_28;
  local_24 = *pfVar4 * *pfVar3 +
             *(float *)(param_1 + 0x34b4) * pfVar3[1] + *(float *)(param_1 + 0x34b8) * pfVar3[2] +
             *(float *)(param_1 + 0x34d4);
  local_20 = *(float *)(param_1 + 0x34bc) * *pfVar3 +
             *(float *)(param_1 + 0x34c0) * pfVar3[1] + *(float *)(param_1 + 0x34c4) * pfVar3[2] +
             *(float *)(param_1 + 0x34d8);
  local_1c = *(float *)(param_1 + 0x34c8) * *pfVar3 +
             *(float *)(param_1 + 0x34cc) * pfVar3[1] + *(float *)(param_1 + 0x34d0) * pfVar3[2] +
             *(float *)(param_1 + 0x34dc);
  puVar2 = (undefined4 *)FUN_004ed750(&local_3c);
  local_18 = (float)*puVar2;
  local_14 = (float)puVar2[1];
  local_10 = (float)puVar2[2];
  pfVar3 = (float *)FUN_004ed710(local_c);
  local_3c = *pfVar3;
  local_38 = pfVar3[1];
  local_34 = pfVar3[2];
  param_2 = (local_3c * *pfVar4 +
            local_38 * *(float *)(param_1 + 0x34b4) + local_34 * *(float *)(param_1 + 0x34b8)) *
            local_30 +
            (local_3c * *(float *)(param_1 + 0x34bc) +
            local_38 * *(float *)(param_1 + 0x34c0) + local_34 * *(float *)(param_1 + 0x34c4)) *
            local_2c +
            (local_3c * *(float *)(param_1 + 0x34c8) +
            local_38 * *(float *)(param_1 + 0x34cc) + local_34 * *(float *)(param_1 + 0x34d0)) *
            local_28;
  if (param_2 == DAT_0059e440) {
    param_2 = 0.0;
  }
  else {
    param_2 = ((local_24 * local_30 + local_20 * local_2c + local_1c * local_28) - fVar1) / param_2;
  }
  FUN_004ef680(&local_24);
  local_18 = local_24 * *pfVar4 +
             local_20 * *(float *)(param_1 + 0x34b4) + local_1c * *(float *)(param_1 + 0x34b8);
  local_14 = local_24 * *(float *)(param_1 + 0x34bc) +
             local_20 * *(float *)(param_1 + 0x34c0) + local_1c * *(float *)(param_1 + 0x34c4);
  local_10 = local_24 * *(float *)(param_1 + 0x34c8) +
             local_20 * *(float *)(param_1 + 0x34cc) + local_1c * *(float *)(param_1 + 0x34d0);
  FUN_004ec020((float *)(param_1 + 0x34d4));
  pfVar4 = (float *)FUN_004ed750(local_c);
  local_24 = *pfVar4;
  local_20 = pfVar4[1];
  local_1c = pfVar4[2];
  pfVar4 = (float *)FUN_004ed710(local_c);
  local_3c = *pfVar4;
  local_38 = pfVar4[1];
  local_34 = pfVar4[2];
  FUN_004ed7b0(&local_3c,local_c);
  fVar5 = (float10)FUN_004efee0();
  fVar6 = (float10)FUN_004efee0();
  if (fVar6 == (float10)DAT_0059e440) {
    fVar6 = (float10)DAT_0059e440;
  }
  else {
    fVar6 = (float10)(float)(fVar5 - (float10)fVar1) / fVar6;
  }
  if (fVar6 < (float10)param_2) {
    fVar6 = (float10)param_2;
  }
  if (fVar6 < (float10)DAT_0059e440) {
    return (float10)*(float *)(param_1 + 0x34ac);
  }
  if ((float10)_DAT_0059e87c < fVar6) {
    return (float10)*(float *)(param_1 + 0x34ac) - (float10)_DAT_0059e87c;
  }
  return (float10)*(float *)(param_1 + 0x34ac) - fVar6;
}


