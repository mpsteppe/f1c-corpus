// Function: FUN_004fd7e0 @ 004fd7e0
// Size (bytes): 93


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004fd7e0(int param_1,float param_2)

{
  int iVar1;
  float10 extraout_ST0;
  float10 fVar2;
  
  if (_DAT_005ad2d0 <= param_2) {
    return (float10)*(float *)(param_1 + 0xa0);
  }
  param_2 = param_2 * _DAT_0059e46c;
  FUN_005895a2((double)param_2);
  iVar1 = __ftol();
  fVar2 = (float10)*(float *)(param_1 + 100 + iVar1 * 4);
  return ((float10)param_2 - extraout_ST0) *
         ((float10)*(float *)(param_1 + 0x68 + iVar1 * 4) - fVar2) + fVar2;
}


