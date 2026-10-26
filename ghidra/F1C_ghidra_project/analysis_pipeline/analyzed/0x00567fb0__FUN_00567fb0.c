// Function: FUN_00567fb0 @ 00567fb0
// Size (bytes): 566


int __thiscall
FUN_00567fb0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char local_200;
  undefined4 local_1ff;
  char local_100;
  undefined4 local_ff;
  
  local_200 = DAT_005ea438;
  local_100 = DAT_005ea438;
  puVar8 = &local_1ff;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  *(undefined1 *)((int)puVar8 + 2) = 0;
  iVar5 = 0;
  puVar8 = &local_ff;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  *(undefined1 *)((int)puVar8 + 2) = 0;
  if (param_2 == 0) {
    return 0;
  }
  thunk_FUN_00567b10(param_2,&local_200);
  thunk_FUN_00567b10(param_3,&local_100);
  iVar6 = FUN_00567d00(&local_200);
  if ((-1 < iVar6) && (iVar6 < 9)) {
    pvVar3 = operator_new(0x2c);
    if (pvVar3 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_00567900(param_5);
    }
    if (param_5 == 0) {
      uVar4 = FUN_00568220(param_4);
      FUN_004979c0(uVar4);
    }
    FUN_00566650(&local_200);
    iVar7 = -1;
    pcVar9 = &local_100;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (iVar7 != -2) {
      FUN_00566650(&local_100);
    }
    if (param_5 != 0) {
      iVar6 = FUN_005679c0(&local_200);
      if (iVar6 == 0) {
        iVar6 = *(int *)(param_5 + 8);
        if (iVar6 != 0) {
          for (iVar7 = *(int *)(iVar6 + 4); iVar7 != 0; iVar7 = *(int *)(iVar7 + 4)) {
            iVar6 = iVar7;
          }
          *(int *)(iVar6 + 4) = iVar5;
          *(int *)(iVar5 + 0x24) = iVar6;
          return iVar5;
        }
        *(int *)(param_5 + 8) = iVar5;
        return iVar5;
      }
      if (*(int *)(iVar6 + 0xc) != 0) {
        iVar7 = *(int *)(iVar6 + 0xc);
        while (iVar2 = iVar7, iVar2 != 0) {
          iVar6 = iVar2;
          iVar7 = *(int *)(iVar2 + 0xc);
        }
        *(int *)(iVar6 + 0xc) = iVar5;
        *(int *)(iVar5 + 0x28) = iVar6;
        return iVar5;
      }
      *(int *)(iVar6 + 0xc) = iVar5;
      *(int *)(iVar5 + 0x28) = iVar6;
      return iVar5;
    }
    iVar7 = FUN_00568210(&local_200);
    if (iVar7 != 0) {
      if (*(int *)(iVar7 + 0xc) != 0) {
        iVar6 = *(int *)(iVar7 + 0xc);
        while (iVar2 = iVar6, iVar2 != 0) {
          iVar7 = iVar2;
          iVar6 = *(int *)(iVar2 + 0xc);
        }
        *(int *)(iVar7 + 0xc) = iVar5;
        *(int *)(iVar5 + 0x28) = iVar7;
        return iVar5;
      }
      *(int *)(iVar7 + 0xc) = iVar5;
      *(int *)(iVar5 + 0x28) = iVar7;
      return iVar5;
    }
    iVar7 = *(int *)(param_1 + iVar6 * 4);
    if (iVar7 == 0) {
      *(int *)(param_1 + iVar6 * 4) = iVar5;
      return iVar5;
    }
    for (iVar6 = *(int *)(iVar7 + 4); iVar6 != 0; iVar6 = *(int *)(iVar6 + 4)) {
      iVar7 = iVar6;
    }
    *(int *)(iVar7 + 4) = iVar5;
    *(int *)(iVar5 + 0x24) = iVar7;
  }
  return iVar5;
}


