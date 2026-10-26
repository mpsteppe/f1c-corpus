// Function: FUN_00491770 @ 00491770
// Size (bytes): 66


void __fastcall FUN_00491770(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  iVar3 = 0;
  if (0 < *piVar1) {
    iVar2 = 0;
    do {
      FUN_004910d0(piVar1[2] + iVar2);
      piVar1 = (int *)*param_1;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < *piVar1);
  }
  FUN_004910d0(*param_1 + 0xc);
  FUN_004910d0(*param_1 + 0x1c);
  return;
}


