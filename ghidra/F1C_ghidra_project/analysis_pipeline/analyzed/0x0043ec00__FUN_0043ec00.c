// Function: FUN_0043ec00 @ 0043ec00
// Size (bytes): 79


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043ec00(double param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
  DAT_008aae70 = DAT_008aae70 + 1;
  FUN_0043e980((double)(fVar1 * (float)param_1));
  FUN_0043ea70((_DAT_0059e420 - (double)fVar1) * param_1);
  return;
}


