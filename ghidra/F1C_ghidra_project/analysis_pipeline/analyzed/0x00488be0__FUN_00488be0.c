// Function: FUN_00488be0 @ 00488be0
// Size (bytes): 858


undefined4 __thiscall FUN_00488be0(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  char local_80 [128];
  
  if (*(char *)(param_1 + 0xe8) == '\0') {
    pcVar8 = *(char **)(param_1 + 0xb0);
    if (pcVar8 == (char *)0x0) {
      pcVar8 = &DAT_005ea438;
    }
    pcVar6 = local_80;
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      *pcVar6 = cVar2;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
  }
  else {
    pcVar8 = *(char **)(param_1 + 0xb0);
    if (pcVar8 == (char *)0x0) {
      pcVar8 = &DAT_005ea438;
    }
    iVar3 = FUN_00423a00(pcVar8,&DAT_005ec4cc);
    if (iVar3 != 0) {
      if (pcVar8 == (char *)0x0) {
        DAT_005ec4cc = 0;
      }
      else {
        iVar3 = (int)&DAT_005ec4cc - (int)pcVar8;
        do {
          cVar2 = *pcVar8;
          pcVar8[iVar3] = cVar2;
          pcVar8 = pcVar8 + 1;
        } while (cVar2 != '\0');
      }
    }
    iVar3 = 0;
    do {
      cVar2 = (&DAT_005ec4cc)[iVar3];
      local_80[iVar3] = cVar2;
      iVar3 = iVar3 + 1;
    } while (cVar2 != '\0');
  }
  pcVar8 = *(char **)(param_1 + 0xb8);
  if (pcVar8 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  cVar2 = FUN_00589a35((int)*pcVar8);
  if (cVar2 == 'C') {
    *(undefined4 *)(param_1 + 0xe0) = 2;
  }
  else if (cVar2 == 'L') {
    *(undefined4 *)(param_1 + 0xe0) = 1;
  }
  else if (cVar2 == 'R') {
    *(undefined4 *)(param_1 + 0xe0) = 3;
  }
  local_90 = *(int *)(param_1 + 0xc);
  local_8c = *(int *)(param_1 + 8);
  iVar7 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 0x10);
  iVar5 = -1;
  pcVar8 = local_80;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  if (iVar5 != -2) {
    local_94 = 0;
    local_98 = 0;
    if (*(int *)(param_1 + 0xe4) < 1) {
      iVar5 = iVar3 - local_90;
      local_84 = local_8c - iVar7;
      local_88 = iVar5;
      if (*(char *)(param_1 + 0xe8) == '\0') {
        pcVar8 = local_80;
      }
      else {
        iVar4 = FUN_00423a00(local_80,&DAT_005ec4cc);
        if (iVar4 != 0) {
          iVar4 = 0;
          do {
            cVar2 = local_80[iVar4];
            (&DAT_005ec4cc)[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
          } while (cVar2 != '\0');
        }
        pcVar8 = &DAT_005ec4cc;
      }
      FUN_004983b0(pcVar8,&local_98,&local_94,1);
      if ((iVar5 < local_98) || (iVar5 = local_8c, local_84 < local_94)) {
        iVar5 = local_94 + iVar7;
        local_8c = iVar7;
        if (*(int *)(param_1 + 0xe0) == 2) {
          iVar4 = __ftol();
          local_90 = __ftol();
          local_90 = (iVar3 - iVar4) - local_90;
          iVar3 = local_90 + local_98;
        }
        else if (*(int *)(param_1 + 0xe0) == 3) {
          local_90 = iVar3 - local_98;
        }
        else {
          iVar3 = local_98 + local_90;
        }
        local_88 = local_94 / 2;
        if (local_88 < local_84 / 2) {
          local_8c = (local_84 / 2 - local_88) + iVar7;
        }
        iVar7 = local_8c;
        FUN_0049a9c0(local_8c,iVar5,local_90,iVar3);
      }
    }
    else {
      FUN_004983b0(local_80,&local_98,&local_94,1);
      iVar5 = local_8c;
      if (*(int *)(param_1 + 0xe4) < local_98) {
        pcVar8 = local_80;
        while (local_80[0] != '\0') {
          pcVar6 = pcVar8 + 1;
          pcVar8 = pcVar8 + 1;
          local_80[0] = *pcVar6;
        }
        pcVar8 = pcVar8 + -1;
        *pcVar8 = '\0';
        FUN_004983b0(local_80,&local_98,&local_94,1);
        iVar5 = local_8c;
        if (*(int *)(param_1 + 0xe4) < local_98) {
          do {
            iVar5 = local_8c;
            if (local_80 == pcVar8) break;
            pcVar8 = pcVar8 + -1;
            *pcVar8 = '\0';
            FUN_004983b0(local_80,&local_98,&local_94,1);
            iVar5 = local_8c;
          } while (*(int *)(param_1 + 0xe4) < local_98);
        }
      }
    }
    uVar1 = *(undefined1 *)(param_1 + 0xe8);
    if (*(int *)(param_1 + 0xe0) == 2) {
      FUN_004980d0(local_80,iVar7,iVar5,local_90,iVar3,uVar1);
    }
    else if (*(int *)(param_1 + 0xe0) == 3) {
      FUN_004982c0(local_80,iVar7,iVar5,local_90,iVar3,uVar1);
    }
    else {
      FUN_004981f0(local_80,iVar7,iVar5,local_90,iVar3,uVar1);
    }
    *param_2 = iVar7;
    *param_3 = iVar5;
    *param_4 = local_90;
    *param_5 = iVar3;
  }
  return 0;
}


