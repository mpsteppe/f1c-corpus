// Function: FUN_00558e70 @ 00558e70
// Size (bytes): 889


void __thiscall FUN_00558e70(int param_1,undefined4 param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 uVar6;
  float *pfVar7;
  float local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  float local_98;
  float local_94;
  uint *local_90;
  uint uStack_8c;
  int local_88;
  float local_84;
  float fStack_80;
  int local_7c;
  int local_78;
  uint *local_74;
  short sStack_70;
  uint uStack_6c;
  uint local_40 [10];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  
  if (*(char *)(param_1 + 0x20) < '\0') {
    if (*(int *)(param_1 + 0x30) != 0) {
      iStack_8 = 0;
      iStack_c = 0x5591d1;
      FUN_00558d80();
      iStack_8 = *(int *)(param_1 + 0x28) * *(int *)(param_1 + 0x30);
      iStack_c = *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x30);
      uStack_10 = *(undefined4 *)(param_1 + 0x50);
      uStack_14 = param_2;
      uStack_18 = 0x5591f5;
      FUN_0055cf50();
    }
    return;
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    return;
  }
  FUN_0053b130();
  if ((*(uint *)(param_1 + 0x20) & 0x20) == 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x10) == 0) goto LAB_00558f27;
    FUN_00542490(&local_94,&local_a8,&local_98);
    local_98 = -local_98;
    local_94 = -local_94;
  }
  else {
    FUN_00542490(&local_94,&local_a8,&local_98);
    local_98 = 0.0;
    local_94 = 0.0;
  }
  FUN_0053b240(local_94,-local_a8,local_98);
LAB_00558f27:
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x44) + iVar3 * 4) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x48) + iVar3 * 4) = 0;
      FUN_00558d10(iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x4c));
  }
  puVar2 = *(uint **)(param_1 + 0x38);
  pfVar7 = &local_84;
  uVar6 = 2;
  local_90 = puVar2;
  FUN_005457c0(0);
  FUN_0055d560(uVar6,pfVar7);
  while (puVar2 != (uint *)0x0) {
    if ((*(byte *)(param_1 + 0x20) & 0x30) != 0) {
      puVar4 = local_40;
      puVar5 = puVar2 + 0xe;
      for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_0053b170(&local_a0,&local_9c,&local_a4);
      FUN_0053b200(local_a0,local_9c,local_a4);
    }
    if ((*puVar2 & 0x4000) != 0) {
      FUN_0053b1d0(&local_a0,&local_9c,&local_a4);
      FUN_0053b330(local_a0,local_9c,local_a4);
    }
    FUN_0053b350();
    local_78 = 0;
    if (0 < *(int *)(param_1 + 0x4c)) {
      local_88 = 0;
      do {
        iVar3 = *(int *)(*(int *)(param_1 + 0x50) + 0xc + local_88);
        iVar1 = *(int *)(param_1 + 0x50) + local_88;
        local_7c = 0;
        if (0 < *(int *)(iVar1 + 8)) {
          local_74 = puVar2 + 0xe;
          iVar1 = *(int *)(*(int *)(param_1 + 0x44) + local_78 * 4) * 0x40 + *(int *)(iVar1 + 0x20);
          do {
            (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,iVar3,iVar1,local_74);
            *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar3 + 0x1c);
            *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar3 + 0x20);
            uStack_8c = puVar2[3];
            uStack_6c = *(uint *)(iVar3 + 0x18);
            fStack_80 = (float)(uStack_8c >> 0x18) * local_84;
            sStack_70 = (short)ROUND(fStack_80);
            iVar3 = iVar3 + 0x24;
            *(int *)(iVar1 + 0x18) =
                 ((((int)(((uStack_6c >> 0x10 & 0xff) + 1) * (uStack_8c >> 0x10 & 0xff)) >> 8) +
                  sStack_70 * 0x100) * 0x100 +
                 ((int)(((uStack_6c >> 8 & 0xff) + 1) * (uStack_8c >> 8 & 0xff)) >> 8)) * 0x100 +
                 ((int)(((uStack_6c & 0xff) + 1) * (uStack_8c & 0xff)) >> 8);
            local_7c = local_7c + 1;
            puVar2 = local_90;
            iVar1 = iVar1 + 0x40;
          } while (local_7c < *(int *)(local_88 + 8 + *(int *)(param_1 + 0x50)));
        }
        *(int *)(*(int *)(param_1 + 0x44) + local_78 * 4) =
             *(int *)(*(int *)(param_1 + 0x44) + local_78 * 4) +
             *(int *)(local_88 + 8 + *(int *)(param_1 + 0x50));
        *(int *)(*(int *)(param_1 + 0x48) + local_78 * 4) =
             *(int *)(*(int *)(param_1 + 0x48) + local_78 * 4) +
             *(int *)(local_88 + 0x10 + *(int *)(param_1 + 0x50));
        local_78 = local_78 + 1;
        local_88 = local_88 + 0x40;
      } while (local_78 < *(int *)(param_1 + 0x4c));
    }
    puVar2 = (uint *)puVar2[0x1f];
    local_90 = puVar2;
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    iVar1 = 0;
    do {
      FUN_00558d80(iVar3);
      FUN_0055cf50(param_2,*(int *)(param_1 + 0x50) + iVar1,
                   *(undefined4 *)(*(int *)(param_1 + 0x44) + iVar3 * 4),
                   *(undefined4 *)(*(int *)(param_1 + 0x48) + iVar3 * 4));
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x40;
    } while (iVar3 < *(int *)(param_1 + 0x4c));
  }
  FUN_0053b160();
  return;
}


