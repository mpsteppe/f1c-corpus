// Function: FUN_004d1ad0 @ 004d1ad0
// Size (bytes): 113


int __thiscall FUN_004d1ad0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = FUN_004d7bf0(param_2);
  iVar3 = FUN_004d7c00(param_2);
  if (iVar3 < iVar2) {
    return 0;
  }
  piVar6 = (int *)(*(int *)(param_1 + 0x110) + iVar2 * 8);
  iVar4 = 0;
  do {
    iVar1 = *piVar6;
    iVar5 = iVar4;
    if (iVar4 != 3) {
      if (iVar1 == 3) {
        return 3;
      }
      if ((((iVar4 != 8) && (iVar5 = iVar1, iVar1 != 8)) && (iVar5 = iVar4, iVar4 != 2)) &&
         (iVar1 == 2)) {
        iVar5 = iVar1;
      }
    }
    iVar2 = iVar2 + 1;
    piVar6 = piVar6 + 2;
    iVar4 = iVar5;
  } while (iVar2 <= iVar3);
  return iVar5;
}


