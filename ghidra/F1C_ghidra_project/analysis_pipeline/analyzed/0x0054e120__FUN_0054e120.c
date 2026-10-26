// Function: FUN_0054e120 @ 0054e120
// Size (bytes): 109


int __thiscall FUN_0054e120(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    iVar1 = 0;
    while ((param_2 < iVar2 || (*(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar1) + iVar2 <= param_2))
          ) {
      iVar2 = iVar2 + *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar1);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x40;
      if (*(int *)(param_1 + 0x118) <= iVar3) {
        return 0;
      }
    }
    iVar1 = (param_2 - iVar2) * 0x30 + *(int *)(*(int *)(param_1 + 0x11c) + 0xc + iVar3 * 0x40);
  }
  return iVar1;
}


