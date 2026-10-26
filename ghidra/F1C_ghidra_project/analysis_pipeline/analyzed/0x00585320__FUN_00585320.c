// Function: FUN_00585320 @ 00585320
// Size (bytes): 95


void __thiscall FUN_00585320(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x11c);
  *(int **)(param_1 + 0x124) = piVar1;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    while( true ) {
      iVar2 = FUN_00587720();
      if (iVar2 != -1) {
        FUN_005878a0(param_2);
        FUN_00587710(0xffffffff);
      }
      if (*(int *)(param_1 + 0x124) == 0) break;
      piVar1 = *(int **)(*(int *)(param_1 + 0x124) + 4);
      *(int **)(param_1 + 0x124) = piVar1;
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


