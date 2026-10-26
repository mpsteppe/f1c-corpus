// Function: FUN_0055a500 @ 0055a500
// Strings:  [FALSE, FALSE, COLOR, ACTIVE, MOVINGOMNI, MOVINGOMNI, STATICOMNI, STATICOMNI]


undefined4 FUN_0055a500(undefined4 param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c [2];
  undefined1 local_24 [4];
  char local_20 [16];
  char local_10 [16];
  
  piVar1 = param_2;
  local_58 = 0;
  uVar4 = 1;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_30 = 0;
  local_34 = 0;
  local_38 = 0;
  local_48 = 0x42c80000;
  local_2c[0] = 0x3f800000;
  iVar3 = FUN_00559a70();
  while ((iVar3 != 1 && (*piVar1 != 3))) {
    if (*piVar1 != 2) {
      FUN_00559e20(&DAT_005dc274,local_20,0);
      FUN_00559fb0(&DAT_005dc230,&local_4c,&local_50,&local_54,0);
      FUN_00559fb0(&DAT_005dc224,&local_3c,&local_40,&local_44,0);
      FUN_00559f00(s_COLOR_005c57f4,&local_38,&local_34,&local_30,0);
      FUN_00559fb0(s_RANGE_005dc26c,local_24,&local_48,0,0);
      FUN_00559fb0(s_INTENSITY_005dc260,local_2c,0,0,0);
      iVar3 = FUN_00559e20(s_ACTIVE_005d267c,local_10,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar7 = true;
        pcVar5 = local_10;
        pcVar6 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar5 == *pcVar6;
          pcVar5 = pcVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          uVar4 = 1;
        }
        else {
          iVar3 = 6;
          bVar7 = true;
          pcVar5 = local_10;
          pcVar6 = s_FALSE_005c5798;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar5 == *pcVar6;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
          } while (bVar7);
          if (bVar7) {
            uVar4 = 0;
          }
        }
      }
    }
    iVar3 = FUN_00559a70();
  }
  iVar3 = 0xc;
  bVar7 = true;
  pcVar5 = local_20;
  pcVar6 = s_DIRECTIONAL_005dc254;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar5 == *pcVar6;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    local_58 = 1;
  }
  else {
    iVar3 = 0xb;
    bVar7 = true;
    pcVar5 = local_20;
    pcVar6 = s_STATICOMNI_005dc248;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      local_58 = 4;
    }
    else {
      iVar3 = 0xb;
      bVar7 = true;
      pcVar5 = local_20;
      pcVar6 = s_MOVINGOMNI_005dc23c;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        local_58 = 2;
      }
    }
  }
  iVar3 = FUN_00545430(&param_2,param_1,local_58);
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if (local_58 == 1) {
    FUN_0055d460(local_3c,local_40,local_44);
  }
  else if ((local_58 == 2) || (local_58 == 4)) {
    FUN_0055d4f0(local_4c,local_50,local_54);
    FUN_0055d530(local_48);
  }
  FUN_0055d3f0(2,(local_38 << 8 | local_34) << 8 | local_30);
  uVar2 = local_2c[0];
  FUN_0055d410(1,local_2c[0]);
  FUN_0055d410(2,uVar2);
  FUN_0055d410(3,uVar2);
  FUN_0055d2f0(uVar4);
  return 0;
}


