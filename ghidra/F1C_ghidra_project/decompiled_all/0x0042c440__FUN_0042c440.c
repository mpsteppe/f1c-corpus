// Function: FUN_0042c440 @ 0042c440
// Strings:  [Clutch Assistance:, Pit Lane Assistance:, Anti-lock Brakes:, Traction Control:, Auto Shifting:, Invulnerability:, Spin Recovery:, Stability Assistance:]


void FUN_0042c440(void)

{
  char cVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if ((*(int *)(DAT_007c54e8 + 13000) == 0) && (DAT_007ce254 == '\0')) {
    iVar3 = 0;
    if (0 < DAT_007cb218) {
      puVar2 = &DAT_007cb21c;
      do {
        switch(*puVar2) {
        case 0x3b:
          pcVar5 = s_Steering_Assistance__005c3480;
          uVar4 = 2;
          break;
        case 0x3c:
          pcVar5 = s_Opposite_Lock_Assistance__005c3464;
          goto LAB_0042c563;
        case 0x3d:
          pcVar5 = s_Braking_Point_Assistance__005c3448;
          uVar4 = 2;
          break;
        case 0x3e:
          pcVar5 = s_Stability_Assistance__005c3430;
          uVar4 = 2;
          break;
        case 0x3f:
          pcVar5 = s_Spin_Recovery__005c3420;
          uVar4 = 2;
          break;
        case 0x40:
          pcVar5 = s_Invulnerability__005c340c;
          goto LAB_0042c563;
        case 0x41:
          pcVar5 = s_Auto_Shifting__005c33fc;
          uVar4 = 3;
          break;
        case 0x42:
          pcVar5 = s_Traction_Control__005c33e8;
          uVar4 = 2;
          break;
        case 0x43:
          pcVar5 = s_Anti_lock_Brakes__005c33d4;
          uVar4 = 2;
          break;
        case 0x44:
          pcVar5 = s_Pit_Lane_Assistance__005c33bc;
          goto LAB_0042c563;
        default:
          goto switchD_0042c48c_caseD_45;
        case 0x57:
          pcVar5 = s_Clutch_Assistance__005c33a8;
LAB_0042c563:
          uVar4 = 1;
        }
        FUN_0042b8d0(uVar4,pcVar5);
switchD_0042c48c_caseD_45:
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < DAT_007cb218);
    }
    if (DAT_007cc260 != 0) {
      FUN_004a5e10();
    }
    if (((DAT_007cc394 != 0) && (DAT_007c9081 != '\0')) && (DAT_007c74a4 == '\0')) {
      FUN_00447c70(DAT_007c9080 == '\0',0);
    }
    if (DAT_007cc3c0 != 0) {
      FUN_00447d00(0xffffffff);
    }
    if (DAT_007cc3ec != 0) {
      FUN_00447d00(1);
    }
    if (DAT_007cc6d8 != 0) {
      DAT_007c9081 = DAT_007c9081 == '\0';
    }
    if ((DAT_007cc704 != 0) && (cVar1 = FUN_00447160(), cVar1 != '\0')) {
      FUN_004471f0(0);
    }
  }
  return;
}


