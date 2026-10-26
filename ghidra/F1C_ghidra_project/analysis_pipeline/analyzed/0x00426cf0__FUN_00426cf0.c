// Function: FUN_00426cf0 @ 00426cf0
// Size (bytes): 936


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00426cf0(int param_1)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float local_c;
  
  if (*(int *)(param_1 + 0x45fc) != 0) {
    fVar3 = (float10)FUN_00424750();
    *(float *)(param_1 + 0x457c) = (float)(fVar3 * (float10)_DAT_0059e7fc);
  }
  if ((_DAT_0059e84c < ABS(*(float *)(param_1 + 0x442c))) &&
     (_DAT_0059e8ec < *(float *)(param_1 + 0x4440))) {
    *(float *)(param_1 + 0x4434) =
         (_DAT_0059e43c - ABS(*(float *)(param_1 + 0x442c)) * _DAT_0059e6e8) *
         *(float *)(param_1 + 0x4434);
  }
  local_c = 0.0;
  fVar1 = _DAT_0059e8b4;
  fVar2 = _DAT_0059e6e8;
  if (*(float *)(param_1 + 0x38c4) < *(float *)(param_1 + 0x37cc)) {
    fVar1 = _DAT_0059e6e8;
    fVar2 = _DAT_0059e8b4;
  }
  fVar1 = *(float *)(param_1 + 0x37cc) * fVar2 + *(float *)(param_1 + 0x38c4) * fVar1;
  fVar2 = (fVar1 + *(float *)(param_1 + 0x4464)) * _DAT_0059e450;
  if ((fVar2 < _DAT_0059e824) &&
     ((_DAT_0059e46c < *(float *)(param_1 + 0x4440) || (*(int *)(param_1 + 0x446c) != 0)))) {
    fVar3 = (float10)FUN_004e8780();
    fVar4 = (float10)_DAT_0059e43c - (float10)fVar2 * (float10)_DAT_0059e8e8;
    fVar4 = fVar4 + fVar4;
    if ((float10)DAT_0059e440 <= fVar4) {
      if ((float10)_DAT_0059e43c < fVar4) {
        fVar4 = (float10)_DAT_0059e43c;
      }
    }
    else {
      fVar4 = (float10)DAT_0059e440;
    }
    fVar3 = (fVar3 - (float10)*(float *)(param_1 + 0x4434)) * fVar4 +
            (float10)*(float *)(param_1 + 0x4434);
    if ((fVar3 < (float10)*(float *)(param_1 + 0x4434)) && (*(char *)(param_1 + 0x39f9) != '\0')) {
      fVar4 = ((float10)*(float *)(param_1 + 0x4434) - fVar3) * (float10)_DAT_0059e46c;
      local_c = (float)fVar4;
      if ((float10)DAT_0059e440 <= fVar4) {
        if (_DAT_0059e43c < local_c) {
          local_c = 1.0;
        }
      }
      else {
        local_c = 0.0;
      }
    }
    *(float *)(param_1 + 0x4434) = (float)fVar3;
  }
  *(float *)(param_1 + 0x4028) = local_c;
  *(float *)(param_1 + 0x4464) = fVar1;
  if ((DAT_007c56a8 < 5) && (DAT_007c56a4 == 7)) {
    FUN_0042b0e0();
  }
  FUN_0042a740(*(undefined4 *)(param_1 + 0x4538));
  if (_DAT_008acf90 + _DAT_0059e8e4 <= (float)_DAT_008afea0) {
    if (*(float *)(param_1 + 0x4440) <= *(float *)(param_1 + 0x4484) + _DAT_0059e5fc) {
      if (*(float *)(param_1 + 0x4440) <= *(float *)(param_1 + 0x4484) + _DAT_0059e478) {
        if (*(float *)(param_1 + 0x4440) <= *(float *)(param_1 + 0x4484) + _DAT_0059e43c) {
          if ((*(float *)(param_1 + 0x4484) < *(float *)(param_1 + 0x4440)) &&
             (*(float *)(param_1 + 0x4438) == DAT_0059e440)) {
            fVar3 = (float10)FUN_004e87e0();
            *(float *)(param_1 + 0x4434) = (float)(fVar3 * (float10)_DAT_0059e8cc);
          }
        }
        else {
          if (*(float *)(param_1 + 0x4438) == DAT_0059e440) {
            *(undefined4 *)(param_1 + 0x4438) = 0;
          }
          *(undefined4 *)(param_1 + 0x4434) = 0;
        }
      }
      else {
        fVar3 = (float10)FUN_004e88b0();
        if (fVar3 * (float10)_DAT_0059e450 <= (float10)*(float *)(param_1 + 0x4438)) {
          *(undefined4 *)(param_1 + 0x4434) = 0;
        }
        else {
          *(float *)(param_1 + 0x4438) = (float)(fVar3 * (float10)_DAT_0059e450);
          *(undefined4 *)(param_1 + 0x4434) = 0;
        }
      }
    }
    else {
      fVar3 = (float10)FUN_004e88b0();
      *(float *)(param_1 + 0x4438) = (float)fVar3;
      *(undefined4 *)(param_1 + 0x4434) = 0;
    }
  }
  else if (DAT_0059e440 < *(float *)(param_1 + 0x4438)) {
    *(undefined4 *)(param_1 + 0x4438) = 0;
  }
  if (DAT_005c3160 == '\0') {
    if (*(float *)(param_1 + 0x457c) < *(float *)(param_1 + 0x4434)) {
      *(undefined4 *)(param_1 + 0x4434) = *(undefined4 *)(param_1 + 0x457c);
    }
  }
  else {
    fVar1 = _DAT_0059e43c;
    if (*(float *)(param_1 + 0x44b8) <= _DAT_0059e43c) {
      fVar1 = *(float *)(param_1 + 0x44b8);
    }
    if (fVar1 < *(float *)(param_1 + 0x4434)) {
      if (*(float *)(param_1 + 0x44b8) <= _DAT_0059e43c) {
        *(undefined4 *)(param_1 + 0x4434) = *(undefined4 *)(param_1 + 0x44b8);
        return;
      }
      *(float *)(param_1 + 0x4434) = _DAT_0059e43c;
      return;
    }
  }
  return;
}


