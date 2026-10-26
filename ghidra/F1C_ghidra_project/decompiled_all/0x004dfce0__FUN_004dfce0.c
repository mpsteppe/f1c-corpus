// Function: FUN_004dfce0 @ 004dfce0
// Strings:  [WHEEL, CATSTEER, LFTIRE, RFTIRE, RFTIRE, LRTIRE, LRTIRE, RRTIRE]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004dfce0(int *param_1,undefined4 param_2,char param_3)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int local_1ac;
  int local_1a8;
  int *local_1a4;
  int local_1a0;
  int local_19c;
  float local_198;
  float local_194;
  float local_190;
  float local_18c;
  float local_188;
  float local_184;
  undefined1 local_180 [64];
  undefined1 local_140 [32];
  int aiStack_120 [8];
  undefined1 local_100 [256];
  
  local_100[0] = 0;
  local_140[0] = 0;
  iVar4 = FUN_0055b6b0(param_2);
  if (iVar4 != 0) {
    FUN_0053c5b0(0,local_100);
    cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehgf_005d4ce0,0x6a1);
    if (cVar3 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Unable_to_read__s___s_005d4e2c,param_2,local_100);
    }
  }
  if (param_3 != '\0') {
    iVar4 = FUN_00543fa0();
    if (iVar4 != 0) {
      FUN_0053c5b0(0,local_100);
      cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehgf_005d4ce0,0x6ac);
      if (cVar3 != '\0') {
        FUN_004d7aa0(&DAT_008ad25c,s_Unable_to_setup_after_reading__s_005d4e04,param_2,local_100);
      }
    }
    FUN_004e2a60();
    FUN_004cef30();
  }
  FUN_0058815f(local_140,s_SLOT_03d_005d4df8,*(undefined4 *)(*param_1 + 0x4894));
  iVar4 = FUN_005453a0(local_140,0);
  piVar5 = param_1 + 1;
  *piVar5 = iVar4;
  if ((iVar4 == 0) &&
     (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehgf_005d4ce0,0x6bc), cVar3 != '\0')) {
    FUN_004d7aa0(&DAT_008ad25c,s_Could_not_find_instance___s__005d4dd8,local_140);
  }
  FUN_0054c030(1,1,0,0);
  FUN_004dfa60(0,0,9);
  FUN_0054c110(*(undefined4 *)(*param_1 + 0x4894),0x800);
  FUN_004dd550(param_1 + 0x21);
  FUN_0054fb40(0);
  piVar10 = param_1 + 0x51;
  iVar4 = FUN_005453a0(s_LFTIRE_005c6754,*piVar5);
  *piVar10 = iVar4;
  iVar4 = FUN_005453a0(s_LFSPINDLE_005d4dcc,*piVar5);
  param_1[0x62] = iVar4;
  iVar4 = FUN_005453a0(s_RFTIRE_005c675c,*piVar5);
  param_1[0x9b] = iVar4;
  iVar4 = FUN_005453a0(s_RFSPINDLE_005d4dc0,*piVar5);
  param_1[0xac] = iVar4;
  iVar4 = FUN_005453a0(s_LRTIRE_005c6764,*piVar5);
  param_1[0xe5] = iVar4;
  iVar4 = FUN_005453a0(s_LRSPINDLE_005d4db4,*piVar5);
  param_1[0xf6] = iVar4;
  iVar4 = FUN_005453a0(s_RRTIRE_005c676c,*piVar5);
  param_1[0x12f] = iVar4;
  iVar4 = FUN_005453a0(s_RRSPINDLE_005d4da8,*piVar5);
  param_1[0x140] = iVar4;
  iVar4 = 4;
  do {
    FUN_004e2ad0(*piVar10,piVar10[0x11]);
    piVar10 = piVar10 + 0x4a;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_1a4 = param_1 + 99;
  local_1ac = 4;
  do {
    piVar5 = local_1a4;
    FUN_004dfa60(1,0,3);
    FUN_004dfa60(1,0,5);
    if (piVar5[-1] == 0) {
      *piVar5 = piVar5[-0x11];
      piVar5[1] = piVar5[-0x10];
      piVar5[2] = piVar5[-0xf];
      piVar5[3] = piVar5[-0xe];
      iVar4 = piVar5[-0xc];
      piVar5[4] = piVar5[-0xd];
      piVar10 = piVar5 + -0xb;
      piVar11 = piVar5 + 6;
      for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
        *piVar11 = *piVar10;
        piVar10 = piVar10 + 1;
        piVar11 = piVar11 + 1;
      }
      piVar5[5] = iVar4;
    }
    piVar5[0x17] = 0;
    piVar5[0x15] = 0;
    piVar5[0x16] = 0;
    local_1a0 = 0;
    do {
      if (local_1a0 == 0) {
        piVar5 = local_1a4 + -1;
      }
      else {
        piVar5 = local_1a4 + -0x12;
      }
      local_1a8 = *piVar5;
      if (local_1a8 != 0) {
        local_19c = FUN_0054c210();
joined_r0x004e0032:
        local_19c = local_19c + -1;
        if (-1 < local_19c) {
          iVar4 = FUN_0054c230(local_19c);
          iVar8 = FUN_0054e190();
          iVar12 = 0;
          if (0 < iVar8) {
            do {
              iVar6 = FUN_0054e240(iVar12);
              if (iVar6 != 0) {
                local_180[0] = 0;
                FUN_00547370(local_180);
                iVar6 = FUN_00588410(local_180,s_DISCGLOW_005d4d9c);
                if (iVar6 == 0) {
                  if (local_1a4[0x15] == 0) {
                    local_1a4[0x15] = iVar4;
                  }
                  else {
                    local_1a4[0x16] = iVar4;
                    local_19c = 0;
                    local_1a0 = 1;
                  }
                  break;
                }
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar8);
          }
          goto joined_r0x004e0032;
        }
      }
      local_1a0 = local_1a0 + 1;
    } while (local_1a0 < 2);
    local_1a4 = local_1a4 + 0x4a;
    local_1ac = local_1ac + -1;
  } while (local_1ac != 0);
  iVar4 = FUN_005453a0(s_FWING_005d4d94,param_1[1]);
  param_1[0x179] = iVar4;
  FUN_004dfa60(1,1,4);
  iVar4 = FUN_005453a0(s_RWING_005d4d8c,param_1[1]);
  param_1[0x18a] = iVar4;
  FUN_004dfa60(1,1,4);
  iVar4 = 0;
  piVar5 = param_1 + 0x19b;
  do {
    FUN_0058815f(local_180,s_DEBRIS_d_005d4d80,iVar4);
    iVar8 = FUN_005453a0(local_180,param_1[1]);
    *piVar5 = iVar8;
    FUN_004dfa60(1,1,5);
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 0x11;
  } while (iVar4 < 8);
  iVar4 = FUN_005453a0(s_COCKPIT_005c677c,param_1[1]);
  param_1[0x223] = iVar4;
  iVar4 = FUN_005453a0(s_SUSPENSION_005d4d74,param_1[1]);
  param_1[0x224] = iVar4;
  iVar4 = FUN_005453a0(s_HELMET_005d4d6c,param_1[1]);
  param_1[0x225] = iVar4;
  iVar4 = FUN_005453a0(&DAT_005c674c,param_1[1]);
  param_1[0x226] = iVar4;
  iVar4 = FUN_005453a0(&DAT_005d4d64,param_1[1]);
  param_1[0x227] = iVar4;
  iVar4 = FUN_005453a0(s_WHEEL_005beb70,param_1[1]);
  param_1[0x228] = iVar4;
  iVar4 = FUN_005453a0(s_RAINLIGHT_005d4d58,param_1[1]);
  param_1[0x229] = iVar4;
  iVar4 = FUN_005453a0(s_BRAKELIGHT_005d4d4c,param_1[1]);
  param_1[0x22a] = iVar4;
  iVar4 = FUN_005453a0(s_HEADLIGHT_005d4d40,param_1[1]);
  param_1[0x22b] = iVar4;
  iVar4 = FUN_005453a0(s_BACKFIRE_005d4d34,param_1[1]);
  param_1[0x22c] = iVar4;
  param_1[0x24c] = 0;
  if (param_1[0x225] != 0) {
    FUN_0054b420(param_1 + 0x24c,&local_1ac,&local_1ac);
  }
  FUN_004e2d00();
  FUN_004e3360();
  param_1[0x18] = param_1[0x1e];
  param_1[0x19] = param_1[0x1f];
  param_1[0x1a] = param_1[0x20];
  piVar5 = param_1 + 0x1b;
  *piVar5 = param_1[0x21];
  param_1[0x1c] = param_1[0x22];
  param_1[0x1d] = param_1[0x23];
  piVar10 = param_1 + 0x62;
  local_1ac = 4;
  do {
    if (piVar10[-0x11] != 0) {
      FUN_004dd6a0(piVar5);
    }
    if (*piVar10 != 0) {
      FUN_004dd6a0(piVar5);
    }
    piVar10 = piVar10 + 0x4a;
    local_1ac = local_1ac + -1;
  } while (local_1ac != 0);
  if (param_1[0x179] != 0) {
    FUN_004dd6a0(piVar5);
  }
  if (param_1[0x18a] != 0) {
    FUN_004dd6a0(piVar5);
  }
  param_1[0x22d] = 0;
  if (param_1[0x226] != 0) {
    iVar4 = FUN_0054c210();
    param_1[0x22d] = iVar4;
    if (2 < iVar4) {
      param_1[0x22d] = 2;
    }
    iVar4 = 0;
    if (0 < param_1[0x22d]) {
      piVar5 = param_1 + 0x22e;
      do {
        iVar8 = FUN_0054c230(iVar4);
        *piVar5 = iVar8;
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < param_1[0x22d]);
    }
  }
  param_1[0x230] = 0;
  if ((0 < param_1[0x22d]) && (iVar4 = 0, 0 < param_1[0x22d])) {
    piVar5 = param_1 + 0x231;
    do {
      iVar8 = FUN_00551830(s_CATSTEER_005c6740);
      *piVar5 = iVar8;
      if (iVar8 != 0) {
        param_1[0x230] = param_1[0x230] + 1;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 4;
    } while (iVar4 < param_1[0x22d]);
  }
  iVar4 = *(int *)(*param_1 + 0x4898) * 0x424 + DAT_008ac394;
  param_1[0x23a] = *(int *)(iVar4 + 0x44);
  param_1[0x23b] = *(int *)(iVar4 + 0x48);
  param_1[0x23c] = *(int *)(iVar4 + 0x4c);
  param_1[0x23d] = *(int *)(iVar4 + 0x38);
  param_1[0x23e] = *(int *)(iVar4 + 0x3c);
  param_1[0x23f] = *(int *)(iVar4 + 0x40);
  param_1[0x240] = 0;
  param_1[0x241] = 0;
  param_1[0x242] = 0;
  param_1[0x243] = 0;
  param_1[0x244] = 0;
  param_1[0x245] = 0;
  param_1[0x254] = 0;
  param_1[0x246] = *(int *)(iVar4 + 0x50);
  param_1[0x247] = *(int *)(iVar4 + 0x54);
  param_1[0x248] = *(int *)(iVar4 + 0x58);
  param_1[0x249] = *(int *)(iVar4 + 0x5c);
  param_1[0x24a] = *(int *)(iVar4 + 0x60);
  param_1[0x24b] = *(int *)(iVar4 + 100);
  param_1[0x256] = *(int *)(iVar4 + 0x68);
  param_1[599] = *(int *)(iVar4 + 0x6c);
  param_1[600] = *(int *)(iVar4 + 0x70);
  piVar5 = param_1 + 0x77;
  local_1ac = 4;
  do {
    piVar5[-3] = 0;
    if (piVar5[-0x26] != 0) {
      FUN_0054b420(piVar5 + -2,piVar5 + -1,piVar5);
      FUN_004dd550(piVar5 + -0x3f);
      fVar2 = ((float)piVar5[-0x3f] - (float)piVar5[-0x42]) * _DAT_005ad14c;
      piVar5[4] = 0;
      piVar5[-0x3c] = (int)fVar2;
      FUN_005506a0(0,0,0);
    }
    iVar4 = 0;
    piVar5 = piVar5 + 0x4a;
    local_1ac = local_1ac + -1;
  } while (local_1ac != 0);
  param_1[0x24d] = 0;
  param_1[0x24e] = 0;
  param_1[0x24f] = 0;
  param_1[0x250] = 0;
  param_1[0x251] = 0;
  *(undefined2 *)(param_1 + 0x252) = 0;
  param_1[0x254] = 0;
  FUN_004e0c90(0);
  param_1[0x2db] = 0;
  DAT_008ad3ec = 0;
  DAT_008ad3f0 = 0;
  _DAT_008ad3f4 = 0;
  iVar8 = FUN_00545f40();
  if (iVar8 != 0) {
    DAT_008ad3ec = FUN_00548890(s_TREAD_005d4d2c);
    DAT_008ad3f0 = FUN_00548890(s_TREADMED_005d4d20);
    _DAT_008ad3f4 = FUN_00548890(s_TREADLOW_005d4d14);
  }
  *(undefined1 *)(param_1 + 0x25b) = 1;
  *(undefined1 *)((int)param_1 + 0x96d) = 1;
  *(undefined1 *)((int)param_1 + 0x979) = 0;
  uVar9 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  fVar2 = *(float *)(&DAT_008ab274 + uVar9 * 4) * _DAT_0059ed18 + _DAT_0059e43c;
  *(undefined1 *)((int)param_1 + 0x975) = 0;
  *(undefined1 *)((int)param_1 + 0x976) = 1;
  fVar2 = fVar2 * _DAT_0059e854;
  *(undefined1 *)((int)param_1 + 0x977) = 0;
  *(undefined1 *)(param_1 + 0x25e) = 1;
  param_1[0x25f] = (int)fVar2;
  param_1[0x25c] = 0x3f800000;
  FUN_00411570(*(undefined4 *)(*param_1 + 0x4894),1);
  for (iVar8 = *(int *)(param_1[1] + 0x44); iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x4c)) {
    FUN_0054bda0(local_180);
    iVar12 = FUN_00587c20(local_180,&PTR_LAB_005d4d10);
    if ((iVar12 != 0) && (iVar12 = FUN_00587c20(local_180,&DAT_005d4d08), iVar12 != 0)) {
      iVar12 = param_1[0xaf4];
      aiStack_120[iVar12] = iVar8;
      iVar12 = iVar12 + 1;
      param_1[0xaf4] = iVar12;
      if (iVar12 == 8) break;
    }
  }
  if (0 < param_1[0xaf4]) {
    pvVar7 = operator_new(param_1[0xaf4] * 0x14);
    param_1[0xaf5] = (int)pvVar7;
    local_1a8 = 0;
    if (0 < param_1[0xaf4]) {
      do {
        iVar8 = aiStack_120[local_1a8];
        FUN_0054bda0(local_180);
        FUN_0054b420(&local_198,&local_194,&local_190);
        iVar6 = 0;
        iVar12 = FUN_00587c20(local_180,s_RFTIRE_005c675c);
        if (iVar12 == 0) {
          iVar12 = FUN_00587c20(local_180,s_LRTIRE_005c6764);
          if (iVar12 == 0) {
            iVar12 = FUN_00587c20(local_180,s_RRTIRE_005c676c);
            if (iVar12 != 0) {
              iVar6 = 3;
            }
          }
          else {
            iVar6 = 2;
          }
        }
        else {
          iVar6 = 1;
        }
        *(int *)(iVar4 + 0x10 + param_1[0xaf5]) = iVar8;
        *(int *)(iVar4 + param_1[0xaf5]) = iVar6;
        local_18c = local_198 - (float)param_1[iVar6 * 0x4a + 0x52];
        local_188 = local_194 - (float)param_1[iVar6 * 0x4a + 0x53];
        local_184 = local_190 - (float)param_1[iVar6 * 0x4a + 0x54];
        pfVar1 = (float *)(iVar4 + 4 + param_1[0xaf5]);
        *pfVar1 = local_18c;
        pfVar1[1] = local_188;
        pfVar1[2] = local_184;
        local_1a8 = local_1a8 + 1;
        iVar4 = iVar4 + 0x14;
      } while (local_1a8 < param_1[0xaf4]);
    }
  }
  return;
}


