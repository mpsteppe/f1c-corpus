// Function: FUN_0044ff50 @ 0044ff50
// Size (bytes): 5968


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044ff50(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  float *pfVar12;
  bool bVar13;
  int local_1e0;
  int local_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  char local_1c6;
  char local_1c5;
  uint local_1c4;
  int local_1c0;
  int *local_1bc;
  int iStack_1b8;
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float afStack_19c [6];
  undefined4 uStack_184;
  int iStack_180;
  undefined4 auStack_17c [8];
  int iStack_15c;
  int iStack_158;
  undefined4 local_13c [7];
  byte bStack_120;
  
  if (*param_1 != 0) {
    local_1c5 = '\0';
    local_1c6 = '\0';
    param_1[0x105] = 0;
    local_1bc = (int *)0x0;
    param_1[0x142] = 0;
    param_1[0x144] = 0;
    param_1[0x145] = 0;
    param_1[0x13a] = 0;
    param_1[0x13c] = 0;
    param_1[0x13d] = 0;
    param_1[0x13e] = 0;
    param_1[0x140] = 0;
    param_1[0x141] = 0;
    local_1c0 = 0;
    do {
      if (local_1c0 == 0) {
        local_1c4 = 2;
LAB_0044ffe7:
        iVar9 = *param_1;
        if ((*(int *)(local_1c4 * 0x2c + 0x1b20 + iVar9) == 2) &&
           (puVar4 = *(undefined4 **)(local_1c4 * 0x2c + iVar9 + 0x1b40),
           puVar4 != (undefined4 *)0x0)) {
          if ((*(uint *)(iVar9 + 0x1054) & 0x100) == 0) {
LAB_0045014a:
            if ((*(uint *)(iVar9 + 0x1450) & 0x100) != 0) {
              if (puVar4 == &DAT_007ca3b8) {
                local_1dc = 0;
                local_1e0 = 1;
              }
              else {
                if (puVar4 == &DAT_007cc9bc) {
                  local_1dc = 0;
                }
                else {
                  if (puVar4 == &DAT_007cd158) {
                    local_1dc = 4;
                    local_1e0 = 1;
                    goto LAB_00450272;
                  }
                  if (puVar4 == &DAT_007ca50c) {
                    local_1dc = 4;
                  }
                  else {
                    if (puVar4 == &DAT_007cd0f8) {
                      local_1dc = 8;
                      local_1e0 = 1;
                      goto LAB_00450272;
                    }
                    if (puVar4 == &DAT_007ca438) {
                      local_1dc = 8;
                    }
                    else {
                      if (puVar4 == &DAT_007ca448) {
                        local_1dc = 0xc;
                        local_1e0 = 1;
                        goto LAB_00450272;
                      }
                      if (puVar4 == &DAT_007ccbf4) {
                        local_1dc = 0xc;
                      }
                      else {
                        if (puVar4 == &DAT_007ca3a8) {
                          local_1dc = 0x10;
                          local_1e0 = 1;
                          goto LAB_00450272;
                        }
                        if (puVar4 == &DAT_007ca480) {
                          local_1dc = 0x10;
                        }
                        else {
                          if (puVar4 == &DAT_007cc9ec) {
                            local_1dc = 0x14;
                            local_1e0 = 1;
                            goto LAB_00450272;
                          }
                          if (puVar4 != &DAT_007ca3d8) goto LAB_00450336;
                          local_1dc = 0x14;
                        }
                      }
                    }
                  }
                }
                local_1e0 = -1;
              }
LAB_00450272:
              iVar8 = iVar9 + 0x1184;
              if (iVar8 != 0) goto LAB_00450280;
            }
          }
          else {
            if (puVar4 == &DAT_007ca490) {
              local_1dc = 0;
              local_1e0 = 1;
            }
            else {
              if (puVar4 == &DAT_007cca44) {
                local_1dc = 0;
              }
              else {
                if (puVar4 == &DAT_007ca3e8) {
                  local_1dc = 4;
                  local_1e0 = 1;
                  goto LAB_0045013c;
                }
                if (puVar4 == &DAT_007ca470) {
                  local_1dc = 4;
                }
                else {
                  if (puVar4 == &DAT_007cd198) {
                    local_1dc = 8;
                    local_1e0 = 1;
                    goto LAB_0045013c;
                  }
                  if (puVar4 == &DAT_007ca3c8) {
                    local_1dc = 8;
                  }
                  else {
                    if (puVar4 == &DAT_007ccbb0) {
                      local_1dc = 0xc;
                      local_1e0 = 1;
                      goto LAB_0045013c;
                    }
                    if (puVar4 == &DAT_007ccfb0) {
                      local_1dc = 0xc;
                    }
                    else {
                      if (puVar4 == &DAT_007cca6c) {
                        local_1dc = 0x10;
                        local_1e0 = 1;
                        goto LAB_0045013c;
                      }
                      if (puVar4 == &DAT_007ccf80) {
                        local_1dc = 0x10;
                      }
                      else {
                        if (puVar4 == &DAT_007cccb0) {
                          local_1dc = 0x14;
                          local_1e0 = 1;
                          goto LAB_0045013c;
                        }
                        if (puVar4 != &DAT_007cca7c) goto LAB_0045014a;
                        local_1dc = 0x14;
                      }
                    }
                  }
                }
              }
              local_1e0 = -1;
            }
LAB_0045013c:
            iVar8 = iVar9 + 0xd88;
            if (iVar8 == 0) goto LAB_0045014a;
LAB_00450280:
            piVar10 = *(int **)(iVar8 + 0x80);
            if (piVar10 != (int *)0x0) {
              if (local_1c0 == 0) {
                local_1bc = (int *)iVar8;
              }
              puVar4 = local_13c;
              for (iVar9 = 0x4f; iVar9 != 0; iVar9 = iVar9 + -1) {
                *puVar4 = 0;
                puVar4 = puVar4 + 1;
              }
              local_13c[0] = 0x13c;
              iVar9 = (**(code **)(*piVar10 + 0x38))(piVar10,local_13c,local_1dc,1);
              if ((-1 < iVar9) && ((bStack_120 & 1) != 0)) {
                if (local_1c0 == 0) {
                  param_1[0x142] = local_1dc;
                  param_1[0x13a] = iVar8;
                  param_1[0x13e] = local_1e0;
                }
                else if (local_1c0 == 1) {
                  param_1[0x144] = local_1dc;
                  param_1[0x13c] = iVar8;
                  param_1[0x140] = local_1e0;
                }
                else if (local_1c0 == 2) {
                  param_1[0x145] = local_1dc;
                  param_1[0x13d] = iVar8;
                  param_1[0x141] = local_1e0;
                }
              }
            }
          }
        }
      }
      else {
        if (local_1c0 == 1) {
          local_1c4 = 0;
          goto LAB_0044ffe7;
        }
        if (local_1c0 == 2) {
          local_1c4 = 1;
          goto LAB_0044ffe7;
        }
        if (-1 < (int)local_1c4) goto LAB_0044ffe7;
      }
LAB_00450336:
      local_1c0 = local_1c0 + 1;
    } while (local_1c0 < 3);
    if ((param_1[0x13a] != 0) && (param_1[0x13e] != 0)) {
      if ((param_1[0x13c] == 0) || (DAT_007d2044 != 0)) {
        param_1[0x144] = param_1[0x142];
        param_1[0x13c] = param_1[0x13a];
        param_1[0x140] = param_1[0x13e];
        DAT_007d2044 = 1;
        if (DAT_007d204c < 2) {
          if (DAT_007d2050 < 1) {
            DAT_007d2044 = DAT_007d2050;
          }
        }
        else {
          DAT_007d2044 = DAT_007d204c;
        }
      }
      if ((param_1[0x13d] == 0) || (DAT_007d2068 != 0)) {
        param_1[0x145] = param_1[0x142];
        param_1[0x13d] = param_1[0x13a];
        param_1[0x141] = param_1[0x13e];
        DAT_007d2068 = 1;
        if (DAT_007d2070 < 2) {
          if (DAT_007d2074 < 1) {
            DAT_007d2068 = DAT_007d2074;
          }
        }
        else {
          DAT_007d2068 = DAT_007d2070;
        }
      }
    }
    if (((DAT_007d1fd8 == 3) && (local_1bc != (int *)0x0)) &&
       (piVar10 = *(int **)((int)local_1bc + 0x80), piVar10 != (int *)0x0)) {
      puVar4 = local_13c;
      for (iVar9 = 0x4f; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      local_13c[0] = 0x13c;
      iVar9 = (**(code **)(*piVar10 + 0x38))(piVar10,local_13c,4,1);
      if ((-1 < iVar9) && ((bStack_120 & 1) != 0)) {
        param_1[0x13a] = (int)local_1bc;
        param_1[0x142] = 4;
        param_1[0x13e] = 1;
        param_1[0x13c] = (int)local_1bc;
        param_1[0x144] = 4;
        param_1[0x140] = 1;
        param_1[0x13d] = (int)local_1bc;
        param_1[0x145] = 4;
        param_1[0x141] = 1;
        iVar9 = (**(code **)(**(int **)((int)local_1bc + 0x80) + 0x38))
                          (*(int **)((int)local_1bc + 0x80),local_13c,0,1);
        if ((-1 < iVar9) && ((bStack_120 & 1) != 0)) {
          if (DAT_007d2044 == 0) {
            param_1[0x144] = 0;
          }
          if (DAT_007d2068 == 0) {
            param_1[0x145] = 0;
          }
        }
      }
    }
    if (*(int *)(*param_1 + 0xe08) != 0) {
      piVar10 = param_1 + 0x148;
      puVar4 = &DAT_007cc9cc;
      piVar5 = piVar10;
      do {
        *puVar4 = 0;
        *piVar5 = 0;
        puVar4 = puVar4 + 1;
        piVar5 = piVar5 + 1;
      } while ((int)puVar4 < 0x7cc9ec);
      DAT_007cd07c = 0;
      param_1[0x146] = 0;
      iVar9 = (**(code **)(**(int **)(*param_1 + 0xe08) + 0x10))
                        (*(int **)(*param_1 + 0xe08),&LAB_0044edd0,0,3);
      if (-1 < iVar9) {
        param_1[0x146] = DAT_007cd07c;
        piVar5 = &DAT_007cc9cc;
        do {
          *piVar10 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar10 = piVar10 + 1;
        } while ((int)piVar5 < 0x7cc9ec);
      }
    }
    if (*(int *)(*param_1 + 0x1204) != 0) {
      piVar10 = param_1 + 0x150;
      DAT_007cd07c = 0;
      param_1[0x147] = 0;
      puVar4 = &DAT_007cc9cc;
      piVar5 = piVar10;
      do {
        *puVar4 = 0;
        *piVar5 = 0;
        puVar4 = puVar4 + 1;
        piVar5 = piVar5 + 1;
      } while ((int)puVar4 < 0x7cc9ec);
      iVar9 = (**(code **)(**(int **)(*param_1 + 0x1204) + 0x10))
                        (*(int **)(*param_1 + 0x1204),&LAB_0044edd0,0,3);
      if (-1 < iVar9) {
        param_1[0x147] = DAT_007cd07c;
        piVar5 = &DAT_007cc9cc;
        do {
          *piVar10 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar10 = piVar10 + 1;
        } while ((int)piVar5 < 0x7cc9ec);
      }
    }
    local_1c0 = 0;
    do {
      iVar9 = local_1c0;
      iStack_180 = local_1c0 + 1;
      piVar10 = param_1 + iStack_180 * 0x1a;
      *(undefined1 *)(param_1 + local_1c0 * 0x1a + 1) = 0;
      param_1[local_1c0 * 0x1a + 0x19] = 0;
      *piVar10 = 0;
      if ((DAT_007d1ffc == 0) || (DAT_007d2020 == DAT_0059e440)) goto LAB_0045162a;
      local_1bc = piVar10;
      switch(local_1c0) {
      case 0:
        if ((((_DAT_007d2140 == DAT_0059e440) || (_DAT_007d2164 == DAT_0059e440)) ||
            (param_1[0x13a] == 0)) || ((param_1[0x13e] == 0 || (DAT_007d1ffc < 1)))) {
LAB_004514b0:
          *piVar10 = 0;
        }
        else {
          *piVar10 = param_1[0x13a];
          param_1[0x107] = 0;
          param_1[0x108] = 0;
          param_1[0x109] = 0;
          param_1[0x10a] = 0;
          param_1[local_1c0 * 0x1a + 4] = -1;
          param_1[local_1c0 * 0x1a + 7] = -1;
          param_1[local_1c0 * 0x1a + 2] = 0x38;
          param_1[local_1c0 * 0x1a + 3] = 0x12;
          param_1[local_1c0 * 0x1a + 5] = 0;
          param_1[local_1c0 * 0x1a + 6] = 10000;
          param_1[local_1c0 * 0x1a + 8] = 0;
          param_1[local_1c0 * 0x1a + 9] = 1;
          param_1[local_1c0 * 0x1a + 10] = (int)(param_1 + 0x142);
          param_1[local_1c0 * 0x1a + 0xb] = (int)(param_1 + 0x13e);
          param_1[local_1c0 * 0x1a + 0xc] = 0;
          param_1[local_1c0 * 0x1a + 0xd] = 0x10;
          param_1[local_1c0 * 0x1a + 0xe] = (int)(param_1 + 0x107);
          param_1[local_1c0 * 0x1a + 0xf] = 0;
          switch(DAT_007d20f8) {
          case 0:
            goto switchD_004513db_caseD_0;
          case 1:
switchD_004513db_caseD_1:
            uStack_1d8 = DAT_005ad3d0;
            uStack_1d4 = DAT_005ad3d4;
            uStack_1d0 = DAT_005ad3d8;
            uStack_1cc = DAT_005ad3dc;
            break;
          case 2:
switchD_004513db_caseD_2:
            uStack_1d8 = DAT_005ad3b0;
            uStack_1d4 = DAT_005ad3b4;
            uStack_1d0 = DAT_005ad3b8;
            uStack_1cc = DAT_005ad3bc;
            break;
          case 3:
switchD_004513db_caseD_3:
            uStack_1d8 = DAT_005ad3a0;
            uStack_1d4 = DAT_005ad3a4;
            uStack_1d0 = DAT_005ad3a8;
            uStack_1cc = DAT_005ad3ac;
            break;
          case 4:
switchD_004513db_caseD_4:
            uStack_1d8 = DAT_005ad390;
            uStack_1d4 = DAT_005ad394;
            uStack_1d0 = DAT_005ad398;
            uStack_1cc = DAT_005ad39c;
            break;
          default:
switchD_004513db_default:
            uStack_1d8 = DAT_005ad3c0;
            uStack_1d4 = DAT_005ad3c4;
            uStack_1d0 = DAT_005ad3c8;
            uStack_1cc = DAT_005ad3cc;
          }
        }
        break;
      case 1:
        if (((_DAT_007d21f4 == DAT_0059e440) || (_DAT_007d2218 == DAT_0059e440)) ||
           ((param_1[0x13a] == 0 || ((param_1[0x13e] == 0 || (DAT_007d1ffc < 2))))))
        goto LAB_004514b0;
        *piVar10 = param_1[0x13a];
        iVar8 = __ftol();
        param_1[0x10c] = iVar8;
        iVar8 = __ftol();
        param_1[0x10e] = iVar8;
        iVar8 = __ftol();
        param_1[0x10d] = iVar8;
        iVar8 = __ftol();
        param_1[0x10f] = iVar8;
        param_1[0x10b] = 0;
        param_1[0x110] = 0;
        param_1[iVar9 * 0x1a + 4] = -1;
        param_1[iVar9 * 0x1a + 7] = -1;
        param_1[iVar9 * 0x1a + 10] = (int)(param_1 + 0x142);
        param_1[iVar9 * 0x1a + 2] = 0x38;
        param_1[iVar9 * 0x1a + 3] = 0x12;
        param_1[iVar9 * 0x1a + 5] = 0;
        param_1[iVar9 * 0x1a + 6] = 10000;
        param_1[iVar9 * 0x1a + 8] = 0;
        param_1[iVar9 * 0x1a + 9] = 1;
        param_1[iVar9 * 0x1a + 0xb] = (int)(param_1 + 0x13e);
        param_1[iVar9 * 0x1a + 0xc] = 0;
        param_1[iVar9 * 0x1a + 0xd] = 0x18;
        param_1[iVar9 * 0x1a + 0xe] = (int)(param_1 + 0x10b);
        param_1[iVar9 * 0x1a + 0xf] = 0;
        uStack_1d8 = DAT_005ad360;
        uStack_1d4 = DAT_005ad364;
        uStack_1d0 = DAT_005ad368;
        uStack_1cc = DAT_005ad36c;
        break;
      case 2:
        if ((((_DAT_007d223c == DAT_0059e440) || (_DAT_007d2260 == DAT_0059e440)) ||
            (param_1[0x13a] == 0)) || ((param_1[0x13e] == 0 || (DAT_007d1ffc < 2))))
        goto LAB_004514b0;
        *piVar10 = param_1[0x13a];
        iVar8 = __ftol();
        param_1[0x112] = iVar8;
        iVar8 = __ftol();
        param_1[0x114] = iVar8;
        iVar8 = __ftol();
        param_1[0x113] = iVar8;
        iVar8 = __ftol();
        param_1[0x115] = iVar8;
        param_1[0x111] = 0;
        param_1[0x116] = 0;
        param_1[iVar9 * 0x1a + 4] = -1;
        param_1[iVar9 * 0x1a + 7] = -1;
        param_1[iVar9 * 0x1a + 10] = (int)(param_1 + 0x142);
        param_1[iVar9 * 0x1a + 2] = 0x38;
        param_1[iVar9 * 0x1a + 3] = 0x12;
        param_1[iVar9 * 0x1a + 5] = 0;
        param_1[iVar9 * 0x1a + 6] = 10000;
        param_1[iVar9 * 0x1a + 8] = 0;
        param_1[iVar9 * 0x1a + 9] = 1;
        param_1[iVar9 * 0x1a + 0xb] = (int)(param_1 + 0x13e);
        param_1[iVar9 * 0x1a + 0xc] = 0;
        param_1[iVar9 * 0x1a + 0xd] = 0x18;
        param_1[iVar9 * 0x1a + 0xe] = (int)(param_1 + 0x111);
        param_1[iVar9 * 0x1a + 0xf] = 0;
        uStack_1d8 = DAT_005ad370;
        uStack_1d4 = DAT_005ad374;
        uStack_1d0 = DAT_005ad378;
        uStack_1cc = DAT_005ad37c;
        break;
      case 3:
        if (((2 < DAT_007d1ffc) && ((*(uint *)(*param_1 + 0x1054) & 0x100) != 0)) &&
           (param_1[0x146] != 0)) {
          puVar4 = local_13c;
          local_1c4 = 0;
          pfVar12 = (float *)&DAT_007d24c4;
          iStack_1b8 = 8;
          do {
            uVar7 = param_1[0x146];
            puVar4[5] = 0;
            *puVar4 = 0;
            if (local_1c4 < uVar7) {
              uVar6 = __ftol();
              puVar4[3] = uVar6;
              uVar6 = __ftol();
              puVar4[1] = uVar6;
              uVar6 = __ftol();
              puVar4[4] = uVar6;
              uVar6 = __ftol();
              puVar4[2] = uVar6;
            }
            else {
              fVar1 = pfVar12[2];
              fVar3 = pfVar12[3];
              *pfVar12 = 0.0;
              fVar2 = *pfVar12;
              puVar4[2] = 0;
              puVar4[1] = 0;
              if (fVar1 <= fVar2) {
                if (fVar3 < *pfVar12) {
                  *pfVar12 = fVar3;
                }
              }
              else {
                *pfVar12 = fVar1;
              }
              fStack_1ac = pfVar12[0x93];
              pfVar12[0x90] = 0.0;
              if (pfVar12[0x92] <= pfVar12[0x90]) {
                if (fStack_1ac < pfVar12[0x90]) {
                  pfVar12[0x90] = fStack_1ac;
                }
              }
              else {
                pfVar12[0x90] = pfVar12[0x92];
              }
              fStack_1a0 = pfVar12[0x123];
              pfVar12[0x120] = 0.0;
              if (pfVar12[0x122] <= pfVar12[0x120]) {
                if (fStack_1a0 < pfVar12[0x120]) {
                  pfVar12[0x120] = fStack_1a0;
                }
              }
              else {
                pfVar12[0x120] = pfVar12[0x122];
              }
              afStack_19c[0] = pfVar12[0x1b3];
              pfVar12[0x1b0] = 0.0;
              if (pfVar12[0x1b2] <= pfVar12[0x1b0]) {
                if (afStack_19c[0] < pfVar12[0x1b0]) {
                  pfVar12[0x1b0] = afStack_19c[0];
                }
              }
              else {
                pfVar12[0x1b0] = pfVar12[0x1b2];
              }
            }
            local_1c4 = local_1c4 + 1;
            puVar4 = puVar4 + 6;
            pfVar12 = pfVar12 + 9;
            iStack_1b8 = iStack_1b8 + -1;
          } while (iStack_1b8 != 0);
          uVar7 = 0;
          do {
            if (uVar7 == 0) {
              auStack_17c[0] = 1;
            }
            else {
              auStack_17c[uVar7] = 0;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 8);
          *local_1bc = *param_1 + 0xd88;
          param_1[iVar9 * 0x1a + 4] = -1;
          param_1[iVar9 * 0x1a + 7] = -1;
          param_1[iVar9 * 0x1a + 2] = 0x38;
          param_1[iVar9 * 0x1a + 3] = 0x11;
          param_1[iVar9 * 0x1a + 5] = 0;
          param_1[iVar9 * 0x1a + 6] = 10000;
          param_1[iVar9 * 0x1a + 8] = 0;
          param_1[iVar9 * 0x1a + 9] = param_1[0x146];
          param_1[iVar9 * 0x1a + 0xc] = 0;
          param_1[iVar9 * 0x1a + 10] = (int)(param_1 + 0x148);
          param_1[iVar9 * 0x1a + 0xb] = (int)auStack_17c;
          param_1[iVar9 * 0x1a + 0xd] = param_1[0x146] * 0x18;
          param_1[iVar9 * 0x1a + 0xe] = (int)local_13c;
          param_1[iVar9 * 0x1a + 0xf] = 0;
          uStack_1d8 = DAT_005ad380;
          uStack_1d4 = DAT_005ad384;
          uStack_1d0 = DAT_005ad388;
          uStack_1cc = DAT_005ad38c;
          iStack_1b8 = 0;
          piVar10 = local_1bc;
        }
        break;
      case 4:
        if (((2 < DAT_007d1ffc) && ((*(uint *)(*param_1 + 0x1450) & 0x100) != 0)) &&
           (param_1[0x147] != 0)) {
          puVar4 = local_13c + 3;
          local_1c4 = 0;
          pfVar12 = (float *)&DAT_007d25e4;
          iStack_1b8 = 8;
          do {
            if (local_1c4 < (uint)param_1[0x147]) {
              uVar6 = __ftol();
              *puVar4 = uVar6;
              uStack_184 = __ftol();
              puVar4[-2] = uStack_184;
              uVar6 = __ftol();
              puVar4[1] = uVar6;
              puVar4[-1] = uStack_184;
              puVar4[2] = 0;
              puVar4[-3] = 0;
            }
            else {
              fVar1 = pfVar12[2];
              fStack_1a4 = pfVar12[3];
              *pfVar12 = 0.0;
              fVar2 = *pfVar12;
              puVar4[1] = 0;
              *puVar4 = 0;
              puVar4[2] = 0;
              puVar4[-1] = 0;
              puVar4[-3] = 0;
              puVar4[-2] = 0;
              if (fVar1 <= fVar2) {
                if (fStack_1a4 < *pfVar12) {
                  *pfVar12 = fStack_1a4;
                }
              }
              else {
                *pfVar12 = fVar1;
              }
              fStack_1b4 = pfVar12[0x93];
              pfVar12[0x90] = 0.0;
              if (pfVar12[0x92] <= pfVar12[0x90]) {
                if (fStack_1b4 < pfVar12[0x90]) {
                  pfVar12[0x90] = fStack_1b4;
                }
              }
              else {
                pfVar12[0x90] = pfVar12[0x92];
              }
              fStack_1b0 = pfVar12[0x123];
              pfVar12[0x120] = 0.0;
              if (pfVar12[0x122] <= pfVar12[0x120]) {
                if (fStack_1b0 < pfVar12[0x120]) {
                  pfVar12[0x120] = fStack_1b0;
                }
              }
              else {
                pfVar12[0x120] = pfVar12[0x122];
              }
              fStack_1a8 = pfVar12[0x1b3];
              pfVar12[0x1b0] = 0.0;
              if (pfVar12[0x1b2] <= pfVar12[0x1b0]) {
                if (fStack_1a8 < pfVar12[0x1b0]) {
                  pfVar12[0x1b0] = fStack_1a8;
                }
              }
              else {
                pfVar12[0x1b0] = pfVar12[0x1b2];
              }
            }
            local_1c4 = local_1c4 + 1;
            puVar4 = puVar4 + 6;
            pfVar12 = pfVar12 + 9;
            iStack_1b8 = iStack_1b8 + -1;
          } while (iStack_1b8 != 0);
          uVar7 = 0;
          do {
            if (uVar7 == 0) {
              auStack_17c[0] = 1;
            }
            else {
              auStack_17c[uVar7] = 0;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 8);
          iVar8 = *param_1;
          param_1[iVar9 * 0x1a + 4] = -1;
          param_1[iVar9 * 0x1a + 7] = -1;
          *local_1bc = iVar8 + 0x1184;
          param_1[iVar9 * 0x1a + 2] = 0x38;
          param_1[iVar9 * 0x1a + 3] = 0x11;
          param_1[iVar9 * 0x1a + 5] = 0;
          param_1[iVar9 * 0x1a + 6] = 10000;
          param_1[iVar9 * 0x1a + 8] = 0;
          param_1[iVar9 * 0x1a + 9] = param_1[0x146];
          param_1[iVar9 * 0x1a + 0xc] = 0;
          param_1[iVar9 * 0x1a + 10] = (int)(param_1 + 0x148);
          param_1[iVar9 * 0x1a + 0xb] = (int)auStack_17c;
          param_1[iVar9 * 0x1a + 0xd] = param_1[0x147] * 0x18;
          param_1[iVar9 * 0x1a + 0xe] = (int)local_13c;
          param_1[iVar9 * 0x1a + 0xf] = 0;
          uStack_1d8 = DAT_005ad380;
          uStack_1d4 = DAT_005ad384;
          uStack_1d0 = DAT_005ad388;
          uStack_1cc = DAT_005ad38c;
          iStack_1b8 = 0;
          piVar10 = local_1bc;
        }
        break;
      case 5:
        if ((_DAT_007d2284 == DAT_0059e440) ||
           ((((_DAT_007d22a8 == DAT_0059e440 && (_DAT_007d22cc == DAT_0059e440)) ||
             (param_1[0x13c] == 0)) || (DAT_007d1ffc < 4)))) goto LAB_004514b0;
        *piVar10 = param_1[0x13c];
        param_1[0x123] = 0;
        param_1[0x124] = 0;
        param_1[0x125] = 0;
        param_1[0x126] = 0;
        param_1[local_1c0 * 0x1a + 4] = -1;
        param_1[local_1c0 * 0x1a + 7] = -1;
        param_1[local_1c0 * 0x1a + 10] = (int)(param_1 + 0x144);
        param_1[local_1c0 * 0x1a + 2] = 0x38;
        param_1[local_1c0 * 0x1a + 3] = 0x12;
        param_1[local_1c0 * 0x1a + 5] = 0;
        param_1[local_1c0 * 0x1a + 6] = 10000;
        param_1[local_1c0 * 0x1a + 8] = 0;
        param_1[local_1c0 * 0x1a + 9] = 1;
        param_1[local_1c0 * 0x1a + 0xb] = (int)(param_1 + 0x140);
        param_1[local_1c0 * 0x1a + 0xc] = 0;
        param_1[local_1c0 * 0x1a + 0xd] = 0x10;
        param_1[local_1c0 * 0x1a + 0xe] = (int)(param_1 + 0x123);
        param_1[local_1c0 * 0x1a + 0xf] = 0;
        switch(DAT_007d22f0) {
        case 0:
switchD_00451198_caseD_0:
          uStack_1d8 = DAT_005ad3c0;
          uStack_1d4 = DAT_005ad3c4;
          uStack_1d0 = DAT_005ad3c8;
          uStack_1cc = DAT_005ad3cc;
          break;
        case 1:
switchD_00451198_caseD_1:
          uStack_1d8 = DAT_005ad3d0;
          uStack_1d4 = DAT_005ad3d4;
          uStack_1d0 = DAT_005ad3d8;
          uStack_1cc = DAT_005ad3dc;
          break;
        case 2:
switchD_00451198_caseD_2:
          uStack_1d8 = DAT_005ad3b0;
          uStack_1d4 = DAT_005ad3b4;
          uStack_1d0 = DAT_005ad3b8;
          uStack_1cc = DAT_005ad3bc;
          break;
        case 3:
switchD_00451198_caseD_3:
          uStack_1d8 = DAT_005ad3a0;
          uStack_1d4 = DAT_005ad3a4;
          uStack_1d0 = DAT_005ad3a8;
          uStack_1cc = DAT_005ad3ac;
          break;
        case 4:
switchD_00451198_caseD_4:
          uStack_1d8 = DAT_005ad390;
          uStack_1d4 = DAT_005ad394;
          uStack_1d0 = DAT_005ad398;
          uStack_1cc = DAT_005ad39c;
          break;
        default:
          goto switchD_004513db_caseD_0;
        }
        break;
      case 6:
        if ((((_DAT_007d2338 == DAT_0059e440) ||
             ((_DAT_007d235c == DAT_0059e440 && (_DAT_007d2380 == DAT_0059e440)))) ||
            (param_1[0x13d] == 0)) || (DAT_007d1ffc < 3)) goto LAB_004514b0;
        *piVar10 = param_1[0x13d];
        param_1[0x127] = 0;
        param_1[0x128] = 0;
        param_1[0x129] = 0;
        param_1[0x12a] = 0;
        param_1[local_1c0 * 0x1a + 4] = -1;
        param_1[local_1c0 * 0x1a + 7] = -1;
        param_1[local_1c0 * 0x1a + 10] = (int)(param_1 + 0x145);
        param_1[local_1c0 * 0x1a + 2] = 0x38;
        param_1[local_1c0 * 0x1a + 3] = 0x12;
        param_1[local_1c0 * 0x1a + 5] = 0;
        param_1[local_1c0 * 0x1a + 6] = 10000;
        param_1[local_1c0 * 0x1a + 8] = 0;
        param_1[local_1c0 * 0x1a + 9] = 1;
        param_1[local_1c0 * 0x1a + 0xb] = (int)(param_1 + 0x141);
        param_1[local_1c0 * 0x1a + 0xc] = 0;
        param_1[local_1c0 * 0x1a + 0xd] = 0x10;
        param_1[local_1c0 * 0x1a + 0xe] = (int)(param_1 + 0x127);
        param_1[local_1c0 * 0x1a + 0xf] = 0;
        switch(DAT_007d23a4) {
        case 0:
          goto switchD_00451198_caseD_0;
        case 1:
          goto switchD_00451198_caseD_1;
        case 2:
          goto switchD_00451198_caseD_2;
        case 3:
          goto switchD_00451198_caseD_3;
        case 4:
          goto switchD_00451198_caseD_4;
        }
switchD_004513db_caseD_0:
        uStack_1d8 = DAT_005ad3c0;
        uStack_1d4 = DAT_005ad3c4;
        uStack_1d0 = DAT_005ad3c8;
        uStack_1cc = DAT_005ad3cc;
        break;
      case 7:
        if ((_DAT_007d24a0 == DAT_0059e440) ||
           (((iVar8 = param_1[0x13a], iVar8 == 0 && (param_1[0x13d] == 0)) || (DAT_007d1ffc < 2))))
        goto LAB_004514b0;
        if (DAT_007d1fd8 == 3) {
          if (iVar8 == 0) goto LAB_0045120c;
          iVar11 = 2;
          iStack_15c = 0;
          iStack_158 = 4;
          auStack_17c[1] = 1;
LAB_00451285:
          *piVar10 = iVar8;
        }
        else {
          if (iVar8 != 0) {
            if (((param_1[0x13d] == 0) || (DAT_007d2068 != 0)) || (param_1[0x13d] != iVar8)) {
              iStack_15c = param_1[0x142];
              iVar11 = 1;
            }
            else {
              iStack_15c = param_1[0x142];
              iStack_158 = param_1[0x145];
              iVar11 = 2;
              auStack_17c[1] = 1;
            }
            goto LAB_00451285;
          }
LAB_0045120c:
          iStack_15c = param_1[0x145];
          iVar11 = 1;
          *piVar10 = param_1[0x13d];
        }
        auStack_17c[0] = 1;
        bVar13 = DAT_007d1fd8 == 3;
        param_1[local_1c0 * 0x1a + 0x17] = 100000;
        param_1[local_1c0 * 0x1a + 0x16] = 0;
        param_1[local_1c0 * 0x1a + 0x15] = 0;
        param_1[local_1c0 * 0x1a + 0x14] = 10000;
        param_1[local_1c0 * 0x1a + 0x13] = 0x14;
        if (bVar13) {
          param_1[local_1c0 * 0x1a + 4] = 300000;
        }
        else {
          param_1[local_1c0 * 0x1a + 4] = 150000;
        }
        param_1[299] = 0;
        param_1[local_1c0 * 0x1a + 9] = iVar11;
        param_1[local_1c0 * 0x1a + 10] = (int)&iStack_15c;
        param_1[local_1c0 * 0x1a + 2] = 0x38;
        param_1[local_1c0 * 0x1a + 3] = 0x12;
        param_1[local_1c0 * 0x1a + 5] = 0;
        param_1[local_1c0 * 0x1a + 6] = 10000;
        param_1[local_1c0 * 0x1a + 7] = -1;
        param_1[local_1c0 * 0x1a + 8] = 0;
        param_1[local_1c0 * 0x1a + 0xb] = (int)auStack_17c;
        param_1[local_1c0 * 0x1a + 0xc] = (int)(param_1 + local_1c0 * 0x1a + 0x13);
        param_1[local_1c0 * 0x1a + 0xd] = 4;
        param_1[local_1c0 * 0x1a + 0xe] = (int)(param_1 + 299);
        param_1[local_1c0 * 0x1a + 0xf] = 0;
        uStack_1d8 = DAT_005ad3e0;
        uStack_1d4 = DAT_005ad3e4;
        uStack_1d0 = DAT_005ad3e8;
        uStack_1cc = DAT_005ad3ec;
        break;
      case 8:
        if ((_DAT_007d23ec != DAT_0059e440) && (1 < DAT_007d1ffc)) {
          *piVar10 = param_1[0x13a];
          param_1[300] = 0;
          param_1[0x12d] = 0;
          param_1[0x12e] = 0;
          param_1[0x12f] = 0;
          param_1[local_1c0 * 0x1a + 4] = -1;
          param_1[local_1c0 * 0x1a + 7] = -1;
          param_1[local_1c0 * 0x1a + 10] = (int)(param_1 + 0x142);
          param_1[local_1c0 * 0x1a + 2] = 0x38;
          param_1[local_1c0 * 0x1a + 3] = 0x12;
          param_1[local_1c0 * 0x1a + 5] = 0;
          param_1[local_1c0 * 0x1a + 6] = 10000;
          param_1[local_1c0 * 0x1a + 8] = 0;
          param_1[local_1c0 * 0x1a + 9] = 1;
          param_1[local_1c0 * 0x1a + 0xb] = (int)(param_1 + 0x13e);
          param_1[local_1c0 * 0x1a + 0xc] = 0;
          param_1[local_1c0 * 0x1a + 0xd] = 0x10;
          param_1[local_1c0 * 0x1a + 0xe] = (int)(param_1 + 300);
          param_1[local_1c0 * 0x1a + 0xf] = 0;
          switch(DAT_007d2434) {
          case 0:
            goto switchD_004513db_caseD_0;
          case 1:
            goto switchD_004513db_caseD_1;
          case 2:
            goto switchD_004513db_caseD_2;
          case 3:
            goto switchD_004513db_caseD_3;
          case 4:
            goto switchD_004513db_caseD_4;
          default:
            goto switchD_004513db_default;
          }
        }
        goto LAB_004514b0;
      }
      if (((*piVar10 != 0) && (piVar5 = *(int **)(*piVar10 + 0x80), piVar5 != (int *)0x0)) &&
         ((iVar8 = (**(code **)(*piVar5 + 0x48))
                             (piVar5,&uStack_1d8,param_1 + iVar9 * 0x1a + 2,
                              param_1 + iVar9 * 0x1a + 0x19,0), -1 < iVar8 &&
          (param_1[iVar9 * 0x1a + 0x19] != 0)))) {
        iVar8 = *piVar10;
        if (((iVar8 == *param_1 + 0xd88) && (local_1c5 == '\0')) ||
           ((iVar8 == *param_1 + 0x1184 && (local_1c6 == '\0')))) {
          (**(code **)(**(int **)(iVar8 + 0x80) + 0x20))(*(int **)(iVar8 + 0x80));
          afStack_19c[0] = 2.8026e-44;
          afStack_19c[1] = 2.24208e-44;
          afStack_19c[2] = 0.0;
          afStack_19c[3] = 0.0;
          afStack_19c[4] = (float)__ftol();
          (**(code **)(**(int **)(*piVar10 + 0x80) + 0x18))
                    (*(int **)(*piVar10 + 0x80),7,afStack_19c);
          fStack_1a8 = 2.8026e-44;
          fStack_1a4 = 2.24208e-44;
          fStack_1a0 = 0.0;
          afStack_19c[0] = 0.0;
          afStack_19c[1] = 0.0;
          iVar8 = (**(code **)(**(int **)(*piVar10 + 0x80) + 0x18))
                            (*(int **)(*piVar10 + 0x80),9,&fStack_1a8);
          if (-1 < iVar8) {
            iVar8 = *piVar10;
            if (iVar8 == *param_1 + 0xd88) {
              local_1c5 = '\x01';
            }
            else if (iVar8 == *param_1 + 0x1184) {
              local_1c6 = '\x01';
            }
            (**(code **)(**(int **)(iVar8 + 0x80) + 0x1c))(*(int **)(iVar8 + 0x80));
          }
        }
        if (((*piVar10 == *param_1 + 0xd88) && (local_1c5 != '\0')) ||
           ((*piVar10 == *param_1 + 0x1184 && (local_1c6 != '\0')))) {
          (**(code **)(*(int *)param_1[iVar9 * 0x1a + 0x19] + 0x28))
                    ((int *)param_1[iVar9 * 0x1a + 0x19]);
          if (local_1c0 == 7) {
            *(undefined1 *)(param_1 + 0xb7) = 1;
          }
          else {
            iVar8 = (**(code **)(*(int *)param_1[iVar9 * 0x1a + 0x19] + 0x1c))
                              ((int *)param_1[iVar9 * 0x1a + 0x19],0xffffffff,0);
            if (iVar8 < 0) goto LAB_0045162a;
            *(undefined1 *)(param_1 + iVar9 * 0x1a + 1) = 1;
          }
          param_1[0x105] = 1;
        }
      }
LAB_0045162a:
      local_1c0 = iStack_180;
    } while (iStack_180 < 10);
  }
  param_1[0x130] = (int)(_DAT_0059ef58 / _DAT_007d208c);
  param_1[0x131] = (int)(_DAT_0059ef58 / _DAT_007d2284);
  param_1[0x132] = (int)(_DAT_0059ef58 / _DAT_007d2338);
  fVar1 = _DAT_0059ef58 / _DAT_007d2410;
  param_1[0x134] = 0;
  param_1[0x135] = 0;
  *(undefined1 *)(param_1 + 0x106) = 0;
  param_1[0x133] = (int)fVar1;
  return;
}


