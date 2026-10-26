// Function: FUN_004d9f80 @ 004d9f80
// Size (bytes): 86


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004d9f80(int param_1)

{
  char cVar1;
  
  if (DAT_0059e440 <= *(float *)(param_1 + 0x10)) {
    *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) - (float)_DAT_008afe98;
    if (*(float *)(param_1 + 0x14) < DAT_0059e440) {
      FUN_004d9fe0();
    }
    cVar1 = FUN_004da080();
    if (cVar1 != '\0') {
      FUN_004da0d0();
      return 0;
    }
  }
  return 1;
}


