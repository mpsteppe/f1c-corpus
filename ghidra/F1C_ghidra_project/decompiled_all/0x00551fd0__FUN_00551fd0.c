// Function: FUN_00551fd0 @ 00551fd0
// Strings:  [Error opening bitmap file %s, Error allocating temp surface memory, %sGRAB_%.3d.BMP, GRAB_%.3d.BMP]


undefined4 __thiscall
FUN_00551fd0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  void *pvVar4;
  void *pvVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  int local_258;
  undefined4 *local_254;
  undefined2 local_240;
  int local_23e;
  undefined2 local_23a;
  undefined2 local_238;
  undefined4 local_236;
  undefined4 local_232;
  int local_22e;
  int local_22a;
  undefined2 local_226;
  undefined2 local_224;
  undefined4 local_222;
  undefined4 local_21e;
  undefined4 local_21a;
  undefined4 local_216;
  undefined4 local_212;
  undefined4 local_20e;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  iVar2 = DAT_008cbf48;
  DAT_008cbf48 = DAT_008cbf48 + 1;
  if (param_6 == 0) {
    FUN_0058815f(local_200,s_GRAB___3d_BMP_005dc0f8);
  }
  else {
    FUN_0058815f(local_200,s__sGRAB___3d_BMP_005dc0e8,param_6,iVar2);
  }
  iVar2 = FUN_00587db0(local_200,&DAT_005c2ab0);
  if (iVar2 == 0) {
    FUN_0058815f(local_100,s_Error_opening_bitmap_file__s_005dbdec,local_200);
    FUN_0053c590(0xffffffff,local_100);
    return 0xffffffff;
  }
  local_258 = param_4 * param_5;
  uVar1 = local_258 * 3;
  pcVar3 = operator_new(uVar1);
  iVar13 = (param_4 + 3U & 0xfffffffc) * param_5;
  pvVar4 = operator_new(iVar13 * 3);
  local_23e = iVar13 * 3 + 0x36;
  local_21a = 0xe74;
  local_216 = 0xe74;
  local_240 = 0x4d42;
  local_23a = 0;
  local_238 = 0;
  local_236 = 0x36;
  local_232 = 0x28;
  local_22e = param_4;
  local_22a = param_5;
  local_226 = 1;
  local_224 = 0x18;
  local_222 = 0;
  local_21e = 0;
  local_212 = 0;
  local_20e = 0;
  FUN_00588678(&local_240,1,0xe,iVar2);
  FUN_00588678(&local_232,1,0x28,iVar2);
  pvVar5 = operator_new(0x3c);
  if (pvVar5 == (void *)0x0) {
    local_254 = (undefined4 *)0x0;
  }
  else {
    local_254 = (undefined4 *)FUN_005426a0();
  }
  iVar13 = FUN_00542950(param_4,param_5,*(undefined4 *)(param_1 + 0x30),0x11);
  if (iVar13 == 0) {
    FUN_00543250(param_2,param_3,local_254,0,0,param_4,param_5,0xfffffffe,0);
    if ((local_254[6] & 1) == 0) {
      uVar6 = 2;
      if ((local_254[6] & 2) == 0) {
        uVar6 = uVar1;
      }
    }
    else {
      uVar6 = 1;
    }
    iVar11 = 0;
    puVar7 = (ushort *)FUN_00543210(uVar6 | 0x100,0);
    *local_254 = puVar7;
    iVar13 = *(int *)(param_1 + 0x30);
    if (iVar13 == 5) {
      pcVar12 = pcVar3;
      if (0 < local_258) {
        do {
          *pcVar12 = (char)*puVar7 << 3;
          puVar8 = puVar7 + 1;
          pcVar12[1] = (byte)(*puVar7 >> 2) & 0xf8;
          pcVar12[2] = (byte)(*puVar7 >> 7) & 0xf8;
          iVar11 = iVar11 + 1;
          if (iVar11 == param_4) {
            iVar11 = 0;
            puVar8 = puVar8 + (local_254[10] + param_4 * -2 >> 1);
          }
          local_258 = local_258 + -1;
          puVar7 = puVar8;
          pcVar12 = pcVar12 + 3;
        } while (local_258 != 0);
      }
    }
    else if (iVar13 == 6) {
      pcVar12 = pcVar3;
      if (0 < local_258) {
        do {
          *pcVar12 = (char)*puVar7 << 3;
          puVar8 = puVar7 + 1;
          pcVar12[1] = (byte)(*puVar7 >> 3) & 0xfc;
          pcVar12[2] = *(byte *)((int)puVar7 + 1) & 0xf8;
          iVar11 = iVar11 + 1;
          if (iVar11 == param_4) {
            iVar11 = 0;
            puVar8 = puVar8 + (local_254[10] + param_4 * -2 >> 1);
          }
          local_258 = local_258 + -1;
          puVar7 = puVar8;
          pcVar12 = pcVar12 + 3;
        } while (local_258 != 0);
      }
    }
    else if (iVar13 == 7) {
      pcVar12 = pcVar3;
      if (0 < local_258) {
        do {
          *pcVar12 = (char)*puVar7;
          pcVar12[1] = *(char *)((int)puVar7 + 1);
          pcVar12[2] = (char)puVar7[1];
          puVar7 = (ushort *)((int)puVar7 + 3);
          iVar11 = iVar11 + 1;
          if (iVar11 == param_4) {
            iVar11 = 0;
            puVar7 = (ushort *)((int)puVar7 + local_254[10] + param_4 * -3);
          }
          local_258 = local_258 + -1;
          pcVar12 = pcVar12 + 3;
        } while (local_258 != 0);
      }
    }
    else if ((iVar13 == 8) && (pcVar12 = pcVar3, 0 < local_258)) {
      do {
        *pcVar12 = (char)*puVar7;
        pcVar12[1] = *(char *)((int)puVar7 + 1);
        pcVar12[2] = (char)puVar7[1];
        puVar7 = puVar7 + 2;
        iVar11 = iVar11 + 1;
        if (iVar11 == param_4) {
          iVar11 = 0;
          puVar7 = (ushort *)((int)puVar7 + local_254[10] + param_4 * -4);
        }
        local_258 = local_258 + -1;
        pcVar12 = pcVar12 + 3;
      } while (local_258 != 0);
    }
    FUN_00543230(0,0);
    *local_254 = 0;
    FUN_00542e50();
    FUN_00557470();
    FUN_00587bcf(local_254);
    uVar6 = param_4 * 3;
    uVar10 = 0;
    if (0 < param_5) {
      pcVar12 = pcVar3 + (param_5 + -1) * uVar6;
      local_258 = param_5;
      do {
        pcVar14 = pcVar12;
        pcVar15 = (char *)((int)pvVar4 + uVar10);
        for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
          pcVar14 = pcVar14 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar9 = uVar6 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar15 = *pcVar14;
          pcVar14 = pcVar14 + 1;
          pcVar15 = pcVar15 + 1;
        }
        pcVar12 = pcVar12 + param_4 * -3;
        uVar10 = uVar6 + 3 + uVar10 & 0xfffffffc;
        local_258 = local_258 + -1;
      } while (local_258 != 0);
    }
    FUN_00588678(pvVar4,1,uVar1,iVar2);
    FUN_00587d02(iVar2);
    FUN_00587bcf(pcVar3);
    FUN_00587bcf(pvVar4);
    return 0;
  }
  FUN_0053c590(0xffffffff,s_Error_allocating_temp_surface_me_005dc0c0);
  return 0xffffffff;
}


