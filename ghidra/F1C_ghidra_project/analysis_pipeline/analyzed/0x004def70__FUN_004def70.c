// Function: FUN_004def70 @ 004def70
// Size (bytes): 179


void __thiscall FUN_004def70(int param_1,undefined4 param_2,float *param_3,float *param_4)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_20 = param_2;
  local_1c = *param_3;
  local_18 = param_3[1];
  local_14 = param_3[2];
  iVar1 = *(int *)(param_1 + 4);
  local_24 = 0;
  if (*(char *)(iVar1 + 0x42) != '\0') {
    local_1c = local_1c - *(float *)(iVar1 + 4);
    local_18 = local_18 - *(float *)(iVar1 + 8);
    local_14 = local_14 - *(float *)(iVar1 + 0xc);
  }
  local_10 = *param_4;
  local_c = param_4[1];
  local_8 = param_4[2];
  local_4 = SQRT(param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4);
  if (local_4 < DAT_0059e440 == (local_4 == DAT_0059e440)) {
    FUN_004dedb0(&local_24);
  }
  return;
}


