// Function: FUN_00451720 @ 00451720
// Size (bytes): 3910


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00451720(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  float10 extraout_ST0;
  undefined4 uVar15;
  float fStack_60;
  float local_5c;
  float fStack_58;
  float fStack_54;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (DAT_007c56ac == '\0') {
    if (*(char *)(param_1 + 0x418) != '\0') {
      if ((*(int *)(param_1 + 0x4e8) != 0) &&
         (piVar11 = *(int **)(*(int *)(param_1 + 0x4e8) + 0x80), piVar11 != (int *)0x0)) {
        (**(code **)(*piVar11 + 0x58))(piVar11,0x10);
      }
      if ((*(int *)(param_1 + 0x4ec) != 0) &&
         (piVar11 = *(int **)(*(int *)(param_1 + 0x4ec) + 0x80), piVar11 != (int *)0x0)) {
        (**(code **)(*piVar11 + 0x58))(piVar11,0x10);
      }
      if ((*(int *)(param_1 + 0x4f0) != 0) &&
         (piVar11 = *(int **)(*(int *)(param_1 + 0x4f0) + 0x80), piVar11 != (int *)0x0)) {
        (**(code **)(*piVar11 + 0x58))(piVar11,0x10);
      }
      if ((*(int *)(param_1 + 0x4f4) != 0) &&
         (piVar11 = *(int **)(*(int *)(param_1 + 0x4f4) + 0x80), piVar11 != (int *)0x0)) {
        (**(code **)(*piVar11 + 0x58))(piVar11,0x10);
      }
      *(undefined1 *)(param_1 + 0x418) = 0;
    }
  }
  else if (*(char *)(param_1 + 0x418) == '\0') {
    if ((*(int *)(param_1 + 0x4e8) != 0) &&
       (piVar11 = *(int **)(*(int *)(param_1 + 0x4e8) + 0x80), piVar11 != (int *)0x0)) {
      (**(code **)(*piVar11 + 0x58))(piVar11,0x20);
    }
    if ((*(int *)(param_1 + 0x4ec) != 0) &&
       (piVar11 = *(int **)(*(int *)(param_1 + 0x4ec) + 0x80), piVar11 != (int *)0x0)) {
      (**(code **)(*piVar11 + 0x58))(piVar11,0x20);
    }
    if ((*(int *)(param_1 + 0x4f0) != 0) &&
       (piVar11 = *(int **)(*(int *)(param_1 + 0x4f0) + 0x80), piVar11 != (int *)0x0)) {
      (**(code **)(*piVar11 + 0x58))(piVar11,0x20);
    }
    if ((*(int *)(param_1 + 0x4f4) != 0) &&
       (piVar11 = *(int **)(*(int *)(param_1 + 0x4f4) + 0x80), piVar11 != (int *)0x0)) {
      (**(code **)(*piVar11 + 0x58))(piVar11,0x20);
    }
    *(undefined1 *)(param_1 + 0x418) = 1;
  }
  fVar5 = _DAT_0059e7e8;
  if ((*(int *)(DAT_007c54e0 + 0x95c) == 0) || (*(char *)(DAT_007c54e0 + 0x99c) == '\0')) {
    if ((*(int *)(DAT_007c54e0 + 0x834) == 0) || (*(char *)(DAT_007c54e0 + 0x874) == '\0')) {
      local_5c = 0.0;
    }
    else {
      local_5c = ABS(*(float *)(DAT_007c54e0 + 0x35bc));
    }
  }
  else {
    local_5c = ABS(*(float *)(DAT_007c54e0 + 0x36b4));
  }
  fStack_54 = ABS(*(float *)(DAT_007c54e0 + 0x37ac));
  if (fStack_54 < ABS(*(float *)(DAT_007c54e0 + 0x38a4))) {
    fStack_54 = ABS(*(float *)(DAT_007c54e0 + 0x38a4));
  }
  *(undefined4 *)(param_1 + 0x4d0) = 0;
  *(undefined4 *)(param_1 + 0x4d8) = 0;
  *(undefined4 *)(param_1 + 0x4e0) = 0;
  fStack_58 = 0.0;
  if (((DAT_007c54e8 == DAT_007c54e0) && (*(int *)(DAT_007c54e8 + 13000) == 0)) &&
     ((*(char *)(DAT_007c54e8 + 0x344c) == '\0' || (DAT_007ce7a8 == 0)))) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  iVar13 = 0;
  do {
    iVar3 = *(int *)(iVar13 * 0xf8 + 0x3674 + DAT_007c54e0);
    if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x54), iVar3 != 0)) {
      *(int *)(param_1 + 0x4e0) = *(int *)(param_1 + 0x4e0) + *(int *)(iVar3 + 0x30);
      switch(*(undefined4 *)
              (*(int *)(*(int *)(iVar13 * 0xf8 + 0x3674 + DAT_007c54e0) + 0x54) + 0x30)) {
      case 6:
      case 7:
        if ((iVar13 == 1) || (iVar13 == 0)) {
          fVar5 = fVar5 + _DAT_0059e8c8;
        }
        break;
      case 9:
      case 10:
        *(undefined4 *)(param_1 + 0x4d8) = 1;
        break;
      case 0xb:
        *(undefined4 *)(param_1 + 0x4d0) = 1;
        switch(iVar13) {
        case 0:
          fStack_58 = fStack_58 + _DAT_0059e43c;
          break;
        case 1:
          fStack_58 = fStack_58 - _DAT_0059e43c;
          break;
        case 2:
          fStack_58 = fStack_58 + _DAT_0059e7f8;
          break;
        case 3:
          fStack_58 = fStack_58 - _DAT_0059e7f8;
        }
      }
    }
    iVar13 = iVar13 + 1;
  } while (iVar13 < 4);
  if ((bVar7) && (fStack_58 = 0.0, DAT_007d1358 == '\0')) {
    *(undefined4 *)(param_1 + 0x4d0) = 0;
    *(undefined4 *)(param_1 + 0x4d8) = 0;
  }
  fVar5 = _DAT_007d21ac * fVar5;
  iStack_44 = 0;
  iVar13 = 0;
  do {
    fVar1 = DAT_0059e440;
    iVar3 = iStack_44 * 0x68 + param_1;
    if ((*(char *)(iVar3 + 4) == '\0') || (piVar11 = *(int **)(iVar3 + 100), piVar11 == (int *)0x0))
    goto switchD_00451a5a_caseD_1;
    switch(iStack_44) {
    case 0:
      bVar8 = false;
      if ((_DAT_007d2164 == DAT_0059e440) || (_DAT_007d2140 == DAT_0059e440)) {
LAB_00451d04:
        fStack_60 = 0.0;
      }
      else {
        if (bVar7) {
          if (DAT_007d1358 == '\0') goto LAB_00451d04;
          fVar1 = *(float *)(DAT_007c54e0 + 0x3580);
          bVar4 = fVar1 < DAT_0059e440;
          if (bVar4) {
            fVar1 = fVar1 * _DAT_0059e670;
          }
          fVar1 = SQRT(fVar1);
          if (bVar4) {
            fVar1 = fVar1 * _DAT_0059e670;
          }
          if (_DAT_007cc130 <= DAT_0059e440) {
            fVar2 = _DAT_007cc15c * _DAT_0059e450 + _DAT_0059e450;
          }
          else {
            fVar2 = (_DAT_0059e43c - _DAT_007cc130) * _DAT_0059e450;
          }
          fStack_60 = (fVar2 - (fVar1 + _DAT_0059e43c) * _DAT_0059e450) * _DAT_0059ef74;
          if (_DAT_0059ef70 <= fStack_60) {
            if (_DAT_0059ef6c < fStack_60) {
              fStack_60 = 5000.0;
            }
          }
          else {
            fStack_60 = -5000.0;
          }
          if (_DAT_007d2164 < DAT_0059e440) {
            fVar14 = (float10)fStack_60 * (float10)_DAT_0059e670;
            goto LAB_00451cc7;
          }
        }
        else {
          fVar14 = (float10)DAT_0059e440;
          if ((*(int *)(DAT_007c54e8 + 0x834) != 0) && (*(char *)(DAT_007c54e8 + 0x874) != '\0')) {
            fVar14 = (float10)DAT_007c77f8;
          }
          if ((*(int *)(DAT_007c54e8 + 0x95c) != 0) && (*(char *)(DAT_007c54e8 + 0x99c) != '\0')) {
            fVar14 = fVar14 + (float10)DAT_007c7c5c;
          }
          fVar2 = (float)(((float10)_DAT_0059e43c - (float10)fVar5) +
                         fVar14 * (float10)_DAT_0059e450 * (float10)fVar5);
          fVar6 = ((float)_DAT_007c8a80 / _DAT_007d2164) * fVar2;
          fStack_60 = fVar6;
          if (fVar6 <= DAT_0059e440) {
            fStack_60 = fVar6 * _DAT_0059e670;
          }
          if (_DAT_007d2140 == _DAT_0059e450) {
            fVar14 = SQRT((float10)fStack_60);
          }
          else if (_DAT_007d2140 == _DAT_0059e800) {
            fVar14 = (float10)fStack_60 * (float10)fStack_60;
          }
          else {
            fVar14 = (float10)FUN_005881f0();
          }
          if (fVar1 < fVar6) {
            fVar14 = fVar14 * (float10)_DAT_0059e670;
          }
          fVar14 = ((float10)_DAT_0059e43c - (float10)_DAT_007d211c) * (float10)_DAT_007cd1f8 +
                   (float10)_DAT_007d2188 * (float10)fVar2 * fVar14 * (float10)_DAT_007d211c;
          _DAT_007cd1f8 = (float)fVar14;
          if ((float10)_DAT_0059e670 <= fVar14) {
            if ((float10)_DAT_0059e43c < fVar14) {
              fVar14 = (float10)_DAT_0059e43c;
            }
          }
          else {
            fVar14 = (float10)_DAT_0059e670;
          }
          fVar14 = fVar14 * (float10)_DAT_0059ee68;
LAB_00451cc7:
          fStack_60 = (float)fVar14;
        }
        iVar13 = __ftol();
        iVar13 = *(int *)(param_1 + 0x420) - iVar13;
        iVar10 = __ftol();
        if ((iVar10 * 10000 < iVar13) || (iVar13 < iVar10 * -10000)) {
          bVar8 = true;
        }
      }
      if ((((local_5c == DAT_0059e440) || (_DAT_007d208c == DAT_0059e440)) || (DAT_007d1ffc < 4)) ||
         (((bVar7 && (DAT_007d1358 == '\0')) ||
          ((iVar10 = __ftol(), iVar10 < 1 || (2000000 < iVar10)))))) {
        iVar10 = 1000000;
LAB_00451da2:
        iVar13 = 0;
      }
      else {
        iVar13 = __ftol();
        if (iVar13 < 0) goto LAB_00451da2;
        if (10000 < iVar13) {
          iVar13 = 10000;
        }
      }
      iVar9 = __ftol();
      iVar12 = *(int *)(param_1 + 0x428) - iVar10;
      if ((((iVar9 * 10000 < iVar12) || (iVar12 < iVar9 * -10000)) ||
          ((iVar13 == 0 && (*(int *)(param_1 + 0x41c) != 0)))) ||
         ((bVar8 || (_DAT_007d21d0 == DAT_0059e440)))) {
        if (*(char *)(param_1 + 0x418) != '\0') goto LAB_00451e0f;
        *(int *)(param_1 + 0x41c) = iVar13;
        *(int *)(param_1 + 0x428) = iVar10;
        uVar15 = __ftol();
        *(undefined4 *)(param_1 + 0x420) = uVar15;
      }
      else {
        if (*(char *)(param_1 + 0x418) == '\0') break;
LAB_00451e0f:
        *(undefined4 *)(param_1 + 0x41c) = 0;
        *(undefined4 *)(param_1 + 0x428) = 1;
        *(undefined4 *)(param_1 + 0x420) = 0;
      }
      goto LAB_00452166;
    case 5:
      if (((*(float *)(DAT_007c54e0 + 0x39a0) <= DAT_0059e440) ||
          (*(char *)(param_1 + 0x418) != '\0')) ||
         ((((*(float *)(DAT_007c54e0 + 0x3584) != DAT_0059e440 &&
            (((fStack_54 != DAT_0059e440 && (*(int *)(param_1 + 0x2d4) != 0)) &&
             (*(int *)(param_1 + 0x510) == *(int *)(param_1 + 0x514))))) &&
           (*(int *)(param_1 + 0x4f0) == *(int *)(param_1 + 0x4f4))) ||
          ((bVar7 && (DAT_007d1358 != '\x01')))))) {
        iVar13 = 0;
        iStack_48 = 1000000;
        fStack_60 = 0.0;
      }
      else if (DAT_007d1fd8 == 3) {
        iStack_48 = __ftol();
        if (iStack_48 < 0) {
          iStack_48 = 0;
        }
        iVar13 = 0;
        fStack_60 = (float)iStack_48 * _DAT_007d22a8;
        if (_DAT_0059e958 <= fStack_60) {
          if (_DAT_0059ee68 < fStack_60) {
            fStack_60 = 10000.0;
          }
        }
        else {
          fStack_60 = -10000.0;
        }
      }
      else {
        fStack_60 = 0.0;
        iStack_48 = __ftol();
        if (iStack_48 < 0) {
          iStack_48 = -iStack_48;
        }
        if ((iStack_48 == 0) || (1000000 < iStack_48)) {
          iVar13 = 0;
          iStack_48 = 1000000;
        }
        else {
          iVar13 = __ftol();
          if (iVar13 < 0) {
            iVar13 = 0;
          }
          else if (10000 < iVar13) {
            iVar13 = 10000;
          }
        }
      }
      if ((_DAT_007d2314 != DAT_0059e440) && (*(char *)(param_1 + 0x418) == '\0')) {
        iVar10 = __ftol();
        iVar9 = *(int *)(param_1 + 0x498) - iStack_48;
        if (((iVar9 <= iVar10 * 10000) && (iVar10 * -10000 <= iVar9)) &&
           ((iVar13 != 0 || (*(int *)(param_1 + 0x48c) == 0)))) break;
      }
      *(int *)(param_1 + 0x498) = iStack_48;
      *(int *)(param_1 + 0x48c) = iVar13;
      uVar15 = __ftol();
      *(undefined4 *)(param_1 + 0x490) = uVar15;
      goto LAB_00452166;
    case 6:
      if ((((*(float *)(DAT_007c54e0 + 0x3584) <= DAT_0059e440) || (fStack_54 == DAT_0059e440)) ||
          (*(char *)(param_1 + 0x418) != '\0')) || ((bVar7 && (DAT_007d1358 != '\x01')))) {
LAB_004520f7:
        iVar10 = 1000000;
LAB_004520fc:
        iVar13 = 0;
      }
      else {
        iVar10 = __ftol();
        if (iVar10 < 0) {
          iVar10 = -iVar10;
        }
        if ((iVar10 == 0) || (2000000 < iVar10)) goto LAB_004520f7;
        iVar13 = __ftol();
        if (iVar13 < 0) goto LAB_004520fc;
        if (10000 < iVar13) {
          iVar13 = 10000;
        }
      }
      if ((_DAT_007d23c8 != DAT_0059e440) && (*(char *)(param_1 + 0x418) == '\0')) {
        iVar9 = __ftol();
        iVar12 = *(int *)(param_1 + 0x4a8) - iVar10;
        if (((iVar12 <= iVar9 * 10000) && (iVar9 * -10000 <= iVar12)) &&
           ((iVar13 != 0 || (*(int *)(param_1 + 0x49c) == 0)))) break;
      }
      *(int *)(param_1 + 0x4a8) = iVar10;
      *(int *)(param_1 + 0x49c) = iVar13;
LAB_00452166:
      (**(code **)(**(int **)(iVar3 + 100) + 0x18))(*(int **)(iVar3 + 100),iVar3 + 8,0x40000100);
      break;
    case 7:
      if ((!bVar7) && (*(char *)(param_1 + 0x418) == '\0')) {
        if (DAT_007d1fd8 == 3) {
          iVar10 = *(int *)(param_1 + 0x4e4);
          if ((*(int *)(param_1 + 0x4e0) != iVar10) &&
             (*(int *)(param_1 + 0x4e4) = *(int *)(param_1 + 0x4e0), iVar10 != 0)) {
            *(double *)(param_1 + 0x560) =
                 (double)(local_5c * _DAT_0059ef64 * _DAT_0059ef60 +
                         (float)*(double *)(param_1 + 0x560));
          }
        }
        if (((*(double *)(param_1 + 0x570) != _DAT_0059e430) ||
            (*(double *)(param_1 + 0x560) != _DAT_0059e430)) ||
           (*(double *)(param_1 + 0x568) != _DAT_0059e430)) {
          uStack_28 = 0;
          if ((DAT_007d1fd8 == 3) && (*(int *)(param_1 + 0x4e8) != 0)) {
            uStack_28 = 1;
            uStack_24 = 1;
          }
          else if (((*(int *)(param_1 + 0x4e8) == 0) ||
                   ((*(int *)(param_1 + 0x4f4) == 0 || (DAT_007d2068 != 0)))) ||
                  (*(int *)(param_1 + 0x4f4) != *(int *)(param_1 + 0x4e8))) {
            uStack_28 = 1;
          }
          else {
            uStack_28 = __ftol();
            uStack_24 = __ftol();
          }
          iVar10 = __ftol();
          *(int *)(param_1 + 0x4ac) = iVar10;
          if (iVar10 < -10000) {
            *(undefined4 *)(param_1 + 0x4ac) = 0xffffd8f0;
          }
          else if (10000 < iVar10) {
            *(undefined4 *)(param_1 + 0x4ac) = 10000;
          }
          *(undefined4 **)(iVar3 + 0x2c) = &uStack_28;
          (**(code **)(**(int **)(iVar3 + 100) + 0x18))(*(int **)(iVar3 + 100),iVar3 + 8,0x40000140)
          ;
          (**(code **)(**(int **)(iVar3 + 100) + 0x1c))(*(int **)(iVar3 + 100),1,0);
        }
      }
      break;
    case 8:
      if (local_5c == DAT_0059e440) {
LAB_004525c1:
        if (DAT_007d1fd8 == 3) {
LAB_0045263d:
          if ((*(int *)(param_1 + 0x4d0) != 0) || (*(int *)(param_1 + 0x4d8) != 0)) break;
          if (*(int *)(param_1 + 0x4d4) == 0) {
            iVar10 = *(int *)(param_1 + 0x4dc);
            goto joined_r0x0045265f;
          }
LAB_004525dc:
          *(undefined4 *)(param_1 + 0x4d0) = 0;
          *(undefined4 *)(param_1 + 0x4d4) = 0;
          *(undefined4 *)(param_1 + 0x4d8) = 0;
          *(undefined4 *)(param_1 + 0x4dc) = 0;
          (**(code **)(**(int **)(iVar3 + 100) + 0x20))(*(int **)(iVar3 + 100));
        }
        else {
LAB_004525c6:
          if (*(int *)(param_1 + 0x4d0) == 0) {
            iVar10 = *(int *)(param_1 + 0x4d4);
joined_r0x0045265f:
            if (iVar10 != 0) goto LAB_004525dc;
          }
        }
      }
      else {
        iVar10 = *(int *)(param_1 + 0x4d0);
        if (iVar10 == 0) {
          if (DAT_007d1fd8 == 3) {
            if (*(int *)(param_1 + 0x4d8) != 0) goto LAB_0045239e;
            goto LAB_0045263d;
          }
          goto LAB_004525c6;
        }
LAB_0045239e:
        if ((bVar7) && (DAT_007d1358 != '\x01')) goto LAB_004525c1;
        if (DAT_007d1fd8 == 3) {
          iVar9 = __ftol();
          if (iVar10 == 0) {
            if (*(int *)(param_1 + 0x4d8) != 0) {
              fStack_60 = (float)((float10)_DAT_007d23ec * extraout_ST0 * (float10)_DAT_0059ef5c);
              iVar13 = __ftol();
              iVar9 = __ftol();
            }
          }
          else {
            iVar13 = 0;
            fStack_60 = (float)((float10)_DAT_007d23ec * extraout_ST0 * (float10)_DAT_0059ee68);
          }
LAB_004523ef:
          if (fStack_60 <= _DAT_0059ee68) {
            if (fStack_60 < _DAT_0059e958) {
              fStack_60 = -10000.0;
            }
          }
          else {
            fStack_60 = 10000.0;
          }
        }
        else {
          iVar9 = __ftol();
          if (iVar9 < 0x1e8481) {
            iVar13 = __ftol();
            fStack_60 = (float)*(int *)(param_1 + 0x4b0) * _DAT_007d2458 * fStack_58;
            if (iVar13 < 0x2711) {
              if (iVar13 < 0) {
                iVar13 = 0;
              }
            }
            else {
              iVar13 = 10000;
            }
            goto LAB_004523ef;
          }
          iVar13 = 0;
          iVar9 = 1000000;
          fStack_60 = 0.0;
        }
        if ((*(int *)(param_1 + 0x4d4) == 0) && (*(int *)(param_1 + 0x4dc) == 0)) {
          uVar15 = 0x20000100;
LAB_0045259d:
          (**(code **)(*piVar11 + 0x18))(piVar11,iVar3 + 8,uVar15);
        }
        else {
          if (_DAT_007d247c == DAT_0059e440) {
LAB_00452554:
            if (*(char *)(param_1 + 0x418) == '\0') {
              *(int *)(param_1 + 0x4b0) = iVar13;
              uVar15 = __ftol();
              *(undefined4 *)(param_1 + 0x4b4) = uVar15;
              *(int *)(param_1 + 0x4bc) = iVar9;
            }
            else {
LAB_0045255e:
              *(undefined4 *)(param_1 + 0x4b0) = 0;
              *(undefined4 *)(param_1 + 0x4b4) = 0;
              *(undefined4 *)(param_1 + 0x4bc) = 1000000;
            }
            piVar11 = *(int **)(iVar3 + 100);
            uVar15 = 0x40000100;
            goto LAB_0045259d;
          }
          if (*(char *)(param_1 + 0x418) != '\0') goto LAB_0045255e;
          iVar10 = __ftol();
          iVar12 = *(int *)(param_1 + 0x4bc) - iVar9;
          if (((iVar10 * 10000 < iVar12) || (iVar12 < iVar10 * -10000)) ||
             ((iVar13 == 0 && (*(int *)(param_1 + 0x4b0) != 0)))) goto LAB_00452554;
        }
        *(undefined4 *)(param_1 + 0x4d4) = *(undefined4 *)(param_1 + 0x4d0);
        *(undefined4 *)(param_1 + 0x4dc) = *(undefined4 *)(param_1 + 0x4d8);
      }
    }
switchD_00451a5a_caseD_1:
    iStack_44 = iStack_44 + 1;
    if (9 < iStack_44) {
      *(undefined4 *)(param_1 + 0x560) = 0;
      *(undefined4 *)(param_1 + 0x564) = 0;
      *(undefined4 *)(param_1 + 0x568) = 0;
      *(undefined4 *)(param_1 + 0x56c) = 0;
      *(undefined4 *)(param_1 + 0x570) = 0;
      *(undefined4 *)(param_1 + 0x574) = 0;
      return;
    }
  } while( true );
}


