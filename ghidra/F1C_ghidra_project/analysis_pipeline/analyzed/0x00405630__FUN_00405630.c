// Function: FUN_00405630 @ 00405630
// Size (bytes): 62


void __fastcall FUN_00405630(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_0052d990();
  (**(code **)(*(int *)(param_1 + 0x34) + 4))();
  puVar2 = (undefined4 *)(param_1 + 0x44);
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 0x70) = 0;
  return;
}


