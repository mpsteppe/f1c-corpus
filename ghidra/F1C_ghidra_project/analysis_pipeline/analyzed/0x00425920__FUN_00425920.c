// Function: FUN_00425920 @ 00425920
// Size (bytes): 2012


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00425920(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int *piVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float local_28;
  float local_24;
  int local_20;
  float local_18 [2];
  float local_10;
  undefined1 local_c [12];
  
  fVar1 = *(float *)(param_1 + 0x4438);
  iVar6 = FUN_00403aa0(param_1 + 0x34e0,*(undefined4 *)(param_1 + 0x4354),
                       *(undefined4 *)(param_1 + 0x4550),0);
  iVar10 = *(int *)(param_1 + 0x454c);
  if (((iVar10 == 0) || (iVar9 = *(int *)(iVar6 + 0x114), iVar9 == 0)) ||
     (iVar10 != *(int *)(iVar9 + 300))) {
    iVar9 = *(int *)(iVar6 + 0x110);
  }
  if (((iVar10 == 0) || (iVar11 = *(int *)(iVar9 + 0x114), iVar11 == 0)) ||
     (iVar10 != *(int *)(iVar11 + 300))) {
    iVar11 = *(int *)(iVar9 + 0x110);
  }
  if ((*(int *)(param_1 + 0x443c) != 0) && (*(int *)(param_1 + 0x4400) != 0)) {
    FUN_004efb20(local_18,local_c);
    fVar2 = local_18[0] - **(float **)(param_1 + 0x4400);
    fVar3 = local_10 - (*(float **)(param_1 + 0x4400))[2];
    fVar2 = SQRT(fVar2 * fVar2 + fVar3 * fVar3);
    local_28 = fVar2 * _DAT_0059e8c8;
    fVar12 = (float10)FUN_004e8b80(*(undefined4 *)(param_1 + 0x4440),local_28,0x3f400000);
    if ((float10)DAT_0059e440 < fVar12) {
      *(undefined4 *)(param_1 + 0x443c) = 0;
      *(float *)(param_1 + 0x4524) = fVar2;
    }
    if (*(float *)(param_1 + 0x4424) == DAT_0059e440) {
      iVar10 = *(int *)(param_1 + 0x4400);
      iVar9 = *(int *)(iVar10 + 0x114);
      if (iVar9 != 0) {
        fVar3 = local_18[0] - *(float *)(iVar9 + 0x94);
        fVar4 = local_10 - *(float *)(iVar9 + 0x9c);
        local_28 = SQRT(fVar3 * fVar3 + fVar4 * fVar4);
        fVar3 = SQRT(*(float *)(iVar10 + 0x18) * *(float *)(iVar10 + 0x18)) + _DAT_0059e8c4;
        if (_DAT_0059e8c0 < fVar3) {
          fVar3 = _DAT_0059e8c0;
        }
        if (_DAT_0059e854 * fVar3 <= local_28) {
          if (local_28 < fVar3) {
            *(undefined4 *)(param_1 + 0x443c) = 0;
            fVar3 = *(float *)(iVar10 + 0x18) * _DAT_0059e450;
            *(float *)(param_1 + 0x4524) = fVar2;
            *(float *)(param_1 + 0x4424) = fVar3;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x443c) = 0;
          *(undefined4 *)(param_1 + 0x4424) = *(undefined4 *)(iVar10 + 0x18);
          *(float *)(param_1 + 0x4524) = fVar2;
        }
      }
    }
  }
  if (*(float *)(param_1 + 0x4524) == DAT_0059e440) {
    fVar2 = *(float *)(param_1 + 0x4440) * _DAT_0059e8b0;
    fVar12 = (float10)FUN_0042a780(iVar6);
    if ((fVar12 < (float10)fVar2) ||
       (fVar12 = (float10)FUN_0042a780(*(undefined4 *)(iVar6 + 0x110)), fVar12 < (float10)fVar2)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if (*(int *)(iVar11 + 0x134) == 1) {
      fVar12 = (float10)*(int *)(iVar11 + 0x138);
    }
    else {
      fVar12 = (float10)FUN_0042a780(iVar11);
      fVar12 = fVar12 * (float10)*(float *)(param_1 + 0x4554);
    }
    local_24 = (float)fVar12;
    local_28 = *(float *)(param_1 + 0x4440);
    piVar7 = (int *)(param_1 + 0x4354);
    local_20 = 0;
    iVar10 = *(int *)(param_1 + 0x4354);
    while (iVar11 != iVar10) {
      piVar7[0x14] = (int)local_28;
      local_20 = local_20 + 1;
      piVar7 = piVar7 + 1;
      if (0x13 < local_20) break;
      iVar10 = *piVar7;
    }
    *(undefined4 *)(param_1 + 0x43f8) = 0;
    fVar2 = DAT_0059e440;
    *(undefined4 *)(param_1 + 0x43fc) = 0x461c3c00;
    if (fVar2 < local_28) {
      pfVar8 = (float *)(param_1 + 0x43a4 + local_20 * 4);
      do {
        if (local_24 <= local_28) {
          if (local_20 < 1) {
            local_20 = 1;
          }
          else if (0x13 < local_20) goto LAB_00425f92;
          iVar10 = 0x14 - local_20;
          pfVar8 = (float *)(param_1 + 0x43a4 + local_20 * 4);
          do {
            iVar10 = iVar10 + -1;
            *pfVar8 = pfVar8[-1] - _DAT_0059e8a8;
            pfVar8 = pfVar8 + 1;
          } while (iVar10 != 0);
LAB_00425f92:
          DAT_005c3160 = '\0';
          *(int *)(param_1 + 0x43f8) = iVar11;
          *(float *)(param_1 + 0x43fc) = local_24;
          break;
        }
        iVar10 = *(int *)(param_1 + 0x454c);
        if (((iVar10 == 0) || (iVar6 = *(int *)(iVar11 + 0x114), iVar6 == 0)) ||
           (iVar10 != *(int *)(iVar6 + 300))) {
          iVar6 = *(int *)(iVar11 + 0x110);
        }
        if (iVar6 == 0) break;
        if (*(int *)(iVar6 + 0x134) == 1) {
          fVar12 = (float10)_DAT_008acfb4;
LAB_00425ec1:
          local_24 = (float)fVar12;
        }
        else {
          if (((*(int *)(iVar6 + 0x114) == 0) ||
              (iVar9 = *(int *)(*(int *)(iVar6 + 0x114) + 300), iVar9 != iVar10)) ||
             ((iVar10 == 1 || (iVar9 == 0)))) {
            fVar12 = (float10)FUN_0042a780(iVar6);
            goto LAB_00425ec1;
          }
          local_24 = 12.0;
        }
        fVar12 = (float10)FUN_004e9100(local_28,*(undefined4 *)(iVar6 + 0x74),iVar6 + 0x78,
                                       *(undefined4 *)(iVar6 + 0x70));
        if ((local_28 <= _DAT_0059e43c) ||
           (local_28 = (float)((float10)local_28 -
                              ((float10)*(float *)(iVar6 + 0x3c) / (float10)local_28) *
                              (float10)*(float *)(param_1 + 0x44cc) * fVar12 *
                              (float10)_DAT_0059e8ac), local_28 < _DAT_0059e450)) {
          local_28 = 0.0;
        }
        if (local_20 < 0x14) {
          local_20 = local_20 + 1;
          *pfVar8 = local_28;
          pfVar8 = pfVar8 + 1;
        }
        iVar11 = iVar6;
      } while (DAT_0059e440 < local_28);
    }
    if ((*(float *)(*(int *)(param_1 + 0x4354) + 0x54) + _DAT_0059e8a4 <=
         *(float *)(param_1 + 0x4428)) ||
       (*(float *)(*(int *)(param_1 + 0x4354) + 0x50) + _DAT_0059e8a4 <=
        -*(float *)(param_1 + 0x4428))) {
      *(undefined1 *)(param_1 + 0x445c) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x445c) = 1;
    }
    if (DAT_0059e440 < local_28) {
      fVar12 = (float10)FUN_004e88b0();
      if ((float10)_DAT_0059e7e8 < fVar12 - (float10)fVar1) {
        fVar12 = (float10)fVar1 + (float10)_DAT_0059e7e8;
      }
      *(float *)(param_1 + 0x4438) = (float)fVar12;
      *(undefined4 *)(param_1 + 0x4434) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x4438) = 0;
    if (bVar5) {
      fVar12 = (float10)FUN_004e87e0();
    }
    else {
      if (*(char *)(param_1 + 0x445c) == '\0') {
        if (*(float *)(param_1 + 0x4440) <= _DAT_0059e8a0) {
          fVar12 = (float10)_DAT_0059e8c8;
        }
        else {
          fVar12 = (float10)_DAT_0059e450;
        }
      }
      else if (*(int *)(param_1 + 0x446c) == 0) {
        fVar12 = (float10)_DAT_0059e43c;
      }
      else {
        fVar12 = (float10)FUN_004e87e0();
      }
      if (DAT_005c3160 == '\0') {
        fVar1 = *(float *)(param_1 + 0x44c4);
      }
      else {
        fVar1 = *(float *)(param_1 + 0x44b8);
      }
      if ((float10)(fVar1 * _DAT_0059e7e8) < fVar12 - (float10)*(float *)(param_1 + 0x4434)) {
        *(float *)(param_1 + 0x4434) = fVar1 * _DAT_0059e7e8 + *(float *)(param_1 + 0x4434);
        return;
      }
    }
    *(float *)(param_1 + 0x4434) = (float)fVar12;
    return;
  }
  FUN_004efb20(local_18,local_c);
  pfVar8 = *(float **)(param_1 + 0x4400);
  fVar1 = pfVar8[0x45];
  if (fVar1 != 0.0) {
    fVar2 = local_18[0] - *(float *)((int)fVar1 + 0x94);
    fVar1 = local_10 - *(float *)((int)fVar1 + 0x9c);
    local_28 = SQRT(fVar2 * fVar2 + fVar1 * fVar1);
    fVar1 = SQRT(pfVar8[6] * pfVar8[6]) * _DAT_0059e8bc + _DAT_0059e8b8;
    if (_DAT_0059e8c0 < fVar1) {
      fVar1 = _DAT_0059e8c0;
    }
    if (_DAT_0059e854 * fVar1 <= local_28) {
      if (local_28 < fVar1) {
        *(undefined4 *)(param_1 + 0x4468) = 0;
        *(undefined4 *)(param_1 + 0x443c) = 0;
        *(float *)(param_1 + 0x4424) = pfVar8[6] * _DAT_0059e450;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x4468) = 0;
      *(undefined4 *)(param_1 + 0x443c) = 0;
      *(float *)(param_1 + 0x4424) = pfVar8[6];
    }
  }
  fVar1 = pfVar8[0x45];
  fVar2 = SQRT((local_18[0] - *pfVar8) * (local_18[0] - *pfVar8) +
               (local_10 - pfVar8[2]) * (local_10 - pfVar8[2]));
  if (fVar1 == 0.0) {
    if (fVar2 < *(float *)(param_1 + 0x4524) == (fVar2 == *(float *)(param_1 + 0x4524)))
    goto LAB_00425c54;
  }
  else {
    local_28 = (pfVar8[2] - local_10) * *(float *)((int)fVar1 + 0x14) +
               (*pfVar8 - local_18[0]) * *(float *)((int)fVar1 + 0xc);
LAB_00425c54:
    if (local_28 <= DAT_0059e440) goto LAB_00425cd1;
  }
  if (_DAT_0059e450 < fVar2) {
    *(float *)(param_1 + 0x4524) = fVar2;
    fVar12 = (float10)FUN_004e8b80(*(undefined4 *)(param_1 + 0x4440),fVar2 * _DAT_0059e8b4,
                                   0x3f333333);
    if ((float10)DAT_0059e440 < fVar12) {
      *(undefined4 *)(param_1 + 0x4434) = 0;
      *(undefined4 *)(param_1 + 0x4438) = 0x3f800000;
      return;
    }
    *(undefined4 *)(param_1 + 0x4438) = 0;
    fVar12 = (float10)FUN_004e87e0();
    *(float *)(param_1 + 0x4434) = (float)fVar12;
    return;
  }
LAB_00425cd1:
  if (fVar2 < _DAT_0059e7ec) {
    *(undefined1 *)(param_1 + 0x45f4) = 0;
  }
  *(undefined4 *)(param_1 + 0x443c) = 0;
  *(undefined4 *)(param_1 + 0x34f8) = 0;
  *(undefined4 *)(param_1 + 0x3500) = 0;
  *(undefined4 *)(param_1 + 0x34fc) = 0;
  *(undefined4 *)(param_1 + 0x43f8) = 0;
  FUN_0042ae00();
  if (DAT_007c56a4 == 7) {
    *(undefined4 *)(param_1 + 0x4510) = 4;
  }
  else {
    *(undefined4 *)(param_1 + 0x4510) = 5;
  }
  *(undefined4 *)(param_1 + 0x4524) = 0;
  *(undefined4 *)(param_1 + 0x4438) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x4434) = 0;
  *(undefined4 *)(param_1 + 0x454c) = 0;
  *(undefined4 *)(param_1 + 0x4550) = 1;
  *(undefined4 *)(param_1 + 0x4424) = 0;
  FUN_00426430();
  return;
}


