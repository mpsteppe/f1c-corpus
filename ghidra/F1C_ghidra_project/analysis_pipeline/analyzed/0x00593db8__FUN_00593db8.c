// Function: FUN_00593db8 @ 00593db8
// Size (bytes): 27


undefined4 FUN_00593db8(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_008d41b4 != (code *)0x0) {
    iVar1 = (*DAT_008d41b4)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


