// Function: FUN_004bb6b0 @ 004bb6b0
// Size (bytes): 115


undefined4 __thiscall FUN_004bb6b0(int *param_1,int param_2,char param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  uVar2 = 0;
  if (param_2 != 0) {
    piVar3 = (int *)0x0;
    piVar4 = (int *)*param_1;
    if ((int *)*param_1 != (int *)0x0) {
      while (*piVar4 != param_2) {
        piVar1 = piVar4 + 1;
        piVar3 = piVar4;
        piVar4 = (int *)*piVar1;
        if ((int *)*piVar1 == (int *)0x0) {
          return uVar2;
        }
      }
      if (piVar4 == (int *)param_1[2]) {
        param_1[2] = piVar4[1];
      }
      if (piVar3 == (int *)0x0) {
        *param_1 = piVar4[1];
      }
      else {
        piVar3[1] = piVar4[1];
      }
      if ((int *)param_1[1] == piVar4) {
        param_1[1] = (int)piVar3;
      }
      param_1[3] = param_1[3] + -1;
      if (param_3 == '\0') {
        *(undefined1 *)(piVar4 + 2) = 0;
      }
      if ((char)piVar4[2] != '\0') {
        FUN_00587bcf(*piVar4);
      }
      FUN_00587bcf(piVar4);
      uVar2 = 1;
    }
  }
  return uVar2;
}


