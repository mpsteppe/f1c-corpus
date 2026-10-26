// Function: FUN_00436230 @ 00436230
// Size (bytes): 407


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00436230(int param_1,double *param_2,double *param_3,undefined4 *param_4,double *param_5)

{
  double *pdVar1;
  double *pdVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  double *pdVar7;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_18;
  double local_10;
  
  pdVar7 = (double *)(param_1 + (uint)(*param_2 <= _DAT_0059e430) * 0x18);
  dVar3 = *param_2 * *param_2;
  iVar6 = 2;
  if (param_2[1] <= _DAT_0059e430) {
    iVar6 = 3;
  }
  pdVar1 = (double *)(param_1 + iVar6 * 0x18);
  dVar4 = param_2[1] * param_2[1];
  local_38 = dVar4 * *pdVar1;
  iVar6 = 4;
  if (param_2[2] <= _DAT_0059e430) {
    iVar6 = 5;
  }
  pdVar2 = (double *)(param_1 + iVar6 * 0x18);
  dVar5 = param_2[2] * param_2[2];
  local_18 = dVar5 * pdVar2[1];
  local_10 = dVar5 * pdVar2[2];
  local_30 = dVar3 * pdVar7[1] + dVar4 * pdVar1[1];
  local_28 = dVar3 * pdVar7[2] + dVar4 * pdVar1[2];
  local_50 = dVar4 * *pdVar1 + dVar3 * *pdVar7 + dVar5 * *pdVar2;
  local_48 = dVar5 * pdVar2[1] + local_30;
  local_40 = dVar5 * pdVar2[2] + local_28;
  pdVar7 = &local_50;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *param_4 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    param_4 = param_4 + 1;
  }
  dVar3 = *(double *)(param_1 + 0x90) * *param_3 * *param_3;
  *param_5 = dVar3;
  if (_DAT_0059e430 < *param_3) {
    *param_5 = -dVar3;
  }
  dVar3 = *(double *)(param_1 + 0x98) * param_3[1] * param_3[1];
  param_5[1] = dVar3;
  if (_DAT_0059e430 < param_3[1]) {
    param_5[1] = -dVar3;
  }
  dVar3 = *(double *)(param_1 + 0xa0) * param_3[2] * param_3[2];
  param_5[2] = dVar3;
  if (_DAT_0059e430 < param_3[2]) {
    param_5[2] = -dVar3;
    return;
  }
  return;
}


