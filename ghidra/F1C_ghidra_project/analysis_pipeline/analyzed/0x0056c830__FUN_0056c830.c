// Function: FUN_0056c830 @ 0056c830
// Size (bytes): 1330


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056c830(int *param_1,int *param_2,undefined4 *param_3,uint param_4)

{
  undefined1 *puVar1;
  void *pvVar2;
  undefined4 *puVar3;
  double *pdVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  double *pdVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint local_24;
  int local_20;
  uint local_1c;
  int *local_14;
  int *local_10;
  
  FUN_0056cf10();
  piVar8 = param_2;
  uVar11 = param_4;
  if (0 < (int)param_4) {
    do {
      iVar5 = 0;
      do {
        puVar3 = (undefined4 *)(*piVar8 + iVar5 * 8);
        if (*(double *)(*piVar8 + iVar5 * 8) != _DAT_0059e430) {
          *puVar3 = 0;
          puVar3[1] = 0x3ff00000;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)param_4);
      uVar11 = uVar11 - 1;
      piVar8 = piVar8 + 1;
    } while (uVar11 != 0);
  }
  if (0 < (int)param_4) {
    *param_3 = 0;
    param_3[1] = 0x3ff00000;
    puVar3 = param_3 + 2;
    for (uVar11 = param_4 * 8 - 5 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar3 = *param_3;
      param_3 = param_3 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  local_20 = 0;
  local_1c = 0;
  local_24 = 0;
  if (-1 < (int)param_4) {
    iVar5 = 0;
    do {
      uVar11 = (local_24 == param_4) - 1 & local_24;
      if ((int)uVar11 < (int)param_4) {
        local_14 = (int *)(uVar11 * 8);
        piVar8 = param_2 + uVar11;
        do {
          if (local_24 == param_4) {
            if (0 < (int)local_14) {
              pdVar4 = (double *)*piVar8;
              uVar6 = uVar11;
              do {
                if (*pdVar4 != _DAT_0059e430) {
                  local_1c = local_1c + 1;
                }
                pdVar4 = pdVar4 + 1;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            local_20 = local_20 + 1;
          }
          else {
            iVar12 = 0;
            if (0 < iVar5) {
              do {
                iVar10 = *piVar8;
                if (((*(double *)(iVar10 + iVar12 * 8) != _DAT_0059e430) &&
                    (*(double *)(iVar5 + param_2[iVar12]) != _DAT_0059e430)) &&
                   (local_1c = local_1c + 1, *(double *)(iVar5 + iVar10) == _DAT_0059e430)) {
                  *(undefined4 *)(iVar5 + iVar10) = 0;
                  *(undefined4 *)(iVar5 + 4 + iVar10) = 0x40000000;
                }
                iVar12 = iVar12 + 1;
              } while (iVar12 < (int)local_24);
            }
            puVar3 = (undefined4 *)(*piVar8 + iVar5);
            if (*(double *)(*piVar8 + iVar5) != _DAT_0059e430) {
              local_20 = local_20 + 1;
            }
            iVar12 = param_2[local_24];
            *(undefined4 *)((int)local_14 + iVar12) = *puVar3;
            *(undefined4 *)((int)local_14 + 4 + iVar12) = puVar3[1];
          }
          uVar11 = uVar11 + 1;
          local_14 = (int *)((int)local_14 + 8);
          piVar8 = piVar8 + 1;
        } while ((int)uVar11 < (int)param_4);
      }
      local_24 = local_24 + 1;
      iVar5 = iVar5 + 8;
    } while ((int)local_24 <= (int)param_4);
  }
  iVar5 = param_4 - 2;
  if (-1 < iVar5) {
    iVar12 = param_4 - 1;
    iVar10 = iVar12 * 8;
    do {
      if (iVar12 < (int)param_4) {
        pdVar4 = (double *)(param_2[iVar5] + iVar10);
        iVar7 = param_4 - iVar12;
        do {
          if (*pdVar4 != _DAT_0059e430) {
            local_1c = local_1c + 1;
          }
          pdVar4 = pdVar4 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      iVar5 = iVar5 + -1;
      iVar10 = iVar10 + -8;
      iVar12 = iVar12 + -1;
    } while (-1 < iVar5);
  }
  piVar8 = param_2;
  uVar11 = param_4;
  if (0 < (int)param_4) {
    do {
      iVar5 = 0;
      do {
        puVar3 = (undefined4 *)(*piVar8 + iVar5 * 8);
        if ((*(int *)(*piVar8 + iVar5 * 8) == 0) && (puVar3[1] == 0x40000000)) {
          *puVar3 = 0;
          puVar3[1] = 0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)param_4);
      uVar11 = uVar11 - 1;
      piVar8 = piVar8 + 1;
    } while (uVar11 != 0);
  }
  pvVar2 = operator_new(param_4 * 8 + 8);
  *param_1 = (int)pvVar2;
  pvVar2 = operator_new(param_4 * 8);
  param_1[1] = (int)pvVar2;
  pvVar2 = operator_new(local_20 * 8);
  param_1[2] = (int)pvVar2;
  pvVar2 = operator_new(local_1c);
  param_1[3] = (int)pvVar2;
  iVar5 = 0;
  uVar11 = 0;
  local_20 = 0;
  local_1c = 0;
  local_24 = 0;
  if (-1 < (int)param_4) {
    do {
      *(undefined4 *)(iVar5 + *param_1) = 0;
      *(int *)(*param_1 + 4 + iVar5) = param_1[2] + local_20 * 8;
      uVar6 = (local_24 == param_4) - 1 & local_24;
      if ((int)uVar6 < (int)param_4) {
        local_10 = (int *)(uVar6 * 8);
        local_14 = param_2 + uVar6;
        do {
          if (local_24 == param_4) {
            *(int *)(*param_1 + iVar5) = *(int *)(*param_1 + iVar5) + 1;
            puVar1 = (undefined1 *)(param_1[2] + local_20 * 8);
            local_20 = local_20 + 1;
            *puVar1 = (char)uVar6;
            puVar1[1] = 0;
            *(uint *)(puVar1 + 4) = param_1[3] + uVar11;
            iVar12 = 0;
            if (0 < (int)local_10) {
              do {
                if (*(double *)(*local_14 + iVar12 * 8) != _DAT_0059e430) {
                  puVar1[1] = puVar1[1] + '\x01';
                  *(char *)(uVar11 + param_1[3]) = (char)iVar12;
                  uVar11 = uVar11 + 1;
                }
                iVar12 = iVar12 + 1;
                local_1c = uVar11;
              } while (iVar12 < (int)uVar6);
            }
          }
          else {
            pdVar4 = (double *)*local_14;
            if ((*(double *)(iVar5 + (int)pdVar4) == _DAT_0059e430) &&
               (iVar12 = 0, pdVar9 = pdVar4, 0 < iVar5)) {
              do {
                if ((*pdVar9 != _DAT_0059e430) &&
                   (*(double *)(iVar5 + param_2[iVar12]) != _DAT_0059e430)) {
                  *(undefined4 *)(iVar5 + (int)pdVar4) = 0;
                  *(undefined4 *)(iVar5 + 4 + (int)pdVar4) = 0x40000000;
                  break;
                }
                iVar12 = iVar12 + 1;
                pdVar9 = pdVar9 + 1;
              } while (iVar12 < (int)local_24);
            }
            if (*(double *)(iVar5 + *local_14) != _DAT_0059e430) {
              *(int *)(*param_1 + iVar5) = *(int *)(*param_1 + iVar5) + 1;
              puVar1 = (undefined1 *)(param_1[2] + local_20 * 8);
              *puVar1 = (char)uVar6;
              puVar1[1] = 0;
              local_20 = local_20 + 1;
              *(uint *)(puVar1 + 4) = param_1[3] + uVar11;
              iVar12 = 0;
              if (0 < iVar5) {
                do {
                  if ((*(double *)(*local_14 + iVar12 * 8) != _DAT_0059e430) &&
                     (*(double *)(iVar5 + param_2[iVar12]) != _DAT_0059e430)) {
                    puVar1[1] = puVar1[1] + '\x01';
                    *(char *)(uVar11 + param_1[3]) = (char)iVar12;
                    uVar11 = uVar11 + 1;
                  }
                  iVar12 = iVar12 + 1;
                  local_1c = uVar11;
                } while (iVar12 < (int)local_24);
              }
            }
            iVar12 = *local_14;
            iVar10 = param_2[local_24];
            *(undefined4 *)((int)local_10 + iVar10) = *(undefined4 *)(iVar5 + iVar12);
            *(undefined4 *)((int)local_10 + 4 + iVar10) = *(undefined4 *)(iVar5 + 4 + iVar12);
            uVar11 = local_1c;
          }
          uVar6 = uVar6 + 1;
          local_14 = local_14 + 1;
          local_10 = (int *)((int)local_10 + 8);
        } while ((int)uVar6 < (int)param_4);
      }
      local_24 = local_24 + 1;
      iVar5 = iVar5 + 8;
    } while ((int)local_24 <= (int)param_4);
  }
  iVar5 = param_4 - 1;
  if (-1 < iVar5) {
    local_10 = param_2 + iVar5;
    do {
      puVar1 = (undefined1 *)(param_1[1] + iVar5 * 8);
      *puVar1 = (char)iVar5;
      puVar1[1] = 0;
      *(uint *)(puVar1 + 4) = param_1[3] + uVar11;
      iVar12 = iVar5;
      while (iVar12 = iVar12 + 1, iVar12 < (int)param_4) {
        if (*(double *)(*local_10 + iVar12 * 8) != _DAT_0059e430) {
          puVar1[1] = puVar1[1] + '\x01';
          *(char *)(uVar11 + param_1[3]) = (char)iVar12;
          uVar11 = uVar11 + 1;
        }
      }
      iVar5 = iVar5 + -1;
      local_10 = local_10 + -1;
    } while (-1 < iVar5);
  }
  return;
}


