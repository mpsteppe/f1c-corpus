// Function: FUN_00548e80 @ 00548e80
// Size (bytes): 47


void __thiscall FUN_00548e80(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (param_1 + 8) - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar2] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(param_1 + 8);
  *(undefined4 *)(param_1 + 4) = param_3;
  return;
}


