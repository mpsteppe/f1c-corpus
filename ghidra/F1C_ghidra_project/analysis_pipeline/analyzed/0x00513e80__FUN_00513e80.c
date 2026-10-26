// Function: FUN_00513e80 @ 00513e80
// Size (bytes): 250


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00513e80(float *param_1)

{
  float local_1c;
  float local_18;
  float local_14;
  
  if (DAT_0059e440 <= *param_1) {
    if (_DAT_0059e43c < *param_1) {
      local_1c = 1.0;
    }
    else {
      local_1c = *param_1;
    }
  }
  else {
    local_1c = 0.0;
  }
  if (DAT_0059e440 <= param_1[1]) {
    if (_DAT_0059e43c < param_1[1]) {
      local_18 = 1.0;
    }
    else {
      local_18 = param_1[1];
    }
  }
  else {
    local_18 = 0.0;
  }
  if (DAT_0059e440 <= param_1[2]) {
    if (param_1[2] <= _DAT_0059e43c) {
      local_14 = param_1[2];
    }
    else {
      local_14 = 1.0;
    }
  }
  else {
    local_14 = 0.0;
  }
  FUN_00513e5d();
  return ((int)ROUND(local_1c * _DAT_005accd0 + _DAT_0059e450) << 6 |
         (int)ROUND(local_18 * _DAT_005accd8 + _DAT_0059e450)) << 5 |
         (int)ROUND(local_14 * _DAT_005accd0 + _DAT_0059e450);
}


