// Function: FUN_0057b0d0 @ 0057b0d0
// Size (bytes): 46


undefined4 __thiscall FUN_0057b0d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x14))) {
    puVar1 = *(undefined4 **)(param_1 + 8);
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


