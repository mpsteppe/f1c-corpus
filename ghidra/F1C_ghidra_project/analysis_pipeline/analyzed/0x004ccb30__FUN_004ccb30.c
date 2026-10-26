// Function: FUN_004ccb30 @ 004ccb30
// Size (bytes): 653


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ccb30(int param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float local_44;
  int local_40;
  int local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  FUN_004cc840();
  if (DAT_008ab6e4 == 2) {
    fVar8 = (float10)FUN_004b9ce0();
  }
  else {
    fVar8 = (float10)_DAT_008afea0;
  }
  if (DAT_008ab6e4 == 2) {
    iVar5 = FUN_004b9e30();
    if (iVar5 == 5) {
      local_44 = 0.0;
      goto LAB_004ccb98;
    }
    fVar9 = (float10)FUN_004b9cf0();
  }
  else {
    fVar9 = (float10)_DAT_008afe98;
  }
  local_44 = (float)fVar9;
LAB_004ccb98:
  local_40 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 0x68) + local_40 * 4);
      if ((*(float *)(iVar5 + 0xc) < (float)fVar8) || ((float)fVar8 < *(float *)(iVar5 + 8))) {
        FUN_004cb5a0(iVar5);
        local_40 = local_40 + -1;
      }
      else {
        fVar3 = local_44 * *(float *)(iVar5 + 0x3c) + *(float *)(iVar5 + 0x30);
        *(float *)(iVar5 + 0x30) = fVar3;
        if ((DAT_007cfa04 & 3) != 0) {
          fVar4 = *(float *)(iVar5 + 0x3c) * _DAT_0059ed18;
          if (DAT_007cfa04 == 1) {
            if (DAT_007c54e0 != 0) {
              local_30 = *(float *)(DAT_007c54e0 + 0x744);
              local_2c = *(undefined4 *)(DAT_007c54e0 + 0x748);
              local_28 = *(float *)(DAT_007c54e0 + 0x74c);
              if ((ABS(local_30 - *(float *)(iVar5 + 0x2c)) < _DAT_0059e46c) &&
                 (ABS(local_28 - *(float *)(iVar5 + 0x34)) < _DAT_0059e46c)) {
                local_18 = *(undefined4 *)(iVar5 + 0x2c);
                local_14 = fVar3 - fVar4;
                local_10 = *(undefined4 *)(iVar5 + 0x34);
                FUN_004cbf50(&local_18,(undefined4 *)(iVar5 + 0x2c),DAT_007c54e0 + 0x6f0);
              }
            }
          }
          else {
            pfVar1 = (float *)(iVar5 + 0x2c);
            iVar6 = FUN_004c9c70(*(float *)(iVar5 + 0x2c) + *(float *)(iVar5 + 0x34),0x40b504f3,
                                 &local_34);
            iVar7 = 0;
            if (0 < local_34) {
              do {
                iVar2 = *(int *)(iVar6 + iVar7 * 4);
                local_24 = *(float *)(iVar2 + 0x738);
                local_20 = *(undefined4 *)(iVar2 + 0x73c);
                local_1c = *(float *)(iVar2 + 0x740);
                if (((ABS(local_24 - *pfVar1) < _DAT_0059e46c) &&
                    (ABS(local_1c - *(float *)(iVar5 + 0x34)) < _DAT_0059e46c)) &&
                   ((((byte)DAT_007cfa4c & 1) != 0 || (*(int *)(iVar2 + 4) != DAT_007c54dc)))) {
                  local_c = *pfVar1;
                  local_8 = *(float *)(iVar5 + 0x30) - fVar4;
                  local_4 = *(undefined4 *)(iVar5 + 0x34);
                  FUN_004cbf50(&local_c,pfVar1,iVar2 + 0x6e4);
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 < local_34);
            }
          }
        }
        FUN_004cc700(iVar5,&DAT_008ac830 + *(int *)(iVar5 + 0x54) * 10,
                     &DAT_008ac83c + *(int *)(iVar5 + 0x54) * 10);
      }
      local_40 = local_40 + 1;
    } while (local_40 < *(int *)(param_1 + 100));
  }
  return;
}


