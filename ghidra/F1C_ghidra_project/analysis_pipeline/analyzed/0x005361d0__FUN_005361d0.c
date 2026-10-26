// Function: FUN_005361d0 @ 005361d0
// Size (bytes): 137


uint __fastcall FUN_005361d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) &&
     ((iVar2 = *(int *)(iVar1 + 4), iVar2 == 0x2a || ((iVar2 == 0x71 || (iVar2 == 0x29a)))))) {
    if (*(int *)(iVar1 + 8) != 0) {
      (**(code **)(param_1 + 0x24))();
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x3a) != 0) {
      (**(code **)(param_1 + 0x24))();
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x36) != 0) {
      (**(code **)(param_1 + 0x24))();
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x2e) != 0) {
      (**(code **)(param_1 + 0x24))();
    }
    (**(code **)(param_1 + 0x24))();
    *(undefined4 *)(param_1 + 0x1c) = 0;
    return (iVar2 != 0x71) - 1 & 0xfffffffd;
  }
  return 0xfffffffe;
}


