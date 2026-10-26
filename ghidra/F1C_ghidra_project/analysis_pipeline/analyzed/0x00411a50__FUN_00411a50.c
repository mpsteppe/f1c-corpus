// Function: FUN_00411a50 @ 00411a50
// Size (bytes): 95


undefined4 FUN_00411a50(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (0x218 < param_1)) {
    return 0;
  }
  if (param_1 < 0x18e) {
    if (param_1 == 0x18d) {
      return 0;
    }
    if (2 < param_1) {
      if ((0x122 < param_1) && (param_1 < 0x125)) {
        return 0xffffffff;
      }
      goto LAB_00411a9f;
    }
    if (0 < param_1) {
      return 0;
    }
  }
  else {
    if (param_1 == 0x1aa) {
      return 0;
    }
    param_1 = param_1 + -0x218;
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
LAB_00411a9f:
  uVar1 = FUN_00411650();
  return uVar1;
}


