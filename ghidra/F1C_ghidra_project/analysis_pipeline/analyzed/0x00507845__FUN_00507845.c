// Function: FUN_00507845 @ 00507845
// Size (bytes): 112


void __thiscall FUN_00507845(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  
  uVar1 = *(int *)(param_1 + 0x1058) * 0x10 + param_2;
  if (param_2 < uVar1) {
    iVar2 = ((uVar1 - param_2) - 1 >> 4) + 1;
    pfVar3 = (float *)(param_2 + 8);
    do {
      if ((((pfVar3[-2] == *(float *)(param_1 + 0x1c)) && (pfVar3[-1] == *(float *)(param_1 + 0x20))
           ) && (*pfVar3 == *(float *)(param_1 + 0x24))) &&
         (pfVar3[1] == *(float *)(param_1 + 0x28))) {
        pfVar3[1] = 0.0;
        *pfVar3 = 0.0;
        pfVar3[-1] = 0.0;
        pfVar3[-2] = 0.0;
      }
      pfVar3 = pfVar3 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


