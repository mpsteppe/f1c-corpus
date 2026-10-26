// Function: FUN_0045a8e0 @ 0045a8e0
// Size (bytes): 1297


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0045a8e0(int *param_1,float param_2,float *param_3)

{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  double *pdVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  int local_20 [7];
  
  param_1[9] = (int)param_2;
  if ((float)param_1[8] <= (float)param_1[7]) {
    fVar1 = (float)param_1[8];
  }
  else {
    fVar1 = (float)param_1[7];
  }
  if (fVar1 < param_2) {
    fVar1 = _DAT_007d0ab0 + (float)param_1[8];
    if ((float)param_1[7] < fVar1) {
      fVar1 = (float)param_1[7];
    }
    if (param_2 <= fVar1) {
      local_20[0] = 0;
      local_20[1] = 0;
      local_20[2] = 0;
      local_20[3] = 0;
      local_20[4] = 0;
      local_20[5] = 0;
      piVar7 = local_20;
      piVar8 = param_1 + 0x4e;
      for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar8 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar8 = piVar8 + 1;
      }
      FUN_00569280(local_20);
      dVar2 = *(double *)(param_1 + 0x3a);
      dVar3 = *(double *)(param_1 + 0x38);
      *param_3 = (float)*(double *)(param_1 + 0x36);
      param_3[1] = (float)dVar3;
      param_3[2] = (float)dVar2;
      return 1;
    }
    cVar5 = (**(code **)(*param_1 + 4))();
    if (cVar5 != '\0') {
      FUN_0054b3b0(0x4e6e6b28,0x4e6e6b28,0x4e6e6b28);
      FUN_0054c030(0,0,0,0);
      local_20[0] = 0;
      local_20[1] = 0;
      local_20[2] = 0;
      local_20[3] = 0;
      local_20[4] = 0;
      local_20[5] = 0;
      piVar7 = local_20;
      piVar8 = param_1 + 0x4e;
      for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar8 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar8 = piVar8 + 1;
      }
      FUN_00569280(local_20);
      local_20[0] = 0;
      local_20[1] = 0x41cdcd65;
      local_20[2] = 0;
      local_20[3] = 0x41cdcd65;
      local_20[4] = 0;
      local_20[5] = 0x41cdcd65;
      piVar7 = local_20;
      piVar8 = param_1 + 0x36;
      for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar8 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar8 = piVar8 + 1;
      }
      param_1[0x30] = 0x4e6e6b28;
      param_1[0x31] = 0x4e6e6b28;
      param_1[0x32] = 0x4e6e6b28;
    }
    dVar2 = *(double *)(param_1 + 0x3a);
    dVar3 = *(double *)(param_1 + 0x38);
    *param_3 = (float)*(double *)(param_1 + 0x36);
    param_3[1] = (float)dVar3;
    param_3[2] = (float)dVar2;
    return 0;
  }
  if (param_1[0x34] == 0) {
    return 0;
  }
  FUN_00459ae0(0x9999999a,0x3f899999);
  FUN_00459ae0(0x9999999a,0x3f899999);
  dVar2 = *(double *)(param_1 + 0x3a);
  dVar3 = *(double *)(param_1 + 0x38);
  *param_3 = (float)*(double *)(param_1 + 0x36);
  param_3[1] = (float)dVar3;
  param_3[2] = (float)dVar2;
  fVar10 = (float10)FUN_00588570();
  if (ABS(*(double *)(param_1 + 0x46)) == _DAT_0059e420) {
    fVar11 = (float10)fpatan(-(float10)*(double *)(param_1 + 0x48),
                             (float10)*(double *)(param_1 + 0x3c));
    fVar12 = (float10)_DAT_0059e430;
  }
  else {
    fVar11 = (float10)fpatan((float10)*(double *)(param_1 + 0x40),
                             (float10)*(double *)(param_1 + 0x4c));
    fVar12 = (float10)fpatan((float10)*(double *)(param_1 + 0x42),
                             (float10)*(double *)(param_1 + 0x44));
  }
  FUN_0054b4d0(*param_3,(float)dVar3,(float)dVar2,(float)-fVar10,(float)fVar11,(float)fVar12);
  pdVar9 = (double *)(param_1 + 0x4e);
  if (_DAT_0059f070 <= *(double *)(param_1 + 0x50)) {
    if ((*(double *)(param_1 + 0x52) * *(double *)(param_1 + 0x52) +
         *(double *)(param_1 + 0x50) * *(double *)(param_1 + 0x50) + *pdVar9 * *pdVar9 <
         _DAT_0059f068) &&
       (*(double *)(param_1 + 0x58) * *(double *)(param_1 + 0x58) +
        *(double *)(param_1 + 0x56) * *(double *)(param_1 + 0x56) +
        *(double *)(param_1 + 0x54) * *(double *)(param_1 + 0x54) < _DAT_0059f060)) {
      dVar2 = *(double *)(param_1 + 0x88) * *(double *)(param_1 + 0x70) +
              *(double *)(param_1 + 0x72) * *(double *)(param_1 + 0x8a) +
              *(double *)(param_1 + 0x74) * *(double *)(param_1 + 0x8c);
      dVar3 = *(double *)(param_1 + 0x78) * *(double *)(param_1 + 0x8a) +
              *(double *)(param_1 + 0x7a) * *(double *)(param_1 + 0x8c) +
              *(double *)(param_1 + 0x76) * *(double *)(param_1 + 0x88);
      dVar4 = *(double *)(param_1 + 0x7e) * *(double *)(param_1 + 0x8a) +
              *(double *)(param_1 + 0x80) * *(double *)(param_1 + 0x8c) +
              *(double *)(param_1 + 0x7c) * *(double *)(param_1 + 0x88);
      if (((*(double *)(param_1 + 0x86) * *(double *)(param_1 + 0x86) +
           *(double *)(param_1 + 0x84) * *(double *)(param_1 + 0x84) +
           *(double *)(param_1 + 0x82) * *(double *)(param_1 + 0x82)) * *(double *)(param_1 + 0x62)
           < _DAT_0059f068) && (dVar3 * dVar3 + dVar4 * dVar4 + dVar2 * dVar2 < _DAT_0059f060)) {
        local_20[0] = 0;
        local_20[1] = 0;
        local_20[2] = 0;
        local_20[3] = 0;
        local_20[4] = 0;
        local_20[5] = 0;
        piVar7 = local_20;
        for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(int *)pdVar9 = *piVar7;
          piVar7 = piVar7 + 1;
          pdVar9 = (double *)((int)pdVar9 + 4);
        }
        FUN_00569280(local_20);
        param_1[8] = param_1[9];
        return 1;
      }
    }
    return 1;
  }
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  piVar7 = local_20;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(int *)pdVar9 = *piVar7;
    piVar7 = piVar7 + 1;
    pdVar9 = (double *)((int)pdVar9 + 4);
  }
  FUN_00569280(local_20);
  param_1[8] = param_1[9];
  return 1;
}


