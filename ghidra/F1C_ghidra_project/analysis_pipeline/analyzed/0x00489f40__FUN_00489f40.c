// Function: FUN_00489f40 @ 00489f40
// Size (bytes): 136


int __thiscall FUN_00489f40(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  if (0 < *(int *)(param_1 + 0x158)) {
    if ((*(int *)(param_1 + 4) < param_2) && (param_2 < *(int *)(param_1 + 8))) {
      iVar1 = *(int *)(param_1 + 0x14c);
      iVar2 = __ftol();
      if (iVar2 < iVar1) {
        iVar2 = iVar1;
      }
      if (param_3 != '\0') {
        iVar1 = *(int *)(param_1 + 0x164) + -1 + iVar1;
        if (iVar1 < iVar2) {
          iVar2 = iVar1;
        }
        if (*(int *)(param_1 + 0x94) <= iVar2) {
          iVar2 = *(int *)(param_1 + 0x94) + -1;
        }
      }
    }
  }
  return iVar2;
}


