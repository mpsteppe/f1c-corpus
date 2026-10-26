// Function: FUN_0046b5f0 @ 0046b5f0
// Strings:  [FTIM14REDOUTLINED.BMP, FTIM14REDOUTLINED.BMP, FTIM14GREENOUTLINED.BMP, FTIM14GREENOUTLINED.BMP, FTIM14GreyOutlined.bmp, FTIM14GreyOutlined.bmp, %d/%s]


undefined4 __thiscall FUN_0046b5f0(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  undefined1 local_128 [8];
  char local_120 [48];
  char local_f0 [47];
  undefined1 local_c1;
  char local_c0 [47];
  undefined1 local_91;
  undefined1 local_90 [48];
  undefined1 local_60 [48];
  undefined1 local_30 [48];
  
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = 0;
  }
  iVar3 = (&DAT_007c54f0)[param_2];
  FUN_0058815f(local_120,&DAT_005c3280,*(undefined4 *)(iVar3 + 0x4060));
  _strncpy(local_f0,(char *)(iVar3 + 0x4620),0x2f);
  local_c1 = 0;
  _strncpy(local_c0,(char *)(iVar3 + 0x46b8),0x2f);
  iVar5 = DAT_008acf8c;
  local_91 = 0;
  if ((DAT_007c56a4 == 5) || (DAT_007c56a4 == 7)) {
    iVar3 = *(int *)(iVar3 + 0x403c);
    if (DAT_008acf8c == 0x7fffffff) {
      FUN_0058815f(local_128,&DAT_005c6a78);
    }
    else {
      FUN_0058815f(local_128,&DAT_005c3280,DAT_008acf8c);
    }
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if ((iVar5 < iVar3) && (DAT_007ce814 == 0)) {
      iVar3 = iVar5;
    }
    FUN_0058815f(local_90,s__d__s_005c6a70,iVar3,local_128);
  }
  else {
    FUN_0058815f(local_90,&DAT_005c3280,
                 ((int)*(uint *)(iVar3 + 0x403c) < 0) - 1 & *(uint *)(iVar3 + 0x403c));
  }
  iVar3 = FUN_0042bdd0(param_2,local_60);
  if (iVar3 == 1) {
    pcVar4 = s_FTIM14REDOUTLINED_BMP_005c6a28;
    do {
      cVar1 = *pcVar4;
      (param_4 + -0x5c6a28)[(int)pcVar4] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  else if (iVar3 == 2) {
    pcVar4 = s_FTIM14GREENOUTLINED_BMP_005c6a40;
    do {
      cVar1 = *pcVar4;
      (param_4 + -0x5c6a40)[(int)pcVar4] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  else if (iVar3 == 3) {
    pcVar4 = s_FTIM14GreyOutlined_bmp_005c6a58;
    do {
      cVar1 = *pcVar4;
      (param_4 + -0x5c6a58)[(int)pcVar4] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  FUN_0046b830(param_2,local_30,0x2f);
  *param_3 = '\0';
  bVar2 = true;
  iVar3 = 0;
  pcVar4 = local_120;
  do {
    if ((*(int *)(param_1 + 0x17c) != 1) ||
       ((uVar6 = 0, -1 < iVar3 && ((iVar3 < 2 || (iVar3 == 4)))))) {
      if (!bVar2) {
        iVar5 = -1;
        pcVar8 = param_3;
        do {
          pcVar10 = pcVar8;
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          pcVar10 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar10;
        } while (cVar1 != '\0');
        *(undefined2 *)(pcVar10 + -1) = DAT_005c692c;
      }
      uVar6 = 0xffffffff;
      pcVar8 = pcVar4;
      do {
        pcVar10 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar10 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar10;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar5 = -1;
      pcVar8 = param_3;
      do {
        pcVar9 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      pcVar8 = pcVar10 + -uVar6;
      pcVar10 = pcVar9 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar10 = pcVar10 + 4;
      }
      bVar2 = false;
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    iVar3 = iVar3 + 1;
    pcVar4 = pcVar4 + 0x30;
    if (5 < iVar3) {
      return CONCAT31((int3)(uVar6 >> 8),1);
    }
  } while( true );
}


