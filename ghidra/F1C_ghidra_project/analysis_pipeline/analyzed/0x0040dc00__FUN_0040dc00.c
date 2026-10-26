// Function: FUN_0040dc00 @ 0040dc00
// Size (bytes): 195


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0040dc00(void)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  size_t _Count;
  char *pcVar8;
  
  pcVar7 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (char *)0x0) {
    pcVar7 = &DAT_005ea438;
  }
  uVar4 = 0xffffffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar5 = 0xffffffff;
  pcVar7 = &DAT_005beb4c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  pcVar7 = operator_new(~uVar4 + ~uVar5);
  if (pcVar7 == (char *)0x0) {
    return 0;
  }
  pcVar3 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (char *)0x0) {
    pcVar3 = &DAT_005ea438;
  }
  _Count = (~uVar4 + ~uVar5) - 1;
  _strncpy(pcVar7,pcVar3,_Count);
  uVar4 = 0xffffffff;
  pcVar7[_Count] = '\0';
  pcVar3 = pcVar7;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  for (pcVar3 = pcVar7 + (~uVar4 - 1); pcVar7 < pcVar3; pcVar3 = pcVar3 + -1) {
    if (*pcVar3 == '.') {
      *pcVar3 = '\0';
      break;
    }
  }
  iVar6 = -1;
  pcVar3 = pcVar7;
  do {
    pcVar8 = pcVar3;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  *(undefined2 *)(pcVar8 + -1) = _DAT_005beb48;
  iVar6 = -1;
  pcVar3 = pcVar7;
  do {
    pcVar8 = pcVar3;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar8 + -1) = _DAT_005beb4c;
  uVar2 = FUN_0040dbe0(pcVar7);
  FUN_00587bcf(pcVar7);
  return uVar2;
}


