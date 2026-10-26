// Function: FUN_00550ad0 @ 00550ad0
// Size (bytes): 1183


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00550ad0(uint *param_1,int param_2,uint param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  void *pvVar8;
  uint *puVar9;
  int *extraout_EDX;
  uint *puVar10;
  uint uVar11;
  int local_14;
  int local_10;
  
  puVar10 = (uint *)0x0;
  if (param_3 == 0) {
    iVar3 = FUN_0058ace6(param_2);
    FUN_00587f64(param_2,0,2);
    iVar4 = FUN_0058ace6(param_2);
    param_3 = iVar4 - iVar3;
    FUN_00587f64(param_2,iVar3,0);
  }
  else {
    iVar3 = *(int *)(param_3 + 0x124) * 0x100;
    iVar4 = iVar3 + *(int *)(param_3 + 0x128);
    if ((*(byte *)(iVar3 + *(int *)(param_3 + 0x128)) & 0x10) != 0) {
      uVar11 = *(uint *)(iVar4 + 0xc);
      DAT_008b8f30 = operator_new(*(uint *)(iVar4 + 8));
      DAT_008b8f34 = operator_new(uVar11);
      uVar5 = FUN_0058803f(DAT_008b8f34,1,uVar11,param_2);
      if (uVar5 != uVar11) {
        FUN_00587bcf(DAT_008b8f30);
        FUN_00587bcf(DAT_008b8f34);
        return 0xffffffff;
      }
      FUN_0059b260(DAT_008b8f34,uVar11);
      goto LAB_00550b7b;
    }
    iVar3 = FUN_0058ace6(param_2);
    FUN_00587f64(param_2,0,2);
    iVar4 = FUN_0058ace6(param_2);
    param_3 = iVar4 - iVar3;
    FUN_00587f64(param_2,iVar3,0);
  }
  DAT_008b8f30 = operator_new(param_3);
  uVar11 = FUN_0058803f(DAT_008b8f30,1,param_3,param_2);
  if (uVar11 != param_3) {
    FUN_00587bcf(DAT_008b8f30);
    return 0xffffffff;
  }
LAB_00550b7b:
  DAT_008b8f3c = 0;
  FUN_0054a5c0(0x10);
  FUN_0054a5c0(4);
  pfVar1 = (float *)(param_1 + 1);
  FUN_0054a5c0(4);
  FUN_0054a5c0(4);
  *pfVar1 = _DAT_0059e43c / *pfVar1;
  FUN_00589901(param_1 + 7);
  if ((*param_1 & 2) == 0) {
    if ((*param_1 & 1) != 0) {
      FUN_0054a5c0(4);
      uVar11 = param_1[3];
      puVar10 = operator_new(uVar11 * 0x2c + 4);
      if (puVar10 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        puVar6 = puVar10 + 1;
        *puVar10 = uVar11;
        if (-1 < (int)(uVar11 - 1)) {
          do {
            FUN_005507e0();
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
      }
      param_1[4] = (uint)puVar6;
      param_2 = 0;
      if (0 < (int)param_1[3]) {
        local_10 = 0;
        do {
          iVar3 = param_1[4] + local_10;
          FUN_0054a5c0(0x20);
          FUN_0054a5c0(4);
          puVar10 = (uint *)(iVar3 + 0x24);
          FUN_0054a5c0(4);
          uVar11 = *puVar10;
          puVar6 = operator_new(uVar11 * 0x20 + 4);
          if (puVar6 == (uint *)0x0) {
            puVar9 = (uint *)0x0;
          }
          else {
            puVar9 = puVar6 + 1;
            *puVar6 = uVar11;
            if (-1 < (int)(uVar11 - 1)) {
              do {
                FUN_005507a0();
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
            }
          }
          *(uint **)(iVar3 + 0x28) = puVar9;
          FUN_0054a5c0(*puVar10 << 5);
          local_14 = 0;
          if (0 < (int)*puVar10) {
            iVar4 = 0;
            do {
              fVar2 = (float)local_14;
              local_14 = local_14 + 1;
              *(float *)(iVar4 + *(int *)(iVar3 + 0x28)) = fVar2 * *pfVar1;
              iVar4 = iVar4 + 0x20;
            } while (local_14 < (int)*puVar10);
          }
          if ((int)param_1[5] < (int)*puVar10) {
            param_1[5] = *puVar10;
          }
          param_2 = param_2 + 1;
          local_10 = local_10 + 0x2c;
        } while (param_2 < (int)param_1[3]);
      }
      param_1[2] = (uint)((float)(int)param_1[5] * *pfVar1);
    }
  }
  else {
    FUN_0054a5c0(4);
    uVar11 = param_1[5];
    puVar6 = operator_new(uVar11 * 0xc + 4);
    if (puVar6 != (uint *)0x0) {
      *puVar6 = uVar11;
      puVar10 = puVar6 + 1;
      if (-1 < (int)(uVar11 - 1)) {
        do {
          FUN_005593b0();
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
    }
    param_1[6] = (uint)puVar10;
    param_2 = 0;
    if (0 < (int)param_1[5]) {
      local_14 = 0;
      do {
        iVar4 = param_1[6] + local_14;
        FUN_0054a5c0(4);
        iVar3 = *(int *)(iVar4 + 4);
        piVar7 = operator_new(iVar3 * 8 + 4);
        if (piVar7 == (int *)0x0) {
          piVar7 = (int *)0x0;
        }
        else {
          *piVar7 = iVar3;
          piVar7 = piVar7 + 1;
          if (-1 < iVar3 + -1) {
            do {
              FUN_00550800();
              iVar3 = iVar3 + -1;
              piVar7 = extraout_EDX;
            } while (iVar3 != 0);
          }
        }
        iVar3 = 0;
        *(int **)(iVar4 + 8) = piVar7;
        if (0 < *(int *)(iVar4 + 4)) {
          do {
            piVar7 = (int *)(*(int *)(iVar4 + 8) + iVar3 * 8);
            FUN_0054a5c0(4);
            pvVar8 = operator_new(*piVar7 * 0x24);
            piVar7[1] = (int)pvVar8;
            FUN_0054a5c0(*piVar7 * 0x24);
            iVar3 = iVar3 + 1;
          } while (iVar3 < *(int *)(iVar4 + 4));
        }
        param_2 = param_2 + 1;
        local_14 = local_14 + 0xc;
      } while (param_2 < (int)param_1[5]);
    }
  }
  if (DAT_008b8f30 != (void *)0x0) {
    FUN_00587bcf(DAT_008b8f30);
  }
  if (DAT_008b8f34 != (void *)0x0) {
    FUN_00587bcf(DAT_008b8f34);
  }
  return 0;
}


