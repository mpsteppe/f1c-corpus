// Function: FUN_00589b70 @ 00589b70
// Size (bytes): 46


uint FUN_00589b70(int param_1)

{
  uint uVar1;
  
  if (1 < DAT_005e6bd4) {
    uVar1 = FUN_0058c674(param_1,0x103);
    return uVar1;
  }
  return *(ushort *)(PTR_DAT_005e69c8 + param_1 * 2) & 0x103;
}


