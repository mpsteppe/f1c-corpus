// Function: FUN_00486580 @ 00486580
// Size (bytes): 125


void __thiscall FUN_00486580(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
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
    if (*(int *)(param_1 + 0x54) == 0) {
      *(undefined4 **)(param_1 + 0x54) = puVar2;
      *(undefined4 **)(param_1 + 0x5c) = puVar2;
      *(undefined4 **)(param_1 + 0x58) = puVar2;
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
      return;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x58) + 4) = puVar2;
    *(undefined4 **)(param_1 + 0x58) = puVar2;
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  }
  return;
}


