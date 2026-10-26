// Function: FUN_004ef680 @ 004ef680
// Size (bytes): 64


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ef680(int param_1,undefined4 *param_2)

{
  param_2[2] = *(undefined4 *)(param_1 + 0x74c);
  param_2[1] = 0;
  *param_2 = 0;
  param_2[1] = ((*(float *)(param_1 + 0x3590) - *(float *)(param_1 + 0x3610)) +
               (*(float *)(param_1 + 0x3688) - *(float *)(param_1 + 0x3708))) * _DAT_0059e450;
  return;
}


