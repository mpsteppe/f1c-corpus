// Function: FUN_004eb430 @ 004eb430
// Size (bytes): 2029


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004eb430(int *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  float *pfVar12;
  int *piVar13;
  bool bVar14;
  float10 fVar15;
  float local_4c;
  float local_48;
  float local_44;
  float local_2c;
  float local_28;
  float local_24;
  float local_14;
  float local_10;
  float local_c;
  
  *(undefined1 *)((int)param_1 + 0x3b75) = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0x3f800000;
  param_1[0x2d] = 0;
  if ((param_1[0xcaf] != 0) && (param_1[0xcaf] != 1)) {
    return;
  }
  if ((*(byte *)(*param_1 + 0x48bc) & 1) == 0) {
    return;
  }
  if ((char)param_1[0x41c] != '\0') {
    *(undefined1 *)(param_1 + 0x41c) = 0;
    piVar13 = param_1 + 0x41d;
    iVar9 = 0x11;
    do {
      *(undefined1 *)piVar13 = 0;
      piVar13 = piVar13 + 7;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  piVar13 = param_1 + 0xede;
  iVar9 = 4;
  do {
    iVar11 = *piVar13;
    if ((char)iVar11 != '\0') {
      cVar8 = *(char *)((int)piVar13 + 1);
      *(undefined1 *)(param_1 + 0x41c) = 1;
      *(char *)(piVar13 + -0xa66) = (char)iVar11;
      *(char *)((int)piVar13 + -0x2997) = cVar8;
      piVar13[-0xa62] = piVar13[4];
      piVar13[-0xa61] = piVar13[5];
      piVar13[-0xa60] = piVar13[6];
      *(char *)piVar13 = '\0';
    }
    piVar13 = piVar13 + 7;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  DAT_008adaf8 = 0;
  fVar15 = (float10)FUN_004e9980();
  FUN_004be340(param_1,param_1 + 0xd35,(float)fVar15);
  cVar8 = FUN_004e96c0();
  if (cVar8 != '\0') {
    fVar15 = (float10)FUN_004e9a40(0);
    FUN_004be4e0(param_1[0x1ba],param_1 + 0xd35,(float)fVar15);
  }
  FUN_004e9bd0();
  FUN_004ea970();
  iVar9 = DAT_008adaf8;
  if (DAT_008adaf8 < 1) {
    return;
  }
  if (DAT_008adaf8 < 2) goto LAB_004eb66b;
  local_48 = 0.0;
  local_4c = 0.0;
  fVar2 = DAT_0059e440;
  if (DAT_008adaf8 < 1) {
LAB_004eb621:
    local_4c = 1.0;
  }
  else {
    pfVar12 = (float *)&DAT_008ad400;
    iVar11 = DAT_008adaf8;
    fVar3 = DAT_0059e440;
    do {
      if (local_4c < pfVar12[-1]) {
        local_4c = pfVar12[-1];
      }
      fVar3 = fVar3 + pfVar12[-1];
      if (local_48 < *pfVar12) {
        local_48 = *pfVar12;
      }
      iVar11 = iVar11 + -1;
      fVar2 = fVar2 + *pfVar12;
      pfVar12 = pfVar12 + 0xe;
    } while (iVar11 != 0);
    if (fVar3 <= DAT_0059e440) goto LAB_004eb621;
    local_4c = local_4c / fVar3;
  }
  fVar3 = _DAT_0059e43c;
  if (DAT_0059e440 < fVar2) {
    fVar3 = local_48 / fVar2;
  }
  if (0 < DAT_008adaf8) {
    pfVar12 = (float *)&DAT_008ad400;
    iVar11 = DAT_008adaf8;
    do {
      iVar11 = iVar11 + -1;
      pfVar12[-1] = local_4c * pfVar12[-1];
      *pfVar12 = fVar3 * *pfVar12;
      pfVar12 = pfVar12 + 0xe;
    } while (iVar11 != 0);
  }
LAB_004eb66b:
  local_44 = 0.0;
  if (0 < iVar9) {
    pfVar12 = (float *)&DAT_008ad42c;
    do {
      pfVar1 = pfVar12 + -0xd;
      FUN_004ebc60(pfVar1,1);
      fVar2 = ABS(pfVar12[-0xc]);
      pfVar12[-0xc] = -pfVar12[-0xc];
      switch(pfVar12[-10]) {
      case 0.0:
      case 1.4013e-45:
      case 2.8026e-45:
      case 4.2039e-45:
      case 5.60519e-45:
      case 7.00649e-45:
        FUN_0040f4b0(pfVar1,param_1[0xd2b]);
        iVar9 = 0x25;
        local_4c = (fVar2 - _DAT_0059e7ec) * _DAT_0059e444;
        goto LAB_004eb84c;
      case 8.40779e-45:
        FUN_0040f4b0(pfVar1,param_1[0xd2b]);
        local_4c = (fVar2 - _DAT_0059e874) * _DAT_005ad1e8;
        iVar9 = (int)ROUND(local_4c * _DAT_0059e478);
        if (iVar9 < 0) {
          iVar9 = 0;
        }
        else if (3 < iVar9) {
          iVar9 = 3;
        }
        uVar10 = DAT_008aae70 & 0xff;
        DAT_008aae70 = DAT_008aae70 + 1;
        if (DAT_0059e440 < *(float *)(&DAT_008ab274 + uVar10 * 4)) {
          iVar9 = iVar9 + 1;
        }
        iVar9 = iVar9 + 0x20;
        bVar14 = DAT_007cf728 == '\0';
LAB_004eb739:
        if ((!bVar14) &&
           (_DAT_005ad1e4 <
            (float)param_1[0xd3d] * (float)param_1[0xd3d] +
            (float)param_1[0xd3c] * (float)param_1[0xd3c] +
            (float)param_1[0xd3b] * (float)param_1[0xd3b])) {
          fVar3 = (float)param_1[0xd3b] * _DAT_0059e450;
          fVar4 = (float)param_1[0xd3d] * _DAT_0059e450;
          fVar5 = (float)param_1[0xd3c] * _DAT_0059e450 + _DAT_0059e800;
          fVar6 = pfVar12[-2] * _DAT_0059e450;
          piVar13 = param_1 + (int)*pfVar1 * 7 + 0x41d;
          fVar7 = pfVar12[-1] * _DAT_0059e450;
          fVar2 = *pfVar12;
          *(undefined1 *)(param_1 + 0x41c) = 1;
          fVar2 = fVar2 * _DAT_0059e450;
          *(undefined1 *)piVar13 = 8;
          *(undefined1 *)((int)piVar13 + 1) = 8;
          piVar13[4] = (int)(fVar3 + fVar6);
          piVar13[5] = (int)(fVar7 + fVar5);
          piVar13[6] = (int)(fVar4 + fVar2);
        }
        break;
      default:
        goto switchD_004eb6b1_caseD_7;
      case 1.26117e-44:
        fVar3 = pfVar12[-9];
        if (fVar3 == 0.0) {
          iVar9 = 0x1b;
        }
        else {
          iVar9 = *(int *)((int)fVar3 + 0x38);
          if (*(float *)((int)fVar3 + 8) - *(float *)((int)fVar3 + 0xc) * DAT_0059e440 ==
              DAT_0059e440) {
            *(undefined1 *)((int)param_1 + 0x3b75) = 1;
          }
        }
        local_4c = (fVar2 - _DAT_0059e874) * _DAT_005ad1e8;
        iVar11 = (int)ROUND(local_4c * _DAT_0059e478);
        if (iVar11 < 0) {
          iVar11 = 0;
        }
        else if (3 < iVar11) {
          iVar11 = 3;
        }
        uVar10 = DAT_008aae70 & 0xff;
        DAT_008aae70 = DAT_008aae70 + 1;
        if (DAT_0059e440 < *(float *)(&DAT_008ab274 + uVar10 * 4)) {
          iVar11 = iVar11 + 1;
        }
        iVar9 = iVar9 + iVar11;
        if ((pfVar12[-9] != 0.0) && (-1 < (int)*pfVar1)) {
          bVar14 = *(int *)((int)pfVar12[-9] + 0x28) == 0;
          goto LAB_004eb739;
        }
      }
      if (iVar9 != -1) {
LAB_004eb84c:
        if (_DAT_0059e444 < local_4c) {
          if (_DAT_0059e43c < local_4c) {
            local_4c = 1.0;
          }
          fVar15 = (float10)FUN_004f8ab0(iVar9);
          if (fVar15 < (float10)local_4c) {
            fVar2 = pfVar12[-8] - (float)param_1[0xd35];
            fVar4 = pfVar12[-7] - (float)param_1[0xd36];
            fVar3 = pfVar12[-6] - (float)param_1[0xd37];
            local_14 = fVar2 * (float)param_1[0xd2c] +
                       fVar4 * (float)param_1[0xd2f] + fVar3 * (float)param_1[0xd32];
            local_10 = fVar2 * (float)param_1[0xd2d] +
                       fVar4 * (float)param_1[0xd30] + fVar3 * (float)param_1[0xd33];
            local_c = fVar2 * (float)param_1[0xd2e] +
                      fVar4 * (float)param_1[0xd31] + fVar3 * (float)param_1[0xd34];
            FUN_004f8850(iVar9,2,local_4c,0x3f800000,&local_14);
          }
        }
      }
switchD_004eb6b1_caseD_7:
      local_44 = (float)((int)local_44 + 1);
      pfVar12 = pfVar12 + 0xe;
      iVar9 = DAT_008adaf8;
    } while ((int)local_44 < DAT_008adaf8);
  }
  iVar11 = 0;
  if (0 < iVar9) {
    piVar13 = &DAT_008ad404;
    do {
      iVar9 = *piVar13;
      if ((iVar9 != 9) && (iVar9 != 10)) {
        switch(iVar9) {
        case 0:
        case 3:
          local_4c = (float)*(double *)(*(int *)(piVar13[1] + 0x20) + 0x180);
          break;
        case 1:
        case 4:
          local_4c = (float)*(double *)(*(int *)(piVar13[1] + 0x20) + 0x180);
          break;
        case 2:
        case 5:
          local_4c = (float)*(double *)(*(int *)(piVar13[1] + 0x20) + 0x180);
          break;
        case 6:
          local_4c = *(float *)(*(int *)(piVar13[1] + 0x20) + 0x3514);
        }
        local_44 = ((float)piVar13[-1] * (float)param_1[0xd45]) / (local_4c + (float)param_1[0xd45])
        ;
        piVar13[-1] = (int)((float)piVar13[-1] - local_44);
      }
      FUN_004ec080(piVar13 + -3);
      if ((*piVar13 != 9) && (*piVar13 != 10)) {
        piVar13[-1] = (int)-local_44;
        FUN_0040f550(piVar13 + -3);
      }
      iVar11 = iVar11 + 1;
      piVar13 = piVar13 + 0xe;
      iVar9 = DAT_008adaf8;
    } while (iVar11 < DAT_008adaf8);
  }
  if (param_1[0xea7] == 0) {
    FUN_004e9630();
    iVar9 = DAT_008adaf8;
  }
  pfVar12 = (float *)param_1[0xea7];
  local_2c = *pfVar12 - (float)param_1[0xd35];
  local_28 = pfVar12[1] - (float)param_1[0xd36];
  local_24 = pfVar12[2] - (float)param_1[0xd37];
  if (((local_2c != DAT_0059e440) || (local_28 != DAT_0059e440)) || (local_24 != DAT_0059e440)) {
    fVar2 = _DAT_0059e43c / SQRT(local_2c * local_2c + local_28 * local_28 + local_24 * local_24);
    local_2c = local_2c * fVar2;
    local_28 = local_28 * fVar2;
    local_24 = local_24 * fVar2;
  }
  iVar11 = 0;
  if (0 < iVar9) {
    pfVar12 = (float *)&DAT_008ad428;
    do {
      if ((pfVar12[-9] == 1.26117e-44) &&
         (local_28 * *pfVar12 + local_2c * pfVar12[-1] + local_24 * pfVar12[1] < _DAT_005ad1e0)) {
        *(undefined1 *)(param_1 + 0xffc) = 1;
        iVar9 = DAT_008adaf8;
      }
      iVar11 = iVar11 + 1;
      pfVar12 = pfVar12 + 0xe;
    } while (iVar11 < iVar9);
  }
  return;
}


