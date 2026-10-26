// Function: FUN_004cc970 @ 004cc970
// Size (bytes): 445


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cc970(int param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  float10 fVar10;
  
  if (0 < *(int *)(param_1 + 0x58)) {
    uVar8 = DAT_008aae70 & 0xff;
    DAT_008aae70 = DAT_008aae70 + 1;
    *param_2 = *(float *)(&DAT_008ab274 + uVar8 * 4) + *(float *)(&DAT_008ab274 + uVar8 * 4) +
               *param_2;
    uVar8 = DAT_008aae70 & 0xff;
    DAT_008aae70 = DAT_008aae70 + 1;
    param_2[2] = *(float *)(&DAT_008ab274 + uVar8 * 4) + *(float *)(&DAT_008ab274 + uVar8 * 4) +
                 param_2[2];
    if (DAT_008ab6e4 == 2) {
      fVar9 = (float10)FUN_004b9ce0();
    }
    else {
      fVar9 = (float10)_DAT_008afea0;
    }
    FUN_004cc840();
    if (DAT_008ab6e4 == 2) {
      iVar6 = FUN_004b9e30();
      if (iVar6 == 5) {
        fVar10 = (float10)DAT_0059e440;
      }
      else {
        fVar10 = (float10)FUN_004b9cf0();
      }
    }
    else {
      fVar10 = (float10)_DAT_008afe98;
    }
    fVar4 = SQRT(param_3) * _DAT_0059e8cc;
    iVar6 = (int)ROUND((float)((float10)*(int *)(param_1 + 0x58) * fVar10 * (float10)SQRT(param_3) *
                              (float10)_DAT_005aceb4)) >>
            ((byte)*(undefined4 *)(param_1 + 8) & 0x1f);
    if (0 < iVar6) {
      fVar5 = (float)fVar9 + _DAT_005aceb0;
      do {
        iVar7 = FUN_004cb540();
        *(float *)(iVar7 + 8) = (float)fVar9;
        *(float *)(iVar7 + 0xc) = fVar5;
        DAT_008acedc = DAT_008acedc + 1 & 0x7f;
        iVar3 = *(int *)(iVar7 + 0x54);
        *(float *)(iVar7 + 0x2c) = (float)(&DAT_008acaa0)[DAT_008acedc * 2] + *param_2;
        *(float *)(iVar7 + 0x30) = param_2[1] + _DAT_0059e4dc;
        fVar1 = (float)(&DAT_008acaa4)[DAT_008acedc * 2];
        fVar2 = param_2[2];
        *(undefined4 *)(iVar7 + 0x38) = 0;
        *(float *)(iVar7 + 0x34) = fVar1 + fVar2;
        *(undefined4 *)(iVar7 + 0x3c) = (&DAT_008ac82c)[iVar3 * 10];
        *(undefined4 *)(iVar7 + 0x40) = 0;
        *(int *)(iVar7 + 0x60) = (int)ROUND(fVar4 * *(float *)(iVar7 + 0x28)) * 0x1000000 + 0xffffff
        ;
        FUN_004cc700(iVar7,&DAT_008ac830 + iVar3 * 10,&DAT_008ac83c + iVar3 * 10);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return;
}


