// Function: FUN_004f8ab0 @ 004f8ab0
// Size (bytes): 37


float10 __thiscall FUN_004f8ab0(int param_1,int param_2)

{
  param_1 = param_2 * 0x20 + param_1;
  if (*(char *)(param_1 + 0xb4) != '\0') {
    return (float10)*(float *)(param_1 + 0xbc);
  }
  return (float10)DAT_0059e440;
}


