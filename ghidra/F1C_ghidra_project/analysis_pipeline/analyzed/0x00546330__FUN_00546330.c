// Function: FUN_00546330 @ 00546330
// Size (bytes): 49


void __thiscall FUN_00546330(int param_1,char *param_2,undefined4 param_3)

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
  *(undefined4 *)(param_1 + 0xb8) = param_3;
  return;
}


