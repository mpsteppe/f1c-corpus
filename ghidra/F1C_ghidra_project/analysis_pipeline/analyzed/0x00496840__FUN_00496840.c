// Function: FUN_00496840 @ 00496840
// Size (bytes): 59


int __fastcall FUN_00496840(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 4);
  while ((*(int **)(param_1 + 0xc) != (int *)0x0 && (iVar1 = **(int **)(param_1 + 0xc), iVar1 != 0))
        ) {
    iVar1 = FUN_004958d0(iVar1);
    iVar2 = iVar2 + iVar1;
    if (*(int *)(param_1 + 0xc) != 0) {
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 4);
    }
  }
  return iVar2;
}


