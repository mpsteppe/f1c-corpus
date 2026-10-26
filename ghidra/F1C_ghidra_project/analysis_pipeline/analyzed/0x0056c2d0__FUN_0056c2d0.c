// Function: FUN_0056c2d0 @ 0056c2d0
// Size (bytes): 206


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056c2d0(double *param_1,double param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar3 = (float10)fsin((float10)param_2);
  fVar4 = (float10)fcos((float10)param_2);
  dVar1 = param_1[1];
  param_1[1] = (double)((float10)param_1[2] * fVar3 + (float10)dVar1 * fVar4);
  param_1[2] = (double)((float10)param_1[2] * fVar4 - (float10)dVar1 * fVar3);
  dVar1 = param_1[4];
  param_1[4] = (double)((float10)param_1[5] * fVar3 + (float10)dVar1 * fVar4);
  param_1[5] = (double)((float10)param_1[5] * fVar4 - (float10)dVar1 * fVar3);
  dVar1 = param_1[7];
  param_1[7] = (double)((float10)param_1[8] * fVar3 + (float10)dVar1 * fVar4);
  param_1[8] = (double)((float10)param_1[8] * fVar4 - (float10)dVar1 * fVar3);
  if (param_3 != (double *)0x0) {
    fVar3 = (float10)FUN_00588570();
    *param_3 = (double)-fVar3;
    if (ABS(param_1[5]) != _DAT_0059e420) {
      fVar3 = (float10)fpatan((float10)param_1[2],(float10)param_1[8]);
      param_3[1] = (double)fVar3;
      fVar3 = (float10)fpatan((float10)param_1[3],(float10)param_1[4]);
      param_3[2] = (double)fVar3;
      return;
    }
    dVar1 = param_1[6];
    dVar2 = *param_1;
    *(undefined4 *)(param_3 + 2) = 0;
    fVar3 = (float10)fpatan(-(float10)dVar1,(float10)dVar2);
    *(undefined4 *)((int)param_3 + 0x14) = 0;
    param_3[1] = (double)fVar3;
  }
  return;
}


