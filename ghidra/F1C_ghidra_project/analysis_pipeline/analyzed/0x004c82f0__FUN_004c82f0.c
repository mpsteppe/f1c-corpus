// Function: FUN_004c82f0 @ 004c82f0
// Size (bytes): 84


void FUN_004c82f0(void)

{
  int iVar1;
  
  if (DAT_008ac4c4 != (int *)0x0) {
    (**(code **)(*DAT_008ac4c4 + 0x38))(2);
    iVar1 = (**(code **)(*DAT_008ac4c4 + 4))(DAT_007ce2dc);
    if (iVar1 == 0) {
      (**(code **)(*DAT_008ac4c4 + 0x2c))(0x3f800000);
      (**(code **)(*DAT_008ac4c4 + 0x34))(DAT_007cf230);
      return;
    }
    DAT_008ac4c4 = (int *)0x0;
  }
  return;
}


