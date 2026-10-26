// Function: FUN_004b6a10 @ 004b6a10
// Size (bytes): 639


undefined1 __thiscall FUN_004b6a10(int param_1,undefined4 param_2,float param_3,float param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  float *pfVar7;
  float *pfVar8;
  undefined1 uVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  int *piVar13;
  float *pfVar14;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  float local_4;
  
  uVar5 = param_2;
  local_15 = 1;
  FUN_00566d30();
  FUN_00566bd0(PTR_DAT_005d2434,4);
  FUN_00566bd0(&DAT_005d2438,4);
  pcVar10 = *(char **)(param_1 + 0x724);
  if (pcVar10 == (char *)0x0) {
    pcVar10 = &DAT_005ea438;
  }
  uVar6 = 0xffffffff;
  pcVar12 = pcVar10;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  local_14 = ~uVar6 - 1;
  FUN_00566bd0(&local_14,4);
  FUN_00566bd0(pcVar10,local_14);
  pcVar10 = *(char **)(param_1 + 0x72c);
  if (pcVar10 == (char *)0x0) {
    pcVar10 = &DAT_005ea438;
  }
  uVar6 = 0xffffffff;
  pcVar12 = pcVar10;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  local_14 = ~uVar6 - 1;
  FUN_00566bd0(&local_14,4);
  FUN_00566bd0(pcVar10,local_14);
  param_2 = CONCAT31(param_2._1_3_,*(undefined1 *)(param_1 + 0xf1c));
  FUN_00566bd0(&param_2,1);
  local_17 = *(undefined1 *)(param_1 + 0xf20);
  FUN_00566bd0(&local_17,1);
  local_14 = FUN_004b5e30();
  FUN_00566bd0(&local_14,4);
  iVar11 = 0;
  piVar13 = (int *)(param_1 + 0x48);
  local_8 = 0x68;
  do {
    piVar2 = (int *)piVar13[-2];
    *piVar13 = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      iVar3 = *piVar2;
      while (iVar3 != 0) {
        FUN_004b4fb0(uVar5);
        iVar11 = iVar11 + 1;
        if (*piVar13 != 0) {
          *piVar13 = *(int *)(*piVar13 + 4);
        }
        if ((int *)*piVar13 == (int *)0x0) break;
        iVar3 = *(int *)*piVar13;
      }
    }
    piVar13 = piVar13 + 4;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  local_16 = *(undefined1 *)(param_1 + 0x6cc);
  FUN_00566bd0(&local_16,1);
  piVar13 = *(int **)(param_1 + 0x6c0);
  *(int **)(param_1 + 0x6c8) = piVar13;
  if ((piVar13 != (int *)0x0) && (*piVar13 != 0)) {
    while( true ) {
      FUN_004b41e0(uVar5);
      if (*(int *)(param_1 + 0x6c8) == 0) break;
      piVar13 = *(int **)(*(int *)(param_1 + 0x6c8) + 4);
      *(int **)(param_1 + 0x6c8) = piVar13;
      if ((piVar13 == (int *)0x0) || (*piVar13 == 0)) break;
    }
  }
  uVar9 = local_15;
  if (local_14 != iVar11) {
    uVar9 = 0;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x714);
  pfVar8 = (float *)0x0;
  pfVar14 = (float *)0x0;
  local_10 = 0;
  local_c = 0;
  *(undefined4 **)(param_1 + 0x71c) = puVar4;
  if ((puVar4 != (undefined4 *)0x0) && (pfVar7 = (float *)*puVar4, pfVar7 != (float *)0x0)) {
    while( true ) {
      if (param_4 < *pfVar7) break;
      if (param_3 <= *pfVar7) {
        if (pfVar14 == (float *)0x0) {
          pfVar14 = pfVar7;
        }
        local_10 = local_10 + 1;
        local_c = local_c + (uint)*(ushort *)(pfVar7 + 2);
        pfVar8 = pfVar7;
      }
      if (*(int *)(param_1 + 0x71c) != 0) {
        *(undefined4 *)(param_1 + 0x71c) = *(undefined4 *)(*(int *)(param_1 + 0x71c) + 4);
      }
      if ((*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) ||
         (pfVar7 = (float *)**(undefined4 **)(param_1 + 0x71c), pfVar7 == (float *)0x0)) break;
    }
    if ((pfVar14 != (float *)0x0) && (pfVar8 != (float *)0x0)) {
      FUN_00566bd0(&local_10,4);
      FUN_00566bd0(&local_c,4);
      local_4 = param_4 - param_3;
      FUN_00566bd0(&local_4,4);
      return uVar9;
    }
  }
  return 0;
}


