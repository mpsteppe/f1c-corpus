// Function: FUN_00496280 @ 00496280
// Size (bytes): 56


void __fastcall FUN_00496280(int param_1)

{
  int iVar1;
  float *pfVar2;
  float10 fVar3;
  
  iVar1 = 0;
  pfVar2 = (float *)(param_1 + 0x162c);
  do {
    fVar3 = (float10)FUN_005881f0();
    *pfVar2 = (float)fVar3;
    iVar1 = iVar1 + 1;
    pfVar2 = pfVar2 + 1;
  } while (iVar1 < 0x10);
  return;
}


