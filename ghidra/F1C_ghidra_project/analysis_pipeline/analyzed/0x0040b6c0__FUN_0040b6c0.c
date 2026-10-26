// Function: FUN_0040b6c0 @ 0040b6c0
// Size (bytes): 48


int __thiscall FUN_0040b6c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar1 = *(int *)(param_1 + 0xc);
    iVar2 = 0;
    while (iVar1 != param_2) {
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xd0;
      if (*(int *)(param_1 + 0x10) <= iVar2) {
        return -1;
      }
    }
  }
  return iVar2;
}


