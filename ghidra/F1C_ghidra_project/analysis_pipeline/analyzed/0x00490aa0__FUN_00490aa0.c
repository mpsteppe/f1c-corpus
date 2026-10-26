// Function: FUN_00490aa0 @ 00490aa0
// Size (bytes): 91


void __fastcall FUN_00490aa0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_00490930();
  FUN_00491330();
  if (param_1 != 0) {
    piVar2 = operator_new(0xc);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      *piVar2 = param_1;
      piVar2[1] = 0;
      *(undefined1 *)(piVar2 + 2) = 0;
    }
    if (*(int *)(iVar1 + 0x10) == 0) {
      *(int **)(iVar1 + 0x14) = piVar2;
      *(int **)(iVar1 + 0x18) = piVar2;
      *(int **)(iVar1 + 0x10) = piVar2;
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
      return;
    }
    piVar2[1] = *(int *)(iVar1 + 0x10);
    *(int **)(iVar1 + 0x10) = piVar2;
    *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
  }
  return;
}


