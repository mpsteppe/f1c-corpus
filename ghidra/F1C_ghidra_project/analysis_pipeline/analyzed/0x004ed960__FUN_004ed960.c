// Function: FUN_004ed960 @ 004ed960
// Size (bytes): 2003


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ed960(int *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  
  if (DAT_0059e440 < (float)param_1[0xe5e]) {
    fVar3 = (float)param_1[0xe5e] -
            (float)param_1[0xe65] * (float)param_1[0xe61] * (float)param_1[0xd5c] * param_2;
    param_1[0xe5e] = (int)fVar3;
    if (fVar3 < DAT_0059e440 != (fVar3 == DAT_0059e440)) {
      param_1[0xe5e] = 0;
      if (*(int *)(*param_1 + 0x4068) == 0) {
        *(undefined4 *)(*param_1 + 0x4068) = 9;
      }
    }
  }
  fVar3 = (float)param_1[0xe5e] * _DAT_0059e7fc + (float)param_1[0xd44];
  param_1[0xd45] = (int)fVar3;
  param_1[0xd46] = (int)(_DAT_0059e43c / fVar3);
  if (_DAT_0059e43c <
      (float)param_1[0xd3d] * (float)param_1[0xd3d] +
      (float)param_1[0xd3c] * (float)param_1[0xd3c] + (float)param_1[0xd3b] * (float)param_1[0xd3b])
  {
    pfVar6 = (float *)(param_1 + 0xd74);
    iVar8 = 4;
    fVar3 = DAT_0059e440;
    do {
      fVar3 = fVar3 + *pfVar6;
      pfVar6 = pfVar6 + 0x3e;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    pfVar6 = (float *)(param_1 + 0xd8c);
    iVar8 = 4;
    fVar3 = _DAT_0059e43c - fVar3 * _DAT_005ad200;
    do {
      if ((DAT_0059e440 < pfVar6[-0x1b]) &&
         (fVar4 = *pfVar6 - fVar3 * pfVar6[-0x1b] * pfVar6[1] * (float)DAT_007d0c60 * param_2,
         *pfVar6 = fVar4, fVar4 < (float)_DAT_0059ea60)) {
        *pfVar6 = 0.75;
      }
      pfVar6 = pfVar6 + 0x3e;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  fVar4 = _DAT_008afee8;
  iVar8 = 4;
  fVar3 = (_DAT_008aced4 - _DAT_008aced0) * _DAT_008afee8 + _DAT_008aced0;
  pfVar6 = (float *)(param_1 + 0xd88);
  do {
    iVar8 = iVar8 + -1;
    pfVar6[-1] = ((pfVar6[1] - *pfVar6) * fVar4 + *pfVar6) * pfVar6[4] * (float)param_1[0xefd] *
                 fVar3;
    pfVar6 = pfVar6 + 0x3e;
  } while (iVar8 != 0);
  if (_DAT_0059e918 < ABS((float)_DAT_008afea0 - (float)param_1[0xefe])) {
    uVar9 = DAT_008aae70 & 0xff;
    DAT_008aae70 = DAT_008aae70 + 1;
    param_1[0xefe] =
         (int)(*(float *)(&DAT_008ab274 + uVar9 * 4) + *(float *)(&DAT_008ab274 + uVar9 * 4) +
              (float)_DAT_008afea0);
    FUN_004e8010(0);
  }
  cVar5 = FUN_004d21d0();
  if (cVar5 != '\0') {
    iVar8 = 0;
    do {
      if ((DAT_0059e440 <= (float)param_1[iVar8 + 0xf59]) &&
         (fVar3 = (float)param_1[iVar8 + 0xf59], param_1[iVar8 + 0xf59] = (int)(fVar3 - param_2),
         fVar3 - param_2 < DAT_0059e440)) {
        switch(iVar8) {
        case 0:
          if (*(int *)(*param_1 + 0x4068) == 0) {
            *(undefined4 *)(*param_1 + 0x4068) = 1;
          }
          if ((float)param_1[0xe66] * _DAT_0059e450 <= (float)param_1[0xe65]) {
            if (((float)param_1[0xf52] == DAT_0059e440) && ((float)param_1[0xf53] == DAT_0059e440))
            {
              fVar3 = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
              DAT_008aae70 = DAT_008aae70 + 1;
              if (fVar3 < _DAT_0059e450) {
                iVar7 = 0;
                if (0 < param_1[0xe6c]) {
                  do {
                    iVar1 = iVar7 * 8;
                    iVar2 = iVar7 * 8;
                    iVar7 = iVar7 + 1;
                    *(float *)(param_1[0xe69] + 4 + iVar2) =
                         *(float *)(param_1[0xe69] + 4 + iVar1) * _DAT_0059e824;
                  } while (iVar7 < param_1[0xe6c]);
                }
                if (_DAT_0059e8b4 <= fVar3) {
                  if (_DAT_0059e8c8 <= fVar3) {
                    fVar3 = fVar3 - _DAT_0059e8c8;
                    param_1[0xf54] = -0x3bbac000;
                    fVar3 = fVar3 * _DAT_0059e828;
                  }
                  else {
                    fVar3 = fVar3 - _DAT_0059e8b4;
                    param_1[0xf53] = -0x3bbac000;
                    fVar3 = fVar3 * _DAT_0059e93c;
                  }
                }
                else {
                  fVar3 = fVar3 * _DAT_0059e874;
                  param_1[0xf52] = -0x3bbac000;
                }
                param_1[iVar8 + 0xf59] = (int)fVar3;
                if ((DAT_007cea5c == 3) && (_DAT_0059f118 < (float)param_1[iVar8 + 0xf59])) {
                  param_1[iVar8 + 0xf59] = 0x42700000;
                }
                break;
              }
            }
            if ((((float)param_1[0xf52] != (float)_DAT_005ad1f8) &&
                ((float)param_1[0xf53] != (float)_DAT_005ad1f8)) &&
               ((float)param_1[0xf54] != (float)_DAT_005ad1f8)) {
              fVar3 = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
              DAT_008aae70 = DAT_008aae70 + 1;
              if (_DAT_0059e8c8 <= fVar3) {
                if (_DAT_0059e8f8 <= fVar3) {
                  if (fVar3 < _DAT_0059e824) {
                    param_1[0xf54] = -0x3bbac000;
                  }
                }
                else {
                  param_1[0xf53] = -0x3bbac000;
                }
              }
              else {
                param_1[0xf52] = -0x3bbac000;
              }
            }
            if ((float)param_1[0xf52] == (float)_DAT_005ad1f8) {
              uVar9 = DAT_008aae70 & 0xff;
              DAT_008aae70 = DAT_008aae70 + 1;
              param_1[0xf52] =
                   (int)(_DAT_0059e43c - *(float *)(&DAT_008aae74 + uVar9 * 4) * _DAT_0059e8b4);
              uVar10 = DAT_008aae70 & 0xff;
              DAT_008aae70 = DAT_008aae70 + 1;
              uVar9 = DAT_008aae70;
              if (*(float *)(&DAT_008aae74 + uVar10 * 4) < _DAT_0059e7e8) {
                param_1[0xf53] = (int)(*(float *)(&DAT_008aae74 + uVar10 * 4) + _DAT_0059e84c);
                uVar9 = DAT_008aae70;
              }
            }
            else if ((float)param_1[0xf53] == (float)_DAT_005ad1f8) {
              uVar9 = DAT_008aae70 & 0xff;
              DAT_008aae70 = DAT_008aae70 + 1;
              param_1[0xf53] =
                   (int)(_DAT_0059e43c - *(float *)(&DAT_008aae74 + uVar9 * 4) * _DAT_0059e8b4);
              fVar3 = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
              uVar9 = DAT_008aae70 + 1;
              if (_DAT_0059e7e8 <= fVar3) {
                if (fVar3 < _DAT_0059e8cc) {
                  DAT_008aae70 = DAT_008aae70 + 2;
                  param_1[0xf54] =
                       (int)(_DAT_0059e43c -
                            *(float *)(&DAT_008aae74 + (uVar9 & 0xff) * 4) * _DAT_0059e8b4);
                  uVar9 = DAT_008aae70;
                }
              }
              else {
                DAT_008aae70 = uVar9;
                param_1[0xf52] = (int)(fVar3 + _DAT_0059e84c);
                uVar9 = DAT_008aae70;
              }
            }
            else {
              uVar9 = DAT_008aae70;
              if ((float)param_1[0xf54] == (float)_DAT_005ad1f8) {
                uVar9 = DAT_008aae70 & 0xff;
                DAT_008aae70 = DAT_008aae70 + 1;
                param_1[0xf54] =
                     (int)(_DAT_0059e43c - *(float *)(&DAT_008aae74 + uVar9 * 4) * _DAT_0059e8b4);
                uVar9 = DAT_008aae70 & 0xff;
                DAT_008aae70 = DAT_008aae70 + 1;
                param_1[0xf53] =
                     (int)(_DAT_0059e43c - *(float *)(&DAT_008aae74 + uVar9 * 4) * _DAT_0059e8b4);
                uVar9 = DAT_008aae70;
              }
            }
            DAT_008aae70 = uVar9;
            iVar7 = 0;
            if (0 < param_1[0xe6c]) {
              do {
                *(undefined4 *)(param_1[0xe69] + 4 + iVar7 * 8) = 0;
                iVar7 = iVar7 + 1;
              } while (iVar7 < param_1[0xe6c]);
            }
            iVar7 = *param_1;
            uVar11 = 0;
            goto LAB_004ee10e;
          }
          param_1[iVar8 + 0xf59] = 0;
          break;
        case 1:
          if (*(int *)(*param_1 + 0x4068) == 0) {
            *(undefined4 *)(*param_1 + 0x4068) = 5;
          }
          if (((float)param_1[0xd5e] != DAT_0059e440) &&
             (_DAT_0059e6f8 <=
              (float)param_1[0xd3d] * (float)param_1[0xd3d] +
              (float)param_1[0xd3c] * (float)param_1[0xd3c] +
              (float)param_1[0xd3b] * (float)param_1[0xd3b])) {
            uVar9 = DAT_008aae70 & 0xff;
            DAT_008aae70 = DAT_008aae70 + 1;
            if (*(float *)(&DAT_008ab274 + uVar9 * 4) <= _DAT_0059e4e8) {
              iVar7 = *param_1;
              uVar11 = 1;
              param_1[0xe8c] = (int)((float)param_1[0xe8c] * _DAT_0059ed18);
            }
            else {
              iVar7 = *param_1;
              uVar11 = 1;
              param_1[0xe91] = (int)((float)param_1[0xe91] * _DAT_0059ed18);
            }
            goto LAB_004ee10e;
          }
LAB_004ee0ce:
          param_1[iVar8 + 0xf59] = 0;
          break;
        case 2:
          if (*(int *)(*param_1 + 0x4068) == 0) {
            *(undefined4 *)(*param_1 + 0x4068) = 2;
          }
          if ((float)param_1[0xe66] * _DAT_0059e450 <= (float)param_1[0xe65]) {
            *(undefined1 *)((int)param_1 + 0x39ee) = 1;
            if (param_1[0xf58] == 0) {
              param_1[0xf58] = 1;
            }
            iVar7 = *param_1;
            uVar11 = 2;
            goto LAB_004ee118;
          }
          param_1[iVar8 + 0xf59] = 0;
          break;
        case 3:
          if (*(int *)(*param_1 + 0x4068) == 0) {
            *(undefined4 *)(*param_1 + 0x4068) = 4;
          }
          if ((float)param_1[0xd3d] * (float)param_1[0xd3d] +
              (float)param_1[0xd3c] * (float)param_1[0xd3c] +
              (float)param_1[0xd3b] * (float)param_1[0xd3b] < _DAT_0059e6f8) goto LAB_004ee0ce;
          uVar9 = _rand();
          uVar9 = uVar9 & 0x80000003;
          if ((int)uVar9 < 0) {
            uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
          }
          param_1[uVar9 * 0x3e + 0xd78] =
               (int)((float)param_1[uVar9 * 0x3e + 0xd78] + _DAT_0059e448);
          iVar7 = *param_1;
          uVar11 = 3;
LAB_004ee10e:
          param_1[0xf58] = 2;
LAB_004ee118:
          FUN_0041ac50(iVar7,uVar11);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
  }
  return;
}


