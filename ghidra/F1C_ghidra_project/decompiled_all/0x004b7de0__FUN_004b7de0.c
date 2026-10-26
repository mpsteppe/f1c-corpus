// Function: FUN_004b7de0 @ 004b7de0
// Strings:  [Saving Hotlap, Saving Hotlap, HOT LAP, HOT LAP]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_004b7de0(int param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 uVar9;
  char *pcVar10;
  char *pcVar11;
  undefined1 local_229;
  undefined1 local_21c [27];
  char local_201 [513];
  
  fVar1 = *(float *)(DAT_007c54e8 + 0x409c);
  uVar9 = 0;
  local_229 = 0;
  if (fVar1 == _DAT_0059e670) {
    return 0;
  }
  if (fVar1 <= DAT_0059e440) {
    return 0;
  }
  fVar2 = *(float *)(DAT_007c54e8 + 0x40b4);
  pcVar5 = *(char **)(param_1 + 0x70c);
  if (pcVar5 == (char *)0x0) {
    pcVar5 = &DAT_005ea438;
  }
  pcVar11 = local_201;
  do {
    pcVar11 = pcVar11 + 1;
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar11 = cVar3;
  } while (cVar3 != '\0');
  uVar6 = 0xffffffff;
  pcVar5 = local_201;
  do {
    pcVar5 = pcVar5 + 1;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
  } while (*pcVar5 != '\0');
  pcVar5 = local_201 + ~uVar6;
  if (local_201 + 1 < pcVar5) {
    do {
      if (*pcVar5 == '.') {
        *pcVar5 = '\0';
        break;
      }
      pcVar5 = pcVar5 + -1;
    } while (local_201 + 1 < pcVar5);
  }
  iVar7 = -1;
  pcVar5 = local_201 + 1;
  do {
    pcVar11 = pcVar5;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar11 = pcVar5 + 1;
    cVar3 = *pcVar5;
    pcVar5 = pcVar11;
  } while (cVar3 != '\0');
  *(undefined2 *)(pcVar11 + -1) = DAT_005c32d8;
  iVar7 = FUN_00423a00(s_HOT_LAP_005d2464,&DAT_005ec4cc);
  if (iVar7 != 0) {
    iVar7 = 0;
    do {
      pcVar5 = s_HOT_LAP_005d2464 + iVar7;
      (&DAT_005ec4cc)[iVar7] = *pcVar5;
      iVar7 = iVar7 + 1;
    } while (*pcVar5 != '\0');
  }
  uVar6 = 0xffffffff;
  pcVar5 = &DAT_005ec4cc;
  do {
    pcVar11 = pcVar5;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar11 = pcVar5 + 1;
    cVar3 = *pcVar5;
    pcVar5 = pcVar11;
  } while (cVar3 != '\0');
  uVar6 = ~uVar6;
  iVar7 = -1;
  pcVar5 = local_201 + 1;
  do {
    pcVar10 = pcVar5;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar10 = pcVar5 + 1;
    cVar3 = *pcVar5;
    pcVar5 = pcVar10;
  } while (cVar3 != '\0');
  pcVar5 = pcVar11 + -uVar6;
  pcVar11 = pcVar10 + -1;
  for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar11 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar11 = pcVar11 + 1;
  }
  iVar7 = -1;
  pcVar5 = local_201 + 1;
  do {
    pcVar11 = pcVar5;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar11 = pcVar5 + 1;
    cVar3 = *pcVar5;
    pcVar5 = pcVar11;
  } while (cVar3 != '\0');
  *(undefined4 *)(pcVar11 + -1) = DAT_005be714;
  pcVar11[3] = DAT_005be718;
  FUN_005668b0();
  switch(*(undefined4 *)(param_1 + 0x9a4)) {
  case 0:
    uVar4 = 0;
    break;
  case 1:
    uVar4 = 1;
    break;
  case 2:
    uVar4 = 2;
    break;
  case 3:
    uVar4 = 3;
    break;
  default:
    uVar4 = 4;
  }
  cVar3 = FUN_00566940(local_201 + 1,uVar4,0,1);
  if (cVar3 == '\0') goto LAB_004b7fe9;
  iVar7 = FUN_00423a00(s_Saving_Hotlap_005d2454,&DAT_005ec4cc);
  if (iVar7 != 0) {
    iVar7 = 0;
    do {
      pcVar5 = s_Saving_Hotlap_005d2454 + iVar7;
      (&DAT_005ec4cc)[iVar7] = *pcVar5;
      iVar7 = iVar7 + 1;
    } while (*pcVar5 != '\0');
  }
  FUN_004a0e70(&DAT_005ec4cc);
  cVar3 = FUN_004b6a10(local_21c,fVar2,fVar2 + fVar1);
  if (cVar3 == '\0') {
LAB_004b7fdc:
    uVar9 = local_229;
  }
  else {
    iVar7 = FUN_004b7c80(param_1 + 0x6e4,local_21c,fVar2,fVar2 + fVar1);
    uVar9 = 1;
    if (iVar7 == 0) goto LAB_004b7fdc;
  }
  FUN_00566b90();
LAB_004b7fe9:
  FUN_005668d0();
  return uVar9;
}


