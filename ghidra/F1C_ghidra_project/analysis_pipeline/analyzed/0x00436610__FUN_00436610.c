// Function: FUN_00436610 @ 00436610
// Size (bytes): 208


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00436610(double *param_1,double param_2,double param_3)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar1 = (float10)param_3;
  if (fVar1 <= (float10)_DAT_0059e430) {
    if ((float10)param_1[7] <= fVar1) {
      fVar1 = fVar1 * (float10)param_1[6];
    }
    else {
      fVar1 = fVar1 * (float10)param_1[5] + (float10)param_1[8];
    }
  }
  else if (fVar1 <= (float10)param_1[3]) {
    fVar1 = fVar1 * (float10)param_1[2];
  }
  else {
    fVar1 = fVar1 * (float10)param_1[1] + (float10)param_1[4];
  }
  fVar1 = fVar1 + (float10)param_2 * (float10)*param_1;
  if (param_2 <= param_1[0xe]) {
    fVar2 = (float10)param_1[0xe] - (float10)param_2;
  }
  else {
    fVar2 = (float10)param_2 - (float10)param_1[0xd];
  }
  if ((float10)_DAT_0059e430 < fVar2) {
    fVar3 = fVar2 * (float10)param_1[10] + (float10)param_1[9];
    fVar4 = fVar2 * (float10)param_1[0xc] + (float10)param_1[0xb];
    if (param_2 <= _DAT_0059e430) {
      fVar2 = fVar4 * (float10)param_3 - fVar3 * fVar2;
      if (fVar2 < (float10)_DAT_0059e430) {
        return fVar2 + fVar1;
      }
    }
    else {
      fVar2 = fVar4 * (float10)param_3 + fVar3 * fVar2;
      if ((float10)_DAT_0059e430 < fVar2) {
        return fVar2 + fVar1;
      }
    }
  }
  return fVar1;
}


