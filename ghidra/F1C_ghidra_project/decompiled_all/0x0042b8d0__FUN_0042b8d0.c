// Function: FUN_0042b8d0 @ 0042b8d0
// Strings:  [Upshifts, Downshifts, Disallowed, Disallowed]


void __fastcall FUN_0042b8d0(int param_1,int *param_2,int param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char local_80 [128];
  
  cVar1 = FUN_004b15d0(param_1);
  if (cVar1 == '\0') {
    iVar2 = FUN_00423a00(param_4,&DAT_005ec4cc);
    if (iVar2 != 0) {
      if (param_4 == (char *)0x0) {
        DAT_005ec4cc = 0;
      }
      else {
        iVar2 = (int)&DAT_005ec4cc - (int)param_4;
        do {
          cVar1 = *param_4;
          param_4[iVar2] = cVar1;
          param_4 = param_4 + 1;
        } while (cVar1 != '\0');
      }
    }
    iVar2 = 0;
    do {
      cVar1 = (&DAT_005ec4cc)[iVar2];
      local_80[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
    iVar2 = -1;
    pcVar5 = local_80;
    do {
      pcVar7 = pcVar5;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar7 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar7;
    } while (cVar1 != '\0');
    *(undefined2 *)(pcVar7 + -1) = DAT_005c32d8;
    iVar2 = FUN_00423a00(s_Disallowed_005c32cc,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar5 = s_Disallowed_005c32cc + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar5;
        iVar2 = iVar2 + 1;
      } while (*pcVar5 != '\0');
    }
    uVar3 = 0xffffffff;
    pcVar5 = &DAT_005ec4cc;
    do {
      pcVar7 = pcVar5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar5 = local_80;
    do {
      pcVar6 = pcVar5;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    pcVar5 = pcVar7 + -uVar3;
    pcVar7 = pcVar6 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    FUN_0045bd10(local_80,3,0x1020304);
    return;
  }
  iVar2 = *param_2;
  *param_2 = iVar2 + 1;
  if (param_3 < iVar2 + 1) {
    *param_2 = 0;
  }
  iVar2 = *param_2;
  if (param_1 == 3) {
    if (iVar2 != 0) {
      if (iVar2 == 1) {
        pcVar5 = s_Upshifts_005c32b0;
      }
      else if (iVar2 == 2) {
        pcVar5 = s_Downshifts_005c32bc;
      }
      else {
        pcVar5 = &DAT_005c32c8;
      }
      goto LAB_0042ba3a;
    }
  }
  else if (iVar2 != 0) {
    if (iVar2 == 1) {
      if (param_3 == 1) {
        pcVar5 = &DAT_005c32c8;
      }
      else {
        pcVar5 = (char *)&PTR_DAT_005c32a4;
      }
    }
    else {
      pcVar5 = &DAT_005c32a8;
    }
    goto LAB_0042ba3a;
  }
  pcVar5 = (char *)&PTR_DAT_005be704;
LAB_0042ba3a:
  iVar2 = FUN_00423a00(param_4,&DAT_005ec4cc);
  if (iVar2 != 0) {
    if (param_4 == (char *)0x0) {
      DAT_005ec4cc = 0;
    }
    else {
      iVar2 = (int)&DAT_005ec4cc - (int)param_4;
      do {
        cVar1 = *param_4;
        param_4[iVar2] = cVar1;
        param_4 = param_4 + 1;
      } while (cVar1 != '\0');
    }
  }
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005ec4cc)[iVar2];
    local_80[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  iVar2 = -1;
  pcVar7 = local_80;
  do {
    pcVar6 = pcVar7;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar6;
  } while (cVar1 != '\0');
  *(undefined2 *)(pcVar6 + -1) = DAT_005c32d8;
  iVar2 = FUN_00423a00(pcVar5,&DAT_005ec4cc);
  if (iVar2 != 0) {
    if ((undefined **)pcVar5 == (undefined **)0x0) {
      DAT_005ec4cc = 0;
    }
    else {
      iVar2 = (int)&DAT_005ec4cc - (int)pcVar5;
      do {
        cVar1 = *pcVar5;
        *(char *)((int)pcVar5 + iVar2) = cVar1;
        pcVar5 = (char *)((int)pcVar5 + 1);
      } while (cVar1 != '\0');
    }
  }
  uVar3 = 0xffffffff;
  pcVar5 = &DAT_005ec4cc;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar2 = -1;
  pcVar5 = local_80;
  do {
    pcVar6 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar3;
  pcVar7 = pcVar6 + -1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  FUN_0045bdf0();
  FUN_0045bd10(local_80,3,0x1020304);
  FUN_00438cc0();
  return;
}


