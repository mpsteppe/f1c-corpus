// Function: FUN_004c1820 @ 004c1820
// Size (bytes): 141


undefined1 __fastcall FUN_004c1820(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  int *piVar5;
  
  iVar2 = FUN_004c2850();
  if (iVar2 == 0) {
    return 0;
  }
  piVar5 = (int *)*param_1;
  uVar4 = 0;
  piVar3 = (int *)0x0;
  if (piVar5 != (int *)0x0) {
    while (*piVar5 != iVar2) {
      piVar1 = piVar5 + 1;
      piVar3 = piVar5;
      piVar5 = (int *)*piVar1;
      if ((int *)*piVar1 == (int *)0x0) {
        return 0;
      }
    }
    if (piVar5 == (int *)param_1[2]) {
      param_1[2] = piVar5[1];
    }
    if (piVar3 == (int *)0x0) {
      *param_1 = piVar5[1];
    }
    else {
      piVar3[1] = piVar5[1];
    }
    if ((int *)param_1[1] == piVar5) {
      param_1[1] = (int)piVar3;
    }
    param_1[3] = param_1[3] + -1;
    if (((char)piVar5[2] != '\0') && (iVar2 = *piVar5, iVar2 != 0)) {
      FUN_004c0b10();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar5);
    uVar4 = 1;
  }
  return uVar4;
}


