// Function: FUN_004faec0 @ 004faec0
// Size (bytes): 153


void __fastcall FUN_004faec0(float *param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  
  pfVar3 = (float *)param_1[0x44];
  if (pfVar3 != (float *)0x0) {
    fVar1 = pfVar3[1];
    fVar2 = pfVar3[2];
    param_1[3] = *pfVar3 - *param_1;
    param_1[4] = fVar1 - param_1[1];
    param_1[5] = fVar2 - param_1[2];
    return;
  }
  pfVar3 = (float *)param_1[0x43];
  if (pfVar3 != (float *)0x0) {
    fVar1 = pfVar3[1];
    fVar2 = pfVar3[2];
    param_1[3] = *param_1 - *pfVar3;
    param_1[4] = param_1[1] - fVar1;
    param_1[5] = param_1[2] - fVar2;
    return;
  }
  param_1[3] = 0.0;
  param_1[4] = 0.0;
  param_1[5] = -1.0;
  return;
}


