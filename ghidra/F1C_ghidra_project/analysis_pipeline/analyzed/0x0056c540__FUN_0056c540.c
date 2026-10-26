// Function: FUN_0056c540 @ 0056c540
// Size (bytes): 243


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0056c540(double *param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  float10 fVar4;
  
  *param_3 = param_2[2] * param_1[1] - param_2[1] * param_1[2];
  param_3[1] = *param_2 * param_1[2] - *param_1 * param_2[2];
  dVar3 = *param_1 * param_2[1] - *param_2 * param_1[1];
  param_3[2] = dVar3;
  if (((*param_3 == _DAT_0059e430) && (param_3[1] == _DAT_0059e430)) && (dVar3 == _DAT_0059e430)) {
    return;
  }
  dVar1 = param_3[1];
  dVar2 = *param_3;
  fVar4 = (float10)FUN_005894a0();
  fVar4 = fVar4 / SQRT((float10)(dVar3 * dVar3 + dVar2 * dVar2 + dVar1 * dVar1));
  *param_3 = (double)(fVar4 * (float10)*param_3);
  param_3[1] = (double)(fVar4 * (float10)param_3[1]);
  param_3[2] = (double)(fVar4 * (float10)param_3[2]);
  return;
}


