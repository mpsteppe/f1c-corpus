// Function: FUN_004b2bf0 @ 004b2bf0
// Size (bytes): 43


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004b2bf0(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xf) & 3;
  if (uVar1 == 1) {
    return (float10)_DAT_0059e8cc;
  }
  if (uVar1 != 2) {
    if (uVar1 != 3) {
      return (float10)_DAT_0059e6e8;
    }
    return (float10)_DAT_0059e43c;
  }
  return (float10)_DAT_0059e824;
}


