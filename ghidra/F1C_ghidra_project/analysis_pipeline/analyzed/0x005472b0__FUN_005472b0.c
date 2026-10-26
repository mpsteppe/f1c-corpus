// Function: FUN_005472b0 @ 005472b0
// Size (bytes): 29


void __thiscall FUN_005472b0(int param_1,char *param_2)

{
  char cVar1;
  
  if (param_2 != (char *)0x0) {
    param_1 = param_1 - (int)param_2;
    do {
      cVar1 = *param_2;
      param_2[param_1] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  return;
}


