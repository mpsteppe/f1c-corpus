// Function: FUN_004cefa0 @ 004cefa0
// Size (bytes): 53


void __thiscall FUN_004cefa0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar2 = *(int *)(param_1 + 0x14);
    while (*(int *)(iVar2 + 4) != param_2) {
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x6c;
      if (*(int *)(param_1 + 0x10) <= iVar1) {
        return;
      }
    }
    FUN_004cd6c0(param_3,param_4);
  }
  return;
}


