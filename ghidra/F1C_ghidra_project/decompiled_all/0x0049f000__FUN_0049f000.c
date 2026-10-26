// Function: FUN_0049f000 @ 0049f000
// Strings:  [D:\dev\F1_1999_2002\Source\onscreen.cpp, Entered OnScreen::Restart()]


void __fastcall FUN_0049f000(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_onscr_005ccf10,0xa4b);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_OnScreen__Restart___005ccf70);
  }
  FUN_0045bdf0();
  FUN_0049f150(0);
  *(undefined4 *)(param_1 + 4) = 1;
  *(undefined1 *)(param_1 + 8) = 0;
  FUN_0045bdf0();
  FUN_004d82a0();
  return;
}


