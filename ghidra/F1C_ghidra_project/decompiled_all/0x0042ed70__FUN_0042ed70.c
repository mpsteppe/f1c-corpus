// Function: FUN_0042ed70 @ 0042ed70
// Strings:  [%s/%s/%s, %s/%s/%s, %s/%s, %s/%s]


void __fastcall FUN_0042ed70(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_c0 [64];
  char local_80 [64];
  char local_40 [64];
  
  iVar2 = FUN_00423a00(&DAT_005c3774,&DAT_005ec4cc);
  if (iVar2 != 0) {
    iVar2 = 0;
    do {
      pcVar3 = &DAT_005c3774 + iVar2;
      (&DAT_005ec4cc)[iVar2] = *pcVar3;
      iVar2 = iVar2 + 1;
    } while (*pcVar3 != '\0');
  }
  pcVar3 = &DAT_005ec4cc;
  do {
    cVar1 = *pcVar3;
    pcVar3[param_1 + -0x5ec4a4] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (*(int *)(param_1 + 4) == 0) {
    iVar2 = FUN_00423a00(&DAT_005c3770,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar3 = &DAT_005c3770 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar3;
        iVar2 = iVar2 + 1;
      } while (*pcVar3 != '\0');
    }
    pcVar3 = &DAT_005ec4cc;
    do {
      cVar1 = *pcVar3;
      pcVar3[param_1 + -0x5ec4c4] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    iVar2 = FUN_00423a00(&DAT_005c376c,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar3 = &DAT_005c376c + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar3;
        iVar2 = iVar2 + 1;
      } while (*pcVar3 != '\0');
    }
    pcVar3 = &DAT_005ec4cc;
    do {
      cVar1 = *pcVar3;
      pcVar3[param_1 + -0x5ec4b4] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    iVar2 = FUN_00423a00(&DAT_005c36fc,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar3 = &DAT_005c36fc + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar3;
        iVar2 = iVar2 + 1;
      } while (*pcVar3 != '\0');
    }
    iVar2 = 0;
    do {
      cVar1 = (&DAT_005ec4cc)[iVar2];
      local_80[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
    iVar2 = FUN_00423a00(&DAT_005c3768,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar3 = &DAT_005c3768 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar3;
        iVar2 = iVar2 + 1;
      } while (*pcVar3 != '\0');
    }
    iVar2 = 0;
    do {
      cVar1 = (&DAT_005ec4cc)[iVar2];
      local_c0[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
    FUN_0058815f(param_1 + 0x38,s__s__s_005c3760,local_80,local_c0);
    iVar2 = FUN_00423a00(&DAT_005c375c,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar3 = &DAT_005c375c + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar3;
        iVar2 = iVar2 + 1;
      } while (*pcVar3 != '\0');
    }
    iVar2 = 0;
    do {
      cVar1 = (&DAT_005ec4cc)[iVar2];
      local_c0[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
    iVar2 = FUN_00423a00(&DAT_005c3758,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar3 = &DAT_005c3758 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar3;
        iVar2 = iVar2 + 1;
      } while (*pcVar3 != '\0');
    }
    iVar2 = 0;
    do {
      cVar1 = (&DAT_005ec4cc)[iVar2];
      local_40[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
    FUN_0058815f(param_1 + 0x48,s__s__s__s_005c374c,local_80,local_c0,local_40);
    iVar2 = FUN_00423a00(&DAT_005c3748,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar3 = &DAT_005c3748 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar3;
        iVar2 = iVar2 + 1;
      } while (*pcVar3 != '\0');
    }
    pcVar3 = &DAT_005ec4cc;
    do {
      cVar1 = *pcVar3;
      pcVar3[param_1 + -0x5ec474] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    return;
  }
  iVar2 = FUN_00423a00(&DAT_005c3744,&DAT_005ec4cc);
  if (iVar2 != 0) {
    iVar2 = 0;
    do {
      pcVar3 = &DAT_005c3744 + iVar2;
      (&DAT_005ec4cc)[iVar2] = *pcVar3;
      iVar2 = iVar2 + 1;
    } while (*pcVar3 != '\0');
  }
  pcVar3 = &DAT_005ec4cc;
  do {
    cVar1 = *pcVar3;
    pcVar3[param_1 + -0x5ec4c4] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar2 = FUN_00423a00(&DAT_005c3740,&DAT_005ec4cc);
  if (iVar2 != 0) {
    iVar2 = 0;
    do {
      pcVar3 = &DAT_005c3740 + iVar2;
      (&DAT_005ec4cc)[iVar2] = *pcVar3;
      iVar2 = iVar2 + 1;
    } while (*pcVar3 != '\0');
  }
  pcVar3 = &DAT_005ec4cc;
  do {
    cVar1 = *pcVar3;
    pcVar3[param_1 + -0x5ec4b4] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar2 = FUN_00423a00(&DAT_005c3700,&DAT_005ec4cc);
  if (iVar2 != 0) {
    iVar2 = 0;
    do {
      pcVar3 = &DAT_005c3700 + iVar2;
      (&DAT_005ec4cc)[iVar2] = *pcVar3;
      iVar2 = iVar2 + 1;
    } while (*pcVar3 != '\0');
  }
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005ec4cc)[iVar2];
    local_80[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  pcVar4 = (char *)FUN_0042f140(&DAT_005c3740);
  pcVar3 = local_c0;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_0058815f(param_1 + 0x38,s__s__s_005c3760,local_80,local_c0);
  pcVar4 = (char *)FUN_0042f140(&DAT_005c3758);
  pcVar3 = local_40;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_0058815f(param_1 + 0x48,s__s__s__s_005c374c,local_80,local_c0,local_40);
  pcVar4 = (char *)FUN_0042f140(&PTR_DAT_005c373c);
  pcVar3 = (char *)(param_1 + 0x58);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return;
}


