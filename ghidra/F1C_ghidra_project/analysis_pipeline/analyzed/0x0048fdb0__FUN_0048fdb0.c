// Function: FUN_0048fdb0 @ 0048fdb0
// Size (bytes): 60


void __thiscall FUN_0048fdb0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    *(int *)(param_1 + 0x30) = param_2;
    iVar1 = *(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc);
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + 1;
    }
    *(int *)(param_1 + 0xc) = iVar1;
    iVar1 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4);
    if (0 < iVar1) {
      *(int *)(param_1 + 0x10) = iVar1 + 1;
      return;
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}


