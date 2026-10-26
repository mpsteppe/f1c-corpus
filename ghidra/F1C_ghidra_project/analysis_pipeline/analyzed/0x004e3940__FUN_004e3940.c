// Function: FUN_004e3940 @ 004e3940
// Size (bytes): 133


void __thiscall FUN_004e3940(int param_1,undefined4 param_2,float *param_3,undefined4 param_4)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *param_3 - *(float *)(param_1 + 0x48);
  iVar1 = 0;
  local_8 = param_3[1] - *(float *)(param_1 + 0x4c);
  local_4 = param_3[2] - *(float *)(param_1 + 0x50);
  if (0 < *(int *)(param_1 + 0xba8)) {
    do {
      FUN_004def70(param_2,&local_c,param_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0xba8));
  }
  return;
}


