// Function: FUN_0040acd0 @ 0040acd0
// Size (bytes): 134


void __thiscall FUN_0040acd0(int param_1,undefined4 param_2,int *param_3,float *param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_8;
  int local_4;
  
  iVar3 = 0;
  local_8 = 3.4028235e+38;
  local_4 = -1;
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar2 = 0;
    do {
      fVar1 = *(float *)(*(int *)(param_1 + 0xc) + 0x8c + iVar2);
      fVar4 = (float10)FUN_004579c0(param_2);
      fVar4 = fVar4 - (float10)fVar1;
      if (fVar4 < (float10)local_8) {
        local_8 = (float)fVar4;
        local_4 = iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xa0;
    } while (iVar3 < *(int *)(param_1 + 0x10));
  }
  *param_3 = local_4;
  *param_4 = local_8;
  return;
}


