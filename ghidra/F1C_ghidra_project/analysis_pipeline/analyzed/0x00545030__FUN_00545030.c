// Function: FUN_00545030 @ 00545030
// Size (bytes): 85


void __thiscall FUN_00545030(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xf8);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x1b8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1b8)) {
      iVar1 = iVar2;
    }
    *(int *)(iVar1 + 0x1b8) = param_2;
    *(int *)(param_2 + 0x1b4) = iVar1;
    *(undefined4 *)(param_2 + 0x1b8) = 0;
    return;
  }
  *(int *)(param_1 + 0xf8) = param_2;
  *(undefined4 *)(param_2 + 0x1b4) = 0;
  *(undefined4 *)(param_2 + 0x1b8) = 0;
  return;
}


