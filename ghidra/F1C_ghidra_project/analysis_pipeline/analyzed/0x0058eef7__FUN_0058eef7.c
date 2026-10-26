// Function: FUN_0058eef7 @ 0058eef7
// Size (bytes): 55


uint FUN_0058eef7(uint param_1)

{
  uint uVar1;
  
  if (DAT_005e6bd4 < 2) {
    uVar1 = (byte)PTR_DAT_005e69c8[param_1 * 2] & 4;
  }
  else {
    uVar1 = FUN_0058c674(param_1,4);
  }
  if (uVar1 == 0) {
    param_1 = (param_1 & 0xffffffdf) - 7;
  }
  return param_1;
}


