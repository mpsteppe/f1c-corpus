// Function: FUN_004ba7a0 @ 004ba7a0
// Size (bytes): 126


undefined4 __thiscall FUN_004ba7a0(int *param_1,int param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  uVar3 = 0;
  if (param_2 != 0) {
    piVar4 = (int *)0x0;
    piVar5 = (int *)*param_1;
    if ((int *)*param_1 != (int *)0x0) {
      while (*piVar5 != param_2) {
        piVar1 = piVar5 + 1;
        piVar4 = piVar5;
        piVar5 = (int *)*piVar1;
        if ((int *)*piVar1 == (int *)0x0) {
          return uVar3;
        }
      }
      if (piVar5 == (int *)param_1[2]) {
        param_1[2] = piVar5[1];
      }
      if (piVar4 == (int *)0x0) {
        *param_1 = piVar5[1];
      }
      else {
        piVar4[1] = piVar5[1];
      }
      if ((int *)param_1[1] == piVar5) {
        param_1[1] = (int)piVar4;
      }
      param_1[3] = param_1[3] + -1;
      if (param_3 == '\0') {
        *(undefined1 *)(piVar5 + 2) = 0;
      }
      if (((char)piVar5[2] != '\0') && (iVar2 = *piVar5, iVar2 != 0)) {
        FUN_004b0170();
        FUN_00587bcf(iVar2);
      }
      FUN_00587bcf(piVar5);
      uVar3 = 1;
    }
  }
  return uVar3;
}


