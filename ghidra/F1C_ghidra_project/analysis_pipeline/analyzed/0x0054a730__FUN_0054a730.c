// Function: FUN_0054a730 @ 0054a730
// Size (bytes): 55


int __thiscall FUN_0054a730(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = param_1 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar2] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(param_1);
  iVar2 = FUN_0054a870(param_3);
  return -(uint)(iVar2 != 0);
}


