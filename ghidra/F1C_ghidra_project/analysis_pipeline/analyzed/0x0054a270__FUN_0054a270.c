// Function: FUN_0054a270 @ 0054a270
// Size (bytes): 85


void __thiscall FUN_0054a270(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x100);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x104); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x104)) {
      iVar1 = iVar2;
    }
    *(int *)(iVar1 + 0x104) = param_2;
    *(int *)(param_2 + 0x100) = iVar1;
    *(undefined4 *)(param_2 + 0x104) = 0;
    return;
  }
  *(int *)(param_1 + 0x100) = param_2;
  *(undefined4 *)(param_2 + 0x100) = 0;
  *(undefined4 *)(param_2 + 0x104) = 0;
  return;
}


