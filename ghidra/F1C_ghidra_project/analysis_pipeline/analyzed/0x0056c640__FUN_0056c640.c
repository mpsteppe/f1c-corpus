// Function: FUN_0056c640 @ 0056c640
// Size (bytes): 248


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0056c640(double *param_1,double *param_2,double *param_3,double *param_4)

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
  double dVar13;
  
  dVar1 = *param_1;
  dVar2 = *param_2;
  dVar3 = param_1[1];
  dVar4 = param_2[1];
  dVar5 = param_1[2];
  dVar6 = param_2[2];
  dVar7 = *param_3;
  dVar8 = *param_2;
  dVar9 = param_3[1];
  dVar10 = param_2[1];
  dVar11 = param_3[2];
  dVar12 = param_2[2];
  dVar13 = (dVar3 - dVar4) * (dVar11 - dVar12) - (dVar9 - dVar10) * (dVar5 - dVar6);
  *param_4 = dVar13;
  dVar5 = (dVar5 - dVar6) * (dVar7 - dVar8) - (dVar1 - dVar2) * (dVar11 - dVar12);
  param_4[1] = dVar5;
  dVar1 = (dVar9 - dVar10) * (dVar1 - dVar2) - (dVar3 - dVar4) * (dVar7 - dVar8);
  param_4[2] = dVar1;
  dVar2 = dVar13 * dVar13 + dVar5 * dVar5 + dVar1 * dVar1;
  if (_DAT_0059e430 < dVar2) {
    dVar2 = _DAT_0059e420 / SQRT(dVar2);
    *param_4 = dVar13 * dVar2;
    param_4[1] = dVar5 * dVar2;
    param_4[2] = dVar1 * dVar2;
    return 0;
  }
  *(undefined4 *)param_4 = 0;
  *(undefined4 *)((int)param_4 + 4) = 0;
  *(undefined4 *)(param_4 + 1) = 0;
  *(undefined4 *)(param_4 + 2) = 0;
  *(undefined4 *)((int)param_4 + 0x14) = 0;
  *(undefined4 *)((int)param_4 + 0xc) = 0x3ff00000;
  return 0xffffffff;
}


