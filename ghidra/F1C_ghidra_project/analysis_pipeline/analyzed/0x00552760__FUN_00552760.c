// Function: FUN_00552760 @ 00552760
// Size (bytes): 88


undefined4 __fastcall FUN_00552760(int param_1)

{
  int iVar1;
  
  FUN_0053cb90(*(undefined4 *)(param_1 + 100));
  *(undefined4 *)(param_1 + 100) = 0;
  if ((*(uint *)(param_1 + 0x24) & 0x20000) != 0) {
    FUN_00540eb0(*(undefined4 *)(param_1 + 0xc));
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0xc));
    }
    iVar1 = *(int *)(param_1 + 0x868);
    if (iVar1 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar1);
    }
  }
  return 0;
}


