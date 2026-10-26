// Function: FUN_004a0030 @ 004a0030
// Strings:  [MONITORPAGE]


undefined4 FUN_004a0030(void)

{
  switch(DAT_007d0410) {
  case 1:
  case 2:
  case 3:
  case 4:
    FUN_004a0d30(1);
    FUN_00497940(s_MONITORPAGE_005c6bd4,0xffffffff);
    break;
  case 5:
  case 6:
    FUN_004a0d30(1);
  }
  FUN_004c8d90(1);
  FUN_0042e400();
  return 0;
}


