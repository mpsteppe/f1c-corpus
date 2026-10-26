// Function: FUN_00498e50 @ 00498e50
// Size (bytes): 91


int __thiscall FUN_00498e50(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  *(int *)(param_2 + 0x50) = param_1;
  FUN_0049a9c0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  iVar3 = FUN_00498e30();
  if (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x48);
    while (iVar1 = iVar2, iVar1 != 0) {
      iVar3 = iVar1;
      iVar2 = *(int *)(iVar1 + 0x48);
    }
    *(int *)(iVar3 + 0x48) = param_2;
    return param_2;
  }
  *(int *)(param_1 + 0x48) = param_2;
  *(int *)(param_1 + 0x50) = param_2;
  return param_2;
}


