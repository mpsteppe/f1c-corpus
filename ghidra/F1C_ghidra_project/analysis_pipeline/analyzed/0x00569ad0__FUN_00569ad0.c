// Function: FUN_00569ad0 @ 00569ad0
// Size (bytes): 149


void __thiscall FUN_00569ad0(int param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  *(double *)(param_1 + 0x134) = *(double *)(param_1 + 0x134) + *param_3;
  *(double *)(param_1 + 0x13c) = param_3[1] + *(double *)(param_1 + 0x13c);
  *(double *)(param_1 + 0x144) = param_3[2] + *(double *)(param_1 + 0x144);
  dVar1 = param_2[2];
  dVar2 = *param_3;
  dVar3 = param_3[2];
  dVar4 = *param_2;
  dVar5 = param_3[1];
  dVar6 = *param_2;
  dVar7 = *param_3;
  dVar8 = param_2[1];
  *(double *)(param_1 + 0x14c) =
       (param_3[2] * param_2[1] - param_3[1] * param_2[2]) + *(double *)(param_1 + 0x14c);
  *(double *)(param_1 + 0x154) = (dVar1 * dVar2 - dVar3 * dVar4) + *(double *)(param_1 + 0x154);
  *(double *)(param_1 + 0x15c) = (dVar5 * dVar6 - dVar7 * dVar8) + *(double *)(param_1 + 0x15c);
  return;
}


