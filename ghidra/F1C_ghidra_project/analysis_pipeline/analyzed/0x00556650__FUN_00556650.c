// Function: FUN_00556650 @ 00556650
// Size (bytes): 123


float10 __fastcall FUN_00556650(uint *param_1)

{
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_8 = param_1[6];
  local_c = param_1[7];
  FUN_005564b0(&local_10,&local_14);
  return (float10)((local_10 - local_c) - (uint)(local_14 < local_8)) *
         (float10)*(double *)(param_1 + 2) + (float10)(local_14 - local_8) / (float10)*param_1;
}


