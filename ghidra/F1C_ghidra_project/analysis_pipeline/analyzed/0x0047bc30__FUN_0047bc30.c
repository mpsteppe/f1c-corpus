// Function: FUN_0047bc30 @ 0047bc30
// Size (bytes): 94


int __fastcall FUN_0047bc30(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  pcVar4 = (char *)**(undefined4 **)(param_1 + 0xe0);
  if (pcVar4 == (char *)0x0) {
    pcVar4 = &DAT_005ea438;
  }
  uVar3 = 0xffffffff;
  pcVar6 = pcVar4;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar7 = 0;
  iVar5 = 0;
  while( true ) {
    iVar2 = FUN_0047b730(iVar5);
    if (((iVar5 == iVar2) || (*(int *)(param_1 + 0xe4) < iVar2)) ||
       ((~uVar3 - 1 == iVar2 && (pcVar4[iVar2 + -1] != -1)))) break;
    iVar7 = iVar7 + 1;
    iVar5 = iVar2;
  }
  return iVar7;
}


