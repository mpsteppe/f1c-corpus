// Function: FUN_004e513e @ 004e513e
// Size (bytes): 88


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e513e(int param_1)

{
  float10 in_ST0;
  
  *(float *)(param_1 + 0x3570) =
       (float)(((-in_ST0 - (float10)*(float *)(param_1 + 0x3994)) + (float10)_DAT_0059e828) *
              (float10)_DAT_0059e444);
  if (*(float *)(param_1 + 0x3570) < DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x3570) = 0;
    return;
  }
  if (_DAT_0059e43c < *(float *)(param_1 + 0x3570)) {
    *(undefined4 *)(param_1 + 0x3570) = 0x3f800000;
  }
  return;
}


