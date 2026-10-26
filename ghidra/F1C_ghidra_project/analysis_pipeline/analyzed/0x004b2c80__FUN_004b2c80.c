// Function: FUN_004b2c80 @ 004b2c80
// Size (bytes): 336


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2c80(int param_1,float *param_2)

{
  float10 fVar1;
  undefined2 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *param_2;
  local_4 = param_2[2];
  local_8 = param_2[1];
  FUN_004b21f0(&local_c);
  FUN_004b2580(&local_c);
  if (local_c <= _DAT_0059e710) {
    if (_DAT_0059e70c <= local_c) {
      local_10 = (undefined2)(int)ROUND(local_c * _DAT_0059e708);
    }
    else {
      local_10 = 0x8001;
    }
  }
  else {
    local_10 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 9) = local_10;
  if (local_8 <= _DAT_0059e710) {
    if (_DAT_0059e70c <= local_8) {
      local_10 = (undefined2)(int)ROUND(local_8 * _DAT_0059e708);
    }
    else {
      local_10 = 0x8001;
    }
  }
  else {
    local_10 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 0xb) = local_10;
  if (local_4 <= _DAT_0059e710) {
    if (_DAT_0059e70c <= local_4) {
      local_10 = (undefined2)(int)ROUND(local_4 * _DAT_0059e708);
    }
    else {
      local_10 = 0x8001;
    }
  }
  else {
    local_10 = 0x7fff;
  }
  *(undefined2 *)(param_1 + 0xd) = local_10;
  fVar1 = (float10)FUN_004b29f0();
  FUN_004b2b90((float)fVar1);
  fVar1 = (float10)FUN_004b2980();
  FUN_004b2c20((float)fVar1);
  return;
}


