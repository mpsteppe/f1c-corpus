// Function: FUN_0043fffb @ 0043fffb
// Size (bytes): 4850


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043fffb(void)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int extraout_ECX;
  int iVar10;
  double *pdVar11;
  double *pdVar12;
  int iVar13;
  int iVar14;
  int unaff_EBP;
  int unaff_ESI;
  int *piVar15;
  int unaff_EDI;
  bool bVar16;
  float10 in_ST0;
  double in_stack_00000010;
  double dStack00000018;
  int in_stack_00000024;
  double dStack00000028;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  int in_stack_00000044;
  double dStack00000048;
  double in_stack_00000050;
  double in_stack_00000058;
  double in_stack_00000060;
  double in_stack_00000068;
  double in_stack_00000070;
  double in_stack_00000078;
  double in_stack_00000080;
  undefined4 in_stack_00000088;
  undefined4 in_stack_0000008c;
  double in_stack_00000090;
  double in_stack_00000098;
  double in_stack_000000a0;
  double in_stack_000000a8;
  double in_stack_000000b0;
  double in_stack_000000b8;
  double in_stack_000000c0;
  double in_stack_000000c8;
  double in_stack_000000d0;
  double in_stack_000000d8;
  double in_stack_000000e0;
  double in_stack_000000e8;
  double in_stack_000000f0;
  double in_stack_000000f8;
  double in_stack_00000108;
  double in_stack_00000110;
  double in_stack_00000140;
  double in_stack_00000148;
  double in_stack_00000150;
  double in_stack_00000158;
  double in_stack_00000160;
  double in_stack_00000168;
  double in_stack_00000170;
  double in_stack_00000178;
  double in_stack_00000180;
  double in_stack_00000188;
  double in_stack_00000190;
  double in_stack_00000198;
  double in_stack_000002b0;
  double dVar17;
  
  dStack00000018 = (double)(in_ST0 * (float10)_DAT_0059ec10);
  dStack00000048 = (double)(in_ST0 * (float10)_DAT_0059ec10 * (float10)dStack00000018);
  dStack00000028 =
       (*(double *)(unaff_ESI + 0x1074) + *(double *)(unaff_ESI + 0xc10)) * dStack00000018;
  cVar7 = FUN_00435290();
  if (cVar7 == '\0') {
    if (dStack00000028 <= *(double *)(unaff_ESI + 0x1e38)) {
      unaff_EDI = 1;
      in_stack_00000010 = -(double)CONCAT44(in_stack_0000003c,in_stack_00000038);
    }
    else {
      in_stack_00000010 = (double)CONCAT44(in_stack_0000003c,in_stack_00000038);
    }
  }
  else {
    bVar16 = extraout_ECX == unaff_EDI;
    unaff_EDI = 0;
    if (bVar16) {
      in_stack_00000010 = -(double)CONCAT44(in_stack_0000008c,in_stack_00000088);
    }
    else if (extraout_ECX == 0) {
      in_stack_00000010 = -in_stack_000000f0;
    }
    else if (extraout_ECX == 1) {
      in_stack_00000010 = (double)CONCAT44(in_stack_0000008c,in_stack_00000088);
    }
  }
  in_stack_00000010 = in_stack_00000010 * dStack00000018;
  dVar17 = *(double *)(unaff_EBP + 8) * _DAT_0059e880;
  _uStack00000030 =
       (in_stack_000000d8 * dVar17 * *(double *)(unaff_ESI + 0xc28) + *(double *)(unaff_ESI + 0xc10)
       ) - (in_stack_000000e0 * dVar17 * *(double *)(unaff_ESI + 0x108c) +
           *(double *)(unaff_ESI + 0x1074));
  dVar1 = _uStack00000030 * *(double *)(unaff_ESI + 0x1e18);
  if (_uStack00000030 <= _DAT_0059e430) {
    if (_uStack00000030 < _DAT_0059e430) {
      if (in_stack_00000010 <= _DAT_0059e430) {
        dVar1 = in_stack_00000010 * *(double *)(unaff_ESI + 0x1e28) + dVar1;
      }
      else {
        dVar1 = dVar1 - in_stack_00000010 * *(double *)(unaff_ESI + 0x1e20);
      }
      dVar1 = dVar1 - *(double *)(unaff_ESI + 0x1e30);
    }
  }
  else if (in_stack_00000010 <= _DAT_0059e430) {
    dVar1 = (dVar1 - in_stack_00000010 * *(double *)(unaff_ESI + 0x1e28)) +
            *(double *)(unaff_ESI + 0x1e30);
  }
  else {
    dVar1 = in_stack_00000010 * *(double *)(unaff_ESI + 0x1e20) + dVar1 +
            *(double *)(unaff_ESI + 0x1e30);
  }
  dVar1 = dVar1 * _DAT_0059e880;
  dStack00000028 =
       (-(dVar17 * dVar1 * *(double *)(unaff_ESI + 0xc28)) -
       dVar17 * dVar1 * *(double *)(unaff_ESI + 0x108c)) + _uStack00000030;
  if (((_DAT_0059e430 <= _uStack00000030) && (dStack00000028 < _DAT_0059e430)) ||
     ((_uStack00000030 < _DAT_0059e430 != (_uStack00000030 == _DAT_0059e430) &&
      (_DAT_0059e430 < dStack00000028)))) {
    dVar1 = (_uStack00000030 / (_uStack00000030 - dStack00000028)) * dVar1;
  }
  in_stack_000000d8 = in_stack_000000d8 - dVar1;
  in_stack_000000e0 = dVar1 + in_stack_000000e0;
