// Function: FUN_0044fc20 @ 0044fc20
// Size (bytes): 156


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044fc20(int param_1,int param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  
  fVar1 = DAT_0059e440;
  if ((DAT_0059e440 <= param_4) && (fVar1 = param_4, _DAT_0059e43c < param_4)) {
    fVar1 = _DAT_0059e43c;
  }
  *(float *)(param_1 + 0x20 + param_2 * 4) = fVar1;
  if (param_3 < DAT_0059e440) {
    param_3 = DAT_0059e440;
  }
  *(float *)(param_1 + 0x2f8 + param_2 * 4) = param_3;
  if (DAT_0059e440 <= param_5) {
    if (_DAT_0059e43c < param_5) {
      param_5 = _DAT_0059e43c;
    }
    *(float *)(param_1 + param_2 * 4) = param_5;
    FUN_0044f8f0();
    return;
  }
  *(float *)(param_1 + param_2 * 4) = DAT_0059e440;
  FUN_0044f8f0();
  return;
}


