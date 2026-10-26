// Function: FUN_00559e20 @ 00559e20
// Size (bytes): 210


undefined4 __thiscall FUN_00559e20(int param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  
  iVar2 = param_1 + 0xc;
  iVar4 = 0;
  if (*(char *)(param_1 + 0xc) != '\0') {
    do {
      pcVar3 = (char *)(iVar2 + 1);
      iVar2 = iVar2 + 1;
      if (*pcVar3 == '=') {
        iVar4 = iVar4 + 1;
      }
    } while (*pcVar3 != '\0');
    if (iVar4 == 1) {
      iVar2 = FUN_00559d10(param_2);
      goto LAB_00559e5d;
    }
  }
  iVar2 = FUN_00559d80(param_2);
LAB_00559e5d:
  if (iVar2 == 0) {
    return 0;
  }
  pcVar3 = *(char **)(param_1 + 0x30c);
  pcVar5 = (char *)(param_1 + 0x18c);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar3 = (char *)FUN_005897ca((char *)(param_1 + 0x18c),&DAT_005d251c);
  if ((pcVar3 != (char *)0x0) && (param_3 != 0)) {
    iVar2 = param_3 - (int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[iVar2] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(param_3);
    pcVar3 = (char *)FUN_005897ca(0,&DAT_005d251c);
    if ((pcVar3 != (char *)0x0) && (param_4 != 0)) {
      iVar2 = param_4 - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00589901(param_4);
    }
  }
  return 1;
}


