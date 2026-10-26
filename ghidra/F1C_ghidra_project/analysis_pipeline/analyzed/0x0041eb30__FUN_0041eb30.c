// Function: FUN_0041eb30 @ 0041eb30
// Size (bytes): 488


uint __fastcall FUN_0041eb30(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint local_74;
  int local_68 [26];
  
  local_74 = 0;
  iVar1 = FUN_004c2850();
  if (iVar1 == 0) {
    return 0;
  }
  FUN_004c2850();
  iVar1 = FUN_004c11d0();
  FUN_004c2850();
  iVar2 = FUN_004c1370();
  piVar9 = local_68;
  for (iVar8 = 0x1a; iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  if (iVar1 < 2) {
    return 0;
  }
  iVar8 = 0;
  if (0 < iVar1 + -1) {
    do {
      FUN_004c2850();
      FUN_004c1390();
      iVar3 = FUN_0041ed20();
      local_68[0] = local_68[0] + iVar3;
      iVar3 = 0;
      if (0 < iVar2) {
        do {
          iVar4 = iVar3;
          FUN_004c2850(iVar3);
          FUN_004c13a0(iVar4);
          iVar4 = FUN_0041ed20();
          local_68[iVar3 + 1] = local_68[iVar3 + 1] + iVar4;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar2);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar1 + -1);
  }
  if (param_1 != 0) {
    FUN_004c2850();
    puVar5 = (undefined4 *)FUN_004c1390();
    puVar6 = (undefined1 *)*puVar5;
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    iVar1 = FUN_00588410(puVar6,param_1);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_0041ec4a;
    }
  }
  iVar1 = local_68[0];
  FUN_004c2850();
  local_74 = FUN_004c1390();
LAB_0041ec4a:
  iVar8 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = local_68[iVar8 + 1];
      if (iVar1 < iVar3) {
        if (param_1 != 0) {
          iVar4 = iVar8;
          FUN_004c2850(iVar8);
          puVar5 = (undefined4 *)FUN_004c13a0(iVar4);
          puVar6 = (undefined1 *)*puVar5;
          if (puVar6 == (undefined1 *)0x0) {
            puVar6 = &DAT_005ea438;
          }
          iVar4 = FUN_00588410(puVar6,param_1);
          if (iVar4 == 0) goto LAB_0041ecab;
        }
        iVar1 = iVar8;
        FUN_004c2850(iVar8);
        local_74 = FUN_004c13a0(iVar1);
        iVar1 = iVar3;
      }
LAB_0041ecab:
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar2);
  }
  FUN_004c2850();
  uVar7 = FUN_004c1390();
  if ((local_74 != uVar7) && (iVar1 == local_68[0])) {
LAB_0041eccf:
    return -(uint)(param_2 != '\0') & local_74;
  }
  iVar8 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = iVar8;
      FUN_004c2850(iVar8);
      uVar7 = FUN_004c13a0(iVar3);
      if ((local_74 != uVar7) && (iVar1 == local_68[iVar8 + 1])) goto LAB_0041eccf;
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar2);
  }
  return local_74;
}


