// Function: FUN_00589bc6 @ 00589bc6
// Size (bytes): 45


uint FUN_00589bc6(int param_1)

{
  uint uVar1;
  
  if (1 < DAT_005e6bd4) {
    uVar1 = FUN_0058c674(param_1,0x80);
    return uVar1;
  }
  return (byte)PTR_DAT_005e69c8[param_1 * 2] & 0x80;
}


