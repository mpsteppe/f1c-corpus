// Function: FUN_004983b0 @ 004983b0
// Size (bytes): 140


undefined4 __thiscall
FUN_004983b0(int param_1,char *param_2,undefined4 *param_3,undefined4 *param_4,char param_5)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  *param_3 = 0;
  *param_4 = 0;
  if (param_2 == (char *)0x0) {
    return 0xffffffff;
  }
  iVar2 = -1;
  pcVar3 = (char *)(param_1 + 0x1518);
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 != -2) {
    if (param_5 != '\0') {
      iVar2 = FUN_00423a00(param_2,&DAT_005ec4cc);
      if (iVar2 != 0) {
        iVar2 = (int)&DAT_005ec4cc - (int)param_2;
        do {
          cVar1 = *param_2;
          param_2[iVar2] = cVar1;
          param_2 = param_2 + 1;
        } while (cVar1 != '\0');
      }
      param_2 = &DAT_005ec4cc;
    }
    FUN_00494f00((char *)(param_1 + 0x1518),param_2,param_3,param_4);
  }
  return 0;
}


