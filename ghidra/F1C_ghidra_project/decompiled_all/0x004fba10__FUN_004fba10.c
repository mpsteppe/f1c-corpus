// Function: FUN_004fba10 @ 004fba10
// Strings:  [CLOUDS, CLOUDS, CLOUDRNY, CLOUDRNY, CLOUDRNY, CLOUDRNY, CLOUDRNY, CLOUDSNY]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fba10(int *param_1)

{
  char cVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  int *piVar11;
  int local_458 [3];
  int local_44c;
  char local_440 [64];
  int local_400 [128];
  int local_200 [128];
  
  iVar3 = FUN_005453a0(s_SKYBOXI_005d6f28,0);
  *param_1 = iVar3;
  if (iVar3 != 0) {
    FUN_0054b420(param_1 + 1,param_1 + 2,param_1 + 3);
    FUN_0054bdc0(0,0,0);
  }
  uVar8 = 0xffffffff;
  iVar3 = 0;
  pcVar10 = &DAT_005d6f1c;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  uVar9 = 0xffffffff;
  pcVar10 = s_CLOUDRNY_005d6f10;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  param_1[0x10] = -1;
  do {
    if (iVar3 == 0) {
      pcVar10 = s_CLOUDS_005d6f08;
    }
    else if (iVar3 == 1) {
      pcVar10 = &DAT_005d6f1c;
    }
    else {
      pcVar10 = (char *)((iVar3 != 2) - 1 & 0x5d6f10);
    }
    iVar3 = iVar3 + 1;
    piVar11 = param_1 + iVar3 * 4;
    iVar4 = FUN_005453a0(pcVar10,*param_1);
    *piVar11 = iVar4;
    if (iVar4 != 0) {
      FUN_0054b420(piVar11 + 1,piVar11 + 2,piVar11 + 3);
      FUN_0054bdc0(0,0,0);
    }
  } while (iVar3 < 3);
  param_1[0x12] = 0;
  param_1[0x1f] = 0;
  if (param_1[8] != 0) {
    param_1[0x12] = 1;
    local_400[0] = param_1[8];
  }
  if (param_1[0xc] != 0) {
    param_1[0x1f] = 1;
    local_200[0] = param_1[0xc];
  }
  iVar3 = FUN_005452f0();
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      iVar5 = FUN_00545340(iVar4);
      FUN_0054bda0(local_440);
      iVar6 = _strncmp(local_440,&DAT_005d6f1c,~uVar8 - 1);
      if (iVar6 == 0) {
        iVar6 = param_1[0x12];
        local_400[iVar6] = iVar5;
        param_1[0x12] = iVar6 + 1;
      }
      else {
        iVar6 = _strncmp(local_440,s_CLOUDRNY_005d6f10,~uVar9 - 1);
        if (iVar6 == 0) {
          iVar6 = param_1[0x1f];
          local_200[iVar6] = iVar5;
          param_1[0x1f] = iVar6 + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  pvVar7 = operator_new(param_1[0x12] << 2);
  param_1[0x13] = (int)pvVar7;
  iVar3 = 0;
  if (0 < param_1[0x12]) {
    do {
      *(int *)(param_1[0x13] + iVar3 * 4) = local_400[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[0x12]);
  }
  pvVar7 = operator_new(param_1[0x1f] << 2);
  param_1[0x20] = (int)pvVar7;
  iVar3 = 0;
  if (0 < param_1[0x1f]) {
    do {
      *(int *)(param_1[0x20] + iVar3 * 4) = local_200[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[0x1f]);
  }
  iVar3 = FUN_00545f40();
  if (iVar3 == 0) {
    param_1[0x1c] = 0;
  }
  else {
    iVar4 = FUN_00548890(&DAT_005d6f1c);
    param_1[0x1c] = iVar4;
  }
  uVar8 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  param_1[0x1d] =
       (int)((*(float *)(&DAT_008aae74 + uVar8 * 4) * _DAT_0059e450 + _DAT_0059e450) * _DAT_007cf914
            );
  uVar8 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  param_1[0x1e] =
       (int)((*(float *)(&DAT_008aae74 + uVar8 * 4) * _DAT_0059e450 + _DAT_0059e450) * _DAT_007cf914
            );
  if (iVar3 == 0) {
    param_1[0x29] = 0;
  }
  else {
    iVar3 = FUN_00548890(s_CLOUDRNY_005d6f10);
    param_1[0x29] = iVar3;
  }
  uVar8 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  param_1[0x2a] =
       (int)((*(float *)(&DAT_008aae74 + uVar8 * 4) * _DAT_0059e450 + _DAT_0059e450) * _DAT_007cf914
            );
  uVar8 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  fVar2 = (*(float *)(&DAT_008aae74 + uVar8 * 4) * _DAT_0059e450 + _DAT_0059e450) * _DAT_007cf914;
  param_1[0x2c] = 0x7f7fffff;
  param_1[0x2d] = -0x800001;
  param_1[0x2b] = (int)fVar2;
  if (param_1[8] != 0) {
    FUN_004dd550(local_458);
    param_1[0x2c] = local_44c;
    param_1[0x2d] = local_458[0];
  }
  param_1[0x2e] = -0x40800000;
  return;
}


