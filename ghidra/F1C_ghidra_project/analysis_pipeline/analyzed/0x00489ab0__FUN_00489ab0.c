// Function: FUN_00489ab0 @ 00489ab0
// Size (bytes): 227


undefined4 __thiscall FUN_00489ab0(int *param_1,int param_2,char param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  if ((param_1[0x25] < param_2) || (param_2 < 1)) {
    param_1[0x5a] = -1;
  }
  else {
    param_2 = param_2 + -1;
    param_1[0x5a] = param_2;
    if ((param_3 != '\0') &&
       ((param_2 < param_1[0x53] || (param_1[0x59] + param_1[0x53] <= param_2)))) {
      param_1[0x53] = param_2;
      FUN_00489d00();
      FUN_00489e90();
    }
    iVar1 = param_1[0x24];
    iVar3 = 0;
    if (iVar1 != 0) {
      do {
        if (iVar3 == param_1[0x5a]) {
          puVar4 = *(undefined1 **)(iVar1 + 0xa8);
          if (puVar4 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          puVar6 = *(undefined1 **)(iVar1 + 0xa0);
          if (puVar6 == (undefined1 *)0x0) {
            puVar6 = &DAT_005ea438;
          }
          puVar5 = *(undefined1 **)(iVar1 + 0xb8);
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          puVar2 = *(undefined1 **)(iVar1 + 0xb0);
          if (puVar2 == (undefined1 *)0x0) {
            puVar2 = &DAT_005ea438;
          }
          (**(code **)(*param_1 + 0xa8))(puVar2,puVar5,puVar6,puVar4);
          return 0;
        }
        iVar1 = *(int *)(iVar1 + 0x8c);
        iVar3 = iVar3 + 1;
      } while (iVar1 != 0);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}


