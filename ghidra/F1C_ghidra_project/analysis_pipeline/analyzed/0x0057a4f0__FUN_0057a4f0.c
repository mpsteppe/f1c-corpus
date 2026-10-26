// Function: FUN_0057a4f0 @ 0057a4f0
// Size (bytes): 107


undefined4 __thiscall FUN_0057a4f0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 in_stack_00000028;
  int in_stack_00000034;
  undefined4 auStack_48 [9];
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  uint uStack_14;
  
  uStack_14 = (uint)*(byte *)(in_stack_00000034 + 0x2b);
  iStack_18 = 0x57a507;
  FUN_00585860();
  uStack_14 = (uint)*(byte *)(in_stack_00000034 + 0x2b);
  iStack_18 = in_stack_00000034 + 8;
  iStack_1c = 0x57a518;
  uVar1 = (**(code **)(*(int *)*param_1 + 0x68))();
  puVar3 = (undefined4 *)&stack0xfffffffc;
  puVar4 = auStack_48;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00585030();
  iStack_1c = in_stack_00000034;
  uStack_20 = 0x57a53e;
  (**(code **)(*(int *)*param_1 + 0xc0))();
  *(undefined1 *)(*param_1 + 0x5d) = 0;
  uStack_24 = 0x57a550;
  uStack_20 = uVar1;
  FUN_00584ff0();
  return in_stack_00000028;
}


