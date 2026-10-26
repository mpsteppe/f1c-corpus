// Function: FUN_004e9a40 @ 004e9a40
// Size (bytes): 390


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004e9a40(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  float10 fVar6;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  fVar1 = *(float *)(param_1 + 0x3b60);
  local_28 = *(float *)(param_1 + 0x3b64);
  local_24 = *(float *)(param_1 + 0x3b68);
  if (param_2 != (float *)0x0) {
    fVar1 = *param_2 * _DAT_0059e87c + fVar1;
    local_28 = param_2[1] * _DAT_0059e87c + local_28;
    local_24 = param_2[2] * _DAT_0059e87c + local_24;
  }
  fVar1 = fVar1 - *(float *)(param_1 + 0x34d4);
  local_28 = local_28 - *(float *)(param_1 + 0x34d8);
  iVar4 = 0;
  pfVar5 = (float *)(param_1 + 0x3abc);
  local_24 = local_24 - *(float *)(param_1 + 0x34dc);
  fVar3 = fVar1 * *(float *)(param_1 + 0x34b0) +
          local_28 * *(float *)(param_1 + 0x34bc) + local_24 * *(float *)(param_1 + 0x34c8);
  fVar2 = fVar1 * *(float *)(param_1 + 0x34b4) +
          local_28 * *(float *)(param_1 + 0x34c0) + local_24 * *(float *)(param_1 + 0x34cc);
  fVar1 = fVar1 * *(float *)(param_1 + 0x34b8) +
          local_28 * *(float *)(param_1 + 0x34c4) + local_24 * *(float *)(param_1 + 0x34d0);
  local_20 = fVar3 - *(float *)(param_1 + 0x72c);
  local_1c = fVar2 - *(float *)(param_1 + 0x730);
  local_18 = fVar1 - *(float *)(param_1 + 0x734);
  do {
    local_14 = pfVar5[-1] - *(float *)(param_1 + 0x72c);
    local_10 = *pfVar5 - *(float *)(param_1 + 0x730);
    local_c = pfVar5[1] - *(float *)(param_1 + 0x734);
    FUN_0054fa00(&local_20,iVar4);
    iVar4 = iVar4 + 1;
    pfVar5 = pfVar5 + 3;
  } while (iVar4 < 0xd);
  fVar6 = SQRT((float10)fVar3 * (float10)fVar3 +
               (float10)fVar2 * (float10)fVar2 + (float10)fVar1 * (float10)fVar1);
  if (fVar6 < (float10)*(float *)(param_1 + 0x3b6c)) {
    fVar6 = (float10)*(float *)(param_1 + 0x3b6c);
  }
  return fVar6;
}


