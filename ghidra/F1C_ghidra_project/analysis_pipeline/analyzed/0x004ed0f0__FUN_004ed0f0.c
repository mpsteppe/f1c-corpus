// Function: FUN_004ed0f0 @ 004ed0f0
// Size (bytes): 195


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ed0f0(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_2 * _DAT_005acee8 + *(float *)(param_1 + 0x3a6c);
  *(float *)(param_1 + 0x3a6c) = fVar1;
  fVar2 = *(float *)(param_1 + 0x3a78) + _DAT_0059e8fc;
  if (fVar2 < fVar1) {
    *(float *)(param_1 + 0x3a6c) = fVar2;
  }
  if (*(float *)(param_1 + 0x3a78) + _DAT_0059e868 < *(float *)(param_1 + 0x3a6c)) {
    if (*(int *)(param_1 + 0x3d60) == 0) {
      *(undefined4 *)(param_1 + 0x3d60) = 1;
    }
    fVar1 = (*(float *)(param_1 + 0x3a80) + *(float *)(param_1 + 0x3a70)) * _DAT_0059e450;
    if (fVar1 < *(float *)(param_1 + 0x3a70)) {
      *(float *)(param_1 + 0x3a70) = fVar1;
    }
  }
  if (*(float *)(param_1 + 0x3a78) + _DAT_0059e8b4 < *(float *)(param_1 + 0x3a6c)) {
    *(undefined4 *)(param_1 + 0x3a70) = *(undefined4 *)(param_1 + 0x3a80);
  }
  FUN_004e8010();
  return;
}


