// Function: FUN_004b31a0 @ 004b31a0
// Size (bytes): 246


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b31a0(int param_1,float *param_2)

{
  undefined2 local_4;
  
  if (*param_2 <= _DAT_005acc94) {
    if (_DAT_005acc90 <= *param_2) {
      local_4 = (undefined2)(int)ROUND(*param_2 * _DAT_0059e714);
    }
    else {
      local_4 = 0x8001;
    }
  }
  else {
    local_4 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 0xc) = local_4;
  if (param_2[1] <= _DAT_005acc94) {
    if (_DAT_005acc90 <= param_2[1]) {
      local_4 = (undefined2)(int)ROUND(param_2[1] * _DAT_0059e714);
    }
    else {
      local_4 = 0x8001;
    }
  }
  else {
    local_4 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 0xe) = local_4;
  if (_DAT_005acc94 < param_2[2]) {
    *(undefined2 *)(param_1 + 0x10) = 0x7fff;
    return;
  }
  if (param_2[2] < _DAT_005acc90) {
    *(undefined2 *)(param_1 + 0x10) = 0x8001;
    return;
  }
  local_4 = (undefined2)(int)ROUND(param_2[2] * _DAT_0059e714);
  *(undefined2 *)(param_1 + 0x10) = local_4;
  return;
}


