// Function: FUN_004c4240 @ 004c4240
// Size (bytes): 904


void FUN_004c4240(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_430;
  int local_42c;
  undefined1 local_424 [40];
  undefined1 local_3fc [16];
  undefined4 local_3ec;
  undefined4 local_3e8;
  undefined4 local_3e4;
  undefined4 local_3e0;
  undefined4 local_3dc;
  undefined4 local_3d8;
  undefined4 local_3d4;
  undefined4 local_3d0;
  undefined4 local_3cc;
  undefined4 local_3c8;
  undefined4 local_3c4;
  undefined4 local_3c0;
  undefined4 local_3bc;
  undefined4 local_3b8;
  undefined4 local_3b4;
  undefined1 local_3b0 [8];
  undefined1 local_3a8 [64];
  undefined1 local_368 [64];
  undefined1 local_328 [64];
  undefined1 local_2e8 [64];
  undefined1 local_2a8 [64];
  undefined1 local_268 [256];
  undefined1 local_168 [128];
  undefined1 local_e8 [16];
  undefined1 local_d8 [64];
  undefined1 local_98 [16];
  undefined1 local_88 [16];
  undefined1 local_78 [16];
  undefined1 local_68 [24];
  undefined4 local_50;
  undefined1 local_44 [64];
  undefined4 local_4;
  
  FUN_004c3050();
  if (0 < DAT_008ac390) {
    local_430 = 0;
    iVar2 = DAT_008ac390;
    iVar5 = 0;
    do {
      iVar1 = iVar5 + 1;
      iVar6 = local_430;
      iVar8 = iVar1;
      iVar7 = local_430;
      local_42c = iVar5;
      if (iVar1 < iVar2) {
        do {
          iVar2 = FUN_004c3890(iVar6 + DAT_008ac394);
          if (iVar2 != 0) {
            iVar6 = iVar7 + 0x424;
            local_42c = iVar8;
          }
          iVar8 = iVar8 + 1;
          iVar7 = iVar7 + 0x424;
        } while (iVar8 < DAT_008ac390);
        iVar2 = DAT_008ac390;
        if (local_42c != iVar5) {
          iVar2 = DAT_008ac394 + local_430;
          uVar3 = FUN_00415c30();
          FUN_00566650(uVar3);
          uVar3 = FUN_00415c30();
          FUN_00566650(uVar3);
          uVar3 = FUN_00415c30();
          FUN_00566650(uVar3);
          uVar3 = FUN_00415c30();
          FUN_00566650(uVar3);
          uVar3 = FUN_00415c30();
          FUN_00566650(uVar3);
          iVar7 = iVar2 - (int)local_424;
          puVar4 = local_3fc;
          iVar5 = 0x10;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          local_3ec = *(undefined4 *)(iVar2 + 0x38);
          local_3e8 = *(undefined4 *)(iVar2 + 0x3c);
          local_3e4 = *(undefined4 *)(iVar2 + 0x40);
          local_3e0 = *(undefined4 *)(iVar2 + 0x44);
          local_3dc = *(undefined4 *)(iVar2 + 0x48);
          local_3d8 = *(undefined4 *)(iVar2 + 0x4c);
          local_3d4 = *(undefined4 *)(iVar2 + 0x50);
          local_3d0 = *(undefined4 *)(iVar2 + 0x54);
          local_3cc = *(undefined4 *)(iVar2 + 0x58);
          local_3c8 = *(undefined4 *)(iVar2 + 0x5c);
          local_3c4 = *(undefined4 *)(iVar2 + 0x60);
          local_3c0 = *(undefined4 *)(iVar2 + 100);
          local_3bc = *(undefined4 *)(iVar2 + 0x68);
          local_3b8 = *(undefined4 *)(iVar2 + 0x6c);
          local_3b4 = *(undefined4 *)(iVar2 + 0x70);
          puVar4 = local_3b0;
          iVar5 = 8;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_3a8;
          iVar5 = 0x40;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_368;
          iVar5 = 0x40;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_328;
          iVar5 = 0x40;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_2e8;
          iVar5 = 0x40;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_2a8;
          iVar5 = 0x40;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_268;
          iVar5 = 0x100;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_168;
          iVar5 = 0x80;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_e8;
          iVar5 = 0x10;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_d8;
          iVar5 = 0x40;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_98;
          iVar5 = 0x10;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_88;
          iVar5 = 0x10;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_78;
          iVar5 = 0x10;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar4 = local_68;
          iVar5 = 0x10;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          uVar3 = FUN_00415c30();
          FUN_00566650(uVar3);
          local_50 = *(undefined4 *)(iVar2 + 0x3d4);
          uVar3 = FUN_00415c30();
          FUN_00566650(uVar3);
          puVar4 = local_44;
          iVar5 = 0x40;
          do {
            *puVar4 = puVar4[iVar7];
            puVar4 = puVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          local_4 = *(undefined4 *)(iVar2 + 0x420);
          FUN_004c45d0(local_42c * 0x424 + DAT_008ac394);
          FUN_004c45d0(local_424);
          iVar2 = DAT_008ac390;
        }
      }
      local_430 = local_430 + 0x424;
      iVar5 = iVar1;
    } while (iVar1 < iVar2);
  }
  FUN_004c3130();
  return;
}


