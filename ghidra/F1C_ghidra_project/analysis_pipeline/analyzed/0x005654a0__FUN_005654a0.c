// Function: FUN_005654a0 @ 005654a0
// Size (bytes): 120


undefined4 __thiscall FUN_005654a0(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)(param_1 + 0x198);
  iVar3 = param_1 - (int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[iVar3] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = FUN_005897ca(param_1,&DAT_005c30ac);
  *(int *)(param_1 + 0x180) = iVar3;
  if ((iVar3 != 0) && (iVar3 = FUN_00588410(iVar3,param_2), iVar3 == 0)) {
    pcVar2 = (char *)FUN_005897ca(0,&DAT_005c64d4);
    *(char **)(param_1 + 0x180) = pcVar2;
    if (pcVar2 != (char *)0x0) {
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        *param_3 = cVar1;
        param_3 = param_3 + 1;
      } while (cVar1 != '\0');
      return 1;
    }
  }
  return 0;
}


