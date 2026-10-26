// Function: FUN_004078a0 @ 004078a0
// Size (bytes): 119


int __fastcall FUN_004078a0(int param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x88) != 0) {
    pvVar1 = operator_new(0x60);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_00406130(param_1);
      if (iVar2 != 0) {
        piVar3 = operator_new(0xc);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          *piVar3 = iVar2;
          piVar3[1] = 0;
          *(undefined1 *)(piVar3 + 2) = 0;
        }
        if (*(int *)(param_1 + 0x18) == 0) {
          *(int **)(param_1 + 0x18) = piVar3;
          *(int **)(param_1 + 0x20) = piVar3;
          *(int **)(param_1 + 0x1c) = piVar3;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          return iVar2;
        }
        *(int **)(*(int *)(param_1 + 0x1c) + 4) = piVar3;
        *(int **)(param_1 + 0x1c) = piVar3;
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        return iVar2;
      }
    }
  }
  return 0;
}


