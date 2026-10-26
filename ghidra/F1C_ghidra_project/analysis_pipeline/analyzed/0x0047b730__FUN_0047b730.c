// Function: FUN_0047b730 @ 0047b730
// Size (bytes): 281


int __thiscall FUN_0047b730(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int local_10;
  int local_8;
  undefined1 local_4 [4];
  
  pcVar7 = (char *)**(undefined4 **)(param_1 + 0xe0);
  if (pcVar7 == (char *)0x0) {
    pcVar7 = &DAT_005ea438;
  }
  uVar4 = 0xffffffff;
  pcVar8 = pcVar7;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  local_10 = param_2;
  iVar9 = 0x20;
  iVar5 = param_2;
  do {
    iVar6 = iVar9 + iVar5;
    if ((int)(~uVar4 - 1) < iVar6) {
      iVar9 = iVar9 / 2;
      iVar6 = iVar5;
      iVar5 = local_10;
    }
    else {
      cVar1 = pcVar7[iVar6];
      pcVar7[iVar6] = '\0';
      if (*(int *)(param_1 + 200) != 0) {
        puVar3 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x40);
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_005ea438;
        }
        FUN_00498560(puVar3);
      }
      FUN_004983b0(pcVar7 + param_2,&local_8,local_4,1);
      pcVar7[iVar6] = cVar1;
      iVar5 = iVar6;
      if (*(int *)(param_1 + 0x100) < local_8) {
        iVar9 = iVar9 / 2;
        iVar6 = local_10;
        iVar5 = local_10;
      }
    }
    local_10 = iVar5;
    iVar5 = iVar6;
  } while (0 < iVar9);
  iVar9 = iVar6;
  if (pcVar7[iVar6] != '\0') {
    do {
      iVar2 = iVar5;
      iVar5 = iVar2 + -1;
      iVar9 = iVar6;
      if ((iVar5 < param_2) || (iVar9 = iVar2, pcVar7[iVar5] == ' ')) break;
      iVar6 = local_10;
    } while (pcVar7[iVar5] != -1);
  }
  do {
    if (iVar9 <= param_2) {
      return iVar9;
    }
    pcVar8 = pcVar7 + param_2;
    param_2 = param_2 + 1;
  } while (*pcVar8 != -1);
  return param_2;
}


