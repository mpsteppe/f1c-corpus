// Function: FUN_0056c3a0 @ 0056c3a0
// Size (bytes): 416


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0056c3a0(undefined4 *param_1,double *param_2,double *param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined4 local_50;
  undefined4 uStack_4c;
  double local_38 [3];
  double local_20 [3];
  
  if (param_2 == (double *)0x0) {
    param_2 = local_38;
  }
  if (param_3 == (double *)0x0) {
    param_3 = (double *)&local_50;
  }
  if (param_4 == (double *)0x0) {
    param_3 = local_20;
  }
  *(undefined4 *)param_2 = *param_1;
  *(undefined4 *)((int)param_2 + 4) = param_1[1];
  *(undefined4 *)(param_2 + 1) = param_1[2];
  *(undefined4 *)((int)param_2 + 0xc) = param_1[3];
  dVar1 = *(double *)(param_1 + 4);
  param_2[2] = dVar1;
  local_50 = 0;
  uStack_4c = 0;
  dVar4 = _DAT_0059e420 / SQRT(dVar1 * dVar1 + param_2[1] * param_2[1] + *param_2 * *param_2);
  dVar1 = *param_2;
  *param_2 = dVar4 * dVar1;
  dVar2 = param_2[1];
  param_2[1] = dVar4 * dVar2;
  dVar3 = param_2[2];
  param_2[2] = dVar4 * dVar3;
  dVar5 = _DAT_0059e430;
  dVar6 = _DAT_0059e420;
  if (_DAT_0059e830 <= ABS(dVar4 * dVar1)) {
    dVar5 = _DAT_0059e420;
    dVar6 = 0.0;
  }
  *param_3 = dVar4 * dVar2 * _DAT_0059e430 - dVar4 * dVar3 * dVar5;
  param_3[1] = dVar6 * param_2[2] - *param_2 * _DAT_0059e430;
  dVar1 = dVar5 * *param_2 - dVar6 * param_2[1];
  param_3[2] = dVar1;
  *param_4 = dVar1 * param_2[1] - param_3[1] * param_2[2];
  param_4[1] = *param_3 * param_2[2] - *param_2 * param_3[2];
  param_4[2] = param_3[1] * *param_2 - param_2[1] * *param_3;
  dVar1 = _DAT_0059e420 /
          SQRT(param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3);
  *param_3 = dVar1 * *param_3;
  param_3[1] = dVar1 * param_3[1];
  param_3[2] = dVar1 * param_3[2];
  dVar1 = _DAT_0059e420 /
          SQRT(param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4);
  *param_4 = dVar1 * *param_4;
  param_4[1] = dVar1 * param_4[1];
  param_4[2] = dVar1 * param_4[2];
  return;
}


