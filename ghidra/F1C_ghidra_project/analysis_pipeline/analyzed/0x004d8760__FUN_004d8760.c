// Function: FUN_004d8760 @ 004d8760
// Size (bytes): 212


undefined4 __thiscall FUN_004d8760(int *param_1,int param_2,char param_3)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = param_1[param_2 + 4];
  if (DAT_007cf638 == 0) {
    cVar4 = FUN_004d9280(param_2);
    bVar3 = false;
    if (cVar4 != '\0') goto LAB_004d878f;
  }
  else {
LAB_004d878f:
    bVar3 = true;
  }
  if (*param_1 != -1) {
    iVar5 = FUN_004d91e0(*param_1);
    iVar6 = FUN_004d91e0(param_2);
    if ((iVar6 <= iVar5) && (*param_1 != param_2)) {
      bVar2 = false;
      goto LAB_004d87bb;
    }
  }
  bVar2 = true;
LAB_004d87bb:
  cVar4 = FUN_00404f10();
  if ((((iVar1 != 0) && (bVar3)) && (bVar2)) && (cVar4 == '\0')) {
    if (param_3 == '\x01') {
      param_1[0x37] = 0;
      *param_1 = param_2;
      FUN_004d7e30();
      return 0;
    }
    param_1[0x37] = DAT_005acf34;
    *param_1 = param_2;
    FUN_004d7e30();
    return 0;
  }
  if (param_2 == -1) {
    *param_1 = -1;
  }
  return 1;
}


