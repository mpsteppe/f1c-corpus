// Function: FUN_0042c9f0 @ 0042c9f0
// Strings:  [D:\dev\F1_1999_2002\Source\dynman.cpp, Entered DynMan::Post()]


void FUN_0042c9f0(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_dynma_005c3334,0x3a5);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_DynMan__Post___005c3498);
  }
  iVar2 = 0;
  if (0 < DAT_005c329c) {
    do {
      FUN_004c6e80();
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_005c329c);
  }
  FUN_0043e230();
  FUN_0042bd60();
  FUN_0040fb30();
  return;
}


