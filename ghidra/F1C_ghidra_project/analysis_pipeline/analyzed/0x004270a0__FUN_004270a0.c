// Function: FUN_004270a0 @ 004270a0
// Size (bytes): 9165


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004270a0(int *param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  bool bVar4;
  float fVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  float fVar14;
  int iVar15;
  int iVar16;
  ushort uVar17;
  byte bVar18;
  float10 fVar19;
  float10 fVar20;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  int local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  int local_14 [5];
  
  iVar10 = param_1[0x10d5];
  local_60 = *(float *)(iVar10 + 0x54);
  fVar14 = *(float *)(iVar10 + 0x50);
  iVar9 = param_1[0x115b];
  bVar8 = false;
  bVar7 = false;
  bVar6 = false;
  piVar13 = param_1 + 0x10d6;
  iVar15 = 5;
  do {
    iVar12 = *piVar13;
    if (*(float *)(iVar12 + 0x54) <= local_60) {
      local_60 = *(float *)(iVar12 + 0x54);
    }
    if (*(float *)(iVar12 + 0x50) <= fVar14) {
      fVar14 = *(float *)(iVar12 + 0x50);
    }
    piVar13 = piVar13 + 1;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  local_70 = (float)param_1[0x1105];
  local_6c = (float)param_1[0x1106];
  local_58 = (local_60 + fVar14) * _DAT_0059e450;
  local_48 = 1.0;
  fVar14 = fVar14 + (float)param_1[0x1107];
  if (fVar14 < local_58) {
    if (fVar14 < DAT_0059e440) {
      fVar14 = DAT_0059e440;
    }
    local_48 = fVar14 / local_58;
  }
  local_60 = local_60 - (float)param_1[0x1107];
  if (local_58 <= local_60) {
    local_58 = 1.0;
  }
  else {
    if (local_60 < DAT_0059e440) {
      local_60 = DAT_0059e440;
    }
    local_58 = local_60 / local_58;
  }
  fVar14 = (float)param_1[0x1108];
  param_1[0x1103] = (int)fVar14;
  if (local_70 < local_6c) {
    local_70 = _DAT_0059e800 + fVar14;
    local_6c = fVar14 - _DAT_0059e800;
  }
  if (fVar14 <= local_70) {
    if (fVar14 < local_6c) {
      param_1[0x1103] = (int)local_6c;
    }
  }
  else {
    param_1[0x1103] = (int)local_70;
  }
  if (*(char *)((int)param_1 + 0x4579) != '\0') {
    if (_DAT_0059e964 <= (float)param_1[0x1103] - (float)param_1[0x1108]) {
      if (_DAT_0059e964 <= (float)param_1[0x1108] - (float)param_1[0x1103]) {
        param_1[0x1103] = param_1[0x1108];
      }
      else {
        param_1[0x1103] = (int)((float)param_1[0x1103] - _DAT_0059e7e8);
      }
    }
    else {
      param_1[0x1103] = (int)((float)param_1[0x1103] + _DAT_0059e7e8);
    }
  }
  if ((float)_DAT_008afea0 < _DAT_008acf90 + _DAT_0059e960) {
    if (DAT_0059e440 <= (float)param_1[0x1107]) {
      fVar14 = *(float *)(param_1[param_1[0x111a] + 0x10d5] + 0x54) /
               (*(float *)(iVar10 + 0x54) + _DAT_0059e43c);
    }
    else {
      fVar14 = *(float *)(param_1[param_1[0x111a] + 0x10d5] + 0x50) /
               (*(float *)(iVar10 + 0x50) + _DAT_0059e43c);
    }
    if (_DAT_0059e43c < fVar14) {
      fVar14 = _DAT_0059e43c;
    }
    param_1[0x1103] = (int)(fVar14 * (float)param_1[0x1107]);
  }
  if ((float)_DAT_008afea0 < _DAT_008acf90 + _DAT_0059e8e4) {
    if (param_1[0x113f] == 0) {
      param_1[0x1103] = (int)((float)param_1[0x110a] - _DAT_0059e43c);
    }
    else if (param_1[0x113f] == 2) {
      param_1[0x1103] = (int)((float)param_1[0x110a] + _DAT_0059e43c);
    }
    else {
      param_1[0x1103] = param_1[0x110a];
    }
  }
  local_28 = 99999.9;
  local_14[0] = -1;
  local_24 = 99999.9;
  local_14[1] = -1;
  local_20 = 99999.9;
  local_14[2] = -1;
  fVar14 = -NAN;
  local_1c = 99999.9;
  *(undefined1 *)((int)param_1 + 0x4579) = 0;
  param_1[0x115c] = 0;
  param_1[0x115d] = 0;
  param_1[0x1157] = 0;
  param_1[0x1155] = 0x3f800000;
  *(undefined1 *)(param_1 + 0x115b) = 0;
  local_18 = 99999.9;
  local_14[3] = 0xffffffff;
  local_14[4] = -1;
  local_4c = 0.0;
  piVar13 = param_1 + 0x105d;
  do {
    if ((float)piVar13[0xd] < _DAT_0059e95c) {
      iVar10 = FUN_00403aa0(*piVar13 + 0x34e0,*(undefined4 *)(*piVar13 + 0x4354),param_1[0x1154],0);
      piVar13[0xe] = iVar10;
      if (((*(int *)(iVar10 + 300) != 1) || (*(int *)(param_1[0x10d5] + 300) != 0)) ||
         ((iVar15 = *(int *)(iVar10 + 0x114), iVar15 != 0 && (iVar15 != *(int *)(iVar15 + 0x110)))))
      {
        if ((*(int *)(iVar10 + 300) == 0) && (*(int *)(param_1[0x10d5] + 300) == 1)) {
          iVar10 = FUN_004039c0(*piVar13 + 0x34e0,param_1[0x10d5]);
          piVar13[0xe] = iVar10;
        }
        FUN_00423ca0(param_1[0xd3e],param_1[0xd3f],param_1[0xd40],param_1[0x1110]);
        FUN_00423db0(param_1[0x1123],param_1[0x1124],param_1[0x1125],param_1[0xd38],param_1[0xd39],
                     param_1[0xd3a]);
        FUN_00423b10(iVar10,0,1);
        FUN_00423b10(param_1[param_1[0x111a] + 0x10d5],0,0);
        iVar15 = local_14[2];
        fVar5 = (float)param_1[0x1110] - (float)piVar13[0xc];
        if ((float)param_1[0x1110] - (float)piVar13[0xc] < _DAT_0059e444) {
          fVar5 = _DAT_0059e444;
        }
        fVar2 = (float)piVar13[3] - _DAT_0059e7ec;
        param_1[piVar13[0x10] * 7 + 0x10b2] = -1;
        fVar2 = fVar2 / fVar5;
        iVar12 = 0;
        piVar11 = param_1 + 0x10d5;
        do {
          if (*piVar11 == iVar10) {
            param_1[piVar13[0x10] * 7 + 0x10b2] = iVar12;
            if (((float)piVar13[0xc] < (float)param_1[iVar12 + 0x10e9]) &&
               (_DAT_0059e84c < (float)param_1[0x110e])) {
              fVar2 = ((float)param_1[iVar12 + 0x10e9] - (float)piVar13[0xc]) + _DAT_0059e7ec;
              if (fVar2 < _DAT_0059e444) {
                fVar2 = _DAT_0059e444;
              }
              fVar2 = ((float)piVar13[3] - _DAT_0059e7ec) / fVar2;
            }
            break;
          }
          iVar12 = iVar12 + 1;
          piVar11 = piVar11 + 1;
        } while (iVar12 < 0x14);
        fVar5 = _DAT_0059e958;
        if (fVar2 < DAT_0059e440) {
          fVar2 = DAT_0059e440;
        }
        if ((*(int *)(*piVar13 + 13000) == 0) ||
           (((float)piVar13[0xc] < _DAT_0059e450 && (_DAT_0059e43c < (float)param_1[0x1110])))) {
          param_1[piVar13[0x10] * 7 + 0x10b6] = -0x40800000;
          fVar2 = fVar5;
        }
        if (local_28 <= fVar2) {
          if (local_24 <= fVar2) {
            if (local_20 <= fVar2) {
              if (local_1c <= fVar2) {
                if (fVar2 < local_18) {
                  local_14[4] = (int)local_4c;
                  local_18 = fVar2;
                }
              }
              else {
                local_14[4] = (int)fVar14;
                local_18 = local_1c;
                fVar14 = local_4c;
                local_1c = fVar2;
              }
            }
            else {
              local_14[4] = (int)fVar14;
              local_18 = local_1c;
              local_1c = local_20;
              local_14[2] = (int)local_4c;
              fVar14 = (float)iVar15;
              local_20 = fVar2;
            }
          }
          else {
            local_18 = local_1c;
            local_1c = local_20;
            local_14[4] = (int)fVar14;
            local_14[2] = local_14[1];
            local_20 = local_24;
            local_14[1] = (int)local_4c;
            fVar14 = (float)iVar15;
            local_24 = fVar2;
          }
        }
        else {
          local_18 = local_1c;
          local_14[4] = (int)fVar14;
          local_1c = local_20;
          local_14[2] = local_14[1];
          local_20 = local_24;
          local_14[1] = local_14[0];
          local_24 = local_28;
          local_14[0] = (int)local_4c;
          fVar14 = (float)iVar15;
          local_28 = fVar2;
        }
      }
    }
    local_4c = (float)((int)local_4c + 1);
    piVar13 = piVar13 + 0x11;
  } while ((int)local_4c < 5);
  local_14[3] = (int)fVar14;
  local_44 = 0;
  do {
    iVar10 = local_14[local_44];
    bVar4 = false;
    if ((iVar10 != -1) && ((float)param_1[iVar10 * 0x11 + 0x106a] < _DAT_0059e95c)) {
      iVar15 = param_1[iVar10 * 0x11 + 0x105d];
      if (*(int *)(iVar15 + 13000) == 1) {
        local_4c = (_DAT_0059e43c - (float)param_1[0x113e]) + _DAT_0059e478;
      }
      else {
        local_58 = 1.0;
        local_48 = 1.0;
        local_4c = 4.0;
      }
      fVar14 = local_4c - _DAT_0059e43c;
      iVar12 = param_1[iVar10 * 0x11 + 0x106b];
      fVar5 = *(float *)(param_1[0x10d5] + 0xb8) - *(float *)(iVar12 + 0xb8);
      if ((float)_DAT_0059e890 <= ABS(fVar5)) {
        if (DAT_0059e440 <= fVar5) {
          fVar5 = fVar5 - _DAT_0059e888;
        }
        else {
          fVar5 = fVar5 + _DAT_0059e888;
        }
      }
      if (ABS(fVar5) <= (float)_DAT_0059e950) {
        local_64 = *(float *)(iVar12 + 0x48) - (float)param_1[0x1114];
        if (DAT_005ea3fc * _DAT_0059e450 <= ABS(local_64)) {
          if (DAT_0059e440 <= local_64) {
            local_64 = local_64 - DAT_005ea3fc;
          }
          else {
            local_64 = DAT_005ea3fc + local_64;
          }
        }
        if ((DAT_0059e440 <= local_64) &&
           (local_64 = local_64 - (float)param_1[0x1129], local_64 < DAT_0059e440)) {
          local_64 = 0.0;
        }
        fVar5 = (_DAT_0059e94c - local_64) * (float)param_1[0x1110] * _DAT_0059e948;
        if (fVar5 < _DAT_0059e43c) {
          fVar5 = _DAT_0059e43c;
        }
        local_5c = (float)param_1[0x1110] * _DAT_0059e868 +
                   (_DAT_0059e800 - (float)param_1[0x113e]) * _DAT_0059e7ec +
                   (float)*(int *)(iVar15 + 0x455c) + (float)*(int *)(iVar15 + 0x455c) +
                   (_DAT_0059e43c -
                   ((float)param_1[iVar10 * 0x11 + 0x1069] - (float)param_1[0x1110]) * _DAT_0059e464
                   ) * (_DAT_0059e800 - (float)param_1[0x113e]) * fVar5;
        fVar5 = _DAT_0059e8ec - (float)param_1[0x113e] * _DAT_0059e5fc;
        if (local_5c < fVar5) {
          local_5c = fVar5;
        }
        local_74 = *(float *)(iVar12 + 0x20) *
                   (*(float *)(iVar15 + 0x34e0) - *(float *)(iVar12 + 0x94)) +
                   *(float *)(iVar12 + 0x28) *
                   (*(float *)(iVar15 + 0x34e8) - *(float *)(iVar12 + 0x9c));
        if (DAT_0059e440 <= local_74) {
          fVar5 = (local_74 / *(float *)(iVar12 + 0x54)) *
                  *(float *)(*(int *)(iVar12 + 0x110) + 0x54);
        }
        else {
          fVar5 = (local_74 / *(float *)(iVar12 + 0x50)) *
                  *(float *)(*(int *)(iVar12 + 0x110) + 0x50);
        }
        if (ABS(fVar5 - (float)param_1[0x110a]) < ABS(local_74 - (float)param_1[0x110a])) {
          local_74 = fVar5;
        }
        fVar5 = (float)param_1[iVar10 * 0x11 + 0x1061] * _DAT_0059e7f8;
        if (DAT_0059e440 <= local_74) {
          if (DAT_0059e440 < fVar5) goto LAB_004279ff;
        }
        else if (fVar5 < DAT_0059e440) {
LAB_004279ff:
          fVar5 = DAT_0059e440;
        }
        fVar5 = fVar5 + local_74;
        local_50 = fVar5 - (float)param_1[0x110a];
        if (param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] != 5) {
          local_5c = local_5c + _DAT_0059e800;
        }
        fVar2 = local_5c * _DAT_0059e944;
        if (local_64 <= fVar2) {
          if (DAT_0059e440 <= fVar5) {
            if (fVar5 <= *(float *)(iVar12 + 0x54) + _DAT_0059e8a4) goto LAB_00427aa7;
          }
          else if (-(*(float *)(iVar12 + 0x50) + _DAT_0059e8a4) <= fVar5) {
LAB_00427aa7:
            if ((((DAT_0059e440 <= local_64) && (param_1[0x1151] == 0)) &&
                (*(int *)(iVar15 + 0x4510) < 4)) &&
               (((float)param_1[0x1110] * _DAT_0059e7fc < -(float)param_1[iVar10 * 0x11 + 0x1063] &&
                (_DAT_0059e7ec < -(float)param_1[iVar10 * 0x11 + 0x1069])))) {
              local_54 = (float)param_1[0x1110] * _DAT_0059e8b4;
              local_60 = (float)param_1[0x1110] * _DAT_0059e4e8;
              fVar1 = (float)param_1[0x1110] * _DAT_0059e84c;
              if ((float)param_1[0x1110] * _DAT_0059e84c < _DAT_0059e7ec) {
                fVar1 = _DAT_0059e7ec;
              }
              if (local_54 < _DAT_0059e940) {
                local_54 = 6.0;
              }
              if (local_60 < _DAT_0059e864) {
                local_60 = 7.0;
              }
              if (_DAT_0059e5fc <= local_64) {
                if (fVar1 <= local_64) {
                  if (local_54 <= local_64) {
                    if (local_64 < local_60) {
                      FUN_0042a740(*(undefined4 *)(iVar15 + 0x4440));
                    }
                  }
                  else {
                    fVar1 = *(float *)(iVar15 + 0x4440);
LAB_00427bfc:
                    FUN_0042a740(fVar1 * _DAT_0059e824);
                  }
                }
                else {
                  fVar1 = *(float *)(iVar15 + 0x4440);
LAB_00427bc9:
                  FUN_0042a740(fVar1 * _DAT_0059e8cc);
                }
              }
              else if (DAT_0059e440 < (float)param_1[iVar10 * 0x11 + 0x1060]) {
                if ((float)param_1[iVar10 * 0x11 + 0x1060] < fVar1) {
                  fVar1 = (float)param_1[iVar10 * 0x11 + 0x1063] + (float)param_1[0x1110];
                  goto LAB_00427bc9;
                }
                if ((float)param_1[iVar10 * 0x11 + 0x1060] < local_54) {
                  fVar1 = (float)param_1[iVar10 * 0x11 + 0x1063] + (float)param_1[0x1110];
                  goto LAB_00427bfc;
                }
                if ((float)param_1[iVar10 * 0x11 + 0x1060] < local_60) {
                  FUN_0042a740((float)param_1[iVar10 * 0x11 + 0x1063] + (float)param_1[0x1110]);
                }
              }
            }
            if ((((float)param_1[0x113e] + _DAT_0059e43c) * _DAT_0059e8ec <=
                 (float)param_1[iVar10 * 0x11 + 0x1060]) ||
               (3 < *(int *)(param_1[iVar10 * 0x11 + 0x105d] + 0x455c))) {
              param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] =
                   (int)((float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] -
                        _DAT_0059e7ec);
              if ((float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] < DAT_0059e440) {
                param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] = 0;
              }
            }
            else {
              fVar1 = -(float)param_1[iVar10 * 0x11 + 0x1063];
              if (-(float)param_1[iVar10 * 0x11 + 0x1063] <= _DAT_0059e43c) {
                fVar1 = _DAT_0059e43c;
              }
              param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] =
                   (int)(fVar1 * (float)param_1[0x113e] +
                        (float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7]);
              if (_DAT_0059e93c < (float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7]) {
                param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] = 0x43e10000;
              }
              if ((param_1[0x1153] == 1) &&
                 (_DAT_0059e6a8 < (float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7])) {
                param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] = 0x437a0000;
              }
            }
            if (((DAT_0059e440 <= (float)param_1[iVar10 * 0x11 + 0x1060]) ||
                ((float)param_1[iVar10 * 0x11 + 0x1060] <= _DAT_0059e938)) || ((char)iVar9 != '\0'))
            {
              if ((_DAT_0059e46c <= (float)param_1[iVar10 * 0x11 + 0x1060]) ||
                 ((float)param_1[iVar10 * 0x11 + 0x1060] < DAT_0059e440)) {
                if (((float)param_1[iVar10 * 0x11 + 0x1060] < _DAT_0059e46c) ||
                   ((fVar2 <= local_64 || (local_64 < DAT_0059e440)))) {
                  param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] = 5;
                }
                else {
                  if (((float)param_1[iVar10 * 0x11 + 0x1069] < _DAT_0059e43c) &&
                     (_DAT_0059e8bc < (float)param_1[0x1110])) {
                    local_48 = 1.0;
                    local_58 = 1.0;
                    if (*(char *)(param_1[iVar10 * 0x11 + 0x105d] + 0x456c) == '\0') {
                      if (!bVar6) {
                        fVar2 = *(float *)(param_1[param_1[0x111a] + 0x10d5] + 0x38) - local_70;
                        if (_DAT_0059e7ec < fVar2) {
                          fVar2 = _DAT_0059e7ec;
                        }
                        fVar1 = DAT_0059e440;
                        if ((float)param_1[0x1110] <= _DAT_0059e8ec) {
                          fVar1 = (_DAT_0059e43c - (float)param_1[0x1110] * _DAT_0059e448) * fVar2;
                        }
                        local_70 = local_70 + fVar1;
                      }
                      if (!bVar7) {
                        fVar2 = -*(float *)(param_1[param_1[0x111a] + 0x10d5] + 0x34) - local_6c;
                        if (_DAT_0059e7ec < fVar2) {
                          fVar2 = _DAT_0059e7ec;
                        }
                        fVar1 = DAT_0059e440;
                        if ((float)param_1[0x1110] <= _DAT_0059e8ec) {
                          fVar1 = (_DAT_0059e43c - (float)param_1[0x1110] * _DAT_0059e448) * fVar2;
                        }
                        local_6c = local_6c + fVar1;
                      }
                      bVar4 = true;
                    }
                    *(undefined1 *)(param_1 + 0x115b) = 1;
                  }
                  if (_DAT_0059e8d8 < (float)param_1[iVar10 * 0x11 + 0x1060]) {
                    local_50 = (float)param_1[iVar10 * 0x11 + 0x1064] - (float)param_1[0x110a];
                  }
                  if (((param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] == 5) &&
                      (ABS(local_50) < (float)_DAT_0059e7e0)) &&
                     ((float)param_1[iVar10 * 0x11 + 0x1063] < _DAT_0059e7f0)) {
                    param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b6] = -0x40800000;
                  }
                  if (((char)param_1[0x1122] == '\0') ||
                     (iVar15 = param_1[iVar10 * 0x11 + 0x106d],
                     (float)param_1[0x1120] <= (float)param_1[iVar15 * 7 + 0x10b6])) {
                    iVar15 = param_1[iVar10 * 0x11 + 0x106d];
                    if ((float)param_1[iVar15 * 7 + 0x10b6] < DAT_0059e440) goto LAB_00428487;
                    iVar16 = param_1[(iVar15 + 0x263) * 7];
LAB_00428bea:
                    if ((iVar16 == 8) || (iVar16 == 7)) {
                      local_48 = 1.0;
                      local_58 = 1.0;
                    }
                    if (iVar16 == 4) {
                      local_48 = 1.0;
                      local_58 = 1.0;
                      FUN_0042a740((float)param_1[iVar10 * 0x11 + 0x1063] * _DAT_0059e8bc +
                                   (float)param_1[0x1110]);
                      iVar16 = 2;
LAB_00428cc6:
                      if (_DAT_0059e8d8 <= (float)param_1[iVar10 * 0x11 + 0x1060]) {
                        bVar18 = fVar5 - _DAT_0059e800 < (float)param_1[0x1107] |
                                 (byte)((ushort)((ushort)(NAN(fVar5 - _DAT_0059e800) ||
                                                         NAN((float)param_1[0x1107])) << 10) >> 8);
                      }
                      else {
                        bVar18 = (float)param_1[iVar10 * 0x11 + 0x105e] < _DAT_0059e800 |
                                 (byte)((ushort)((ushort)(NAN((float)param_1[iVar10 * 0x11 + 0x105e]
                                                             ) || NAN(_DAT_0059e800)) << 10) >> 8);
                      }
                      if ((POPCOUNT(bVar18) & 1U) != 0) {
                        iVar16 = 7;
                      }
                    }
                    else {
                      if (iVar16 != 3) goto LAB_00428bb6;
                      local_48 = 1.0;
                      local_58 = 1.0;
                      FUN_0042a740((float)param_1[iVar10 * 0x11 + 0x1063] * _DAT_0059e8bc +
                                   (float)param_1[0x1110]);
                      iVar16 = 1;
LAB_00428c82:
                      if (_DAT_0059e8d8 <= (float)param_1[iVar10 * 0x11 + 0x1060]) {
                        uVar17 = (ushort)(fVar5 + _DAT_0059e800 < (float)param_1[0x1107]) << 8 |
                                 (ushort)(fVar5 + _DAT_0059e800 == (float)param_1[0x1107]) << 0xe;
                      }
                      else {
                        uVar17 = (ushort)((float)param_1[iVar10 * 0x11 + 0x105e] < _DAT_0059e7f0) <<
                                 8 | (ushort)((float)param_1[iVar10 * 0x11 + 0x105e] ==
                                             _DAT_0059e7f0) << 0xe;
                      }
                      if (uVar17 == 0) {
                        iVar16 = 8;
                      }
                    }
                  }
                  else {
LAB_00428487:
                    iVar16 = 0;
                    param_1[iVar15 * 7 + 0x10b6] = (int)((float)param_1[0x1120] + _DAT_0059e43c);
                    fVar2 = fVar5 - fVar14;
                    if ((float)param_1[0x110a] <= fVar2) {
                      fVar2 = (float)param_1[0x110a];
                    }
                    if (DAT_0059e440 <= fVar5) {
                      if (fVar5 <= *(float *)(iVar12 + 0x54) + _DAT_0059e8a4) goto LAB_004284eb;
LAB_0042858e:
                      local_3c = 550.0;
                    }
                    else {
                      if (fVar5 < -(*(float *)(iVar12 + 0x50) + _DAT_0059e8a4)) goto LAB_0042858e;
LAB_004284eb:
                      fVar19 = (float10)FUN_004fae70(fVar2);
                      local_3c = (float)fVar19;
                    }
                    if (fVar2 + fVar14 < (float)param_1[0x110a]) {
                      local_3c = local_3c -
                                 ((float)param_1[0x110a] - (fVar2 + fVar14)) * _DAT_0059e92c;
                    }
                    fVar2 = fVar5 + fVar14;
                    if (fVar2 <= (float)param_1[0x110a]) {
                      fVar2 = (float)param_1[0x110a];
                    }
                    if (DAT_0059e440 <= fVar5) {
                      if (fVar5 <= *(float *)(iVar12 + 0x54) + _DAT_0059e8a4) goto LAB_004285b9;
LAB_004285af:
                      local_68 = 550.0;
                    }
                    else {
                      if (fVar5 < -(*(float *)(iVar12 + 0x50) + _DAT_0059e8a4)) goto LAB_004285af;
LAB_004285b9:
                      fVar19 = (float10)FUN_004fae70(fVar2);
                      local_68 = (float)fVar19;
                    }
                    if ((float)param_1[0x110a] < fVar2 - fVar14) {
                      local_68 = local_68 -
                                 ((fVar2 - fVar14) - (float)param_1[0x110a]) * _DAT_0059e92c;
                    }
                    piVar13 = (int *)param_1[iVar10 * 0x11 + 0x105d];
                    local_3c = local_3c - (float)piVar13[0x115d] * _DAT_0059e8dc;
                    local_68 = local_68 - (float)piVar13[0x115c] * _DAT_0059e8dc;
                    if ((float)piVar13[0x1111] <= _DAT_0059e450) {
                      fVar14 = (_DAT_0059e43c - (float)piVar13[0x1111]) * _DAT_0059e80c;
                      local_3c = local_3c + fVar14;
                      local_68 = local_68 + fVar14;
                    }
                    else {
                      if ((float)piVar13[0x114a] < DAT_0059e440) {
                        local_3c = local_3c - (float)param_1[iVar10 * 0x11 + 0x1069] * _DAT_0059e7ec
                        ;
                      }
                      if ((float)piVar13[0x114b] < DAT_0059e440) {
                        local_68 = local_68 - (float)param_1[iVar10 * 0x11 + 0x1069] * _DAT_0059e7ec
                        ;
                      }
                    }
                    if ((param_1[0x115c] != 0) && (_DAT_0059e7f0 < local_50)) {
                      local_3c = DAT_0059e440;
                    }
                    if ((param_1[0x115d] != 0) && (local_50 < _DAT_0059e800)) {
                      local_68 = 0.0;
                    }
                    if (bVar4) {
                      local_50 = (float)param_1[iVar10 * 0x11 + 0x105e];
                    }
                    iVar15 = 0;
                    piVar11 = param_1 + 0x10d5;
                    do {
                      if (*piVar11 == piVar13[0x10fe]) {
                        fVar14 = ((float)param_1[iVar15 + 0x10e9] + (float)param_1[0x1110]) *
                                 _DAT_0059e450;
                        break;
                      }
                      iVar15 = iVar15 + 1;
                      piVar11 = piVar11 + 1;
                      fVar14 = _DAT_0059e928;
                    } while (iVar15 < 0x14);
                    if ((((fVar14 < (float)piVar13[0x10ff]) || (0 < piVar13[0x115c])) ||
                        (0 < piVar13[0x115d])) && ((char)param_1[0x115b] == '\0')) {
                      local_68 = 0.0;
                      local_3c = DAT_0059e440;
                    }
                    if ((*(int *)(*param_1 + 0x48a4) == *(int *)(*piVar13 + 0x48a4)) &&
                       (*(int *)(*piVar13 + 0x48a8) < *(int *)(*param_1 + 0x48a8))) {
                      local_3c = local_3c - _DAT_0059e924;
                      local_68 = local_68 - _DAT_0059e924;
                    }
                    if (param_1[0x1154] == 1) {
                      local_3c = local_3c - _DAT_0059e920;
                      local_68 = local_68 - _DAT_0059e920;
                    }
                    if ((param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b2] < 0) ||
                       ((float)param_1[0x110e] <= _DAT_0059e84c)) {
                      local_60 = (float)param_1[0x1110];
                    }
                    else {
                      local_60 = ((float)param_1[param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 +
                                                         0x10b2] + 0x10e9] + (float)param_1[0x1110])
                                 * _DAT_0059e450;
                    }
                    cVar3 = (char)param_1[0x115b];
                    local_60 = local_68 / local_60;
                    local_54 = -((float)param_1[iVar10 * 0x11 + 0x1060] /
                                (float)param_1[iVar10 * 0x11 + 0x1063]);
                    if ((cVar3 != '\0') && ((float)param_1[iVar10 * 0x11 + 0x1060] < _DAT_0059e8d8))
                    {
                      if (((float)param_1[0x1105] + (float)param_1[0x1106]) * _DAT_0059e450 <=
                          (float)param_1[iVar10 * 0x11 + 0x1064]) {
                        if (local_3c <= _DAT_0059e920) {
                          local_3c = _DAT_0059e920;
                        }
                      }
                      else if (local_68 <= _DAT_0059e920) {
                        local_68 = 400.0;
                      }
                      local_60 = 2.0;
                      local_54 = 1.0;
                    }
                    if (((((local_44 == 0) && (local_68 != DAT_0059e440)) &&
                         (DAT_0059e440 < local_60)) &&
                        ((DAT_0059e440 < local_54 && (local_54 < local_60)))) ||
                       (_DAT_0059e91c - (float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7]
                        < local_68)) {
                      if ((local_64 < local_5c) || (cVar3 != '\0')) {
                        iVar16 = 1;
                        *(undefined1 *)((int)param_1 + 0x4579) = 1;
                        goto LAB_0042893a;
                      }
LAB_00428951:
                      if ((param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b2] < 0) ||
                         ((float)param_1[0x110e] <= _DAT_0059e84c)) {
                        local_60 = (float)param_1[0x1110];
                      }
                      else {
                        local_60 = ((float)param_1[param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 +
                                                           0x10b2] + 0x10e9] +
                                   (float)param_1[0x1110]) * _DAT_0059e450;
                      }
                      local_60 = local_3c / local_60;
                    }
                    else {
LAB_0042893a:
                      if ((cVar3 == '\0') ||
                         (_DAT_0059e8d8 <= (float)param_1[iVar10 * 0x11 + 0x1060]))
                      goto LAB_00428951;
                    }
                    if ((((((local_44 != 0) || (local_3c == DAT_0059e440)) ||
                          (local_60 <= DAT_0059e440)) ||
                         ((local_54 <= DAT_0059e440 || (local_60 <= local_54)))) &&
                        (local_3c <=
                         _DAT_0059e91c -
                         (float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7])) ||
                       ((local_5c <= local_64 && (cVar3 == '\0')))) {
                      if (iVar16 == 0) {
                        if ((local_64 < local_5c) ||
                           (2 < *(int *)(param_1[iVar10 * 0x11 + 0x105d] + 0x455c))) {
                          if ((bVar4) || ((float)param_1[iVar10 * 0x11 + 0x1060] < _DAT_0059e918)) {
                            if ((float)_DAT_0059e910 <= ABS((float)param_1[iVar10 * 0x11 + 0x105e]))
                            {
                              uVar17 = (ushort)((float)param_1[iVar10 * 0x11 + 0x105e] <
                                               (float)_DAT_0059e430) << 8 |
                                       (ushort)((float)param_1[iVar10 * 0x11 + 0x105e] ==
                                               (float)_DAT_0059e430) << 0xe;
                            }
                            else {
                              uVar17 = (ushort)(local_3c < local_68) << 8 |
                                       (ushort)(local_3c == local_68) << 0xe;
                            }
                            if (uVar17 == 0) {
                              iVar16 = 7;
                            }
                            else {
                              iVar16 = 8;
                            }
                          }
                          else {
                            iVar16 = 0x10;
                          }
                        }
                        else {
                          iVar16 = 5;
                        }
                      }
                    }
                    else if ((iVar16 != 1) || (local_68 < local_3c)) {
                      iVar16 = 2;
                      *(undefined1 *)((int)param_1 + 0x4579) = 1;
                    }
                    else {
                      *(undefined1 *)((int)param_1 + 0x4579) = 1;
                    }
                    if (cVar3 == '\0') {
                      if (iVar16 == 1) {
                        if (*(float *)(iVar12 + 0x54) - (fVar5 + local_4c) < DAT_0059e440) {
                          if (_DAT_0059e43c < local_50) {
                            iVar16 = 2;
                            goto LAB_00428b1d;
                          }
                          iVar16 = 7;
                        }
                      }
                      else if (iVar16 == 2) {
LAB_00428b1d:
                        if (((fVar5 - local_4c) + *(float *)(iVar12 + 0x50) < DAT_0059e440) &&
                           (iVar16 = 1, _DAT_0059e670 <= local_50)) {
                          iVar16 = 8;
                        }
                      }
                    }
                    iVar15 = param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7];
                    if (iVar15 == iVar16) goto LAB_00428bea;
                    if ((iVar15 == 2) && (iVar16 == 0x10)) {
                      iVar16 = 7;
                    }
                    else if ((iVar15 == 1) && (iVar16 == 0x10)) {
                      iVar16 = 8;
                    }
                    param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] = iVar16;
                    if (iVar16 != 0x10) goto LAB_00428bea;
                    param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] =
                         (int)((float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] *
                              _DAT_0059e908);
