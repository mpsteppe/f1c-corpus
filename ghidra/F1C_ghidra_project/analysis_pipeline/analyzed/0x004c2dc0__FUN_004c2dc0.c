// Function: FUN_004c2dc0 @ 004c2dc0
// Size (bytes): 92


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c2dc0(int param_1,float param_2)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  iVar4 = iVar1 + 1;
  *(int *)(param_1 + 0x2c) = iVar4;
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0x2c) = 1;
  }
  fVar3 = ((float)iVar1 * *(float *)(param_1 + 0x50) + param_2) / (float)*(int *)(param_1 + 0x2c);
  bVar2 = fVar3 < _DAT_005acb00;
  *(float *)(param_1 + 0x50) = fVar3;
  if (bVar2) {
    *(undefined4 *)(param_1 + 0x50) = 0x428c0000;
    return;
  }
  if (_DAT_0059e968 < fVar3) {
    *(undefined4 *)(param_1 + 0x50) = 0x42f00000;
  }
  return;
}


