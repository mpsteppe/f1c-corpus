// Function: FUN_00589b9e @ 00589b9e
// Size (bytes): 40


uint FUN_00589b9e(int param_1)

{
  uint uVar1;
  
  if (1 < DAT_005e6bd4) {
    uVar1 = FUN_0058c674(param_1,4);
    return uVar1;
  }
  return (byte)PTR_DAT_005e69c8[param_1 * 2] & 4;
}


