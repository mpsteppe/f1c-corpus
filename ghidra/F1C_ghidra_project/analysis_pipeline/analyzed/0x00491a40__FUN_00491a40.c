// Function: FUN_00491a40 @ 00491a40
// Size (bytes): 138


undefined4 __fastcall FUN_00491a40(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  
  piVar5 = *(int **)(*param_1 + 0x10);
  uVar4 = 0;
  *(int **)(*param_1 + 0x14) = piVar5;
  if ((piVar5 != (int *)0x0) && (iVar2 = *piVar5, iVar2 != 0)) {
    FUN_00490aa0();
    iVar3 = *param_1;
    piVar5 = (int *)0x0;
    piVar6 = *(int **)(iVar3 + 0xc);
    if (*(int **)(iVar3 + 0xc) != (int *)0x0) {
      while (*piVar6 != iVar2) {
        piVar1 = piVar6 + 1;
        piVar5 = piVar6;
        piVar6 = (int *)*piVar1;
        if ((int *)*piVar1 == (int *)0x0) {
          return 1;
        }
      }
      if (piVar6 == *(int **)(iVar3 + 0x14)) {
        *(int *)(iVar3 + 0x14) = piVar6[1];
      }
      if (piVar5 == (int *)0x0) {
        *(int *)(iVar3 + 0xc) = piVar6[1];
      }
      else {
        piVar5[1] = piVar6[1];
      }
      if (*(int **)(iVar3 + 0x10) == piVar6) {
        *(int **)(iVar3 + 0x10) = piVar5;
      }
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -1;
      if (((char)piVar6[2] != '\0') && (*piVar6 != 0)) {
        FUN_00587bcf(*piVar6);
      }
      FUN_00587bcf(piVar6);
    }
    uVar4 = 1;
  }
  return uVar4;
}


