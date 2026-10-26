// Function: FUN_004f1aa0 @ 004f1aa0
// Size (bytes): 100


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_004f1aa0(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x32bc) == 0) {
    return DAT_007c9080;
  }
  if ((1 < *(int *)(param_1 + 0x3444)) && (*(int *)(param_1 + 0x3444) < 5)) {
    if ((*(float *)(param_1 + 0x34f4) * *(float *)(param_1 + 0x34f4) +
         *(float *)(param_1 + 0x34f0) * *(float *)(param_1 + 0x34f0) +
         *(float *)(param_1 + 0x34ec) * *(float *)(param_1 + 0x34ec) < _DAT_0059e43c) &&
       (cVar1 = FUN_004effd0(), cVar1 != '\0')) {
      return 0;
    }
    return 1;
  }
  return 0;
}


