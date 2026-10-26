// Function: FUN_0056bd40 @ 0056bd40
// Size (bytes): 159


void __thiscall FUN_0056bd40(double *param_1,double *param_2)

{
  double dVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar2 = (float10)fsin((float10)*param_2);
  fVar3 = (float10)fcos((float10)*param_2);
  fVar4 = (float10)fsin((float10)param_2[1]);
  fVar5 = (float10)fcos((float10)param_2[1]);
  dVar1 = (double)fVar5;
  fVar5 = (float10)fsin((float10)param_2[2]);
  fVar6 = (float10)fcos((float10)param_2[2]);
  *param_1 = (double)(fVar4 * fVar2 * fVar5 + (float10)(double)(fVar6 * (float10)dVar1));
  param_1[1] = (double)(fVar4 * fVar2 * fVar6 - (float10)(double)(fVar5 * (float10)dVar1));
  param_1[2] = (double)(fVar4 * fVar3);
  param_1[3] = (double)(fVar5 * fVar3);
  param_1[4] = (double)(fVar6 * fVar3);
  param_1[5] = (double)-fVar2;
  param_1[6] = (double)((float10)(double)(fVar5 * (float10)dVar1) * fVar2 - fVar6 * fVar4);
  param_1[7] = (double)((float10)(double)(fVar6 * (float10)dVar1) * fVar2 + fVar5 * fVar4);
  param_1[8] = (double)((float10)dVar1 * fVar3);
  return;
}


