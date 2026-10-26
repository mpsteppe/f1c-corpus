// Function: FUN_0054eed0 @ 0054eed0
// Size (bytes): 1045


int __thiscall FUN_0054eed0(float param_1,float param_2,float param_3)

{
  float *pfVar1;
  float fVar2;
  ushort uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  ushort *puVar8;
  float10 fVar9;
  float10 fVar10;
  float fStack_6c;
  int local_68;
  int local_5c;
  int local_58;
  float local_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  local_58 = *(int *)((int)param_3 + 300);
  puVar8 = *(ushort **)((int)param_3 + 0x124);
  local_68 = 0;
  local_5c = 0;
  iVar4 = 0;
  if (0 < *(int *)((int)param_3 + 0x120)) {
    do {
      (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,puVar8 + 8,&local_54,(int)param_2 + 0x114);
      iVar4 = *(int *)((int)param_1 + 0x204);
      fStack_3c = *(float *)(iVar4 + 0xe8) - local_54;
      fStack_38 = *(float *)(iVar4 + 0xec) - fStack_50;
      fStack_34 = *(float *)(iVar4 + 0xf0) - fStack_4c;
      fVar2 = *(float *)(puVar8 + 0xe) + **(float **)((int)param_1 + 0x1e0);
      fVar9 = (float10)(**(code **)(*DAT_008b8f24 + 0x20))(&fStack_3c,&fStack_3c);
      if (fVar9 <= (float10)fVar2 * (float10)fVar2) {
        iVar4 = *(int *)(puVar8 + 4);
        iVar6 = (int)param_2 + 0x1a0;
        (**(code **)(*DAT_008b8f24 + 4))
                  (DAT_008b8f24,(uint)*puVar8 * 0x30 + *(int *)(iVar4 + 0xc),auStack_24,iVar6);
        (**(code **)(*DAT_008b8f24 + 4))
                  (DAT_008b8f24,(uint)puVar8[1] * 0x30 + *(int *)(iVar4 + 0xc),auStack_18,iVar6);
        (**(code **)(*DAT_008b8f24 + 4))
                  (DAT_008b8f24,(uint)puVar8[2] * 0x30 + *(int *)(iVar4 + 0xc),auStack_c,iVar6);
        puStack_30 = auStack_24;
        puStack_28 = auStack_c;
        puStack_2c = auStack_18;
        piVar5 = *(int **)(*(int *)((int)param_1 + 0x1e0) + 8);
        fStack_6c = 0.0;
        if (0 < *(int *)(*(int *)((int)param_1 + 0x1e0) + 4)) {
          pfVar7 = (float *)(piVar5 + 6);
          do {
            if (*piVar5 != 6) {
              (**(code **)*DAT_008b8f24)
                        (DAT_008b8f24,*(int *)(puVar8 + 6) * 0x10 + local_58,&local_54,
                         (int)param_2 + 0x114);
              fVar9 = (float10)(**(code **)(*DAT_008b8f24 + 0x20))(&local_54,auStack_24);
              *(float *)(puVar8 + 0x10) = (float)fVar9;
              pfVar1 = pfVar7 + -2;
              fVar9 = (float10)(**(code **)(*DAT_008b8f24 + 0x20))(&local_5c,pfVar1);
              if (((float10)*(float *)(puVar8 + 0x10) < fVar9) &&
                 (fVar10 = (float10)(**(code **)(*DAT_008b8f24 + 0x20))(&local_54,pfVar7 + 4),
                 fVar10 < (float10)*(float *)(puVar8 + 0x10))) {
                fVar9 = ((float10)*(float *)(puVar8 + 0x10) - (float10)(float)fVar9) /
                        (fVar10 - (float10)(float)fVar9);
                fStack_48 = (float)(((float10)pfVar7[4] - (float10)*pfVar1) * fVar9 +
                                   (float10)*pfVar1);
                fStack_44 = (float)(((float10)pfVar7[5] - (float10)pfVar7[-1]) * fVar9 +
                                   (float10)pfVar7[-1]);
                fStack_40 = (float)(((float10)pfVar7[6] - (float10)*pfVar7) * fVar9 +
                                   (float10)*pfVar7);
                if (ABS(local_54) <= ABS(fStack_50)) {
                  if (ABS(fStack_50) <= ABS(fStack_4c)) goto LAB_0054f1a8;
                  uVar3 = 2;
                  if (fStack_50 <= DAT_0059e440) {
                    uVar3 = 3;
                  }
                }
                else if (ABS(local_54) <= ABS(fStack_4c)) {
LAB_0054f1a8:
                  uVar3 = 4;
                  if (fStack_4c <= DAT_0059e440) {
                    uVar3 = 5;
                  }
                }
                else if (local_54 <= DAT_0059e440) {
                  uVar3 = 1;
                }
                else {
                  uVar3 = 0;
                }
                puVar8[3] = uVar3;
                iVar4 = FUN_0054eb40(&fStack_48);
                if (iVar4 != 0) {
                  *piVar5 = 1;
                  pfVar7[9] = param_2;
                  pfVar7[10] = param_3;
                  pfVar7[8] = 0.0;
                  pfVar7[7] = param_1;
                  pfVar7[0xb] = *(float *)(*(int *)(puVar8 + 4) + 4);
                  pfVar7[0xe] = 0.0;
                  pfVar7[0xc] = fStack_6c;
                  pfVar7[0x13] = fStack_48;
                  pfVar7[0x14] = fStack_44;
                  pfVar7[0x15] = fStack_40;
                  pfVar7[0xd] = (float)puVar8;
                  pfVar7[0x10] = local_54;
                  pfVar7[0x11] = fStack_50;
                  pfVar7[0x12] = fStack_4c;
                  local_68 = local_68 + 1;
                  pfVar7[0x16] = SQRT((pfVar7[4] - fStack_48) * (pfVar7[4] - fStack_48) +
                                      (pfVar7[5] - fStack_44) * (pfVar7[5] - fStack_44) +
                                      (pfVar7[6] - fStack_40) * (pfVar7[6] - fStack_40));
                  FUN_00559a30(pfVar7 + 7);
                }
              }
            }
            piVar5 = piVar5 + 0x1d;
            pfVar7 = pfVar7 + 0x1d;
            fStack_6c = (float)((int)fStack_6c + 1);
          } while ((int)fStack_6c < *(int *)(*(int *)((int)param_1 + 0x1e0) + 4));
        }
      }
      puVar8 = puVar8 + 0x12;
      local_5c = local_5c + 1;
      iVar4 = local_68;
    } while (local_5c < *(int *)((int)param_3 + 0x120));
  }
  return iVar4;
}


