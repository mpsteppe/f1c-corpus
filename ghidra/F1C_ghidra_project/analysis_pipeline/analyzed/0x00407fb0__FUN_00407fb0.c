// Function: FUN_00407fb0 @ 00407fb0
// Size (bytes): 73


undefined1 __thiscall FUN_00407fb0(int param_1,int param_2)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (param_2 != -1) {
    piVar1 = *(int **)(param_1 + 0x18);
    *(int **)(param_1 + 0x20) = piVar1;
    if ((piVar1 != (int *)0x0) && (iVar3 = *piVar1, iVar3 != 0)) {
      while (*(int *)(iVar3 + 0x5c) != param_2) {
        if (*(int *)(param_1 + 0x20) != 0) {
          *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
        }
        if (*(int **)(param_1 + 0x20) == (int *)0x0) {
          return 0;
        }
        iVar3 = **(int **)(param_1 + 0x20);
        if (iVar3 == 0) {
          return uVar2;
        }
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}


