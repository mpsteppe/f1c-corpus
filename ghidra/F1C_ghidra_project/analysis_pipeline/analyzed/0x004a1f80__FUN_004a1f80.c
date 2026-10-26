// Function: FUN_004a1f80 @ 004a1f80
// Size (bytes): 44


void __fastcall FUN_004a1f80(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = *(int *)(param_1 + iVar3 * 4);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x44);
      FUN_00587bcf(iVar2);
      iVar2 = iVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}


