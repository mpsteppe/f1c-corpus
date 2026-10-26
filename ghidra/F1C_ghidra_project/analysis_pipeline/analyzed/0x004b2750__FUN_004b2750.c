// Function: FUN_004b2750 @ 004b2750
// Size (bytes): 170


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2750(int param_1,float *param_2)

{
  undefined2 local_4;
  
  if (*param_2 <= _DAT_005accbc) {
    if (_DAT_005accb8 <= *param_2) {
      local_4 = (undefined2)(int)ROUND(*param_2 * _DAT_005accb4);
    }
    else {
      local_4 = 0x8001;
    }
  }
  else {
    local_4 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 0x28) = local_4;
  if (_DAT_005accbc < param_2[2]) {
    *(undefined2 *)(param_1 + 0x2a) = 0x7fff;
    return;
  }
  if (param_2[2] < _DAT_005accb8) {
    *(undefined2 *)(param_1 + 0x2a) = 0x8001;
    return;
  }
  local_4 = (undefined2)(int)ROUND(param_2[2] * _DAT_005accb4);
  *(undefined2 *)(param_1 + 0x2a) = local_4;
  return;
}


