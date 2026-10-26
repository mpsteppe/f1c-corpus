// Function: FUN_004bc4e0 @ 004bc4e0
// Strings:  [Ignored Stop/Go Penalty, %d %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004bc4e0(int *param_1,float param_2,float param_3,int param_4,int param_5)

{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  undefined1 uVar5;
  int *piVar6;
  int iVar7;
  undefined1 local_50 [80];
  
  if (*(int *)(*param_1 + 13000) == 3) {
    return;
  }
  if (param_4 != 0) {
    param_1[3] = param_4;
    if (DAT_0059e440 < param_2) {
      if (((float)param_1[param_4 + 0x1a] < DAT_0059e440) ||
         (param_2 < (float)param_1[param_4 + 0x1a])) {
        param_1[param_4 + 0x1a] = (int)param_2;
      }
      param_1[param_1[3] + 6] = (int)param_2;
      FUN_004d1c40(param_1[3],*(undefined4 *)(*param_1 + 0x4894),0);
      FUN_00419500(*param_1,param_1[3]);
    }
    if ((param_1[0x18] == 0) && (param_1[3] == 1)) {
      param_1[0x18] = 1;
    }
    if (param_4 == 2) {
      iVar7 = 0;
      if (0 < param_1[0xf]) {
        piVar6 = param_1 + 0x10;
        do {
          if (*piVar6 == 1) {
            FUN_0041a8c0(*param_1);
            break;
          }
          iVar7 = iVar7 + 1;
          piVar6 = piVar6 + 2;
        } while (iVar7 < param_1[0xf]);
      }
    }
    if (*(int *)(*param_1 + 13000) != 0) {
      return;
    }
    FUN_004a6d50();
    return;
  }
  iVar7 = param_1[2];
  param_1[3] = 0;
  if (iVar7 < 0x7f) {
    if (-1 < iVar7) goto LAB_004bc523;
  }
  else {
    iVar7 = 0x7f;
LAB_004bc523:
    if (iVar7 < param_1[0x22]) {
      if (DAT_0059e440 < param_2) {
        *(float *)(param_1[0x24] + iVar7 * 4) = param_2;
        if (((float)param_1[0x1a] < DAT_0059e440) || (param_2 < (float)param_1[0x1a])) {
          param_1[0x20] = param_1[0x19];
          param_1[0x1a] = (int)param_2;
          FUN_004d1c40(param_1[3],*(undefined4 *)(*param_1 + 0x4894),0);
        }
        bVar3 = (float)param_1[0x1d] < DAT_0059e440;
        bVar4 = (float)param_1[0x1d] == DAT_0059e440;
        param_1[6] = (int)param_2;
        if ((bVar3 != bVar4) || (param_2 < (float)param_1[0x1d])) {
          param_1[0x1d] = param_1[6];
          param_1[0x1e] = param_1[7];
          param_1[0x1f] = param_1[8];
        }
      }
      uVar5 = FUN_004d1bc0((char)param_1[1]);
      *(undefined1 *)(iVar7 + param_1[0x25]) = uVar5;
    }
  }
  if (param_1[0x18] == 0) goto LAB_004bc876;
  param_5 = param_5 + 1;
  param_1[2] = param_5;
  switch(DAT_007c56a4) {
  case 0:
    FUN_004199e0(*param_1);
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    if (param_1[0xc] == 1) {
      if (((DAT_007c56a4 == 5) && (DAT_008acf8c < param_5)) &&
         ((DAT_007ce814 != 0 &&
          ((*(int *)(*param_1 + 13000) == 0 || (*(int *)(*param_1 + 13000) == 1)))))) {
        iVar7 = FUN_00423a00(&DAT_005c32fc,&DAT_005ec4cc);
        if (iVar7 != 0) {
          iVar7 = 0;
          do {
            pcVar1 = &DAT_005c32fc + iVar7;
            (&DAT_005ec4cc)[iVar7] = *pcVar1;
            iVar7 = iVar7 + 1;
          } while (*pcVar1 != '\0');
        }
        FUN_0058815f(local_50,s__d__s_005c3778,param_1[2],&DAT_005ec4cc);
        FUN_004bc0e0(local_50);
      }
    }
    else {
      if (param_1[0x18] == 2) {
        FUN_004199e0(*param_1);
      }
      if (((DAT_008acf8c <= param_1[2]) || (_DAT_008acf94 < param_3 != (_DAT_008acf94 == param_3)))
         && (param_1[0xc] != 3)) {
        param_1[0xc] = 1;
      }
      if (((DAT_008acf8c + -1 <= param_1[2]) ||
          (_DAT_008acf94 < param_3 != (_DAT_008acf94 == param_3))) &&
         ((DAT_007c56a4 == 5 && (param_1[1] == *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)))))
      {
        FUN_004a0c60();
      }
    }
    break;
  case 7:
    if (DAT_007c56a8 == 8) {
      if (param_1[0xc] != 3) {
        param_1[0xc] = 1;
      }
      param_1[0x21] = (int)(param_3 - _DAT_008acf90);
LAB_004bc69f:
      FUN_004a0ba0(*param_1);
    }
    else {
      if ((DAT_008acf8c <= param_5) || (_DAT_008acf94 < param_3 != (_DAT_008acf94 == param_3))) {
        if (param_1[0xc] != 3) {
          param_1[0xc] = 1;
        }
        param_1[0x21] = (int)(param_3 - _DAT_008acf90);
        FUN_0042d140(8);
        goto LAB_004bc69f;
      }
      FUN_004a0b20(*param_1);
      FUN_004199e0(*param_1);
    }
    iVar7 = 0;
    if (0 < param_1[0xf]) {
      piVar6 = param_1 + 0x10;
      do {
        iVar2 = *piVar6;
        if ((iVar2 == 0) || ((iVar2 == 1 && (*(char *)(*param_1 + 0x344c) == '\0')))) {
          if ((*(int *)(*param_1 + 13000) == 0) || (*(int *)(*param_1 + 13000) == 1)) {
            FUN_004bc0e0(s_Ignored_Stop_Go_Penalty_005c2730);
          }
          *piVar6 = 0;
        }
        else {
          *piVar6 = iVar2 + -1;
        }
        if (param_1[0xc] != 0) {
          param_1[0x21] = (int)((float)(piVar6[1] + 0xf) + (float)param_1[0x21]);
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 2;
      } while (iVar7 < param_1[0xf]);
    }
  }
  if ((DAT_008acfa0 == '\0') && (DAT_008acf8c + 1 >> 1 <= param_1[2])) {
    DAT_008acfa0 = '\x01';
  }
LAB_004bc876:
  param_1[0x19] = (int)param_3;
  iVar7 = param_1[2];
  param_1[0x18] = 2;
  if ((0 < iVar7) && (iVar7 <= param_1[0x22])) {
    *(float *)(param_1[0x23] + -4 + iVar7 * 4) = param_3;
  }
  FUN_004bc240();
  return;
}


