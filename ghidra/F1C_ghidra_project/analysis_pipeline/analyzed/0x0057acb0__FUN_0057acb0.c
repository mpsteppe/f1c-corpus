// Function: FUN_0057acb0 @ 0057acb0
// Size (bytes): 191


undefined4 FUN_0057acb0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_00585cc0();
  (**(code **)(*piVar2 + 4))();
  FUN_004b0170();
  piVar2 = DAT_008d3bfc;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    if (*piVar2 == param_1) break;
    piVar2 = (int *)piVar2[1];
  }
  if (piVar2 == DAT_008d3c04) {
    DAT_008d3c04 = (int *)piVar2[1];
  }
  if (piVar2[2] == 0) {
    DAT_008d3bfc = (int *)piVar2[1];
  }
  else {
    *(int *)(piVar2[2] + 4) = piVar2[1];
  }
  if (piVar2[1] != 0) {
    *(int *)(piVar2[1] + 8) = piVar2[2];
  }
  if (DAT_008d3c00 == piVar2) {
    DAT_008d3c00 = (int *)piVar2[2];
  }
  DAT_008d3c08 = DAT_008d3c08 + -1;
  if (((char)piVar2[3] != '\0') && (iVar1 = *piVar2, iVar1 != 0)) {
    FUN_0057a4c0();
    FUN_00587bcf(iVar1);
  }
  FUN_00587bcf(piVar2);
  return 0;
}


