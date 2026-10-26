// Function: FUN_00429960 @ 00429960
// Strings:  [%d,%d,%d,%d, %d,%d,%d, %d,%d, PitStopStrategies]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00429960(int *param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  float *pfVar9;
  char *pcVar10;
  int *piVar11;
  float fVar12;
  float10 extraout_ST0;
  char local_20 [32];
  
  FUN_004f1630();
  iVar3 = FUN_004a4830();
  param_1[0x1163] = iVar3;
  piVar6 = param_1 + 0x1166;
  iVar3 = 5;
  do {
    piVar6[-2] = DAT_008acf8c;
    *piVar6 = 1;
    piVar6[-1] = 0x461c3f9a;
    piVar6[1] = 0;
    piVar6 = piVar6 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  fVar12 = (float)param_1[0xe64] * _DAT_005ea40c;
  if ((float)param_1[0xe64] * _DAT_005ea40c < _DAT_0059e43c) {
    fVar12 = _DAT_0059e43c;
  }
  param_1[0x117a] = (int)fVar12;
  fVar1 = (float)DAT_007d0b64 * _DAT_0059e8bc;
  if (fVar12 < fVar1) {
    if (fVar1 < _DAT_0059e43c) {
      fVar1 = _DAT_0059e43c;
    }
    param_1[0x117a] = (int)fVar1;
  }
  param_1[0x1178] = 0;
  param_1[0x117c] = 0x461c3c00;
  if (DAT_007c56a4 == 7) {
    iVar3 = FUN_004c5840(0);
    if (((iVar3 != 0) && (iVar3 = FUN_005679c0(s_PitStopStrategies_005c3284), iVar3 != 0)) &&
       (iVar3 = FUN_005679c0(*param_1 + 0x4620), iVar3 != 0)) {
      pcVar4 = (char *)FUN_00567970();
      pcVar10 = local_20;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        *pcVar10 = cVar2;
        pcVar10 = pcVar10 + 1;
      } while (cVar2 != '\0');
      fVar12 = (float)DAT_007d0b64;
      piVar6 = param_1 + 0x1164;
      if (local_20[0] == '1') {
        param_1[0x1162] = 1;
        FUN_005887ed(local_20 + 3,&DAT_005c3280,piVar6);
        param_1[0x1168] = DAT_008acf8c;
      }
      else if (local_20[0] == '2') {
        param_1[0x1162] = 2;
        FUN_005887ed(local_20 + 3,s__d__d_005c3278,piVar6,param_1 + 0x1168);
        param_1[0x116c] = DAT_008acf8c;
      }
      else if (local_20[0] == '3') {
        param_1[0x1162] = 3;
        FUN_005887ed(local_20 + 3,s__d__d__d_005c326c,piVar6,param_1 + 0x1168,param_1 + 0x116c);
        param_1[0x1170] = DAT_008acf8c;
      }
      else {
        param_1[0x1162] = 4;
        FUN_005887ed(local_20 + 3,s__d__d__d__d_005c3260,piVar6,param_1 + 0x1168,param_1 + 0x116c,
                     param_1 + 0x1170);
        param_1[0x1174] = DAT_008acf8c;
      }
      iVar3 = 0;
      piVar11 = piVar6;
      if (0 < param_1[0x1162]) {
        do {
          if (fVar12 == DAT_0059e440) {
            *piVar11 = 0;
          }
          else {
            iVar5 = __ftol();
            *piVar11 = iVar5;
          }
          iVar3 = iVar3 + 1;
          piVar11 = piVar11 + 4;
        } while (iVar3 < param_1[0x1162]);
      }
      iVar3 = 0;
      if (0 < param_1[0x1162]) {
        do {
          piVar11 = param_1 + (iVar3 + 0x459) * 4;
          if ((DAT_008acf8c + -5 < param_1[(iVar3 + 0x459) * 4]) &&
             (param_1[0x1162] = iVar3, iVar3 < 5)) {
            iVar5 = 5 - iVar3;
            iVar3 = iVar3 + iVar5;
            do {
              *piVar11 = DAT_008acf8c;
              piVar11 = piVar11 + 4;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_1[0x1162]);
      }
      iVar3 = 0;
      if (0 < param_1[0x1162]) {
        do {
          iVar3 = iVar3 + 1;
          piVar6[1] = (int)((float)(piVar6[4] - *piVar6) * (float)param_1[0x117a]);
          piVar6 = piVar6 + 4;
        } while (iVar3 < param_1[0x1162]);
      }
    }
    if ((DAT_007d0b64 == 0) && (DAT_007d0c60 == 0)) {
      param_1[0x1162] = 0;
      param_1[0x1164] = DAT_008acf8c;
    }
    param_1[param_1[0x1162] * 4 + 0x1167] = 8;
  }
  else {
    switch(DAT_007c56a4) {
    case 0:
    case 1:
    case 2:
    case 6:
      uVar7 = _rand();
      uVar7 = uVar7 & 0x80000001;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
      }
      iVar3 = (uVar7 != 0) + 3;
      iVar5 = 0;
      param_1[0x1162] = iVar3;
      if (iVar3 != 0) {
        piVar6 = param_1 + 0x1167;
        do {
          _rand();
          iVar3 = __ftol();
          piVar6[-3] = iVar3;
          *piVar6 = 8;
          iVar5 = iVar5 + 1;
          piVar6 = piVar6 + 4;
        } while (iVar5 < param_1[0x1162]);
      }
      iVar3 = 0;
      if (0 < param_1[0x1162]) {
        piVar6 = param_1 + 0x1164;
        do {
          iVar3 = iVar3 + 1;
          piVar6[1] = (int)(((float)(piVar6[4] - *piVar6) + _DAT_0059e800) * (float)param_1[0x117a])
          ;
          piVar6 = piVar6 + 4;
        } while (iVar3 < param_1[0x1162]);
      }
      break;
    case 3:
    case 4:
    case 5:
      iVar3 = _rand();
      iVar3 = (iVar3 % 0x15 != 0) + 3;
      iVar5 = 0;
      param_1[0x1162] = iVar3;
      if (iVar3 != 0) {
        iVar3 = __ftol();
        pfVar9 = (float *)(param_1 + 0x1165);
        fVar12 = (float)(iVar3 + -1);
        do {
          pfVar9[-1] = fVar12;
          fVar1 = (float)param_1[0x117a];
          pfVar9[2] = 1.12104e-44;
          iVar5 = iVar5 + 1;
          fVar12 = (float)((int)fVar12 + iVar3);
          *pfVar9 = (float)(extraout_ST0 * (float10)fVar1);
          pfVar9 = pfVar9 + 4;
        } while (iVar5 < param_1[0x1162]);
      }
      iVar3 = 0;
      if (0 < param_1[0x1162]) {
        piVar6 = param_1 + 0x1164;
        do {
          iVar3 = iVar3 + 1;
          piVar6[1] = (int)(((float)(piVar6[4] - *piVar6) + _DAT_0059e800) * (float)param_1[0x117a])
          ;
          piVar6 = piVar6 + 4;
        } while (iVar3 < param_1[0x1162]);
      }
    }
  }
  if (param_1[0x1164] < 1) {
    param_1[0x1164] = 1;
  }
  param_1[0x117c] = (int)(((float)param_1[0x1164] + _DAT_0059e800) * (float)param_1[0x117a]);
  if (DAT_007d0b64 == 0) {
    param_1[0x117c] = 0x3f800000;
  }
  if ((float)param_1[0xe62] < (float)param_1[0x117c]) {
    param_1[0x117c] = param_1[0xe62];
  }
  if (*(int *)(*param_1 + 13000) == 1) {
    FUN_004f1890(param_1[0x117c]);
    uVar8 = FUN_00429fd0();
    FUN_004f1a60(uVar8,1);
  }
  return;
}


