// Function: FUN_00465460 @ 00465460
// Size (bytes): 1975


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00465460(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int local_2c;
  undefined4 local_28;
  int *local_24;
  int local_20;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  iVar8 = *param_1;
  iVar14 = *(int *)(iVar8 + 0xe5c0);
  while (iVar14 != 0) {
    iVar13 = *(int *)(iVar14 + 4);
    FUN_00582290();
    FUN_00587bcf(iVar14);
    iVar14 = iVar13;
  }
  *(int *)(iVar8 + 0xe5c0) = 0;
  *(undefined4 *)(iVar8 + 0xe5c4) = 0;
  *(undefined4 *)(iVar8 + 0xe5c8) = 0;
  *(undefined4 *)(iVar8 + 0xe5cc) = 0;
  uVar4 = FUN_00464f50(param_2);
  iVar14 = param_2 * 0x230;
  iVar8 = *param_1;
  local_2c = __ftol();
  local_2c = local_2c + (uint)*(ushort *)(iVar14 + 0x2b4 + iVar8);
  *(undefined2 *)(iVar14 + 0x2b4 + iVar8) = 0;
  puVar5 = *(undefined4 **)(*param_1 + 0x6c);
  *(undefined4 **)(*param_1 + 0x74) = puVar5;
  if (puVar5 != (undefined4 *)0x0) {
    puVar9 = (uint *)*puVar5;
    while (puVar9 != (uint *)0x0) {
      if (puVar9[0x6b] != param_3) {
        iVar8 = *param_1;
        puVar5 = operator_new(0xc);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = puVar9;
          puVar5[1] = 0;
          *(undefined1 *)(puVar5 + 2) = 0;
        }
        if (*(int *)(iVar8 + 0xe5c0) == 0) {
          *(int *)(iVar8 + 0xe5c0) = (int)puVar5;
          *(undefined4 **)(iVar8 + 0xe5c8) = puVar5;
        }
        else {
          *(undefined4 **)(*(int *)(iVar8 + 0xe5c4) + 4) = puVar5;
        }
        *(undefined4 **)(iVar8 + 0xe5c4) = puVar5;
        *(int *)(iVar8 + 0xe5cc) = *(int *)(iVar8 + 0xe5cc) + 1;
        local_2c = local_2c + (-8 - (*puVar9 >> 8 & 0x3ff));
      }
      iVar8 = *param_1;
      if (*(int *)(iVar8 + 0x74) != 0) {
        *(undefined4 *)(iVar8 + 0x74) = *(undefined4 *)(*(int *)(iVar8 + 0x74) + 4);
      }
      if (*(undefined4 **)(iVar8 + 0x74) == (undefined4 *)0x0) break;
      puVar9 = (uint *)**(undefined4 **)(iVar8 + 0x74);
    }
  }
  uVar4 = FUN_00464f90(uVar4);
  switch(uVar4) {
  case 1:
    local_28 = 0x3e000000;
    break;
  case 2:
    local_28 = 0x3daaaaab;
    break;
  case 3:
    local_28 = 0x3d800000;
    break;
  case 4:
    local_28 = 0x3c800000;
    break;
  default:
    local_28 = 0x3e2aaaab;
  }
  cVar3 = FUN_00464bb0((float)_DAT_008afe90,local_28);
  if ((cVar3 != '\0') && (0 < local_2c)) {
    FUN_00464bd0(local_28);
    iVar8 = local_2c / 0x3c;
    if (0 < iVar8) {
      iVar13 = *param_1;
      iVar12 = *(int *)(iVar13 + 0xe5b0);
      while (iVar12 != 0) {
        iVar7 = *(int *)(iVar12 + 4);
        FUN_00582290();
        FUN_00587bcf(iVar12);
        iVar12 = iVar7;
      }
      *(undefined4 *)(iVar13 + 0xe5b0) = 0;
      *(undefined4 *)(iVar13 + 0xe5b4) = 0;
      *(undefined4 *)(iVar13 + 0xe5b8) = 0;
      *(undefined4 *)(iVar13 + 0xe5bc) = 0;
      local_24 = (int *)0x0;
      local_20 = 0;
      iVar13 = 0xe410;
      do {
        *(undefined4 *)(*param_1 + iVar13) = 0xffffffff;
        iVar12 = *param_1;
        if (((*(char *)(iVar12 + 0xf8 + local_20) != '\0') && (local_24 != (int *)param_2)) &&
           (iVar7 = *(int *)(iVar12 + 0x2b8 + local_20), iVar7 != 0)) {
          piVar6 = operator_new(0xc);
          if (piVar6 == (int *)0x0) {
            piVar6 = (int *)0x0;
          }
          else {
            *piVar6 = iVar7;
            piVar6[1] = 0;
            *(undefined1 *)(piVar6 + 2) = 0;
          }
          if (*(int *)(iVar12 + 0xe5b0) == 0) {
            *(int **)(iVar12 + 0xe5b0) = piVar6;
            *(int **)(iVar12 + 0xe5b8) = piVar6;
          }
          else {
            *(int **)(*(int *)(iVar12 + 0xe5b4) + 4) = piVar6;
          }
          *(int **)(iVar12 + 0xe5b4) = piVar6;
          *(int *)(iVar12 + 0xe5bc) = *(int *)(iVar12 + 0xe5bc) + 1;
        }
        local_24 = (int *)((int)local_24 + 1);
        iVar13 = iVar13 + 4;
        local_20 = local_20 + 0x230;
      } while (iVar13 < 0xe5b0);
      iVar13 = (int)*(short *)(&DAT_005f0f88 + param_2 * 0x48c0);
      if ((&DAT_005ef9a0)[*(short *)(&DAT_005f0f88 + param_2 * 0x48c0) * 0x1230] == -1) {
        iVar13 = param_2;
      }
      piVar6 = *(int **)(*param_1 + 0xe5b0);
      *(int **)(*param_1 + 0xe5b8) = piVar6;
      if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
        do {
          FUN_00464990(&DAT_005ec6d8 + iVar13 * 0x48c0);
          iVar12 = *param_1;
          if (*(int *)(iVar12 + 0xe5b8) != 0) {
            *(undefined4 *)(iVar12 + 0xe5b8) = *(undefined4 *)(*(int *)(iVar12 + 0xe5b8) + 4);
          }
        } while ((*(int **)(iVar12 + 0xe5b8) != (int *)0x0) && (**(int **)(iVar12 + 0xe5b8) != 0));
      }
      iVar13 = *param_1;
      iVar7 = FUN_00465c70(*(undefined4 *)(iVar13 + 0xe5b0));
      *(int *)(iVar13 + 0xe5b0) = iVar7;
      iVar12 = iVar7;
      if (iVar7 != 0) {
        iVar2 = *(int *)(iVar7 + 4);
        while (iVar1 = iVar2, iVar1 != 0) {
          iVar12 = iVar1;
          iVar2 = *(int *)(iVar1 + 4);
        }
      }
      *(int *)(iVar13 + 0xe5b8) = iVar7;
      *(int *)(iVar13 + 0xe5b4) = iVar12;
      puVar5 = *(undefined4 **)(*param_1 + 0xe5b0);
      *(undefined4 **)(*param_1 + 0xe5b8) = puVar5;
      if (puVar5 == (undefined4 *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)*puVar5;
      }
      if (piVar6 != (int *)0x0) {
        iVar13 = 0xe410;
        do {
          *(uint *)(iVar13 + *param_1) = *(uint *)(*piVar6 + 0x6d) & 0xff;
          iVar12 = *param_1;
          iVar13 = iVar13 + 4;
          if (*(int *)(iVar12 + 0xe5b8) != 0) {
            *(undefined4 *)(iVar12 + 0xe5b8) = *(undefined4 *)(*(int *)(iVar12 + 0xe5b8) + 4);
          }
        } while ((*(undefined4 **)(iVar12 + 0xe5b8) != (undefined4 *)0x0) &&
                (piVar6 = (int *)**(undefined4 **)(iVar12 + 0xe5b8), piVar6 != (int *)0x0));
      }
      DAT_007cd2ac = *param_1;
      local_10 = (undefined4 *)0x0;
      local_c = (undefined4 *)0x0;
      piVar6 = *(int **)(*param_1 + 0x7c);
      *(int **)(*param_1 + 0x84) = piVar6;
      if (piVar6 != (int *)0x0) {
        puVar5 = local_10;
        puVar10 = local_c;
        for (iVar13 = *piVar6; local_10 = puVar5, iVar13 != 0; iVar13 = **(int **)(iVar13 + 0x84)) {
          local_c = puVar10;
          if (*(uint *)(iVar13 + 0x1ac) != param_3) {
            piVar6 = operator_new(4);
            *piVar6 = iVar13;
            local_c = operator_new(0xc);
            if (local_c == (undefined4 *)0x0) {
              local_c = (undefined4 *)0x0;
            }
            else {
              *local_c = piVar6;
              local_c[1] = 0;
              *(undefined1 *)(local_c + 2) = 1;
            }
            local_10 = local_c;
            if (puVar5 != (undefined4 *)0x0) {
              puVar10[1] = local_c;
              local_10 = puVar5;
            }
          }
          iVar13 = *param_1;
          if (*(int *)(iVar13 + 0x84) != 0) {
            *(undefined4 *)(iVar13 + 0x84) = *(undefined4 *)(*(int *)(iVar13 + 0x84) + 4);
          }
          if (*(int **)(iVar13 + 0x84) == (int *)0x0) break;
          puVar5 = local_10;
          puVar10 = local_c;
        }
      }
      puVar5 = (undefined4 *)FUN_00465d70(local_10);
      if (puVar5 != (undefined4 *)0x0) {
        for (iVar13 = puVar5[1]; iVar13 != 0; iVar13 = *(int *)(iVar13 + 4)) {
        }
      }
      if (1 < iVar8) {
        iVar8 = iVar8 / 2;
      }
      puVar10 = *(undefined4 **)(*param_1 + 0xe5b0);
      *(undefined4 **)(*param_1 + 0xe5b8) = puVar10;
      if (puVar10 == (undefined4 *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)*puVar10;
      }
      local_8 = puVar5;
      local_20 = iVar8;
      if (puVar5 == (undefined4 *)0x0) {
        local_24 = (int *)0x0;
      }
      else {
        local_24 = (int *)*puVar5;
      }
joined_r0x00465962:
      do {
        if (piVar6 != (int *)0x0) {
          if ((*(char *)(*piVar6 + 0x6c) == '\0') ||
             (cVar3 = FUN_00464ae0(param_2,*(undefined1 *)(iVar14 + 0x2b6 + *param_1)),
             cVar3 == '\0')) {
            iVar8 = *param_1;
            if (*(int *)(iVar8 + 0xe5b8) != 0) {
              *(undefined4 *)(iVar8 + 0xe5b8) = *(undefined4 *)(*(int *)(iVar8 + 0xe5b8) + 4);
            }
            if (*(undefined4 **)(iVar8 + 0xe5b8) != (undefined4 *)0x0) {
              piVar6 = (int *)**(undefined4 **)(iVar8 + 0xe5b8);
              goto joined_r0x00465962;
            }
          }
          else {
            FUN_00464ad0(param_2);
            if (*(uint *)(*piVar6 + 0x219) != param_3) {
              local_20 = local_20 + -1;
              if (local_20 < 0) {
                puVar9 = operator_new(0x1b0);
                iVar8 = *piVar6;
                FUN_004b33b0(1,7,0x13,*(uint *)(iVar8 + 0x6d) & 0xff,*(undefined4 *)(iVar8 + 0x71),0
                            );
                FUN_004b2c80(iVar8 + 0x75);
                iVar8 = *param_1;
                if (puVar9 != (uint *)0x0) {
                  puVar10 = operator_new(0xc);
                  if (puVar10 == (undefined4 *)0x0) {
                    puVar10 = (undefined4 *)0x0;
                  }
                  else {
                    *puVar10 = puVar9;
                    puVar10[1] = 0;
                    *(undefined1 *)(puVar10 + 2) = 1;
                  }
                  if (*(int *)(iVar8 + 0xe5c0) == 0) {
                    *(int *)(iVar8 + 0xe5c0) = (int)puVar10;
                    *(undefined4 **)(iVar8 + 0xe5c8) = puVar10;
                  }
                  else {
                    *(undefined4 **)(*(int *)(iVar8 + 0xe5c4) + 4) = puVar10;
                  }
                  *(undefined4 **)(iVar8 + 0xe5c4) = puVar10;
                  *(int *)(iVar8 + 0xe5cc) = *(int *)(iVar8 + 0xe5cc) + 1;
                }
                local_2c = local_2c + (-8 - (*puVar9 >> 8 & 0x3ff));
              }
              else {
                iVar8 = *param_1;
                iVar13 = *piVar6 + 0x6d;
                if (iVar13 != 0) {
                  piVar6 = operator_new(0xc);
                  if (piVar6 == (int *)0x0) {
                    piVar6 = (int *)0x0;
                  }
                  else {
                    *piVar6 = iVar13;
                    piVar6[1] = 0;
                    *(undefined1 *)(piVar6 + 2) = 0;
                  }
                  if (*(int *)(iVar8 + 0xe5c0) == 0) {
                    *(int *)(iVar8 + 0xe5c0) = (int)piVar6;
                    *(int **)(iVar8 + 0xe5c8) = piVar6;
                  }
                  else {
                    *(int **)(*(int *)(iVar8 + 0xe5c4) + 4) = piVar6;
                  }
                  *(int **)(iVar8 + 0xe5c4) = piVar6;
                  *(int *)(iVar8 + 0xe5cc) = *(int *)(iVar8 + 0xe5cc) + 1;
                }
                local_2c = local_2c + -0x3c;
              }
            }
            iVar8 = *param_1;
            if (*(int *)(iVar8 + 0xe5b8) != 0) {
              *(undefined4 *)(iVar8 + 0xe5b8) = *(undefined4 *)(*(int *)(iVar8 + 0xe5b8) + 4);
            }
            if (*(undefined4 **)(iVar8 + 0xe5b8) != (undefined4 *)0x0) {
              piVar6 = (int *)**(undefined4 **)(iVar8 + 0xe5b8);
              goto LAB_00465af2;
            }
          }
          piVar6 = (int *)0x0;
        }
LAB_00465af2:
        if (local_2c < 1) break;
        if (local_24 == (int *)0x0) {
          if (piVar6 == (int *)0x0) break;
        }
        else {
          iVar8 = *param_1;
          iVar13 = *local_24;
          if (iVar13 != 0) {
            piVar11 = operator_new(0xc);
            if (piVar11 == (int *)0x0) {
              piVar11 = (int *)0x0;
            }
            else {
              *piVar11 = iVar13;
              piVar11[1] = 0;
              *(undefined1 *)(piVar11 + 2) = 0;
            }
            if (*(int *)(iVar8 + 0xe5c0) == 0) {
              *(int *)(iVar8 + 0xe5c0) = (int)piVar11;
              *(int **)(iVar8 + 0xe5c8) = piVar11;
            }
            else {
              *(int **)(*(int *)(iVar8 + 0xe5c4) + 4) = piVar11;
            }
            *(int **)(iVar8 + 0xe5c4) = piVar11;
            *(int *)(iVar8 + 0xe5cc) = *(int *)(iVar8 + 0xe5cc) + 1;
          }
          local_2c = local_2c + (-8 - (*(uint *)*local_24 >> 8 & 0x3ff));
          if ((local_8 == (undefined4 *)0x0) ||
             (local_8 = (undefined4 *)local_8[1], local_8 == (undefined4 *)0x0)) {
            local_24 = (int *)0x0;
          }
          else {
            local_24 = (int *)*local_8;
          }
        }
      } while (0 < local_2c);
      while (puVar5 != (undefined4 *)0x0) {
        puVar10 = (undefined4 *)puVar5[1];
        if (*(char *)(puVar5 + 2) != '\0') {
          FUN_00587bcf(*puVar5);
        }
        FUN_00587bcf(puVar5);
        puVar5 = puVar10;
      }
    }
  }
  *(undefined4 *)(*param_1 + 0xe5c8) = *(undefined4 *)(*param_1 + 0xe5c0);
  if (0 < local_2c) {
    iVar8 = __ftol();
    if (local_2c <= iVar8) {
      iVar8 = local_2c;
    }
    *(short *)(iVar14 + 0x2b4 + *param_1) = (short)iVar8;
  }
  return;
}


