// Function: FUN_004bea10 @ 004bea10
// Size (bytes): 248


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004bea10(undefined4 param_1,float param_2)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  _rand();
  fVar2 = (float10)FUN_005881f0();
  iVar1 = _rand();
  fVar3 = (float10)(iVar1 % 0x32) * (float10)_DAT_0059e444 + (float10)_DAT_0059e450;
  if ((float10)_DAT_0059e43c < fVar3) {
    fVar3 = (float10)_DAT_0059e43c;
  }
  return (fVar3 * (float10)(float)fVar2 * (float10)_DAT_005acdb4 * (float10)param_2 -
         (float10)_DAT_0059e7f8) + (float10)param_2;
}


