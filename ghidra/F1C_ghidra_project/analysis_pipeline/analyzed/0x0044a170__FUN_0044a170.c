// Function: FUN_0044a170 @ 0044a170
// Size (bytes): 349


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044a170(float *param_1,int param_2,int param_3,int param_4,char param_5)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  *param_1 = 0.0;
  param_1[1] = 1.7014117e+38;
  param_1[2] = -1.7014117e+38;
  param_1[3] = 0.0;
  param_1[4] = 1.7014117e+38;
  param_1[5] = -1.7014117e+38;
  param_1[6] = 3.4028235e+38;
  local_4 = 0;
  iVar4 = 0;
  if (0 < param_3) {
    pfVar2 = (float *)(param_2 + 8);
    iVar3 = param_3;
    do {
      if (pfVar2[-1] < param_1[1]) {
        param_1[1] = pfVar2[-1];
      }
      if (param_1[2] < *pfVar2) {
        param_1[2] = *pfVar2;
      }
      if (param_5 != '\0') {
        *(float *)((int)pfVar2[-2] + 0x1c) = *param_1;
        *param_1 = pfVar2[-2];
      }
      pfVar2 = pfVar2 + 4;
      iVar3 = iVar3 + -1;
      iVar4 = param_3;
    } while (iVar3 != 0);
  }
  if (iVar4 < param_4) {
    pfVar2 = (float *)(iVar4 * 0x10 + 4 + param_2);
    iVar4 = param_4 - iVar4;
    do {
      if (*pfVar2 < param_1[2]) {
        local_4 = local_4 + 1;
      }
      if (*pfVar2 < param_1[4]) {
        param_1[4] = *pfVar2;
      }
      if (param_1[5] < pfVar2[1]) {
        param_1[5] = pfVar2[1];
      }
      if (param_5 != '\0') {
        *(float *)((int)pfVar2[-1] + 0x1c) = param_1[3];
        param_1[3] = pfVar2[-1];
      }
      pfVar2 = pfVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (0 < param_3) {
    pfVar2 = (float *)(param_2 + 8);
    do {
      if (param_1[4] < *pfVar2) {
        local_4 = local_4 + 1;
      }
      pfVar2 = pfVar2 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  fVar1 = _DAT_0059e43c;
  if (param_1[5] - param_1[2] != DAT_0059e440) {
    fVar1 = (param_1[2] - param_1[4]) / (param_1[5] - param_1[2]);
  }
  if (param_4 != 0) {
    param_1[6] = (float)local_4 / (float)param_4 + fVar1;
    return;
  }
  param_1[6] = _DAT_0059e43c + fVar1;
  return;
}


