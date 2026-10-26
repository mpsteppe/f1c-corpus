// Function: FUN_00541d10 @ 00541d10
// Size (bytes): 148


void __thiscall FUN_00541d10(int param_1,float param_2,float param_3,float param_4)

{
  *(float *)(param_1 + 0x24) = param_2;
  *(float *)(param_1 + 0x28) = param_3;
  *(float *)(param_1 + 0x2c) = param_4;
  *(float *)(param_1 + 0x18c) =
       param_2 * *(float *)(param_1 + 0x15c) +
       param_3 * *(float *)(param_1 + 0x16c) + param_4 * *(float *)(param_1 + 0x17c);
  *(float *)(param_1 + 400) =
       *(float *)(param_1 + 0x160) * *(float *)(param_1 + 0x24) +
       *(float *)(param_1 + 0x170) * *(float *)(param_1 + 0x28) +
       *(float *)(param_1 + 0x180) * *(float *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x198) = 0x3f800000;
  *(float *)(param_1 + 0x194) =
       *(float *)(param_1 + 0x164) * *(float *)(param_1 + 0x24) +
       *(float *)(param_1 + 0x174) * *(float *)(param_1 + 0x28) +
       *(float *)(param_1 + 0x184) * *(float *)(param_1 + 0x2c);
  return;
}


