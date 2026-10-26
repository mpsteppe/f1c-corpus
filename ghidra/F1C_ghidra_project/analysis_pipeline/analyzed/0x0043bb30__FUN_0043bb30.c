// Function: FUN_0043bb30 @ 0043bb30
// Size (bytes): 77


void __thiscall FUN_0043bb30(int param_1,double param_2)

{
  *(double *)(param_1 + 0x1c00) = param_2;
  *(double *)(param_1 + 0x1930) =
       param_2 * *(double *)(param_1 + 0x17b0) + param_2 * *(double *)(param_1 + 0x17b8) * param_2 +
       *(double *)(param_1 + 0x17a8);
  *(double *)(param_1 + 0x19e8) =
       param_2 * *(double *)(param_1 + 0x17c8) + param_2 * *(double *)(param_1 + 0x17d0) * param_2 +
       *(double *)(param_1 + 0x17c0);
  return;
}


