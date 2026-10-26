// Function: FUN_004b2310 @ 004b2310
// Size (bytes): 262


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2310(undefined4 *param_1,undefined4 *param_2,float *param_3)

{
  float *pfVar1;
  
  pfVar1 = param_3;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  if (*param_3 <= _DAT_005acc94) {
    if (_DAT_005acc90 <= *param_3) {
      param_3._0_2_ = (undefined2)(int)ROUND(*param_3 * _DAT_0059e714);
    }
    else {
      param_3._0_2_ = 0x8001;
    }
  }
  else {
    param_3._0_2_ = 0x7fff;
  }
  *(undefined2 *)(param_1 + 3) = param_3._0_2_;
  if (pfVar1[1] <= _DAT_005acc94) {
    if (_DAT_005acc90 <= pfVar1[1]) {
      param_3._0_2_ = (undefined2)(int)ROUND(pfVar1[1] * _DAT_0059e714);
    }
    else {
      param_3._0_2_ = 0x8001;
    }
  }
  else {
    param_3._0_2_ = 0x7fff;
  }
  *(undefined2 *)((int)param_1 + 0xe) = param_3._0_2_;
  if (_DAT_005acc94 < pfVar1[2]) {
    *(undefined2 *)(param_1 + 4) = 0x7fff;
    return;
  }
  if (pfVar1[2] < _DAT_005acc90) {
    *(undefined2 *)(param_1 + 4) = 0x8001;
    return;
  }
  param_3._0_2_ = (undefined2)(int)ROUND(pfVar1[2] * _DAT_0059e714);
  *(undefined2 *)(param_1 + 4) = param_3._0_2_;
  return;
}


