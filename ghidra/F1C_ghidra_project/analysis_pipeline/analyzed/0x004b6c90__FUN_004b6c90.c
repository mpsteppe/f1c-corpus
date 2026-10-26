// Function: FUN_004b6c90 @ 004b6c90
// Size (bytes): 1047


undefined4 __thiscall FUN_004b6c90(int param_1,undefined4 param_2)

{
  float fVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *pvVar6;
  float *pfVar7;
  byte *pbVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  byte local_113;
  byte local_112;
  byte local_111;
  int local_110;
  int *local_10c;
  int local_108;
  int local_104;
  undefined1 local_100 [256];
  
  uVar4 = FUN_004b8090(param_2);
  if ((char)uVar4 == '\0') {
    return uVar4;
  }
  FUN_00566c00(&local_108,4);
  FUN_00566c00(local_100,local_108);
  local_100[local_108] = 0;
  FUN_00566650(local_100);
  FUN_00566c00(&local_108,4);
  FUN_00566c00(local_100,local_108);
  local_100[local_108] = 0;
  FUN_00566650(local_100);
  local_112 = 0;
  FUN_00566c00(&local_112,1);
  *(uint *)(param_1 + 0xf1c) = (uint)local_112;
  local_111 = 0;
  FUN_00566c00(&local_111,1);
  *(uint *)(param_1 + 0xf20) = (uint)local_111;
  FUN_004b5e50();
  FUN_00566c00(&local_104,4);
  local_110 = 0;
  if (0 < local_104) {
    do {
      pbVar8 = (byte *)0x0;
      FUN_004ba780();
      puVar5 = *(undefined4 **)(param_1 + 0x18);
      if (puVar5 != (undefined4 *)0x0) {
        pbVar8 = (byte *)*puVar5;
        *(undefined1 *)(puVar5 + 2) = 0;
        cVar3 = FUN_004ba830(pbVar8,1);
        if (cVar3 == '\0') {
          pbVar8 = (byte *)0x0;
        }
      }
      if (pbVar8 == (byte *)0x0) {
        FUN_004bafc0();
        pbVar8 = (byte *)FUN_004bb0c0();
      }
      FUN_004b5040(param_2);
      piVar10 = (int *)((*pbVar8 + 4) * 0x10 + param_1);
      puVar5 = operator_new(0xc);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = pbVar8;
        puVar5[1] = 0;
        *(undefined1 *)(puVar5 + 2) = 0;
      }
      if (*piVar10 == 0) {
        *piVar10 = (int)puVar5;
        piVar10[2] = (int)puVar5;
      }
      else {
        *(undefined4 **)(piVar10[1] + 4) = puVar5;
      }
      piVar10[1] = (int)puVar5;
      piVar10[3] = piVar10[3] + 1;
      local_110 = local_110 + 1;
    } while (local_110 < local_104);
  }
  piVar10 = *(int **)(param_1 + 0x6c0);
  piVar2 = local_10c;
  while (local_10c = piVar10, local_10c != (int *)0x0) {
    piVar10 = (int *)local_10c[1];
    if (((char)local_10c[3] != '\0') && (*local_10c != 0)) {
      FUN_004bb460(1);
    }
    FUN_00587bcf(local_10c);
    piVar2 = local_10c;
  }
  *(undefined4 *)(param_1 + 0x6c0) = 0;
  *(undefined4 *)(param_1 + 0x6c4) = 0;
  *(undefined4 *)(param_1 + 0x6c8) = 0;
  *(undefined4 *)(param_1 + 0x6cc) = 0;
  local_113 = 0;
  local_10c = piVar2;
  FUN_00566c00(&local_113,1);
  local_110 = 0;
  if (local_113 != 0) {
    do {
      pvVar6 = operator_new(0xc);
      if (pvVar6 == (void *)0x0) {
        pvVar6 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)pvVar6 + 4) = 0;
        *(undefined4 *)((int)pvVar6 + 8) = 0xffffffff;
      }
      FUN_004b4250(param_2);
      if (pvVar6 != (void *)0x0) {
        puVar5 = operator_new(0x10);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = pvVar6;
          puVar5[1] = 0;
          puVar5[2] = 0;
          *(undefined1 *)(puVar5 + 3) = 1;
        }
        if (*(int *)(param_1 + 0x6c0) == 0) {
          *(undefined4 **)(param_1 + 0x6c0) = puVar5;
          *(undefined4 **)(param_1 + 0x6c8) = puVar5;
        }
        else {
          *(undefined4 **)(*(int *)(param_1 + 0x6c4) + 4) = puVar5;
          puVar5[2] = *(undefined4 *)(param_1 + 0x6c4);
        }
        *(undefined4 **)(param_1 + 0x6c4) = puVar5;
        *(int *)(param_1 + 0x6cc) = *(int *)(param_1 + 0x6cc) + 1;
      }
      local_110 = local_110 + 1;
    } while (local_110 < (int)(uint)local_113);
  }
  FUN_00566c00((int *)(param_1 + 0xf24),4);
  FUN_00566c00(param_1 + 0xf28,4);
  FUN_00566c00(param_1 + 0xf2c,4);
  FUN_004b5f60();
  local_110 = 0;
  if (0 < *(int *)(param_1 + 0xf24)) {
    local_10c = (int *)(param_1 + 0x30);
    do {
      piVar10 = local_10c;
      iVar11 = 0;
      FUN_004ba780();
      piVar10 = *(int **)((int)piVar10 + 8);
      if (piVar10 != (int *)0x0) {
        iVar11 = *piVar10;
        *(undefined1 *)(piVar10 + 2) = 0;
        cVar3 = FUN_004bb6b0(iVar11,1);
        if (cVar3 == '\0') {
          iVar11 = 0;
        }
      }
      if (iVar11 == 0) {
        FUN_004bb200();
        iVar11 = FUN_004bacf0();
      }
      FUN_004b44a0(param_2);
      if (iVar11 != 0) {
        piVar10 = operator_new(0x10);
        if (piVar10 == (int *)0x0) {
          piVar10 = (int *)0x0;
        }
        else {
          *piVar10 = iVar11;
          piVar10[1] = 0;
          piVar10[2] = 0;
          *(undefined1 *)(piVar10 + 3) = 0;
        }
        if (*(int *)(param_1 + 0x714) == 0) {
          *(int **)(param_1 + 0x714) = piVar10;
          *(int **)(param_1 + 0x71c) = piVar10;
        }
        else {
          *(int **)(*(int *)(param_1 + 0x718) + 4) = piVar10;
          piVar10[2] = *(int *)(param_1 + 0x718);
        }
        *(int **)(param_1 + 0x718) = piVar10;
        *(int *)(param_1 + 0x720) = *(int *)(param_1 + 0x720) + 1;
      }
      iVar9 = 0;
      if (*(short *)(iVar11 + 8) != 0) {
        do {
          FUN_004b43e0(param_2);
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(uint)*(ushort *)(iVar11 + 8));
      }
      local_110 = local_110 + 1;
    } while (local_110 < *(int *)(param_1 + 0xf24));
  }
  *(undefined4 *)(param_1 + 0xf30) = 0;
  *(undefined4 *)(param_1 + 0xf34) = 0;
  puVar5 = *(undefined4 **)(param_1 + 0x714);
  *(undefined4 **)(param_1 + 0x71c) = puVar5;
  pfVar7 = (float *)0x0;
  if ((puVar5 != (undefined4 *)0x0) && (pfVar7 = (float *)*puVar5, pfVar7 != (float *)0x0)) {
    fVar1 = *pfVar7;
    *(float *)(param_1 + 0xf30) = fVar1;
    *(float *)(param_1 + 0xf34) = fVar1 + *(float *)(param_1 + 0xf2c);
  }
  return CONCAT31((int3)((uint)pfVar7 >> 8),1);
}


