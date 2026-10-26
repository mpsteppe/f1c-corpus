// Function: FUN_00540da0 @ 00540da0
// Size (bytes): 67


void FUN_00540da0(int param_1,byte param_2)

{
  if (param_1 != 0) {
    if ((param_2 & 4) != 0) {
      FUN_00540f90(*(undefined4 *)(param_1 + 0x1c));
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
    if ((param_2 & 8) != 0) {
      FUN_005410f0(*(undefined4 *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
  }
  return;
}


