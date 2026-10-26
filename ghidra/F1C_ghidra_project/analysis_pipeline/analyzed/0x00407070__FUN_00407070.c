// Function: FUN_00407070 @ 00407070
// Size (bytes): 97


void __fastcall FUN_00407070(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if ((*(int *)(param_1 + 0x48) != 0) && (iVar3 = 0, 0 < *(int *)(param_1 + 0x4c))) {
    iVar4 = 0;
    do {
      piVar2 = *(int **)(iVar4 + *(int *)(param_1 + 0x48));
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x10))();
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar3 < *(int *)(param_1 + 0x4c));
  }
  piVar2 = *(int **)(param_1 + 0x18);
  *(int **)(param_1 + 0x20) = piVar2;
  if ((piVar2 != (int *)0x0) && (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0)) {
    while( true ) {
      (**(code **)(*piVar2 + 0x14))();
      if (*(int *)(param_1 + 0x20) == 0) break;
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x20) + 4);
      *(undefined4 **)(param_1 + 0x20) = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        return;
      }
      piVar2 = (int *)*puVar1;
      if (piVar2 == (int *)0x0) {
        return;
      }
    }
  }
  return;
}