LAB_00428bb6:
                    if (bVar8) {
                      iVar16 = 0x10;
                      param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] = 0x10;
                    }
                    else {
                      if (iVar16 == 1) goto LAB_00428c82;
                      if (iVar16 == 2) goto LAB_00428cc6;
                    }
                  }
                  if (bVar4) {
                    local_50 = fVar5 - (float)param_1[0x110a];
                  }
                  if (((iVar16 != 0x10) && (iVar16 != 7)) && (iVar16 != 8)) {
LAB_0042905c:
                    if ((iVar16 == 2) || (iVar16 == 7)) goto LAB_00429222;
                    if ((iVar16 != 1) && (iVar16 != 8)) goto LAB_004293a6;
                    param_1[0x1142] = (int)((float)param_1[0x1142] + _DAT_0059e43c);
                    if (((float)param_1[iVar10 * 0x11 + 0x1060] < _DAT_0059e5fc) &&
                       (ABS((float)param_1[iVar10 * 0x11 + 0x105e]) < (float)_DAT_0059e900)) {
                      FUN_0042a740(param_1[0x1110]);
                    }
                    FUN_0042af70(param_1,iVar16);
                    if ((_DAT_0059e5fc <= (float)param_1[iVar10 * 0x11 + 0x1060]) &&
                       (_DAT_0059e43c <= (float)param_1[iVar10 * 0x11 + 0x1063])) goto LAB_004293a6;
                    fVar14 = (local_50 + local_4c) * local_58 + (float)param_1[0x110a];
                    if (fVar14 < local_70) {
                      param_1[0x1157] = param_1[0x1157] + 1;
                      if (local_6c < fVar14) {
                        bVar7 = true;
                        local_6c = fVar14;
                      }
                      goto LAB_004293a6;
                    }
                    if (!bVar6) {
                      param_1[0x1157] = param_1[0x1157] + 1;
                      local_6c = local_70;
                      bVar7 = true;
                      goto LAB_004293a6;
                    }
                    if ((param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] == 3) ||
                       ((float)param_1[iVar10 * 0x11 + 0x1063] <= _DAT_0059e850)) {
                      if (local_5c * _DAT_0059e450 <= (float)param_1[iVar10 * 0x11 + 0x1060])
                      goto LAB_004293a6;
                      param_1[0x1157] = param_1[0x1157] + 1;
                      param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] = 8;
                      goto LAB_004291e2;
                    }
                    param_1[0x1157] = param_1[0x1157] + 1;
                    param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] = 4;
                    goto LAB_00429206;
                  }
                  if ((param_1[0x1154] == 1) &&
                     (ABS((float)param_1[iVar10 * 0x11 + 0x105e]) < (float)_DAT_0059e900)) {
                    if (_DAT_0059e5fc <= (float)param_1[iVar10 * 0x11 + 0x1060]) {
                      if (_DAT_0059e8ec <= (float)param_1[iVar10 * 0x11 + 0x1060])
                      goto LAB_00428d95;
                      fVar14 = (float)param_1[0x1110] - _DAT_0059e43c;
                    }
                    else {
                      fVar14 = (float)param_1[0x1110] - _DAT_0059e8a4;
                    }
                    FUN_0042a740(fVar14);
                  }
