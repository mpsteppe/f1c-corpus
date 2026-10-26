// Function: FUN_00435e60 @ 00435e60
// Size (bytes): 877


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00435e60(int *param_1,int param_2,double *param_3,double *param_4)

{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  double local_50 [2];
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_10;
  
  if (*param_1 == 0) {
    *(undefined4 *)param_3 = 0;
    *(undefined4 *)((int)param_3 + 4) = 0;
    *(undefined4 *)(param_3 + 1) = 0;
    *(undefined4 *)((int)param_3 + 0xc) = 0;
    *(undefined4 *)(param_3 + 2) = 0;
    *(undefined4 *)((int)param_3 + 0x14) = 0;
    *(undefined4 *)param_4 = 0;
    *(undefined4 *)((int)param_4 + 4) = 0;
    *(undefined4 *)(param_4 + 1) = 0;
    *(undefined4 *)((int)param_4 + 0xc) = 0;
    *(undefined4 *)(param_4 + 2) = 0;
    *(undefined4 *)((int)param_4 + 0x14) = 0;
    return;
  }
  FUN_004361d0(param_2 + 4,*param_1 + 4,param_3);
  *param_3 = *param_3 - *(double *)(param_1 + 1);
  param_3[1] = param_3[1] - *(double *)(param_1 + 3);
  param_3[2] = param_3[2] - *(double *)(param_1 + 5);
  fVar3 = _DAT_007cfb48;
  dVar1 = (double)_DAT_007cfb48;
  fVar2 = _DAT_007cfb48 * (float)*param_3;
  *param_3 = (double)fVar2;
  param_3[1] = dVar1 * param_3[1];
  param_3[2] = dVar1 * param_3[2];
  iVar4 = param_1[0xe];
  iVar5 = param_1[8];
  if ((float)*(double *)(param_1 + 7) <= fVar2) {
    if ((float)*(double *)(param_1 + 0xd) < fVar2) {
      *(int *)param_3 = param_1[0xd];
      *(int *)((int)param_3 + 4) = iVar4;
    }
  }
  else {
    *(int *)param_3 = param_1[7];
    *(int *)((int)param_3 + 4) = iVar5;
  }
  iVar4 = param_1[0x10];
  if (*(double *)(param_1 + 9) <= param_3[1]) {
    if (*(double *)(param_1 + 0xf) < param_3[1]) {
      *(int *)(param_3 + 1) = param_1[0xf];
      *(int *)((int)param_3 + 0xc) = iVar4;
    }
  }
  else {
    param_3[1] = *(double *)(param_1 + 9);
  }
  iVar4 = param_1[0x12];
  if (*(double *)(param_1 + 0xb) <= param_3[2]) {
    if (*(double *)(param_1 + 0x11) < param_3[2]) {
      *(int *)(param_3 + 2) = param_1[0x11];
      *(int *)((int)param_3 + 0x14) = iVar4;
    }
  }
  else {
    param_3[2] = *(double *)(param_1 + 0xb);
  }
  FUN_0056c740(local_50);
  fVar6 = (float10)FUN_00588570();
  *param_4 = (double)-fVar6;
  if (ABS(local_28) == _DAT_0059e420) {
    *(undefined4 *)(param_4 + 2) = 0;
    *(undefined4 *)((int)param_4 + 0x14) = 0;
    fVar7 = (float10)fpatan(-(float10)local_20,(float10)local_50[0]);
    param_4[1] = (double)fVar7;
  }
  else {
    fVar7 = (float10)fpatan((float10)local_40,(float10)local_10);
    param_4[1] = (double)fVar7;
    fVar7 = (float10)fpatan((float10)local_38,(float10)local_30);
    param_4[2] = (double)fVar7;
  }
  dVar1 = (double)((float10)_DAT_007cfb6c * (float10)fVar3);
  fVar6 = (float10)_DAT_007cfb6c * (float10)fVar3 * -fVar6;
  *param_4 = (double)fVar6;
  param_4[1] = dVar1 * param_4[1];
  param_4[2] = dVar1 * param_4[2];
  iVar4 = param_1[0x1a];
  iVar5 = param_1[0x19];
  if ((fVar6 < (float10)*(double *)(param_1 + 0x19)) ||
     (iVar4 = param_1[0x20], iVar5 = param_1[0x1f], (float10)*(double *)(param_1 + 0x1f) < fVar6)) {
    *(int *)param_4 = iVar5;
    *(int *)((int)param_4 + 4) = iVar4;
  }
  iVar4 = param_1[0x22];
  if (*(double *)(param_1 + 0x1b) <= param_4[1]) {
    if (*(double *)(param_1 + 0x21) < param_4[1]) {
      *(int *)(param_4 + 1) = param_1[0x21];
      *(int *)((int)param_4 + 0xc) = iVar4;
    }
  }
  else {
    param_4[1] = *(double *)(param_1 + 0x1b);
  }
  iVar4 = param_1[0x24];
  if (*(double *)(param_1 + 0x1d) <= param_4[2]) {
    if (*(double *)(param_1 + 0x23) < param_4[2]) {
      *(int *)(param_4 + 2) = param_1[0x23];
      *(int *)((int)param_4 + 0x14) = iVar4;
    }
    return;
  }
  param_4[2] = *(double *)(param_1 + 0x1d);
  return;
}


