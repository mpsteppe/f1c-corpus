// Function: FUN_00547370 @ 00547370
// Size (bytes): 29


void __thiscall FUN_00547370(char *param_1,int param_2)

{
  char cVar1;
  
  if (param_2 != 0) {
    param_2 = param_2 - (int)param_1;
    do {
      cVar1 = *param_1;
      param_1[param_2] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
  }
  return;
}


