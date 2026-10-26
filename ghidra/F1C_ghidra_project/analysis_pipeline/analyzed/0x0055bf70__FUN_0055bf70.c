// Function: FUN_0055bf70 @ 0055bf70
// Size (bytes): 69


void __fastcall FUN_0055bf70(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    piVar2 = (int *)(param_1 + 8);
    do {
      FUN_0055bba0();
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar1);
      }
      *piVar2 = 0;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  return;
}


