// Function: FUN_004e2760 @ 004e2760
// Size (bytes): 659


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __fastcall FUN_004e2760(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  float *pfVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  undefined2 local_28;
  undefined2 local_24;
  undefined2 local_20;
  short local_1c [6];
  int local_10 [4];
  
  iVar12 = 0;
  piVar11 = (int *)(param_1 + 0x108);
  do {
    if (*piVar11 < 0x18) {
      iVar10 = *piVar11 >> 3;
    }
    else {
      iVar10 = 3;
    }
    iVar6 = __ftol();
    iVar7 = __ftol();
    local_10[iVar12] = iVar7 + (iVar6 + iVar10 * 8) * 8;
    sVar5 = __ftol();
    local_1c[iVar12] = sVar5;
    iVar12 = iVar12 + 1;
    piVar11 = piVar11 + 0x4a;
  } while (iVar12 < 4);
  piVar11 = (int *)(param_1 + 0x938);
  *piVar11 = ((local_10[0] * 0x100 + local_10[1]) * 0x100 + local_10[2]) * 0x100 + local_10[3];
  *(short *)(param_1 + 0x93c) =
       ((local_1c[0] * 0x10 + local_1c[1]) * 0x10 + local_1c[2]) * 0x10 + local_1c[3];
  cVar1 = __ftol();
  cVar2 = __ftol();
  cVar3 = __ftol();
  *(char *)(param_1 + 0x93e) = (cVar1 * '\b' + cVar2) * '\x04' + cVar3;
  if (*(char *)(param_1 + 0x98c) != '\0') {
    *(undefined4 *)(param_1 + 0x940) = 0;
    iVar12 = 0;
    pfVar9 = (float *)(param_1 + 0x9a8);
    do {
      if (*(char *)(pfVar9 + -6) != '\0') {
        *(uint *)(param_1 + 0x940) = *(uint *)(param_1 + 0x940) | 1 << ((byte)iVar12 & 0x1f);
        bVar4 = *(byte *)(pfVar9 + -6);
        if (0xf < bVar4) {
          bVar4 = 0xf;
        }
        bVar8 = *(byte *)((int)pfVar9 + -0x17);
        if (0xf < bVar8) {
          bVar8 = 0xf;
        }
        *(byte *)(param_1 + 0x93f) = bVar4 * '\x10' + bVar8;
        if (pfVar9[-2] <= _DAT_0059e710) {
          if (_DAT_0059e70c <= pfVar9[-2]) {
            local_28 = (undefined2)(int)ROUND(pfVar9[-2] * _DAT_0059e708);
          }
          else {
            local_28 = 0x8001;
          }
        }
        else {
          local_28 = 0x7fff;
        }
        *(undefined2 *)(param_1 + 0x944) = local_28;
        if (pfVar9[-1] <= _DAT_0059e710) {
          if (_DAT_0059e70c <= pfVar9[-1]) {
            local_24 = (undefined2)(int)ROUND(pfVar9[-1] * _DAT_0059e708);
          }
          else {
            local_24 = 0x8001;
          }
        }
        else {
          local_24 = 0x7fff;
        }
        *(undefined2 *)(param_1 + 0x946) = local_24;
        if (*pfVar9 <= _DAT_0059e710) {
          if (_DAT_0059e70c <= *pfVar9) {
            local_20 = (undefined2)(int)ROUND(*pfVar9 * _DAT_0059e708);
          }
          else {
            local_20 = 0x8001;
          }
        }
        else {
          local_20 = 0x7fff;
        }
        *(undefined2 *)(param_1 + 0x948) = local_20;
      }
      iVar12 = iVar12 + 1;
      pfVar9 = pfVar9 + 7;
    } while (iVar12 < 0x11);
    return piVar11;
  }
  *(undefined1 *)(param_1 + 0x93f) = 0;
  *(undefined4 *)(param_1 + 0x940) = 0;
  *(undefined2 *)(param_1 + 0x944) = 0;
  *(undefined2 *)(param_1 + 0x946) = 0;
  *(undefined2 *)(param_1 + 0x948) = 0;
  return piVar11;
}


