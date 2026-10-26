// Function: FUN_004c62c0 @ 004c62c0
// Size (bytes): 111


void __fastcall FUN_004c62c0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_00566650(&DAT_005ea438);
  piVar3 = *(int **)(param_1 + 8);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      if (*(int *)(iVar2 + 4) != 0) {
        FUN_00587bcf(*(int *)(iVar2 + 4));
      }
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


