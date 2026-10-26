// Function: FUN_0055fc40 @ 0055fc40
// Strings:  [%s\%s, Incorrect MAS file version, CUBEMAS4.01, CUBEMAS4.01, CUBEMAS4.00, CUBEMAS4.00, CUBEMAS4.10, CUBEMAS4.10]


undefined4 __thiscall FUN_0055fc40(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  bool bVar8;
  char *pcVar9;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  if (param_2 == (char *)0x0) {
    return 0xffffffff;
  }
  if (*param_2 == '\0') {
    return 0xffffffff;
  }
  pcVar9 = param_1 + 0x14;
  iVar5 = (int)pcVar9 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar5] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(pcVar9);
  iVar5 = FUN_00587db0(pcVar9,&DAT_005be828);
  *(int *)(param_1 + 0x10) = iVar5;
  if (iVar5 == 0) {
    iVar5 = 0;
    if (0 < DAT_008b8e30) {
      puVar6 = &DAT_008b5a3c;
      do {
        FUN_0058815f(local_200,s__s__s_005c2d64,puVar6,pcVar9);
        iVar2 = FUN_00587db0(local_200,&DAT_005be828);
        *(int *)(param_1 + 0x10) = iVar2;
        if (iVar2 != 0) break;
        iVar5 = iVar5 + 1;
        puVar6 = puVar6 + 0x84;
      } while (iVar5 < DAT_008b8e30);
    }
    if (iVar5 == DAT_008b8e30) {
      FUN_0058815f(local_100,s_Error_opening_MAS_file__s_005dbc14,pcVar9);
      FUN_0053c590(0xfffffffe,local_100);
      return 0xfffffffe;
    }
  }
  FUN_0058803f(param_1,1,0xc,*(undefined4 *)(param_1 + 0x10));
  iVar5 = 0xc;
  bVar8 = true;
  pcVar9 = param_1;
  pcVar7 = s_CUBEMAS4_10_005dbc08;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar8 = *pcVar9 == *pcVar7;
    pcVar9 = pcVar9 + 1;
    pcVar7 = pcVar7 + 1;
  } while (bVar8);
  if (!bVar8) {
    iVar5 = 0xc;
    bVar8 = true;
    pcVar9 = param_1;
    pcVar7 = s_CUBEMAS4_00_005dbbfc;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar8 = *pcVar9 == *pcVar7;
      pcVar9 = pcVar9 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (!bVar8) {
      iVar5 = 0xc;
      bVar8 = true;
      pcVar9 = param_1;
      pcVar7 = s_CUBEMAS4_01_005dbbf0;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar8 = *pcVar9 == *pcVar7;
        pcVar9 = pcVar9 + 1;
        pcVar7 = pcVar7 + 1;
      } while (bVar8);
      if (!bVar8) {
        FUN_00587d02(*(undefined4 *)(param_1 + 0x10));
        pcVar9 = s_Incorrect_MAS_file_version_005dbbd4;
        goto LAB_0055fd74;
      }
    }
  }
  FUN_0058803f(param_1 + 0x114,1,4,*(undefined4 *)(param_1 + 0x10));
  FUN_0058803f(param_1 + 0x118,1,4,*(undefined4 *)(param_1 + 0x10));
  FUN_0058803f(param_1 + 0x120,1,4,*(undefined4 *)(param_1 + 0x10));
  uVar3 = *(int *)(param_1 + 0x118) << 8;
  *(uint *)(param_1 + 0x11c) = uVar3;
  pvVar4 = operator_new(uVar3);
  *(void **)(param_1 + 0x128) = pvVar4;
  if (pvVar4 != (void *)0x0) {
    FUN_0058803f(pvVar4,1,*(undefined4 *)(param_1 + 0x11c),*(undefined4 *)(param_1 + 0x10));
    *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 0x18;
    return 0;
  }
  FUN_00587d02(*(undefined4 *)(param_1 + 0x10));
  pcVar9 = s_Unable_to_allocate_for_MAS_heade_005dc5e4;
LAB_0055fd74:
  FUN_0053c590(0xffffffff,pcVar9);
  return 0xffffffff;
}


