// Function: FUN_004a1fd0 @ 004a1fd0
// Size (bytes): 62


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a1fd0(float *param_1,float param_2,float param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  if (DAT_0059e440 < param_3 - param_2) {
    param_1[2] = _DAT_0059e43c / (param_3 - param_2);
    return;
  }
  param_1[2] = 0.0;
  return;
}


