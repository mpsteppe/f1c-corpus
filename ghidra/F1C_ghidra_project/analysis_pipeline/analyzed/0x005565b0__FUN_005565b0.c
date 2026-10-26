// Function: FUN_005565b0 @ 005565b0
// Size (bytes): 148


float10 __fastcall FUN_005565b0(uint *param_1)

{
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_c = param_1[7];
  local_10 = param_1[10];
  local_8 = param_1[6];
  local_14 = param_1[0xb];
  FUN_005564b0(&local_18,&local_1c);
  return (float10)((((local_18 - local_c) - (uint)(local_1c < local_8)) - local_14) -
                  (uint)(local_1c - local_8 < local_10)) * (float10)*(double *)(param_1 + 2) +
         (float10)((local_1c - local_8) - local_10) / (float10)*param_1 +
         (float10)*(double *)(param_1 + 4);
}


