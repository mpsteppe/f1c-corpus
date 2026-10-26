// Function: FUN_004339e0 @ 004339e0
// Size (bytes): 370


undefined4 __thiscall FUN_004339e0(int param_1,char *param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  *param_2 = '\0';
  if (*(char *)(param_1 + 0x18) == '\0') {
    FUN_00432e70();
  }
  puVar1 = DAT_007ce64c;
  if (DAT_007ce64c == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_004c40b0(puVar1);
  if ((*(char *)(param_1 + 0x18) != '\0') && (0 < *(int *)(param_1 + 0x28))) {
    iVar3 = FUN_00432e50(DAT_007c56a4);
    uVar4 = FUN_004326a0();
    puVar8 = *(undefined4 **)(param_1 + 0x1c);
    puVar7 = (undefined4 *)0x0;
    *(undefined4 **)(param_1 + 0x24) = puVar8;
    if ((puVar8 != (undefined4 *)0x0) &&
       (puVar8 = (undefined4 *)*puVar8, puVar8 != (undefined4 *)0x0)) {
      do {
        puVar1 = (undefined1 *)*puVar8;
        if (puVar1 == (undefined1 *)0x0) {
          puVar1 = &DAT_005ea438;
        }
        iVar5 = FUN_00588410(uVar4,puVar1);
        if (iVar5 == 0) {
          pcVar6 = (char *)puVar8[2];
          if (pcVar6 == (char *)0x0) {
            pcVar6 = &DAT_005ea438;
          }
          if ((*pcVar6 != '\0') && (iVar2 != 0)) {
            puVar1 = (undefined1 *)puVar8[2];
            if (puVar1 == (undefined1 *)0x0) {
              puVar1 = &DAT_005ea438;
            }
            iVar5 = FUN_00588410(iVar2 + 0x1bc,puVar1);
            if (iVar5 != 0) goto LAB_00433ad8;
          }
          if (puVar7 == (undefined4 *)0x0) {
            puVar7 = puVar8;
          }
          if ((puVar8[4] == iVar3) && (puVar7[4] != iVar3)) {
            puVar7 = puVar8;
          }
        }
LAB_00433ad8:
        if (*(int *)(param_1 + 0x24) == 0) goto LAB_00433aef;
        puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x24) + 4);
        *(undefined4 **)(param_1 + 0x24) = puVar8;
        if ((puVar8 == (undefined4 *)0x0) ||
           (puVar8 = (undefined4 *)*puVar8, puVar8 == (undefined4 *)0x0)) goto LAB_00433aef;
      } while( true );
    }
  }
LAB_00433b29:
  _strncpy(param_2,&DAT_005ea438,param_3 - 1U);
  param_2[param_3 - 1U] = '\0';
  return 1;
LAB_00433aef:
  if (puVar7 != (undefined4 *)0x0) {
    pcVar6 = (char *)puVar7[5];
    if (pcVar6 == (char *)0x0) {
      pcVar6 = &DAT_005ea438;
    }
    _strncpy(param_2,pcVar6,param_3 - 1U);
    param_2[param_3 - 1U] = '\0';
    return 0;
  }
  goto LAB_00433b29;
}


