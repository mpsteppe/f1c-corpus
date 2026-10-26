// Function: FUN_00492a40 @ 00492a40
// Strings:  [POSITION, ATTRIBUTESET, POS-W-H, FRIENDGIZMO, ACTIONS, CHILD, CAPTION2, TOOLTIP]


int __thiscall FUN_00492a40(int param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  char local_100;
  undefined4 local_ff;
  char local_80;
  undefined4 local_7f;
  
  local_100 = DAT_005ea438;
  puVar12 = &local_ff;
  for (iVar11 = 0x1f; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  *(undefined2 *)puVar12 = 0;
  *(undefined1 *)((int)puVar12 + 2) = 0;
  local_80 = DAT_005ea438;
  puVar12 = &local_7f;
  for (iVar11 = 0x1f; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  *(undefined2 *)puVar12 = 0;
  *(undefined1 *)((int)puVar12 + 2) = 0;
  local_110 = 0;
  local_108 = 0;
  local_10c = 0;
  local_104 = 0;
  bVar3 = false;
  bVar2 = false;
  if (param_2 == (char *)0x0) {
    FUN_00493c80(2,s_Null_gizmoName_ptr_passed_to___R_005cc75c);
  }
  iVar11 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(&local_80 + iVar11)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(&local_80);
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 1;
  iVar11 = FUN_00493fc0(&local_80);
  if (iVar11 == 0) {
    FUN_0058815f(&DAT_007cdcf0,s_undefined_gizmo_type__s_005cc744,&local_80);
    FUN_00493c80(1,&DAT_007cdcf0);
    FUN_00492030();
    return 0;
  }
  *(undefined4 *)(iVar11 + 0x40) = *(undefined4 *)(param_1 + 0x1a4);
  *(undefined4 *)(iVar11 + 0x98) = *(undefined4 *)(param_1 + 0x1a8);
  *(undefined4 *)(iVar11 + 0x9c) = *(undefined4 *)(param_1 + 0x1ac);
  iVar4 = FUN_00491fb0();
  while ((iVar4 != 0 && (iVar4 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f4), iVar4 == 0))) {
    iVar4 = FUN_005654a0(&DAT_005cc650,&local_100);
    if (iVar4 == 0) {
      iVar4 = FUN_005654a0(s_SOURCE_VARIABLE_005cc734,&local_100);
      if (iVar4 == 0) {
        iVar4 = FUN_005654a0(s_VARIABLE_005cc728,&local_100);
        if (iVar4 == 0) {
          iVar4 = FUN_005654a0(s_VARIABLE_VALUE_005cc718,&local_100);
          if (iVar4 == 0) {
            iVar4 = FUN_00565870(s_POS_W_H_005cc68c,&local_110,&local_108,&local_10c,&local_104,0,0,
                                 0,0);
            if (iVar4 == 0) {
              iVar4 = FUN_00565870(s_POSITION_005c59d4,&local_10c,&local_110,0,0,0,0,0,0);
              if (iVar4 == 0) {
                iVar4 = FUN_00565870(s_WIDTH_HEIGHT_005cc708,&local_110,&local_10c,0,0,0,0,0,0);
                if (iVar4 == 0) {
                  iVar4 = FUN_00565870(s_POS2_OFFSET_005cc6fc,&local_110,&local_108,&local_10c,
                                       &local_104,0,0,0,0);
                  if (iVar4 == 0) {
                    iVar4 = FUN_00565870(s_OFFSET_005cc6f4,&local_110,&local_10c,0,0,0,0,0,0);
                    if (iVar4 == 0) {
                      iVar4 = FUN_005654a0(s_CAPTION1_005cc6e8,&DAT_007cdcf0);
                      if (iVar4 == 0) {
                        iVar4 = FUN_005654a0(s_TOOLTIP_005cc6e0,&DAT_007cdcf0);
                        if (iVar4 == 0) {
                          iVar4 = FUN_005654a0(s_CAPTION2_005cc6d4,&DAT_007cdcf0);
                          if (iVar4 == 0) {
                            iVar4 = FUN_005654a0(s_CHILD_005cc6cc,&local_100);
                            if (iVar4 == 0) {
                              iVar4 = FUN_005654a0(s_ACTIONS_005cc6c4,&local_100);
                              if (iVar4 == 0) {
                                iVar4 = FUN_005654a0(s_ATTRIBUTESET_005cc5bc,&local_100);
                                if (iVar4 == 0) {
                                  iVar4 = FUN_005654a0(s_FRIENDGIZMO_005cc6b8,&DAT_007cdcf0);
                                  if (iVar4 != 0) {
                                    FUN_00486580(&DAT_007cdcf0);
                                  }
                                }
                                else {
                                  iVar4 = FUN_0049a210(&local_100);
                                  *(int *)(iVar11 + 200) = iVar4;
                                  if (iVar4 != 0) {
                                    FUN_004861a0(!bVar3,!bVar2);
                                  }
                                }
                              }
                              else {
                                FUN_00493480(iVar11,&local_100);
                              }
                            }
                            else {
                              iVar4 = FUN_00492a40(&local_100);
                              if (iVar4 != 0) {
                                FUN_00486340(iVar4,0);
                              }
                            }
                          }
                          else {
                            FUN_00566650(&DAT_007cdcf0);
                          }
                        }
                        else {
                          FUN_00566650(&DAT_007cdcf0);
                        }
                      }
                      else {
                        FUN_00566650(&DAT_007cdcf0);
                      }
                    }
                    else {
                      uVar5 = __ftol();
                      uVar6 = __ftol(uVar5);
                      FUN_0049adc0(uVar6,uVar5);
                    }
                  }
                  else {
                    uVar5 = __ftol();
                    uVar6 = __ftol(uVar5);
                    FUN_0049adc0(uVar6,uVar5);
                    uVar5 = __ftol();
                    uVar6 = __ftol(uVar5);
                    FUN_0049adc0(uVar6,uVar5);
                    bVar2 = true;
                  }
                }
                else {
                  uVar5 = __ftol();
                  uVar6 = __ftol(uVar5);
                  FUN_0049aa70(uVar6,uVar5);
                  bVar3 = true;
                }
              }
              else {
                uVar5 = __ftol();
                uVar6 = __ftol(uVar5);
                FUN_0049aa30(uVar6,uVar5);
              }
            }
            else {
              uVar5 = __ftol();
              uVar6 = __ftol(uVar5);
              uVar7 = __ftol(uVar6);
              uVar8 = __ftol(uVar7);
              FUN_0049a9c0(uVar8,uVar7,uVar6,uVar5);
              bVar3 = true;
            }
          }
          else {
            FUN_00566650(&local_100);
          }
        }
        else {
          FUN_00566650(&local_100);
        }
      }
      else {
        FUN_00566650(&local_100);
      }
    }
    else {
      if (((*(char *)(param_1 + 0x19a) != '\0') && (-1 < *(int *)(param_1 + 0x19c))) &&
         (*(int *)(param_1 + 0x19c) < 4)) {
        FUN_00493e20(&local_100);
      }
      FUN_0049ad50(&local_100);
    }
    iVar4 = FUN_00491fb0();
  }
  pcVar9 = *(char **)(iVar11 + 0xb0);
  if (pcVar9 == (char *)0x0) {
    pcVar9 = &DAT_005ea438;
  }
  iVar4 = -1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  if (iVar4 != -2) {
    puVar10 = *(undefined1 **)(iVar11 + 0xb0);
    if (puVar10 == (undefined1 *)0x0) {
      puVar10 = &DAT_005ea438;
    }
    iVar4 = FUN_00423a00(puVar10,&DAT_007cdcf0);
    if (iVar4 == 0) {
      FUN_00566650(&DAT_007cdcf0);
    }
  }
  pcVar9 = *(char **)(iVar11 + 0xc0);
  if (pcVar9 == (char *)0x0) {
    pcVar9 = &DAT_005ea438;
  }
  iVar4 = -1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  if (iVar4 != -2) {
    puVar10 = *(undefined1 **)(iVar11 + 0xc0);
    if (puVar10 == (undefined1 *)0x0) {
      puVar10 = &DAT_005ea438;
    }
    iVar4 = FUN_00423a00(puVar10,&DAT_007cdcf0);
    if (iVar4 == 0) {
      FUN_00566650(&DAT_007cdcf0);
    }
  }
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + -1;
  return iVar11;
}


