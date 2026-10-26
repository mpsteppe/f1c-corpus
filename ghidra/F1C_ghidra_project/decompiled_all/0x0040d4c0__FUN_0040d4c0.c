// Function: FUN_0040d4c0 @ 0040d4c0
// Strings:  [CROWD, WEATHER, TRACK_INFO, WELCOME_TO_COUNTRY, GREETING, Commentary, <PLAYER>, Driver]


uint __thiscall FUN_0040d4c0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  FUN_0040d490();
  *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  *(int *)(param_1 + 4) = param_2;
  if ((param_2 == 0) || (iVar1 = FUN_005679c0(&DAT_005beb08), iVar1 == 0)) goto LAB_0040d91d;
  uVar2 = FUN_00567970();
  iVar1 = FUN_00588410(uVar2,s_CAMERA_SELECT_005beaf8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x24) = 4;
  }
  else {
    iVar1 = FUN_00588410(uVar2,s_CAMERA_TARGET_SELECT_005beae0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x24) = 5;
    }
    else {
      iVar1 = FUN_00588410(uVar2,s_CAMERA_ACQUIRE_CONTROL_005beac8);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x24) = 2;
      }
      else {
        iVar1 = FUN_00588410(uVar2,s_CAMERA_RELEASE_CONTROL_005beab0);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x24) = 3;
        }
        else {
          iVar1 = FUN_00588410(uVar2,s_CAMERA_SET_LAST_005beaa0);
          if (iVar1 == 0) {
            *(undefined4 *)(param_1 + 0x24) = 6;
          }
          else {
            iVar1 = FUN_00588410(uVar2,s_COMMENTARY_START_005bea8c);
            if (iVar1 == 0) {
              *(undefined4 *)(param_1 + 0x24) = 7;
            }
            else {
              iVar1 = FUN_00588410(uVar2,s_COMMENTARY_STOP_005bea7c);
              if (iVar1 == 0) {
                *(undefined4 *)(param_1 + 0x24) = 8;
              }
              else {
                iVar1 = FUN_00588410(uVar2,s_FLY_OVER_005bea70);
                if (iVar1 == 0) {
                  *(undefined4 *)(param_1 + 0x24) = 9;
                }
                else {
                  iVar1 = FUN_00588410(uVar2,s_GRIDWALK_005bea64);
                  if (iVar1 == 0) {
                    *(undefined4 *)(param_1 + 0x24) = 10;
                  }
                  else {
                    iVar1 = FUN_00588410(uVar2,&DAT_005bea5c);
                    if (iVar1 == 0) {
                      *(undefined4 *)(param_1 + 0x24) = 0xb;
                    }
                    else {
                      iVar1 = FUN_00588410(uVar2,s_SCRIPT_END_005bea50);
                      if (iVar1 == 0) {
                        *(undefined4 *)(param_1 + 0x24) = 0xc;
                      }
                      else {
                        *(undefined4 *)(param_1 + 0x24) = 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    iVar1 = FUN_005679c0(s_Probability_005bea44);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0xc) = 0x3f800000;
    }
    else {
      uVar2 = FUN_00567970();
      fVar6 = (float10)FUN_0058850f(uVar2);
      *(float *)(param_1 + 0xc) = (float)fVar6;
    }
    iVar1 = FUN_005679c0(&DAT_005bea3c);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
LAB_0040d6b8:
      *(undefined4 *)(param_1 + 0x14) = 2;
    }
    else {
      uVar2 = FUN_00567970();
      fVar6 = (float10)FUN_0058850f(uVar2);
      *(float *)(param_1 + 0x10) = (float)fVar6;
      pcVar3 = (char *)FUN_00567970();
      if (*pcVar3 == '+') goto LAB_0040d6b8;
      *(undefined4 *)(param_1 + 0x14) = 1;
    }
    iVar1 = FUN_005679c0(s_Iterations_005bea30);
    if (iVar1 == 0) {
LAB_0040d6e4:
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
    else {
      uVar2 = FUN_00567970();
      iVar1 = FUN_00587ece(uVar2);
      *(int *)(param_1 + 0x18) = iVar1;
      if (iVar1 < 1) goto LAB_0040d6e4;
    }
    iVar1 = FUN_005679c0(&DAT_005bea28);
    if (iVar1 != 0) {
      uVar2 = FUN_00567970(&DAT_005bea24);
      iVar1 = FUN_00588410(uVar2);
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x20) = 0;
        goto LAB_0040d71e;
      }
    }
    *(undefined1 *)(param_1 + 0x20) = 1;
  }
LAB_0040d71e:
  switch(*(undefined4 *)(param_1 + 0x24)) {
  case 2:
  case 3:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
switchD_0040d72b_caseD_2:
    *(undefined4 *)(param_1 + 0x28) = 2;
    break;
  case 4:
  case 6:
    *(undefined4 *)(param_1 + 0x2c) = 0;
    iVar1 = FUN_005679c0(s_Camera_005bea1c);
    if (iVar1 != 0) {
      uVar2 = FUN_00567970();
      uVar2 = FUN_0040db00(uVar2);
      *(undefined4 *)(param_1 + 0x2c) = uVar2;
    }
    *(uint *)(param_1 + 0x28) = (uint)(*(int *)(param_1 + 0x2c) == 0) * 2 + 2;
    break;
  case 5:
    *(undefined4 *)(param_1 + 0x28) = 4;
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    iVar1 = FUN_005679c0(s_Position_005bea10);
    if (iVar1 == 0) {
      iVar1 = FUN_005679c0(s_Driver_005bea08);
      if (iVar1 != 0) {
        uVar2 = FUN_00567970(s_<PLAYER>_005be9fc);
        iVar1 = FUN_00588410(uVar2);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(DAT_007c54e8 + 0x4894);
          *(undefined4 *)(param_1 + 0x28) = 2;
        }
      }
    }
    else {
      uVar2 = FUN_00567970();
      iVar1 = FUN_00587f59(uVar2);
      if (((0 < iVar1) && (iVar1 <= DAT_005c329c)) && (iVar5 = 0, 0 < DAT_005c329c)) {
        do {
          if (iVar1 == *(int *)((&DAT_007c54f0)[iVar5] + 0x4060)) {
            *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)((&DAT_007c54f0)[iVar5] + 0x4894);
            goto switchD_0040d72b_caseD_2;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_005c329c);
      }
    }
    break;
  case 7:
    *(undefined4 *)(param_1 + 0x28) = 4;
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    iVar1 = FUN_005679c0(s_Commentary_005be9f0);
    if (iVar1 != 0) {
      uVar2 = FUN_00567970(s_GREETING_005be9e4);
      iVar1 = FUN_00588410(uVar2);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x2c) = 0;
      }
      else {
        uVar2 = FUN_00567970(s_WELCOME_TO_COUNTRY_005be9d0);
        iVar1 = FUN_00588410(uVar2);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x2c) = 1;
        }
        else {
          uVar2 = FUN_00567970(s_TRACK_INFO_005be9c4);
          iVar1 = FUN_00588410(uVar2);
          if (iVar1 == 0) {
            *(undefined4 *)(param_1 + 0x2c) = 2;
          }
          else {
            uVar2 = FUN_00567970(s_WEATHER_005be9bc);
            iVar1 = FUN_00588410(uVar2);
            if (iVar1 == 0) {
              *(undefined4 *)(param_1 + 0x2c) = 3;
            }
            else {
              uVar2 = FUN_00567970(s_CROWD_005be9b4);
              iVar1 = FUN_00588410(uVar2);
              if (iVar1 == 0) {
                *(undefined4 *)(param_1 + 0x2c) = 4;
              }
            }
          }
        }
      }
    }
    if (-1 < *(int *)(param_1 + 0x2c)) {
      *(undefined4 *)(param_1 + 0x28) = 2;
    }
    break;
  default:
    *(undefined4 *)(param_1 + 0x24) = 0;
  case 1:
    *(undefined4 *)(param_1 + 0x28) = 4;
  }
LAB_0040d91d:
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 == 4) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (iVar1 == -1) {
    uVar4 = FUN_0040d490();
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
    return uVar4 & 0xffffff00;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


