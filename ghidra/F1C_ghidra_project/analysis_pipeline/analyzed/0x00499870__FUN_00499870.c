// Function: FUN_00499870 @ 00499870
// Size (bytes): 67


undefined4 __fastcall FUN_00499870(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = *(int *)(param_1 + 0x10) == 0;
  iVar2 = 0;
  if (!bVar3) {
    iVar2 = *(int *)(param_1 + 0xc);
    if (*(int *)(iVar2 + 0xc) != 0) {
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(iVar2 + 0xc) + 4);
    }
    if (*(int **)(iVar2 + 0xc) == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = **(int **)(iVar2 + 0xc);
    }
    *(int *)(param_1 + 0x10) = iVar2;
    if (iVar2 != 0) {
      uVar1 = FUN_00498e30();
      *(undefined4 *)(param_1 + 0x14) = uVar1;
    }
    iVar2 = *(int *)(param_1 + 0x10);
    bVar3 = iVar2 == 0;
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),!bVar3);
}


