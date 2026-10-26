// Function: FUN_0046e170 @ 0046e170
// Size (bytes): 49


void FUN_0046e170(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x24);
  if (iVar1 != 0) {
    FUN_00489cb0();
  }
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x23);
  if (iVar1 != 0) {
    FUN_00489cb0();
    return;
  }
  return;
}


