// Function: FUN_0055bde0 @ 0055bde0
// Size (bytes): 56


int __thiscall FUN_0055bde0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < *(int *)(param_1 + 0x11c)) {
    iVar2 = *(int *)(param_1 + 0x120);
    iVar3 = 0;
    if (0 < param_2) {
      while (iVar1 = *(int *)(iVar2 + 0x20), iVar1 != 0) {
        iVar3 = iVar3 + 1;
        iVar2 = iVar1;
        if (param_2 <= iVar3) {
          return iVar1;
        }
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


