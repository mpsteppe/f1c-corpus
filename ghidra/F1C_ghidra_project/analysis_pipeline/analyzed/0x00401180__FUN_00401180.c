// Function: FUN_00401180 @ 00401180
// Size (bytes): 442


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00401180(double param_1,double param_2,double param_3,double param_4,double param_5,
                    double param_6)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  undefined8 local_20;
  undefined8 local_18;
  
  dVar1 = param_2 * param_2 + param_1 * param_1;
  local_18 = (dVar1 - param_3 * param_3) - param_4 * param_4;
  local_20 = (param_3 + param_3) - (param_1 + param_1);
  fVar3 = (float10)param_2 + (float10)param_2;
  fVar5 = ((float10)param_4 + (float10)param_4) - fVar3;
  dVar1 = (dVar1 - param_5 * param_5) - param_6 * param_6;
  dVar2 = (param_5 + param_5) - (param_1 + param_1);
  fVar3 = ((float10)param_6 + (float10)param_6) - (float10)(double)fVar3;
  param_1 = dVar2;
  param_2 = dVar1;
  param_5 = (double)fVar3;
  if (fVar5 == (float10)_DAT_0059e430) {
    if (fVar3 == (float10)_DAT_0059e430) {
      return (float10)_DAT_0059e430;
    }
    param_5 = (double)fVar5;
    fVar5 = (float10)(double)fVar3;
    fVar3 = (float10)param_5;
    param_1 = local_20;
    param_2 = local_18;
    local_20 = dVar2;
    local_18 = dVar1;
  }
  fVar4 = (float10)local_20 * -(fVar3 / fVar5) + (float10)param_1;
  if (fVar4 == (float10)_DAT_0059e430) {
    return (float10)_DAT_0059e430;
  }
  fVar3 = ((float10)_DAT_0059e428 / fVar4) *
          (-(fVar3 / fVar5) * (float10)local_18 + (float10)param_2);
  if (param_5 == _DAT_0059e430) {
    return (float10)_DAT_0059e430;
  }
  fVar5 = fVar3 - (float10)param_3;
  fVar3 = (float10)(double)(((float10)_DAT_0059e428 / (float10)param_5) *
                           ((float10)param_1 * fVar3 + (float10)param_2)) - (float10)param_4;
  fVar3 = SQRT(fVar5 * fVar5 + fVar3 * fVar3);
  if (fVar3 == (float10)_DAT_0059e430) {
    return (float10)_DAT_0059e430;
  }
  return (float10)_DAT_0059e420 / fVar3;
}


