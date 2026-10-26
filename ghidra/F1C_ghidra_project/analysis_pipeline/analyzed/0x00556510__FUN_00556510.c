// Function: FUN_00556510 @ 00556510
// Size (bytes): 153


float10 __fastcall FUN_00556510(uint *param_1)

{
  uint local_1c;
  uint local_18 [3];
  uint local_c;
  uint local_8;
  
  local_8 = param_1[8];
  local_c = param_1[9];
  FUN_005564b0(local_18,&local_1c);
  param_1[8] = local_1c;
  param_1[9] = local_18[0];
  return (float10)((local_18[0] - local_c) - (uint)(local_1c < local_8)) *
         (float10)*(double *)(param_1 + 2) + (float10)(local_1c - local_8) / (float10)*param_1;
}


