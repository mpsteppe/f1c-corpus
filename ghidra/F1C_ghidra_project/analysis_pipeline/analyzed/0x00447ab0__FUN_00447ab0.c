// Function: FUN_00447ab0 @ 00447ab0
// Size (bytes): 84


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00447ab0(int param_1)

{
  uint uVar1;
  float10 fVar2;
  
  fVar2 = (float10)*(double *)(param_1 + 0x60) * (float10)_DAT_0059e7d8;
  uVar1 = (uint)ROUND((float)(fVar2 - (float10)_DAT_0059e880));
  return ((float10)(double)fVar2 - (float10)(int)uVar1) *
         ((float10)*(float *)(&DAT_008aae74 + (uVar1 + 1 & 0xff) * 4) -
         (float10)*(float *)(&DAT_008aae74 + (uVar1 & 0xff) * 4)) +
         (float10)*(float *)(&DAT_008aae74 + (uVar1 & 0xff) * 4);
}


