// Function: FUN_0054abe0 @ 0054abe0
// Size (bytes): 76


void __thiscall FUN_0054abe0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x204);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x204) = param_2;
    *(undefined4 *)(param_2 + 0x140) = 0;
    *(undefined4 *)(param_2 + 0x10) = 0;
    return;
  }
  for (iVar2 = *(int *)(iVar1 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
    iVar1 = iVar2;
  }
  *(int *)(iVar1 + 0x10) = param_2;
  *(int *)(param_2 + 0x140) = iVar1;
  *(undefined4 *)(param_2 + 0x10) = 0;
  return;
}


