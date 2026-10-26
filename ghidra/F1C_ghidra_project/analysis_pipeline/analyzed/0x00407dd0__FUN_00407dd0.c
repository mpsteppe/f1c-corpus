// Function: FUN_00407dd0 @ 00407dd0
// Size (bytes): 60


void __thiscall FUN_00407dd0(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  *(int **)(param_1 + 0x20) = piVar1;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    while( true ) {
      FUN_00406640(param_2);
      if (*(int *)(param_1 + 0x20) == 0) break;
      piVar1 = *(int **)(*(int *)(param_1 + 0x20) + 4);
      *(int **)(param_1 + 0x20) = piVar1;
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


