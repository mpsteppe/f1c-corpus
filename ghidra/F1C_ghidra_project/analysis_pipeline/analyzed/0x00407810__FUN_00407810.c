// Function: FUN_00407810 @ 00407810
// Size (bytes): 144


int __thiscall FUN_00407810(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0x88) != 0) && (param_2 != 0)) {
    pvVar1 = operator_new(0x6c);
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_004057f0(param_2,param_3,param_4,param_1);
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
        if (*(int *)(param_1 + 8) == 0) {
          *(int **)(param_1 + 8) = piVar3;
          *(int **)(param_1 + 0x10) = piVar3;
          *(int **)(param_1 + 0xc) = piVar3;
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          return iVar2;
        }
        *(int **)(*(int *)(param_1 + 0xc) + 4) = piVar3;
        *(int **)(param_1 + 0xc) = piVar3;
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        return iVar2;
      }
    }
  }
  return 0;
}


