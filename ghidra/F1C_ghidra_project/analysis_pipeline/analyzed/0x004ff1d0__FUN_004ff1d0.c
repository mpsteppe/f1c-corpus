// Function: FUN_004ff1d0 @ 004ff1d0
// Size (bytes): 216


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ff1d0(int param_1)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float local_8;
  
  pfVar2 = *(float **)(param_1 + 0x38);
  if (pfVar2 == (float *)0x0) {
    FUN_004ff0e0();
    return;
  }
  fVar3 = _DAT_005ad338;
  if (DAT_007c56a4 == 7) {
    fVar3 = _DAT_005ad33c;
  }
  local_8 = pfVar2[2];
  fVar1 = pfVar2[2];
  for (; pfVar2 != (float *)0x0; pfVar2 = (float *)pfVar2[3]) {
    if (local_8 < pfVar2[2]) {
      local_8 = pfVar2[2];
    }
    if (pfVar2[2] < fVar1) {
      fVar1 = pfVar2[2];
    }
    if ((float)_DAT_008afea0 + fVar3 < *pfVar2) break;
  }
  local_8 = (fVar1 + local_8) * _DAT_0059e450 + *(float *)(param_1 + 0x104);
  if (local_8 < DAT_0059e440) {
    FUN_004feaa0(0);
    return;
  }
  if (_DAT_0059e43c < local_8) {
    local_8 = 1.0;
  }
  FUN_004feaa0(local_8);
  return;
}


