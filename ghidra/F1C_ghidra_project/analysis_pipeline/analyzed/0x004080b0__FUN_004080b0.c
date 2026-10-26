// Function: FUN_004080b0 @ 004080b0
// Size (bytes): 58


int * __thiscall FUN_004080b0(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x38);
  *(int **)(param_1 + 0x40) = piVar1;
  if (piVar1 == (int *)0x0) {
LAB_004080e5:
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)*piVar1;
    if (piVar1 != (int *)0x0) {
      while (*piVar1 != param_2) {
        if (*(int *)(param_1 + 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
        }
        if (*(undefined4 **)(param_1 + 0x40) == (undefined4 *)0x0) goto LAB_004080e5;
        piVar1 = (int *)**(undefined4 **)(param_1 + 0x40);
        if (piVar1 == (int *)0x0) {
          return (int *)0x0;
        }
      }
    }
  }
  return piVar1;
}


