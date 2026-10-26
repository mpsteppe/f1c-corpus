// Function: FUN_00543fa0 @ 00543fa0
// Size (bytes): 1920


undefined4 __fastcall FUN_00543fa0(int param_1)

{
  undefined *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  bool bVar13;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar9 = *(int *)(param_1 + 0x150);
  if (iVar9 != 0) {
    iVar11 = *(int *)(iVar9 + -4);
    if (-1 < iVar11 + -1) {
      do {
        FUN_004b0170();
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    FUN_00587bcf(iVar9 + -4);
    *(undefined4 *)(param_1 + 0x150) = 0;
    *(undefined4 *)(param_1 + 0x14c) = 0;
  }
  iVar9 = *(int *)(param_1 + 100);
  piVar2 = operator_new(iVar9 * 0x18 + 4);
  if (piVar2 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = piVar2 + 1;
    *piVar2 = iVar9;
    if (-1 < iVar9 + -1) {
      do {
        FUN_00548e00();
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
  }
  iVar9 = *(int *)(param_1 + 0x100);
  *(int **)(param_1 + 0x150) = piVar3;
  uVar7 = 0;
  for (; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x104)) {
    if (*(int *)(iVar9 + 0xec) != 0) {
      FUN_0054bd30();
    }
  }
  if (*(int *)(param_1 + 0x108) != 0) {
    FUN_0054bd30();
  }
  for (iVar9 = *(int *)(param_1 + 0x108); iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x4c)) {
    iVar11 = FUN_00544d30(iVar9,0);
    if (iVar11 != 0) {
      return 0xffffffff;
    }
    uVar7 = uVar7 + 1;
    uVar6 = uVar7 & 0x80000001;
    bVar13 = uVar6 == 0;
    if ((int)uVar6 < 0) {
      bVar13 = (uVar6 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (!bVar13) {
      InterlockedDecrement(&DAT_008b8eec);
      FUN_00545f50(0);
    }
  }
  if ((*(byte *)(param_1 + 0xec) & 4) == 0) {
    if (*(int *)(param_1 + 0x110) != 0) {
      iVar9 = FUN_005487a0();
      if (iVar9 != 0) {
        return 0xffffffff;
      }
      FUN_00548810();
    }
    iVar9 = FUN_00544740();
    if (iVar9 != 0) {
      return 0xffffffff;
    }
    FUN_00545a10();
    FUN_00545a40();
    FUN_00545bb0();
  }
  iVar9 = *(int *)(param_1 + 0x1b8);
  if (iVar9 != 0) {
    iVar11 = *(int *)(iVar9 + -4);
    if (-1 < iVar11 + -1) {
      do {
        FUN_00557280();
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    FUN_00587bcf(iVar9 + -4);
    *(undefined4 *)(param_1 + 0x1b8) = 0;
    *(undefined4 *)(param_1 + 0x1b4) = 0;
  }
  iVar9 = *(int *)(param_1 + 0x1c0);
  if (iVar9 != 0) {
    iVar11 = *(int *)(iVar9 + -4);
    if (-1 < iVar11 + -1) {
      do {
        FUN_00557280();
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    FUN_00587bcf(iVar9 + -4);
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    *(undefined4 *)(param_1 + 0x1bc) = 0;
  }
  iVar9 = *(int *)(param_1 + 0x1c8);
  if (iVar9 != 0) {
    iVar11 = *(int *)(iVar9 + -4);
    if (-1 < iVar11 + -1) {
      do {
        FUN_00557280();
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    FUN_00587bcf(iVar9 + -4);
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x1c4) = 0;
  }
  iVar9 = *(int *)(param_1 + 0x1d0);
  if (iVar9 != 0) {
    iVar11 = *(int *)(iVar9 + -4);
    if (-1 < iVar11 + -1) {
      do {
        FUN_00557280();
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    FUN_00587bcf(iVar9 + -4);
    *(undefined4 *)(param_1 + 0x1d0) = 0;
    *(undefined4 *)(param_1 + 0x1cc) = 0;
  }
  piVar2 = (int *)0x0;
  iVar9 = *(int *)(param_1 + 0x110);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(iVar9 + 0x14);
  iVar11 = *(int *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar9 + 0x18);
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar9 + 0x1c);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(iVar9 + 0x20);
  *(int *)(param_1 + 0x1b4) = iVar11;
  if (0 < iVar11) {
    piVar3 = operator_new(iVar11 * 0x210 + 4);
    if (piVar3 != (int *)0x0) {
      piVar2 = piVar3 + 1;
      *piVar3 = iVar11;
      if (-1 < iVar11 + -1) {
        do {
          FUN_00557240();
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
    *(int **)(param_1 + 0x1b8) = piVar2;
  }
  piVar2 = (int *)0x0;
  iVar9 = *(int *)(param_1 + 0x48);
  *(int *)(param_1 + 0x1bc) = iVar9;
  if (0 < iVar9) {
    piVar3 = operator_new(iVar9 * 0x210 + 4);
    if (piVar3 != (int *)0x0) {
      piVar2 = piVar3 + 1;
      *piVar3 = iVar9;
      if (-1 < iVar9 + -1) {
        do {
          FUN_00557240();
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    *(int **)(param_1 + 0x1c0) = piVar2;
  }
  piVar2 = (int *)0x0;
  iVar9 = *(int *)(param_1 + 0x4c);
  *(int *)(param_1 + 0x1c4) = iVar9;
  if (0 < iVar9) {
    piVar3 = operator_new(iVar9 * 0x210 + 4);
    if (piVar3 != (int *)0x0) {
      piVar2 = piVar3 + 1;
      *piVar3 = iVar9;
      if (-1 < iVar9 + -1) {
        do {
          FUN_00557240();
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    *(int **)(param_1 + 0x1c8) = piVar2;
  }
  piVar2 = (int *)0x0;
  iVar9 = *(int *)(param_1 + 0x50);
  *(int *)(param_1 + 0x1cc) = iVar9;
  if (0 < iVar9) {
    piVar3 = operator_new(iVar9 * 0x210 + 4);
    if (piVar3 != (int *)0x0) {
      piVar2 = piVar3 + 1;
      *piVar3 = iVar9;
      if (-1 < iVar9 + -1) {
        do {
          FUN_00557240();
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    *(int **)(param_1 + 0x1d0) = piVar2;
  }
  iVar9 = *(int *)(param_1 + 0x1cc) + *(int *)(param_1 + 0x1c4) + *(int *)(param_1 + 0x1bc) +
          *(int *)(param_1 + 0x1b4);
  local_18 = 0;
  local_10 = 0;
  local_28 = 0;
  local_20 = 0;
  local_2c = 0;
  if (0 < iVar9) {
    local_c = 0;
    local_14 = 0;
    local_1c = 0;
    local_24 = 0;
    do {
      iVar11 = FUN_00548850(local_2c);
      uVar7 = *(uint *)(iVar11 + 0x9c);
      if ((uVar7 & 0x20) == 0) {
        if ((uVar7 & 0x100) == 0) {
          *(int *)(iVar11 + 0xa0) = local_10;
          puVar8 = (uint *)(*(int *)(param_1 + 0x1c0) + local_c);
          local_10 = local_10 + 1;
          local_c = local_c + 0x210;
        }
        else {
          *(int *)(iVar11 + 0xa0) = local_18;
          puVar8 = (uint *)(*(int *)(param_1 + 0x1b8) + local_14);
          local_18 = local_18 + 1;
          local_14 = local_14 + 0x210;
        }
      }
      else if ((uVar7 & 0x100) == 0) {
        *(int *)(iVar11 + 0xa0) = local_20;
        puVar8 = (uint *)(*(int *)(param_1 + 0x1d0) + local_1c);
        local_20 = local_20 + 1;
        local_1c = local_1c + 0x210;
      }
      else {
        *(int *)(iVar11 + 0xa0) = local_28;
        puVar8 = (uint *)(*(int *)(param_1 + 0x1c8) + local_24);
        local_28 = local_28 + 1;
        local_24 = local_24 + 0x210;
      }
      uVar7 = FUN_00486720();
      puVar8[0x81] = uVar7;
      if (0 < (int)uVar7) {
        puVar4 = operator_new(uVar7 << 4);
        puVar8[0x83] = (uint)puVar4;
        for (iVar5 = (puVar8[0x81] & 0xfffffff) << 2; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined1 *)puVar4 = 0;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        *puVar8 = 0x100;
        local_30 = 0;
        if (0 < *(int *)(iVar11 + 0xa4)) {
          puVar12 = (uint *)(*(int *)(iVar11 + 0xa8) + 0x40);
          puVar10 = puVar8 + 10;
          do {
            puVar1 = (undefined *)puVar12[8];
            if ((int)puVar1 < 0x800001) {
              if (puVar1 == (undefined *)0x800000) {
LAB_00544637:
                puVar10[-1] = 8;
                *puVar10 = 1;
                puVar12[0xb] = 1;
                puVar10[1] = 1;
              }
              else if (puVar1 == (undefined *)0x100000) {
                if ((local_30 < 1) || (iVar5 = FUN_005414e0(), local_30 % iVar5 != 0)) {
                  switch(puVar12[9]) {
                  case 1:
                    puVar10[-1] = 1;
                    *puVar10 = 2;
                    puVar10[1] = puVar12[0xb];
                    break;
                  case 2:
                    puVar10[-1] = 2;
                    *puVar10 = 2;
                    puVar10[1] = puVar12[0xb];
                    break;
                  case 3:
                    puVar10[-1] = 3;
                    *puVar10 = 4;
                    puVar10[1] = puVar12[0xb];
                    break;
                  case 4:
                    *puVar10 = 2;
                    puVar10[-1] = 4;
                    puVar10[1] = puVar12[0xb];
                    break;
                  case 5:
                    puVar10[-1] = 9;
                    *puVar10 = 4;
                    puVar10[1] = puVar12[0xb];
                    break;
                  case 6:
                    puVar10[-1] = 10;
                    *puVar10 = 4;
                    puVar10[1] = puVar12[0xb];
                    break;
                  case 7:
                    puVar10[-1] = 0xb;
                    *puVar10 = 4;
                  default:
                    puVar10[1] = puVar12[0xb];
                  }
                }
                else {
                  puVar10[-1] = 1;
                  *puVar10 = 2;
                  puVar10[1] = puVar12[0xb];
                }
              }
              else if (puVar1 == (undefined *)0x400000) {
                *puVar8 = *puVar8 | 0x800;
                puVar10[-1] = 2;
                *puVar10 = 2;
                puVar10[1] = 0;
              }
            }
            else if (puVar1 == &DAT_00804000) goto LAB_00544637;
            if ((*(uint *)(iVar11 + 0x9c) & 0x800) != 0) {
              *puVar8 = *puVar8 | 4;
            }
            if ((*(byte *)(iVar11 + 0x9c) & 0x40) != 0) {
              *puVar8 = *puVar8 | 0x400;
            }
            if ((*puVar12 & 0xc) != 0) {
              puVar10[3] = 1;
            }
            if ((*(byte *)(iVar11 + 0x9c) & 0x20) != 0) {
              *puVar8 = *puVar8 | 0x800;
              *puVar10 = 2;
            }
            if ((char)(byte)*puVar12 < '\0') {
              *puVar8 = *puVar8 | 1;
              *puVar10 = 3;
            }
            if ((*puVar12 & 0x200) != 0) {
              puVar10[-1] = 6;
            }
            puVar10[4] = 0;
            if ((*puVar12 & 0x400) == 0) {
              if ((*puVar12 & 0x1000) != 0) {
                puVar10[4] = 2;
              }
            }
            else {
              puVar10[4] = 1;
            }
            puVar10[5] = 0;
            if ((*puVar12 & 0x800) == 0) {
              if ((*puVar12 & 0x2000) != 0) {
                puVar10[5] = 2;
              }
            }
            else {
              puVar10[5] = 1;
            }
            puVar12 = puVar12 + 0x25;
            local_30 = local_30 + 1;
            puVar10 = puVar10 + 0x10;
          } while (local_30 < *(int *)(iVar11 + 0xa4));
        }
      }
      local_2c = local_2c + 1;
    } while (local_2c < iVar9);
  }
  FUN_0053ced0();
  FUN_0053c9c0();
  return 0;
}


