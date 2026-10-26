// Function: FUN_004a0eb0 @ 004a0eb0
// Strings:  [Entered Options::Setup(), D:\dev\F1_1999_2002\Source\options.cpp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a0eb0(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_optio_005cd064,0x491);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_Options__Setup___005cd048);
  }
  if (DAT_007ce260 == '\0') {
    if (DAT_007ce264 == 0) {
      FUN_00404b50();
      while( true ) {
        FUN_004f9f00();
        FUN_004537b0((float)_DAT_008afe90);
        DAT_007ce250 = DAT_007ce250 + 1;
        iVar2 = FUN_00485b90();
        FUN_004186f0();
        FUN_004f9ad0();
        FUN_00404b60();
        if (DAT_007ce25c != '\0') {
          DAT_007ce25c = 0;
          return 0;
        }
        if (iVar2 == -1) break;
        if (iVar2 == 1) {
          return 0;
        }
        FUN_004f9f30();
        FUN_004a1830();
      }
    }
    else if (DAT_005ccfe4 != '\0') {
      DAT_005ccfe4 = 0;
      return 0;
    }
    return 1;
  }
  DAT_007c5690 = 1;
  return 0;
}


