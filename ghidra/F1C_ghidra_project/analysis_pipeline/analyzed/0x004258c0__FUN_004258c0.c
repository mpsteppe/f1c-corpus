// Function: FUN_004258c0 @ 004258c0
// Size (bytes): 88


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004258c0(int param_1)

{
  bool bVar1;
  
  *(undefined4 *)(param_1 + 0x4438) = 0x3f800000;
  bVar1 = *(float *)(param_1 + 0x4440) < _DAT_0059e46c;
  *(undefined4 *)(param_1 + 0x4434) = 0;
  if ((bVar1) ||
     ((_DAT_0059e824 < *(float *)(param_1 + 0x37cc) &&
      (_DAT_0059e824 < *(float *)(param_1 + 0x38c4))))) {
    *(undefined4 *)(param_1 + 0x4510) = 2;
  }
  return;
}


