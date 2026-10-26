// Function: FUN_00537070 @ 00537070
// Size (bytes): 154


undefined4 * __fastcall FUN_00537070(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EBX;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x20))(0x40);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar2 = (**(code **)(param_1 + 0x20))(0x5a0);
  puVar1[9] = iVar2;
  if (iVar2 == 0) {
    (**(code **)(param_1 + 0x24))();
    return (undefined4 *)0x0;
  }
  iVar2 = (**(code **)(param_1 + 0x20))(unaff_EBX);
  puVar1[10] = iVar2;
  if (iVar2 == 0) {
    (**(code **)(param_1 + 0x24))();
    (**(code **)(param_1 + 0x24))();
    return (undefined4 *)0x0;
  }
  puVar1[0xb] = iVar2 + unaff_EBX;
  puVar1[0xe] = param_2;
  *puVar1 = 0;
  FUN_00537000(0);
  return puVar1;
}


