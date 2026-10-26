// Function: FUN_0042c3b0 @ 0042c3b0
// Strings:  [D:\dev\F1_1999_2002\Source\dynman.cpp, Entered DynMan::Restart()]


void FUN_0042c3b0(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_dynma_005c3334,0x26f);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_DynMan__Restart___005c338c);
  }
  iVar2 = 0;
  DAT_007c5694 = 0;
  DAT_007c5698 = 0;
  FUN_004333e0();
  if (0 < DAT_005c329c) {
    do {
      FUN_004c6d90(1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_005c329c);
  }
  FUN_00410890();
  DAT_007c54dc = DAT_007c54e4;
  DAT_007c54e0 = (&DAT_007c54f0)[DAT_007c54e4];
  return;
}


