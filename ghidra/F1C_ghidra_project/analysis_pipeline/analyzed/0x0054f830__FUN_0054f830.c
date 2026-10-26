// Function: FUN_0054f830 @ 0054f830
// Size (bytes): 454


undefined4 __thiscall FUN_0054f830(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  float *pfVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  float *pfVar13;
  undefined4 *puVar14;
  int local_4;
  
  iVar11 = (int)param_3;
  if ((*(int *)(param_1 + 0x1e0) != 0) && (*(int *)(*(int *)(param_1 + 0x1e0) + 8) != 0)) {
    FUN_0054fa50();
    FUN_00587bcf(*(undefined4 *)(param_1 + 0x1e0));
    *(undefined4 *)(param_1 + 0x1e0) = 0;
  }
  pvVar4 = operator_new(0x14);
  if (pvVar4 == (void *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_0054eb20();
  }
  *(int *)(param_1 + 0x1e0) = iVar5;
  *(float *)(iVar5 + 4) = param_3;
  pvVar4 = operator_new((int)param_3 * 0x74);
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else if (-1 < (int)param_3 + -1) {
    local_4 = (int)param_3;
    do {
      FUN_0054eaf0();
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  *(void **)(*(int *)(param_1 + 0x1e0) + 8) = pvVar4;
  puVar9 = *(undefined4 **)(*(int *)(param_1 + 0x1e0) + 8);
  for (uVar6 = (uint)((int)param_3 * 0x74) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar9 = 0;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  puVar9 = *(undefined4 **)(*(int *)(param_1 + 0x1e0) + 8);
  if (0 < (int)param_3) {
    puVar12 = (undefined4 *)(param_2 + 8);
    do {
      puVar9[1] = puVar12[-2];
      puVar9[2] = puVar12[-1];
      puVar9[3] = *puVar12;
      puVar9[7] = puVar12[1];
      puVar9[8] = puVar12[2];
      puVar9[9] = puVar12[3];
      *puVar9 = 0;
      puVar14 = puVar9 + 0xd;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      puVar9 = puVar9 + 0x1d;
      puVar12 = puVar12 + 8;
      param_3 = (float)((int)param_3 + -1);
    } while (param_3 != 0.0);
  }
  param_3 = 0.0;
  if (0 < iVar11) {
    iVar5 = *(int *)(param_1 + 0x204);
    pfVar8 = (float *)0x0;
    pfVar13 = (float *)((int)(*(float **)(param_1 + 0x1e0))[2] + 4);
    do {
      iVar10 = 0;
      pfVar7 = pfVar8;
      do {
        pfVar8 = pfVar13;
        if ((iVar10 != 0) && (pfVar8 = pfVar7, iVar10 == 1)) {
          pfVar8 = pfVar13 + 6;
        }
        fVar1 = *(float *)(iVar5 + 0xdc) - *pfVar8;
        fVar3 = *(float *)(iVar5 + 0xe0) - pfVar8[1];
        fVar2 = *(float *)(iVar5 + 0xe4) - pfVar8[2];
        fVar1 = fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2;
        if (param_3 <= fVar1) {
          param_3 = fVar1;
        }
        iVar10 = iVar10 + 1;
        pfVar7 = pfVar8;
      } while (iVar10 < 2);
      pfVar13 = pfVar13 + 0x1d;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  **(float **)(param_1 + 0x1e0) = SQRT(param_3);
  return 0;
}


