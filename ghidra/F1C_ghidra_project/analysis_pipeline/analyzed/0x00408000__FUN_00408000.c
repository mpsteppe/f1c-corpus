// Function: FUN_00408000 @ 00408000
// Size (bytes): 76


void __thiscall FUN_00408000(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 != -1) {
    piVar1 = *(int **)(param_1 + 0x18);
    *(int **)(param_1 + 0x20) = piVar1;
    if ((piVar1 != (int *)0x0) && (iVar2 = *piVar1, iVar2 != 0)) {
      while (*(int *)(iVar2 + 0x5c) != param_2) {
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
      FUN_00406a70();
    }
  }
  return;
}


