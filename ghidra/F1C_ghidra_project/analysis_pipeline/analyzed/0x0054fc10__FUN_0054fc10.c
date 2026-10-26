// Function: FUN_0054fc10 @ 0054fc10
// Size (bytes): 39


void __thiscall FUN_0054fc10(int param_1,char *param_2)

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
  return;
}


