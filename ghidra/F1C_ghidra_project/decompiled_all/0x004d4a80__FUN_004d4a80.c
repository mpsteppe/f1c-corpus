// Function: FUN_004d4a80 @ 004d4a80
// Strings:  [Clutch, Clutch, Clutch, Brake, Brake, Brake, Steering, Steering]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d4a80(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,char *param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 char param_10)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *extraout_ECX;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int in_stack_00000528;
  int in_stack_00000534;
  int in_stack_0000053c;
  int in_stack_00000544;
  int in_stack_0000054c;
  int in_stack_00000554;
  int in_stack_00001ff8;
  
  FUN_005881c0();
  FUN_004d5840();
  cVar1 = FUN_0042bc10();
  if (cVar1 != '\0') {
    iVar2 = 0;
    param_2 = 0;
    if (0 < DAT_005c329c) {
      do {
        param_2 = (&DAT_007c54f0)[iVar2];
        if (*(int *)(param_2 + 13000) == 0) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_005c329c);
    }
    if (iVar2 != DAT_005c329c) {
      pcVar7 = DAT_007cea34;
      if (DAT_007cea34 == (char *)0x0) {
        pcVar7 = &DAT_005ea438;
      }
      iVar2 = -1;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (((iVar2 != -2) && (0 < DAT_007ce9d0)) && ((DAT_007c56a4 != 7 || (DAT_007ce9f4 != 0)))) {
        iVar2 = FUN_00587db0();
        *extraout_ECX = iVar2;
        if (iVar2 != 0) {
          iVar2 = __ftol();
          iVar2 = iVar2 * 10;
          extraout_ECX[1] = iVar2;
          if (iVar2 < 1) {
            extraout_ECX[1] = 1;
          }
          else if (0x28 < iVar2) {
            extraout_ECX[1] = 0x28;
          }
          param_9 = 0;
          FUN_00588678();
          iVar2 = 0;
          do {
            iVar3 = _rand();
            *(char *)((int)&param_3 + iVar2) = (char)iVar3;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 4);
          FUN_00588678();
          uVar5 = param_3 >> 8 & 0xff;
          extraout_ECX[6] = 0;
          uVar4 = param_3 >> 0x10 & 0xff;
          extraout_ECX[3] = (param_3 & 0xff) + 0x12 + uVar5;
          extraout_ECX[4] = uVar4 + 0x4d + uVar5;
          extraout_ECX[5] = (param_3 >> 0x18) + 0xf + uVar4;
          param_8 = 0x3d4ccccd;
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = (char *)(param_2 + 0x4620);
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = (char *)(param_2 + 0x4678);
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = (char *)(param_2 + 0x4714);
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          pcVar7 = DAT_007ce5ec;
          if (DAT_007ce5ec == (char *)0x0) {
            pcVar7 = &DAT_005ea438;
          }
          iVar2 = -1;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          param_7 = 0x39;
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Elapsed_Time__s__005d45a4;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Pos_X__m__005d4598;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Pos_Y__m__005d458c;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = &DAT_005d4580;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Yaw__rads__005d4574;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Lat_Accel__m_s__005d4564;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Vert_Accel__m_s__005d4550;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Long_Accel__m_s__005d453c;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Engine_RPM_005d4530;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Clutch_RPM_005d4524;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Unfiltered_Throttle_005d4510;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Throttle_005c6f6c;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Unfiltered_Brake_005d44fc;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Brake_005c565c;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Unfiltered_Steering_005d44e8;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Steering_005c6f30;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Unfiltered_Clutch_005d44d4;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Clutch_005c55cc;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          iVar2 = 0;
          do {
            if (iVar2 == 0) {
              pcVar7 = &DAT_005d44d0;
            }
            else if (iVar2 == 1) {
              pcVar7 = &DAT_005d44cc;
            }
            else {
              pcVar7 = &DAT_005d44c8;
              if (iVar2 != 2) {
                pcVar7 = &DAT_005d44c4;
              }
            }
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = pcVar7;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = s_Wheelspin__rads_s__005d44b0;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = pcVar7;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = s_Suspension_Deflection__m__005d4494;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = pcVar7;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = s_Undertray_Ride_Height__m__005d4478;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = pcVar7;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = s_Tyre_Left_Temp__K__005d4464;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = pcVar7;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = s_Tyre_Center_Temp__K__005d444c;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = pcVar7;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = s_Tyre_Right_Temp__K__005d4438;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = pcVar7;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = s_Tyre_Pressure__kPa__005d4424;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = pcVar7;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar6 = s_Tyre_Wear_005d4418;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            FUN_004d5be0();
            iVar3 = -1;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar3 = -1;
            pcVar7 = s_Corner_Weight_005d4408;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 != '\0');
            FUN_004d5be0();
            iVar2 = iVar2 + 1;
          } while (iVar2 < 4);
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = &DAT_005d4400;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Water_Temperature_005d43ec;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          FUN_004d5be0();
          iVar2 = -1;
          pcVar7 = s_Oil_Temperature_005d43dc;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          FUN_004d5be0();
          if (param_2 != 0) {
            pcVar7 = *(char **)(*(int *)(param_2 + 0x4898) * 0x424 + 8 + DAT_008ac394);
            if (pcVar7 == (char *)0x0) {
              pcVar7 = &DAT_005ea438;
            }
            pcVar6 = &stack0x00000228;
            do {
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              *pcVar6 = cVar1;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            pcVar7 = (char *)(param_2 + 0x4794);
            iVar2 = -(int)pcVar7;
            do {
              cVar1 = *pcVar7;
              pcVar7[(int)(&stack0x00000328 + iVar2)] = cVar1;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 != '\0');
          }
          FUN_004ceef0();
          param_10 = DAT_005ea438;
          puVar8 = (undefined4 *)&stack0x00000029;
          for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
          }
          *(undefined2 *)puVar8 = 0;
          *(undefined1 *)((int)puVar8 + 2) = 0;
          pcVar7 = DAT_007ce5d0;
          if (DAT_007ce5d0 == (char *)0x0) {
            pcVar7 = &DAT_005ea438;
          }
          _strncpy(&param_10,pcVar7,0x1ff);
          uVar5 = 0xffffffff;
          pcVar7 = &param_10;
          do {
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          pcVar7 = (char *)((int)&param_9 + ~uVar5 + 3);
          if (&param_10 < pcVar7) {
            do {
              if (*pcVar7 == '.') {
                *pcVar7 = '\0';
                break;
              }
              pcVar7 = pcVar7 + -1;
            } while (&param_10 < pcVar7);
          }
          iVar2 = -1;
          pcVar7 = &param_10;
          do {
            pcVar6 = pcVar7;
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            pcVar6 = pcVar7 + 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar6;
          } while (cVar1 != '\0');
          *(undefined4 *)(pcVar6 + -1) = DAT_005c5d24;
          pcVar6[3] = DAT_005c5d28;
          FUN_004f34e0();
          FUN_0042e320();
          FUN_004f4270();
          FUN_004b3c60();
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          FUN_004d5be0();
          param_4 = _DAT_007c935c ^ 0x516141f2;
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          FUN_004b3c60();
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          FUN_004d5be0();
          FUN_004b3c60();
          FUN_004d5be0();
          FUN_00568a60();
          FUN_004d5be0();
          param_5 = (char *)0x0;
          param_6 = 0xffffffff;
          FUN_00566650();
          pcVar7 = param_5;
          if (param_5 == (char *)0x0) {
            pcVar7 = &DAT_005ea438;
          }
          uVar5 = 0xffffffff;
          pcVar6 = pcVar7;
          do {
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          for (pcVar6 = pcVar7 + (~uVar5 - 1); pcVar7 < pcVar6; pcVar6 = pcVar6 + -1) {
            if (*pcVar6 == '.') {
              *pcVar6 = '\0';
              break;
            }
          }
          if (0 < DAT_008ac488) {
            param_2 = DAT_008ac488;
            do {
              FUN_00588410();
              param_2 = param_2 + -1;
            } while (param_2 != 0);
          }
          FUN_004d5be0();
          FUN_004d5af0();
          if (param_5 != (char *)0x0) {
            FUN_00587bcf();
          }
          FUN_0042ddd0();
          if (in_stack_00001ff8 != 0) {
            FUN_00587bcf();
          }
          if (in_stack_00000554 != 0) {
            FUN_00587bcf();
          }
          if (in_stack_0000054c != 0) {
            FUN_00587bcf();
          }
          if (in_stack_00000544 != 0) {
            FUN_00587bcf();
          }
          if (in_stack_0000053c != 0) {
            FUN_00587bcf();
          }
          if (in_stack_00000534 != 0) {
            FUN_00587bcf();
          }
          if (in_stack_00000528 != 0) {
            FUN_00587bcf();
          }
        }
      }
    }
  }
  return;
}


