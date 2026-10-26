// Function: FUN_004ef7c0 @ 004ef7c0
// Size (bytes): 353


void __thiscall FUN_004ef7c0(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  double local_8;
  
  *(float *)(param_1 + 0x34e0) = *param_3;
  *(float *)(param_1 + 0x34e4) = param_3[1];
  *(float *)(param_1 + 0x34e8) = param_3[2];
  FUN_00566e40();
  FUN_004ef680(&local_30);
  fVar1 = local_28._0_4_ * *(float *)(param_1 + 0x34b8);
  fVar2 = local_28._0_4_ * *(float *)(param_1 + 0x34c4);
  fVar3 = (float)local_30 * *(float *)(param_1 + 0x34c8) +
          local_30._4_4_ * *(float *)(param_1 + 0x34cc) +
          local_28._0_4_ * *(float *)(param_1 + 0x34d0);
  local_28 = (double)CONCAT44(local_28._4_4_,fVar3);
  fVar4 = *param_2 -
          ((float)local_30 * *(float *)(param_1 + 0x34b0) +
           local_30._4_4_ * *(float *)(param_1 + 0x34b4) + fVar1 + *(float *)(param_1 + 0x34d4));
  fVar2 = param_2[1] -
          ((float)local_30 * *(float *)(param_1 + 0x34bc) +
           local_30._4_4_ * *(float *)(param_1 + 0x34c0) + fVar2 + *(float *)(param_1 + 0x34d8));
  local_30 = (double)CONCAT44(fVar2,fVar4);
  fVar1 = param_2[2];
  *(float *)(param_1 + 0x34d4) = fVar4 + *(float *)(param_1 + 0x34d4);
  *(float *)(param_1 + 0x34d8) = fVar2 + *(float *)(param_1 + 0x34d8);
  *(float *)(param_1 + 0x34dc) =
       (fVar1 - (fVar3 + *(float *)(param_1 + 0x34dc))) + *(float *)(param_1 + 0x34dc);
  *(undefined4 *)(param_1 + 0x3a9c) = 0;
  FUN_004e9bd0();
  if (*(int *)(param_1 + 0x32bc) == 0) {
    local_18 = (double)*(float *)(param_1 + 0x34d4);
    local_10 = (double)*(float *)(param_1 + 0x34d8);
    local_8 = (double)*(float *)(param_1 + 0x34dc);
    local_30 = (double)*(float *)(param_1 + 0x34e0);
    local_28 = (double)*(float *)(param_1 + 0x34e4);
    local_20 = (double)*(float *)(param_1 + 0x34e8);
    FUN_0043e4b0(&local_18,&local_30);
  }
  return;
}


