// Function: FUN_00404e60 @ 00404e60
// Size (bytes): 136


void __thiscall FUN_00404e60(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = operator_new(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[1] = 0xffffffff;
    FUN_00566650(param_2);
  }
  iVar1 = *param_1;
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = puVar2;
      puVar3[1] = 0;
      *(undefined1 *)(puVar3 + 2) = 1;
    }
    if (*(int *)(iVar1 + 0x40) == 0) {
      *(int *)(iVar1 + 0x40) = (int)puVar3;
      *(undefined4 **)(iVar1 + 0x48) = puVar3;
      *(undefined4 **)(iVar1 + 0x44) = puVar3;
      *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + 1;
      return;
    }
    *(undefined4 **)(*(int *)(iVar1 + 0x44) + 4) = puVar3;
    *(undefined4 **)(iVar1 + 0x44) = puVar3;
    *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + 1;
  }
  return;
}


