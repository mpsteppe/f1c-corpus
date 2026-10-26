// Function: FUN_0054c6c0 @ 0054c6c0
// Size (bytes): 832


undefined4 __thiscall FUN_0054c6c0(int param_1,uint param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_a4;
  int local_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 local_40 [64];
  
  if ((*(uint *)(param_1 + 0x14) & 0x4000000) == 0) {
    FUN_0053b130();
    FUN_0053b200(*(undefined4 *)(param_1 + 0x100),*(undefined4 *)(param_1 + 0x104),
                 *(undefined4 *)(param_1 + 0x108));
    FUN_0053b240(*(undefined4 *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0x110),
                 *(undefined4 *)(param_1 + 0x114));
    local_9c = 0;
    if (0 < *(int *)(param_1 + 0x118)) {
      iVar3 = 0;
      do {
        local_a4 = 0;
        if ((*(uint *)(param_1 + 0x14) & 0x800000) == 0) {
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x11c) + 0xc + iVar3);
          if (0 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar3)) {
            do {
              (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,puVar2,&uStack_80,local_40);
              (**(code **)*DAT_008b8f24)(DAT_008b8f24,puVar2 + 3,&uStack_74,local_40);
              if ((*(byte *)(*(int *)(param_1 + 0x138) + 0x3c) & 0x10) == 0) {
                *puVar2 = uStack_80;
                puVar2[1] = uStack_7c;
                puVar2[2] = uStack_78;
                puVar2[3] = uStack_74;
                puVar2[4] = uStack_70;
                puVar2[5] = uStack_6c;
              }
              puVar2[10] = puVar2[8];
              puVar2[0xb] = puVar2[9];
              puVar2 = puVar2 + 0xc;
              local_a4 = local_a4 + 1;
            } while (local_a4 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar3));
          }
        }
        else {
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x11c) + 0xc + iVar3);
          if (0 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar3)) {
            do {
              (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,puVar2,&local_98,local_40);
              (**(code **)*DAT_008b8f24)(DAT_008b8f24,puVar2 + 7,&uStack_8c,local_40);
              if ((*(byte *)(*(int *)(param_1 + 0x138) + 0x3c) & 0x10) == 0) {
                *puVar2 = local_98;
                puVar2[1] = uStack_94;
                puVar2[2] = uStack_90;
                puVar2[7] = uStack_8c;
                puVar2[8] = uStack_88;
                puVar2[9] = uStack_84;
              }
              puVar2[0xe] = puVar2[0xc];
              puVar2[0xf] = puVar2[0xd];
              puVar2 = puVar2 + 0x10;
              local_a4 = local_a4 + 1;
            } while (local_a4 < *(int *)(*(int *)(param_1 + 0x11c) + 8 + iVar3));
          }
          FUN_0054b4d0(0,0,0,0,0,0);
        }
        *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x34 + iVar3) = 0xffffffff;
        *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x1c + iVar3) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x20 + iVar3) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x24 + iVar3) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x28 + iVar3) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x38 + iVar3) = 0;
        if ((param_2 & 4) != 0) {
          puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0x11c) + 4 + iVar3) + 0x9c);
          *puVar1 = *puVar1 | 0x8000;
        }
        local_9c = local_9c + 1;
        iVar3 = iVar3 + 0x40;
      } while (local_9c < *(int *)(param_1 + 0x118));
    }
    FUN_0054d520(1);
    FUN_0054e270();
    FUN_0054d080(0);
    FUN_0054e080();
    *(undefined4 *)(param_1 + 0x10c) = 0;
    *(undefined4 *)(param_1 + 0x108) = 0;
    *(undefined4 *)(param_1 + 0x104) = 0;
    *(undefined4 *)(param_1 + 0x100) = 0;
    *(undefined4 *)(param_1 + 0x114) = 0;
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    puVar2 = operator_new(0x1c4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 8;
      puVar2 = puVar2 + 1;
      iVar3 = 8;
      do {
        FUN_0055d200();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    *(undefined4 **)(param_1 + 0x110) = puVar2;
    *(undefined4 *)(param_1 + 0x108) = 0;
    *(undefined4 *)(param_1 + 0x104) = 0;
    *(undefined4 *)(param_1 + 0x100) = 0;
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x4000000;
    FUN_0053b160();
  }
  return 0;
}


