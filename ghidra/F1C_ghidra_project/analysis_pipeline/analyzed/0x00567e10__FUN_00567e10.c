// Function: FUN_00567e10 @ 00567e10
// Size (bytes): 241


void __thiscall FUN_00567e10(int param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  
  puVar3 = *(undefined4 **)(param_1 + 0x24);
  *(undefined4 **)(param_1 + 0x2c) = puVar3;
  if (puVar3 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*puVar3;
    while (puVar3 != (undefined4 *)0x0) {
      puVar5 = *(undefined1 **)(param_2 + 4);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      puVar1 = (undefined1 *)*puVar3;
      if (puVar1 == (undefined1 *)0x0) {
        puVar1 = &DAT_005ea438;
      }
      iVar2 = FUN_00588410(puVar1,puVar5);
      if (iVar2 == 0) {
        return;
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 4);
      }
      if (*(undefined4 **)(param_1 + 0x2c) == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 0x2c);
    }
  }
  puVar3 = operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar5 = *(undefined1 **)(param_2 + 4);
    iVar2 = *(int *)(param_1 + 0x34);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    *(int *)(param_1 + 0x34) = iVar2 + 1;
    *puVar3 = 0;
    puVar3[1] = 0xffffffff;
    FUN_00566650(puVar5);
    puVar3[2] = iVar2;
  }
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = operator_new(0xc);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = puVar3;
      puVar4[1] = 0;
      *(undefined1 *)(puVar4 + 2) = 1;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 **)(param_1 + 0x24) = puVar4;
      *(undefined4 **)(param_1 + 0x2c) = puVar4;
      *(undefined4 **)(param_1 + 0x28) = puVar4;
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      return;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x28) + 4) = puVar4;
    *(undefined4 **)(param_1 + 0x28) = puVar4;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  }
  return;
}


