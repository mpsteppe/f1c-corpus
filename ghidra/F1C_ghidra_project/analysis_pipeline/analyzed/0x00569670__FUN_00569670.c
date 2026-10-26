// Function: FUN_00569670 @ 00569670
// Size (bytes): 294


void __thiscall FUN_00569670(int param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  dVar1 = *(double *)(param_1 + 0xb4);
  dVar2 = param_2[1];
  dVar3 = param_2[2];
  *(double *)(param_1 + 100) = dVar1 * *param_2 + *(double *)(param_1 + 100);
  *(double *)(param_1 + 0x6c) = dVar1 * dVar2 + *(double *)(param_1 + 0x6c);
  *(double *)(param_1 + 0x74) = dVar1 * dVar3 + *(double *)(param_1 + 0x74);
  dVar1 = *param_3;
  dVar2 = param_2[2];
  dVar3 = param_3[2];
  dVar4 = *param_2;
  dVar5 = param_3[1];
  dVar6 = *param_2;
  dVar7 = param_2[1];
  dVar8 = *param_3;
  *(double *)(param_1 + 0x94) =
       (param_2[1] * param_3[2] - param_3[1] * param_2[2]) + *(double *)(param_1 + 0x94);
  *(double *)(param_1 + 0x9c) = (dVar1 * dVar2 - dVar3 * dVar4) + *(double *)(param_1 + 0x9c);
  *(double *)(param_1 + 0xa4) = (dVar5 * dVar6 - dVar7 * dVar8) + *(double *)(param_1 + 0xa4);
  *(double *)(param_1 + 0x7c) =
       *(double *)(param_1 + 0x94) * *(double *)(param_1 + 0xec) +
       *(double *)(param_1 + 0xf4) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 0xfc) * *(double *)(param_1 + 0xa4);
  *(double *)(param_1 + 0x84) =
       *(double *)(param_1 + 0x10c) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 0x114) * *(double *)(param_1 + 0xa4) +
       *(double *)(param_1 + 0x104) * *(double *)(param_1 + 0x94);
  *(double *)(param_1 + 0x8c) =
       *(double *)(param_1 + 0x124) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 300) * *(double *)(param_1 + 0xa4) +
       *(double *)(param_1 + 0x11c) * *(double *)(param_1 + 0x94);
  return;
}


