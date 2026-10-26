// Function: FUN_00566380 @ 00566380
// Size (bytes): 287


void __thiscall FUN_00566380(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  *(undefined4 *)(*param_1 + 0x220) = param_2;
  param_1 = (int *)*param_1;
  iVar5 = 0;
  puVar9 = (undefined4 *)*param_1;
  puVar7 = puVar9;
  if (puVar9 != (undefined4 *)0x0) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      iVar5 = iVar5 + 1;
    } while (puVar7 != (undefined4 *)0x0);
    if (1 < iVar5) {
      iVar5 = iVar5 / 2 + -1;
      puVar7 = puVar9;
      if (0 < iVar5) {
        do {
          puVar7 = (undefined4 *)puVar7[1];
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      uVar1 = puVar7[1];
      puVar7[1] = 0;
      puVar6 = (undefined4 *)FUN_005664a0(puVar9);
      puVar7 = (undefined4 *)FUN_005664a0(uVar1);
      puVar9 = puVar7;
      if ((puVar6 != (undefined4 *)0x0) && (puVar9 = puVar6, puVar7 != (undefined4 *)0x0)) {
        cVar4 = FUN_00565bb0(*puVar7);
        if (cVar4 == '\0') {
          puVar2 = (undefined4 *)puVar7[1];
          puVar3 = puVar7;
          puVar10 = puVar6;
        }
        else {
          puVar3 = puVar6;
          puVar2 = puVar7;
          puVar10 = (undefined4 *)puVar6[1];
          puVar7 = puVar6;
        }
        while (puVar9 = puVar7, puVar10 != (undefined4 *)0x0) {
          if (puVar2 == (undefined4 *)0x0) {
            if (puVar10 == (undefined4 *)0x0) goto LAB_00566456;
            puVar3[1] = puVar10;
            goto LAB_00566473;
          }
          cVar4 = FUN_00565bb0(*puVar2);
          if (cVar4 == '\0') {
            puVar9 = (undefined4 *)puVar2[1];
            puVar6 = puVar2;
          }
          else {
            puVar6 = puVar10;
            puVar9 = puVar2;
            puVar10 = (undefined4 *)puVar10[1];
          }
          puVar3[1] = puVar6;
          puVar3 = puVar6;
          puVar2 = puVar9;
        }
        if (puVar2 == (undefined4 *)0x0) {
LAB_00566456:
          puVar3[1] = 0;
        }
        else {
          puVar3[1] = puVar2;
        }
      }
    }
  }
LAB_00566473:
  *param_1 = (int)puVar9;
  if ((puVar9 != (undefined4 *)0x0) && (iVar5 = puVar9[1], puVar9[1] != 0)) {
    do {
      iVar8 = iVar5;
      iVar5 = *(int *)(iVar8 + 4);
    } while (iVar5 != 0);
    param_1[1] = iVar8;
    param_1[2] = (int)puVar9;
    return;
  }
  param_1[1] = (int)puVar9;
  param_1[2] = (int)puVar9;
  return;
}


