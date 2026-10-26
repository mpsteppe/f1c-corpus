// Function: FUN_0054bda0 @ 0054bda0
// Size (bytes): 19


void __thiscall FUN_0054bda0(char *param_1,int param_2)

{
  char cVar1;
  
  param_2 = param_2 - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[param_2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}


