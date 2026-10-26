// Function: FUN_00423ca0 @ 00423ca0
// Size (bytes): 270


void __thiscall
FUN_00423ca0(int *param_1,float param_2,undefined4 param_3,float param_4,float param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  iVar1 = *param_1;
  fVar3 = param_2 * param_2 + param_4 * param_4;
  fVar4 = DAT_0059e440;
  if (fVar3 != DAT_0059e440) {
    fVar4 = (param_2 * *(float *)(iVar1 + 0x34f8) + param_4 * *(float *)(iVar1 + 0x3500)) / fVar3;
  }
  fVar2 = param_2 * fVar4 * param_2 * fVar4 + param_4 * fVar4 * param_4 * fVar4;
  if (fVar4 <= DAT_0059e440) {
    fVar2 = -SQRT(fVar2);
  }
  else {
    fVar2 = SQRT(fVar2);
  }
  param_1[6] = (int)fVar2;
  param_1[6] = (int)((float)param_1[6] - param_5);
  fVar4 = DAT_0059e440;
  if (fVar3 != DAT_0059e440) {
    fVar4 = (param_2 * *(float *)(iVar1 + 0x3500) - param_4 * *(float *)(iVar1 + 0x34f8)) / fVar3;
  }
  fVar3 = fVar4 * -param_4 * fVar4 * -param_4 + param_2 * fVar4 * param_2 * fVar4;
  if (fVar4 <= DAT_0059e440) {
    param_1[4] = (int)SQRT(fVar3);
    return;
  }
  param_1[4] = (int)-SQRT(fVar3);
  return;
}


