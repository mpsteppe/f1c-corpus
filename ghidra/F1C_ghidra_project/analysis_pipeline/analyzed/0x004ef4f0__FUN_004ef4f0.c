// Function: FUN_004ef4f0 @ 004ef4f0
// Size (bytes): 110


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ef4f0(int param_1)

{
  if ((float)_DAT_008afea0 <= *(float *)(param_1 + 0x4014) + _DAT_005acb5c) {
    return;
  }
  *(float *)(param_1 + 0x4014) = (float)_DAT_008afea0;
  if (DAT_0083ee60 < 0x3ff) {
    DAT_0083ee60 = DAT_0083ee60 + 1;
    DAT_008aae64 = DAT_008aae64 + 0x1b0;
  }
  FUN_004b33b0(2,0,0,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x34ac),0);
  return;
}


