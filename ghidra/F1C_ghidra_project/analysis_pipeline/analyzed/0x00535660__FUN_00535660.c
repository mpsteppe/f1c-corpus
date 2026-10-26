// Function: FUN_00535660 @ 00535660
// Size (bytes): 62


undefined4 __fastcall FUN_00535660(int param_1)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x1c) != 0)) && (*(int *)(param_1 + 0x24) != 0)) {
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x14) != 0) {
      FUN_00537ce0();
    }
    (**(code **)(param_1 + 0x24))();
    *(undefined4 *)(param_1 + 0x1c) = 0;
    return 0;
  }
  return 0xfffffffe;
}


