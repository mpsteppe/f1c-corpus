// Function: FUN_0046fc30 @ 0046fc30
// Strings:  [MAIN MENU, MPCLIENTGRID, MPHOSTGRID, CH_POSTRACEDRIVERSTANDINGS]


undefined4 FUN_0046fc30(void)

{
  char cVar1;
  
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  if (DAT_007d0410 == 4) {
    FUN_004a0760();
    FUN_00486aa0(s_CH_POSTRACEDRIVERSTANDINGS_005c6df8);
    return 0;
  }
  if (DAT_007d0410 != 5) {
    FUN_00486aa0(s_MAIN_MENU_005be708);
    DAT_005cc9e8 = 3;
    return 0;
  }
  cVar1 = FUN_00461dc0();
  if (cVar1 != '\0') {
    FUN_00497940(s_MPHOSTGRID_005c6bc8,0xffffffff);
    return 0;
  }
  FUN_00497940(s_MPCLIENTGRID_005c5f5c,0xffffffff);
  return 0;
}


