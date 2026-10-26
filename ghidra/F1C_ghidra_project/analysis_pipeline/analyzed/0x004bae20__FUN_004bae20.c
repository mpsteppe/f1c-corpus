// Function: FUN_004bae20 @ 004bae20
// Size (bytes): 131


int __fastcall FUN_004bae20(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)*param_1;
  param_1[2] = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    *(undefined1 *)(piVar1 + 2) = 0;
    if (iVar2 != 0) {
      piVar1 = (int *)0x0;
      for (piVar4 = (int *)*param_1; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
        if (*piVar4 == iVar2) {
          if (piVar4 == (int *)param_1[2]) {
            param_1[2] = piVar4[1];
          }
          if (piVar1 == (int *)0x0) {
            *param_1 = piVar4[1];
          }
          else {
            piVar1[1] = piVar4[1];
          }
          if ((int *)param_1[1] == piVar4) {
            param_1[1] = (int)piVar1;
          }
          param_1[3] = param_1[3] + -1;
          if (((char)piVar4[2] != '\0') && (iVar3 = *piVar4, iVar3 != 0)) {
            FUN_004b0170();
            FUN_00587bcf(iVar3);
          }
          FUN_00587bcf(piVar4);
          return iVar2;
        }
        piVar1 = piVar4;
      }
    }
  }
  return 0;
}


