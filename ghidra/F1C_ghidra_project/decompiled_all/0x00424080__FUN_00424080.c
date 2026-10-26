// Function: FUN_00424080 @ 00424080
// Strings:  [Gearbox, Gearbox, Engine, Engine, Brakes, Brakes, Suspension, Suspension]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_00424080(int *param_1)

{
  char cVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  char *pcVar9;
  bool bVar10;
  float10 fVar11;
  float local_c;
  float local_8;
  
  iVar4 = FUN_00568210(*param_1 + 0x4620);
  piVar8 = param_1 + 0x1138;
  param_1[0x1131] = 0x40400000;
  param_1[0x1132] = 0x40400000;
  pcVar5 = s_default_scp_005c3254;
  local_c = 0.0;
  local_8 = 0.0;
  param_1[0x112f] = 0x40000000;
  param_1[0x1130] = 0x3f000000;
  param_1[0x1133] = 0x42480000;
  param_1[0x1134] = 0x41200000;
  param_1[0x1137] = 0x42700000;
  do {
    cVar1 = *pcVar5;
    pcVar5[(int)(param_1 + -0x16fb5d)] = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  param_1[0x113d] = 0x3f800000;
  param_1[0x113e] = 0x3f800000;
  iVar6 = _rand();
  param_1[0x1140] = 0x3fc00000;
  param_1[0x1141] = 0x3f770a3d;
  param_1[0x113f] = iVar6 % 3;
  if (iVar4 != 0) {
    iVar4 = FUN_005679c0(s_StartsDry_005c3248);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      local_c = (float)fVar11;
    }
    iVar4 = FUN_005679c0(s_StartsWet_005c323c);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      local_8 = (float)fVar11;
    }
    iVar4 = FUN_005679c0(s_StartStalls_005c3230);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x112f] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_QualifyingAbility_005c321c);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x1130] = (int)(float)(((float10)_DAT_0059e85c - fVar11) * (float10)_DAT_0059e858);
    }
    iVar4 = FUN_005679c0(s_TrackAggression_005c320c);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x113e] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_RainAbility_005c3200);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x1132] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_RaceAbility_005c31f4);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x1131] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_Passing_005c31ec);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x1133] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_CorneringAdd_005c31dc);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x1140] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_CorneringMult_005c31cc);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x1141] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_Crash_005c31c4);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x1134] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_CompletedLaps__005c31b4);
    if (iVar4 != 0) {
      uVar7 = FUN_00567970();
      fVar11 = (float10)FUN_0058850f(uVar7);
      param_1[0x1137] = (int)(float)fVar11;
    }
    iVar4 = FUN_005679c0(s_Script_005c31ac);
    if (iVar4 != 0) {
      pcVar5 = (char *)FUN_00567970();
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        *(char *)piVar8 = cVar1;
        piVar8 = (int *)((int)piVar8 + 1);
      } while (cVar1 != '\0');
    }
  }
  fVar2 = _DAT_007d017c * (float)param_1[0x113e];
  param_1[0x113e] = (int)fVar2;
  if (fVar2 < _DAT_0059e444) {
    param_1[0x113e] = 0x3c23d70a;
  }
  fVar2 = (float)param_1[0x1132] * _DAT_0059e444 * _DAT_005ea3d8;
  param_1[0x1132] = (int)fVar2;
  param_1[0x1160] = (int)(_DAT_0059e43c - _DAT_008afee8 * fVar2);
  fVar2 = (_DAT_0059e43c - (float)param_1[0x1131] * _DAT_0059e444) * _DAT_005ea3d8;
  param_1[0x113d] = (int)fVar2;
  param_1[0x1136] = (int)((_DAT_0059e43c - fVar2) * _DAT_0059e854);
  param_1[0x1135] = (int)((_DAT_0059e85c - (float)param_1[0x1131] * _DAT_0059e854) * _DAT_0059e858);
  fVar2 = (_DAT_0059e85c - (float)param_1[0x1131]) * _DAT_0059e858;
  param_1[0x1131] = (int)fVar2;
  if (DAT_007d01a0 < 100) {
    param_1[0x1131] =
         (int)((float)DAT_007d01a0 * _DAT_0059e444 * (float)DAT_007d01a0 * _DAT_0059e444 * fVar2);
  }
  FUN_0042ad00(100);
  fVar2 = (float)param_1[0x1133] * _DAT_0059e600 + _DAT_0059e824;
  param_1[0x1133] = (int)fVar2;
  if (_DAT_0059e43c < fVar2) {
    param_1[0x1133] = 0x3f800000;
  }
  param_1[0x112e] = (int)(_DAT_008afee8 * local_8 + (_DAT_0059e43c - _DAT_008afee8) * local_c);
  iVar4 = _rand();
  fVar2 = (float)(iVar4 % 200) * _DAT_0059e444 + (float)param_1[0x112e];
  bVar10 = _DAT_0059e850 <= fVar2;
  param_1[0x112e] = (int)fVar2;
  if (bVar10) {
    if (_DAT_0059e46c < fVar2) {
      param_1[0x112e] = 0x40800000;
    }
  }
  else {
    param_1[0x112e] = -0x3f800000;
  }
  param_1[0x112e] = (int)((float)param_1[0x112e] * _DAT_0059e84c + _DAT_0059e43c);
  fVar11 = (float10)FUN_00424750();
  param_1[0x115f] = (int)(float)fVar11;
  iVar4 = DAT_007c56a4;
  if ((DAT_007c56a4 == 7) && (iVar4 = DAT_007cea5c, 0 < DAT_007cea5c)) {
    if (DAT_007cea5c < 3) {
      fVar3 = (float)param_1[0x112f] * _DAT_0059e6f8;
      iVar4 = _rand();
      fVar2 = (float)(iVar4 % 10000);
      iVar4 = CONCAT22((short)((uint)(iVar4 / 10000) >> 0x10),
                       (ushort)(fVar2 < fVar3) << 8 | (ushort)(NAN(fVar2) || NAN(fVar3)) << 10 |
                       (ushort)(fVar2 == fVar3) << 0xe);
      if (fVar2 < fVar3) {
        iVar6 = _rand();
        iVar4 = iVar6 / 10;
        if (iVar6 % 10 == 0) {
          param_1[0x1051] = 0;
          param_1[0x1052] = 4;
          return iVar4;
        }
        param_1[0x1052] = 5;
        param_1[0x1051] = 0;
      }
    }
    else if (DAT_007cea5c == 3) {
      iVar6 = FUN_004c5840(0);
      iVar4 = 0;
      if (iVar6 != 0) {
        iVar6 = FUN_005679c0(s_RaceEvents_005c31a0);
        iVar4 = 0;
        if (iVar6 != 0) {
          iVar6 = FUN_005679c0(*param_1 + 0x4620);
          iVar4 = 0;
          if (iVar6 != 0) {
            local_8 = 0.0;
            iVar6 = thunk_FUN_0059d6a9(0);
            iVar4 = 0;
            if (iVar6 != 0) {
              param_1 = param_1 + 0x1052;
              do {
                *param_1 = 6;
                pcVar5 = (char *)FUN_00567970();
                iVar4 = 6;
                bVar10 = true;
                pcVar9 = s_Stall_005c3198;
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar10 = *pcVar5 == *pcVar9;
                  pcVar5 = pcVar5 + 1;
                  pcVar9 = pcVar9 + 1;
                } while (bVar10);
                if (bVar10) {
                  *param_1 = 4;
                  goto LAB_00424681;
                }
                pcVar5 = (char *)FUN_00567970();
                iVar4 = 0xc;
                bVar10 = true;
                pcVar9 = s_Stall___DNS_005c318c;
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar10 = *pcVar5 == *pcVar9;
                  pcVar5 = pcVar5 + 1;
                  pcVar9 = pcVar9 + 1;
                } while (bVar10);
                if (bVar10) {
LAB_00424672:
                  *param_1 = 5;
LAB_00424681:
                  uVar7 = FUN_00499e20(0,10);
                  iVar4 = FUN_00589278(uVar7);
                  param_1[-1] = iVar4;
                  iVar4 = __ftol();
                  param_1[-1] = iVar4;
                }
                else {
                  pcVar5 = (char *)FUN_00567970();
                  iVar4 = 4;
                  bVar10 = true;
                  pcVar9 = &DAT_005c3188;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar10 = *pcVar5 == *pcVar9;
                    pcVar5 = pcVar5 + 1;
                    pcVar9 = pcVar9 + 1;
                  } while (bVar10);
                  if (bVar10) goto LAB_00424672;
                  pcVar5 = (char *)FUN_00567970();
                  iVar4 = 0xb;
                  bVar10 = true;
                  pcVar9 = s_Suspension_005c317c;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar10 = *pcVar5 == *pcVar9;
                    pcVar5 = pcVar5 + 1;
                    pcVar9 = pcVar9 + 1;
                  } while (bVar10);
                  if (bVar10) {
                    *param_1 = 3;
                    goto LAB_00424681;
                  }
                  pcVar5 = (char *)FUN_00567970();
                  iVar4 = 7;
                  bVar10 = true;
                  pcVar9 = s_Brakes_005c3174;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar10 = *pcVar5 == *pcVar9;
                    pcVar5 = pcVar5 + 1;
                    pcVar9 = pcVar9 + 1;
                  } while (bVar10);
                  if (bVar10) {
                    *param_1 = 1;
                    goto LAB_00424681;
                  }
                  pcVar5 = (char *)FUN_00567970();
                  iVar4 = 7;
                  bVar10 = true;
                  pcVar9 = s_Engine_005c316c;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar10 = *pcVar5 == *pcVar9;
                    pcVar5 = pcVar5 + 1;
                    pcVar9 = pcVar9 + 1;
                  } while (bVar10);
                  if (bVar10) {
                    *param_1 = 0;
                    goto LAB_00424681;
                  }
                  pcVar5 = (char *)FUN_00567970();
                  iVar4 = 8;
                  bVar10 = true;
                  pcVar9 = s_Gearbox_005c3164;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar10 = *pcVar5 == *pcVar9;
                    pcVar5 = pcVar5 + 1;
                    pcVar9 = pcVar9 + 1;
                  } while (bVar10);
                  if (bVar10) {
                    *param_1 = 2;
                    goto LAB_00424681;
                  }
                  if (*param_1 != 6) goto LAB_00424681;
                  param_1[-1] = -1;
                }
                local_8 = (float)((int)local_8 + 1);
                param_1 = param_1 + 2;
                iVar4 = thunk_FUN_0059d6a9(local_8);
                if (iVar4 == 0) {
                  return 0;
                }
              } while( true );
            }
          }
        }
      }
    }
  }
  return iVar4;
}


