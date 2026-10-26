// Function: FUN_004b2840 @ 004b2840
// Size (bytes): 175


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2840(int param_1,int param_2,float param_3,float param_4)

{
  float fVar1;
  undefined1 local_4;
  
  fVar1 = _DAT_005accc4;
  if (param_3 <= _DAT_005acccc) {
    if (_DAT_005accc8 <= param_3) {
      local_4 = (undefined1)(int)ROUND(param_3 * _DAT_0059f10c);
    }
    else {
      local_4 = 0x81;
    }
  }
  else {
    local_4 = 0x7f;
  }
  *(undefined1 *)(param_2 + 0x12 + param_1) = local_4;
  if (fVar1 < param_4) {
    *(undefined2 *)(param_1 + 0x16 + param_2 * 2) = 0x7fff;
    return;
  }
  if (param_4 < _DAT_005accc0) {
    *(undefined2 *)(param_1 + 0x16 + param_2 * 2) = 0x8001;
    return;
  }
  param_4._0_2_ = (undefined2)(int)ROUND(param_4 * _DAT_0059e6f8);
  *(undefined2 *)(param_1 + 0x16 + param_2 * 2) = param_4._0_2_;
  return;
}


