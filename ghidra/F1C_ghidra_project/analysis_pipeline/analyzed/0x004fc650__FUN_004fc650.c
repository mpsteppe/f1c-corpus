// Function: FUN_004fc650 @ 004fc650
// Size (bytes): 165


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fc650(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  
  iVar7 = DAT_008aae64;
  if (DAT_0083ee60 < 0x3ff) {
    DAT_0083ee60 = DAT_0083ee60 + 1;
    DAT_008aae64 = DAT_008aae64 + 0x1b0;
  }
  uVar3 = 0xffffffff;
  pcVar2 = (char *)(param_1 + 0x50);
  pcVar8 = pcVar2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar4 = 0xffffffff;
  pcVar6 = (char *)(param_1 + 0x84);
  pcVar8 = pcVar6;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_004b33b0(2,5,~uVar4 + ~uVar3,0xff,(float)_DAT_008afea0,1);
  iVar5 = (iVar7 + 8) - (int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[iVar5] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar7 = (~uVar3 + 8 + iVar7) - (int)pcVar6;
  do {
    cVar1 = *pcVar6;
    pcVar6[iVar7] = cVar1;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  return;
}


