// Function: FUN_004a18d0 @ 004a18d0
// Strings:  [_F1 Challenge 99-02_APP_MUTEX_, Entered OSMan::Enter(), D:\dev\F1_1999_2002\Source\osman.cpp]


undefined4 FUN_004a18d0(void)

{
  char cVar1;
  DWORD DVar2;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_osman_005cd0ec,0x1a4);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_OSMan__Enter___005cd0d4);
  }
  DAT_007ce2d8 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,s__F1_Challenge_99_02_APP_MUTEX__005cd0b4
                             );
  if (DAT_007ce2d8 != (HANDLE)0x0) {
    DVar2 = GetLastError();
    if (DVar2 != 0xb7) {
      return 0;
    }
  }
  return 1;
}


