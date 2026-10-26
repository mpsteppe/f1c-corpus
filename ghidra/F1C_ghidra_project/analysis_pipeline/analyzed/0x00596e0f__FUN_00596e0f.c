// Function: FUN_00596e0f @ 00596e0f
// Size (bytes): 49


undefined4 FUN_00596e0f(byte param_1,uint param_2,byte param_3)

{
  if ((*(byte *)((int)&DAT_008d47e0 + param_1 + 1) & param_3) == 0) {
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = *(ushort *)(&DAT_005e69d2 + (uint)param_1 * 2) & param_2;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  return 1;
}


