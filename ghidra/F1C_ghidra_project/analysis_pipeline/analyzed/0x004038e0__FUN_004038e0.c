// Function: FUN_004038e0 @ 004038e0
// Size (bytes): 217


int __thiscall FUN_004038e0(int param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float local_4;
  
  iVar6 = *(int *)(param_1 + 0x130);
  iVar5 = 0;
  local_4 = 1e+37;
  if (0 < iVar6) {
    iVar4 = *(int *)(param_1 + 0x134);
    do {
      fVar1 = *param_2 - *(float *)(iVar4 + 0x94);
      fVar3 = param_2[1] - *(float *)(iVar4 + 0x98);
      fVar2 = param_2[2] - *(float *)(iVar4 + 0x9c);
      fVar1 = fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2;
      if ((fVar1 < local_4) && ((param_3 == -1 || (param_3 == *(int *)(iVar4 + 300))))) {
        iVar5 = iVar4;
        local_4 = fVar1;
      }
      iVar4 = iVar4 + 0x13c;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if ((iVar5 != 0) &&
       (*(float *)(iVar5 + 0xa4) * (*(float *)(iVar5 + 0x94) - *param_2) +
        *(float *)(iVar5 + 0xac) * (*(float *)(iVar5 + 0x9c) - param_2[2]) < DAT_0059e440)) {
      return *(int *)(iVar5 + 0x110);
    }
  }
  return iVar5;
}


