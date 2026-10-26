// Function: FUN_00431db0 @ 00431db0
// Size (bytes): 750


undefined1 __thiscall FUN_00431db0(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  HANDLE hFindFile;
  int iVar7;
  undefined4 *puVar8;
  void *pvVar9;
  BOOL BVar10;
  uint uVar11;
  int *piVar12;
  CHAR *pCVar13;
  char *pcVar14;
  bool bVar15;
  undefined1 local_351;
  _WIN32_FIND_DATAA local_340;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  local_351 = 1;
  pcVar4 = operator_new(0x80);
  *pcVar4 = '\0';
  if (param_2 == 0) {
    puVar5 = (undefined1 *)*param_1;
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_00566650(puVar5);
    puVar5 = (undefined1 *)param_1[2];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_005665b0(puVar5);
  }
  else {
    FUN_00566650(param_2);
  }
  pcVar14 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    pcVar14 = &DAT_005ea438;
  }
  uVar11 = 0xffffffff;
  do {
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    cVar1 = *pcVar14;
    pcVar14 = pcVar14 + 1;
  } while (cVar1 != '\0');
  if ((0 < (int)(~uVar11 - 1)) &&
     (iVar6 = FUN_00415c30(), *(char *)(iVar6 + -1 + (~uVar11 - 1)) != '\\')) {
    FUN_005665b0(&DAT_005c2aac);
  }
  FUN_005665b0(&DAT_005c2ab8);
  piVar12 = param_1 + 8;
  iVar6 = param_1[8];
  while (iVar6 != 0) {
    iVar7 = *(int *)(iVar6 + 4);
    FUN_00434420();
    FUN_00587bcf(iVar6);
    iVar6 = iVar7;
  }
  *piVar12 = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  iVar6 = param_1[0xc];
  while (iVar6 != 0) {
    iVar7 = *(int *)(iVar6 + 4);
    FUN_00434420();
    FUN_00587bcf(iVar6);
    iVar6 = iVar7;
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  pcVar14 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    pcVar14 = &DAT_005ea438;
  }
  hFindFile = FindFirstFileA(pcVar14,&local_340);
  if (hFindFile == (HANDLE)0xffffffff) {
    local_351 = 0;
  }
  else {
    do {
      if (((byte)local_340.dwFileAttributes & 0x10) == 0) {
        FUN_00568910(0x100);
        puVar8 = operator_new(8);
        if (puVar8 == (undefined4 *)0x0) {
          puVar8 = (undefined4 *)0x0;
        }
        else {
          *puVar8 = 0;
          puVar8[1] = 0xffffffff;
          FUN_00566650(local_100);
        }
        FUN_00434030(puVar8,1);
      }
      else {
        iVar6 = 2;
        bVar15 = true;
        pCVar13 = local_340.cFileName;
        pcVar14 = &DAT_005beb48;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar15 = *pCVar13 == *pcVar14;
          pCVar13 = pCVar13 + 1;
          pcVar14 = pcVar14 + 1;
        } while (bVar15);
        if (!bVar15) {
          iVar6 = 3;
          bVar15 = true;
          pCVar13 = local_340.cFileName;
          pcVar14 = &DAT_005c2ab4;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar15 = *pCVar13 == *pcVar14;
            pCVar13 = pCVar13 + 1;
            pcVar14 = pcVar14 + 1;
          } while (bVar15);
          if (!bVar15) {
            FUN_00568910(0x100);
            puVar8 = operator_new(8);
            if (puVar8 == (undefined4 *)0x0) {
              puVar8 = (undefined4 *)0x0;
            }
            else {
              *puVar8 = 0;
              puVar8[1] = 0xffffffff;
              FUN_00566650(local_200);
            }
            if (puVar8 != (undefined4 *)0x0) {
              pvVar9 = operator_new(0xc);
              if (pvVar9 == (void *)0x0) {
                iVar6 = 0;
              }
              else {
                iVar6 = FUN_004bac20(puVar8,1);
              }
              if (*piVar12 == 0) {
                *piVar12 = iVar6;
                param_1[10] = iVar6;
                param_1[9] = iVar6;
                param_1[0xb] = param_1[0xb] + 1;
              }
              else {
                *(int *)(param_1[9] + 4) = iVar6;
                param_1[9] = iVar6;
                param_1[0xb] = param_1[0xb] + 1;
              }
            }
          }
        }
      }
      BVar10 = FindNextFileA(hFindFile,&local_340);
    } while (BVar10 != 0);
    FindClose(hFindFile);
  }
  iVar7 = FUN_00434290(*piVar12);
  *piVar12 = iVar7;
  iVar6 = iVar7;
  if (iVar7 != 0) {
    iVar3 = *(int *)(iVar7 + 4);
    while (iVar2 = iVar3, iVar2 != 0) {
      iVar6 = iVar2;
      iVar3 = *(int *)(iVar2 + 4);
    }
  }
  param_1[9] = iVar6;
  param_1[10] = iVar7;
  FUN_00434090(1);
  param_1[7] = param_1[7] + 1;
  if (pcVar4 != (char *)0x0) {
    FUN_00587bcf(pcVar4);
  }
  return local_351;
}


