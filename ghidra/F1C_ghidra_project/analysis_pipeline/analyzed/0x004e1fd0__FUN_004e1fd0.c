// Function: FUN_004e1fd0 @ 004e1fd0
// Size (bytes): 156


void __thiscall FUN_004e1fd0(int param_1,float *param_2,undefined4 *param_3)

{
  *param_2 = *(float *)(param_1 + 0x8e8) * *(float *)(param_1 + 0x20) +
             *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x8ec) +
             *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x8f0);
  param_2[1] = *(float *)(param_1 + 0x2c) * *(float *)(param_1 + 0x8e8) +
               *(float *)(param_1 + 0x30) * *(float *)(param_1 + 0x8ec) +
               *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x8f0);
  param_2[2] = *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x8e8) +
               *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x8ec) +
               *(float *)(param_1 + 0x40) * *(float *)(param_1 + 0x8f0);
  *param_2 = *(float *)(param_1 + 8) + *param_2;
  param_2[1] = *(float *)(param_1 + 0xc) + param_2[1];
  param_2[2] = *(float *)(param_1 + 0x10) + param_2[2];
  *param_3 = *(undefined4 *)(param_1 + 0x14);
  param_3[1] = *(undefined4 *)(param_1 + 0x18);
  param_3[2] = *(undefined4 *)(param_1 + 0x1c);
  return;
}


