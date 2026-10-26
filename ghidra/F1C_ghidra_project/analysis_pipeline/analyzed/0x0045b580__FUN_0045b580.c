// Function: FUN_0045b580 @ 0045b580
// Size (bytes): 59


int __thiscall FUN_0045b580(int param_1,int param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  pfVar1 = (float *)(param_1 + 0x90);
  do {
    if (DAT_0059e440 < *pfVar1) {
      if (param_2 == iVar3) {
        return iVar2;
      }
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 0x17;
  } while (iVar2 < 8);
  return 0;
}


