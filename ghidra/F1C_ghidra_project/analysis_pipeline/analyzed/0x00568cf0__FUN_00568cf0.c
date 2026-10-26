// Function: FUN_00568cf0 @ 00568cf0
// Size (bytes): 145


float10 __fastcall FUN_00568cf0(uint *param_1)

{
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = param_1[8];
  local_c = param_1[9];
  FUN_00568cb0(&local_10,&local_14);
  param_1[8] = local_14;
  param_1[9] = local_10;
  return (float10)((local_10 - local_c) - (uint)(local_14 < local_8)) *
         (float10)*(double *)(param_1 + 2) + (float10)(local_14 - local_8) / (float10)*param_1;
}


