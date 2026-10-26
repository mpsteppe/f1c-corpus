// Function: FUN_0044a070 @ 0044a070
// Size (bytes): 177


undefined4 __thiscall FUN_0044a070(double *param_1,double *param_2)

{
  double dVar1;
  double dVar2;
  int iVar3;
  float *pfVar4;
  
  iVar3 = 0;
  pfVar4 = (float *)((int)param_1 + 0x34);
  do {
    if ((float)param_2[2] * *pfVar4 + (float)*param_2 * pfVar4[-1] < pfVar4[1]) {
      return 0;
    }
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 3;
  } while (iVar3 < 3);
  dVar1 = param_2[2];
  dVar1 = (dVar1 * param_1[1] + param_1[4]) * dVar1 +
          (*param_2 * *param_1 + dVar1 * param_1[2] + param_1[3]) * *param_2 + param_1[5];
  dVar2 = dVar1 - param_2[1];
  if (dVar2 <= param_2[3]) {
    dVar2 = ABS(dVar2);
    if (param_2[4] <= dVar2) {
      return 0;
    }
    param_2[4] = dVar2;
    *(double **)(param_2 + 6) = param_1;
    param_2[5] = dVar1;
    return 1;
  }
  return 0;
}


