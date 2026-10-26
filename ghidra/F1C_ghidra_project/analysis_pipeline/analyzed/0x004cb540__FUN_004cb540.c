// Function: FUN_004cb540 @ 004cb540
// Size (bytes): 82


int __fastcall FUN_004cb540(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x60);
  *(int *)(param_1 + 0x60) = iVar1 + 1;
  if (*(int *)(param_1 + 0x58) <= iVar1 + 1) {
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  iVar2 = iVar1 * 0x6c;
  iVar3 = *(int *)(param_1 + 0x5c) + iVar2;
  if (*(int *)(*(int *)(param_1 + 0x5c) + 4 + iVar2) < 0) {
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(param_1 + 100);
    *(int *)(*(int *)(param_1 + 0x68) + *(int *)(param_1 + 100) * 4) =
         *(int *)(param_1 + 0x5c) + iVar2;
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
    FUN_00558a30(iVar1);
  }
  return iVar3;
}


