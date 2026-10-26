// Function: FUN_004a0c60 @ 004a0c60
// Size (bytes): 74


undefined4 FUN_004a0c60(void)

{
  char cVar1;
  
  cVar1 = FUN_00404f00();
  if (cVar1 != '\0') {
    DAT_007c569c = 6;
    FUN_00404f30();
    return 0;
  }
  if (DAT_007ce814 == 0) {
    FUN_00408420(0x3f000000);
    FUN_004a0d10();
  }
  return 0;
}


