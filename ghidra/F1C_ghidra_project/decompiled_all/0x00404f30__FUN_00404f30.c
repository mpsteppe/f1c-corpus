// Function: FUN_00404f30 @ 00404f30
// Strings:  [MAIN MENU]


void FUN_00404f30(void)

{
  char cVar1;
  
  FUN_004a0250();
  FUN_004a03f0();
  cVar1 = FUN_00404f10();
  if (cVar1 != '\0') {
    FUN_00497940(s_MAIN_MENU_005be708,0xffffffff);
  }
  FUN_004049d0();
  return;
}


