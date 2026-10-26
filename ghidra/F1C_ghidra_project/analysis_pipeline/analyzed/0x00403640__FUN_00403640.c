// Function: FUN_00403640 @ 00403640
// Size (bytes): 662


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * __thiscall FUN_00403640(int param_1,float *param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float local_28;
  float *local_24;
  int local_20;
  
  pfVar4 = param_2;
  iVar6 = 0;
  if (param_3 == (float *)0x0) {
    param_3 = (float *)0x4e6e6b28;
    param_2 = (float *)0x7f7fffff;
    local_28 = 3.4028235e+38;
    local_24 = (float *)0x0;
  }
  else {
    pfVar5 = (float *)param_3[0x44];
    local_24 = param_3;
    fVar2 = (*param_2 - *param_3) * (*param_2 - *param_3) +
            (param_2[2] - param_3[2]) * (param_2[2] - param_3[2]);
    while (pfVar7 = pfVar5,
          fVar3 = (*param_2 - *pfVar7) * (*param_2 - *pfVar7) +
                  (param_2[2] - pfVar7[2]) * (param_2[2] - pfVar7[2]), fVar3 < fVar2) {
      pfVar5 = (float *)pfVar7[0x44];
      local_24 = pfVar7;
      fVar2 = fVar3;
    }
    pfVar5 = (float *)param_3[0x43];
    while (pfVar7 = pfVar5,
          fVar3 = (*param_2 - *pfVar7) * (*param_2 - *pfVar7) +
                  (param_2[2] - pfVar7[2]) * (param_2[2] - pfVar7[2]), fVar3 < fVar2) {
      pfVar5 = (float *)pfVar7[0x43];
      local_24 = pfVar7;
      fVar2 = fVar3;
    }
    fVar8 = (float10)FUN_004fb6d0(param_2);
    param_3 = (float *)(float)fVar8;
    if (fVar8 < (float10)DAT_0059e440) {
      return local_24;
    }
    fVar2 = (param_2[1] - local_24[1]) * _DAT_0059e46c;
    param_2 = (float *)(fVar2 * fVar2 +
                       (*param_2 - *local_24) * (*param_2 - *local_24) +
                       (param_2[2] - local_24[2]) * (param_2[2] - local_24[2]));
    local_28 = ((float)param_3 + _DAT_0059e468) * ((float)param_3 + _DAT_0059e468);
  }
  local_20 = 0;
  pfVar5 = local_24;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x134) + 300 + iVar6);
      pfVar7 = (float *)(*(int *)(param_1 + 0x134) + iVar6);
      if ((iVar1 == 0) || (iVar1 == 1)) {
        fVar2 = (pfVar4[1] - pfVar7[1]) * _DAT_0059e46c;
        fVar2 = fVar2 * fVar2 +
                (*pfVar4 - *pfVar7) * (*pfVar4 - *pfVar7) +
                (pfVar4[2] - pfVar7[2]) * (pfVar4[2] - pfVar7[2]);
        if (fVar2 < (float)param_2) {
          pfVar5 = pfVar7;
          param_2 = (float *)fVar2;
        }
        if (((DAT_0059e440 < (float)param_3) && (fVar2 < local_28)) &&
           (fVar8 = (float10)FUN_004fb6d0(pfVar4), fVar8 < (float10)(float)param_3)) {
          param_3 = (float *)(float)fVar8;
          local_28 = (float)((fVar8 + (float10)_DAT_0059e468) * (fVar8 + (float10)_DAT_0059e468));
          local_24 = pfVar7;
        }
      }
      local_20 = local_20 + 1;
      iVar6 = iVar6 + 0x13c;
    } while (local_20 < *(int *)(param_1 + 0x130));
  }
  fVar8 = (float10)FUN_004fb6d0(pfVar4);
  if ((float10)DAT_0059e440 <= fVar8) {
    pfVar5 = local_24;
  }
  return pfVar5;
}


