// Function: FUN_0045bb00 @ 0045bb00
// Size (bytes): 50


int __fastcall FUN_0045bb00(int param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  pfVar1 = (float *)(param_1 + 0x90);
  while ((*pfVar1 <= DAT_0059e440 || (iVar3 = iVar3 + 1, iVar3 < 4))) {
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 0x17;
    if (7 < iVar2) {
      return iVar3;
    }
  }
  return iVar3;
}


