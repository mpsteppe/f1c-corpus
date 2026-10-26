// Function: FUN_00423b10 @ 00423b10
// Size (bytes): 393


void __thiscall FUN_00423b10(int *param_1,int param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (param_4 == '\0') {
    fVar3 = (*(float *)(*param_1 + 0x34e8) - *(float *)(param_2 + 0x9c)) *
            *(float *)(param_2 + 0xa4) -
            (*(float *)(*param_1 + 0x34e0) - *(float *)(param_2 + 0x94)) *
            *(float *)(param_2 + 0xac);
    fVar2 = -*(float *)(param_2 + 0xac) * fVar3;
    fVar4 = *(float *)(param_2 + 0xa4) * fVar3;
    fVar2 = fVar2 * fVar2 + fVar4 * fVar4;
    if (DAT_0059e440 < fVar3) {
      param_1[9] = (int)-SQRT(fVar2);
      return;
    }
    param_1[9] = (int)SQRT(fVar2);
    return;
  }
  iVar1 = *param_1;
  fVar3 = (*(float *)(iVar1 + 0x34e8) - *(float *)(param_2 + 0x9c)) * *(float *)(param_2 + 0xac) +
          (*(float *)(iVar1 + 0x34e0) - *(float *)(param_2 + 0x94)) * *(float *)(param_2 + 0xa4);
  fVar2 = *(float *)(param_2 + 0xa4) * fVar3;
  fVar4 = *(float *)(param_2 + 0xac) * fVar3;
  fVar2 = fVar2 * fVar2 + fVar4 * fVar4;
  if (fVar3 <= DAT_0059e440) {
    fVar2 = -SQRT(fVar2);
  }
  else {
    fVar2 = SQRT(fVar2);
  }
  param_1[9] = (int)fVar2;
  fVar2 = *(float *)(param_2 + 0xa4) * *(float *)(param_2 + 0xa4) +
          *(float *)(param_2 + 0xac) * *(float *)(param_2 + 0xac);
  if (fVar2 != DAT_0059e440) {
    param_1[0xc] = (int)((*(float *)(iVar1 + 0x3500) * *(float *)(param_2 + 0xac) +
                         *(float *)(iVar1 + 0x34f8) * *(float *)(param_2 + 0xa4)) / fVar2);
    return;
  }
  param_1[0xc] = 0;
  return;
}


