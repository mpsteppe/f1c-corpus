// Function: FUN_004dad80 @ 004dad80
// Size (bytes): 128


undefined1 __fastcall FUN_004dad80(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  bool bVar6;
  
  uVar4 = 0;
  cVar1 = FUN_004dae80();
  iVar3 = DAT_005c329c;
  if ((cVar1 != '\0') || (*(int *)(param_1 + 0x20) == DAT_005c329c)) {
    uVar4 = 1;
  }
  iVar5 = *(int *)(DAT_007c54e8 + 0x4060);
  iVar2 = FUN_004da990();
  if ((iVar2 == iVar5) && (iVar5 != iVar3)) {
    uVar4 = 1;
    if (*(char *)(param_1 + 0x28) == '\x01') {
      iVar5 = iVar5 + 1;
      bVar6 = iVar5 == iVar3;
      if (iVar5 < iVar3) {
        do {
          iVar3 = FUN_004d1b50(iVar5 + -1);
          if (*(int *)(&DAT_005f073c + iVar3 * 0x48c0) == 0) break;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_005c329c);
        bVar6 = iVar5 == DAT_005c329c;
      }
      if (bVar6) {
        uVar4 = 0;
      }
    }
    *(undefined1 *)(param_1 + 0x28) = 1;
  }
  return uVar4;
}


