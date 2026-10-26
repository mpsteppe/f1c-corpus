
uint __thiscall FUN_004b1b10(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_100 [256];
  
  auStack_100[0] = 0;
  FUN_004a1a60(auStack_100,param_1 + 0x14);
  puVar2 = *(undefined1 **)(param_1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566c30(param_2,s__s___s__005cd13c,puVar2,auStack_100);
  pcVar3 = *(char **)(param_1 + 0xc);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = &DAT_005ea438;
  }
  iVar5 = -1;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar5 != -2) {
    FUN_00566c30(param_2,s_____s_005d23a8,*(undefined4 *)(param_1 + 0xc),
                 *(undefined4 *)(param_1 + 0x10));
  }
  uVar4 = FUN_00566c30(param_2,&DAT_005c30b4);
  return uVar4 & 0xffffff00;
}

