
undefined4 FUN_0046d6d0(void)

{
  int iVar1;
  undefined1 auStack_80 [128];
  
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  switch(DAT_007d0410) {
  case 1:
  case 2:
  case 3:
    FUN_00486aa0(s_SELECTCIRCUITPAGE_005c65ec);
    return 0xffffffff;
  case 4:
    FUN_004a0630();
    FUN_00486aa0(s_CH_RESUME_005c6bf8);
    return 0xffffffff;
  case 5:
    break;
  default:
    return 0;
  }
  iVar1 = FUN_00461cd0();
  if (iVar1 == 3) {
    FUN_00497940(s_MPCLIENTGRID_005c5f5c,0xffffffff);
    FUN_00461550();
    FUN_004627c0(auStack_80,0);
    FUN_00461900();
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x18);
    if (iVar1 != 0) {
      FUN_00477640();
      FUN_00477680();
    }
    DAT_005cc9e8 = 1;
    FUN_004b0170();
  }
  return 0xffffffff;
}

