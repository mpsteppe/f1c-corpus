// Function: FUN_00415650 @ 00415650
// Size (bytes): 47


undefined4 __thiscall FUN_00415650(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((-1 < param_2) && (param_2 < (int)param_1[3])) {
    param_1 = (undefined4 *)*param_1;
    for (; 0 < param_2; param_2 = param_2 + -1) {
      if (param_1 == (undefined4 *)0x0) {
        return 0;
      }
      param_1 = (undefined4 *)param_1[1];
    }
    if (param_1 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = *param_1;
  }
  return uVar1;
}


