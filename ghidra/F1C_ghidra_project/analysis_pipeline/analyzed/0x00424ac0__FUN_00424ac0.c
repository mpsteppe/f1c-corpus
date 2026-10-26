// Function: FUN_00424ac0 @ 00424ac0
// Size (bytes): 95


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00424ac0(void)

{
  float10 fVar1;
  
  fVar1 = (float10)_DAT_005ea3e0;
  if (DAT_007d01a0 < 0x65) {
    return (fVar1 - (float10)_DAT_005ea3dc) *
           (float10)(DAT_007d01a0 + -0x46) * (float10)_DAT_0059e474 + (float10)_DAT_005ea3dc;
  }
  return (float10)(DAT_007d01a0 + -100) * (float10)_DAT_0059e448 * ((float10)_DAT_005ea3e4 - fVar1)
         + fVar1;
}


