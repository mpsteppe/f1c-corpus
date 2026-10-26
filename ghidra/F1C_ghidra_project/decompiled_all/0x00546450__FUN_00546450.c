// Function: FUN_00546450 @ 00546450
// Strings:  [%s%4s%s%c, %s%.2d%s]


undefined4 __thiscall FUN_00546450(int param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int *piVar11;
  char *pcVar12;
  uint local_40;
  int *local_38;
  undefined1 *local_34;
  int local_30;
  char local_28 [4];
  undefined1 auStack_24 [4];
  undefined1 local_20 [32];
  
  local_40 = 0;
  if (((*(uint *)(param_1 + 0x9c) & 1) != 0) && ((*(uint *)(param_1 + 0x9c) & 2) != 0)) {
    if (param_2 == -1) {
      iVar7 = *(int *)(param_1 + 0xa4);
      param_2 = 0;
    }
    else {
      iVar7 = param_2 + 1;
    }
    for (; param_2 < iVar7; param_2 = param_2 + 1) {
      pcVar10 = (char *)(param_2 * 0x94 + *(int *)(param_1 + 0xa8));
      if (*(int *)(param_2 * 0x94 + 0x60 + *(int *)(param_1 + 0xa8)) == 0x8000000) {
        pvVar2 = operator_new(0x14);
        if (pvVar2 == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_00551a30();
        }
        *(undefined4 *)(pcVar10 + 0x90) = uVar3;
        iVar4 = FUN_00551a50(pcVar10,1,0);
        if (iVar4 != 0) {
          iVar7 = *(int *)(pcVar10 + 0x90);
          if (iVar7 != 0) {
            FUN_00557470();
            FUN_00587bcf(iVar7);
          }
          return 0xffffffff;
        }
        piVar5 = (int *)FUN_00547920(pcVar10);
        if (piVar5 == (int *)0x0) {
          iVar4 = *(int *)(pcVar10 + 0x48);
          piVar5 = operator_new(iVar4 * 0x60 + 4);
          if (piVar5 == (int *)0x0) {
            piVar11 = (int *)0x0;
          }
          else {
            piVar11 = piVar5 + 1;
            *piVar5 = iVar4;
            if (-1 < iVar4 + -1) {
              do {
                FUN_0054fe10();
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
          }
          *(int **)(pcVar10 + 0x8c) = piVar11;
          FUN_00550300(*(undefined4 *)(pcVar10 + 0x48));
          iVar4 = FUN_0054fec0(pcVar10,*(undefined4 *)(*(int *)(pcVar10 + 0x90) + 8),
                               *(undefined4 *)(*(int *)(pcVar10 + 0x90) + 0xc),0,4);
          if (iVar4 != 0) {
            return 0xffffffff;
          }
          FUN_00547860(piVar11);
          **(int **)(pcVar10 + 0x8c) = **(int **)(pcVar10 + 0x8c) + 1;
        }
        else {
          *(int **)(pcVar10 + 0x8c) = piVar5;
          *piVar5 = *piVar5 + 1;
        }
      }
      else {
        if (*pcVar10 != '\0') {
          iVar4 = FUN_00547920(pcVar10);
          if ((iVar4 == 0) || ((*(uint *)(pcVar10 + 0x40) & 0x100) != 0)) {
            iVar4 = *(int *)(pcVar10 + 0x48);
            piVar5 = operator_new(iVar4 * 0x60 + 4);
            if (piVar5 == (int *)0x0) {
              local_38 = (int *)0x0;
            }
            else {
              local_38 = piVar5 + 1;
              *piVar5 = iVar4;
              if (-1 < iVar4 + -1) {
                do {
                  FUN_0054fe10();
                  iVar4 = iVar4 + -1;
                } while (iVar4 != 0);
              }
            }
            *(int **)(pcVar10 + 0x8c) = local_38;
            FUN_00550300(*(undefined4 *)(pcVar10 + 0x48));
            if (1 < *(int *)(pcVar10 + 0x48)) {
              *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x400;
            }
            uVar8 = 0xffffffff;
            iVar4 = 0;
            pcVar12 = pcVar10;
            do {
              if (uVar8 == 0) break;
              uVar8 = uVar8 - 1;
              cVar1 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar1 != '\0');
            iVar9 = ~uVar8 - 1;
            do {
              cVar1 = *(char *)((int)&DAT_005cc79c + iVar4);
              local_28[iVar4] = cVar1;
              iVar4 = iVar4 + 1;
            } while (cVar1 != '\0');
            if (0 < iVar9) {
LAB_00546663:
              if (pcVar10[iVar9] != '.') goto code_r0x00546669;
              pcVar12 = pcVar10 + iVar9;
              pcVar6 = pcVar12;
              do {
                cVar1 = *pcVar6;
                pcVar6[(int)(local_28 + -(int)pcVar12)] = cVar1;
                pcVar6 = pcVar6 + 1;
              } while (cVar1 != '\0');
              *pcVar12 = '\0';
            }
LAB_0054668c:
            iVar4 = *(int *)(pcVar10 + 0x48);
            local_30 = 0;
            if (0 < iVar4) {
              local_34 = auStack_24 + -(int)local_38;
              piVar5 = local_38 + 1;
              do {
                if (iVar4 < 2) {
                  FUN_0058815f(piVar5,&DAT_005be860,pcVar10,local_28);
                }
                else {
                  FUN_0058815f(piVar5,s__s__2d_s_005dbe54,pcVar10,local_30,local_28);
                }
                if (((*(uint *)(pcVar10 + 0x60) & 0x800000) != 0) &&
                   ((*(uint *)(pcVar10 + 0x60) & 0x4000) != 0)) {
                  local_40 = local_40 & 0xfffffffb;
                  *(uint *)(pcVar10 + 0x40) = *(uint *)(pcVar10 + 0x40) | 2;
                }
                if ((*(uint *)(pcVar10 + 0x40) & 2) == 0) {
                  uVar8 = local_40 | 4;
                  if ((char)*(uint *)(pcVar10 + 0x40) < '\0') {
                    uVar8 = local_40 | 0x804;
                  }
                }
                else {
                  if (DAT_008b8dbc == 0) {
                    if (DAT_008b8dc0 != 0) {
                      FUN_00542e50();
                      iVar4 = DAT_008b8dc0;
                      if (DAT_008b8dc0 != 0) {
                        FUN_00557470();
                        FUN_00587bcf(iVar4);
                      }
                      DAT_008b8dc0 = 0;
                    }
                  }
                  else {
                    FUN_00542e50();
                    iVar4 = DAT_008b8dbc;
                    if (DAT_008b8dbc != 0) {
                      FUN_00557470();
                      FUN_00587bcf(iVar4);
                    }
                    DAT_008b8dbc = 0;
                  }
                  uVar8 = local_40 | 0x40008;
                  *(uint *)(pcVar10 + 0x40) = *(uint *)(pcVar10 + 0x40) | 1;
                }
                local_40 = uVar8;
                if ((DAT_008b8e24 == 0) || ((pcVar10[0x40] & 0xcU) == 0)) {
                  *(uint *)(pcVar10 + 0x40) = *(uint *)(pcVar10 + 0x40) & 0xfffffff3;
                  piVar5[0x13] = 1;
                }
                else {
                  piVar5[0x13] = *(int *)(pcVar10 + 0x44) + 1;
                  if ((*(uint *)(pcVar10 + 0x40) & 8) == 0) {
                    if ((*(uint *)(pcVar10 + 0x40) & 4) != 0) {
                      local_40 = uVar8 | 0x4000;
                    }
                  }
                  else {
                    local_40 = uVar8 | 0x2000;
                  }
                }
                if ((pcVar10[0x40] & 1U) != 0) {
                  piVar5[0x10] = piVar5[0x10] | 1;
                }
                if ((*(uint *)(pcVar10 + 0x60) & 0x400000) != 0) {
                  local_40 = local_40 | 0x800000;
                }
                iVar4 = FUN_00550080(piVar5,*(undefined4 *)(pcVar10 + 0x80),local_40);
                if (iVar4 != 0) {
                  return 0xffffffff;
                }
                if ((((*(uint *)(pcVar10 + 0x60) & 0x800000) != 0) &&
                    ((*(uint *)(pcVar10 + 0x60) & 0x4000) != 0)) &&
                   (iVar4 = FUN_00548d40(2,param_1), iVar4 != 0)) {
                  return 0xffffffff;
                }
                if ((1 < *(int *)(*(int *)(pcVar10 + 0x8c) + 0x50)) &&
                   ((*(uint *)(pcVar10 + 0x40) & 0xc) == 0)) {
                  *(uint *)(pcVar10 + 0x40) = *(uint *)(pcVar10 + 0x40) | 8;
                }
                if ((*(uint *)(pcVar10 + 0x40) & 0x100) != 0) {
                  uVar8 = 0xffffffff;
                  piVar11 = piVar5;
                  do {
                    if (uVar8 == 0) break;
                    uVar8 = uVar8 - 1;
                    iVar4 = *piVar11;
                    piVar11 = (int *)((int)piVar11 + 1);
                  } while ((char)iVar4 != '\0');
                  iVar4 = ~uVar8 - 1;
                  if (0 < iVar4) {
LAB_00546870:
                    if (*(char *)(iVar4 + (int)piVar5) != '.') goto code_r0x00546876;
                    *(undefined1 *)(iVar4 + 4 + (int)local_38) = 0;
                    piVar11 = piVar5;
                    do {
                      iVar4 = *piVar11;
                      local_34[(int)piVar11] = (char)iVar4;
                      piVar11 = (int *)((int)piVar11 + 1);
                    } while ((char)iVar4 != '\0');
                    FUN_0058815f(piVar5,s__s_4s_s_c_005dbe48,local_20,param_1 + 0x40,local_28,0);
                  }
                }
LAB_005468bc:
                local_38 = local_38 + 0x18;
                local_34 = local_34 + -0x60;
                piVar5 = piVar5 + 0x18;
                iVar4 = *(int *)(pcVar10 + 0x48);
                local_30 = local_30 + 1;
              } while (local_30 < iVar4);
            }
            FUN_00547860(*(undefined4 *)(pcVar10 + 0x8c));
          }
          else {
            *(int *)(pcVar10 + 0x8c) = iVar4;
          }
          **(int **)(pcVar10 + 0x8c) = **(int **)(pcVar10 + 0x8c) + 1;
        }
        if ((*(byte *)(param_1 + 0x9c) & 0x40) != 0) {
          iVar4 = FUN_00548a00(*(undefined4 *)(param_1 + 0xb0));
          *(int *)(param_1 + 0xb4) = iVar4;
          if (iVar4 == 0) {
            FUN_005489a0(*(undefined4 *)(param_1 + 0xb0));
            uVar3 = FUN_00548a00(*(undefined4 *)(param_1 + 0xb0));
            *(undefined4 *)(param_1 + 0xb4) = uVar3;
          }
        }
      }
      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) & 0xfffffffd;
    }
  }
  return 0;
code_r0x00546669:
  iVar9 = iVar9 + -1;
  if (iVar9 < 1) goto LAB_0054668c;
  goto LAB_00546663;
code_r0x00546876:
  iVar4 = iVar4 + -1;
  if (iVar4 < 1) goto LAB_005468bc;
  goto LAB_00546870;
}


