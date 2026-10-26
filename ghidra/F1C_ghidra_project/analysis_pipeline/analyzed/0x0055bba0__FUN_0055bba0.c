// Function: FUN_0055bba0 @ 0055bba0
// Size (bytes): 69


undefined4 __fastcall FUN_0055bba0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x120);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x20); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
      if (iVar1 != 0) {
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_00587bcf(iVar1);
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  return 0;
}


