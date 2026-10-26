// Function: FUN_004c2cb0 @ 004c2cb0
// Size (bytes): 126


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c2cb0(int param_1,float param_2)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 < 2) {
    fVar3 = param_2;
    if (iVar1 == 1) {
      fVar3 = *(float *)(param_1 + 0x48);
    }
  }
  else {
    fVar3 = (float)(iVar1 + -1) * *(float *)(param_1 + 0x48);
  }
  if (iVar1 < 1) {
    *(float *)(param_1 + 0x48) = (float)(int)param_2;
  }
  fVar3 = ((float)(int)param_2 + fVar3) / (float)iVar1;
  bVar2 = _DAT_0059e43c <= fVar3;
  *(float *)(param_1 + 0x48) = fVar3;
  if (bVar2) {
    if (_DAT_0059e85c < fVar3) {
      *(undefined4 *)(param_1 + 0x48) = 0x41b00000;
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x48) = 0x3f800000;
  return;
}


