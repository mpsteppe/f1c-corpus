// Function: FUN_00540cb0 @ 00540cb0
// Size (bytes): 132


undefined4 __thiscall FUN_00540cb0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  if (*(int *)(param_1 + 0x13dc) != 0) {
    if (iVar1 != 0) {
      FUN_00587bcf(iVar1);
    }
    *(undefined4 *)(param_2 + 0x1c) = 0;
    *(undefined4 *)(param_2 + 0x2c) = 0;
    if (*(int *)(param_2 + 0x24) != 0) {
      FUN_00587bcf(*(int *)(param_2 + 0x24));
    }
    *(undefined4 *)(param_2 + 0x24) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    return 0;
  }
  FUN_00540eb0(iVar1);
  if (*(int *)(param_2 + 0x1c) != 0) {
    FUN_00587bcf(*(int *)(param_2 + 0x1c));
  }
  FUN_00541040(*(undefined4 *)(param_2 + 0x24));
  if (*(int *)(param_2 + 0x24) != 0) {
    FUN_00587bcf(*(int *)(param_2 + 0x24));
  }
  return 0;
}


