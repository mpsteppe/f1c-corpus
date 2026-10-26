// Function: FUN_004efb20 @ 004efb20
// Size (bytes): 163


void FUN_004efb20(float *param_1,undefined4 *param_2)

{
  int extraout_ECX;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_004ef680(&local_c);
  *param_1 = local_c * *(float *)(extraout_ECX + 0x34b0) +
             local_8 * *(float *)(extraout_ECX + 0x34b4) +
             local_4 * *(float *)(extraout_ECX + 0x34b8);
  param_1[1] = local_8 * *(float *)(extraout_ECX + 0x34c0) +
               local_c * *(float *)(extraout_ECX + 0x34bc) +
               local_4 * *(float *)(extraout_ECX + 0x34c4);
  param_1[2] = local_8 * *(float *)(extraout_ECX + 0x34cc) +
               local_c * *(float *)(extraout_ECX + 0x34c8) +
               local_4 * *(float *)(extraout_ECX + 0x34d0);
  *param_1 = *param_1 + *(float *)(extraout_ECX + 0x34d4);
  param_1[1] = *(float *)(extraout_ECX + 0x34d8) + param_1[1];
  param_1[2] = *(float *)(extraout_ECX + 0x34dc) + param_1[2];
  *param_2 = *(undefined4 *)(extraout_ECX + 0x34e0);
  param_2[1] = *(undefined4 *)(extraout_ECX + 0x34e4);
  param_2[2] = *(undefined4 *)(extraout_ECX + 0x34e8);
  return;
}


