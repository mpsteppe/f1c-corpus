// Function: FUN_0049cd80 @ 0049cd80
// Strings:  [NEEDLE_01.tga, ingame.mas]


void FUN_0049cd80(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 uVar12;
  int local_88;
  undefined4 local_84;
  char local_80;
  undefined4 uStack_7f;
  undefined1 local_1;
  
  if ((DAT_008afe88 != 0) && (iVar3 = FUN_00545f40(), iVar3 != 0)) {
    local_80 = DAT_005ea438;
    puVar10 = &uStack_7f;
    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = 0;
    *(undefined1 *)((int)puVar10 + 2) = 0;
    local_88 = 0;
    local_84 = 0;
    puVar4 = DAT_007ce64c;
    if (DAT_007ce64c == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    iVar3 = FUN_004c40b0(puVar4);
    if (iVar3 != 0) {
      pcVar5 = *(char **)(iVar3 + 0x20);
      if (pcVar5 == (char *)0x0) {
        pcVar5 = &DAT_005ea438;
      }
      _strncpy(&local_80,pcVar5,0x7f);
      uVar9 = 0xffffffff;
      local_1 = 0;
      pcVar5 = &local_80;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = (char *)((int)&local_84 + ~uVar9 + 3);
      if (&local_80 < pcVar5) {
        do {
          if (*pcVar5 == '.') {
            *pcVar5 = '\0';
            break;
          }
          pcVar5 = pcVar5 + -1;
        } while (&local_80 < pcVar5);
      }
      iVar3 = -1;
      pcVar5 = &local_80;
      do {
        pcVar11 = pcVar5;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar11 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar11;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar11 + -1) = DAT_005ccebc;
      pcVar11[3] = DAT_005ccec0;
    }
    puVar4 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0053c800(puVar4);
    iVar3 = FUN_00588410(&local_80,&DAT_005ea438);
    if (iVar3 != 0) {
      FUN_0053cbc0(&local_84,&local_80);
    }
    FUN_0053cbc0(&local_88,PTR_s_ingame_mas_005ccb54);
    puVar4 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0053c900(puVar4);
    if ((local_88 != 0) && (param_2 != (int *)0x0)) {
      iVar3 = FUN_00547920(param_3);
      *param_2 = iVar3;
      if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x54), iVar3 != 0)) {
        iVar2 = *(int *)(iVar3 + 0x1c);
        iVar3 = *(int *)(iVar3 + 0x20);
        FUN_0049e930(param_3);
        FUN_0049ea10(0,0,iVar2,iVar3,2);
        iVar6 = FUN_0049e9a0(PTR_s_NEEDLE_01_tga_005ccb84);
        if (iVar6 != 0) {
          uVar12 = 2;
          uVar7 = __ftol(2);
          uVar8 = __ftol(uVar7);
          FUN_0049eb40(iVar2 / 2,iVar3 / 2,uVar8,uVar7,uVar12);
        }
        *(undefined4 *)(param_1 + 0x14) = param_6;
        *(undefined4 *)(param_1 + 0x18) = param_7;
      }
    }
    FUN_0053ce40(local_88);
    if (local_84 != 0) {
      FUN_0053ce40(local_84);
    }
  }
  return;
}


