// Function: FUN_00421890 @ 00421890
// Size (bytes): 64


void FUN_00421890(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  if (param_1 != (char *)0x0) {
    iVar2 = -1;
    pcVar4 = param_1;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      uVar3 = 0xffffffff;
      pcVar4 = param_1;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      if (param_1[~uVar3 - 2] != '\\') {
        iVar2 = -1;
        do {
          pcVar4 = param_1;
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          pcVar4 = param_1 + 1;
          cVar1 = *param_1;
          param_1 = pcVar4;
        } while (cVar1 != '\0');
        *(undefined2 *)(pcVar4 + -1) = DAT_005c2aac;
      }
    }
  }
  return;
}


