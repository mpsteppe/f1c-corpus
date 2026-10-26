// Function: FUN_00462ff0 @ 00462ff0
// Size (bytes): 204


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00462ff0(int *param_1,int param_2,float param_3)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  iVar1 = param_2 * 0x48c0;
  if (param_3 <= DAT_0059e440) {
    param_3 = *(float *)(*param_1 + 4);
  }
  fVar2 = (float10)param_3;
  fVar3 = ABS(SQRT((float10)*(float *)(&DAT_005efbd8 + iVar1) *
                   (float10)*(float *)(&DAT_005efbd8 + iVar1) +
                   (float10)*(float *)(&DAT_005efbd4 + iVar1) *
                   (float10)*(float *)(&DAT_005efbd4 + iVar1) +
                   (float10)*(float *)(&DAT_005efbd0 + iVar1) *
                   (float10)*(float *)(&DAT_005efbd0 + iVar1)) * (float10)_DAT_0059f128);
  if (fVar3 < (float10)_DAT_0059e8a0) {
    fVar2 = (((float10)_DAT_0059f124 - fVar3 * (float10)_DAT_0059e860 * (float10)_DAT_0059f124) +
            (float10)_DAT_0059e43c) * fVar2;
  }
  if (((uint)(&DAT_005f0f94)[param_2 * 0x1230] >> 1 & 1) == 0) {
    fVar2 = fVar2 * (float10)_DAT_0059e46c;
  }
  if ((float10)DAT_0059e440 <= fVar2) {
    if ((float10)_DAT_0059e450 < fVar2) {
      fVar2 = (float10)_DAT_0059e450;
    }
    return fVar2;
  }
  return (float10)DAT_0059e440;
}


