// Function: FUN_004a0430 @ 004a0430
// Strings:  [MPCLIENTGRID, MPHOSTGRID, MONITORPAGE]


undefined4 FUN_004a0430(void)

{
  char cVar1;
  
  if (0 < DAT_007d0410) {
    if (DAT_007d0410 < 5) {
      FUN_00497940(s_MONITORPAGE_005c6bd4,0xffffffff);
    }
    else if (DAT_007d0410 == 5) {
      cVar1 = FUN_00461dc0();
      if (cVar1 != '\0') {
        FUN_00497940(s_MPHOSTGRID_005c6bc8,0xffffffff);
        return 0;
      }
      FUN_00497940(s_MPCLIENTGRID_005c5f5c,0xffffffff);
      return 0;
    }
  }
  return 0;
}


