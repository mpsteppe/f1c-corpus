// Function: FUN_00496e40 @ 00496e40
// Size (bytes): 68


void __fastcall FUN_00496e40(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x18dc);
  *(int **)(param_1 + 0x18e4) = piVar2;
  if ((piVar2 != (int *)0x0) && (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0)) {
    while( true ) {
      (**(code **)(*piVar2 + 0x6c))();
      if (*(int *)(param_1 + 0x18e4) == 0) break;
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x18e4) + 4);
      *(undefined4 **)(param_1 + 0x18e4) = puVar1;
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


