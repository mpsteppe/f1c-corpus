// Function: FUN_005453a0 @ 005453a0
// Size (bytes): 139


int __thiscall FUN_005453a0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  iVar1 = 0;
  local_4 = 0;
  if (param_3 != 0) {
    FUN_0054bc60(param_2,&local_4);
    return local_4;
  }
  iVar2 = *(int *)(param_1 + 0x100);
  if (iVar2 != 0) {
    do {
      if (iVar1 != 0) {
        return iVar1;
      }
      if (*(int *)(iVar2 + 0xec) != 0) {
        FUN_0054bc60(param_2,&local_4);
        iVar1 = local_4;
      }
      iVar2 = *(int *)(iVar2 + 0x104);
    } while (iVar2 != 0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = 0;
  if (*(int *)(param_1 + 0x108) != 0) {
    FUN_0054bc60(param_2,&local_4);
    iVar1 = local_4;
  }
  return iVar1;
}


