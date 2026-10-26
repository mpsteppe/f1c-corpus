// Function: FUN_004c2c40 @ 004c2c40
// Size (bytes): 111


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c2c40(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      *(float *)(param_1 + 0x44) = (float)param_2;
      return;
    }
    fVar3 = ((float)(iVar1 + -1) * *(float *)(param_1 + 0x44) + (float)param_2) / (float)iVar1;
    bVar2 = _DAT_0059e43c <= fVar3;
    *(float *)(param_1 + 0x44) = fVar3;
    if (bVar2) {
      if (_DAT_0059e85c < fVar3) {
        *(undefined4 *)(param_1 + 0x44) = 0x41b00000;
        return;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x44) = 0x3f800000;
    }
  }
  return;
}


