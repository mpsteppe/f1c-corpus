// Function: FUN_00588a34 @ 00588a34
// Strings:  [LC_CTYPE, LC_COLLATE, LC_COLLATE]


undefined4 FUN_00588a34(int param_1,char *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  undefined **ppuVar6;
  char *_Str2;
  undefined4 *puVar7;
  char local_8c [132];
  size_t local_8;
  
  iVar5 = 0;
  if ((param_1 < 0) || (5 < param_1)) {
    return 0;
  }
  FUN_0058dfea(0x13);
  DAT_008d5a58 = DAT_008d5a58 + 1;
  while (DAT_008d5a5c != 0) {
    Sleep(1);
  }
  if (param_1 == 0) {
    local_8 = 1;
    param_1 = 0;
    if (param_2 == (char *)0x0) {
LAB_00588c5a:
      uVar1 = FUN_00588d95();
    }
    else {
      if (((*param_2 == 'L') && (param_2[1] == 'C')) && (param_2[2] == '_')) {
        pcVar2 = (char *)FUN_0058fc60(param_2,&DAT_005b8c78);
        _Str2 = param_2;
        while (((pcVar2 != (char *)0x0 && (local_8 = (int)pcVar2 - (int)_Str2, local_8 != 0)) &&
               (*pcVar2 != ';'))) {
          param_2 = (char *)0x1;
          ppuVar6 = &PTR_s_LC_COLLATE_005e64fc;
          do {
            iVar5 = _strncmp(*ppuVar6,_Str2,local_8);
            if ((iVar5 == 0) && (sVar3 = _strlen(*ppuVar6), local_8 == sVar3)) break;
            param_2 = (char *)((int)param_2 + 1);
            ppuVar6 = ppuVar6 + 3;
          } while ((int)ppuVar6 < 0x5e652d);
          pcVar2 = pcVar2 + 1;
          sVar3 = FUN_0058fc20(pcVar2,&DAT_005b8c74);
          if ((sVar3 == 0) && (*pcVar2 != ';')) break;
          if ((int)param_2 < 6) {
            _strncpy(local_8c,pcVar2,sVar3);
            local_8c[sVar3] = '\0';
            iVar5 = FUN_00588c7a(param_2,local_8c);
            if (iVar5 != 0) {
              param_1 = param_1 + 1;
            }
          }
          if ((pcVar2[sVar3] == '\0') || (_Str2 = pcVar2 + sVar3 + 1, *_Str2 == '\0'))
          goto LAB_00588bc4;
          pcVar2 = (char *)FUN_0058fc60(_Str2,&DAT_005b8c78);
        }
        FUN_0058e04b(0x13);
        uVar1 = 0;
        goto LAB_00588c69;
      }
      iVar4 = FUN_00588e4e(param_2,local_8c,0,0,0);
      uVar1 = 0;
      if (iVar4 != 0) {
        puVar7 = &DAT_005e64f4;
        do {
          if (puVar7 != &DAT_005e64f4) {
            iVar4 = _strcmp(local_8c,(char *)*puVar7);
            if ((iVar4 == 0) || (iVar4 = FUN_00588c7a(iVar5,local_8c), iVar4 != 0)) {
              param_1 = param_1 + 1;
            }
            else {
              local_8 = 0;
            }
          }
          puVar7 = puVar7 + 3;
          iVar5 = iVar5 + 1;
        } while ((int)puVar7 < 0x5e6531);
        if (local_8 == 0) {
LAB_00588bc4:
          if (param_1 != 0) goto LAB_00588c5a;
          uVar1 = 0;
        }
        else {
          uVar1 = FUN_00588d95();
          FUN_0058aa6f(DAT_005e64f4);
          DAT_005e64f4 = 0;
        }
      }
    }
  }
  else if (param_2 == (char *)0x0) {
    uVar1 = (&DAT_005e64f4)[param_1 * 3];
  }
  else {
    uVar1 = FUN_00588c7a(param_1,param_2);
  }
  FUN_0058e04b(0x13);
LAB_00588c69:
  DAT_008d5a58 = DAT_008d5a58 + -1;
  return uVar1;
}


