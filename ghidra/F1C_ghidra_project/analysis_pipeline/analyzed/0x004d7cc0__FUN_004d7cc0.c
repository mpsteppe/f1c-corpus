// Function: FUN_004d7cc0 @ 004d7cc0
// Size (bytes): 39


undefined4 FUN_004d7cc0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 == 0) {
    uVar1 = 1;
  }
  else {
    if (param_1 == 1) {
      return 2;
    }
    if (param_1 == 2) {
      return 0;
    }
  }
  return uVar1;
}


