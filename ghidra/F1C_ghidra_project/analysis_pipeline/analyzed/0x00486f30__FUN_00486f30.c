// Function: FUN_00486f30 @ 00486f30
// Size (bytes): 211


void __thiscall FUN_00486f30(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_3 < 1) {
    puVar1 = operator_new(8);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 0xffffffff;
      FUN_00566650(param_2);
    }
    if (puVar1 != (undefined4 *)0x0) {
      puVar2 = operator_new(0xc);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = puVar1;
        puVar2[1] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      if (*(int *)(param_1 + 0x44) == 0) {
        *(undefined4 **)(param_1 + 0x44) = puVar2;
        *(undefined4 **)(param_1 + 0x4c) = puVar2;
        *(undefined4 **)(param_1 + 0x48) = puVar2;
        *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
        return;
      }
      *(undefined4 **)(*(int *)(param_1 + 0x48) + 4) = puVar2;
      *(undefined4 **)(param_1 + 0x48) = puVar2;
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
    }
  }
  else {
    if (param_3 < *(int *)(param_1 + 0x50)) {
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x44);
      do {
        if (*(int *)(param_1 + 0x4c) == 0) break;
        param_3 = param_3 + -1;
        *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(*(int *)(param_1 + 0x4c) + 4);
      } while (0 < param_3);
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    if ((*(int **)(param_1 + 0x4c) != (int *)0x0) && (**(int **)(param_1 + 0x4c) != 0)) {
      FUN_00566650(param_2);
      return;
    }
  }
  return;
}


