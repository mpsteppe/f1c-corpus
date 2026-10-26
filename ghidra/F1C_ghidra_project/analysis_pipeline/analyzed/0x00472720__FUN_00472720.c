// Function: FUN_00472720 @ 00472720
// Size (bytes): 95


void FUN_00472720(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar4 = ~uVar3 - 1;
    if (0x1b < iVar4) {
      iVar2 = ~uVar3 - 0x1d;
      do {
        if (iVar4 <= iVar2) break;
        pcVar5 = param_1 + iVar2;
        iVar2 = iVar2 + 1;
      } while (*pcVar5 != ' ');
      param_1 = param_1 + iVar2;
    }
    if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
      FUN_00486f30(param_1,0xffffffff);
      return;
    }
  }
  FUN_00486f30(param_2,0xffffffff);
  return;
}


