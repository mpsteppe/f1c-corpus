// Function: FUN_00547af0 @ 00547af0
// Size (bytes): 65


undefined4 __fastcall FUN_00547af0(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  iVar2 = -1;
  uVar4 = 0;
  pcVar5 = param_1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (iVar2 != -2) {
    do {
      if (param_1[uVar4] == '.') {
        param_1[uVar4] = '\0';
        return 1;
      }
      uVar3 = 0xffffffff;
      uVar4 = uVar4 + 1;
      pcVar5 = param_1;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
    } while (uVar4 < ~uVar3 - 1);
  }
  return 0;
}


