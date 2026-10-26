// Function: FUN_004896c0 @ 004896c0
// Size (bytes): 597


undefined4 __thiscall FUN_004896c0(int *param_1,char *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iStack_318;
  char *local_314;
  undefined1 auStack_310 [3];
  char acStack_30d [2];
  undefined4 uStack_30b;
  undefined1 uStack_2bd;
  char local_2bc [699];
  undefined1 local_1;
  
  if (param_2 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_1[0x32] != 0) {
    puVar4 = *(undefined1 **)(param_1[0x32] + 0x40);
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_00498560(puVar4);
  }
  _strncpy(local_2bc,param_2,700);
  iVar8 = param_1[0x50];
  iVar6 = param_1[3];
  local_314 = local_2bc;
  local_1 = 0;
  iVar5 = (**(code **)(*param_1 + 0x18))();
  iVar8 = (iVar5 - (iVar6 + iVar8)) - param_1[0x50];
  FUN_004983b0(local_2bc,&iStack_318,auStack_310,1);
  bVar3 = true;
  while (iVar8 < iStack_318) {
    puVar9 = &uStack_30b;
    for (iVar6 = 0x13; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    *(undefined2 *)puVar9 = 0;
    *(undefined1 *)((int)puVar9 + 2) = 0;
    acStack_30d[1] = DAT_005ea438;
    _strncpy(acStack_30d + 1,local_314,0x4f);
    uVar7 = 0xffffffff;
    uStack_2bd = 0;
    pcVar10 = acStack_30d;
    do {
      pcVar10 = pcVar10 + 1;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
    } while (*pcVar10 != '\0');
    iVar6 = ~uVar7 - 1;
    FUN_004983b0(acStack_30d + 1,&iStack_318,auStack_310,1);
    while (iVar8 < iStack_318) {
      if (iVar6 < 1) goto LAB_00489858;
      bVar2 = false;
      do {
        if (bVar2) break;
        if ((acStack_30d[iVar6] == ' ') || (!bVar3)) {
          bVar2 = true;
        }
        acStack_30d[iVar6] = '\0';
        pcVar10 = acStack_30d;
        uVar7 = 0xffffffff;
        do {
          pcVar10 = pcVar10 + 1;
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
        } while (*pcVar10 != '\0');
        iVar6 = ~uVar7 - 1;
      } while (0 < iVar6);
      FUN_004983b0(acStack_30d + 1,&iStack_318,auStack_310,1);
    }
    if (iVar6 < 1) {
LAB_00489858:
      bVar3 = false;
    }
    else {
      FUN_00489600(acStack_30d + 1,0,0,0,0);
      if (param_3 != 0) {
        FUN_00489c10(param_1[0x25] + -1,param_3);
      }
    }
    uVar7 = 0xffffffff;
    pcVar10 = acStack_30d;
    do {
      pcVar10 = pcVar10 + 1;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
    } while (*pcVar10 != '\0');
    local_314 = local_314 + (~uVar7 - 1);
    cVar1 = *local_314;
    while (cVar1 == ' ') {
      pcVar10 = local_314 + 1;
      local_314 = local_314 + 1;
      cVar1 = *pcVar10;
    }
    FUN_004983b0(local_314,&iStack_318,auStack_310,1);
  }
  iVar8 = -1;
  pcVar10 = local_314;
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  if ((iVar8 != -2) && (FUN_00489600(local_314,0,0,0,0), param_3 != 0)) {
    FUN_00489c10(param_1[0x25] + -1,param_3);
  }
  FUN_00489d00();
  (**(code **)(*param_1 + 0x2c))(1);
  return 0;
}


