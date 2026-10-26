// Function: FUN_004e5080 @ 004e5080
// Size (bytes): 188


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e5080(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x3a04) - *(float *)(param_1 + 0x34a8);
  *(float *)(param_1 + 0x3a04) = fVar1;
  if (fVar1 < DAT_0059e440 != (fVar1 == DAT_0059e440)) {
    *(undefined4 *)(param_1 + 0x39f0) = *(undefined4 *)(param_1 + 0x3a08);
    return;
  }
  if ((*(char *)(param_1 + 0x39ec) != '\0') && (*(int *)(param_1 + 0x3a08) == 1)) {
    *(float *)(param_1 + 0x3570) =
         ((*(float *)(param_1 + 0x3990) - *(float *)(param_1 + 0x3994)) + _DAT_0059e828) *
         _DAT_0059e444;
    if (*(float *)(param_1 + 0x3570) < DAT_0059e440) {
      *(undefined4 *)(param_1 + 0x3570) = 0;
      return;
    }
    if (_DAT_0059e43c < *(float *)(param_1 + 0x3570)) {
      *(undefined4 *)(param_1 + 0x3570) = 0x3f800000;
    }
    return;
  }
  FUN_0059dad5();
  return;
}


