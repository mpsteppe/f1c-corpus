// Function: FUN_004beb10 @ 004beb10
// Size (bytes): 1090


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004beb10(float *param_1,undefined1 *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  float10 fVar11;
  int local_1b8;
  undefined1 local_1b0 [8];
  undefined1 local_1a8;
  
  *param_2 = 0;
  fVar1 = DAT_0059e440;
  param_1[0xd7] = DAT_008acf8c;
  local_1b8 = DAT_005c329c;
  bVar4 = true;
  bVar5 = false;
  param_1[0xd8] = DAT_007c56a4;
  cVar6 = '\0';
  if ((param_1[0xd6] <= fVar1) || (param_1[0xd5] < param_1[0xd6])) {
    if ((DAT_007c56a4 == 9.80909e-45) && (iVar7 = 0, 0 < local_1b8)) {
      do {
        if (*(int *)((&DAT_007c54f0)[iVar7] + 0x4064) == 1) {
          cVar6 = '\x01';
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < local_1b8);
    }
  }
  else {
    cVar6 = '\x01';
    bVar4 = false;
  }
  if (*(char *)((int)param_1 + 0x342) == '\0') {
    FUN_004bf0a0(param_3,cVar6);
  }
  param_1[0xd5] = param_1[0xd5] + param_1[0xd4];
  if (bVar4) {
    if (0 < local_1b8) {
      pfVar10 = param_1;
      do {
        pfVar10[0x68] = param_1[0xd4] + pfVar10[0x68];
        iVar7 = *(int *)(((int)&DAT_007c54f0 - (int)param_1) + (int)pfVar10);
        if (((((*(int *)(iVar7 + 13000) != -1) && (*(int *)(iVar7 + 13000) != 0)) &&
             (iVar9 = *(int *)(iVar7 + 0x403c), iVar9 < (int)param_1[0xd7])) &&
            ((DAT_007c56a4 == 9.80909e-45 || (iVar8 = FUN_0042ae90(), iVar9 <= iVar8)))) &&
           ((*(int *)(*(int *)(((int)&DAT_007c54f0 - (int)param_1) + (int)pfVar10) + 0x4064) != 1 &&
            ((*(int *)(iVar7 + 0x4064) != 3 && (*(int *)(iVar7 + 0x4064) != 2)))))) {
          bVar5 = true;
          if (*pfVar10 < DAT_0059e440) {
            fVar11 = (float10)FUN_004bea10(iVar7,param_1[0xd3]);
            *pfVar10 = (float)fVar11;
          }
          if (*pfVar10 < pfVar10[0x68]) {
            iVar9 = FUN_004bef60(iVar7,0x3f800000);
            if (iVar9 == 0) {
              fVar1 = pfVar10[0x68];
              fVar2 = *pfVar10;
              *(int *)(iVar7 + 0x403c) = *(int *)(iVar7 + 0x403c) + 1;
              fVar3 = param_1[0xd5] - (fVar1 - fVar2);
              if (fVar3 < DAT_0059e440) {
                fVar3 = DAT_0059e440;
              }
              *(float *)(iVar7 + 0x4098) = fVar3;
              if ((*(float *)(iVar7 + 0x409c) < DAT_0059e440 !=
                   (*(float *)(iVar7 + 0x409c) == DAT_0059e440)) ||
                 (*pfVar10 < *(float *)(iVar7 + 0x409c))) {
                *(float *)(iVar7 + 0x409c) = *pfVar10;
              }
              *(float *)(iVar7 + 0x40b8) = (param_1[0xd5] - _DAT_008acf90) - (fVar1 - fVar2);
              FUN_004bf390(iVar7);
              if (((int)param_1[0xd7] <= *(int *)(iVar7 + 0x403c)) || (cVar6 != '\0')) {
                if (*(int *)(iVar7 + 0x4064) != 3) {
                  *(undefined4 *)(iVar7 + 0x4064) = 1;
                }
                if (DAT_007c56a4 == 9.80909e-45) {
                  bVar4 = false;
                }
              }
              pfVar10[0x68] = pfVar10[0x68] - *pfVar10;
            }
            else {
              FUN_004b33b0(4,0x1a,1,*(undefined4 *)(iVar7 + 0x4894),(float)_DAT_008afea0,0);
              if (iVar9 == 1) {
                local_1a8 = 6;
              }
              else {
                fVar1 = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
                DAT_008aae70 = DAT_008aae70 + 1;
                if (_DAT_0059e8b4 <= fVar1) {
                  if (_DAT_0059e8fc <= fVar1) {
                    if (_DAT_0059e4e8 <= fVar1) {
                      if (_DAT_0059e7fc <= fVar1) {
                        if (_DAT_005acddc <= fVar1) {
                          if (_DAT_005acdd8 <= fVar1) {
                            if (_DAT_005acaf0 <= fVar1) {
                              local_1a8 = 9;
                              if (_DAT_005acaec <= fVar1) {
                                local_1a8 = 0;
                              }
                            }
                            else {
                              local_1a8 = 8;
                            }
                          }
                          else {
                            local_1a8 = 7;
                          }
                        }
                        else {
                          local_1a8 = 5;
                        }
                      }
                      else {
                        local_1a8 = 4;
                      }
                    }
                    else {
                      local_1a8 = 3;
                    }
                  }
                  else {
                    local_1a8 = 2;
                  }
                }
                else {
                  local_1a8 = 1;
                }
              }
              FUN_004bbfc0(local_1b0);
            }
            *pfVar10 = -1.0;
          }
        }
        pfVar10 = pfVar10 + 1;
        local_1b8 = local_1b8 + -1;
      } while (local_1b8 != 0);
    }
    _DAT_008afea0 = _DAT_008afea0 + (double)param_1[0xd4];
    if ((bVar4) && (bVar5)) goto LAB_004bef2a;
  }
  FUN_004bf4f0();
  _DAT_008afea0 = (double)(_DAT_008acf90 + param_3);
LAB_004bef2a:
  if ((bVar4) && (bVar5)) {
    return 1;
  }
  return 0;
}


