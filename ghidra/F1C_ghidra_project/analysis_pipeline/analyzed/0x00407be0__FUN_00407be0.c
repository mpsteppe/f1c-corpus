// Function: FUN_00407be0 @ 00407be0
// Size (bytes): 166


void __thiscall FUN_00407be0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = *(int **)(param_1 + 8);
  *(int **)(param_1 + 0x10) = piVar3;
  if ((piVar3 != (int *)0x0) && (iVar2 = *piVar3, iVar2 != 0)) {
    while (param_2 != iVar2) {
      if (*(int *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
      }
      if (*(int **)(param_1 + 0x10) == (int *)0x0) {
        return;
      }
      iVar2 = **(int **)(param_1 + 0x10);
      if (iVar2 == 0) {
        return;
      }
    }
    if (param_2 != 0) {
      piVar3 = (int *)0x0;
      piVar4 = *(int **)(param_1 + 8);
      if (*(int **)(param_1 + 8) != (int *)0x0) {
        while (*piVar4 != param_2) {
          piVar1 = piVar4 + 1;
          piVar3 = piVar4;
          piVar4 = (int *)*piVar1;
          if ((int *)*piVar1 == (int *)0x0) {
            return;
          }
        }
        if (piVar4 == *(int **)(param_1 + 0x10)) {
          *(int *)(param_1 + 0x10) = piVar4[1];
        }
        if (piVar3 == (int *)0x0) {
          *(int *)(param_1 + 8) = piVar4[1];
        }
        else {
          piVar3[1] = piVar4[1];
        }
        if (*(int **)(param_1 + 0xc) == piVar4) {
          *(int **)(param_1 + 0xc) = piVar3;
        }
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
        if (((char)piVar4[2] != '\0') && ((undefined4 *)*piVar4 != (undefined4 *)0x0)) {
          (*(code *)**(undefined4 **)*piVar4)(1);
        }
        FUN_00587bcf(piVar4);
      }
    }
  }
  return;
}