LAB_00440210:
  do {
    puVar8 = (undefined4 *)&stack0x000001a0;
    for (iVar10 = 0x54; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    iVar10 = *(int *)(in_stack_00000044 + 0x1e14);
    if (iVar10 == 0) {
      pdVar11 = (double *)(in_stack_00000044 + 0x368);
      iVar10 = 0;
      pdVar12 = (double *)&stack0x000001d0;
      puVar8 = (undefined4 *)&stack0x000001a0;
      do {
        iVar13 = *(int *)(&stack0x00000118 + iVar10 * 4);
        *puVar8 = 0;
        puVar8[1] = 0x3ff00000;
        if (iVar13 == 0) {
          dVar17 = (&stack0x000000c8)[iVar10];
LAB_00440574:
          dVar17 = -dVar17;
        }
        else {
          dVar17 = *pdVar11;
          if (iVar13 == -1) goto LAB_00440574;
        }
        *pdVar12 = dVar17;
        iVar10 = iVar10 + 1;
        puVar8 = puVar8 + 0x10;
        pdVar11 = (double *)((int)pdVar11 + 0x464);
        pdVar12 = pdVar12 + 7;
      } while (iVar10 < 2);
      iVar10 = 2;
      pdVar11 = (double *)&stack0x00000240;
      puVar8 = (undefined4 *)&stack0x00000220;
      pdVar12 = (double *)(in_stack_00000044 + 0xc28);
      do {
        iVar13 = *(int *)(&stack0x00000118 + iVar10 * 4);
        if (iVar13 == 0) {
          *puVar8 = *(undefined4 *)pdVar12;
          puVar8[1] = *(undefined4 *)((int)pdVar12 + 4);
          pdVar11[-2] = dStack00000018 * *pdVar12;
          dVar17 = (&stack0x000000c8)[iVar10] * *pdVar12;
LAB_004405ee:
          dVar17 = -dVar17;
        }
        else {
          *puVar8 = 0;
          puVar8[1] = 0x3ff00000;
          dVar17 = pdVar12[1];
          if (iVar13 == -1) goto LAB_004405ee;
        }
        *pdVar11 = dVar17;
        iVar10 = iVar10 + 1;
        puVar8 = puVar8 + 0x10;
        pdVar12 = (double *)((int)pdVar12 + 0x464);
        pdVar11 = pdVar11 + 7;
      } while (iVar10 < 4);
      if (unaff_EDI == 0) {
        dVar17 = *(double *)(in_stack_00000044 + 0x1e50);
        dVar1 = in_stack_000000d8 * *(double *)(in_stack_00000044 + 0xc28) +
                in_stack_000000e0 * *(double *)(in_stack_00000044 + 0x108c);
LAB_004404d3:
        in_stack_000002b0 = in_stack_000000e8 * dVar17 - dVar1 * dStack00000018;
      }
      else {
LAB_004403a2:
        if (unaff_EDI == -1) {
          in_stack_000002b0 = -(double)CONCAT44(in_stack_0000003c,in_stack_00000038);
        }
        else {
          in_stack_000002b0 = (double)CONCAT44(in_stack_0000003c,in_stack_00000038);
        }
      }
    }
    else if (iVar10 == 1) {
      pdVar11 = (double *)(in_stack_00000044 + 0x360);
      iVar10 = 0;
      pdVar12 = (double *)&stack0x000001d0;
      puVar8 = (undefined4 *)&stack0x000001a0;
      do {
        iVar13 = *(int *)(&stack0x00000118 + iVar10 * 4);
        if (iVar13 == 0) {
          dVar17 = *pdVar11;
          *puVar8 = *(undefined4 *)pdVar11;
          puVar8[1] = *(undefined4 *)((int)pdVar11 + 4);
          pdVar12[-2] = dStack00000018 * dVar17;
          dVar17 = (&stack0x000000c8)[iVar10] * *pdVar11;
LAB_0044042a:
          dVar17 = -dVar17;
        }
        else {
          dVar17 = pdVar11[1];
          *puVar8 = 0;
          puVar8[1] = 0x3ff00000;
          if (iVar13 == -1) goto LAB_0044042a;
        }
        *pdVar12 = dVar17;
        iVar10 = iVar10 + 1;
        puVar8 = puVar8 + 0x10;
        pdVar11 = (double *)((int)pdVar11 + 0x464);
        pdVar12 = pdVar12 + 7;
      } while (iVar10 < 5);
      if (unaff_EDI == 0) {
        pdVar11 = (double *)(in_stack_00000044 + 0x360);
        iVar10 = 0;
        dVar1 = _DAT_0059e430;
        do {
          iVar13 = iVar10 + 8;
          *(double *)(&stack0x00000280 + iVar10) = dStack00000018 * *pdVar11;
          dVar1 = *(double *)((int)&stack0x000000c8 + iVar10) * *pdVar11 + dVar1;
          pdVar11 = (double *)((int)pdVar11 + 0x464);
          iVar10 = iVar13;
        } while (iVar13 < 0x20);
        dVar17 = *(double *)(in_stack_00000044 + 0x1e50);
        goto LAB_004404d3;
      }
      if (unaff_EDI == -1) {
        in_stack_000002b0 = -(double)CONCAT44(in_stack_0000003c,in_stack_00000038);
      }
      else {
        in_stack_000002b0 = (double)CONCAT44(in_stack_0000003c,in_stack_00000038);
      }
    }
    else if (iVar10 == 2) {
      iVar10 = 0;
      pdVar12 = (double *)&stack0x000001d0;
      puVar8 = (undefined4 *)&stack0x000001a0;
      pdVar11 = (double *)(in_stack_00000044 + 0x360);
      do {
        iVar13 = *(int *)(&stack0x00000118 + iVar10 * 4);
        if (iVar13 == 0) {
          dVar17 = *pdVar11;
          *puVar8 = *(undefined4 *)pdVar11;
          puVar8[1] = *(undefined4 *)((int)pdVar11 + 4);
          pdVar12[-2] = dStack00000018 * dVar17;
          dVar17 = (&stack0x000000c8)[iVar10] * *pdVar11;
LAB_00440295:
          dVar17 = -dVar17;
        }
        else {
          dVar17 = pdVar11[1];
          *puVar8 = 0;
          puVar8[1] = 0x3ff00000;
          if (iVar13 == -1) goto LAB_00440295;
        }
        *pdVar12 = dVar17;
        iVar10 = iVar10 + 1;
        puVar8 = puVar8 + 0x10;
        pdVar11 = (double *)((int)pdVar11 + 0x464);
        pdVar12 = pdVar12 + 7;
      } while (iVar10 < 2);
      iVar10 = 2;
      pdVar12 = (double *)&stack0x00000240;
      puVar8 = (undefined4 *)&stack0x00000220;
      pdVar11 = (double *)(in_stack_00000044 + 0xc30);
      do {
        iVar13 = *(int *)(&stack0x00000118 + iVar10 * 4);
        *puVar8 = 0;
        puVar8[1] = 0x3ff00000;
        if (iVar13 == 0) {
          dVar17 = (&stack0x000000c8)[iVar10];
LAB_004402ec:
          dVar17 = -dVar17;
        }
        else {
          dVar17 = *pdVar11;
          if (iVar13 == -1) goto LAB_004402ec;
        }
        *pdVar12 = dVar17;
        iVar10 = iVar10 + 1;
        puVar8 = puVar8 + 0x10;
        pdVar11 = (double *)((int)pdVar11 + 0x464);
        pdVar12 = pdVar12 + 7;
      } while (iVar10 < 4);
      if (unaff_EDI != 0) goto LAB_004403a2;
      in_stack_000002b0 =
           in_stack_000000e8 * *(double *)(in_stack_00000044 + 0x1e50) -
           (in_stack_000000c8 * *(double *)(in_stack_00000044 + 0x360) +
           in_stack_000000d0 * *(double *)(in_stack_00000044 + 0x7c4)) * dStack00000018;
    }
    if (in_stack_00000024 == 0) {
      dVar17 = in_stack_000000e8 * *(double *)(in_stack_00000044 + 0x1e50) -
               in_stack_000000f0 * *(double *)(in_stack_00000044 + 0x1c74);
    }
    else if (in_stack_00000024 == -1) {
      dVar17 = -(double)CONCAT44(in_stack_0000008c,in_stack_00000088);
    }
    else {
      dVar17 = (double)CONCAT44(in_stack_0000008c,in_stack_00000088);
    }
    FUN_005677b0();
    bVar16 = true;
    iVar10 = 0;
    pdVar12 = (double *)&stack0x000001d0;
    pdVar11 = (double *)(in_stack_00000044 + 0x368);
    do {
      if ((*(int *)(&stack0x00000118 + iVar10 * 4) == 0) && (*pdVar11 < ABS(*pdVar12))) {
        bVar16 = false;
        if (*pdVar12 <= _DAT_0059e430) {
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = 1;
        }
        *(undefined4 *)(&stack0x00000118 + iVar10 * 4) = uVar9;
      }
      iVar10 = iVar10 + 1;
      pdVar11 = (double *)((int)pdVar11 + 0x464);
      pdVar12 = pdVar12 + 7;
    } while (iVar10 < 4);
    if ((in_stack_00000024 != 0) ||
       (ABS(dVar17) <= (double)CONCAT44(in_stack_0000008c,in_stack_00000088))) {
      if (bVar16) {
        pdVar12 = (double *)&stack0x000001d0;
        pdVar11 = (double *)(in_stack_00000044 + 0x660);
        iVar10 = 0;
        do {
          dVar1 = *pdVar12;
          *(double *)(&stack0x00000308 + iVar10) = dVar1;
          *pdVar11 = ABS(dVar1) - pdVar11[1];
          if (ABS(dVar1) - pdVar11[1] < _DAT_0059e430) {
            *(undefined4 *)pdVar11 = 0;
            *(undefined4 *)((int)pdVar11 + 4) = 0;
          }
          iVar13 = iVar10 + 8;
          pdVar12 = pdVar12 + 7;
          pdVar11 = (double *)((int)pdVar11 + 0x464);
          *(double *)((int)&stack0x00000170 + iVar10) =
               dVar1 + *(double *)((int)&stack0x000000c8 + iVar10);
          iVar10 = iVar13;
        } while (iVar13 < 0x20);
        iVar10 = *(int *)(in_stack_00000044 + 0x1e14);
        in_stack_00000010 = in_stack_000002b0 * dStack00000018;
        if (iVar10 == 0) {
          in_stack_00000180 = in_stack_00000180 + in_stack_00000010;
          in_stack_00000188 = in_stack_00000188 + in_stack_00000010;
        }
        else if (iVar10 == 1) {
          iVar10 = 0;
          do {
            iVar10 = iVar10 + 1;
            (&stack0x00000168)[iVar10] = in_stack_00000010 + (&stack0x00000168)[iVar10];
          } while (iVar10 < 4);
        }
        else if (iVar10 == 2) {
          in_stack_00000170 = in_stack_00000170 + in_stack_00000010;
          in_stack_00000178 = in_stack_00000178 + in_stack_00000010;
        }
        pdVar11 = (double *)(in_stack_00000044 + 0x360);
        in_stack_00000190 = (in_stack_000000e8 - in_stack_000002b0) - dVar17;
        in_stack_00000198 = dVar17 + in_stack_000000f0;
        iVar10 = 0;
        do {
          iVar13 = iVar10 + 8;
          dVar1 = *pdVar11;
          pdVar11 = (double *)((int)pdVar11 + 0x464);
          *(double *)((int)&stack0x00000140 + iVar10) =
               *(double *)((int)&stack0x00000170 + iVar10) * dVar1;
          iVar10 = iVar13;
        } while (iVar13 < 0x20);
        in_stack_00000160 = in_stack_00000190 * *(double *)(in_stack_00000044 + 0x1e50);
        pdVar11 = (double *)(in_stack_00000044 + 0x348);
        in_stack_00000168 = (dVar17 + in_stack_000000f0) * *(double *)(in_stack_00000044 + 0x1c74);
        iVar10 = 0;
        do {
          if (*(double *)((int)&stack0x00000140 + iVar10) == _DAT_0059e430) {
LAB_004409b0:
            *(undefined4 *)((int)&stack0x00000050 + iVar10) = 0xffffffff;
            *(undefined4 *)((int)&stack0x00000050 + iVar10 + 4) = 0x7fefffff;
          }
          else {
            dVar17 = -(*pdVar11 / *(double *)((int)&stack0x00000140 + iVar10));
            *(double *)((int)&stack0x00000050 + iVar10) = dVar17;
            if (dVar17 < _DAT_0059e430 != (dVar17 == _DAT_0059e430)) goto LAB_004409b0;
          }
          iVar10 = iVar10 + 8;
          pdVar11 = (double *)((int)pdVar11 + 0x464);
        } while (iVar10 < 0x20);
        iVar10 = *(int *)(in_stack_00000044 + 0x1e14);
        if (iVar10 == 0) {
          _uStack00000030 =
               *(double *)(in_stack_00000044 + 0x1074) + *(double *)(in_stack_00000044 + 0xc10);
          in_stack_000000f8 = in_stack_00000158;
LAB_00440a52:
          in_stack_000000f8 = in_stack_000000f8 + in_stack_00000150;
LAB_00440a59:
          _uStack00000030 = _uStack00000030 * dStack00000018;
          in_stack_000000f8 = in_stack_000000f8 * dStack00000018;
        }
        else {
          if (iVar10 == 1) {
            _uStack00000030 =
                 *(double *)(in_stack_00000044 + 0x1074) + *(double *)(in_stack_00000044 + 0xc10) +
                 *(double *)(in_stack_00000044 + 0x7ac) + *(double *)(in_stack_00000044 + 0x348);
            in_stack_000000f8 = in_stack_00000148 + in_stack_00000140 + in_stack_00000158;
            goto LAB_00440a52;
          }
          if (iVar10 == 2) {
            _uStack00000030 =
                 *(double *)(in_stack_00000044 + 0x7ac) + *(double *)(in_stack_00000044 + 0x348);
            in_stack_000000f8 = in_stack_00000148 + in_stack_00000140;
            goto LAB_00440a59;
          }
        }
        if ((((in_stack_00000160 - in_stack_000000f8 == _DAT_0059e430) ||
             (dStack00000018 == _DAT_0059e430)) ||
            ((double)CONCAT44(in_stack_0000003c,in_stack_00000038) == _DAT_0059e430)) ||
           (in_stack_00000070 =
                 (_uStack00000030 - *(double *)(in_stack_00000044 + 0x1e38)) /
                 (in_stack_00000160 - in_stack_000000f8),
           in_stack_00000070 < _DAT_0059e430 != (in_stack_00000070 == _DAT_0059e430))) {
          in_stack_00000070 = 1.7976931348623157e+308;
        }
        in_stack_00000080 = in_stack_00000160 - in_stack_00000168;
        if (((in_stack_00000080 == _DAT_0059e430) ||
            ((double)CONCAT44(in_stack_0000008c,in_stack_00000088) == _DAT_0059e430)) ||
           (in_stack_00000078 =
                 (*(double *)(in_stack_00000044 + 0x1c5c) - *(double *)(in_stack_00000044 + 0x1e38))
                 / in_stack_00000080,
           in_stack_00000078 < _DAT_0059e430 != (in_stack_00000078 == _DAT_0059e430))) {
          in_stack_00000078 = 1.7976931348623157e+308;
        }
        if (in_stack_00000078 <= in_stack_00000070) {
          dStack00000028 = in_stack_00000078;
        }
        else {
          dStack00000028 = in_stack_00000070;
        }
        dVar17 = *(double *)(unaff_EBP + 8);
        dVar1 = dVar17;
        if ((dStack00000028 <= dVar17) &&
           (dVar1 = in_stack_00000078, in_stack_00000070 < in_stack_00000078)) {
          dVar1 = in_stack_00000070;
        }
        dVar2 = in_stack_00000058;
        if (in_stack_00000050 < in_stack_00000058) {
          dVar2 = in_stack_00000050;
        }
        dVar3 = in_stack_00000068;
        if (in_stack_00000060 < in_stack_00000068) {
          dVar3 = in_stack_00000060;
        }
        if (dVar3 <= dVar2) {
          dVar2 = in_stack_00000068;
          if (in_stack_00000060 < in_stack_00000068) {
            dVar2 = in_stack_00000060;
          }
        }
        else {
          dVar2 = in_stack_00000058;
          if (in_stack_00000050 < in_stack_00000058) {
            dVar2 = in_stack_00000050;
          }
        }
        if (dVar2 <= dVar1) {
          dVar1 = in_stack_00000058;
          if (in_stack_00000050 < in_stack_00000058) {
            dVar1 = in_stack_00000050;
          }
          dVar2 = in_stack_00000068;
          if (in_stack_00000060 < in_stack_00000068) {
            dVar2 = in_stack_00000060;
          }
          if (dVar2 <= dVar1) {
            dVar1 = in_stack_00000068;
            if (in_stack_00000060 < in_stack_00000068) {
              dVar1 = in_stack_00000060;
            }
          }
          else {
            dVar1 = in_stack_00000058;
            if (in_stack_00000050 < in_stack_00000058) {
              dVar1 = in_stack_00000050;
            }
          }
        }
        else {
          dVar2 = in_stack_00000078;
          if (in_stack_00000070 < in_stack_00000078) {
            dVar2 = in_stack_00000070;
          }
          dVar1 = dVar17;
          if ((dVar2 <= dVar17) &&
             (dVar1 = in_stack_00000078, in_stack_00000070 < in_stack_00000078)) {
            dVar1 = in_stack_00000070;
          }
        }
        piVar15 = (int *)&stack0x00000118;
        pdVar11 = (double *)(in_stack_00000044 + 0x348);
        iVar10 = 0;
        do {
          iVar13 = *piVar15;
          pdVar11[-2] = dVar1 * *pdVar11 + pdVar11[-2];
          if ((iVar13 == 0) || (dVar1 == *(double *)((int)&stack0x00000050 + iVar10))) {
            *(undefined4 *)pdVar11 = 0;
            *(undefined4 *)((int)pdVar11 + 4) = 0;
            *piVar15 = 0;
          }
          else {
            *pdVar11 = dVar1 * *(double *)((int)&stack0x00000140 + iVar10) + *pdVar11;
          }
          iVar10 = iVar10 + 8;
          pdVar11 = (double *)((int)pdVar11 + 0x464);
          piVar15 = piVar15 + 1;
        } while (iVar10 < 0x20);
        if ((unaff_EDI == 0) || (dVar1 == in_stack_00000070)) {
          iVar10 = *(int *)(in_stack_00000044 + 0x1e14);
          if (iVar10 == 0) {
            _uStack00000030 =
                 *(double *)(in_stack_00000044 + 0x1074) + *(double *)(in_stack_00000044 + 0xc10);
LAB_00440d9e:
            _uStack00000030 = _uStack00000030 * dStack00000018;
          }
          else {
            if (iVar10 == 1) {
              _uStack00000030 =
                   *(double *)(in_stack_00000044 + 0x1074) + *(double *)(in_stack_00000044 + 0xc10)
                   + *(double *)(in_stack_00000044 + 0x7ac) + *(double *)(in_stack_00000044 + 0x348)
              ;
              goto LAB_00440d9e;
            }
            if (iVar10 == 2) {
              _uStack00000030 =
                   *(double *)(in_stack_00000044 + 0x7ac) + *(double *)(in_stack_00000044 + 0x348);
              goto LAB_00440d9e;
            }
          }
          *(undefined4 *)(in_stack_00000044 + 0x1e38) = uStack00000030;
          *(undefined4 *)(in_stack_00000044 + 0x1e3c) = uStack00000034;
          unaff_EDI = 0;
        }
        else {
          *(double *)(in_stack_00000044 + 0x1e38) =
               in_stack_00000160 * dVar1 + *(double *)(in_stack_00000044 + 0x1e38);
        }
        if ((in_stack_00000024 == 0) || (dVar1 == in_stack_00000078)) {
          *(undefined4 *)(in_stack_00000044 + 0x1c5c) = *(undefined4 *)(in_stack_00000044 + 0x1e38);
          *(undefined4 *)(in_stack_00000044 + 0x1c60) = *(undefined4 *)(in_stack_00000044 + 0x1e3c);
          in_stack_00000024 = 0;
        }
        else {
          *(double *)(in_stack_00000044 + 0x1c5c) =
               in_stack_00000168 * dVar1 + *(double *)(in_stack_00000044 + 0x1c5c);
        }
        if (dVar1 != dVar17) {
          dVar2 = dVar1 / dVar17;
          in_stack_00000010 = in_stack_00000010 * dVar2;
          in_stack_000002b0 = in_stack_000002b0 * dVar2;
          iVar10 = 0;
          do {
            iVar13 = iVar10 + 8;
            *(double *)(&stack0x00000308 + iVar10) = dVar2 * *(double *)(&stack0x00000308 + iVar10);
            *(double *)((int)&stack0x00000170 + iVar10) =
                 dVar2 * *(double *)((int)&stack0x00000170 + iVar10);
            iVar10 = iVar13;
          } while (iVar13 < 0x20);
        }
        iVar10 = *(int *)(in_stack_00000044 + 0x1e14);
        if (iVar10 == 0) {
          iVar13 = *(int *)(in_stack_00000044 + 0xcb0);
          in_stack_000000a8 = in_stack_00000010 * _DAT_0059ed20;
          iVar5 = *(int *)(in_stack_00000044 + 0x1114);
          in_stack_00000108 = in_stack_00000010 * *(double *)(iVar5 + 0x34);
          in_stack_00000110 = in_stack_00000010 * *(double *)(iVar5 + 0x4c);
          in_stack_00000090 =
               in_stack_00000010 * *(double *)(iVar5 + 0x1c) +
               in_stack_00000010 * *(double *)(iVar13 + 0x1c);
          in_stack_00000098 = in_stack_00000108 + in_stack_00000010 * *(double *)(iVar13 + 0x34);
          in_stack_000000a0 = in_stack_00000110 + in_stack_00000010 * *(double *)(iVar13 + 0x4c);
        }
        else if (iVar10 == 1) {
          iVar13 = *(int *)(in_stack_00000044 + 1000);
          in_stack_000000a8 = in_stack_00000010 * _DAT_0059ed08;
          iVar5 = *(int *)(in_stack_00000044 + 0x84c);
          in_stack_00000108 = in_stack_00000010 * *(double *)(iVar5 + 0x34);
          iVar14 = *(int *)(in_stack_00000044 + 0xcb0);
          iVar6 = *(int *)(in_stack_00000044 + 0x1114);
          in_stack_00000110 = in_stack_00000010 * *(double *)(iVar6 + 0x4c);
          in_stack_00000090 =
               in_stack_00000010 * *(double *)(iVar6 + 0x1c) +
               in_stack_00000010 * *(double *)(iVar14 + 0x1c) +
               in_stack_00000010 * *(double *)(iVar5 + 0x1c) +
               in_stack_00000010 * *(double *)(iVar13 + 0x1c);
          in_stack_00000098 =
               in_stack_00000010 * *(double *)(iVar6 + 0x34) +
               in_stack_00000010 * *(double *)(iVar14 + 0x34) +
               in_stack_00000108 + in_stack_00000010 * *(double *)(iVar13 + 0x34);
          in_stack_000000a0 =
               in_stack_00000110 +
               in_stack_00000010 * *(double *)(iVar14 + 0x4c) +
               in_stack_00000010 * *(double *)(iVar5 + 0x4c) +
               in_stack_00000010 * *(double *)(iVar13 + 0x4c);
        }
        else if (iVar10 == 2) {
          iVar13 = *(int *)(in_stack_00000044 + 1000);
          in_stack_000000a8 = in_stack_00000010 * _DAT_0059ed20;
          iVar5 = *(int *)(in_stack_00000044 + 0x84c);
          in_stack_00000108 = in_stack_00000010 * *(double *)(iVar5 + 0x34);
          in_stack_00000110 = in_stack_00000010 * *(double *)(iVar5 + 0x4c);
          in_stack_00000090 =
               in_stack_00000010 * *(double *)(iVar5 + 0x1c) +
               in_stack_00000010 * *(double *)(iVar13 + 0x1c);
          in_stack_00000098 = in_stack_00000108 + in_stack_00000010 * *(double *)(iVar13 + 0x34);
          in_stack_000000a0 = in_stack_00000110 + in_stack_00000010 * *(double *)(iVar13 + 0x4c);
        }
        in_stack_000000a8 = in_stack_000000a8 * *(double *)(in_stack_00000044 + 0x1ea4);
        if ((iVar10 != 0) || (iVar10 = *(int *)(in_stack_00000044 + 0x141c), iVar10 == 0)) {
          iVar10 = *(int *)(in_stack_00000044 + 0x15f0);
        }
        in_stack_000000b0 = in_stack_000000a8 * *(double *)(iVar10 + 0x2c);
        dVar2 = in_stack_000000a8 * *(double *)(iVar10 + 0x44);
        dVar3 = in_stack_000000a8 * *(double *)(iVar10 + 0x5c);
        *(double *)(iVar10 + 0x14c) =
             *(double *)(iVar10 + 0x14c) - (in_stack_000000b0 + in_stack_00000090);
        *(double *)(iVar10 + 0x154) = *(double *)(iVar10 + 0x154) - (in_stack_00000098 + dVar2);
        *(double *)(iVar10 + 0x15c) = *(double *)(iVar10 + 0x15c) - (in_stack_000000a0 + dVar3);
        iVar10 = *(int *)(in_stack_00000044 + 0x15f0);
        in_stack_000000b0 = in_stack_000002b0 * *(double *)(iVar10 + 0x2c) - in_stack_000000b0;
        *(double *)(iVar10 + 0x14c) = *(double *)(iVar10 + 0x14c) - in_stack_000000b0;
        *(double *)(iVar10 + 0x154) =
             *(double *)(iVar10 + 0x154) - (in_stack_000002b0 * *(double *)(iVar10 + 0x44) - dVar2);
        *(double *)(iVar10 + 0x15c) =
             *(double *)(iVar10 + 0x15c) - (in_stack_000002b0 * *(double *)(iVar10 + 0x5c) - dVar3);
        iVar10 = 0;
        piVar15 = (int *)(in_stack_00000044 + 1000);
        do {
          iVar13 = piVar15[1];
          if (iVar13 == 0) {
            iVar13 = *(int *)(in_stack_00000044 + 0x141c);
          }
          iVar5 = *piVar15;
          dVar2 = *(double *)(&stack0x00000308 + iVar10);
          iVar14 = iVar10 + 8;
          dVar3 = *(double *)(iVar5 + 0x34);
          dVar4 = *(double *)(iVar5 + 0x4c);
          *(double *)(iVar13 + 0x14c) =
               *(double *)(iVar13 + 0x14c) - dVar2 * *(double *)(iVar5 + 0x1c);
          *(double *)(iVar13 + 0x154) = *(double *)(iVar13 + 0x154) - dVar2 * dVar3;
          *(double *)(iVar13 + 0x15c) = *(double *)(iVar13 + 0x15c) - dVar2 * dVar4;
          iVar13 = *piVar15;
          dVar2 = *(double *)((int)&stack0x00000170 + iVar10);
          in_stack_000000b8 = dVar2 * *(double *)(iVar13 + 0x34);
          in_stack_000000c0 = dVar2 * *(double *)(iVar13 + 0x4c);
          *(double *)(iVar13 + 0x14c) =
               dVar2 * *(double *)(iVar13 + 0x1c) + *(double *)(iVar13 + 0x14c);
          *(double *)(iVar13 + 0x154) = in_stack_000000b8 + *(double *)(iVar13 + 0x154);
          *(double *)(iVar13 + 0x15c) = in_stack_000000c0 + *(double *)(iVar13 + 0x15c);
          iVar10 = iVar14;
          piVar15 = piVar15 + 0x119;
        } while (iVar14 < 0x20);
        if (dVar1 == dVar17) {
          return;
        }
        *(double *)(unaff_EBP + 8) = dVar17 - dVar1;
      }
      goto LAB_00440210;
    }
    if (dVar17 <= _DAT_0059e430) {
      in_stack_00000024 = -1;
    }
    else {
      in_stack_00000024 = 1;
    }
  } while( true );
}


