// Function: FUN_0049c140 @ 0049c140
// Strings:  [SECTOR 3:, SECTOR 3:, SECTOR 3:, SECTOR 3:, SECTOR 2:, SECTOR 2:, SECTOR 1:, SECTOR 1:]


undefined4 FUN_0049c140(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar3 = PTR_s_SECTOR_3__005ccbf0;
  pcVar4 = PTR_s_SECTOR_2__005ccbec;
  pcVar5 = PTR_s_SECTOR_1__005ccbe8;
  iVar2 = *(int *)(DAT_007c54e0 + 0x4040) + 1;
  if (iVar2 == 3) {
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    iVar2 = FUN_00423a00(PTR_s_SECTOR_3__005ccbf0,&DAT_005ec4cc);
    if (iVar2 == 0) goto LAB_0049c25e;
    if (pcVar3 != (undefined *)0x0) {
      iVar2 = (int)&DAT_005ec4cc - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      goto LAB_0049c25e;
    }
  }
  else {
    if (iVar2 == 1) {
      iVar2 = FUN_00423a00(PTR_s_SECTOR_1__005ccbe8,&DAT_005ec4cc);
      if (iVar2 != 0) {
        if (pcVar5 == (undefined *)0x0) {
          DAT_005ec4cc = 0;
        }
        else {
          iVar2 = (int)&DAT_005ec4cc - (int)pcVar5;
          do {
            cVar1 = *pcVar5;
            pcVar5[iVar2] = cVar1;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
        }
      }
      goto LAB_0049c25e;
    }
    if (iVar2 == 2) {
      iVar2 = FUN_00423a00(PTR_s_SECTOR_2__005ccbec,&DAT_005ec4cc);
      if (iVar2 != 0) {
        if (pcVar4 == (undefined *)0x0) {
          DAT_005ec4cc = 0;
        }
        else {
          iVar2 = (int)&DAT_005ec4cc - (int)pcVar4;
          do {
            cVar1 = *pcVar4;
            pcVar4[iVar2] = cVar1;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
        }
      }
      goto LAB_0049c25e;
    }
    iVar2 = FUN_00423a00(PTR_s_SECTOR_3__005ccbf0,&DAT_005ec4cc);
    if (iVar2 == 0) goto LAB_0049c25e;
    if (pcVar3 != (undefined *)0x0) {
      iVar2 = (int)&DAT_005ec4cc - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      goto LAB_0049c25e;
    }
  }
  DAT_005ec4cc = 0;
LAB_0049c25e:
  _strncpy(param_1,&DAT_005ec4cc,param_2 - 1U);
  param_1[param_2 - 1U] = '\0';
  return 0;
}


