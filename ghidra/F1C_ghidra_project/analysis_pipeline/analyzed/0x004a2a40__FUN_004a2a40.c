// Function: FUN_004a2a40 @ 004a2a40
// Size (bytes): 80


void FUN_004a2a40(char *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  iVar4 = 0;
  iVar3 = 0;
  pcVar5 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar2 - 1)) {
    do {
      if (param_1[iVar3] != '\"') {
        *(char *)(iVar4 + param_2) = param_1[iVar3];
        iVar4 = iVar4 + 1;
      }
      uVar2 = 0xffffffff;
      iVar3 = iVar3 + 1;
      pcVar5 = param_1;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
    } while (iVar3 < (int)(~uVar2 - 1));
  }
  *(undefined1 *)(iVar4 + param_2) = 0;
  FUN_00589901(param_2);
  return;
}


