// Function: FUN_004bffa4 @ 004bffa4
// Size (bytes): 495


void FUN_004bffa4(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int unaff_ESI;
  int unaff_EDI;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  bool in_ZF;
  float10 fVar13;
  int iStack00000010;
  
  if (in_ZF) {
    iVar9 = 0;
    if (0 < unaff_ESI) {
      do {
        if ((iVar9 == 0) && (cVar4 = FUN_0042bc10(), cVar4 != '\0')) {
          puVar7 = DAT_007ce668;
          if (DAT_007ce668 == (undefined1 *)0x0) {
            puVar7 = &DAT_005ea438;
          }
        }
        else {
          puVar7 = &DAT_005f0cf8 + iVar9 * 0x48c0;
        }
        iVar10 = iVar9 * 0xc;
        uVar5 = FUN_004c0260(puVar7);
        *(undefined4 *)(&stack0x00000024 + iVar10) = uVar5;
        fVar13 = (float10)FUN_004c02d0(puVar7);
        *(float *)(&stack0x00000028 + iVar10) = (float)fVar13;
        *(int *)(&stack0x0000002c + iVar10) = iVar9;
        iVar9 = iVar9 + 1;
      } while (iVar9 < unaff_ESI);
    }
    iVar9 = 0;
    if (0 < unaff_ESI) {
      iStack00000010 = 0;
      iVar10 = iVar9;
      iVar6 = iStack00000010;
      iVar8 = iStack00000010;
      iVar11 = iVar9;
      do {
        for (; iVar9 < unaff_ESI; iVar9 = iVar9 + 1) {
          if (*(int *)(&stack0x00000024 + iVar6) < *(int *)(&stack0x00000024 + iVar8)) {
            iVar10 = iVar9;
            iVar8 = iVar6;
          }
          iVar6 = iVar6 + 0xc;
        }
        uVar5 = *(undefined4 *)(&stack0x00000024 + iStack00000010);
        uVar1 = *(undefined4 *)(&stack0x00000028 + iStack00000010);
        uVar2 = *(undefined4 *)(&stack0x0000002c + iStack00000010);
        iVar10 = iVar10 * 0xc;
        *(undefined4 *)(&stack0x00000024 + iStack00000010) =
             *(undefined4 *)(&stack0x00000024 + iVar10);
        *(undefined4 *)(&stack0x00000028 + iStack00000010) =
             *(undefined4 *)(&stack0x00000028 + iVar10);
        *(undefined4 *)(&stack0x0000002c + iStack00000010) =
             *(undefined4 *)(&stack0x0000002c + iVar10);
        *(undefined4 *)(&stack0x00000024 + iVar10) = uVar5;
        *(undefined4 *)(&stack0x00000028 + iVar10) = uVar1;
        iVar9 = iVar11 + 1;
        iVar6 = iStack00000010 + 0xc;
        *(undefined4 *)(&stack0x0000002c + iVar10) = uVar2;
        iVar10 = iVar9;
        iVar8 = iVar6;
        iStack00000010 = iVar6;
        iVar11 = iVar9;
      } while (iVar9 < unaff_ESI);
      if (0 < unaff_ESI) {
        puVar12 = (undefined4 *)&stack0x00000028;
        iVar9 = 1;
        do {
          iVar10 = puVar12[1];
          *(undefined4 *)(&DAT_005f0734 + iVar10 * 0x48c0) = *puVar12;
          (&DAT_005f0730)[iVar10 * 0x1230] = iVar9;
          FUN_004bc2f0(iVar9);
          puVar12 = puVar12 + 3;
          bVar3 = iVar9 < unaff_ESI;
          iVar9 = iVar9 + 1;
        } while (bVar3);
        return;
      }
    }
  }
  else {
    iVar9 = -1;
    cVar4 = FUN_0042bc10();
    iVar10 = 1;
    if (cVar4 != '\0') {
      unaff_EDI = 1;
      iVar9 = DAT_007d0110;
      if (DAT_007d0110 == 0) {
        iVar9 = _rand();
        iVar9 = iVar9 % unaff_ESI + 1;
      }
      if (iVar9 < 1) {
        iVar9 = 1;
      }
      else if (unaff_ESI < iVar9) {
        iVar9 = unaff_ESI;
      }
      *(int *)(DAT_007c54e8 + 0x4058) = iVar9;
      *(undefined4 *)(DAT_007c54e8 + 0x405c) = 0xbf800000;
      FUN_004bc2f0(iVar9);
    }
    if (unaff_EDI < unaff_ESI) {
      puVar12 = (undefined4 *)(&DAT_005f0734 + unaff_EDI * 0x48c0);
      iVar6 = unaff_ESI - unaff_EDI;
      do {
        if (iVar10 == iVar9) {
          iVar10 = iVar10 + 1;
        }
        puVar12[-1] = iVar10;
        *puVar12 = 0xbf800000;
        FUN_004bc2f0(iVar10);
        iVar10 = iVar10 + 1;
        puVar12 = puVar12 + 0x1230;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return;
}


