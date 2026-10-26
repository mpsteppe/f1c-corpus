// Function: FUN_004ee230 @ 004ee230
// Size (bytes): 145


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ee230(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(param_1 + 0x3994) / *(float *)(param_1 + 0x3998);
  *(undefined4 *)(param_1 + 0x77c) = *(undefined4 *)(param_1 + 0x3d48);
  fVar1 = fVar1 * *(float *)(param_1 + 0x3570) * fVar1 * fVar1 * _DAT_0059e450;
  if (*(float *)(param_1 + 0x3d48) == (float)_DAT_005ad1f8) {
    *(float *)(param_1 + 0x77c) = fVar1;
  }
  fVar2 = (float)_DAT_005ad1f8;
  *(undefined4 *)(param_1 + 0x790) = *(undefined4 *)(param_1 + 0x3d4c);
  if (*(float *)(param_1 + 0x3d4c) == fVar2) {
    *(float *)(param_1 + 0x790) = fVar1;
  }
  fVar2 = (float)_DAT_005ad1f8;
  *(undefined4 *)(param_1 + 0x7a4) = *(undefined4 *)(param_1 + 0x3d50);
  if (*(float *)(param_1 + 0x3d50) == fVar2) {
    *(float *)(param_1 + 0x7a4) = fVar1;
    return;
  }
  return;
}


