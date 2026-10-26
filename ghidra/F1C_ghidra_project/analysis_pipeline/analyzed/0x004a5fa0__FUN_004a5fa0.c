// Function: FUN_004a5fa0 @ 004a5fa0
// Size (bytes): 593


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_004a5fa0(uint *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar5;
  undefined2 uVar6;
  bool bVar7;
  ushort uVar8;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [12];
  undefined1 local_30 [12];
  float local_24;
  float local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_4;
  
  FUN_00403f70(*(undefined4 *)(*param_1 + 0x48a4),&local_48,local_3c);
  uVar5 = *param_1;
  FUN_004efb20(&local_54,local_30);
  fVar1 = local_54 - local_48;
  fVar2 = local_50 - local_44;
  fVar3 = local_4c - local_40;
  if (fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3 <= _DAT_0059e8a0) {
    FUN_00566e40();
    fVar4 = local_1c * fVar1 + local_10 * fVar2 + local_4 * fVar3;
    if (fVar4 >= _DAT_0059e8a4 && (fVar4 == _DAT_0059e8a4) == 0) {
      return CONCAT22(extraout_var_00,
                      (ushort)(fVar4 < _DAT_0059e8a4) << 8 |
                      (ushort)(NAN(fVar4) || NAN(_DAT_0059e8a4)) << 10 |
                      (ushort)(fVar4 == _DAT_0059e8a4) << 0xe);
    }
    if (_DAT_0059f11c <= fVar4) {
      if (ABS(local_24 * fVar1 + local_18 * fVar2 + local_c * fVar3) <= _DAT_0059e8a4) {
        uVar8 = (ushort)(fVar4 < DAT_0059e440) << 8 |
                (ushort)(NAN(fVar4) || NAN(DAT_0059e440)) << 10 |
                (ushort)(fVar4 == DAT_0059e440) << 0xe;
        uVar6 = extraout_var_00;
        if (_DAT_0059e908 <=
            *(float *)(uVar5 + 0x34c4) * local_1c +
            *(float *)(uVar5 + 0x34d0) * local_10 + local_4 * *(float *)(uVar5 + 0x34dc)) {
          fVar1 = *(float *)(uVar5 + 0x3500);
          uVar6 = (undefined2)((uint)fVar1 >> 0x10);
          fVar1 = *(float *)(uVar5 + 0x34f8) * *(float *)(uVar5 + 0x34f8) +
                  fVar1 * fVar1 + *(float *)(uVar5 + 0x34fc) * *(float *)(uVar5 + 0x34fc);
          if (fVar4 < DAT_0059e440) {
            uVar5 = CONCAT22(uVar6,(ushort)(fVar1 < _DAT_0059e46c) << 8 |
                                   (ushort)(NAN(fVar1) || NAN(_DAT_0059e46c)) << 10 |
                                   (ushort)(fVar1 == _DAT_0059e46c) << 0xe);
            if (fVar1 >= _DAT_0059e46c && (fVar1 == _DAT_0059e46c) == 0) {
              return uVar5;
            }
          }
          else {
            uVar5 = CONCAT22(uVar6,(ushort)(fVar1 < _DAT_005acb50) << 8 |
                                   (ushort)(NAN(fVar1) || NAN(_DAT_005acb50)) << 10 |
                                   (ushort)(fVar1 == _DAT_005acb50) << 0xe);
            if (fVar1 >= _DAT_005acb50 && (fVar1 == _DAT_005acb50) == 0) {
              return uVar5;
            }
          }
          return CONCAT31((int3)(uVar5 >> 8),1);
        }
        goto LAB_004a6155;
      }
      uVar5 = CONCAT22(extraout_var_00,
                       (ushort)(fVar4 < DAT_0059e440) << 8 |
                       (ushort)(NAN(fVar4) || NAN(DAT_0059e440)) << 10 |
                       (ushort)(fVar4 == DAT_0059e440) << 0xe);
      if (fVar4 >= DAT_0059e440) goto LAB_004a617a;
      uVar5 = *(uint *)(*param_1 + 13000);
      bVar7 = uVar5 == 0;
    }
    else {
      FUN_0042adb0();
      uVar5 = *(uint *)(*param_1 + 13000);
      bVar7 = uVar5 == 0;
    }
  }
  else {
    FUN_00566e40();
    fVar1 = local_1c * fVar1 + local_10 * fVar2 + fVar3 * local_4;
    uVar8 = (ushort)(fVar1 < DAT_0059e440) << 8 | (ushort)(NAN(fVar1) || NAN(DAT_0059e440)) << 10 |
            (ushort)(fVar1 == DAT_0059e440) << 0xe;
    uVar6 = extraout_var;
LAB_004a6155:
    uVar5 = CONCAT22(uVar6,uVar8);
    if ((POPCOUNT((byte)(uVar8 >> 8) & 5) & 1U) == 0) goto LAB_004a617a;
    uVar5 = *param_1;
    bVar7 = *(int *)(uVar5 + 13000) == 0;
  }
  if ((bVar7) && (uVar5 = 0, DAT_007ce7a8 != 0)) {
    uVar5 = FUN_004a5c80(4);
  }
LAB_004a617a:
  return uVar5 & 0xffffff00;
}


