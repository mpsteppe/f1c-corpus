// Function: thunk_FUN_00567b10 @ 00567b00
// Size (bytes): 5


uint thunk_FUN_00567b10(char *param_1,char *param_2)

{
  char cVar1;
  uint in_EAX;
  undefined1 *puVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  *param_2 = '\0';
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      uVar6 = FUN_005678f0();
      param_1 = (char *)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 == 0) break;
      pcVar4 = param_1 + 1;
      param_1 = param_1 + 1;
      cVar1 = *pcVar4;
    }
    iVar5 = (int)param_2 - (int)param_1;
    do {
      cVar1 = *param_1;
      param_1[iVar5] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    puVar2 = (undefined1 *)FUN_00587c20(param_2,&DAT_005c30b8);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 0;
    }
    uVar3 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = param_2 + (~uVar3 - 2);
    while (param_2 <= pcVar4) {
      uVar6 = FUN_005678f0();
      puVar2 = (undefined1 *)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 == 0) break;
      *puVar2 = 0;
      pcVar4 = puVar2 + -1;
    }
    iVar5 = -1;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *param_2;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    in_EAX = 0;
    if (iVar5 != -2) {
      return 1;
    }
  }
  return in_EAX & 0xffffff00;
}


