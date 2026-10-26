// Function: FUN_00433370 @ 00433370
// Size (bytes): 99


void __thiscall FUN_00433370(int param_1,char *param_2,int param_3,undefined1 *param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  FUN_00433290(param_1 + 8,param_2,param_3);
  if (DAT_007c56c0 == '\0') {
    if (param_4 != (undefined1 *)0x0) {
      *param_4 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((int)(~uVar2 - 1) < param_3 + -1) {
      iVar3 = -1;
      do {
        pcVar4 = param_2;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar4 = param_2 + 1;
        cVar1 = *param_2;
        param_2 = pcVar4;
      } while (cVar1 != '\0');
      *(undefined2 *)(pcVar4 + -1) = DAT_005c406c;
    }
    if (param_4 != (undefined1 *)0x0) {
      *param_4 = 1;
      return;
    }
  }
  return;
}


