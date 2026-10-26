// Function: FUN_00449000 @ 00449000
// Size (bytes): 446


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00449000(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  uint in_EAX;
  float *pfVar11;
  undefined2 uVar12;
  float *pfVar13;
  float *pfVar14;
  ushort uVar15;
  
  if (((param_1 == param_3) && (param_2 == param_4)) ||
     ((param_1 == param_4 && (param_2 == param_3)))) goto LAB_004490b8;
  uVar15 = (ushort)(in_EAX >> 0x10);
  pfVar11 = (float *)((uint)uVar15 << 0x10);
  pfVar13 = param_1;
  pfVar14 = param_2;
  if (*param_2 == *param_1) {
    fVar1 = *param_4;
    fVar2 = *param_3;
    in_EAX = CONCAT22(uVar15,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10
                             | (ushort)(fVar1 == fVar2) << 0xe);
    pfVar11 = param_2;
    pfVar13 = param_3;
    param_3 = param_1;
    pfVar14 = param_4;
    param_4 = param_2;
    if (fVar1 == fVar2) goto LAB_004490b8;
  }
  dVar6 = (double)*pfVar13;
  dVar5 = (double)*pfVar14 - dVar6;
  dVar9 = (double)pfVar14[3] - (double)pfVar13[3];
  dVar3 = (double)*param_3;
  dVar4 = (double)(*param_4 - *param_3);
  dVar8 = (double)param_4[3] - (double)param_3[3];
  dVar10 = -((_DAT_0059e420 / dVar5) * dVar9);
  dVar7 = dVar4 * dVar10 + dVar8;
  uVar15 = (ushort)(dVar7 < _DAT_0059e430) << 8 | (ushort)(NAN(dVar7) || NAN(_DAT_0059e430)) << 10 |
           (ushort)(dVar7 == _DAT_0059e430) << 0xe;
  uVar12 = (undefined2)((uint)pfVar11 >> 0x10);
  if (dVar7 != _DAT_0059e430) {
    dVar7 = ((dVar10 * dVar6 + (double)pfVar13[3]) - (dVar10 * dVar3 + (double)param_3[3])) / dVar7;
    in_EAX = CONCAT22(uVar12,(ushort)(dVar7 < _DAT_0059e430) << 8 |
                             (ushort)(NAN(dVar7) || NAN(_DAT_0059e430)) << 10 |
                             (ushort)(dVar7 == _DAT_0059e430) << 0xe);
    if ((dVar7 < _DAT_0059e430 != (dVar7 == _DAT_0059e430)) ||
       (in_EAX = CONCAT22(uVar12,(ushort)(dVar7 < _DAT_0059e420) << 8 |
                                 (ushort)(NAN(dVar7) || NAN(_DAT_0059e420)) << 10 |
                                 (ushort)(dVar7 == _DAT_0059e420) << 0xe), dVar7 >= _DAT_0059e420))
    goto LAB_004490b8;
    dVar3 = ((dVar7 * dVar4 + dVar3) - dVar6) * (_DAT_0059e420 / dVar5);
    in_EAX = CONCAT22(uVar12,(ushort)(dVar3 < _DAT_0059e430) << 8 |
                             (ushort)(NAN(dVar3) || NAN(_DAT_0059e430)) << 10 |
                             (ushort)(dVar3 == _DAT_0059e430) << 0xe);
    if ((dVar3 < _DAT_0059e430 != (dVar3 == _DAT_0059e430)) ||
       (in_EAX = CONCAT22(uVar12,(ushort)(dVar3 < _DAT_0059e420) << 8 |
                                 (ushort)(NAN(dVar3) || NAN(_DAT_0059e420)) << 10 |
                                 (ushort)(dVar3 == _DAT_0059e420) << 0xe), dVar3 >= _DAT_0059e420))
    goto LAB_004490b8;
    dVar5 = SQRT(dVar5 * dVar5 + dVar9 * dVar9);
    dVar3 = dVar5 * dVar3;
    in_EAX = CONCAT22(uVar12,(ushort)(dVar3 < _DAT_0059ea08) << 8 |
                             (ushort)(NAN(dVar3) || NAN(_DAT_0059ea08)) << 10 |
                             (ushort)(dVar3 == _DAT_0059ea08) << 0xe);
    if (dVar3 < _DAT_0059ea08 != (dVar3 == _DAT_0059ea08)) goto LAB_004490b8;
    dVar5 = dVar5 - _DAT_0059ea08;
    in_EAX = CONCAT22(uVar12,(ushort)(dVar3 < dVar5) << 8 | (ushort)(NAN(dVar3) || NAN(dVar5)) << 10
                             | (ushort)(dVar3 == dVar5) << 0xe);
    if (dVar3 >= dVar5) goto LAB_004490b8;
    dVar3 = SQRT(dVar4 * dVar4 + dVar8 * dVar8);
    dVar7 = dVar7 * dVar3;
    uVar15 = (ushort)(dVar7 < _DAT_0059ea08) << 8 | (ushort)(NAN(dVar7) || NAN(_DAT_0059ea08)) << 10
             | (ushort)(dVar7 == _DAT_0059ea08) << 0xe;
    if (dVar7 < _DAT_0059ea08 == (dVar7 == _DAT_0059ea08)) {
      dVar3 = dVar3 - _DAT_0059ea08;
      in_EAX = CONCAT22(uVar12,(ushort)(dVar7 < dVar3) << 8 |
                               (ushort)(NAN(dVar7) || NAN(dVar3)) << 10 |
                               (ushort)(dVar7 == dVar3) << 0xe);
      if (dVar7 < dVar3) {
        return CONCAT31((int3)(in_EAX >> 8),1);
      }
      goto LAB_004490b8;
    }
  }
  in_EAX = CONCAT22(uVar12,uVar15);
LAB_004490b8:
  return in_EAX & 0xffffff00;
}


