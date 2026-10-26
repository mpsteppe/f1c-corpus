// Function: FUN_004fe060 @ 004fe060
// Size (bytes): 104


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fe060(int param_1,undefined4 param_2)

{
  char cVar1;
  float *extraout_ECX;
  
  if ((DAT_007c56a0 & 1) != 0) {
    if (DAT_008ab6e4 != 2) {
      return;
    }
    cVar1 = FUN_004b9a00();
    if (cVar1 != '\0') {
      return;
    }
  }
  FUN_004fc910(param_2);
  if (ABS(*(float *)(param_1 + 8) - *extraout_ECX) <= _DAT_0059e450) {
    *(undefined4 *)(param_1 + 4) = 0x40000000;
    FUN_004fd6f0();
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_004fd6f0();
  return;
}


