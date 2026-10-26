// Function: FUN_0056d930 @ 0056d930
// Strings:  [VWh\R^, VWh\R^, VWh\R^, negbody, posbody, inertia, [JOINT&HINGE], [JOINT&HINGE]]


undefined4 __thiscall FUN_0056d930(int *param_1,char *param_2)

{
  double dVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  void *pvVar11;
  int iVar12;
  uint uVar13;
  char *pcVar14;
  char *pcVar15;
  undefined4 *puVar16;
  double *pdVar17;
  int iVar18;
  undefined4 *puVar19;
  bool bVar20;
  char *pcVar21;
  char *local_638;
  int local_630;
  int local_628;
  int local_624;
  int local_620;
  undefined4 local_610;
  undefined4 local_60c;
  undefined4 local_608;
  undefined4 local_604;
  undefined4 local_600;
  undefined4 local_5fc;
  undefined4 local_5f8;
  undefined4 local_5f4;
  undefined4 local_5f0 [2];
  undefined1 local_5e8 [8];
  undefined1 local_5e0 [8];
  undefined4 local_5d8 [2];
  undefined1 local_5d0 [8];
  undefined1 local_5c8 [8];
  double local_5c0 [3];
  char local_5a8 [64];
  undefined4 local_568 [2];
  double local_560;
  double local_558;
  undefined4 local_550 [2];
  undefined1 local_548 [8];
  undefined1 local_540 [8];
  double local_538;
  double local_530;
  double local_528;
  undefined4 local_520 [2];
  undefined1 local_518 [8];
  undefined1 local_510 [8];
  undefined4 local_508 [2];
  undefined1 local_500 [8];
  undefined1 local_4f8 [8];
  undefined4 local_4f0 [2];
  undefined1 local_4e8 [8];
  undefined1 local_4e0 [8];
  char local_4d8 [64];
  undefined1 local_498 [64];
  char local_458 [448];
  undefined4 local_298;
  undefined1 local_294;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_280 [96];
  undefined1 local_100 [256];
  
  puVar16 = local_280;
  for (iVar12 = 0x60; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar16 = 0;
    puVar16 = puVar16 + 1;
  }
  local_298 = 0;
  local_284 = 0;
  local_28c = 0;
  local_288 = 0;
  local_294 = 1;
  FUN_0056e970();
  FUN_0058986e(s_p_pmodel_error_txt_005e5246 + 2);
  iVar12 = FUN_00534b00();
  if (iVar12 == 0) {
    pcVar21 = s_Could_not_open__s_005e5360;
    local_638 = param_2;
LAB_0056e944:
    FUN_0058815f(local_100,pcVar21,local_638);
    FUN_0056d8f0();
    return 0xffffffff;
  }
  *param_1 = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  iVar12 = FUN_005351d0(0x180);
  while (iVar12 != 0) {
    iVar12 = FUN_005651b0();
    if (iVar12 == 0) {
      iVar12 = FUN_00587c20(local_280,s__BODY__005e5358);
      if (iVar12 != 0) {
        *param_1 = *param_1 + 1;
      }
      iVar12 = FUN_00587c20(local_280,s__JOINT__005e5350);
      if (iVar12 != 0) {
        param_1[2] = param_1[2] + 1;
      }
      iVar12 = FUN_00587c20(local_280,s__HINGE__005e5348);
      if (iVar12 != 0) {
        param_1[4] = param_1[4] + 1;
      }
      iVar12 = FUN_00587c20(local_280,s__BAR__005e5340);
      if (iVar12 != 0) {
        param_1[6] = param_1[6] + 1;
      }
      iVar12 = FUN_00587c20(local_280,s__JOINT_HINGE__005e5330);
      if (iVar12 != 0) {
        param_1[2] = param_1[2] + 1;
        param_1[4] = param_1[4] + 1;
      }
    }
    iVar12 = FUN_005351d0(0x180);
  }
  iVar12 = *param_1;
  piVar3 = operator_new(iVar12 * 0x244 + 4);
  if (piVar3 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = piVar3 + 1;
    *piVar3 = iVar12;
    if (-1 < iVar12 + -1) {
      do {
        FUN_00568e30();
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
  }
  iVar12 = param_1[2];
  param_1[1] = (int)piVar4;
  piVar3 = operator_new(iVar12 * 0x30 + 4);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = iVar12;
    piVar3 = piVar3 + 1;
    piVar4 = piVar3;
    if (-1 < iVar12 + -1) {
      do {
        *piVar4 = 0;
        iVar12 = iVar12 + -1;
        piVar4 = piVar4 + 0xc;
      } while (iVar12 != 0);
    }
  }
  iVar12 = param_1[4];
  param_1[3] = (int)piVar3;
  piVar3 = operator_new(iVar12 * 0x30 + 4);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = iVar12;
    piVar3 = piVar3 + 1;
    piVar4 = piVar3;
    if (-1 < iVar12 + -1) {
      do {
        *piVar4 = 0;
        iVar12 = iVar12 + -1;
        piVar4 = piVar4 + 0xc;
      } while (iVar12 != 0);
    }
  }
  iVar12 = param_1[6];
  param_1[5] = (int)piVar3;
  piVar3 = operator_new(iVar12 * 0x48 + 4);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = iVar12;
    piVar3 = piVar3 + 1;
    piVar4 = piVar3;
    if (-1 < iVar12 + -1) {
      do {
        *piVar4 = 0;
        iVar12 = iVar12 + -1;
        piVar4 = piVar4 + 0x12;
      } while (iVar12 != 0);
    }
  }
  param_1[7] = (int)piVar3;
  local_638 = (char *)0x0;
  local_624 = 0;
  FUN_00535390(0);
  iVar12 = FUN_005351d0(0x180);
  if (iVar12 != 0) {
    local_630 = 0;
    local_628 = 0;
    iVar12 = 0;
    local_620 = 0;
    do {
      iVar5 = FUN_005651b0();
      if (iVar5 == 0) {
        iVar5 = FUN_00587c20(local_280,s__BODY__005e5358);
        if (iVar5 == 0) {
          iVar5 = FUN_00587c20(local_280,s__JOINT__005e5350);
          if ((((iVar5 != 0) || (iVar5 = FUN_00587c20(local_280,s__HINGE__005e5348), iVar5 != 0)) ||
              (iVar5 = FUN_00587c20(local_280,s__BAR__005e5340), iVar5 != 0)) ||
             (iVar5 = FUN_00587c20(local_280,s__JOINT_HINGE__005e5330), iVar5 != 0)) {
            iVar5 = FUN_00587c20(local_280,s__JOINT__005e5350);
            iVar18 = FUN_00587c20(local_280,s__HINGE__005e5348);
            iVar6 = FUN_00587c20(local_280,s__BAR__005e5340);
            iVar7 = FUN_00587c20(local_280,s__JOINT_HINGE__005e5330);
            bVar20 = iVar7 != 0;
            puVar16 = local_5d8;
            for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar16 = 0;
              puVar16 = puVar16 + 1;
            }
            puVar16 = local_5f0;
            for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar16 = 0;
              puVar16 = puVar16 + 1;
            }
            local_5a8[0] = '\0';
            local_498[0] = 0;
            local_458[0] = '\0';
            local_4d8[0] = '\0';
            iVar7 = FUN_005351d0(0x180);
            while (iVar7 != 0) {
              iVar7 = FUN_005651b0();
              if (iVar7 == 0) {
                iVar7 = FUN_00565520(&DAT_005e5328,local_5a8,0);
                if (iVar7 != 0) {
                  FUN_00589901(local_5a8);
                }
                FUN_00565520(s_posbody_005e5300,local_498,0);
                FUN_00565520(s_negbody_005e52f8,local_458,0);
                FUN_00565aa0(&DAT_005e52f0,local_5d8,local_5d0,local_5c8,0);
                FUN_00565aa0(&PTR_DAT_005e52ec,local_508,local_500,local_4f8,0);
                local_294 = 0;
                iVar7 = FUN_00565aa0(&PTR_DAT_005e5314,local_4f0,local_4e8,local_4e0,0);
                if (iVar7 == 0) {
                  FUN_00565520(&PTR_DAT_005e5314,local_4d8,0);
                  local_294 = 1;
                }
                else {
                  puVar16 = local_4f0;
                  puVar19 = local_5f0;
                  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *puVar19 = *puVar16;
                    puVar16 = puVar16 + 1;
                    puVar19 = puVar19 + 1;
                  }
                  local_294 = 1;
                }
              }
              else if (iVar7 == 1) break;
              iVar7 = FUN_005351d0(0x180);
            }
            if (local_4d8[0] != '\0') {
              pcVar21 = (char *)0x0;
              if (0 < local_620) {
                iVar7 = 0;
                do {
                  iVar8 = FUN_00588410(local_4d8,*(undefined4 *)(iVar7 + param_1[1]));
                  if (iVar8 == 0) break;
                  pcVar21 = pcVar21 + 1;
                  iVar7 = iVar7 + 0x244;
                } while ((int)pcVar21 < (int)local_638);
              }
              if (pcVar21 == local_638) {
                FUN_0058815f(local_100,s_Invalid_copy_body_name___s__in_h_005e528c,local_4d8);
                FUN_0056d8f0();
                return 0xffffffff;
              }
              puVar16 = (undefined4 *)((int)pcVar21 * 0x244 + 4 + param_1[1]);
              puVar19 = local_5f0;
              for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar19 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar19 = puVar19 + 1;
              }
            }
            pcVar21 = (char *)0x0;
            if (0 < local_620) {
              iVar7 = 0;
              do {
                iVar8 = FUN_00588410(local_498,*(undefined4 *)(iVar7 + param_1[1]));
                if (iVar8 == 0) break;
                pcVar21 = pcVar21 + 1;
                iVar7 = iVar7 + 0x244;
              } while ((int)pcVar21 < (int)local_638);
            }
            if (pcVar21 == local_638) {
              FUN_0058815f(local_100,s_Invalid_body_name___s__in_hinge_o_005e5260,local_498);
              FUN_0056d8f0();
              return 0xffffffff;
            }
            if (bVar20 || iVar5 != 0) {
              *(int *)(param_1[3] + 4 + iVar12) = param_1[1] + (int)pcVar21 * 0x244;
              piVar3 = (int *)(param_1[1] + (int)pcVar21 * 0x244 + 0x22c);
              *piVar3 = *piVar3 + 1;
            }
            if (bVar20 || iVar18 != 0) {
              *(int *)(param_1[5] + 4 + local_628) = param_1[1] + (int)pcVar21 * 0x244;
              piVar3 = (int *)(param_1[1] + (int)pcVar21 * 0x244 + 0x234);
              *piVar3 = *piVar3 + 1;
            }
            if (iVar6 != 0) {
              iVar7 = (int)pcVar21 * 0x244;
              *(int *)(local_630 + 4 + param_1[7]) = param_1[1] + iVar7;
              *(int *)(param_1[1] + iVar7 + 0x23c) = *(int *)(param_1[1] + 0x23c + iVar7) + 1;
            }
            pcVar21 = (char *)0x0;
            if (0 < local_620) {
              iVar7 = 0;
              do {
                iVar8 = FUN_00588410(local_458,*(undefined4 *)(iVar7 + param_1[1]));
                if (iVar8 == 0) break;
                pcVar21 = pcVar21 + 1;
                iVar7 = iVar7 + 0x244;
              } while ((int)pcVar21 < (int)local_638);
            }
            if (pcVar21 == local_638) {
              local_638 = local_458;
              pcVar21 = s_Invalid_body_name___s__in_hinge_o_005e5260;
              goto LAB_0056e944;
            }
            if (bVar20 || iVar5 != 0) {
              iVar5 = (int)pcVar21 * 0x244;
              *(int *)(param_1[3] + 0xc + iVar12) = param_1[1] + iVar5;
              *(int *)(param_1[1] + iVar5 + 0x22c) = *(int *)(param_1[1] + 0x22c + iVar5) + 1;
              if (local_5a8[0] != '\0') {
                uVar13 = 0xffffffff;
                pcVar14 = local_5a8;
                do {
                  if (uVar13 == 0) break;
                  uVar13 = uVar13 - 1;
                  cVar2 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                } while (cVar2 != '\0');
                pvVar11 = operator_new(~uVar13);
                *(void **)(iVar12 + param_1[3]) = pvVar11;
                pcVar15 = *(char **)(iVar12 + param_1[3]);
                pcVar14 = local_5a8;
                do {
                  cVar2 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  *pcVar15 = cVar2;
                  pcVar15 = pcVar15 + 1;
                } while (cVar2 != '\0');
              }
              puVar16 = local_5f0;
              puVar19 = (undefined4 *)(param_1[3] + 0x14 + iVar12);
              for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar19 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar19 = puVar19 + 1;
              }
              *(int *)(param_1[3] + 0x2c + iVar12) = local_624;
              local_624 = local_624 + 1;
              iVar12 = iVar12 + 0x30;
            }
            if (bVar20 || iVar18 != 0) {
              iVar5 = (int)pcVar21 * 0x244;
              *(int *)(param_1[5] + 0xc + local_628) = param_1[1] + iVar5;
              *(int *)(param_1[1] + iVar5 + 0x234) = *(int *)(param_1[1] + 0x234 + iVar5) + 1;
              if (local_5a8[0] != '\0') {
                uVar13 = 0xffffffff;
                pcVar14 = local_5a8;
                do {
                  if (uVar13 == 0) break;
                  uVar13 = uVar13 - 1;
                  cVar2 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                } while (cVar2 != '\0');
                pvVar11 = operator_new(~uVar13);
                *(void **)(local_628 + param_1[5]) = pvVar11;
                pcVar15 = *(char **)(local_628 + param_1[5]);
                pcVar14 = local_5a8;
                do {
                  cVar2 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  *pcVar15 = cVar2;
                  pcVar15 = pcVar15 + 1;
                } while (cVar2 != '\0');
              }
              puVar16 = local_5d8;
              puVar19 = (undefined4 *)(param_1[5] + 0x14 + local_628);
              for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar19 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar19 = puVar19 + 1;
              }
              *(int *)(param_1[5] + 0x2c + local_628) = local_624;
              local_624 = local_624 + 1;
              local_628 = local_628 + 0x30;
            }
            if (iVar6 != 0) {
              iVar5 = (int)pcVar21 * 0x244;
              *(int *)(local_630 + 0xc + param_1[7]) = param_1[1] + iVar5;
              *(int *)(param_1[1] + iVar5 + 0x23c) = *(int *)(param_1[1] + 0x23c + iVar5) + 1;
              if (local_5a8[0] != '\0') {
                uVar13 = 0xffffffff;
                pcVar21 = local_5a8;
                do {
                  if (uVar13 == 0) break;
                  uVar13 = uVar13 - 1;
                  cVar2 = *pcVar21;
                  pcVar21 = pcVar21 + 1;
                } while (cVar2 != '\0');
                pvVar11 = operator_new(~uVar13);
                *(void **)(local_630 + param_1[7]) = pvVar11;
                pcVar14 = *(char **)(local_630 + param_1[7]);
                pcVar21 = local_5a8;
                do {
                  cVar2 = *pcVar21;
                  pcVar21 = pcVar21 + 1;
                  *pcVar14 = cVar2;
                  pcVar14 = pcVar14 + 1;
                } while (cVar2 != '\0');
              }
              puVar16 = local_5f0;
              puVar19 = (undefined4 *)(local_630 + 0x14 + param_1[7]);
              for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar19 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar19 = puVar19 + 1;
              }
              puVar16 = local_508;
              puVar19 = (undefined4 *)(local_630 + 0x2c + param_1[7]);
              for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar19 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar19 = puVar19 + 1;
              }
              *(int *)(local_630 + 0x44 + param_1[7]) = local_624;
              local_624 = local_624 + 1;
              local_630 = local_630 + 0x48;
            }
          }
        }
        else {
          puVar16 = local_550;
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar16 = 0;
            puVar16 = puVar16 + 1;
          }
          puVar16 = local_520;
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar16 = 0;
            puVar16 = puVar16 + 1;
          }
          local_608 = 0;
          puVar16 = local_5d8;
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar16 = 0;
            puVar16 = puVar16 + 1;
          }
          local_604 = 0x3ff00000;
          puVar16 = local_5f0;
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar16 = 0;
            puVar16 = puVar16 + 1;
          }
          local_600 = 0;
          local_5fc = 0x3ff00000;
          local_5f8 = 0;
          local_5f4 = 0x3ff00000;
          local_5a8[0] = '\0';
          local_610 = 0;
          local_60c = 0x3ff00000;
          iVar5 = FUN_005351d0(0x180);
          while (iVar5 != 0) {
            iVar5 = FUN_005651b0();
            if (iVar5 == 0) {
              iVar5 = FUN_00565520(&DAT_005e5328,local_5a8,0);
              if (iVar5 != 0) {
                FUN_00589901(local_5a8);
              }
              FUN_00565aa0(&DAT_005e5320,&local_610,0,0,0);
              FUN_00565aa0(s_inertia_005e5318,&local_608,&local_600,&local_5f8,0);
              FUN_00565aa0(&PTR_DAT_005e5314,local_5f0,local_5e8,local_5e0,0);
              FUN_00565aa0(&PTR_DAT_005e5310,local_5d8,local_5d0,local_5c8,0);
              FUN_00565aa0(&PTR_DAT_005e530c,local_520,local_518,local_510,0);
              FUN_00565aa0(&PTR_DAT_005e5308,local_550,local_548,local_540,0);
            }
            else if (iVar5 == 1) break;
            iVar5 = FUN_005351d0(0x180);
          }
          if (local_5a8[0] == '\0') {
            pcVar21 = s_Body__d_must_be_named_005e52d4;
            goto LAB_0056e944;
          }
          iVar5 = 0;
          if (0 < local_620) {
            iVar18 = 0;
            do {
              iVar6 = FUN_00588410(*(undefined4 *)(iVar18 + param_1[1]),local_5a8);
              if (iVar6 == 0) {
                if (iVar5 < (int)local_638) {
                  local_638 = local_5a8;
                  pcVar21 = s_Two_bodies_named___s__005e52bc;
                  goto LAB_0056e944;
                }
                break;
              }
              iVar5 = iVar5 + 1;
              iVar18 = iVar18 + 0x244;
            } while (iVar5 < (int)local_638);
          }
          FUN_00568e70(local_5a8,local_610,local_60c,&local_608);
          puVar16 = local_5f0;
          puVar19 = (undefined4 *)(param_1[1] + 4 + local_620);
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar19 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar19 = puVar19 + 1;
          }
          FUN_005691d0(local_5d8);
          puVar16 = local_520;
          puVar19 = (undefined4 *)(param_1[1] + 100 + local_620);
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar19 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar19 = puVar19 + 1;
          }
          FUN_00569280(local_550);
          local_638 = local_638 + 1;
          local_620 = local_620 + 0x244;
        }
      }
      iVar5 = FUN_005351d0(0x180);
    } while (iVar5 != 0);
  }
  iVar12 = 0;
  if (0 < *param_1) {
    do {
      FUN_005697f0();
      iVar12 = iVar12 + 1;
    } while (iVar12 < *param_1);
  }
  iVar12 = FUN_0056d430();
  param_1[8] = iVar12;
  local_638 = (char *)0x0;
  if (0 < param_1[2]) {
    local_630 = 0;
    do {
      iVar5 = param_1[3] + local_630;
      puVar16 = (undefined4 *)(iVar5 + 0x14);
      pdVar17 = local_5c0;
      for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
        *(undefined4 *)pdVar17 = *puVar16;
        puVar16 = puVar16 + 1;
        pdVar17 = (double *)((int)pdVar17 + 4);
      }
      uVar10 = *(undefined4 *)(iVar5 + 0x2c);
      uVar9 = FUN_00569860(local_5c0,uVar10,1);
      *(undefined4 *)(iVar5 + 8) = uVar9;
      uVar10 = FUN_00569860(local_5c0,uVar10,0);
      *(undefined4 *)(iVar5 + 0x10) = uVar10;
      *(undefined4 *)(iVar5 + 0x2c) = 0;
      FUN_0056cf70();
      local_638 = (char *)((int)local_638 + 1);
      local_630 = local_630 + 0x30;
    } while ((int)local_638 < param_1[2]);
  }
  local_638 = (char *)0x0;
  if (0 < param_1[4]) {
    local_630 = 0;
    do {
      iVar5 = param_1[5] + local_630;
      puVar16 = (undefined4 *)(iVar5 + 0x14);
      pdVar17 = local_5c0;
      for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
        *(undefined4 *)pdVar17 = *puVar16;
        puVar16 = puVar16 + 1;
        pdVar17 = (double *)((int)pdVar17 + 4);
      }
      uVar10 = *(undefined4 *)(iVar5 + 0x2c);
      uVar9 = FUN_005698e0(local_5c0,uVar10,1,iVar5);
      *(undefined4 *)(iVar5 + 8) = uVar9;
      uVar10 = FUN_005698e0(local_5c0,uVar10,0,iVar5);
      *(undefined4 *)(iVar5 + 0x10) = uVar10;
      *(undefined4 *)(iVar5 + 0x2c) = 0;
      FUN_0056d020();
      local_638 = (char *)((int)local_638 + 1);
      local_630 = local_630 + 0x30;
    } while ((int)local_638 < param_1[4]);
  }
  local_638 = (char *)0x0;
  if (0 < param_1[6]) {
    local_630 = 0;
    do {
      iVar5 = param_1[7] + local_630;
      puVar16 = (undefined4 *)(iVar5 + 0x14);
      pdVar17 = local_5c0;
      for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
        *(undefined4 *)pdVar17 = *puVar16;
        puVar16 = puVar16 + 1;
        pdVar17 = (double *)((int)pdVar17 + 4);
      }
      puVar16 = (undefined4 *)(iVar5 + 0x2c);
      pdVar17 = &local_538;
      for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
        *(undefined4 *)pdVar17 = *puVar16;
        puVar16 = puVar16 + 1;
        pdVar17 = (double *)((int)pdVar17 + 4);
      }
      dVar1 = local_5c0[0] - local_538;
      pdVar17 = local_5c0;
      puVar16 = local_568;
      for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar16 = *(undefined4 *)pdVar17;
        pdVar17 = (double *)((int)pdVar17 + 4);
        puVar16 = puVar16 + 1;
      }
      local_560 = local_560 - local_530;
      local_558 = local_558 - local_528;
      uVar10 = *(undefined4 *)(iVar5 + 0x44);
      dVar1 = SQRT(dVar1 * dVar1 + local_560 * local_560 + local_558 * local_558);
      uVar9 = FUN_00569990(local_5c0,uVar10,1,dVar1);
      *(undefined4 *)(iVar5 + 8) = uVar9;
      uVar10 = FUN_00569990(&local_538,uVar10,0,dVar1);
      *(undefined4 *)(iVar5 + 0x10) = uVar10;
      *(undefined4 *)(iVar5 + 0x44) = 0;
      FUN_0056d2d0();
      local_638 = (char *)((int)local_638 + 1);
      local_630 = local_630 + 0x48;
    } while ((int)local_638 < param_1[6]);
  }
  pvVar11 = operator_new(param_1[8] << 2);
  param_1[10] = (int)pvVar11;
  pvVar11 = operator_new(param_1[8] * param_1[8] * 8);
  iVar12 = param_1[8];
  param_1[9] = (int)pvVar11;
  iVar5 = 0;
  if (0 < iVar12) {
    do {
      *(int *)(param_1[10] + iVar5 * 4) = param_1[9] + iVar12 * iVar5 * 8;
      iVar12 = param_1[8];
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar12);
  }
  FUN_0056d880(param_1[10],param_1[8]);
  param_1[0xc] = 0;
  do {
    piVar3 = (int *)FUN_00579f89();
    if (piVar3 == (int *)0x0) goto LAB_0056e813;
    cVar2 = (**(code **)(*piVar3 + 0x10))(param_1[10],param_1[8]);
  } while (cVar2 == '\0');
  FUN_00587bcf(param_1[9]);
  param_1[9] = 0;
  FUN_00587bcf(param_1[10]);
  iVar12 = (**(code **)(*piVar3 + 8))();
  param_1[10] = iVar12;
  iVar12 = (**(code **)*piVar3)();
  param_1[0xb] = iVar12;
  param_1[0xc] = (int)piVar3;
LAB_0056e813:
  if (param_1[0xc] == 0) {
    FUN_0056d880(param_1[10],param_1[8]);
    pvVar11 = operator_new(param_1[8] << 3);
    param_1[0xb] = (int)pvVar11;
    FUN_0056c830(param_1[10],pvVar11,param_1[8]);
  }
  iVar12 = 0;
  if (0 < *param_1) {
    iVar5 = 0;
    do {
      iVar18 = param_1[1];
      iVar6 = param_1[0xb];
      *(int *)(iVar18 + iVar5 + 0x228) = param_1[10];
      *(int *)(iVar18 + iVar5 + 0x224) = iVar6;
      iVar12 = iVar12 + 1;
      iVar5 = iVar5 + 0x244;
    } while (iVar12 < *param_1);
  }
  FUN_005355a0();
  return 0;
}


