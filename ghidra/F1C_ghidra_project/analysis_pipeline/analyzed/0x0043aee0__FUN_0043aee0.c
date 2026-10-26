// Function: FUN_0043aee0 @ 0043aee0
// Size (bytes): 109


void __thiscall FUN_0043aee0(double *param_1,double *param_2,double *param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  
  dVar1 = param_1[3];
  dVar2 = *param_3;
  dVar3 = param_1[5];
  dVar4 = param_3[2];
  dVar5 = param_1[4];
  dVar6 = param_3[1];
  dVar7 = param_1[6];
  dVar8 = *param_3;
  dVar9 = param_1[8];
  dVar10 = param_3[2];
  dVar11 = param_1[7];
  dVar12 = param_3[1];
  *param_4 = *param_3 * *param_1 + param_1[1] * param_3[1] + param_1[2] * param_3[2] + *param_2;
  param_4[1] = dVar5 * dVar6 + dVar3 * dVar4 + dVar1 * dVar2 + param_2[1];
  param_4[2] = dVar11 * dVar12 + dVar9 * dVar10 + dVar7 * dVar8 + param_2[2];
  return;
}


