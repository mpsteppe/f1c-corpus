// Function: FUN_0059af68 @ 0059af68
// Strings:  [invalid string position, invalid string position, invalid string position]


void FUN_0059af68(void)

{
  size_t sVar1;
  int unaff_EBP;
  
  FUN_0058a5d8();
  *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + -0xd);
  FUN_005993af(0);
  sVar1 = _strlen("invalid string position");
  FUN_00599615("invalid string position",sVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0059ada3(unaff_EBP + -0x20);
  *(undefined ***)(unaff_EBP + -0x3c) = &PTR_LAB_005b9d8c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x3c,&DAT_005bb9b8);
}


