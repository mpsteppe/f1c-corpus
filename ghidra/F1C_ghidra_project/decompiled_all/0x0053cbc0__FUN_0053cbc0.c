// Function: FUN_0053cbc0 @ 0053cbc0
// Strings:  [%s\%s, Incorrect MAS file version, CUBEMAS4.01, CUBEMAS4.01, CUBEMAS4.00, CUBEMAS4.00, CUBEMAS4.10, CUBEMAS4.10]


undefined4 FUN_0053cbc0(int *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  char *pcVar9;
  bool bVar10;
  undefined4 local_214;
  char local_210 [16];
  char local_200 [256];
  undefined1 local_100 [256];
  
  iVar6 = 0;
  local_214 = 0;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    iVar4 = -(int)param_2;
    do {
      cVar1 = *param_2;
      param_2[(int)(local_200 + iVar4)] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_200);
    iVar4 = FUN_00587db0(local_200,&DAT_005be828);
    if (iVar4 == 0) {
      bVar10 = DAT_008b8e30 == 0;
      if (0 < DAT_008b8e30) {
        puVar8 = &DAT_008b5a3c;
        do {
          FUN_0058815f(local_100,s__s__s_005c2d64,puVar8,local_200);
          iVar4 = FUN_00587db0(local_100,&DAT_005be828);
          if (iVar4 != 0) break;
          iVar6 = iVar6 + 1;
          puVar8 = puVar8 + 0x84;
        } while (iVar6 < DAT_008b8e30);
        bVar10 = iVar6 == DAT_008b8e30;
      }
      if (bVar10) {
        FUN_0058815f(local_100,s_Error_opening_MAS_file__s_005dbc14,local_200);
        FUN_0053c590(0xfffffffe,local_100);
        return 0xfffffffe;
      }
    }
    FUN_0058803f(local_210,1,0xc,iVar4);
    FUN_00587d02(iVar4);
    iVar6 = 0xc;
    bVar10 = true;
    pcVar7 = local_210;
    pcVar9 = s_CUBEMAS4_10_005dbc08;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar10 = *pcVar7 == *pcVar9;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if (!bVar10) {
      iVar6 = 0xc;
      bVar10 = true;
      pcVar7 = local_210;
      pcVar9 = s_CUBEMAS4_00_005dbbfc;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar10 = *pcVar7 == *pcVar9;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      } while (bVar10);
      if (!bVar10) {
        iVar6 = 0xc;
        bVar10 = true;
        pcVar7 = local_210;
        pcVar9 = s_CUBEMAS4_01_005dbbf0;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar10 = *pcVar7 == *pcVar9;
          pcVar7 = pcVar7 + 1;
          pcVar9 = pcVar9 + 1;
        } while (bVar10);
        if (!bVar10) {
          return 0;
        }
      }
      FUN_0053c590(0xfffffffe,s_Incorrect_MAS_file_version_005dbbd4);
      return 0xffffffff;
    }
    pvVar5 = operator_new(0x134);
    if (pvVar5 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_0055fbe0();
    }
    iVar4 = FUN_0055fc40(local_200);
    if (iVar4 == -2) {
      if (iVar6 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar6);
      }
      local_214 = 0xfffffffe;
    }
    else if (iVar4 == -1) {
      if (iVar6 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar6);
      }
      local_214 = 0xffffffff;
    }
    else if (iVar4 == 0) {
      iVar4 = iVar6;
      if (DAT_008b8f14 != 0) {
        iVar3 = *(int *)(DAT_008b8f14 + 0x130);
        iVar4 = DAT_008b8f14;
        while (iVar2 = iVar3, iVar2 != 0) {
          iVar4 = iVar2;
          iVar3 = *(int *)(iVar2 + 0x130);
        }
        *(int *)(iVar4 + 0x130) = iVar6;
        *(int *)(iVar6 + 300) = iVar4;
        iVar4 = DAT_008b8f14;
      }
      DAT_008b8f14 = iVar4;
      DAT_008b6ac0 = DAT_008b6ac0 + 1;
      local_214 = 0;
    }
    if (param_1 != (int *)0x0) {
      *param_1 = iVar6;
    }
  }
  return local_214;
}


