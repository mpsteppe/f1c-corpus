// Function: FUN_0049a110 @ 0049a110
// Size (bytes): 59


int __thiscall FUN_0049a110(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = 0;
  if (0 < param_2) {
    do {
      iVar3 = 0;
      if (iVar2 == 0) goto LAB_0049a133;
      iVar2 = *(int *)(iVar2 + 0x24);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 0x28);
  }
LAB_0049a133:
  iVar2 = 0;
  for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x28)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


