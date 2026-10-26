// Function: FUN_0043bbd0 @ 0043bbd0
// Size (bytes): 71


void __thiscall FUN_0043bbd0(int param_1,double param_2)

{
  *(double *)(param_1 + 0x1c18) = param_2;
  *(double *)(param_1 + 0x1b94) =
       param_2 * *(double *)(param_1 + 0x1810) + *(double *)(param_1 + 0x1808);
  *(double *)(param_1 + 0x1adc) =
       param_2 * *(double *)(param_1 + 0x1820) + *(double *)(param_1 + 0x1818);
  *(double *)(param_1 + 0x1d9c) =
       param_2 * *(double *)(param_1 + 0x1830) + *(double *)(param_1 + 0x1828);
  return;
}


