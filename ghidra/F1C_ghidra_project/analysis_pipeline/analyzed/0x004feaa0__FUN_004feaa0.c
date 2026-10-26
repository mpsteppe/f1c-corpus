// Function: FUN_004feaa0 @ 004feaa0
// Size (bytes): 80


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004feaa0(float param_1)

{
  undefined4 uVar1;
  
  if (param_1 < _DAT_005ad334) {
    return 2;
  }
  if (param_1 < _DAT_0059e6e8) {
    return 3;
  }
  uVar1 = 4;
  if (_DAT_005a0038 <= param_1) {
    uVar1 = 5;
  }
  return uVar1;
}


