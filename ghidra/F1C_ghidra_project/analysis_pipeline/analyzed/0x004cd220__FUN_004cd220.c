
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004cd220(int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float fStack_b0;
  int iStack_a8;
  int iStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  float fStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_4;
  
  iVar4 = FUN_0040c870();
  fStack_90 = *(float *)(iVar4 + 0x24);
  fStack_8c = *(float *)(iVar4 + 0x28);
  fStack_88 = *(float *)(iVar4 + 0x2c);
  if (DAT_008ab6e4 == 2) {
    iVar4 = FUN_004b9e30();
    if (iVar4 == 5) {
      fStack_b0 = 0.0;
      goto LAB_004cd28d;
    }
    fVar7 = (float10)FUN_004b9cf0();
  }
  else {
    fVar7 = (float10)_DAT_008afe98;
  }
  fStack_b0 = (float)fVar7;
LAB_004cd28d:
  if (DAT_008ab6e4 == 2) {
    fVar7 = (float10)FUN_004b9ce0();
  }
  else {
    fVar7 = (float10)_DAT_008afea0;
  }
  iStack_a8 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    do {
      iVar4 = *(int *)(*(int *)(param_1 + 0x68) + iStack_a8 * 4);
      if ((*(float *)(iVar4 + 0xc) < (float)fVar7) || ((float)fVar7 < *(float *)(iVar4 + 8))) {
        FUN_004cb5a0(iVar4);
        iStack_a8 = iStack_a8 + -1;
      }
      else {
        pfVar1 = (float *)(iVar4 + 0x2c);
        *pfVar1 = fStack_b0 * *(float *)(iVar4 + 0x38) + *pfVar1;
        *(float *)(iVar4 + 0x30) = fStack_b0 * *(float *)(iVar4 + 0x3c) + *(float *)(iVar4 + 0x30);
        *(float *)(iVar4 + 0x34) = fStack_b0 * *(float *)(iVar4 + 0x40) + *(float *)(iVar4 + 0x34);
        *(float *)(iVar4 + 0x3c) = *(float *)(iVar4 + 0x3c) - ABS(fStack_b0) * _DAT_005aceb8;
        fVar2 = *pfVar1 * *(float *)(iVar4 + 0x54) +
                *(float *)(iVar4 + 0x30) * *(float *)(iVar4 + 0x58) +
                *(float *)(iVar4 + 0x34) * *(float *)(iVar4 + 0x5c);
        if (fVar2 < *(float *)(iVar4 + 100)) {
          fVar2 = *(float *)(iVar4 + 100) - fVar2;
          fStack_44 = fVar2 * *(float *)(iVar4 + 0x58);
          fStack_40 = fVar2 * *(float *)(iVar4 + 0x5c);
          *pfVar1 = fVar2 * *(float *)(iVar4 + 0x54) + *pfVar1;
          *(float *)(iVar4 + 0x30) = fStack_44 + *(float *)(iVar4 + 0x30);
          *(float *)(iVar4 + 0x34) = fStack_40 + *(float *)(iVar4 + 0x34);
          fVar2 = *(float *)(iVar4 + 0x38) * *(float *)(iVar4 + 0x54) +
                  *(float *)(iVar4 + 0x3c) * *(float *)(iVar4 + 0x58) +
                  *(float *)(iVar4 + 0x40) * *(float *)(iVar4 + 0x5c);
          fVar2 = fVar2 + fVar2;
          fStack_2c = fVar2 * *(float *)(iVar4 + 0x58);
          fStack_28 = fVar2 * *(float *)(iVar4 + 0x5c);
          *(float *)(iVar4 + 0x38) = *(float *)(iVar4 + 0x38) - fVar2 * *(float *)(iVar4 + 0x54);
          *(float *)(iVar4 + 0x3c) = *(float *)(iVar4 + 0x3c) - fStack_2c;
          *(float *)(iVar4 + 0x40) = *(float *)(iVar4 + 0x40) - fStack_28;
          fVar2 = *(float *)(iVar4 + 0x38);
          if (fStack_b0 < DAT_0059e440) {
            *(float *)(iVar4 + 0x38) = fVar2 + fVar2;
            *(float *)(iVar4 + 0x3c) = *(float *)(iVar4 + 0x3c) + *(float *)(iVar4 + 0x3c);
            *(float *)(iVar4 + 0x40) = *(float *)(iVar4 + 0x40) + *(float *)(iVar4 + 0x40);
          }
          else {
            *(float *)(iVar4 + 0x38) = fVar2 * _DAT_0059e450;
            *(float *)(iVar4 + 0x3c) = *(float *)(iVar4 + 0x3c) * _DAT_0059e450;
            *(float *)(iVar4 + 0x40) = *(float *)(iVar4 + 0x40) * _DAT_0059e450;
          }
        }
        if ((DAT_007cfa4c & 3) != 0) {
          fStack_9c = *(float *)(iVar4 + 0x38) * _DAT_0059ed18;
          fStack_98 = *(float *)(iVar4 + 0x3c) * _DAT_0059ed18;
          fStack_94 = *(float *)(iVar4 + 0x40) * _DAT_0059ed18;
          if (DAT_007cfa4c == 1) {
            if (DAT_007c54e0 != 0) {
              fStack_60 = *(float *)(DAT_007c54e0 + 0x744);
              uStack_5c = *(undefined4 *)(DAT_007c54e0 + 0x748);
              fStack_58 = *(float *)(DAT_007c54e0 + 0x74c);
              if ((ABS(fStack_60 - *pfVar1) < _DAT_0059e46c) &&
                 (ABS(fStack_58 - *(float *)(iVar4 + 0x34)) < _DAT_0059e46c)) {
                fStack_6c = fStack_9c + *pfVar1;
                fStack_68 = fStack_98 + *(float *)(iVar4 + 0x30);
                fStack_64 = fStack_94 + *(float *)(iVar4 + 0x34);
                fStack_18 = fStack_6c;
                fStack_14 = fStack_68;
                fStack_10 = fStack_64;
                FUN_004cbf50(&fStack_18,pfVar1,DAT_007c54e0 + 0x6f0);
              }
            }
          }
          else {
            iVar5 = FUN_004c9c70(*pfVar1 + *(float *)(iVar4 + 0x34),0x40b504f3,&iStack_a0);
            iVar6 = 0;
            if (0 < iStack_a0) {
              do {
                iVar3 = *(int *)(iVar5 + iVar6 * 4);
                fStack_54 = *(float *)(iVar3 + 0x738);
                uStack_50 = *(undefined4 *)(iVar3 + 0x73c);
                fStack_4c = *(float *)(iVar3 + 0x740);
                if (((ABS(fStack_54 - *pfVar1) < _DAT_0059e46c) &&
                    (ABS(fStack_4c - *(float *)(iVar4 + 0x34)) < _DAT_0059e46c)) &&
                   (((DAT_007cfa4c & 1) != 0 || (*(int *)(iVar3 + 4) != DAT_007c54dc)))) {
                  fStack_78 = fStack_9c + *pfVar1;
                  fStack_74 = fStack_98 + *(float *)(iVar4 + 0x30);
                  fStack_70 = fStack_94 + *(float *)(iVar4 + 0x34);
                  fStack_3c = fStack_78;
                  fStack_38 = fStack_74;
                  fStack_34 = fStack_70;
                  FUN_004cbf50(&fStack_3c,pfVar1,iVar3 + 0x6e4);
                }
                iVar6 = iVar6 + 1;
              } while (iVar6 < iStack_a0);
            }
          }
        }
        fStack_4 = *(float *)(iVar4 + 0x40) - fStack_88;
        fStack_84 = (*(float *)(iVar4 + 0x38) - fStack_90) * _DAT_0059ed18;
        fStack_80 = (*(float *)(iVar4 + 0x3c) - fStack_8c) * _DAT_0059ed18;
        fStack_7c = fStack_4 * _DAT_0059ed18;
        fStack_24 = fStack_84;
        fStack_20 = fStack_80;
        fStack_1c = fStack_7c;
        FUN_004cc500(iVar4,&fStack_24);
      }
      iStack_a8 = iStack_a8 + 1;
    } while (iStack_a8 < *(int *)(param_1 + 100));
  }
  return;
}

