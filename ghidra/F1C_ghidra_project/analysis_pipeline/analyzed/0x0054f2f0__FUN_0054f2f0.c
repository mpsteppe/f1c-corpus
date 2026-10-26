// Function: FUN_0054f2f0 @ 0054f2f0
// Size (bytes): 712


int __thiscall FUN_0054f2f0(float param_1,float param_2,float param_3)

{
  float *pfVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  ushort *puVar7;
  float10 fVar8;
  float10 fVar9;
  float local_3c;
  int local_38;
  int local_2c;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = *(int *)((int)param_3 + 300);
  iVar5 = *(int *)((int)param_1 + 0x204);
  local_18 = *(float *)(iVar5 + 0xe8);
  local_14 = *(float *)(iVar5 + 0xec);
  local_10 = *(float *)(iVar5 + 0xf0);
  puVar7 = *(ushort **)((int)param_3 + 0x124);
  local_38 = 0;
  local_2c = 0;
  if (*(int *)((int)param_3 + 0x120) < 1) {
    return 0;
  }
  do {
    pfVar6 = *(float **)((int)param_1 + 0x1e0);
    if ((local_14 - *(float *)(puVar7 + 10)) * (local_14 - *(float *)(puVar7 + 10)) +
        (local_18 - *(float *)(puVar7 + 8)) * (local_18 - *(float *)(puVar7 + 8)) +
        (local_10 - *(float *)(puVar7 + 0xc)) * (local_10 - *(float *)(puVar7 + 0xc)) <=
        (*(float *)(puVar7 + 0xe) + *pfVar6) * (*(float *)(puVar7 + 0xe) + *pfVar6)) {
      local_4 = *(int *)(*(int *)(puVar7 + 4) + 0xc);
      local_c = (uint)*puVar7 * 0x30 + local_4;
      local_8 = (uint)puVar7[1] * 0x30 + local_4;
      local_4 = (uint)puVar7[2] * 0x30 + local_4;
      piVar3 = (int *)pfVar6[2];
      local_3c = 0.0;
      if (0 < (int)pfVar6[1]) {
        pfVar6 = (float *)(piVar3 + 6);
        do {
          if (*piVar3 != 6) {
            iVar5 = *(int *)(puVar7 + 6) * 0x10 + iVar2;
            fVar8 = (float10)(**(code **)(*DAT_008b8f24 + 0x20))(iVar5,pfVar6 + -2);
            if ((float10)*(float *)(puVar7 + 0x10) < fVar8) {
              pfVar1 = pfVar6 + 4;
              fVar9 = (float10)(**(code **)(*DAT_008b8f24 + 0x20))(iVar5,pfVar1);
              if (fVar9 < (float10)*(float *)(puVar7 + 0x10)) {
                fVar8 = ((float10)*(float *)(puVar7 + 0x10) - (float10)(float)fVar8) /
                        (fVar9 - (float10)(float)fVar8);
                fStack_24 = (float)(((float10)*pfVar1 - (float10)pfVar6[-2]) * fVar8 +
                                   (float10)pfVar6[-2]);
                fStack_20 = (float)(((float10)pfVar6[5] - (float10)pfVar6[-1]) * fVar8 +
                                   (float10)pfVar6[-1]);
                fStack_1c = (float)(((float10)pfVar6[6] - (float10)*pfVar6) * fVar8 +
                                   (float10)*pfVar6);
                iVar5 = FUN_0054eb40(&fStack_24);
                if (iVar5 != 0) {
                  *piVar3 = 1;
                  pfVar6[9] = param_2;
                  pfVar6[10] = param_3;
                  pfVar6[7] = param_1;
                  pfVar6[8] = 0.0;
                  pfVar6[0xb] = *(float *)(*(int *)(puVar7 + 4) + 4);
                  pfVar6[0xc] = local_3c;
                  pfVar6[0x13] = fStack_24;
                  pfVar6[0x14] = fStack_20;
                  pfVar6[0x15] = fStack_1c;
                  pfVar6[0xd] = (float)puVar7;
                  pfVar6[0xe] = 0.0;
                  pfVar4 = (float *)(*(int *)(puVar7 + 6) * 0x10 + *(int *)((int)param_3 + 300));
                  pfVar6[0x10] = *pfVar4;
                  pfVar6[0x11] = pfVar4[1];
                  pfVar6[0x12] = pfVar4[2];
                  local_38 = local_38 + 1;
                  pfVar6[0x16] = SQRT((*pfVar1 - fStack_24) * (*pfVar1 - fStack_24) +
                                      (pfVar6[5] - fStack_20) * (pfVar6[5] - fStack_20) +
                                      (pfVar6[6] - fStack_1c) * (pfVar6[6] - fStack_1c));
                  FUN_00559a30(pfVar6 + 7);
                }
              }
            }
          }
          piVar3 = piVar3 + 0x1d;
          pfVar6 = pfVar6 + 0x1d;
          local_3c = (float)((int)local_3c + 1);
        } while ((int)local_3c < *(int *)(*(int *)((int)param_1 + 0x1e0) + 4));
      }
    }
    puVar7 = puVar7 + 0x12;
    local_2c = local_2c + 1;
  } while (local_2c < *(int *)((int)param_3 + 0x120));
  return local_38;
}


