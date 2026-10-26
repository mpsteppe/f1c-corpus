// Function: FUN_00489fd0 @ 00489fd0
// Size (bytes): 617


undefined4 __thiscall FUN_00489fd0(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  int local_24;
  int local_20;
  int iStack_14;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  iVar2 = param_1[0x53];
  piVar6 = (int *)param_1[0x24];
  local_24 = 0;
  piVar7 = piVar6;
  if (0 < iVar2) {
    local_24 = 0;
    do {
      piVar7 = (int *)0x0;
      if (piVar6 == (int *)0x0) break;
      piVar6 = (int *)piVar6[0x23];
      iVar2 = iVar2 + -1;
      local_24 = local_24 + 1;
      piVar7 = piVar6;
    } while (0 < iVar2);
  }
  FUN_00489d00();
  local_20 = 0;
  if ((param_1[0x56] < 1) || (param_1[0x5b] < 1)) {
    return 0xffffffff;
  }
  iVar2 = param_1[0x59];
  do {
    if ((piVar7 == (int *)0x0) || (iVar2 < 1)) {
      return 0;
    }
    iVar8 = param_1[0x56] * local_20 + param_1[0x4f] + param_1[0x4d] + param_1[1];
    iVar3 = (**(code **)(*param_1 + 0x18))();
    if (iVar3 < 1) {
      iStack_14 = param_1[4];
    }
    else {
      iStack_14 = (**(code **)(*param_1 + 0x18))();
    }
    if (local_24 == param_1[0x5a]) {
      if (param_1[0x32] != 0) {
        puVar5 = *(undefined1 **)(param_1[0x32] + 0x48);
LAB_0048a11c:
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        FUN_00498560(puVar5);
      }
    }
    else {
      pcVar4 = (char *)piVar7[0x28];
      if (pcVar4 == (char *)0x0) {
        pcVar4 = &DAT_005ea438;
      }
      iVar3 = -1;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      if (iVar3 != -2) {
        puVar5 = (undefined1 *)piVar7[0x28];
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        FUN_00497ec0(puVar5);
        puVar5 = (undefined1 *)piVar7[0x28];
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        iVar3 = FUN_00497f90(puVar5);
        if (iVar3 != 0) {
          puVar5 = (undefined1 *)piVar7[0x28];
          goto LAB_0048a11c;
        }
      }
      if (param_1[0x32] != 0) {
        puVar5 = *(undefined1 **)(param_1[0x32] + 0x40);
        goto LAB_0048a11c;
      }
    }
    iVar10 = param_1[0x56] + iVar8;
    iStack_14 = iStack_14 - param_1[0x50];
    iVar9 = param_1[3] + param_1[0x50];
    *(undefined1 *)(piVar7 + 0x39) = *(undefined1 *)((int)param_1 + 0x131);
    FUN_0049a9c0(iVar8,iVar10,iVar9,iStack_14);
    (**(code **)(*piVar7 + 0x34))(auStack_4,auStack_8,auStack_c,auStack_10);
    bVar11 = local_20 != 0;
    iVar3 = iVar8;
    if ((bVar11) && (iVar3 = *param_2, iVar8 < *param_2)) {
      iVar3 = iVar8;
    }
    *param_2 = iVar3;
    if ((bVar11) && (iVar10 <= *param_3)) {
      iVar10 = *param_3;
    }
    *param_3 = iVar10;
    if ((bVar11) && (*param_4 <= iVar9)) {
      iVar9 = *param_4;
    }
    *param_4 = iVar9;
    iVar3 = iStack_14;
    if ((bVar11) && (iVar3 = *param_5, *param_5 < iStack_14)) {
      iVar3 = iStack_14;
    }
    *param_5 = iVar3;
    piVar7 = (int *)piVar7[0x23];
    iVar2 = iVar2 + -1;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
  } while( true );
}


