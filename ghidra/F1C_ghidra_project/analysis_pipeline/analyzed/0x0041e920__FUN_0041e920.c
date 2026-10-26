// Function: FUN_0041e920 @ 0041e920
// Size (bytes): 516


int __fastcall FUN_0041e920(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = -1;
  iVar4 = 0;
  iVar1 = FUN_004c2850();
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 != 0) {
    FUN_004c2850();
    puVar2 = (undefined4 *)FUN_004c1390();
    puVar3 = (undefined1 *)*puVar2;
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    iVar1 = FUN_00588410(param_1,puVar3);
    if (iVar1 == 0) goto LAB_0041e9b3;
  }
  FUN_004c2850();
  iVar1 = FUN_004c1390();
  if (-1 < *(int *)(iVar1 + 0x198)) {
    FUN_004c2850();
    iVar4 = FUN_004c1390();
    FUN_004c2850();
    iVar6 = FUN_004c1390();
    iVar6 = *(int *)(iVar6 + 0x198);
  }
LAB_0041e9b3:
  iVar5 = 0;
  FUN_004c2850();
  iVar1 = FUN_004c1370();
  if (0 < iVar1) {
    do {
      iVar1 = iVar5;
      FUN_004c2850(iVar5);
      iVar1 = FUN_004c13a0(iVar1);
      if (iVar6 < *(int *)(iVar1 + 0x198)) {
        if (param_1 != 0) {
          iVar1 = iVar5;
          FUN_004c2850(iVar5);
          puVar2 = (undefined4 *)FUN_004c13a0(iVar1);
          puVar3 = (undefined1 *)*puVar2;
          if (puVar3 == (undefined1 *)0x0) {
            puVar3 = &DAT_005ea438;
          }
          iVar1 = FUN_00588410(param_1,puVar3);
          if (iVar1 == 0) goto LAB_0041ea45;
        }
        iVar6 = iVar5;
        FUN_004c2850(iVar5);
        iVar4 = FUN_004c13a0(iVar6);
        iVar6 = iVar5;
        FUN_004c2850(iVar5);
        iVar6 = FUN_004c13a0(iVar6);
        iVar6 = *(int *)(iVar6 + 0x198);
      }
LAB_0041ea45:
      iVar5 = iVar5 + 1;
      FUN_004c2850();
      iVar1 = FUN_004c1370();
    } while (iVar5 < iVar1);
  }
  if (param_2 == '\0') {
    if (iVar4 == 0) {
      return 0;
    }
    FUN_004c2850();
    iVar6 = FUN_004c1390();
    if (iVar4 != iVar6) {
      iVar6 = *(int *)(iVar4 + 0x198);
      FUN_004c2850();
      iVar1 = FUN_004c1390();
      if (iVar6 == *(int *)(iVar1 + 0x198)) {
        return 0;
      }
    }
    iVar1 = 0;
    FUN_004c2850();
    iVar6 = FUN_004c1370();
    if (0 < iVar6) {
      do {
        iVar6 = iVar1;
        FUN_004c2850(iVar1);
        iVar6 = FUN_004c13a0(iVar6);
        if (iVar4 != iVar6) {
          iVar6 = *(int *)(iVar4 + 0x198);
          iVar5 = iVar1;
          FUN_004c2850(iVar1);
          iVar5 = FUN_004c13a0(iVar5);
          if (iVar6 == *(int *)(iVar5 + 0x198)) {
            return 0;
          }
        }
        iVar1 = iVar1 + 1;
        FUN_004c2850();
        iVar6 = FUN_004c1370();
      } while (iVar1 < iVar6);
    }
  }
  return iVar4;
}


