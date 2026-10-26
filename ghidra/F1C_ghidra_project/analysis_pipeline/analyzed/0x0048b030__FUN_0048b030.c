// Function: FUN_0048b030 @ 0048b030
// Size (bytes): 993


void __thiscall FUN_0048b030(int param_1,undefined4 *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  bool bVar11;
  undefined4 *local_24;
  char *local_20;
  undefined4 *local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_8;
  undefined4 local_7;
  undefined2 local_3;
  undefined1 local_1;
  
  uVar8 = 0;
  if (param_2 != (undefined4 *)0x0) {
    local_10 = 0;
    local_14 = 0;
    local_18 = 0;
    iVar4 = FUN_00487060(1);
    local_c = FUN_00487060(0);
    local_c = iVar4 - local_c;
    FUN_004870e0(1);
    FUN_004870e0(0);
    local_20 = (char *)*param_2;
    if (local_20 == (char *)0x0) {
      local_20 = &DAT_005ea438;
    }
    local_24 = operator_new(8);
    if (local_24 == (undefined4 *)0x0) {
      local_24 = (undefined4 *)0x0;
    }
    else {
      *local_24 = 0;
      local_24[1] = 0xffffffff;
    }
    local_1c = operator_new(8);
    if (local_1c == (undefined4 *)0x0) {
      local_1c = (undefined4 *)0x0;
    }
    else {
      *local_1c = 0;
      local_1c[1] = 0xffffffff;
    }
    piVar3 = *(int **)(param_1 + 0xec);
    while (piVar3 != (int *)0x0) {
      piVar2 = (int *)piVar3[1];
      if (((char)piVar3[2] != '\0') && (*piVar3 != 0)) {
        FUN_00404f70(1);
      }
      FUN_00587bcf(piVar3);
      piVar3 = piVar2;
    }
    *(undefined4 *)(param_1 + 0xec) = 0;
    *(undefined4 *)(param_1 + 0xf0) = 0;
    *(undefined4 *)(param_1 + 0xf4) = 0;
    *(undefined4 *)(param_1 + 0xf8) = 0;
    puVar5 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x40);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_00498560(puVar5);
    iVar4 = -1;
    pcVar10 = local_20;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      do {
        local_7 = 0;
        local_3 = 0;
        local_1 = 0;
        local_10 = 0;
        local_14 = 0;
        local_8 = local_20[uVar8];
        FUN_005665b0(&local_8);
        bVar11 = local_8 == '\n';
        if ((local_8 == ' ') || (bVar11)) {
          puVar5 = (undefined1 *)*local_1c;
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          FUN_004983b0(puVar5,&local_10,&local_14,1);
          if (local_c < local_10) {
            if (local_24 != (undefined4 *)0x0) {
              puVar6 = operator_new(0xc);
              if (puVar6 == (undefined4 *)0x0) {
                puVar6 = (undefined4 *)0x0;
              }
              else {
                *puVar6 = local_24;
                puVar6[1] = 0;
                *(undefined1 *)(puVar6 + 2) = 1;
              }
              if (*(int *)(param_1 + 0xec) == 0) {
                *(undefined4 **)(param_1 + 0xec) = puVar6;
                *(undefined4 **)(param_1 + 0xf4) = puVar6;
              }
              else {
                *(undefined4 **)(*(int *)(param_1 + 0xf0) + 4) = puVar6;
              }
              *(undefined4 **)(param_1 + 0xf0) = puVar6;
              *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
            }
            local_24 = operator_new(8);
            if (local_24 == (undefined4 *)0x0) {
              local_24 = (undefined4 *)0x0;
            }
            else {
              *local_24 = 0;
              local_24[1] = 0xffffffff;
            }
            FUN_00566650(&DAT_005ea438);
            uVar9 = local_18;
            if (local_18 <= uVar8) {
              do {
                local_8 = local_20[uVar9];
                FUN_005665b0(&local_8);
                uVar9 = uVar9 + 1;
              } while (uVar9 <= uVar8);
              goto joined_r0x0048b27a;
            }
          }
          else {
joined_r0x0048b27a:
            for (; local_18 <= uVar8; local_18 = local_18 + 1) {
              local_8 = local_20[local_18];
              FUN_005665b0(&local_8);
            }
          }
          if (bVar11) {
            if (local_24 != (undefined4 *)0x0) {
              puVar6 = operator_new(0xc);
              if (puVar6 == (undefined4 *)0x0) {
                puVar6 = (undefined4 *)0x0;
              }
              else {
                *puVar6 = local_24;
                puVar6[1] = 0;
                *(undefined1 *)(puVar6 + 2) = 1;
              }
              if (*(int *)(param_1 + 0xec) == 0) {
                *(undefined4 **)(param_1 + 0xec) = puVar6;
                *(undefined4 **)(param_1 + 0xf4) = puVar6;
              }
              else {
                *(undefined4 **)(*(int *)(param_1 + 0xf0) + 4) = puVar6;
              }
              *(undefined4 **)(param_1 + 0xf0) = puVar6;
              *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
            }
            local_24 = operator_new(8);
            if (local_24 == (undefined4 *)0x0) {
              local_24 = (undefined4 *)0x0;
            }
            else {
              *local_24 = 0;
              local_24[1] = 0xffffffff;
            }
            FUN_00566650(&DAT_005ea438);
          }
        }
        uVar9 = 0xffffffff;
        pcVar10 = local_20;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        if (uVar8 == ~uVar9 - 2) {
          for (; local_18 <= uVar8; local_18 = local_18 + 1) {
            local_8 = local_20[local_18];
            FUN_005665b0(&local_8);
          }
          if (local_24 != (undefined4 *)0x0) {
            puVar6 = operator_new(0xc);
            if (puVar6 == (undefined4 *)0x0) {
              puVar6 = (undefined4 *)0x0;
            }
            else {
              *puVar6 = local_24;
              puVar6[1] = 0;
              *(undefined1 *)(puVar6 + 2) = 1;
            }
            if (*(int *)(param_1 + 0xec) == 0) {
              *(undefined4 **)(param_1 + 0xec) = puVar6;
              *(undefined4 **)(param_1 + 0xf4) = puVar6;
            }
            else {
              *(undefined4 **)(*(int *)(param_1 + 0xf0) + 4) = puVar6;
            }
            *(undefined4 **)(param_1 + 0xf0) = puVar6;
            *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
          }
        }
        uVar9 = 0xffffffff;
        uVar8 = uVar8 + 1;
        pcVar10 = local_20;
        do {
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
      } while (uVar8 < ~uVar9 - 1);
    }
    if (local_14 != 0) {
      iVar4 = FUN_004870e0(1);
      iVar7 = FUN_004870e0(0);
      *(int *)(param_1 + 0x108) = (iVar4 - iVar7) / local_14;
    }
  }
  return;
}


