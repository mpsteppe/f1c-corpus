// Function: FUN_004361d0 @ 004361d0
// Size (bytes): 93


void __thiscall FUN_004361d0(double *param_1,double *param_2,double *param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = *param_3 - *param_2;
  dVar3 = param_3[1] - param_2[1];
  dVar2 = param_3[2] - param_2[2];
  *param_4 = dVar1 * *param_1 + dVar3 * param_1[3] + dVar2 * param_1[6];
  param_4[1] = dVar1 * param_1[1] + dVar3 * param_1[4] + dVar2 * param_1[7];
  param_4[2] = dVar1 * param_1[2] + dVar3 * param_1[5] + dVar2 * param_1[8];
  return;
}


