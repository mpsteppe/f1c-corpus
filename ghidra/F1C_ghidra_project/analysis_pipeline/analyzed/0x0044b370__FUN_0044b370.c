// Function: FUN_0044b370 @ 0044b370
// Size (bytes): 1409


void FUN_0044b370(int *param_1)

{
  uint uVar1;
  float fVar2;
  undefined8 uVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  undefined1 *puVar16;
  int local_260;
  int local_25c;
  uint *local_258 [2];
  int local_250;
  uint *local_24c;
  int local_248;
  int local_23c;
  undefined4 local_230;
  undefined8 uStack_22c;
  undefined4 uStack_224;
  undefined1 local_220 [16];
  undefined1 local_210 [16];
  undefined1 local_200 [4];
  undefined1 auStack_1fc [8];
  undefined4 uStack_1f4;
  double local_1f0;
  double local_1e8;
  double local_1e0;
  double local_1d8;
  int local_1a0 [103];
  
  FUN_004492b0();
  local_260 = *param_1;
  local_25c = local_260;
  FUN_004492d0(local_260 * 4);
  iVar13 = local_260;
  if (0 < local_260) {
    iVar14 = 0;
    do {
      iVar13 = 0;
      puVar10 = (undefined4 *)(param_1[2] + iVar14);
      do {
        puVar12 = (undefined4 *)*puVar10;
        uVar8 = puVar12[3];
        iVar6 = iVar13 + 0x10;
        uVar3 = *(undefined8 *)(puVar12 + 4);
        *(undefined4 *)(local_200 + iVar13) = *puVar12;
        *(undefined8 *)(auStack_1fc + iVar13) = uVar3;
        *(undefined4 *)((int)&uStack_1f4 + iVar13) = uVar8;
        puVar12 = (undefined4 *)puVar10[1];
        uVar8 = puVar12[3];
        uVar3 = *(undefined8 *)(puVar12 + 4);
        *(undefined4 *)((int)&local_230 + iVar13) = *puVar12;
        *(undefined8 *)((int)&uStack_22c + iVar13) = uVar3;
        *(undefined4 *)(local_220 + iVar13 + -4) = uVar8;
        iVar13 = iVar6;
        puVar10 = puVar10 + 2;
      } while (iVar6 < 0x30);
      FUN_00448ee0(local_258);
      FUN_004493a0(local_200,&local_230,local_210,local_258,0);
      FUN_004493a0(&local_230,&local_1f0,local_220,local_258,0);
      FUN_004493a0(local_210,local_220,&local_1e0,local_258,0);
      FUN_004493a0(local_220,local_210,&local_230,local_258,0);
      iVar14 = iVar14 + 0x20;
      local_260 = local_260 + -1;
      iVar13 = local_25c;
    } while (local_260 != 0);
  }
  FUN_00449700();
  FUN_00449340();
  local_258[0] = operator_new(iVar13 * 4);
  local_260 = 0;
  if (0 < iVar13) {
    do {
      iVar13 = 0;
      iVar14 = local_260 << 7;
      do {
        local_1a0[iVar13 + 6] = local_23c + iVar14;
        FUN_00449a80(local_23c + iVar14,0);
        iVar13 = iVar13 + 1;
        iVar14 = iVar14 + 0x20;
      } while (iVar13 < 4);
      uVar7 = FUN_0044b110(local_1a0 + 6);
      iVar13 = local_25c;
      local_258[0][local_260] = uVar7;
      local_260 = local_260 + 1;
    } while (local_260 < local_25c);
    if (0 < local_25c) {
      local_25c = 0;
      local_260 = iVar13;
      puVar15 = local_258[0];
      do {
        if (*puVar15 != 0) {
          iVar14 = 0;
          iVar6 = local_23c + local_25c;
          do {
            local_1a0[iVar14 + 6] = iVar6;
            iVar14 = iVar14 + 1;
            iVar6 = iVar6 + 0x20;
          } while (iVar14 < 4);
          FUN_0044af20(local_1a0,local_1a0 + 6);
          puVar16 = local_200;
          uVar8 = FUN_00448ee0(&local_250);
          FUN_0044b040(local_1a0,uVar8,puVar16);
          uVar7 = 0;
          do {
            uVar1 = uVar7 + 1;
            if (*puVar15 != uVar1) {
              pfVar4 = *(float **)(local_1a0[uVar7 + 6] + 4 + uVar7 * 8);
              fVar2 = pfVar4[3];
              *(double *)(pfVar4 + 4) =
                   (double)(((float)stack0xfffffe08 * fVar2 + (float)local_1e0) * fVar2 +
                            ((float)_local_200 * *pfVar4 + (float)local_1f0 * fVar2 +
                            (float)local_1e8) * *pfVar4 + (float)local_1d8);
              pfVar4 = *(float **)(local_1a0[((uVar7 == 2) - 1 & uVar1) + 6] + 4 + uVar7 * 8);
              fVar2 = pfVar4[3];
              *(double *)(pfVar4 + 4) =
                   (double)(((float)stack0xfffffe08 * fVar2 + (float)local_1e0) * fVar2 +
                            (*pfVar4 * (float)_local_200 + (float)local_1f0 * fVar2 +
                            (float)local_1e8) * *pfVar4 + (float)local_1d8);
            }
            uVar7 = uVar1;
          } while ((int)uVar1 < 3);
        }
        local_25c = local_25c + 0x80;
        puVar15 = puVar15 + 1;
        local_260 = local_260 + -1;
      } while (local_260 != 0);
    }
  }
  FUN_004492d0(iVar13);
  if (0 < iVar13) {
    local_260 = 0;
    puVar15 = local_258[0];
    local_250 = iVar13;
    do {
      iVar13 = 0;
      iVar14 = local_260 + local_23c;
      do {
        local_1a0[iVar13 + 6] = iVar14;
        iVar13 = iVar13 + 1;
        iVar14 = iVar14 + 0x20;
      } while (iVar13 < 4);
      local_24c = puVar15;
      FUN_00448ee0(&local_25c);
      switch(*puVar15) {
      case 0:
        local_248 = 0;
        do {
          iVar13 = -local_1a0[local_248 + 6];
          iVar14 = 3;
          puVar10 = (undefined4 *)local_1a0[local_248 + 6];
          puVar12 = &uStack_1f4;
          do {
            puVar5 = (undefined4 *)*puVar10;
            uVar8 = puVar5[3];
            uVar3 = *(undefined8 *)(puVar5 + 4);
            puVar11 = puVar10 + 2;
            iVar14 = iVar14 + -1;
            puVar12[-3] = *puVar5;
            *(undefined8 *)(puVar12 + -2) = uVar3;
            *puVar12 = uVar8;
            iVar6 = puVar10[1];
            *(undefined4 *)(local_220 + iVar13 + -0x18 + (int)puVar11) =
                 *(undefined4 *)(iVar6 + 0x10);
            *(undefined4 *)(local_220 + iVar13 + -0x14 + (int)puVar11) =
                 *(undefined4 *)(iVar6 + 0x14);
            puVar10 = puVar11;
            puVar12 = puVar12 + 4;
          } while (iVar14 != 0);
          FUN_004493a0(local_200,&local_1f0,&local_1e0,&local_25c,&local_230);
          local_248 = local_248 + 1;
          puVar15 = local_24c;
        } while (local_248 < 4);
        break;
      case 1:
      case 2:
      case 3:
        iVar13 = 0;
        do {
          FUN_0044af60(local_1a0,local_1a0 + 6,*puVar15,iVar13);
          iVar14 = 0;
          puVar10 = &uStack_1f4;
          do {
            puVar12 = *(undefined4 **)((int)local_1a0 + iVar14);
            uVar8 = puVar12[3];
            iVar9 = iVar14 + 8;
            uVar3 = *(undefined8 *)(puVar12 + 4);
            iVar6 = *(int *)((int)local_1a0 + iVar14 + 4);
            puVar10[-3] = *puVar12;
            *(undefined8 *)(puVar10 + -2) = uVar3;
            *puVar10 = uVar8;
            *(undefined4 *)((int)&local_230 + iVar14) = *(undefined4 *)(iVar6 + 0x10);
            *(undefined4 *)((int)&uStack_22c + iVar14) = *(undefined4 *)(iVar6 + 0x14);
            iVar14 = iVar9;
            puVar10 = puVar10 + 4;
          } while (iVar9 < 0x18);
          FUN_004493a0(local_200,&local_1f0,&local_1e0,&local_25c,&local_230);
          iVar13 = iVar13 + 1;
        } while (iVar13 < 2);
        break;
      case 4:
        FUN_0044af20(local_1a0,local_1a0 + 6);
        iVar13 = 0;
        puVar10 = &uStack_1f4;
        do {
          puVar12 = *(undefined4 **)((int)local_1a0 + iVar13);
          uVar8 = puVar12[3];
          iVar6 = iVar13 + 8;
          uVar3 = *(undefined8 *)(puVar12 + 4);
          iVar14 = *(int *)((int)local_1a0 + iVar13 + 4);
          puVar10[-3] = *puVar12;
          *(undefined8 *)(puVar10 + -2) = uVar3;
          *puVar10 = uVar8;
          *(undefined4 *)((int)&local_230 + iVar13) = *(undefined4 *)(iVar14 + 0x10);
          *(undefined4 *)((int)&uStack_22c + iVar13) = *(undefined4 *)(iVar14 + 0x14);
          iVar13 = iVar6;
          puVar10 = puVar10 + 4;
        } while (iVar6 < 0x18);
        FUN_004493a0(local_200,&local_1f0,&local_1e0,&local_25c,&local_230);
      }
      local_260 = local_260 + 0x80;
      puVar15 = puVar15 + 1;
      local_250 = local_250 + -1;
      local_24c = puVar15;
    } while (local_250 != 0);
  }
  FUN_00449340();
  if (local_258[0] != (uint *)0x0) {
    FUN_00587bcf(local_258[0]);
  }
  FUN_00449340();
  return;
}


