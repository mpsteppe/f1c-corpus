// Function: FUN_004c78f0 @ 004c78f0
// Strings:  [Nationality]


void __thiscall FUN_004c78f0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(param_2 * 0x424 + DAT_008ac394);
  FUN_004c6980(puVar5 + 0x2f);
  _strncpy((char *)(param_1 + 0x4660),&DAT_005ea438,0x17);
  *(undefined1 *)(param_1 + 0x4677) = 0;
  iVar2 = FUN_00568210(param_1 + 0x4620);
  if (iVar2 != 0) {
    iVar2 = FUN_005679c0(s_Nationality_005c73b8);
    if (iVar2 != 0) {
      pcVar3 = (char *)FUN_00567970();
      _strncpy((char *)(param_1 + 0x4660),pcVar3,0x17);
      *(undefined1 *)(param_1 + 0x4677) = 0;
    }
  }
  _strncpy((char *)(param_1 + 0x4678),(char *)(puVar5 + 0x3f),0x3f);
  *(undefined1 *)(param_1 + 0x46b7) = 0;
  _strncpy((char *)(param_1 + 0x46b8),(char *)(puVar5 + 0x1f),0x3f);
  *(undefined1 *)(param_1 + 0x46f7) = 0;
  FUN_004c69b0(puVar5 + 0x1d);
  pcVar3 = (char *)*puVar5;
  if (pcVar3 == (char *)0x0) {
    pcVar3 = &DAT_005ea438;
  }
  pcVar4 = (char *)(param_1 + 0x4714);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  *(int *)(param_1 + 0x4898) = param_2;
  return;
}


