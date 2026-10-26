// Function: FUN_004d2e50 @ 004d2e50
// Strings:  [%s %d:%02d:%02d, Time Remaining:, Time Remaining:, 00:01, Time until pit closes: , Time until pit closes: ]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d2e50(int *param_1)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  undefined4 uVar8;
  undefined1 local_50 [80];
  
  if (DAT_007c56a4 < 1) goto switchD_004d2e8b_default;
  if (DAT_007c56a4 < 7) {
    FUN_0041a500(param_1[0x2d]);
    if (DAT_007c56a8 != 0) {
      if (DAT_007c56a8 == 5) {
        if ((double)(float)param_1[0x2d] <= _DAT_008afea0) {
          FUN_0042d140(8);
          FUN_004d0ec0(2);
          FUN_0041a6b0();
        }
        goto switchD_004d2e8b_default;
      }
      if (DAT_007c56a8 != 7) goto switchD_004d2e8b_default;
      fVar2 = (float)_DAT_008afe98 + (float)param_1[0x2d];
LAB_004d3428:
      param_1[0x2d] = (int)fVar2;
      goto switchD_004d2e8b_default;
    }
    if (_DAT_008afea0 < (double)(float)param_1[0x2c]) goto switchD_004d2e8b_default;
    uVar8 = 5;
LAB_004d2eaa:
    FUN_0042d140(uVar8);
    FUN_004d0ec0(1);
    goto switchD_004d2e8b_default;
  }
  if (DAT_007c56a4 != 7) goto switchD_004d2e8b_default;
  switch(DAT_007c56a8) {
  case 0:
    if (_DAT_008afea0 < (double)(float)param_1[0x2c]) break;
    uVar8 = 1;
    goto LAB_004d2eaa;
  case 1:
    if ((float)_DAT_008afea0 < (float)param_1[0x2d]) {
      fVar2 = (float)param_1[0x2d] - (float)_DAT_008afea0;
      if (fVar2 < _DAT_005acefc) {
        if (fVar2 < _DAT_0059e808) {
          if (fVar2 < _DAT_0059e968) {
            if (fVar2 < _DAT_0059f118) {
              uVar8 = 1;
            }
            else {
              uVar8 = 2;
            }
          }
          else {
            uVar8 = 3;
          }
        }
        else {
          uVar8 = 4;
        }
      }
      else {
        uVar8 = 5;
      }
      FUN_004d1cd0(uVar8);
      if ((fVar2 < _DAT_0059e8d8) && (DAT_007ced8c == 0)) {
        FUN_004d2e20();
      }
      fVar3 = ((float)_DAT_007cec30 + (float)param_1[0x2c]) - (float)_DAT_008afea0;
      if (DAT_0059e440 <= fVar3) {
        if (DAT_007cec78 != '\0') {
          iVar6 = FUN_00423a00(s_Time_until_pit_closes__005d41bc,&DAT_005ec4cc);
          if (iVar6 != 0) {
            iVar6 = 0;
            do {
              pcVar1 = s_Time_until_pit_closes__005d41bc + iVar6;
              (&DAT_005ec4cc)[iVar6] = *pcVar1;
              iVar6 = iVar6 + 1;
            } while (*pcVar1 != '\0');
          }
          FUN_004d11d0(fVar3,&DAT_005ec4cc);
        }
      }
      else {
        FUN_004d0ec0(2);
        if (_DAT_0059e99c < fVar3) {
          FUN_0045bdf0();
        }
        if (DAT_007cec78 != '\0') {
          FUN_004d11d0(fVar2,0);
        }
      }
      break;
    }
    FUN_0045bdf0();
    if (DAT_007ced8c != 0) {
      FUN_0042d140(2);
      fVar2 = (float)param_1[0x2d] + _DAT_0059e80c;
      goto LAB_004d3428;
    }
    goto LAB_004d30ab;
  case 2:
    if (*(char *)((int)param_1 + 0xc2) == '\0') {
      FUN_0040cde0(5,1);
      *(undefined1 *)((int)param_1 + 0xc2) = 1;
    }
    if (*param_1 == 2) {
      FUN_0040dd80();
    }
    FUN_0040de60();
    if (_DAT_008afea0 < (double)(float)param_1[0x2d]) break;
    *(undefined1 *)((int)param_1 + 0xc2) = 0;
LAB_004d30ab:
    if (DAT_007cee88 == 0) {
      param_1[0x36] = 0x7f7fffff;
      param_1[0x2c] = 0x7f7fffff;
      *(undefined1 *)((int)param_1 + 0xc2) = 0;
      FUN_0042d140(4);
    }
    else {
      FUN_0042d140(3);
    }
    break;
  case 3:
    if (DAT_007c54e8 != 0) {
      FUN_004bc9b0(0,1);
    }
    FUN_004d1cd0(0);
    FUN_0040e170();
    break;
  case 4:
    if (*(char *)((int)param_1 + 0xc2) == '\0') {
      FUN_0040e170();
      FUN_0040d100();
      *(undefined1 *)((int)param_1 + 0xc2) = 1;
    }
    if (_DAT_008afea0 < (double)(float)param_1[0x2c]) {
      cVar4 = FUN_00461db0();
      if (cVar4 != '\0') {
        FUN_0045bde0(s_00_01_005d41b4,0);
      }
      fVar2 = (float)_DAT_008afea0;
      if ((float)param_1[0x36] + _DAT_0059e46c < fVar2 ==
          ((float)param_1[0x36] + _DAT_0059e46c == fVar2)) {
        if ((float)param_1[0x36] + _DAT_0059e478 < fVar2 ==
            ((float)param_1[0x36] + _DAT_0059e478 == fVar2)) {
          if ((float)param_1[0x36] + _DAT_0059e800 < fVar2 ==
              ((float)param_1[0x36] + _DAT_0059e800 == fVar2)) {
            if ((float)param_1[0x36] + _DAT_0059e43c < fVar2 ==
                ((float)param_1[0x36] + _DAT_0059e43c == fVar2)) {
              if ((float)param_1[0x36] < fVar2 == ((float)param_1[0x36] == fVar2)) {
                FUN_004d1cd0(0);
                cVar4 = FUN_00461db0();
                if ((cVar4 != '\0') && (DAT_0059e440 < _DAT_005acef8 - (float)_DAT_008afea0)) {
                  FUN_004d11d0(_DAT_005acef8 - (float)_DAT_008afea0,0);
                }
              }
              else {
                FUN_004d1cd0(1);
              }
            }
            else {
              FUN_004d1cd0(2);
            }
          }
          else {
            FUN_004d1cd0(3);
          }
        }
        else {
          FUN_004d1cd0(4);
        }
      }
      else {
        FUN_004d1cd0(5);
      }
    }
    else {
      FUN_004d2210();
      FUN_004d1cd0(0);
      FUN_0042d140(5);
    }
    break;
  case 5:
    if ((param_1[0x3d] == 2) && (iVar6 = 0, 0 < DAT_005c329c)) {
      do {
        if (*(int *)((&DAT_007c54f0)[iVar6] + 0x4040) == 1) {
          FUN_004d0ec0(1);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_005c329c);
    }
    if (((0 < DAT_007cebf4) &&
        (iVar6 = (int)ROUND(((float)param_1[0x2d] - (float)_DAT_008afea0) + _DAT_0059e450),
        -1 < iVar6)) && (iVar6 % DAT_007cebf4 == 0)) {
      iVar5 = FUN_00423a00(s_Time_Remaining__005d41a4,&DAT_005ec4cc);
      if (iVar5 != 0) {
        iVar5 = 0;
        do {
          pcVar1 = s_Time_Remaining__005d41a4 + iVar5;
          (&DAT_005ec4cc)[iVar5] = *pcVar1;
          iVar5 = iVar5 + 1;
        } while (*pcVar1 != '\0');
      }
      FUN_0058815f(local_50,s__s__d__02d__02d_005d4194,&DAT_005ec4cc,iVar6 / 0xe10,
                   (iVar6 % 0xe10) / 0x3c,(iVar6 % 0xe10) % 0x3c);
      FUN_0045bd10(local_50,3,0x1020304);
    }
  }
switchD_004d2e8b_default:
  if (param_1[0x3d] != 2) {
    if (((char)param_1[0x41] != '\0') &&
       (fVar7 = (float10)FUN_0058957a(), (float10)_DAT_0059e450 < fVar7)) {
      FUN_004d0ec0(4);
      return;
    }
    FUN_004d0ec0(1);
  }
  return;
}


