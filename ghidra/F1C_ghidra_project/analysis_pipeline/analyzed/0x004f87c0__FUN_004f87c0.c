// Function: FUN_004f87c0 @ 004f87c0
// Size (bytes): 137


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f87c0(int *param_1,int param_2,int param_3,float param_4,int param_5)

{
  float fVar1;
  
  fVar1 = _DAT_007cf35c;
  if (*(int *)(*param_1 + 13000) == 0) {
    param_3 = param_3 + 1;
    fVar1 = _DAT_007cf338;
  }
  param_1[param_2 * 8 + 0x2f] = (int)(fVar1 * param_4);
  param_1[(param_2 + 6) * 8] = param_5;
  *(undefined1 *)(param_1 + param_2 * 8 + 0x2d) = 1;
  if (-1 < param_3) {
    if (param_3 < 4) {
      param_1[param_2 * 8 + 0x2e] = param_3;
      *(undefined1 *)(param_1 + param_2 * 8 + 0x31) = 0;
      return;
    }
    param_1[param_2 * 8 + 0x2e] = 3;
    *(undefined1 *)(param_1 + param_2 * 8 + 0x31) = 0;
    return;
  }
  param_1[param_2 * 8 + 0x2e] = 0;
  *(undefined1 *)(param_1 + param_2 * 8 + 0x31) = 0;
  return;
}


