// Function: FUN_004a1d10 @ 004a1d10
// Size (bytes): 59


void __thiscall FUN_004a1d10(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  param_1[2] = (int)piVar1;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    while( true ) {
      FUN_004a1b90(param_2);
      if (param_1[2] == 0) break;
      piVar1 = *(int **)(param_1[2] + 4);
      param_1[2] = (int)piVar1;
      if (piVar1 == (int *)0x0) {
        return;
      }
      if (*piVar1 == 0) {
        return;
      }
    }
  }
  return;
}


