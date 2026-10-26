// Function: FUN_004b2480 @ 004b2480
// Size (bytes): 246


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2480(int param_1,float *param_2)

{
  undefined2 local_4;
  
  if (*param_2 <= _DAT_005acc9c) {
    if (_DAT_005acc98 <= *param_2) {
      local_4 = (undefined2)(int)ROUND(*param_2 * _DAT_0059e828);
    }
    else {
      local_4 = 0x8001;
    }
  }
  else {
    local_4 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 0x1e) = local_4;
  if (param_2[1] <= _DAT_005acc9c) {
    if (_DAT_005acc98 <= param_2[1]) {
      local_4 = (undefined2)(int)ROUND(param_2[1] * _DAT_0059e828);
    }
    else {
      local_4 = 0x8001;
    }
  }
  else {
    local_4 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 0x20) = local_4;
  if (_DAT_005acc9c < param_2[2]) {
    *(undefined2 *)(param_1 + 0x22) = 0x7fff;
    return;
  }
  if (param_2[2] < _DAT_005acc98) {
    *(undefined2 *)(param_1 + 0x22) = 0x8001;
    return;
  }
  local_4 = (undefined2)(int)ROUND(param_2[2] * _DAT_0059e828);
  *(undefined2 *)(param_1 + 0x22) = local_4;
  return;
}


