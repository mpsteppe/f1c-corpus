// Function: FUN_0053eb70 @ 0053eb70
// Size (bytes): 1791


undefined4 __fastcall FUN_0053eb70(undefined4 *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  void *pvVar6;
  int iVar7;
  int *piVar8;
  undefined4 uStack_110;
  int iStack_10c;
  int *piStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  int *piStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  int *piStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  int *piStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  int *piStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  int *piStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  int *piStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  int *piStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  int *piStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  int *piStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  int *piStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  int *piStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int *piStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int *piStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int *piStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  
  if ((param_1[0x4ea] & 0x10000000) == 0) {
    uStack_58 = param_1[0x4e9];
    piStack_60 = (int *)param_1[0x440];
    uStack_5c = 0x16;
    uStack_64 = 0x53eba1;
    uVar2 = (**(code **)(*piStack_60 + 200))();
    uStack_64 = 1;
    *param_1 = uVar2;
    piStack_6c = (int *)param_1[0x440];
    uStack_68 = 0x1a;
    uStack_70 = 0x53ebb6;
    uVar2 = (**(code **)(*piStack_6c + 200))();
    uStack_70 = 0;
    *param_1 = uVar2;
    piStack_78 = (int *)param_1[0x440];
    uStack_74 = 0x1c;
    uStack_7c = 0x53ebcc;
    uVar2 = (**(code **)(*piStack_78 + 200))();
    uStack_7c = 1;
    *param_1 = uVar2;
    piStack_84 = (int *)param_1[0x440];
    uStack_80 = 0x88;
    uStack_88 = 0x53ebe4;
    uVar2 = (**(code **)(*piStack_84 + 200))();
    uStack_88 = param_1[0x4ee];
    *param_1 = uVar2;
    piStack_90 = (int *)param_1[0x440];
    uStack_8c = 7;
    uStack_94 = 0x53ebfe;
    uVar2 = (**(code **)(*piStack_90 + 200))();
    uStack_94 = 2;
    *param_1 = uVar2;
    piStack_9c = (int *)param_1[0x440];
    uStack_98 = 0x17;
    uStack_a0 = 0x53ec13;
    uVar2 = (**(code **)(*piStack_9c + 200))();
    uStack_a0 = 1;
    *param_1 = uVar2;
    uStack_a4 = 0x53ec1e;
    FUN_00554be0();
    uStack_a0 = param_1[0x4f2];
    piStack_a8 = (int *)param_1[0x440];
    uStack_a4 = 0x3c;
    uStack_ac = 0x53ec36;
    uVar2 = (**(code **)(*piStack_a8 + 200))();
    uStack_ac = 5;
    *param_1 = uVar2;
    piStack_b4 = (int *)param_1[0x440];
    uStack_b0 = 0x19;
    uStack_b8 = 0x53ec4b;
    uVar2 = (**(code **)(*piStack_b4 + 200))();
    uStack_b8 = 0x3f;
    *param_1 = uVar2;
    piStack_c0 = (int *)param_1[0x440];
    uStack_bc = 0x18;
    uStack_c4 = 5500000;
    uVar2 = (**(code **)(*piStack_c0 + 200))();
    uStack_c4 = 0;
    *param_1 = uVar2;
    piStack_cc = (int *)param_1[0x440];
    uStack_c8 = 0x1d;
    param_1[0x4f0] = 0x3f;
    uStack_d0 = 0x53ec7e;
    uVar2 = (**(code **)(*piStack_cc + 200))();
    *param_1 = uVar2;
    piStack_d8 = (int *)param_1[0x440];
    uStack_d0 = 0;
    uStack_d4 = 0x1b;
    uStack_dc = 0x53ec92;
    uVar2 = (**(code **)(*piStack_d8 + 200))();
    uStack_dc = 2;
    *param_1 = uVar2;
    piStack_e4 = (int *)param_1[0x440];
    uStack_e0 = 0x13;
    uStack_e8 = 0x53eca7;
    uVar2 = (**(code **)(*piStack_e4 + 200))();
    uStack_e8 = 1;
    *param_1 = uVar2;
    piStack_f0 = (int *)param_1[0x440];
    uStack_ec = 0x14;
    uStack_f4 = 0x53ecbc;
    uVar2 = (**(code **)(*piStack_f0 + 200))();
    uStack_f4 = 2;
    *param_1 = uVar2;
    piStack_fc = (int *)param_1[0x440];
    uStack_f8 = 9;
    uStack_100 = 0x53ecd1;
    uVar2 = (**(code **)(*piStack_fc + 200))();
    uStack_100 = 0;
    *param_1 = uVar2;
    piStack_108 = (int *)param_1[0x440];
    uStack_104 = 0xf;
    iStack_10c = 0x53ece5;
    uVar2 = (**(code **)(*piStack_108 + 200))();
    *param_1 = uVar2;
    iVar7 = 0;
    param_1[0x4ef] = 0x10002;
    param_1[0x45d] = 0x100;
    if (0 < (int)param_1[0x4ec]) {
      do {
        iStack_10c = 2;
        uStack_110 = 0x11;
        uVar2 = (**(code **)(*(int *)param_1[0x440] + 0xfc))((int *)param_1[0x440],iVar7);
        *param_1 = uVar2;
        uVar2 = (**(code **)(*(int *)param_1[0x440] + 0xfc))((int *)param_1[0x440],iVar7,0x10,2);
        *param_1 = uVar2;
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)param_1[0x4ec]);
    }
    iVar7 = 0;
    do {
      uStack_110 = 0x53ed4e;
      iStack_10c = iVar7;
      FUN_00553e10();
      iStack_10c = 0x53ed55;
      iVar3 = FUN_0055c9b0();
      if (iVar3 != 0) {
        iStack_10c = 0xc0000000;
        uStack_110 = 0x53ed65;
        FUN_00554660();
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 8);
    piVar8 = (int *)param_1[0x440];
    iStack_10c = 0;
    uStack_110 = 0;
    param_1[0x4e6] = 0;
    uVar2 = (**(code **)(*piVar8 + 0x14c))(piVar8,0);
    *param_1 = uVar2;
    param_1[0x4e7] = 0;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x130))((int *)param_1[0x440],0x4d2);
    *param_1 = uVar2;
    uStack_110 = 0x3f800000;
    iStack_10c = 0x3f800000;
    piStack_108 = (int *)0x3f800000;
    uStack_104 = 0;
    uStack_100 = 0x3f800000;
    piStack_fc = (int *)0x3f800000;
    uStack_f8 = 0x3f800000;
    uStack_f4 = 0;
    piStack_f0 = (int *)0x0;
    uStack_ec = 0;
    uStack_e8 = 0;
    piStack_e4 = (int *)0x3f800000;
    uStack_e0 = 0;
    uStack_dc = 0;
    piStack_d8 = (int *)0x0;
    uStack_d4 = 0;
    uStack_d0 = 0;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 0xa8))((int *)param_1[0x440],&uStack_110);
    *param_1 = uVar2;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x8d,0);
    *param_1 = uVar2;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x91,1);
    *param_1 = uVar2;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x93,0);
    *param_1 = uVar2;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x92,0);
    *param_1 = uVar2;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x94,0);
    *param_1 = uVar2;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x89,0);
    *param_1 = uVar2;
    param_1[0x4f4] = 0;
    FUN_00560340();
    puVar4 = operator_new(0x24);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[5] = 0;
      puVar4[4] = 0;
      puVar4[3] = 0;
      puVar4[2] = 0;
      puVar4[1] = 0;
      *puVar4 = 0;
      puVar4[7] = 0;
      puVar4[6] = 0;
      puVar4[8] = 0;
    }
    param_1[0x450] = puVar4;
    *puVar4 = 0x22;
    *(undefined4 *)(param_1[0x450] + 0xc) = 8;
    *(undefined4 *)(param_1[0x450] + 4) = DAT_008cef78;
    *(undefined4 *)(param_1[0x450] + 8) = 0x1c;
    iVar7 = FUN_00540df0(param_1[0x450]);
    if (iVar7 != 0) {
      return 0xffffffff;
    }
    iVar7 = FUN_00540f00(param_1[0x450],0,0,0);
    *(undefined4 *)(iVar7 + 8) = 0x3f800000;
    *(undefined4 *)(iVar7 + 0xc) = 0x3f800000;
    *(undefined4 *)(iVar7 + 0x24) = 0x3f800000;
    *(undefined4 *)(iVar7 + 0x28) = 0x3f800000;
    *(undefined4 *)(iVar7 + 0x40) = 0x3f800000;
    *(undefined4 *)(iVar7 + 0x44) = 0x3f800000;
    *(undefined4 *)(iVar7 + 0x5c) = 0x3f800000;
    *(undefined4 *)(iVar7 + 0x60) = 0x3f800000;
    FUN_00540f90(param_1[0x450]);
    puVar4 = operator_new(0x24);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[5] = 0;
      puVar4[4] = 0;
      puVar4[3] = 0;
      puVar4[2] = 0;
      puVar4[1] = 0;
      *puVar4 = 0;
      puVar4[7] = 0;
      puVar4[6] = 0;
      puVar4[8] = 0;
    }
    param_1[0x44f] = puVar4;
    *puVar4 = 0x22;
    *(undefined4 *)(param_1[0x44f] + 0xc) = 0x80;
    *(undefined4 *)(param_1[0x44f] + 4) = 0x142;
    *(undefined4 *)(param_1[0x44f] + 8) = 0x18;
    iVar7 = FUN_00540df0(param_1[0x44f]);
    if (iVar7 != 0) {
      return 0xffffffff;
    }
    puVar4 = operator_new(0x1c);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[3] = 0;
      puVar4[2] = 0;
      puVar4[1] = 0;
      *puVar4 = 0;
      puVar4[5] = 0;
      puVar4[4] = 0;
      puVar4[6] = 0;
    }
    param_1[0x451] = puVar4;
    *puVar4 = 0x12;
    *(undefined4 *)(param_1[0x451] + 4) = 0x18;
    iVar7 = FUN_00540fc0(param_1[0x451]);
    if (iVar7 != 0) {
      return 0xffffffff;
    }
    puVar5 = (undefined2 *)FUN_00541090(param_1[0x451],0,0,0);
    puVar5[3] = 2;
    puVar5[4] = 2;
    puVar5[5] = 3;
    puVar5[6] = 3;
    puVar5[1] = 1;
    puVar5[2] = 1;
    puVar5[9] = 5;
    puVar5[10] = 5;
    puVar5[0x13] = 5;
    *puVar5 = 0;
    puVar5[7] = 0;
    puVar5[8] = 4;
    puVar5[0xb] = 6;
    puVar5[0xc] = 6;
    puVar5[0xd] = 7;
    puVar5[0xe] = 7;
    puVar5[0xf] = 4;
    puVar5[0x10] = 0;
    puVar5[0x11] = 4;
    puVar5[0x12] = 1;
    puVar5[0x14] = 2;
    puVar5[0x15] = 6;
    puVar5[0x16] = 3;
    puVar5[0x17] = 7;
    FUN_005410f0(param_1[0x451]);
    if (piVar8 != (int *)0x0) {
      pvVar6 = operator_new(0x3c);
      if (pvVar6 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_005426a0();
      }
      param_1[0x547] = uVar2;
      iVar7 = FUN_00542950(param_1[0x555],param_1[0x555],param_1[0x556],0x40008);
      if (iVar7 != 0) {
        iVar7 = param_1[0x547];
        if (iVar7 != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar7);
        }
        param_1[0x547] = 0;
      }
      pvVar6 = operator_new(0x3c);
      if (pvVar6 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_005426a0();
      }
      param_1[0x548] = uVar2;
      iVar7 = FUN_00542950(param_1[0x555],param_1[0x555],param_1[0x556],0x40008);
      if (iVar7 != 0) {
        iVar7 = param_1[0x548];
        if (iVar7 != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar7);
        }
        param_1[0x548] = 0;
      }
      iVar7 = FUN_00544740();
      if (iVar7 != 0) {
        return 0xffffffff;
      }
      uVar2 = FUN_00545f40();
      FUN_00554c30(uVar2);
      FUN_005458d0(2);
    }
    for (puVar1 = (uint *)param_1[0x546]; puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[8]) {
      if ((*puVar1 & 2) == 0) {
        if ((*puVar1 & 1) != 0) {
          uVar2 = 1;
          goto LAB_0053f230;
        }
      }
      else {
        uVar2 = 2;
LAB_0053f230:
        FUN_00553370(uVar2);
      }
    }
    for (iVar7 = param_1[0x560]; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x870)) {
      FUN_005527c0();
    }
    param_1[0x4ea] = param_1[0x4ea] | 0x10000000;
  }
  return 0;
}


