// Function: FUN_0046f170 @ 0046f170
// Size (bytes): 196


/* WARNING: Removing unreachable block (ram,0x0046f216) */

void FUN_0046f170(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  FUN_00489cb0();
  iVar2 = FUN_00432920();
  iVar6 = 0;
  if (0 < iVar2) {
    do {
      uVar3 = FUN_00432930(iVar6);
      FUN_00566650(uVar3);
      uVar4 = 0xffffffff;
      pcVar5 = &DAT_005ea438;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = &DAT_005ea437 + ~uVar4;
      if (&DAT_005ea438 < pcVar5) {
        do {
          if (*pcVar5 == '.') {
            *pcVar5 = '\0';
            break;
          }
          pcVar5 = pcVar5 + -1;
        } while (&DAT_005ea438 < pcVar5);
      }
      FUN_00489600(&DAT_005ea438,0,0,0,0);
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar2);
  }
  return;
}


