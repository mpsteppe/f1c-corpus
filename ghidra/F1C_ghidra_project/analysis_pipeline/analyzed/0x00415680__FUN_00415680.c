// Function: FUN_00415680 @ 00415680
// Size (bytes): 58


undefined4 __thiscall FUN_00415680(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0x1c) <= param_2)) {
    return 0;
  }
  if (param_2 < *(int *)(param_1 + 0x1c)) {
    puVar1 = *(undefined4 **)(param_1 + 0x10);
    for (; 0 < param_2; param_2 = param_2 + -1) {
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      puVar1 = (undefined4 *)puVar1[1];
    }
    if (puVar1 != (undefined4 *)0x0) {
      return *puVar1;
    }
  }
  return 0;
}


