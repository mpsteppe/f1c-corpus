// Function: FUN_00411a00 @ 00411a00
// Size (bytes): 75


uint FUN_00411a00(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_004144c0();
  if ((uVar1 != 0x2693) && (uVar1 != 0x2694)) {
    if (-1 < (int)uVar1) {
      if (param_2 == 0) {
        return (uint)*(ushort *)(&DAT_005bebb0 + uVar1 * 2);
      }
      if (param_2 == 1) {
        return (uint)*(ushort *)(&DAT_005bf2f8 + uVar1 * 2);
      }
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


