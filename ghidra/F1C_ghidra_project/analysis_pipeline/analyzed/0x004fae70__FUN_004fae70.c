// Function: FUN_004fae70 @ 004fae70
// Size (bytes): 79


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004fae70(int param_1)

{
  int iVar1;
  
  iVar1 = __ftol();
  if ((double)iVar1 < _DAT_0059e430) {
    iVar1 = -iVar1;
    if (7 < iVar1) {
      iVar1 = 7;
    }
    return (float10)*(float *)(param_1 + 0xcc + iVar1 * 4);
  }
  if (7 < iVar1) {
    iVar1 = 7;
  }
  return (float10)*(float *)(param_1 + 0xec + iVar1 * 4);
}


