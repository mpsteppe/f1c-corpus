// Function: FUN_00433b60 @ 00433b60
// Size (bytes): 510


undefined4 __thiscall FUN_00433b60(int param_1,undefined4 param_2,int param_3,char param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  uVar8 = 1;
  if (param_3 == 0) {
    param_3 = FUN_004326a0();
  }
  uVar1 = FUN_00432e50(DAT_007c56a4);
  puVar2 = DAT_007ce64c;
  if (DAT_007ce64c == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  iVar3 = FUN_004c40b0(puVar2);
  puVar6 = *(undefined4 **)(param_1 + 0x1c);
  *(undefined4 **)(param_1 + 0x24) = puVar6;
  if (puVar6 != (undefined4 *)0x0) {
    puVar6 = (undefined4 *)*puVar6;
    while (puVar6 != (undefined4 *)0x0) {
      puVar2 = (undefined1 *)*puVar6;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar4 = FUN_00588410(param_3,puVar2);
      if (iVar4 == 0) {
        pcVar5 = (char *)puVar6[2];
        if (pcVar5 == (char *)0x0) {
          pcVar5 = &DAT_005ea438;
        }
        if ((*pcVar5 != '\0') && (iVar3 != 0)) {
          puVar2 = (undefined1 *)puVar6[2];
          if (puVar2 == (undefined1 *)0x0) {
            puVar2 = &DAT_005ea438;
          }
          iVar4 = FUN_00588410(iVar3 + 0x1bc,puVar2);
          if (iVar4 != 0) goto LAB_00433c2a;
        }
        if (param_4 == '\0') {
          return 1;
        }
        FUN_00566650(param_2);
        puVar2 = &DAT_005ea438;
        if (iVar3 != 0) {
          puVar2 = (undefined1 *)(iVar3 + 0x1bc);
        }
        FUN_00566650(puVar2);
        uVar8 = 0;
        goto LAB_00433d39;
      }
LAB_00433c2a:
      if (*(int *)(param_1 + 0x24) != 0) {
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 4);
      }
      if (*(undefined4 **)(param_1 + 0x24) == (undefined4 *)0x0) break;
      puVar6 = (undefined4 *)**(undefined4 **)(param_1 + 0x24);
    }
  }
  puVar6 = operator_new(0x1c);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0;
    puVar6[1] = 0xffffffff;
    puVar6[2] = 0;
    puVar6[3] = 0xffffffff;
    puVar6[5] = 0;
    puVar6[6] = 0xffffffff;
    FUN_00432cc0();
    if (iVar3 == 0) {
      puVar2 = &DAT_005ea438;
    }
    else {
      puVar2 = (undefined1 *)(iVar3 + 0x1bc);
    }
    FUN_00566650(param_3);
    FUN_00566650(puVar2);
    puVar6[4] = uVar1;
    FUN_00566650(param_2);
    puVar7 = operator_new(0xc);
    uVar8 = 0;
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      *puVar7 = puVar6;
      puVar7[1] = 0;
      *(undefined1 *)(puVar7 + 2) = 1;
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
      *(undefined4 **)(param_1 + 0x1c) = puVar7;
      *(undefined4 **)(param_1 + 0x24) = puVar7;
    }
    else {
      *(undefined4 **)(*(int *)(param_1 + 0x20) + 4) = puVar7;
    }
    *(undefined4 **)(param_1 + 0x20) = puVar7;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  }
LAB_00433d39:
  FUN_00566650(param_2);
  FUN_004330d0(&DAT_007ce498);
  return uVar8;
}


