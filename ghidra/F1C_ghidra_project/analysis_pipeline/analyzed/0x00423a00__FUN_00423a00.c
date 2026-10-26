// Function: FUN_00423a00 @ 00423a00
// Size (bytes): 197


undefined4 __thiscall FUN_00423a00(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    iVar8 = *(int *)(param_1 + 4);
    do {
      iVar9 = iVar7 + iVar8 >> 1;
      pbVar3 = *(byte **)(iVar9 * 0x10 + *(int *)(param_1 + 8));
      pbVar4 = param_2;
      if (pbVar3 == (byte *)0x0) {
        pbVar3 = &DAT_005ea438;
      }
      do {
        bVar1 = *pbVar4;
        bVar10 = bVar1 < *pbVar3;
        if (bVar1 != *pbVar3) {
LAB_00423a5a:
          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_00423a5f;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar10 = bVar1 < pbVar3[1];
        if (bVar1 != pbVar3[1]) goto LAB_00423a5a;
        pbVar3 = pbVar3 + 2;
        pbVar4 = pbVar4 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_00423a5f:
      if (iVar5 == 0) {
        pcVar6 = *(char **)(iVar9 * 0x10 + 8 + *(int *)(param_1 + 8));
        if (pcVar6 == (char *)0x0) {
          pcVar6 = &DAT_005ea438;
        }
        param_3 = param_3 - (int)pcVar6;
        do {
          cVar2 = *pcVar6;
          pcVar6[param_3] = cVar2;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        return 0;
      }
      if (-1 < iVar5) {
        iVar7 = iVar9 + 1;
        iVar9 = iVar8;
      }
      iVar8 = iVar9;
    } while (iVar7 < iVar9);
  }
  param_3 = param_3 - (int)param_2;
  do {
    bVar1 = *param_2;
    param_2[param_3] = bVar1;
    param_2 = param_2 + 1;
  } while (bVar1 != 0);
  return 0xffffffff;
}


