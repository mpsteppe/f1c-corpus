// Function: FUN_0042bdd0 @ 0042bdd0
// Strings:  [%d:%02.2d:%06.3f, +%d:%06.3f, +%d %s, +%d %s, %d:%06.3f]


undefined4 FUN_0042bdd0(int param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  float10 fVar8;
  
  if ((param_1 < 0) || (DAT_005c329c <= param_1)) {
    return 0;
  }
  iVar6 = (&DAT_007c54f0)[param_1];
  if (DAT_007c56a4 == 7) {
    *param_2 = '\0';
    if ((0 < *(int *)(iVar6 + 0x403c)) && (*(int *)(iVar6 + 0x4064) == 1)) {
      if (*(int *)(iVar6 + 0x4060) == 1) {
        uVar2 = __ftol();
        fVar8 = (float10)FUN_0058957a();
        uVar5 = __ftol((double)fVar8);
        FUN_0058815f(param_2,s__d__02_2d__06_3f_005c32dc,uVar2,uVar5);
      }
      else {
        iVar3 = 0;
        if (0 < DAT_005c329c) {
          do {
            if (*(int *)((&DAT_007c54f0)[iVar3] + 0x4060) == 1) {
              if ((&DAT_007c54f0)[iVar3] != 0) {
                iVar3 = *(int *)((&DAT_007c54f0)[iVar3] + 0x403c) - *(int *)(iVar6 + 0x403c);
                if (iVar3 == 1) {
                  iVar3 = FUN_00423a00(&DAT_005c330c,&DAT_005ec4cc);
                  if (iVar3 != 0) {
                    iVar3 = 0;
                    do {
                      pcVar7 = &DAT_005c330c + iVar3;
                      (&DAT_005ec4cc)[iVar3] = *pcVar7;
                      iVar3 = iVar3 + 1;
                    } while (*pcVar7 != '\0');
                  }
                  FUN_0058815f(param_2,s___d__s_005c3304,1,&DAT_005ec4cc);
                }
                else if (iVar3 < 1) {
                  fVar8 = (float10)FUN_0058957a();
                  uVar2 = __ftol((double)fVar8);
                  FUN_0058815f(param_2,s___d__06_3f_005c32f0,uVar2);
                }
                else {
                  iVar4 = FUN_00423a00(&DAT_005c32fc,&DAT_005ec4cc);
                  if (iVar4 != 0) {
                    iVar4 = 0;
                    do {
                      pcVar7 = &DAT_005c32fc + iVar4;
                      (&DAT_005ec4cc)[iVar4] = *pcVar7;
                      iVar4 = iVar4 + 1;
                    } while (*pcVar7 != '\0');
                  }
                  FUN_0058815f(param_2,s___d__s_005c3304,iVar3,&DAT_005ec4cc);
                }
              }
              break;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < DAT_005c329c);
        }
      }
    }
    iVar3 = -1;
    pcVar7 = param_2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (iVar3 == -2) {
      FUN_0058815f(param_2,&DAT_005c2c18,"--:--.---");
    }
  }
  else if (*(float *)(iVar6 + 0x409c) < DAT_0059e440) {
    FUN_0058815f(param_2,"--:--.---");
  }
  else {
    fVar8 = (float10)FUN_0058957a();
    uVar2 = __ftol((double)fVar8);
    FUN_0058815f(param_2,s__d__06_3f_005c3310,uVar2);
  }
  pcVar7 = PTR_DAT_005c3298;
  iVar6 = *(int *)(iVar6 + 0x4064);
  if ((iVar6 != 3) && ((DAT_007c56a4 != 7 || (iVar6 != 2)))) {
    return 0;
  }
  if (iVar6 != 3) {
    pcVar7 = (char *)FUN_004bb730();
    iVar6 = FUN_00423a00(pcVar7,&DAT_005ec4cc);
    if (iVar6 != 0) {
      if (pcVar7 == (char *)0x0) {
        DAT_005ec4cc = 0;
      }
      else {
        iVar6 = (int)&DAT_005ec4cc - (int)pcVar7;
        do {
          cVar1 = *pcVar7;
          pcVar7[iVar6] = cVar1;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
      }
    }
    pcVar7 = &DAT_005ec4cc;
    do {
      cVar1 = *pcVar7;
      (param_2 + -0x5ec4cc)[(int)pcVar7] = cVar1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    return 3;
  }
  iVar6 = FUN_00423a00(PTR_DAT_005c3298,&DAT_005ec4cc);
  if (iVar6 != 0) {
    if (pcVar7 == (undefined *)0x0) {
      DAT_005ec4cc = 0;
    }
    else {
      iVar6 = (int)&DAT_005ec4cc - (int)pcVar7;
      do {
        cVar1 = *pcVar7;
        pcVar7[iVar6] = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
  }
  pcVar7 = &DAT_005ec4cc;
  do {
    cVar1 = *pcVar7;
    (param_2 + -0x5ec4cc)[(int)pcVar7] = cVar1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  return 3;
}


