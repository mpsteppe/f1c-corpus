// Function: FUN_004ff130 @ 004ff130
// Size (bytes): 160


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ff130(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  
  pfVar1 = *(float **)(param_1 + 0x38);
  if (pfVar1 == (float *)0x0) {
    FUN_004ff0e0();
    return;
  }
  fVar3 = (float)_DAT_008afea0;
  if ((fVar3 < *pfVar1 == (fVar3 == *pfVar1)) &&
     (pfVar2 = (float *)pfVar1[3], pfVar2 != (float *)0x0)) {
    if (fVar3 < *pfVar2) {
      fVar4 = DAT_0059e440;
      if (DAT_0059e440 < *pfVar2 - *pfVar1) {
        fVar4 = (fVar3 - *pfVar1) / (*pfVar2 - *pfVar1);
      }
      FUN_004feaa0(fVar4 * pfVar2[2] + (_DAT_0059e43c - fVar4) * pfVar1[2]);
      return;
    }
    FUN_004feaa0(pfVar2[2]);
    return;
  }
  FUN_004feaa0(pfVar1[2]);
  return;
}


