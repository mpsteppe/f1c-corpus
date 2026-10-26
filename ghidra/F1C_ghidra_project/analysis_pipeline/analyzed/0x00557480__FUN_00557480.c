// Function: FUN_00557480 @ 00557480
// Size (bytes): 46


undefined4 FUN_00557480(int param_1)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x20) & 8) == 0) {
    iVar1 = FUN_00557ce0(param_1);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
  }
  else {
    iVar1 = FUN_00557670(param_1);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
  }
  return 0;
}


