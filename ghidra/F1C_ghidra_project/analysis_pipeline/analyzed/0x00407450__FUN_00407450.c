// Function: FUN_00407450 @ 00407450
// Size (bytes): 207


void __thiscall FUN_00407450(int param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_2 != 0) {
    puVar3 = *(undefined4 **)(param_1 + 0x28);
    *(undefined4 **)(param_1 + 0x30) = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)*puVar3;
      while (puVar3 != (undefined4 *)0x0) {
        puVar1 = (undefined1 *)*puVar3;
        if (puVar1 == (undefined1 *)0x0) {
          puVar1 = &DAT_005ea438;
        }
        iVar2 = FUN_00588410(param_2,puVar1);
        if (iVar2 == 0) {
          return;
        }
        if (*(int *)(param_1 + 0x30) != 0) {
          *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 4);
        }
        if (*(undefined4 **)(param_1 + 0x30) == (undefined4 *)0x0) break;
        puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 0x30);
      }
    }
    puVar3 = operator_new(8);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = 0;
      puVar3[1] = 0xffffffff;
      FUN_00566650(param_2);
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
      if (*(int *)(param_1 + 0x28) == 0) {
        *(undefined4 **)(param_1 + 0x28) = puVar4;
        *(undefined4 **)(param_1 + 0x30) = puVar4;
        *(undefined4 **)(param_1 + 0x2c) = puVar4;
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
        return;
      }
      *(undefined4 **)(*(int *)(param_1 + 0x2c) + 4) = puVar4;
      *(undefined4 **)(param_1 + 0x2c) = puVar4;
      *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
    }
  }
  return;
}


