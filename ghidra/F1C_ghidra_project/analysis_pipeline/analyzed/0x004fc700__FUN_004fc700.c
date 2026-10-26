// Function: FUN_004fc700 @ 004fc700
// Size (bytes): 336


void __thiscall FUN_004fc700(int param_1,int param_2)

{
  byte *_Source;
  bool bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  
  bVar6 = DAT_007c56a0 & 1;
  if (DAT_008ab6e4 == 2) {
    cVar2 = FUN_004b9a00();
    bVar1 = true;
    if (cVar2 == '\0') goto LAB_004fc738;
  }
  bVar1 = false;
LAB_004fc738:
  if ((bVar6 == 0) || (bVar1)) {
    uVar5 = 0xffffffff;
    _Source = (byte *)(param_2 + 8);
    pbVar8 = _Source;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar6 != 0);
    pbVar8 = (byte *)(~uVar5 + 8 + param_2);
    uVar5 = *(byte *)(param_2 + 3) & 7;
    pbVar3 = (byte *)(param_1 + 0x50);
    pbVar7 = _Source;
    do {
      bVar6 = *pbVar3;
      bVar9 = bVar6 < *pbVar7;
      if (bVar6 != *pbVar7) {
LAB_004fc79a:
        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_004fc79f;
      }
      if (bVar6 == 0) break;
      bVar6 = pbVar3[1];
      bVar9 = bVar6 < pbVar7[1];
      if (bVar6 != pbVar7[1]) goto LAB_004fc79a;
      pbVar3 = pbVar3 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar6 != 0);
    iVar4 = 0;
LAB_004fc79f:
    if (iVar4 == 0) {
      pbVar3 = (byte *)(param_1 + 0x84);
      pbVar7 = pbVar8;
      do {
        bVar6 = *pbVar3;
        bVar9 = bVar6 < *pbVar7;
        if (bVar6 != *pbVar7) {
LAB_004fc7d5:
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_004fc7da;
        }
        if (bVar6 == 0) break;
        bVar6 = pbVar3[1];
        bVar9 = bVar6 < pbVar7[1];
        if (bVar6 != pbVar7[1]) goto LAB_004fc7d5;
        pbVar3 = pbVar3 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar6 != 0);
      iVar4 = 0;
LAB_004fc7da:
      if (iVar4 == 0) {
        if (*(int *)(param_1 + 0x44) == -1) {
          return;
        }
        *(uint *)(param_1 + 0x44) = uVar5;
        return;
      }
    }
    _strncpy((char *)(param_1 + 0x50),(char *)_Source,0x1f);
    *(undefined1 *)(param_1 + 0x6f) = 0;
    _strncpy((char *)(param_1 + 0x84),(char *)pbVar8,0x1f);
    *(undefined1 *)(param_1 + 0xa3) = 0;
    if ((!bVar1) && (uVar5 != DAT_007c56a4)) {
      *(uint *)(param_1 + 0x44) = uVar5;
      return;
    }
    FUN_004fc550(0);
  }
  return;
}


