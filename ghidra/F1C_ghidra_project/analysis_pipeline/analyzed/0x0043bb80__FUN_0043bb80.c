// Function: FUN_0043bb80 @ 0043bb80
// Size (bytes): 77


void __thiscall FUN_0043bb80(int param_1,double param_2)

{
  *(double *)(param_1 + 0x1c38) = param_2;
  *(double *)(param_1 + 0x1a0c) =
       param_2 * *(double *)(param_1 + 0x17e0) + param_2 * *(double *)(param_1 + 0x17e8) * param_2 +
       *(double *)(param_1 + 0x17d8);
  *(double *)(param_1 + 0x1abc) =
       param_2 * *(double *)(param_1 + 0x17f8) + param_2 * *(double *)(param_1 + 0x1800) * param_2 +
       *(double *)(param_1 + 0x17f0);
  return;
}


