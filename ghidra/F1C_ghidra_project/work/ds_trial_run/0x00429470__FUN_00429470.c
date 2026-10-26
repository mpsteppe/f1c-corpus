// Function: FUN_00429470 @ 00429470
// Size (bytes): 1259


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00429470(int *param_1)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float local_4;
  
  param_1[0x1151] = 1;
  iVar4 = FUN_004d1cf0(param_1[0x1011]);
  if (iVar4 == 2) {
    param_1[0x1151] = 0;
    fVar5 = (float10)FUN_00424750();
    param_1[0x115f] = (int)(float)(fVar5 * (float10)_DAT_0059e7fc);
  }
  else {
    iVar4 = FUN_004d1cf0(param_1[0x1011]);
    if ((iVar4 == 0) || (iVar4 = FUN_004d1cf0(param_1[0x1011]), iVar4 == 1)) {
      fVar5 = (float10)FUN_00424750();
      param_1[0x115f] = (int)(float)fVar5;
      if (DAT_007c56a4 == 7) {
        if ((float)param_1[0x1142] == DAT_0059e440) {
          fVar2 = (float)param_1[0x114f] - _DAT_0059e444;
          if (fVar2 < (float)param_1[0x113d]) {
            fVar2 = (float)param_1[0x113d];
          }
        }
        else {
          fVar2 = (float)param_1[0x1136] + (float)param_1[0x113d];
          if ((float)param_1[0x114f] + _DAT_0059e444 <=
              (float)param_1[0x1136] + (float)param_1[0x113d]) {
            fVar2 = (float)param_1[0x114f] + _DAT_0059e444;
          }
        }
        param_1[0x114f] = (int)fVar2;
        if ((float)param_1[0x1143] != DAT_0059e440) {
          iVar4 = _rand();
          if ((float)(iVar4 % 100) <=
              ((float)param_1[0x1135] - (float)param_1[0x1143] * _DAT_0059e450) * _DAT_0059e6f8) {
            fVar2 = (float)param_1[0x1136] + (float)param_1[0x113d];
            if ((float)param_1[0x114f] + _DAT_0059e444 <=
                (float)param_1[0x1136] + (float)param_1[0x113d]) {
              fVar2 = (float)param_1[0x114f] + _DAT_0059e444;
            }
          }
          else {
            fVar2 = (float)param_1[0x113d] * _DAT_0059e450;
            if ((float)param_1[0x113d] * _DAT_0059e450 <= (float)param_1[0x114f] - _DAT_0059e444) {
              fVar2 = (float)param_1[0x114f] - _DAT_0059e444;
            }
          }
          param_1[0x114f] = (int)fVar2;
        }
        param_1[0x1142] = 0;
        param_1[0x1143] = 0;
      }
    }
  }
  if (param_1[0x1019] == 1) {
    fVar6 = (float10)FUN_00424750();
    fVar5 = (float10)_DAT_0059e7fc;
    param_1[0x1151] = 0;
    param_1[0x115f] = (int)(float)(fVar6 * fVar5);
  }
  if (((param_1[0xf5b] == 2) ||
      ((float)param_1[0xe61] < _DAT_0059e600 != ((float)param_1[0xe61] == _DAT_0059e600))) ||
     (DAT_0059e440 < (float)param_1[0x1000])) {
    if ((((DAT_007c56a4 != 7) || (param_1[0x100f] != DAT_008acf8c + -1)) ||
        ((param_1[0x1010] != 2 && (param_1[0x1010] != -1)))) ||
       ((float)param_1[0x1110] < _DAT_0059e7ec)) {
      iVar4 = param_1[0x10d5];
      param_1[0x114d] = (int)((float)_DAT_008afea0 + _DAT_0059e968);
      if (*(float *)(iVar4 + 0x34) - (float)param_1[0x110a] <=
          (float)param_1[0x110a] + *(float *)(iVar4 + 0x38)) {
        fVar2 = *(float *)(iVar4 + 0x38);
      }
      else {
        fVar2 = -*(float *)(iVar4 + 0x34);
      }
      param_1[0x1108] = (int)fVar2;
      *(undefined1 *)((int)param_1 + 0x4579) = 0;
      if (((DAT_007c56a4 == 7) && (FUN_004efac0(), DAT_0059e440 < (float)param_1[0x1000])) &&
         (param_1[0x101a] == 0)) {
        param_1[0x101a] = 6;
      }
      if ((float)param_1[0x1110] < _DAT_0059e43c) {
        if (DAT_007c56a4 == 7) {
          *(undefined1 *)(param_1 + 0x117d) = 0;
        }
        else {
          *(undefined1 *)((int)param_1 + 0x4579) = 0;
          FUN_0042a3d0();
          pfVar1 = (float *)(param_1 + param_1[0x1178] * 4 + 0x1165);
          fVar2 = _DAT_0059e43c;
          if (_DAT_0059e43c <= (float)param_1[param_1[0x1178] * 4 + 0x1165]) {
            fVar2 = *pfVar1;
          }
          if (fVar2 <= (float)param_1[0xe62]) {
            if (_DAT_0059e43c <= *pfVar1) {
              local_4 = *pfVar1;
            }
            else {
              local_4 = 1.0;
            }
          }
          else {
            local_4 = (float)param_1[0xe62];
          }
          FUN_004f1890(local_4);
          FUN_0042a6f0();
          param_1[0x1151] = 0;
          FUN_0042acd0(0x12);
          param_1[0x1154] = 1;
          *(undefined1 *)(param_1 + 0x1152) = 1;
          param_1[0x110f] = 0;
          param_1[0xd3e] = 0;
          param_1[0xd40] = 0;
          param_1[0xd3f] = 0;
          param_1[0x10fe] = 0;
          FUN_0042ae00();
          if (DAT_007c56a4 == 7) {
            param_1[0x1144] = 4;
          }
          else {
            param_1[0x1144] = 5;
          }
          param_1[0x1149] = 0;
          param_1[0x110e] = 0x3f800000;
          param_1[0x110d] = 0;
          param_1[0x1153] = 0;
          param_1[0x1154] = 1;
          param_1[0x1109] = 0;
          FUN_00426430();
          param_1[0x114d] = (int)((float)_DAT_008afea0 + _DAT_0059e808);
        }
      }
    }
  }
  else if (param_1[0xf5b] == 1) {
    iVar4 = *param_1;
    if ((((*(int *)(iVar4 + 0xcd4) != 0) && (*(char *)(iVar4 + 0xd14) == '\0')) ||
        ((*(int *)(iVar4 + 0xd18) != 0 && (*(char *)(iVar4 + 0xd58) == '\0')))) ||
       ((*(char *)((int)param_1 + 0x39fa) != '\0' && (param_1[0x100f] + 2 < DAT_008acf8c)))) {
      FUN_0042a110();
    }
    param_1[0x114f] = (int)((float)param_1[0x113d] * _DAT_0059e908);
  }
  if (((param_1[0x117e] != 0) && (DAT_007c56a4 == 7)) &&
     ((((iVar4 = FUN_0042ad20(), iVar4 < 2 && ((iVar4 = FUN_0042ad20(), 0 < iVar4 && (iVar4 < 3))))
       && (cVar3 = FUN_0042ad50(), cVar3 == '\0')) && (cVar3 = FUN_0042ad50(), cVar3 == '\0')))) {
    FUN_0042a110();
  }
  FUN_00429eb0();
  param_1[0x112c] = -1;
  return;
}


