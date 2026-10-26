// Function: FUN_004c4ff0 @ 004c4ff0
// Size (bytes): 124


void __thiscall FUN_004c4ff0(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 0x10) = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)*puVar2;
  }
  iVar5 = 0;
  while (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(*piVar1 * 0x424 + DAT_008ac394);
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = (undefined1 *)*puVar2;
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      iVar4 = FUN_00588410(param_2,puVar3);
      if (iVar4 == 0) {
        *(int *)(param_1 + 0x18) = iVar5;
        return;
      }
    }
    iVar5 = iVar5 + 1;
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
    }
    if (*(undefined4 **)(param_1 + 0x10) == (undefined4 *)0x0) break;
    piVar1 = (int *)**(undefined4 **)(param_1 + 0x10);
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


