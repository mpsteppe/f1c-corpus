// Function: FUN_004a5820 @ 004a5820
// Size (bytes): 129


int __thiscall FUN_004a5820(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < param_2) {
    iVar2 = 0;
    if (-1 < *(int *)(param_1 + 0x15c)) {
      iVar2 = FUN_004d7570(*(int *)(param_1 + 0x15c));
    }
    iVar3 = 0;
    if (0 < *(int *)(*(int *)(param_1 + 0x158) + 0x10)) {
      do {
        iVar1 = FUN_004d7570(iVar3);
        if (*(char *)(iVar1 + 0x14) == '\0') {
          if ((iVar2 == 0) || (iVar2 == iVar1)) goto LAB_004a5887;
        }
        else if ((DAT_007c56a4 < 1) || ((5 < DAT_007c56a4 || (DAT_008afed4 != 0)))) {
LAB_004a5887:
          param_2 = param_2 + -1;
          if (param_2 == 0) {
            return iVar1;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(*(int *)(param_1 + 0x158) + 0x10));
    }
  }
  return 0;
}


