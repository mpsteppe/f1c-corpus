// Function: FUN_004a09f0 @ 004a09f0
// Strings:  [%s%s%s]


void FUN_004a09f0(void)

{
  char *pcVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 local_100 [256];
  
  iVar4 = DAT_008ac48c * 0x18c + DAT_008ac490;
  if ((iVar4 != 0) && (DAT_007d032c == 1)) {
    pcVar1 = (char *)(iVar4 + 4);
    uVar5 = 0xffffffff;
    pcVar6 = pcVar1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    for (pcVar6 = pcVar1 + (~uVar5 - 1); pcVar1 < pcVar6; pcVar6 = pcVar6 + -1) {
      if (*pcVar6 == '\\') {
        pcVar6 = pcVar6 + 1;
        break;
      }
    }
    puVar3 = DAT_005ec418;
    if (DAT_005ec418 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0058815f(local_100,s__s_s_s_005c6784,puVar3,pcVar6,&DAT_005cd02c);
    FUN_004f9b70(local_100,1);
  }
  return;
}


