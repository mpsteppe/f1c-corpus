// Function: FUN_00436470 @ 00436470
// Size (bytes): 47


void __thiscall FUN_00436470(int param_1,double param_2)

{
  *(double *)(param_1 + 0x34) =
       param_2 * *(double *)(param_1 + 0xc) + param_2 * *(double *)(param_1 + 0x14) * param_2 +
       *(double *)(param_1 + 4);
  *(double *)(param_1 + 0x3c) =
       param_2 * *(double *)(param_1 + 0x24) + param_2 * *(double *)(param_1 + 0x2c) * param_2 +
       *(double *)(param_1 + 0x1c);
  return;
}


