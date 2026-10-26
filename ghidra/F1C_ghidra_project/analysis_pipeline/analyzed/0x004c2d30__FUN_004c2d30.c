// Function: FUN_004c2d30 @ 004c2d30
// Size (bytes): 134


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c2d30(int param_1,float param_2)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 0x28);
  param_2 = param_2 * _DAT_0059e6f8;
  if (iVar1 < 2) {
    fVar3 = param_2;
    if (iVar1 == 1) {
      fVar3 = *(float *)(param_1 + 0x4c);
    }
  }
  else {
    fVar3 = (float)(iVar1 + -1) * *(float *)(param_1 + 0x4c);
  }
  if (iVar1 < 1) {
    *(float *)(param_1 + 0x4c) = param_2;
  }
  fVar3 = (fVar3 + param_2) / (float)iVar1;
  bVar2 = _DAT_0059e7ec <= fVar3;
  *(float *)(param_1 + 0x4c) = fVar3;
  if (bVar2) {
    if (_DAT_0059e6f8 < fVar3) {
      *(undefined4 *)(param_1 + 0x4c) = 0x42c80000;
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x4c) = 0x40a00000;
  return;
}


