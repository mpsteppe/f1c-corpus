// Function: FUN_004380b0 @ 004380b0
// Size (bytes): 76


void __thiscall FUN_004380b0(int param_1,double param_2,double param_3)

{
  int extraout_ECX;
  float10 fVar1;
  
  param_2 = *(double *)(param_1 + 0x1f8) - param_2;
  *(double *)(param_1 + 0x1e8) = param_2;
  *(double *)(param_1 + 0x1f0) = -param_3;
  fVar1 = (float10)FUN_00436610(param_2,-param_3);
  *(double *)(extraout_ECX + 0x204) = (double)fVar1;
  return;
}


