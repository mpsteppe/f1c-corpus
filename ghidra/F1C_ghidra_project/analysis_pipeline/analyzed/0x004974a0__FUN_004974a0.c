// Function: FUN_004974a0 @ 004974a0
// Size (bytes): 100


undefined4 __thiscall FUN_004974a0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 4);
  *(int **)(param_1 + 0xc) = piVar1;
  if (((piVar1 != (int *)0x0) && (iVar3 = *piVar1, iVar3 != 0)) && (param_2 != 0)) {
    while( true ) {
      if (iVar3 == param_2) {
        FUN_0054fc40(1);
        uVar2 = FUN_00498e30();
        FUN_00498f40(uVar2);
      }
      if (*(int *)(param_1 + 0xc) == 0) break;
      piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 4);
      *(int **)(param_1 + 0xc) = piVar1;
      if ((piVar1 == (int *)0x0) || (iVar3 = *piVar1, iVar3 == 0)) break;
    }
  }
  FUN_00497250(1);
  return 0;
}


