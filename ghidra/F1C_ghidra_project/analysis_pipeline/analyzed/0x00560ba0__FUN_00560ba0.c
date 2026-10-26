// Function: FUN_00560ba0 @ 00560ba0
// Size (bytes): 85


undefined4 * __thiscall FUN_00560ba0(undefined4 *param_1,int param_2,undefined4 param_3)

{
  FUN_0053c2a0();
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0x3e4ccccd;
  param_1[6] = param_2;
  *(undefined4 **)(*(int *)(param_2 + 0x138) + 0x230) = param_1;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[10] = param_3;
  param_1[9] = 2;
  return param_1;
}


