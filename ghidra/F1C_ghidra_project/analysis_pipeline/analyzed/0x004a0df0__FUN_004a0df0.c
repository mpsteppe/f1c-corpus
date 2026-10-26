// Function: FUN_004a0df0 @ 004a0df0
// Size (bytes): 116


void FUN_004a0df0(void)

{
  int iVar1;
  undefined4 unaff_retaddr;
  
  iVar1 = FUN_00461cd0();
  if (iVar1 == 3) {
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x24);
  }
  else {
    iVar1 = FUN_00461cd0();
    if (iVar1 != 2) {
      return;
    }
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x23);
  }
  if (iVar1 != 0) {
    FUN_004896c0(unaff_retaddr,0);
    FUN_00489ab0(*(undefined4 *)(iVar1 + 0x94),1);
    FUN_004c8de0(4,0x3f800000);
  }
  return;
}


