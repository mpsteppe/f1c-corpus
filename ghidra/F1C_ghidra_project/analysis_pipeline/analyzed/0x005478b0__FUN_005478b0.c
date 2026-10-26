// Function: FUN_005478b0 @ 005478b0
// Size (bytes): 103


void __thiscall FUN_005478b0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x58) + 0x5c) = *(undefined4 *)(param_2 + 0x5c);
  }
  if (*(int *)(param_2 + 0x5c) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x5c) + 0x58) = *(undefined4 *)(param_2 + 0x58);
  }
  if (*(int *)(param_1 + 0x28) == param_2) {
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x5c);
  }
  iVar1 = *(int *)(param_2 + -4);
  if (-1 < iVar1 + -1) {
    do {
      FUN_00557470();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  FUN_00587bcf(param_2 + -4);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
  return;
}


