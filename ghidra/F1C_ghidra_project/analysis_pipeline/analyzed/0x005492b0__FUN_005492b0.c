// Function: FUN_005492b0 @ 005492b0
// Size (bytes): 62


void __fastcall FUN_005492b0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  for (piVar1 = *(int **)(param_1 + 0xf0); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0xd]) {
    iVar2 = FUN_005456b0(*piVar1 + 0x58);
    if (iVar2 != 0) {
      FUN_005455f0(iVar2);
      FUN_00549250(iVar2);
    }
  }
  return;
}


