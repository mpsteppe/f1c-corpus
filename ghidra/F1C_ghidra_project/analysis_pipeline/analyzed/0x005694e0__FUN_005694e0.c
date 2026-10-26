// Function: FUN_005694e0 @ 005694e0
// Size (bytes): 393


void __thiscall
FUN_005694e0(int param_1,double *param_2,double *param_3,double *param_4,double *param_5,
            double *param_6)

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
  
  dVar1 = *param_2 - *(double *)(param_1 + 4);
  dVar8 = param_2[1] - *(double *)(param_1 + 0xc);
  dVar6 = param_2[2] - *(double *)(param_1 + 0x14);
  dVar10 = dVar1 * *(double *)(param_1 + 0x7c) + *(double *)(param_1 + 100);
  dVar7 = dVar8 * *(double *)(param_1 + 0x84) + *(double *)(param_1 + 0x6c);
  dVar11 = dVar6 * *(double *)(param_1 + 0x8c) + *(double *)(param_1 + 0x74);
  *param_4 = dVar11 * param_3[2] + dVar7 * param_3[1] + dVar10 * *param_3;
  dVar5 = dVar8 * param_3[2] - dVar6 * param_3[1];
  dVar2 = dVar6 * *param_3 - dVar1 * param_3[2];
  dVar9 = dVar1 * param_3[1] - dVar8 * *param_3;
  dVar4 = dVar5 * *(double *)(param_1 + 0xec) +
          dVar2 * *(double *)(param_1 + 0xf4) + dVar9 * *(double *)(param_1 + 0xfc);
  dVar3 = dVar5 * *(double *)(param_1 + 0x104) +
          dVar2 * *(double *)(param_1 + 0x10c) + dVar9 * *(double *)(param_1 + 0x114);
  dVar2 = dVar5 * *(double *)(param_1 + 0x11c) +
          dVar2 * *(double *)(param_1 + 0x124) + dVar9 * *(double *)(param_1 + 300);
  *param_5 = (dVar8 * dVar4 - dVar3 * dVar1) * param_3[2] +
             (dVar2 * dVar1 - dVar6 * dVar4) * param_3[1] +
             (dVar3 * dVar6 - dVar2 * dVar8) * *param_3 + *(double *)(param_1 + 0xb4);
  if (param_6 != (double *)0x0) {
    dVar1 = *param_4;
    dVar2 = param_3[1];
    dVar3 = param_3[2];
    *param_6 = dVar10 - dVar1 * *param_3;
    param_6[1] = dVar7 - dVar1 * dVar2;
    param_6[2] = dVar11 - dVar1 * dVar3;
  }
  return;
}


