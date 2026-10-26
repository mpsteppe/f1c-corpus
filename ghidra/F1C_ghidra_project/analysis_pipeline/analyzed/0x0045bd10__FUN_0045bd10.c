// Function: FUN_0045bd10 @ 0045bd10
// Size (bytes): 200


void FUN_0045bd10(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char local_50 [41];
  char acStack_27 [39];
  
  if (DAT_007d02e4 < param_2) {
    return;
  }
  if (param_3 == 0x1020304) {
    param_3 = FUN_0045bb60(param_2);
  }
  iVar4 = 0;
  do {
    uVar3 = 0xffffffff;
    pcVar5 = (char *)(iVar4 + param_1);
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if ((int)(~uVar3 - 1) < 0x50) {
      FUN_0045b9c0(iVar4 + param_1,param_3,DAT_0059f07c,param_2);
      return;
    }
    _strncpy(local_50,(char *)(iVar4 + param_1),0x4f);
    acStack_27[0x26] = 0;
    iVar2 = 0x4e;
    do {
      if (local_50[iVar2] == ' ') break;
      iVar2 = iVar2 + -1;
    } while (0x28 < iVar2);
    if (iVar2 == 0x28) {
      iVar2 = 0x4f;
    }
    else {
      iVar2 = iVar2 + 1;
    }
    local_50[iVar2] = '\0';
    iVar4 = iVar4 + iVar2;
    FUN_0045b9c0(local_50,param_3,DAT_0059f07c,param_2);
  } while( true );
}


