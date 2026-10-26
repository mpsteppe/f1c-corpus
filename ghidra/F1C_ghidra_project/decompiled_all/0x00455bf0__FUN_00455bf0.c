// Function: FUN_00455bf0 @ 00455bf0
// Strings:  [Entered HWInput::Enter(), D:\dev\F1_1999_2002\Source\hwinput.cpp]


undefined4 FUN_00455bf0(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_hwinp_005c56a4,0x1455);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_HWInput__Enter___005c5688);
  }
  FUN_0044f4e0();
  do {
    iVar2 = ShowCursor(0);
  } while (-1 < iVar2);
  FUN_00455290();
  if (DAT_007d13a0 == '\x01') {
    FUN_004f8ae0();
  }
  return 0;
}


