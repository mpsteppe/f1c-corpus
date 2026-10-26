// Function: FUN_00438100 @ 00438100
// Size (bytes): 37


void __fastcall FUN_00438100(int param_1)

{
  double dVar1;
  
  dVar1 = *(double *)(param_1 + 0x36c) * *(double *)(param_1 + 0x364);
  *(double *)(param_1 + 0x374) = dVar1;
  *(double *)(param_1 + 0x22c) = dVar1 * *(double *)(param_1 + 0x38c) + *(double *)(param_1 + 900);
  return;
}


