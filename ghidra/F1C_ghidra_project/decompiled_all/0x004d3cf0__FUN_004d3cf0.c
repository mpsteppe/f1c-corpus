// Function: FUN_004d3cf0 @ 004d3cf0
// Strings:  [RaceTime, RaceTime, D:\dev\F1_1999_2002\Source\steward.cpp, PreRacePresentation, Duration, RaceTimeScaled, RaceTimeScaled, %d:%d:%f]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d3cf0(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int extraout_EDX;
  float fVar6;
  char *pcVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float local_158;
  float local_154;
  int local_150;
  char *local_14c;
  int local_148;
  int local_144;
  char local_140 [64];
  char local_100 [64];
  char local_c0 [64];
  char local_80 [64];
  char local_40 [64];
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x9b1);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_Steward__Restart___005d4390);
  }
  *(undefined1 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x120) = 0;
  FUN_004d1cd0(0);
  FUN_004d0ec0(1);
  FUN_004d0ec0(2);
  *(undefined1 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0xce6e6b28;
  if (0 < *(int *)(param_1 + 0x10c)) {
    do {
      FUN_004d0f00(0);
      *(undefined4 *)(*(int *)(param_1 + 0x114) + extraout_EDX * 4) = 0;
    } while (extraout_EDX + 1 < *(int *)(param_1 + 0x10c));
  }
  *(undefined4 *)(param_1 + 0xd8) = 0x7f7fffff;
  *(undefined1 *)(param_1 + 0xc1) = 0;
  *(undefined1 *)(param_1 + 0xc2) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  local_14c = (char *)FUN_0042ce30();
  pcVar2 = local_14c;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_100 + -(int)local_14c)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar5 = -1;
  pcVar2 = local_100;
  do {
    pcVar7 = pcVar2;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar7 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar7;
  } while (cVar1 != '\0');
  *(undefined **)(pcVar7 + -1) = PTR_DAT_005d438c;
  pcVar2 = local_14c;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_c0 + -(int)local_14c)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar5 = -1;
  pcVar2 = local_c0;
  do {
    pcVar7 = pcVar2;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar7 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar7;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar7 + -1) = s_Start_005d4384._0_4_;
  *(undefined2 *)(pcVar7 + 3) = s_Start_005d4384._4_2_;
  if (((DAT_007c56a4 == 0) || (DAT_007c56a4 == 6)) || (DAT_007c56a4 == 7)) {
    iVar5 = 0;
    do {
      cVar1 = s_RacePitKPH_005d4368[iVar5];
      local_80[iVar5] = cVar1;
      iVar5 = iVar5 + 1;
    } while (cVar1 != '\0');
  }
  else {
    iVar5 = 0;
    do {
      cVar1 = s_NormalPitKPH_005d4374[iVar5];
      local_80[iVar5] = cVar1;
      iVar5 = iVar5 + 1;
    } while (cVar1 != '\0');
  }
  pcVar2 = s_Wednesday_005d435c;
  *(undefined4 *)(param_1 + 0xd4) = 0x41b1c71c;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 + -0x5d4299] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)(param_1 + 0xd0) = 0x46fd2000;
  local_150 = FUN_00568210(s_DefaultScoring_005d434c);
  if (local_150 != 0) {
    iVar5 = FUN_005679c0(local_80);
    if (iVar5 != 0) {
      uVar3 = FUN_00567970();
      fVar9 = (float10)FUN_0058850f(uVar3);
      *(float *)(param_1 + 0xd4) = (float)(fVar9 * (float10)_DAT_005acf00);
    }
    iVar5 = FUN_005679c0(local_100);
    if (iVar5 != 0) {
      pcVar2 = (char *)FUN_00567970();
      _strncpy((char *)(param_1 + 0xc3),pcVar2,0xb);
      *(undefined1 *)(param_1 + 0xce) = 0;
    }
    iVar5 = FUN_005679c0(local_c0);
    if (iVar5 != 0) {
      local_158 = 0.0;
      uVar3 = FUN_00567970(s__d__d__f_005d4340,&local_148,&local_154,&local_158);
      iVar5 = FUN_005887ed(uVar3);
      if (1 < iVar5) {
        *(float *)(param_1 + 0xd0) =
             (float)(int)local_154 * (float)_DAT_0059e9c8 + (float)local_148 * (float)_DAT_0059fb48
             + local_158;
      }
    }
    iVar5 = FUN_005679c0(s_RaceTime_005d2310);
    if (iVar5 != 0) {
      uVar3 = FUN_00567970(&DAT_005d433c,&local_154);
      iVar5 = FUN_005887ed(uVar3);
      if (iVar5 == 1) {
        *(float *)(param_1 + 0xb8) = local_154 * _DAT_0059f118;
      }
    }
    iVar5 = FUN_005679c0(s_RaceTimeScaled_005d432c);
    if (iVar5 != 0) {
      uVar3 = FUN_00567970(&DAT_005d433c,&local_154);
      iVar5 = FUN_005887ed(uVar3);
      if (iVar5 == 1) {
        *(float *)(param_1 + 0xb8) = DAT_007d0798 * local_154 * _DAT_0059f118;
      }
    }
  }
  iVar5 = FUN_004c5840(0);
  local_144 = iVar5;
  if (iVar5 != 0) {
    iVar4 = FUN_005679c0(local_80);
    if (iVar4 != 0) {
      uVar3 = FUN_00567970();
      fVar9 = (float10)FUN_0058850f(uVar3);
      *(float *)(param_1 + 0xd4) = (float)(fVar9 * (float10)_DAT_005acf00);
    }
    iVar4 = FUN_005679c0(local_100);
    if (iVar4 != 0) {
      pcVar2 = (char *)FUN_00567970();
      _strncpy((char *)(param_1 + 0xc3),pcVar2,0xb);
      *(undefined1 *)(param_1 + 0xce) = 0;
    }
    iVar4 = FUN_005679c0(local_c0);
    if (iVar4 != 0) {
      local_158 = 0.0;
      uVar3 = FUN_00567970(s__d__d__f_005d4340,&local_154,&local_148,&local_158);
      iVar4 = FUN_005887ed(uVar3);
      if (1 < iVar4) {
        *(float *)(param_1 + 0xd0) =
             (float)local_148 * (float)_DAT_0059e9c8 + (float)(int)local_154 * (float)_DAT_0059fb48
             + local_158;
      }
    }
    iVar4 = FUN_005679c0(s_RaceTime_005d2310);
    if (iVar4 != 0) {
      uVar3 = FUN_00567970(&DAT_005d433c,&local_154);
      iVar4 = FUN_005887ed(uVar3);
      if (iVar4 == 1) {
        *(float *)(param_1 + 0xb8) = local_154 * _DAT_0059f118;
      }
    }
    iVar4 = FUN_005679c0(s_RaceTimeScaled_005d432c);
    if (iVar4 != 0) {
      uVar3 = FUN_00567970(&DAT_005d433c,&local_154);
      iVar4 = FUN_005887ed(uVar3);
      if (iVar4 == 1) {
        *(float *)(param_1 + 0xb8) = DAT_007d0798 * local_154 * _DAT_0059f118;
      }
    }
  }
  switch(DAT_007c56a4) {
  case 0:
    FUN_0042d140(5);
    *(undefined4 *)(param_1 + 0xac) = 0x7fffffff;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0x7f7fffff;
    uVar3 = 1;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    FUN_0042d140(0);
    *(undefined4 *)(param_1 + 0xb0) = 0x41f00000;
    FUN_004d0ec0(2);
    if (DAT_007c56a4 == 5) {
      *(undefined4 *)(param_1 + 0xac) = DAT_007d04a4;
    }
    else {
      *(undefined4 *)(param_1 + 0xac) = 0x7fffffff;
    }
    switch(DAT_007c56a4) {
    case 1:
    case 2:
    case 5:
      local_158 = 3600.0;
      break;
    case 3:
    case 4:
      local_158 = 2700.0;
      break;
    case 6:
      local_158 = 1800.0;
    }
    pcVar2 = local_14c;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_40 + -(int)local_14c)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    iVar4 = -1;
    pcVar2 = local_40;
    do {
      pcVar7 = pcVar2;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar7 + -1) = s_Duration_005d4320._0_4_;
    *(undefined4 *)(pcVar7 + 3) = s_Duration_005d4320._4_4_;
    pcVar7[7] = s_Duration_005d4320[8];
    pcVar2 = local_14c;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_140 + -(int)local_14c)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    iVar4 = -1;
    pcVar2 = local_140;
    do {
      pcVar7 = pcVar2;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar7 + -1) = _DAT_005c32fc;
    pcVar7[3] = DAT_005c3300;
    if (local_150 != 0) {
      iVar4 = FUN_005679c0(local_40);
      if (iVar4 != 0) {
        uVar3 = FUN_00567970();
        fVar9 = (float10)FUN_0058850f(uVar3);
        local_158 = (float)(fVar9 * (float10)_DAT_0059f118);
      }
      iVar4 = FUN_005679c0(local_140);
      if (iVar4 != 0) {
        uVar3 = FUN_00567970();
        uVar3 = FUN_00587ece(uVar3);
        *(undefined4 *)(param_1 + 0xac) = uVar3;
      }
    }
    if (iVar5 != 0) {
      iVar5 = FUN_005679c0(local_40);
      if (iVar5 != 0) {
        uVar3 = FUN_00567970();
        fVar9 = (float10)FUN_0058850f(uVar3);
        local_158 = (float)(fVar9 * (float10)_DAT_0059f118);
      }
      iVar5 = FUN_005679c0(local_140);
      if (iVar5 != 0) {
        uVar3 = FUN_00567970();
        uVar3 = FUN_00587ece(uVar3);
        *(undefined4 *)(param_1 + 0xac) = uVar3;
      }
    }
    *(float *)(param_1 + 0xb4) = local_158 + *(float *)(param_1 + 0xb0);
    goto switchD_004d4162_default;
  case 7:
    FUN_0040da30();
    FUN_0040dc00();
    FUN_0040dcd0(s_PreRacePresentation_005d430c);
    fVar6 = -NAN;
    local_158 = -NAN;
    pcVar2 = local_14c;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_140 + -(int)local_14c)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    iVar5 = -1;
    pcVar2 = local_140;
    do {
      pcVar7 = pcVar2;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar7 + -1) = _DAT_005c32fc;
    pcVar7[3] = DAT_005c3300;
    if ((local_150 != 0) && (iVar5 = FUN_005679c0(local_140), iVar5 != 0)) {
      uVar3 = FUN_00567970();
      fVar6 = (float)FUN_00587ece(uVar3);
      local_158 = fVar6;
    }
    if ((local_144 != 0) && (iVar5 = FUN_005679c0(local_140), iVar5 != 0)) {
      uVar3 = FUN_00567970();
      fVar6 = (float)FUN_00587ece(uVar3);
      local_158 = fVar6;
    }
    *(undefined4 *)(param_1 + 0xac) = DAT_007d05a0;
    *(undefined4 *)(param_1 + 0x11c) = DAT_007d0894;
    if (fVar6 != -NAN) {
      *(float *)(param_1 + 0xbc) = (float)(int)local_158 / (float)*(int *)(param_1 + 0xac);
    }
    if (DAT_007cec90 != 0) {
      FUN_0042d140(0);
      *(undefined4 *)(param_1 + 0xb0) = 0x41f00000;
      *(float *)(param_1 + 0xb4) = (float)_DAT_007cec30 + (float)_DAT_007cec54 + _DAT_0059e468;
      FUN_004d0ec0(2);
      FUN_004d2dd0();
      goto switchD_004d4162_default;
    }
    if (DAT_007ced8c != 0) {
      FUN_0042d140(2);
      *(undefined4 *)(param_1 + 0xb0) = 0;
      *(undefined4 *)(param_1 + 0xb4) = 0x43960000;
      FUN_004d0ec0(2);
      FUN_004d2dd0();
      goto switchD_004d4162_default;
    }
    if (DAT_007cee88 == 0) {
      *(undefined1 *)(param_1 + 0xc2) = 0;
      FUN_0042d140(4);
      *(undefined4 *)(param_1 + 0xd8) = 0x7f7fffff;
      *(undefined4 *)(param_1 + 0xb0) = 0x7f7fffff;
      *(undefined4 *)(param_1 + 0xb4) = 0x7f7fffff;
    }
    else {
      FUN_0042d140(3);
      *(undefined4 *)(param_1 + 0xb0) = 0;
      *(undefined4 *)(param_1 + 0xb4) = 0;
    }
    uVar3 = 2;
    break;
  default:
    goto switchD_004d4162_default;
  }
  FUN_004d0ec0(uVar3);
switchD_004d4162_default:
  puVar8 = (undefined4 *)(param_1 + 0x128);
  for (iVar5 = 0x1a; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = 0xffffffff;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)(param_1 + 400) = 0xffff;
  *(undefined1 *)(param_1 + 0x192) = 0xff;
  FUN_004c29f0();
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_00448300();
  }
  return;
}


