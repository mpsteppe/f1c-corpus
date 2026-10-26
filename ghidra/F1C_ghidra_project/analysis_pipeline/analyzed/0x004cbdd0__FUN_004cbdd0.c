// Function: FUN_004cbdd0 @ 004cbdd0
// Size (bytes): 372


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cbdd0(float *param_1,float *param_2,float param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = (*param_1 - param_3 * *param_2) - (*param_4 - _DAT_005d3488 * *param_2);
  fVar1 = (param_1[1] - param_3 * param_2[1]) - (param_4[1] - _DAT_005d3488 * param_2[1]);
  fVar3 = (param_1[2] - param_3 * param_2[2]) - (param_4[2] - _DAT_005d3488 * param_2[2]);
  if (fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3 < _DAT_005d348c) {
    fVar4 = fVar2 * *param_2 + fVar1 * param_2[1] + fVar3 * param_2[2];
    fVar2 = fVar2 - fVar4 * *param_2;
    fVar1 = fVar1 - fVar4 * param_2[1];
    fVar3 = fVar3 - fVar4 * param_2[2];
    fVar1 = _DAT_005d348c - (fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3);
    if ((DAT_0059e440 < fVar1) && (fVar4 = SQRT(fVar1) - fVar4, DAT_0059e440 < fVar4)) {
      fVar1 = param_2[1];
      fVar2 = param_2[2];
      *param_1 = fVar4 * *param_2 + *param_1;
      param_1[1] = fVar4 * fVar1 + param_1[1];
      param_1[2] = fVar4 * fVar2 + param_1[2];
      return;
    }
  }
  return;
}


