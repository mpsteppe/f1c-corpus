// Function: FUN_0049b1c0 @ 0049b1c0
// Size (bytes): 60


void FUN_0049b1c0(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_007ce23c;
  do {
    if (*piVar2 != 0) {
      FUN_004dcd10();
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        FUN_004dcd10();
        FUN_00587bcf(iVar1);
      }
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x7ce24c);
  return;
}


