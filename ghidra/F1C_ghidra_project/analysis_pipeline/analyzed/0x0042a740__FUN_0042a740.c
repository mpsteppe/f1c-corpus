// Function: FUN_0042a740 @ 0042a740
// Size (bytes): 59


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042a740(int param_1,float param_2)

{
  if (param_2 < *(float *)(param_1 + 0x4484)) {
    *(float *)(param_1 + 0x4484) = param_2;
  }
  if (*(float *)(param_1 + 0x4484) < _DAT_0059e7ec) {
    *(undefined4 *)(param_1 + 0x4484) = 0x40a00000;
  }
  return;
}


