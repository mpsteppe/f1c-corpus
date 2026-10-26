// Function: FUN_004fc9c0 @ 004fc9c0
// Size (bytes): 136


undefined4 * __fastcall FUN_004fc9c0(undefined4 *param_1)

{
  FUN_004fc850();
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  FUN_004fc280();
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  param_1[0x11] = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)((int)param_1 + 0x4a) = 0xffff;
  *(undefined2 *)(param_1 + 0x13) = 0xffff;
  *(undefined2 *)((int)param_1 + 0x4e) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0x7fff;
  *(undefined2 *)((int)param_1 + 0x52) = 0x8000;
  FUN_004fd6f0();
  return param_1;
}


