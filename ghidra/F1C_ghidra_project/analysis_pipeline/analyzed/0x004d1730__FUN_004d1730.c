// Function: FUN_004d1730 @ 004d1730
// Size (bytes): 787


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d1730(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  uint *puVar5;
  int extraout_EDX;
  int iVar6;
  int iVar7;
  uint *puVar8;
  
  if (0 < *(int *)(param_1 + 0x10c)) {
    do {
      FUN_004d0f00(0);
    } while (extraout_EDX + 1 < *(int *)(param_1 + 0x10c));
  }
  iVar7 = 0;
  if (0 < DAT_005c329c) {
    do {
      iVar6 = (&DAT_007c54f0)[iVar7];
      if (*(int *)(iVar6 + 0x4064) != 2) {
        iVar1 = *(int *)(iVar6 + 0x3aa8);
        if (*(int *)(iVar1 + 300) == 0) {
          fVar2 = *(float *)(iVar1 + 0x8c) - _DAT_0059f118;
          fVar3 = *(float *)(iVar1 + 0x8c) * _DAT_005acee8;
          if (fVar2 <= fVar3) {
            fVar2 = fVar3;
          }
        }
        else {
          fVar2 = _DAT_0059e670;
          if (*(char *)(iVar6 + 0x344c) == '\0') {
            fVar2 = *(float *)(param_1 + 0xd4) * _DAT_0059e450;
          }
        }
        if ((((DAT_007c56a4 == 7) && (DAT_007c56a8 == 5)) &&
            ((float)_DAT_008afea0 < *(float *)(param_1 + 0xb0) + _DAT_0059e8ec)) &&
           (fVar3 = ((float)_DAT_008afea0 - *(float *)(param_1 + 0xb0)) * _DAT_0059e940 -
                    _DAT_0059e5fc, fVar3 < fVar2)) {
          fVar2 = fVar3;
        }
        if (*(float *)(iVar1 + 0xa4) * *(float *)(iVar6 + 0x34f8) +
            *(float *)(iVar1 + 0xa8) * *(float *)(iVar6 + 0x34fc) +
            *(float *)(iVar1 + 0xac) * *(float *)(iVar6 + 0x3500) < fVar2) {
          FUN_004f0050();
          __ftol();
          FUN_004d0f00(2);
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_005c329c);
  }
  bVar4 = false;
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x10c)) {
    do {
      iVar6 = *(int *)(*(int *)(param_1 + 0x110) + iVar7 * 8);
      iVar1 = *(int *)(*(int *)(param_1 + 0x114) + iVar7 * 4);
      if (iVar1 != iVar6) {
        FUN_0041b3c0(iVar6,iVar1,*(undefined4 *)(*(int *)(param_1 + 0x110) + iVar7 * 8 + 4),0,0);
        *(undefined4 *)(*(int *)(param_1 + 0x114) + iVar7 * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x110) + iVar7 * 8);
        bVar4 = true;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x10c));
    if (bVar4) goto LAB_004d1940;
  }
  if (_DAT_008afea0 - (double)*(float *)(param_1 + 0x118) <= (double)_DAT_0059e7ec) {
    return;
  }
LAB_004d1940:
  *(float *)(param_1 + 0x118) = (float)_DAT_008afea0;
  puVar8 = DAT_008aae64;
  if (DAT_0083ee60 < 0x3ff) {
    DAT_0083ee60 = DAT_0083ee60 + 1;
    DAT_008aae64 = DAT_008aae64 + 0x6c;
  }
  FUN_004b33b0(4,10,0,0xff,(float)_DAT_008afea0,0);
  iVar7 = 0;
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x10c)) {
    do {
      puVar5 = DAT_008aae64;
      iVar1 = *(int *)(*(int *)(param_1 + 0x110) + iVar6 * 8);
      if (iVar1 != 0) {
        if (0xf < iVar7) {
          if (DAT_0083ee60 < 0x3ff) {
            DAT_0083ee60 = DAT_0083ee60 + 1;
            DAT_008aae64 = DAT_008aae64 + 0x6c;
          }
          FUN_004b33b0(4,0xb,0,0xff,(float)_DAT_008afea0,0);
          iVar7 = 0;
          puVar8 = puVar5;
        }
        *(short *)((int)puVar8 + iVar7 * 2 + 8) = (short)(iVar6 << 6) + (short)iVar1;
        iVar7 = iVar7 + 1;
        *puVar8 = *puVar8 & 0xfffc00ff | iVar7 * 0x200;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x10c));
  }
  return;
}


