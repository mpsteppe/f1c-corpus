// Function: FUN_004fc910 @ 004fc910
// Size (bytes): 132


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fc910(float *param_1,int param_2)

{
  *param_1 = (float)*(ushort *)(param_2 + 8) * _DAT_005ad290;
  param_1[1] = (float)*(ushort *)(param_2 + 10) * _DAT_005ad290;
  param_1[2] = (float)*(ushort *)(param_2 + 0xc) * _DAT_005ad290;
  param_1[3] = (float)*(ushort *)(param_2 + 0xe) * _DAT_005ad290;
  param_1[4] = (float)(int)*(short *)(param_2 + 0x10) * _DAT_0059e774;
  param_1[5] = (float)(int)*(short *)(param_2 + 0x12) * _DAT_0059e774;
  return;
}


