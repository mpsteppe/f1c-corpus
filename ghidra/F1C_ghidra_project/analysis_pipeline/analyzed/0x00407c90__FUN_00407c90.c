// Function: FUN_00407c90 @ 00407c90
// Size (bytes): 166


void __thiscall FUN_00407c90(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = *(int **)(param_1 + 0x18);
  *(int **)(param_1 + 0x20) = piVar3;
  if ((piVar3 != (int *)0x0) && (iVar2 = *piVar3, iVar2 != 0)) {
    while (param_2 != iVar2) {
      if (*(int *)(param_1 + 0x20) != 0) {
        *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
      }
      if (*(int **)(param_1 + 0x20) == (int *)0x0) {
        return;
      }
      iVar2 = **(int **)(param_1 + 0x20);
      if (iVar2 == 0) {
        return;
      }
    }
    if (param_2 != 0) {
      piVar3 = (int *)0x0;
      piVar4 = *(int **)(param_1 + 0x18);
      if (*(int **)(param_1 + 0x18) != (int *)0x0) {
        while (*piVar4 != param_2) {
          piVar1 = piVar4 + 1;
          piVar3 = piVar4;
          piVar4 = (int *)*piVar1;
          if ((int *)*piVar1 == (int *)0x0) {
            return;
          }
        }
        if (piVar4 == *(int **)(param_1 + 0x20)) {
          *(int *)(param_1 + 0x20) = piVar4[1];
        }
        if (piVar3 == (int *)0x0) {
          *(int *)(param_1 + 0x18) = piVar4[1];
        }
        else {
          piVar3[1] = piVar4[1];
        }
        if (*(int **)(param_1 + 0x1c) == piVar4) {
          *(int **)(param_1 + 0x1c) = piVar3;
        }
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
        if (((char)piVar4[2] != '\0') && ((undefined4 *)*piVar4 != (undefined4 *)0x0)) {
          (*(code *)**(undefined4 **)*piVar4)(1);
        }
        FUN_00587bcf(piVar4);
      }
    }
  }
  return;
}


