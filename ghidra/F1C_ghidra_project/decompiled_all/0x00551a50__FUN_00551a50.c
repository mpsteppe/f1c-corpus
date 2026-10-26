// Function: FUN_00551a50 @ 00551a50
// Strings:  [%s\%s, Error: %s for BINK file %s, Error: %s while setting DirectSound, Error: %s while setting Miles sound]


undefined4 __thiscall FUN_00551a50(int *param_1,char *param_2,uint param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  char *pcVar9;
  char local_37c [256];
  int local_27c;
  int local_278;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  uVar6 = 0;
  iVar3 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_37c + iVar3)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_37c);
  iVar3 = FUN_00587c20(local_37c,&DAT_005dc0b8);
  if (iVar3 == 0) {
    iVar3 = -1;
    pcVar8 = local_37c;
    do {
      pcVar9 = pcVar8;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar9 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar1 != '\0');
    *(undefined4 *)(pcVar9 + -1) = DAT_005dc0b8;
    pcVar9[3] = DAT_005dc0bc;
  }
  if (((param_3 & 1) == 0) || (param_4 == 0)) {
    if (((param_3 & 2) == 0) || (param_4 == 0)) {
      _BinkSetSoundTrack_8(0,0);
      uVar6 = 0x4000;
    }
    else {
      iVar3 = _BinkSetSoundSystem_8(_BinkOpenDirectSound_4_exref,param_4);
      if (iVar3 == 0) {
        uVar4 = _BinkGetError_0();
        FUN_0058815f(local_200,s_Error___s_while_setting_DirectSo_005dc070,uVar4);
        FUN_0053c590(0xffffffff,local_200);
        return 0xffffffff;
      }
    }
  }
  else {
    iVar3 = _BinkSetSoundSystem_8(_BinkOpenMiles_4_exref,param_4);
    if (iVar3 == 0) {
      uVar4 = _BinkGetError_0();
      FUN_0058815f(local_200,s_Error___s_while_setting_Miles_so_005dc094,uVar4);
      FUN_0053c590(0xffffffff,local_200);
      return 0xffffffff;
    }
  }
  if ((param_3 & 0x10) == 0) {
    if ((param_3 & 4) != 0) {
      uVar6 = uVar6 | 0x30000000;
    }
    if ((param_3 & 8) != 0) {
      if ((param_3 & 4) == 0) {
        uVar6 = uVar6 | 0x10000000;
      }
      else {
        uVar6 = uVar6 & 0xcfffffff | 0x40000000;
      }
    }
  }
  else {
    uVar2 = uVar6 | 0x60000000;
    if ((param_3 & 4) != 0) {
      uVar2 = uVar6 | 0x70000000;
    }
    uVar6 = uVar2;
    if ((param_3 & 8) != 0) {
      if ((param_3 & 4) == 0) {
        uVar6 = uVar6 & 0x9fffffff | 0x20000000;
      }
      else {
        uVar6 = uVar6 & 0x9fffffff | 0x50000000;
      }
    }
  }
  iVar3 = _BinkOpen_8(local_37c,uVar6);
  *param_1 = iVar3;
  if (iVar3 == 0) {
    iVar3 = 0;
    if (0 < DAT_008b8e30) {
      puVar7 = &DAT_008b5a3c;
      do {
        FUN_0058815f(local_100,s__s__s_005c2d64,puVar7,local_37c);
        iVar5 = _BinkOpen_8(local_100,uVar6);
        *param_1 = iVar5;
        if (iVar5 != 0) break;
        iVar3 = iVar3 + 1;
        puVar7 = puVar7 + 0x84;
      } while (iVar3 < DAT_008b8e30);
    }
    if (iVar3 == DAT_008b8e30) {
      uVar4 = _BinkGetError_0(local_37c);
      FUN_0058815f(local_100,s_Error___s_for_BINK_file__s_005dc054,uVar4);
      FUN_0053c590(0xffffffff,local_100);
      return 0xffffffff;
    }
  }
  _BinkGetSummary_8(*param_1,&local_27c);
  param_1[3] = local_278;
  param_1[2] = local_27c;
  return 0;
}