LAB_00428d95:
                  bVar8 = true;
                  param_1[0x1142] = (int)((float)param_1[0x1142] + _DAT_0059e43c);
                  fVar14 = local_5c * _DAT_0059e8b4;
                  local_54 = local_5c * _DAT_0059e8fc;
                  local_60 = local_5c * _DAT_0059e8f8;
                  if ((*(int *)(param_1[iVar10 * 0x11 + 0x105d] + 0x455c) < 2) &&
                     (ABS((float)param_1[iVar10 * 0x11 + 0x105e]) < (float)_DAT_0059e7e0)) {
                    if ((float)param_1[iVar10 * 0x11 + 0x1060] < local_5c + local_5c) {
                      param_1[0x1157] = param_1[0x1157] + 1;
                    }
                    if ((float)param_1[iVar10 * 0x11 + 0x1060] < _DAT_0059e5fc) {
                      if (DAT_0059e440 <= (float)param_1[iVar10 * 0x11 + 0x1063]) {
                        fVar14 = (float)param_1[0x1110];
                      }
                      else {
                        fVar14 = (float)param_1[0x1110] - _DAT_0059e5fc;
                      }
                      FUN_0042a740(fVar14);
                    }
                    fVar14 = (float)param_1[iVar10 * 0x11 + 0x1060] - _DAT_0059e5fc;
                    if ((float)param_1[iVar10 * 0x11 + 0x1060] - _DAT_0059e5fc < DAT_0059e440) {
                      fVar14 = DAT_0059e440;
                    }
                    if (fVar14 * fVar14 * _DAT_0059e444 + (float)param_1[iVar10 * 0x11 + 0x1069] <
                        (float)param_1[param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b2] +
                                       0x10e9]) {
                      fVar14 = (float)param_1[iVar10 * 0x11 + 0x1063] - _DAT_0059e5fc;
LAB_00429047:
                      FUN_0042a740(fVar14 + (float)param_1[0x1110]);
                    }
                    goto LAB_0042905c;
                  }
                  if (((float)_DAT_0059e900 <= ABS((float)param_1[iVar10 * 0x11 + 0x105e])) &&
                     ((float)_DAT_0059e900 <= ABS(local_50))) goto LAB_0042905c;
                  if ((float)param_1[iVar10 * 0x11 + 0x1060] < local_5c + local_5c) {
                    param_1[0x1157] = param_1[0x1157] + 1;
                  }
                  if (fVar14 < _DAT_0059e8f4) {
                    fVar14 = _DAT_0059e8f4;
                  }
                  if (local_54 < _DAT_0059e5fc) {
                    local_54 = 10.0;
                  }
                  if (local_60 < _DAT_0059e8f0) {
                    local_60 = 12.5;
                  }
                  if ((_DAT_0059e84c < *(float *)(param_1[iVar10 * 0x11 + 0x105d] + 0x3584)) &&
                     (DAT_0059e440 < (float)param_1[iVar10 * 0x11 + 0x1063])) {
                    param_1[iVar10 * 0x11 + 0x1063] = -0x40800000;
                  }
                  if ((fVar14 <= local_64) ||
                     (_DAT_0059e450 <= (float)param_1[iVar10 * 0x11 + 0x1063])) {
                    if ((local_54 <= local_64) ||
                       (_DAT_0059e7f8 <= (float)param_1[iVar10 * 0x11 + 0x1063])) {
                      if ((local_64 < local_60) &&
                         ((float)param_1[iVar10 * 0x11 + 0x1063] < DAT_0059e440)) {
                        if (iVar16 == 2) goto LAB_00429222;
                        if (iVar16 != 1) {
                          fVar14 = (float)param_1[iVar10 * 0x11 + 0x1063] * _DAT_0059e8bc;
                          goto LAB_00429047;
                        }
                      }
                    }
                    else {
                      if (iVar16 == 2) goto LAB_00429222;
                      if (iVar16 != 1) {
                        fVar14 = (float)param_1[iVar10 * 0x11 + 0x1063] - _DAT_0059e7ec;
                        goto LAB_00429047;
                      }
                    }
                    goto LAB_0042905c;
                  }
                  if (iVar16 != 2) {
                    if (iVar16 != 1) {
                      fVar14 = (float)param_1[iVar10 * 0x11 + 0x1063] - _DAT_0059e5fc;
                      goto LAB_00429047;
                    }
                    goto LAB_0042905c;
                  }
