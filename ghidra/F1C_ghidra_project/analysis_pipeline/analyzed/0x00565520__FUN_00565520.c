// Function: FUN_00565520 @ 00565520
// Size (bytes): 200


undefined4 __thiscall FUN_00565520(char *param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = 0;
  pcVar2 = param_1 + 0x198;
  if (param_1[0x198] != '\0') {
    do {
      pcVar4 = pcVar2 + 1;
      pcVar2 = pcVar2 + 1;
      if (*pcVar4 == '=') {
        iVar3 = iVar3 + 1;
      }
    } while (*pcVar4 != '\0');
    if (iVar3 == 1) {
      iVar3 = thunk_FUN_00565400(param_2);
      goto LAB_00565563;
    }
  }
  iVar3 = FUN_00565400(param_2);
LAB_00565563:
  if (iVar3 == 0) {
    return 0;
  }
  pcVar2 = *(char **)(param_1 + 0x180);
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)FUN_005897ca(param_1,&DAT_005d251c);
  if ((pcVar2 != (char *)0x0) && (param_3 != 0)) {
    iVar3 = param_3 - (int)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[iVar3] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(param_3);
    pcVar2 = (char *)FUN_005897ca(0,&DAT_005d251c);
    if ((pcVar2 != (char *)0x0) && (param_4 != 0)) {
      iVar3 = param_4 - (int)pcVar2;
      do {
        cVar1 = *pcVar2;
        pcVar2[iVar3] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      FUN_00589901(param_4);
    }
  }
  return 1;
}


