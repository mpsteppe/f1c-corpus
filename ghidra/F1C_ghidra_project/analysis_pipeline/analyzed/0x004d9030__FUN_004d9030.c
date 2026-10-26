// Function: FUN_004d9030 @ 004d9030
// Size (bytes): 139


void FUN_004d9030(int param_1)

{
  int iVar1;
  int *piVar2;
  
  switch(param_1) {
  case 1:
    piVar2 = &DAT_008ad398;
    break;
  case 2:
    piVar2 = &DAT_008ad39c;
    break;
  case 3:
    piVar2 = &DAT_008ad3a0;
    break;
  case 4:
    piVar2 = &DAT_008ad3a4;
    break;
  case 5:
    piVar2 = &DAT_008ad3a8;
    break;
  default:
    goto switchD_004d903e_default;
  }
  if (*piVar2 != 0) {
    FUN_005539f0(*piVar2);
    *piVar2 = 0;
  }
switchD_004d903e_default:
  if ((param_1 == 3) && (DAT_008ad3ac != 0)) {
    FUN_005502c0();
    iVar1 = DAT_008ad3ac;
    if (DAT_008ad3ac != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar1);
    }
    DAT_008ad3ac = 0;
  }
  return;
}