LAB_00429222:
                  param_1[0x1142] = (int)((float)param_1[0x1142] + _DAT_0059e43c);
                  FUN_0042af70(param_1,iVar16);
                  if (((float)param_1[iVar10 * 0x11 + 0x1060] < _DAT_0059e5fc) &&
                     (ABS((float)param_1[iVar10 * 0x11 + 0x105e]) < (float)_DAT_0059e900)) {
                    FUN_0042a740(param_1[0x1110]);
                  }
                  if (((float)param_1[iVar10 * 0x11 + 0x1060] < _DAT_0059e5fc) ||
                     ((float)param_1[iVar10 * 0x11 + 0x1063] < _DAT_0059e43c)) {
                    fVar14 = (local_50 - local_4c) * local_48 + (float)param_1[0x110a];
                    if (fVar14 <= local_6c) {
                      if (bVar7) {
                        if ((param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] == 4) ||
                           ((float)param_1[iVar10 * 0x11 + 0x1063] <= _DAT_0059e850)) {
                          if (local_5c * _DAT_0059e450 <= (float)param_1[iVar10 * 0x11 + 0x1060])
                          goto LAB_004293a6;
                          param_1[0x1157] = param_1[0x1157] + 1;
                          param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] = 7;
LAB_004291e2:
                          param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] =
                               (int)((float)param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b7] *
                                    _DAT_0059e450);
                        }
                        else {
                          param_1[0x1157] = param_1[0x1157] + 1;
                          param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] = 3;
                        }
