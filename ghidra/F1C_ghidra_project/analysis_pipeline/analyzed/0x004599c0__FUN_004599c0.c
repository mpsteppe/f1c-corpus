// Function: FUN_004599c0 @ 004599c0
// Size (bytes): 116


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004599c0(int param_1,int param_2,float param_3)

{
  float fVar1;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  double local_8;
  
  fVar1 = param_3 + _DAT_0059e6f8;
  *(float *)(param_1 + 0x24) = param_3;
  *(float *)(param_1 + 0x20) = fVar1;
  fVar1 = *(float *)(param_2 + 4);
  local_18 = (double)(*(float *)(param_2 + 0x20) * fVar1);
  local_10 = (double)(*(float *)(param_2 + 0x24) * fVar1);
  local_8 = (double)(*(float *)(param_2 + 0x28) * fVar1);
  local_30 = (double)((float)*(double *)(param_1 + 0xd8) - *(float *)(param_2 + 0x14));
  local_28 = (double)((float)*(double *)(param_1 + 0xe0) - *(float *)(param_2 + 0x18));
  local_20 = (double)((float)*(double *)(param_1 + 0xe8) - *(float *)(param_2 + 0x1c));
  FUN_00569670(&local_18,&local_30);
  return;
}


