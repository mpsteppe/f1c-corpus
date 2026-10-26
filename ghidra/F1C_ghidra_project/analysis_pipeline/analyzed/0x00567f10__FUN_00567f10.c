// Function: FUN_00567f10 @ 00567f10
// Size (bytes): 37


void __fastcall FUN_00567f10(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = *(int *)(param_1 + iVar2 * 4);
    if (iVar1 != 0) {
      FUN_00567cc0(iVar1);
    }
    *(undefined4 *)(param_1 + iVar2 * 4) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 9);
  return;
}


