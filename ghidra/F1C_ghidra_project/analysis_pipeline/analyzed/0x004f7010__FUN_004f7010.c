// Function: FUN_004f7010 @ 004f7010
// Size (bytes): 162


void __thiscall FUN_004f7010(int param_1,undefined1 param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xb0) == '\0') {
    if (*(int *)(param_1 + 0x6d8) != 0) {
      iVar2 = 0;
      do {
        piVar1 = *(int **)(iVar2 + *(int *)(param_1 + 0x6d8));
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))();
        }
        iVar2 = iVar2 + 4;
      } while (iVar2 < 0xb4);
      *(undefined1 *)(param_1 + 0xb0) = param_2;
      return;
    }
    *(undefined1 *)(param_1 + 0xb0) = param_2;
    return;
  }
  if (*(int *)(param_1 + 0x694) != 0) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(iVar2 + *(int *)(param_1 + 0x694));
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))();
      }
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0xb4);
    *(undefined1 *)(param_1 + 0xb0) = param_2;
    return;
  }
  *(undefined1 *)(param_1 + 0xb0) = param_2;
  return;
}


