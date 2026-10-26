// Function: FUN_0049db80 @ 0049db80
// Strings:  [BRAKES:, BRAKES:, WATER:, WATER:]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0049db80(int param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char local_40 [64];
  
  uVar4 = DAT_007ce238;
  uVar3 = DAT_005ccbc0;
  iVar6 = DAT_005ccbb8;
  if (*(int *)(param_1 + 8) != 0) {
    iVar5 = FUN_00423a00(s_WATER__005ccee8,&DAT_005ec4cc);
    if (iVar5 != 0) {
      iVar5 = 0;
      do {
        pcVar1 = s_WATER__005ccee8 + iVar5;
        (&DAT_005ec4cc)[iVar5] = *pcVar1;
        iVar5 = iVar5 + 1;
      } while (*pcVar1 != '\0');
    }
    iVar5 = 0;
    do {
      cVar2 = (&DAT_005ec4cc)[iVar5];
      local_40[iVar5] = cVar2;
      iVar5 = iVar5 + 1;
    } while (cVar2 != '\0');
    FUN_0049f6a0(local_40,uVar3,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
    FUN_0049db00((float)_DAT_007c91b4 - _DAT_005acafc,local_40);
    FUN_0049f6a0(local_40,uVar4,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
    iVar6 = iVar6 + DAT_005ccbbc;
    iVar5 = FUN_00423a00(&DAT_005ccee0,&DAT_005ec4cc);
    if (iVar5 != 0) {
      iVar5 = 0;
      do {
        pcVar1 = &DAT_005ccee0 + iVar5;
        (&DAT_005ec4cc)[iVar5] = *pcVar1;
        iVar5 = iVar5 + 1;
      } while (*pcVar1 != '\0');
    }
    iVar5 = 0;
    do {
      cVar2 = (&DAT_005ec4cc)[iVar5];
      local_40[iVar5] = cVar2;
      iVar5 = iVar5 + 1;
    } while (cVar2 != '\0');
    FUN_0049f6a0(local_40,uVar3,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
    FUN_0049db00((float)_DAT_007c9174 - _DAT_005acafc,local_40);
    FUN_0049f6a0(local_40,uVar4,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
    iVar6 = iVar6 + DAT_005ccbbc;
    iVar5 = FUN_00423a00(s_BRAKES__005cced8,&DAT_005ec4cc);
    if (iVar5 != 0) {
      iVar5 = 0;
      do {
        pcVar1 = s_BRAKES__005cced8 + iVar5;
        (&DAT_005ec4cc)[iVar5] = *pcVar1;
        iVar5 = iVar5 + 1;
      } while (*pcVar1 != '\0');
    }
    iVar5 = 0;
    do {
      cVar2 = (&DAT_005ec4cc)[iVar5];
      local_40[iVar5] = cVar2;
      iVar5 = iVar5 + 1;
    } while (cVar2 != '\0');
    FUN_0049f6a0(local_40,uVar3,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
    iVar6 = iVar6 + DAT_005ccbbc;
    FUN_0049db00((float)((float10)DAT_007c7ab8 - (float10)_DAT_0059eac8),local_40);
    FUN_0049f6a0(local_40,uVar3,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
    FUN_0049db00((float)((float10)DAT_007c7f1c - (float10)_DAT_0059eac8),local_40);
    FUN_0049f6a0(local_40,uVar4,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
    iVar6 = iVar6 + DAT_005ccbbc;
    FUN_0049db00((float)((float10)_DAT_007c8380 - (float10)_DAT_0059eac8),local_40);
    FUN_0049f6a0(local_40,uVar3,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
    FUN_0049db00((float)((float10)_DAT_007c87e4 - (float10)_DAT_0059eac8),local_40);
    FUN_0049f6a0(local_40,uVar4,iVar6,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
  }
  return;
}


