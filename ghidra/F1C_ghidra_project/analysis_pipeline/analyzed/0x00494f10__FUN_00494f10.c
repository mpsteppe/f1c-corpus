// Function: FUN_00494f10 @ 00494f10
// Size (bytes): 146


void FUN_00494f10(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,char param_6)

{
  char cVar1;
  int iVar2;
  
  if (param_6 == '\0') {
    FUN_0053d2e0(param_1,param_2,param_3,param_4,param_5);
    return;
  }
  iVar2 = FUN_00423a00(param_2,&DAT_005ec4cc);
  if (iVar2 != 0) {
    if (param_2 == (char *)0x0) {
      DAT_005ec4cc = 0;
    }
    else {
      iVar2 = (int)&DAT_005ec4cc - (int)param_2;
      do {
        cVar1 = *param_2;
        param_2[iVar2] = cVar1;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
    }
  }
  FUN_0053d2e0(param_1,&DAT_005ec4cc,param_3,param_4,param_5);
  return;
}


