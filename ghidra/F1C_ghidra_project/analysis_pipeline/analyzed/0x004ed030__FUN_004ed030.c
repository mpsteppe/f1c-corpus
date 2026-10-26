// Function: FUN_004ed030 @ 004ed030
// Size (bytes): 191


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ed030(int param_1)

{
  FUN_004e0d00(param_1 + 0xcc8);
  FUN_004e0d00(param_1 + 0xd0c);
  FUN_004a56b0(0);
  if (*(int *)(param_1 + 0x3d60) == 1) {
    *(undefined4 *)(param_1 + 0x3d60) = 0;
  }
  if (*(float *)(param_1 + 0x3a6c) != *(float *)(param_1 + 0x3a78)) {
    *(float *)(param_1 + 0x3a6c) =
         (*(float *)(param_1 + 0x3a78) + *(float *)(param_1 + 0x3a6c)) * _DAT_0059e450;
  }
  if ((*(int *)(param_1 + 0xd0c) == 0) || (*(char *)(param_1 + 0xd4c) != '\0')) {
    *(undefined4 *)(param_1 + 0x3a70) = *(undefined4 *)(param_1 + 0x3a7c);
  }
  else {
    *(undefined4 *)(param_1 + 0x3a70) = *(undefined4 *)(param_1 + 0x3a80);
  }
  FUN_004e8010(0);
  if (*(int *)(param_1 + 0x32bc) == 0) {
    FUN_0043ec80();
    return;
  }
  return;
}


