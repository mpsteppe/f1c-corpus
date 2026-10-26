// Function: FUN_00441650 @ 00441650
// Size (bytes): 1151


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00441650(int param_1,float param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  double *pdVar9;
  double *pdVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  float10 fVar13;
  undefined8 uStack_f0;
  int iStack_e8;
  double dStack_b0;
  double dStack_a8;
  double dStack_a0;
  double dStack_88;
  undefined4 auStack_80 [8];
  double dStack_60;
  undefined4 auStack_50 [19];
  
  if ((_DAT_005d6d70 == _DAT_0059e420) || (DAT_007ce254 == '\0')) {
    iVar5 = FUN_00567740();
    FUN_004441f0();
    dVar1 = *(double *)(param_1 + 0x68);
    while( true ) {
      dVar4 = *(double *)(param_1 + 0x60);
      dVar3 = *(double *)(param_1 + 0x60);
      FUN_00441d60();
      dVar2 = dVar1 * _DAT_0059e880;
      FUN_004414d0(dVar2);
      *(double *)(param_1 + 0x60) = dVar2 + *(double *)(param_1 + 0x60);
      FUN_00441d60();
      uStack_f0._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
      uStack_f0._0_4_ = SUB84(dVar1,0);
      fVar13 = (float10)FUN_00441600((undefined4)uStack_f0,uStack_f0._4_4_);
      uStack_f0 = dVar1;
      if (fVar13 < (float10)_DAT_0059e420) {
        if ((DAT_007ce958 != 0) && (dVar1 != *(double *)(param_1 + 0x68))) {
          fVar13 = ((float10)*(double *)(param_1 + 0x68) / (float10)dVar1) * fVar13;
        }
        if (fVar13 < (float10)_DAT_0059e420) {
          uStack_f0 = dVar2;
          if (fVar13 <= (float10)_DAT_0059e880) {
            uStack_f0 = (double)(fVar13 * (float10)_DAT_0059ed38 * (float10)dVar1);
          }
          if (uStack_f0 < _DAT_0059ed30) {
            uStack_f0 = 3.814697265625e-06;
          }
          FUN_00441360();
          dVar2 = uStack_f0 * _DAT_0059e880;
          FUN_004414d0(dVar2);
          *(double *)(param_1 + 0x60) = dVar2 + dVar3;
          FUN_00441d60();
          FUN_00441600((undefined4)uStack_f0,uStack_f0._4_4_);
        }
      }
      if (dVar1 < uStack_f0 != (dVar1 == uStack_f0)) break;
      *(double *)(param_1 + 0x60) = dVar4 + uStack_f0;
      dVar1 = dVar1 - uStack_f0;
    }
    *(double *)(param_1 + 0x1658) = *(double *)(param_1 + 0x844) + *(double *)(param_1 + 0x3e0);
    *(double *)(param_1 + 0x60) = (double)param_2;
    FUN_0043ef20();
    pdVar9 = (double *)(param_1 + 0x338);
    iVar8 = 4;
    do {
      fVar13 = (float10)FUN_0058957a();
      *pdVar9 = (double)fVar13;
      FUN_00438130(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c));
      pdVar9 = (double *)((int)pdVar9 + 0x464);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    FUN_00438690(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                 *(undefined4 *)(param_1 + 0x3ec));
    FUN_00438690(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                 *(undefined4 *)(param_1 + 0x850));
    if (*(int *)(param_1 + 0x141c) == 0) {
      FUN_00438690(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                   *(undefined4 *)(param_1 + 0xcb4));
      uVar6 = *(undefined4 *)(param_1 + 0x1118);
    }
    else {
      FUN_00438690(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),
                   *(int *)(param_1 + 0x141c));
      uVar6 = *(undefined4 *)(param_1 + 0x141c);
    }
    FUN_00438690(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),uVar6);
    pdVar9 = (double *)(param_1 + 0x310);
    iStack_e8 = 4;
    do {
      iVar8 = *(int *)((int)pdVar9 + 0xdc);
      if ((iVar8 != 0) && (*(char *)(pdVar9 + 0x28) == '\0')) {
        iVar7 = *(int *)(param_1 + 0x15f0);
        dStack_60 = *(double *)(iVar8 + 0x1c) * *(double *)(iVar7 + 0x24) +
                    *(double *)(iVar8 + 0x34) * *(double *)(iVar7 + 0x3c) +
                    *(double *)(iVar8 + 0x4c) * *(double *)(iVar7 + 0x54);
        if ((*(double *)(iVar8 + 0x1c) * *(double *)(iVar7 + 0x1c) +
             *(double *)(iVar8 + 0x34) * *(double *)(iVar7 + 0x34) +
             *(double *)(iVar8 + 0x4c) * *(double *)(iVar7 + 0x4c) < _DAT_0059e880) ||
           (_DAT_0059e830 < ABS(dStack_60))) {
          dStack_88 = *(double *)(iVar7 + 0x4c) * pdVar9[-1] +
                      *(double *)(iVar7 + 0x5c) * pdVar9[1] + *(double *)(iVar7 + 0x54) * *pdVar9;
          dStack_b0 = pdVar9[-1] * *(double *)(iVar7 + 0x1c) +
                      *(double *)(iVar7 + 0x2c) * pdVar9[1] + *(double *)(iVar7 + 0x24) * *pdVar9 +
                      *(double *)(iVar7 + 4);
          dStack_a8 = *(double *)(iVar7 + 0x34) * pdVar9[-1] +
                      *(double *)(iVar7 + 0x44) * pdVar9[1] + *(double *)(iVar7 + 0x3c) * *pdVar9 +
                      *(double *)(iVar7 + 0xc);
          dStack_a0 = dStack_88 + *(double *)(iVar7 + 0x14);
          pdVar10 = (double *)(iVar7 + 0x1c);
          puVar11 = auStack_50;
          for (iVar8 = 0x12; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar11 = *(undefined4 *)pdVar10;
            pdVar10 = (double *)((int)pdVar10 + 4);
            puVar11 = puVar11 + 1;
          }
          FUN_0056bde0(pdVar9 + 2,0);
          puVar11 = (undefined4 *)(*(int *)(param_1 + 0x15f0) + 0x7c);
          puVar12 = auStack_80;
          for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          puVar11 = *(undefined4 **)((int)pdVar9 + 0xdc);
          pdVar10 = &dStack_b0;
          for (iVar8 = 6; puVar11 = puVar11 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar11 = *(undefined4 *)pdVar10;
            pdVar10 = (double *)((int)pdVar10 + 4);
          }
          iVar8 = *(int *)((int)pdVar9 + 0xdc);
          puVar11 = auStack_50;
          puVar12 = (undefined4 *)(iVar8 + 0x1c);
          for (iVar7 = 0x12; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          FUN_005692a0();
          puVar11 = auStack_80;
          puVar12 = (undefined4 *)(iVar8 + 0x7c);
          for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
          FUN_00569410();
          FUN_00441450();
        }
      }
      pdVar9 = (double *)((int)pdVar9 + 0x464);
      iStack_e8 = iStack_e8 + -1;
    } while (iStack_e8 != 0);
    if (iVar5 != 0x200) {
      FUN_00567780();
    }
  }
  return;
}


