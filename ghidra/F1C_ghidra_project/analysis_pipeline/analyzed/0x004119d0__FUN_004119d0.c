// Function: FUN_004119d0 @ 004119d0
// Size (bytes): 48


undefined4 FUN_004119d0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((0 < param_1) && (param_1 < 0x123)) {
    return 0;
  }
  if ((0x124 < param_1) && (param_1 < 0x218)) {
    uVar1 = 1;
  }
  return uVar1;
}


