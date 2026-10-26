// Function: FUN_004dd6a0 @ 004dd6a0
// Size (bytes): 276


void __fastcall FUN_004dd6a0(undefined4 param_1,float *param_2,float *param_3)

{
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_0054b420(&local_c,&local_8,&local_4);
  FUN_004dd550(&local_24);
  local_18 = local_c + local_18;
  local_14 = local_8 + local_14;
  local_10 = local_4 + local_10;
  local_c = local_c + local_24;
  local_8 = local_8 + local_20;
  if (*param_2 < local_18) {
    local_18 = *param_2;
  }
  *param_2 = local_18;
  if (param_2[1] < local_14) {
    local_14 = param_2[1];
  }
  param_2[1] = local_14;
  if (param_2[2] < local_10) {
    local_10 = param_2[2];
  }
  param_2[2] = local_10;
  if (local_c < *param_3) {
    local_c = *param_3;
  }
  *param_3 = local_c;
  if (local_8 < param_3[1]) {
    local_8 = param_3[1];
  }
  param_3[1] = local_8;
  if (param_3[2] <= local_4 + local_1c) {
    param_3[2] = local_4 + local_1c;
    return;
  }
  param_3[2] = param_3[2];
  return;
}


