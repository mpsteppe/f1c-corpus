// Function: FUN_004b25d0 @ 004b25d0
// Size (bytes): 242


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b25d0(int param_1,float *param_2)

{
  undefined1 uVar1;
  undefined2 local_4;
  
  if (*param_2 <= _DAT_005accac) {
    if (_DAT_005acca8 <= *param_2) {
      uVar1 = (undefined1)(int)ROUND(*param_2 * _DAT_0059e8ec);
    }
    else {
      uVar1 = 0x81;
    }
  }
  else {
    uVar1 = 0x7f;
  }
  *(undefined1 *)(param_1 + 0x24) = uVar1;
  if (param_2[1] <= _DAT_005acca4) {
    if (_DAT_005acca0 <= param_2[1]) {
      local_4 = (undefined2)(int)ROUND(param_2[1] * _DAT_0059e91c);
    }
    else {
      local_4 = 0x8001;
    }
  }
  else {
    local_4 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 0x26) = local_4;
  if (_DAT_005accac < param_2[2]) {
    *(undefined1 *)(param_1 + 0x25) = 0x7f;
    return;
  }
  if (param_2[2] < _DAT_005acca8) {
    *(undefined1 *)(param_1 + 0x25) = 0x81;
    return;
  }
  *(char *)(param_1 + 0x25) = (char)(int)ROUND(param_2[2] * _DAT_0059e8ec);
  return;
}


