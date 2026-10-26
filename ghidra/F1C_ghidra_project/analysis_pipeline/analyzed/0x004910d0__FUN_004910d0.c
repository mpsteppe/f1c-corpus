// Function: FUN_004910d0 @ 004910d0
// Size (bytes): 148


undefined4 FUN_004910d0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  param_1[2] = (int)piVar1;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    while( true ) {
      FUN_00490aa0();
      if (param_1[2] == 0) break;
      piVar1 = *(int **)(param_1[2] + 4);
      param_1[2] = (int)piVar1;
      if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) break;
    }
  }
  piVar1 = (int *)*param_1;
  while (piVar1 != (int *)0x0) {
    piVar2 = (int *)piVar1[1];
    if (((char)piVar1[2] != '\0') && (iVar3 = *piVar1, iVar3 != 0)) {
      FUN_004b0170();
      FUN_00587bcf(iVar3);
    }
    FUN_00587bcf(piVar1);
    piVar1 = piVar2;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return 1;
}


