// Function: FUN_005662d0 @ 005662d0
// Size (bytes): 166


int __fastcall FUN_005662d0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  piVar2 = *(int **)(*param_1 + 8);
  if ((piVar2 != (int *)0x0) && (iVar3 = *piVar2, iVar3 != 0)) {
    puVar6 = *(undefined1 **)(iVar3 + 0x144);
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    FUN_0058815f(*param_1 + 0x10,&DAT_005be860,puVar6,iVar3 + 0x30);
    if (*(char *)(*param_1 + 0x218) == '\0') {
      return *param_1 + 0x10;
    }
    iVar3 = FUN_00566810();
    if (iVar3 != 0) {
      pcVar4 = *(char **)(*param_1 + 0x210);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = &DAT_005ea438;
      }
      uVar5 = 0xffffffff;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      return (uint)(*(char *)((~uVar5 - 1) + iVar3) == '\\') + (~uVar5 - 1) + iVar3;
    }
  }
  return 0;
}