LAB_00429206:
                        FUN_0042a740((float)param_1[iVar10 * 0x11 + 0x1063] + (float)param_1[0x1110]
                                    );
                      }
                      else {
                        param_1[0x1157] = param_1[0x1157] + 1;
                        local_70 = local_6c;
                        bVar6 = true;
                      }
                    }
                    else {
                      param_1[0x1157] = param_1[0x1157] + 1;
                      if (fVar14 < local_70) {
                        bVar6 = true;
                        local_70 = fVar14;
                      }
                    }
                  }
                }
              }
              else {
                param_1[0x1157] = param_1[0x1157] + 1;
                *(undefined1 *)((int)param_1 + 0x4579) = 1;
                bVar4 = (float)param_1[iVar10 * 0x11 + 0x105e] < DAT_0059e440;
                param_1[0x1142] = (int)((float)param_1[0x1142] + _DAT_0059e43c);
                if (bVar4) {
                  if (param_1[0x115c] == 0) {
                    param_1[0x115c] = *(int *)(param_1[iVar10 * 0x11 + 0x105d] + 0x4570) + 1;
                  }
                  local_34 = (float)param_1[0x110a] - _DAT_0059e43c;
                  if (local_34 < fVar5 + _DAT_0059e800) {
                    local_34 = fVar5 + _DAT_0059e800;
                  }
                  fVar19 = (float10)FUN_004fae70(local_34);
                  if ((param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b2] < 0) ||
                     ((float)param_1[0x110e] <= _DAT_0059e84c)) {
                    fVar20 = (float10)(float)param_1[0x1110];
                  }
                  else {
                    fVar20 = ((float10)(float)param_1[param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 +
                                                              0x10b2] + 0x10e9] +
                             (float10)(float)param_1[0x1110]) * (float10)_DAT_0059e450;
                  }
                  if ((((fVar19 / fVar20 <
                         (float10)-((float)param_1[iVar10 * 0x11 + 0x1060] /
                                   (float)param_1[iVar10 * 0x11 + 0x1063])) &&
                       (DAT_0059e440 <
                        -((float)param_1[iVar10 * 0x11 + 0x1060] /
                         (float)param_1[iVar10 * 0x11 + 0x1063]))) &&
                      (_DAT_0059e450 < *(float *)(param_1[iVar10 * 0x11 + 0x105d] + 0x4444))) &&
                     ((float)param_1[0x110e] < _DAT_0059e84c)) {
                    FUN_0042a740((float)param_1[0x1110] * _DAT_0059e8cc);
                  }
                  fVar14 = (fVar5 + local_4c) * local_58;
                  if (local_6c < fVar14) {
                    bVar6 = true;
                    local_6c = fVar14;
                  }
                  if (local_70 < local_6c) {
                    local_70 = local_70 + _DAT_0059e43c;
                    local_6c = local_70;
                  }
                }
                else {
                  if (param_1[0x115d] == 0) {
                    param_1[0x115d] = *(int *)(param_1[iVar10 * 0x11 + 0x105d] + 0x4574) + 1;
                  }
                  local_38 = (float)param_1[0x110a] + _DAT_0059e43c;
                  if (fVar5 - _DAT_0059e800 < local_38) {
                    local_38 = fVar5 - _DAT_0059e800;
                  }
                  fVar19 = (float10)FUN_004fae70(local_38);
                  if ((param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 + 0x10b2] < 0) ||
                     ((float)param_1[0x110e] <= _DAT_0059e84c)) {
                    fVar20 = (float10)(float)param_1[0x1110];
                  }
                  else {
                    fVar20 = ((float10)(float)param_1[param_1[param_1[iVar10 * 0x11 + 0x106d] * 7 +
                                                              0x10b2] + 0x10e9] +
                             (float10)(float)param_1[0x1110]) * (float10)_DAT_0059e450;
                  }
                  if (((fVar19 / fVar20 <
                        (float10)-((float)param_1[iVar10 * 0x11 + 0x1060] /
                                  (float)param_1[iVar10 * 0x11 + 0x1063])) &&
                      (DAT_0059e440 <
                       -((float)param_1[iVar10 * 0x11 + 0x1060] /
                        (float)param_1[iVar10 * 0x11 + 0x1063]))) &&
                     ((_DAT_0059e450 < *(float *)(param_1[iVar10 * 0x11 + 0x105d] + 0x4444) &&
                      ((float)param_1[0x110e] < _DAT_0059e84c)))) {
                    FUN_0042a740((float)param_1[0x1110] * _DAT_0059e8cc);
                  }
                  fVar14 = (fVar5 - local_4c) * local_48;
                  if (fVar14 < local_70) {
                    bVar6 = true;
                    local_70 = fVar14;
                  }
                  if (local_70 < local_6c) {
                    local_70 = local_6c - _DAT_0059e43c;
                    local_6c = local_70;
                  }
                }
                if (ABS((float)param_1[iVar10 * 0x11 + 0x105e]) < (float)_DAT_0059e930) {
                  FUN_0042a740((float)param_1[0x1110] - _DAT_0059e7ec);
                }
              }
            }
            else {
              fVar14 = (float)param_1[0x1142] + _DAT_0059e43c;
              param_1[0x1157] = param_1[0x1157] + 1;
              *(undefined1 *)((int)param_1 + 0x4579) = 1;
              param_1[0x1142] = (int)fVar14;
              if ((float)param_1[iVar10 * 0x11 + 0x105e] < DAT_0059e440) {
                if (param_1[0x115c] == 0) {
                  param_1[0x115c] = *(int *)(param_1[iVar10 * 0x11 + 0x105d] + 0x4570) + 1;
                }
                fVar14 = (fVar5 + local_4c) * local_58;
                if (local_6c < fVar14) {
                  bVar6 = true;
                  local_6c = fVar14;
                }
                if (local_70 < local_6c) {
                  local_6c = local_70;
                }
              }
              else {
                if (param_1[0x115d] == 0) {
                  param_1[0x115d] = *(int *)(param_1[iVar10 * 0x11 + 0x105d] + 0x4574) + 1;
                }
                fVar14 = (fVar5 - local_4c) * local_48;
                if (fVar14 < local_70) {
                  bVar6 = true;
                  local_70 = fVar14;
                }
                if (local_70 < local_6c) {
                  local_70 = local_6c;
                }
              }
            }
            goto LAB_004293a6;
          }
        }
        param_1[(param_1[iVar10 * 0x11 + 0x106d] + 0x263) * 7] = 5;
      }
    }
LAB_004293a6:
    local_44 = local_44 + 1;
    if (4 < local_44) {
      if ((float)param_1[0x1103] <= local_70) {
        if ((float)param_1[0x1103] < local_6c) {
          param_1[0x1103] = (int)local_6c;
        }
      }
      else {
        param_1[0x1103] = (int)local_70;
      }
      param_1[0x1102] = param_1[0x1103];
      if ((char)param_1[0x1152] != '\0') {
        param_1[0x1102] = param_1[0x1108];
      }
      if ((float)param_1[0x1109] != DAT_0059e440) {
        param_1[0x1102] = param_1[0x1109];
      }
      if (((float)param_1[0x1105] <= (float)param_1[0x1102]) ||
         ((float)param_1[0x1102] < (float)param_1[0x1106] !=
          ((float)param_1[0x1102] == (float)param_1[0x1106]))) {
        *(undefined1 *)(param_1 + 0x1050) = 1;
      }
      *(undefined1 *)(param_1 + 0x1122) = 0;
      return;
    }
  } while( true );
}


