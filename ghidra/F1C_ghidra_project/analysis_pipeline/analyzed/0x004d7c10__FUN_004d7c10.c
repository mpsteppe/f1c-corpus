// Function: FUN_004d7c10 @ 004d7c10
// Size (bytes): 167


int __thiscall FUN_004d7c10(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  
  if (param_2 < DAT_0059e440) {
    do {
      param_2 = *(float *)(param_1 + 0x24) + param_2;
    } while (param_2 < DAT_0059e440);
  }
  for (; *(float *)(param_1 + 0x24) < param_2; param_2 = param_2 - *(float *)(param_1 + 0x24)) {
  }
  if (param_2 <= DAT_005ea404) {
    pfVar4 = &DAT_005ea404;
    iVar3 = 0x144;
    iVar1 = 2;
    iVar5 = -1;
    do {
      iVar2 = iVar1;
      if (param_2 < *pfVar4 == (param_2 == *pfVar4)) {
        return iVar5;
      }
      iVar3 = iVar3 + -4;
      pfVar4 = pfVar4 + -1;
      iVar1 = iVar2 + -1;
      iVar5 = iVar2;
    } while (0x13f < iVar3);
    return iVar2;
  }
  return 0;
}


