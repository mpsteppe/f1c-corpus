// Function: FUN_004b8480 @ 004b8480
// Size (bytes): 111


void __fastcall FUN_004b8480(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  *(undefined1 *)(param_1 + 0x6d0) = 1;
  piVar3 = *(int **)(param_1 + 0x6c0);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[3] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      if (*(int *)(iVar2 + 4) != 0) {
        FUN_00587bcf(*(int *)(iVar2 + 4));
      }
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x6c0) = 0;
  *(undefined4 *)(param_1 + 0x6c4) = 0;
  *(undefined4 *)(param_1 + 0x6c8) = 0;
  *(undefined4 *)(param_1 + 0x6cc) = 0;
  return;
}


