// Function: FUN_004bfa00 @ 004bfa00
// Size (bytes): 720


/* WARNING: Removing unreachable block (ram,0x004bfadb) */

int __thiscall FUN_004bfa00(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void *pvVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  float10 fVar13;
  int local_20;
  int local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  uVar11 = 0;
  iVar12 = 0;
  local_20 = 0;
  local_14 = 0;
  iVar2 = FUN_005871f0();
  uVar10 = DAT_008ac390;
  if (iVar2 < 1) {
    return 0;
  }
  local_c = (undefined4 *)0x0;
  if (DAT_008ac390 != 0) {
    do {
      puVar5 = (undefined4 *)(iVar12 + DAT_008ac394);
      puVar3 = (undefined1 *)*puVar5;
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      iVar4 = FUN_00588410(puVar3,param_3);
      if (iVar4 == 0) {
        puVar7 = operator_new(8);
        if (puVar7 != (undefined4 *)0x0) {
          *puVar7 = 0;
          puVar7[1] = 0xffffffff;
          FUN_00566650(puVar5 + 0x1f);
          local_c = operator_new(0xc);
          if (local_c == (undefined4 *)0x0) {
            local_c = (undefined4 *)0x0;
          }
          else {
            *local_c = puVar7;
            local_c[1] = 0;
            *(undefined1 *)(local_c + 2) = 1;
          }
        }
        break;
      }
      uVar11 = uVar11 + 1;
      iVar12 = iVar12 + 0x424;
    } while (uVar11 < uVar10);
  }
  param_3 = _rand();
  param_3 = param_3 << 1;
  local_10 = local_c;
  if (0 < param_2) {
    do {
      param_3 = param_3 % iVar2;
      iVar12 = FUN_004c5070(param_3);
      local_8 = local_10;
      if ((local_10 != (undefined4 *)0x0) &&
         (puVar5 = (undefined4 *)*local_10, puVar5 != (undefined4 *)0x0)) {
        do {
          puVar3 = (undefined1 *)*puVar5;
          if (puVar3 == (undefined1 *)0x0) {
            puVar3 = &DAT_005ea438;
          }
          iVar4 = FUN_00588410(iVar12 + 0x7c,puVar3);
          if (iVar4 == 0) goto LAB_004bfc44;
        } while (((local_8 != (undefined4 *)0x0) &&
                 (local_8 = (undefined4 *)local_8[1], local_8 != (undefined4 *)0x0)) &&
                (puVar5 = (undefined4 *)*local_8, puVar5 != (undefined4 *)0x0));
      }
      puVar5 = operator_new(8);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = 0xffffffff;
        puVar5[1] = 0;
      }
      uVar6 = FUN_004c50e0(param_3);
      *puVar5 = uVar6;
      fVar13 = (float10)FUN_004bf6a0(iVar12 + 0xbc);
      puVar5[1] = (float)fVar13;
      puVar7 = operator_new(0xc);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = puVar5;
        puVar7[1] = 0;
        *(undefined1 *)(puVar7 + 2) = 1;
      }
      if (*param_1 == 0) {
        *param_1 = (int)puVar7;
        param_1[2] = (int)puVar7;
      }
      else {
        *(undefined4 **)(param_1[1] + 4) = puVar7;
      }
      param_1[1] = (int)puVar7;
      param_1[3] = param_1[3] + 1;
      puVar8 = operator_new(8);
      puVar5 = local_10;
      puVar7 = local_c;
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = 0;
        puVar8[1] = 0xffffffff;
        FUN_00566650(iVar12 + 0x7c);
        pvVar9 = operator_new(0xc);
        if (pvVar9 == (void *)0x0) {
          puVar7 = (undefined4 *)0x0;
        }
        else {
          puVar7 = (undefined4 *)FUN_004bac20(puVar8,1);
        }
        puVar5 = puVar7;
        if (local_10 != (undefined4 *)0x0) {
          local_c[1] = puVar7;
          puVar5 = local_10;
        }
      }
      local_c = puVar7;
      local_10 = puVar5;
      local_20 = local_20 + 1;
LAB_004bfc44:
      uVar10 = _rand();
      uVar10 = uVar10 & 0x80000001;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
      }
      param_3 = uVar10 + 1 + param_3;
      local_14 = local_14 + 1;
    } while ((local_14 < 0xc9) && (local_20 < param_2));
  }
  iVar12 = FUN_004c2e20(*param_1);
  *param_1 = iVar12;
  iVar2 = iVar12;
  if (iVar12 != 0) {
    iVar4 = *(int *)(iVar12 + 4);
    while (iVar1 = iVar4, iVar1 != 0) {
      iVar2 = iVar1;
      iVar4 = *(int *)(iVar1 + 4);
    }
  }
  param_1[1] = iVar2;
  param_1[2] = iVar12;
  FUN_004c2f20();
  return local_20;
}


