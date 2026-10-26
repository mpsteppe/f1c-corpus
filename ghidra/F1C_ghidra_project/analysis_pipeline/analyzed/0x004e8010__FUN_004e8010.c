// Function: FUN_004e8010 @ 004e8010
// Size (bytes): 1895


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e8010(int param_1,char param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  float10 fVar16;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float *local_3c;
  int local_30;
  float local_2c;
  float local_18 [5];
  
  fVar2 = _DAT_007d0278;
  fVar7 = _DAT_0059e43c / _DAT_007d029c;
  local_48 = 0.0;
  pfVar13 = (float *)(param_1 + 0x362c);
  fVar6 = (float)_DAT_0059e420 / (_DAT_005acb44 * _DAT_007d0278);
  *(float *)(param_1 + 0x3bfc) = fVar6;
  *(float *)(param_1 + 0x3c3c) = fVar6;
  *(float *)(param_1 + 0x3c7c) = fVar6;
  *(float *)(param_1 + 0x3cbc) = fVar6;
  *(float *)(param_1 + 0x3cfc) = (float)_DAT_0059e420 / (fVar7 * _DAT_005acb44);
  fVar6 = _DAT_0059e43c /
          (ABS(((*(float *)(param_1 + 0x368c) + *(float *)(param_1 + 0x3594)) -
               *(float *)(param_1 + 0x3784)) - *(float *)(param_1 + 0x387c)) * _DAT_0059e450);
  fVar1 = _DAT_0059e43c /
          (ABS(((*(float *)(param_1 + 0x358c) - *(float *)(param_1 + 0x3684)) +
               *(float *)(param_1 + 0x377c)) - *(float *)(param_1 + 0x3874)) * _DAT_0059e450);
  local_3c = (float *)(param_1 + 0x3cc0);
  do {
    iVar15 = 4;
    fVar3 = (float)(int)local_48 * fVar2 * _DAT_005acb44;
    pfVar14 = pfVar13;
    fVar5 = DAT_0059e440;
    do {
      fVar8 = fVar3 * pfVar14[0x12];
      fVar4 = fVar8;
      if (*pfVar14 < fVar8) {
        fVar4 = *pfVar14;
      }
      iVar15 = iVar15 + -1;
      fVar5 = (fVar4 * pfVar14[-1] + _DAT_0059e43c) * pfVar14[-4] * fVar8 + fVar5;
      pfVar14 = pfVar14 + 0x3e;
    } while (iVar15 != 0);
    fVar5 = fVar5 * *(float *)(param_1 + 0x4024);
    iVar15 = 0;
    fVar8 = fVar6 * fVar5 * _DAT_0059e450;
    fVar5 = fVar5 * fVar1 * _DAT_0059e450;
    pfVar14 = pfVar13;
    fVar4 = DAT_0059e440;
    do {
      fVar9 = fVar8;
      if ((iVar15 != 0) && (iVar15 != 1)) {
        fVar9 = -fVar8;
      }
      fVar9 = fVar3 * pfVar14[0x12] + fVar9;
      fVar10 = fVar9;
      if (*pfVar14 < fVar9) {
        fVar10 = *pfVar14;
      }
      iVar15 = iVar15 + 1;
      fVar4 = (fVar10 * pfVar14[-1] + _DAT_0059e43c) * pfVar14[-4] * fVar9 + fVar4;
      pfVar14 = pfVar14 + 0x3e;
    } while (iVar15 < 4);
    iVar15 = 0;
    pfVar14 = pfVar13;
    fVar9 = DAT_0059e440;
    do {
      fVar10 = fVar8;
      if (*(int *)(param_1 + 0x39b4) == 0) {
        if (iVar15 == 2) {
LAB_004e81f4:
          fVar10 = fVar3 * pfVar14[0x12] + fVar10;
          fVar11 = fVar10;
          if (*pfVar14 < fVar10) {
            fVar11 = *pfVar14;
          }
          fVar9 = (fVar11 * pfVar14[-1] + _DAT_0059e43c) * pfVar14[-4] * fVar10 + fVar9;
        }
        else if (iVar15 == 3) goto LAB_004e81de;
      }
      else if (((*(int *)(param_1 + 0x39b4) != 2) || (iVar15 == 0)) || (iVar15 == 1)) {
LAB_004e81de:
        if ((iVar15 != 2) && (iVar15 != 3)) {
          fVar10 = -fVar8;
        }
        goto LAB_004e81f4;
      }
      iVar15 = iVar15 + 1;
      pfVar14 = pfVar14 + 0x3e;
    } while (iVar15 < 4);
    iVar15 = 0;
    pfVar14 = pfVar13;
    fVar8 = DAT_0059e440;
    do {
      fVar10 = fVar5;
      if ((iVar15 != 1) && (iVar15 != 3)) {
        fVar10 = -fVar5;
      }
      fVar10 = fVar3 * pfVar14[0x12] + fVar10;
      fVar11 = fVar10;
      if (*pfVar14 < fVar10) {
        fVar11 = *pfVar14;
      }
      iVar15 = iVar15 + 1;
      fVar8 = (fVar11 * pfVar14[-1] + _DAT_0059e43c) * pfVar14[-4] * fVar10 + fVar8;
      pfVar14 = pfVar14 + 0x3e;
    } while (iVar15 < 4);
    iVar15 = 0;
    pfVar14 = pfVar13;
    fVar10 = DAT_0059e440;
    do {
      fVar11 = fVar5;
      if ((iVar15 != 0) && (iVar15 != 2)) {
        fVar11 = -fVar5;
      }
      fVar11 = fVar3 * pfVar14[0x12] + fVar11;
      fVar12 = fVar11;
      if (*pfVar14 < fVar11) {
        fVar12 = *pfVar14;
      }
      iVar15 = iVar15 + 1;
      fVar10 = (fVar12 * pfVar14[-1] + _DAT_0059e43c) * pfVar14[-4] * fVar11 + fVar10;
      pfVar14 = pfVar14 + 0x3e;
    } while (iVar15 < 4);
    local_3c[-0x30] = fVar4;
    local_48 = (float)((int)local_48 + 1);
    *local_3c = fVar9;
    local_3c[-0x20] = fVar8;
    local_3c[-0x10] = fVar10;
    local_3c = local_3c + 1;
  } while ((int)local_48 < 0xf);
  iVar15 = *(int *)(param_1 + 0x39b4);
  if (iVar15 == 0) {
    fVar6 = *(float *)(param_1 + 0x38f8) + *(float *)(param_1 + 0x3800);
LAB_004e835d:
    fVar6 = fVar6 * _DAT_0059e450;
  }
  else {
    if (iVar15 != 1) {
      if (iVar15 != 2) goto LAB_004e8369;
      fVar6 = *(float *)(param_1 + 0x3708) + *(float *)(param_1 + 0x3610);
      goto LAB_004e835d;
    }
    fVar6 = (*(float *)(param_1 + 0x38f8) + *(float *)(param_1 + 0x3800) +
             *(float *)(param_1 + 0x3708) + *(float *)(param_1 + 0x3610)) * _DAT_0059e7f8;
  }
  *(float *)(param_1 + 0x3d40) = fVar6;
LAB_004e8369:
  pfVar13 = (float *)(param_1 + 0x3610);
  iVar15 = 0;
  pfVar14 = pfVar13;
  fVar6 = DAT_0059e440;
  do {
    if ((iVar15 == 0) || (iVar15 == 1)) {
      fVar1 = *(float *)(param_1 + 0x3a30);
    }
    else {
      fVar1 = *(float *)(param_1 + 0x3a44);
    }
    fVar2 = *pfVar14;
    iVar15 = iVar15 + 1;
    pfVar14 = pfVar14 + 0x3e;
    fVar6 = fVar1 / fVar2 + fVar6;
  } while (iVar15 < 4);
  fVar6 = fVar6 * *(float *)(param_1 + 0x3518);
  iVar15 = 0;
  *(float *)(param_1 + 0x3d3c) = fVar6;
  fVar1 = *(float *)(param_1 + 0x3a6c);
  *(float *)(param_1 + 0x3d44) = fVar1;
  fVar2 = *(float *)(param_1 + 0x3a70);
  fVar3 = *(float *)(param_1 + 0x3514);
  do {
    if (*pfVar13 <= DAT_0059e440) {
      local_18[iVar15] = 0.0;
    }
    else {
      local_18[iVar15] = ((fVar2 * _DAT_005ad1c0 - fVar3 * _DAT_0059e438) / *pfVar13) * pfVar13[10];
    }
    iVar15 = iVar15 + 1;
    pfVar13 = pfVar13 + 0x3e;
  } while (iVar15 < 4);
  iVar15 = 0xf;
  *(float *)(param_1 + 0x3d44) =
       ((local_18[1] + local_18[0]) * _DAT_005acee8 + (local_18[3] + local_18[2]) * _DAT_005ad1bc) *
       _DAT_005ad1b8 + fVar1;
  if (param_2 == '\0') {
    *(float *)(param_1 + 0x3d3c) = fVar6 * _DAT_007d020c;
    pfVar13 = (float *)(param_1 + 0x3c40);
    do {
      iVar15 = iVar15 + -1;
      pfVar13[-0x10] = _DAT_007d0230 * pfVar13[-0x10];
      fVar6 = _DAT_007d0254;
      *pfVar13 = *pfVar13 * _DAT_007d0254;
      pfVar13[0x10] = pfVar13[0x10] * fVar6;
      pfVar13[0x20] = pfVar13[0x20] * _DAT_005acdc4;
      pfVar13 = pfVar13 + 1;
    } while (iVar15 != 0);
  }
  else {
    *(float *)(param_1 + 0x3d3c) = fVar6 * _DAT_005ad1b4;
    fVar6 = _DAT_0059e43c / *(float *)(param_1 + 0x3bf4);
    pfVar13 = (float *)(param_1 + 0x3c40);
    do {
      iVar15 = iVar15 + -1;
      pfVar13[-0x10] = pfVar13[-0x10] * fVar6 * _DAT_005ad1b4;
      *pfVar13 = *pfVar13 * fVar6 * _DAT_005ad1b0;
      pfVar13[0x10] = pfVar13[0x10] * fVar6 * _DAT_005ad1b0;
      pfVar13[0x20] = pfVar13[0x20] * fVar6 * _DAT_005ad1b4;
      pfVar13 = pfVar13 + 1;
    } while (iVar15 != 0);
  }
  local_48 = 0.0;
  pfVar13 = (float *)(param_1 + 0x3d00);
  do {
    fVar1 = local_48;
    local_4c = 0.0;
    local_40 = 0.0;
    local_2c = 0.0;
    local_44 = 128.0;
    fVar6 = (float)(int)local_48 * fVar7 * _DAT_005acb44;
    while( true ) {
      fVar8 = local_40;
      fVar2 = local_4c * *(float *)(param_1 + 0x3514) * local_4c * fVar6;
      fVar3 = local_4c * local_4c * *(float *)(param_1 + 0x3a70) -
              (local_4c * local_4c * DAT_0059e440 - _DAT_005aceb8) * *(float *)(param_1 + 0x3514);
      fVar5 = fVar3 * *(float *)(param_1 + 0x3c3c);
      fVar16 = (float10)FUN_005895a2((double)fVar5);
      local_48 = (float)(int)ROUND((float)fVar16);
      if ((int)local_48 < 0) {
        local_48 = *(float *)(param_1 + 0x3c40);
      }
      else {
        if (0xd < (int)local_48) {
          local_48 = 1.82169e-44;
        }
        fVar4 = *(float *)(param_1 + 0x3c40 + (int)local_48 * 4);
        local_48 = (fVar5 - (float)(int)local_48) *
                   (*(float *)(param_1 + 0x3c44 + (int)local_48 * 4) - fVar4) + fVar4;
      }
      fVar3 = fVar3 * *(float *)(param_1 + 0x3c7c);
      fVar16 = (float10)FUN_005895a2((double)fVar3);
      local_30 = (int)ROUND((float)fVar16);
      if (local_30 < 0) {
        fVar5 = *(float *)(param_1 + 0x3c80);
      }
      else {
        if (0xd < local_30) {
          local_30 = 0xd;
        }
        fVar5 = *(float *)(param_1 + 0x3c80 + local_30 * 4);
        fVar5 = (fVar3 - (float)local_30) * (*(float *)(param_1 + 0x3c84 + local_30 * 4) - fVar5) +
                fVar5;
      }
      if (fVar5 < local_48) {
        fVar5 = local_48;
      }
      if (fVar2 == DAT_0059e440) {
        local_40 = 1024.0;
      }
      else {
        local_40 = fVar5 / fVar2;
      }
      if (local_44 < _DAT_0059e8c8) break;
      local_2c = local_4c;
      if (fVar5 < fVar2) {
        local_4c = local_4c - local_44;
      }
      else {
        local_4c = local_44 + local_4c;
      }
      local_44 = local_44 * _DAT_0059e450;
    }
    if (local_40 - fVar8 != DAT_0059e440) {
      fVar6 = (local_40 - _DAT_0059e43c) / (local_40 - fVar8);
      if (_DAT_0059e670 <= fVar6) {
        if (_DAT_0059e800 < fVar6) {
          fVar6 = _DAT_0059e800;
        }
        local_4c = (local_2c - local_4c) * fVar6 + local_4c;
      }
      else {
        local_4c = (local_2c - local_4c) * _DAT_0059e670 + local_4c;
      }
    }
    if (local_4c < DAT_0059e440) {
      local_4c = DAT_0059e440;
    }
    local_48 = (float)((int)fVar1 + 1);
    *pfVar13 = local_4c;
    pfVar13 = pfVar13 + 1;
  } while ((int)local_48 < 0xf);
  return;
}


