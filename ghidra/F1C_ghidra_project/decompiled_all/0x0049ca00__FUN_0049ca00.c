// Function: FUN_0049ca00 @ 0049ca00
// Strings:  [%s%s%s, LEDFB, LEDFY, LEDFR, LEDLF, LEDPSR, LEDPSY, LEDSL]


undefined4 __fastcall FUN_0049ca00(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int local_104;
  undefined1 local_100 [128];
  undefined1 local_80 [128];
  
  uVar5 = 1;
  if (*param_1 == '\0') {
    FUN_0049cd80(param_1 + 0x60,param_1 + 0x4c,PTR_s_TAC_01_TGA_005ccb70,0x3f800000,0x3f800000,
                 0x43970000,0x42aa0000);
    FUN_0049cd80(param_1 + 0xac,param_1 + 0x50,PTR_s_WATERTEMP_COCKPIT_TGA_005ccb74,0x3f000000,
                 0x3f000000,0x43520000,0x43a50000);
    FUN_0049cd80(param_1 + 0xf8,param_1 + 0x54,PTR_s_OILTEMP_COCKPIT_TGA_005ccb78,0x3f000000,
                 0x3f000000,0x43520000,0x43a50000);
    FUN_0049cd80(param_1 + 0x144,param_1 + 0x58,PTR_s_OILPRESS_COCKPIT_TGA_005ccb7c,0x3f000000,
                 0x3f000000,0x43520000,0x43a50000);
    FUN_0049cd80(param_1 + 400,param_1 + 0x5c,PTR_s_FUEL_COCKPIT_TGA_005ccb80,0x3f000000,0x3f000000,
                 0x43520000,0x43a50000);
    if (DAT_008afe88 != 0) {
      iVar1 = FUN_00545f40();
      if (iVar1 != 0) {
        uVar2 = FUN_00547920(PTR_s_READOUT_BMP_005ccb5c);
        *(undefined4 *)(param_1 + 0x10) = uVar2;
        iVar1 = FUN_00547920(PTR_s_LCD00_BMP_005ccb68);
        *(int *)(param_1 + 0x14) = iVar1;
        if ((*(int *)(param_1 + 0x10) != 0) && (iVar1 != 0)) {
          uVar5 = 0;
        }
        uVar2 = FUN_00548890(PTR_s_LED165_005ccb88);
        *(undefined4 *)(param_1 + 0x20) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LED170_005ccb8c);
        *(undefined4 *)(param_1 + 0x24) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LED175_005ccb90);
        *(undefined4 *)(param_1 + 0x28) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LED182_005ccb94);
        *(undefined4 *)(param_1 + 0x2c) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LEDSL_005ccb98);
        *(undefined4 *)(param_1 + 0x30) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LEDPSY_005ccb9c);
        *(undefined4 *)(param_1 + 0x34) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LEDPSR_005ccba0);
        *(undefined4 *)(param_1 + 0x38) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LEDLF_005ccba4);
        *(undefined4 *)(param_1 + 0x3c) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LEDFR_005ccba8);
        *(undefined4 *)(param_1 + 0x40) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LEDFY_005ccbac);
        *(undefined4 *)(param_1 + 0x44) = uVar2;
        uVar2 = FUN_00548890(PTR_s_LEDFB_005ccbb0);
        *(undefined4 *)(param_1 + 0x48) = uVar2;
      }
      local_104 = 0;
      puVar4 = DAT_005ec428;
      if (DAT_005ec428 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      puVar3 = DAT_005ec3d8;
      if (DAT_005ec3d8 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      FUN_0058815f(local_80,s__s_s_s_005c6784,puVar3,puVar4,s_CMAPS_MAS_005cceb0);
      FUN_0053cbc0(&local_104,local_80);
      if (local_104 != 0) {
        FUN_0058815f(local_100,s__s_BMP_005ccea8,PTR_s_FONTREAD_005ccb58);
        FUN_0053cfe0(param_1 + 4,local_100,0x10801);
        if (*(int *)(param_1 + 4) == 0) {
          uVar5 = 1;
        }
        FUN_0058815f(local_100,s__s_BMP_005ccea8,PTR_s_FONTLCD_005ccb60);
        FUN_0053cfe0(param_1 + 8,local_100,0x10801);
        if (*(int *)(param_1 + 8) == 0) {
          uVar5 = 1;
        }
        FUN_0058815f(local_100,s__s_BMP_005ccea8,PTR_s_FONTAIDS_005ccb64);
        FUN_0053cfe0(param_1 + 0xc,local_100,0x10801);
        if (*(int *)(param_1 + 0xc) == 0) {
          uVar5 = 1;
        }
        if (*(int *)(param_1 + 0x14) != 0) {
          FUN_0053cb20(param_1 + 0x18,PTR_s_LCD00_BMP_005ccb68,0,1);
          if (*(int *)(param_1 + 0x18) == 0) {
            uVar5 = 1;
          }
          FUN_0053cb20(param_1 + 0x1c,PTR_s_LCD01_BMP_005ccb6c,0,1);
          if (*(int *)(param_1 + 0x1c) == 0) {
            uVar5 = 1;
          }
        }
        FUN_0053ce40(local_104);
      }
    }
    *param_1 = '\x01';
  }
  return uVar5;
}


