// Function: FUN_0053c590 @ 0053c590
// Size (bytes): 29


void FUN_0053c590(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  if (param_2 != (char *)0x0) {
    iVar2 = (int)&DAT_008b6ac8 - (int)param_2;
    do {
      cVar1 = *param_2;
      param_2[iVar2] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  return;
}


