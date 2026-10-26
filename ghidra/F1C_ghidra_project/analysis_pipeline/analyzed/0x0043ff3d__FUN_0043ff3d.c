// Function: FUN_0043ff3d @ 0043ff3d
// Size (bytes): 104


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043ff3d(void)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  char cVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int iVar11;
  double *pdVar12;
  double *pdVar13;
  int iVar14;
  int iVar15;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *piVar16;
  int unaff_EDI;
  float10 in_ST0;
  double dStack00000014;
  double dStack0000001c;
  int in_stack_00000028;
  double dStack0000002c;
  undefined4 uStack00000034;
  undefined4 uStack00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  int in_stack_00000048;
  double dStack0000004c;
  double in_stack_00000054;
  double in_stack_0000005c;
  double in_stack_00000064;
  double in_stack_0000006c;
  double in_stack_00000074;
  double in_stack_0000007c;
  double in_stack_00000084;
  undefined4 in_stack_0000008c;
  undefined4 in_stack_00000090;
  double in_stack_00000094;
  double in_stack_0000009c;
  double in_stack_000000a4;
  double in_stack_000000ac;
  double in_stack_000000b4;
  double in_stack_000000bc;
  double in_stack_000000c4;
  double in_stack_000000cc;
  double in_stack_000000d4;
  double in_stack_000000dc;
  double in_stack_000000e4;
  double in_stack_000000ec;
  double in_stack_000000f4;
  double in_stack_000000fc;
  double in_stack_0000010c;
  double in_stack_00000114;
  double in_stack_00000144;
  double in_stack_0000014c;
  double in_stack_00000154;
  double in_stack_0000015c;
  double in_stack_00000164;
  double in_stack_0000016c;
  double in_stack_00000174;
  double in_stack_0000017c;
  double in_stack_00000184;
  double in_stack_0000018c;
  double in_stack_00000194;
  double in_stack_0000019c;
  double in_stack_000002b4;
  double dVar17;
  
  dStack0000001c = (double)(in_ST0 * (float10)_DAT_0059ed10);
  dStack0000004c = (double)(in_ST0 * (float10)_DAT_0059ed10 * (float10)dStack0000001c);
  dStack0000002c = _uStack00000034 * dStack0000001c;
  cVar8 = FUN_00435290();
  if (cVar8 == '\0') {
    if (*(double *)(unaff_ESI + 0x1e38) < dStack0000002c) {
      unaff_EBX = unaff_EDI;
    }
  }
  else {
    unaff_EBX = 0;
  }
LAB_00440210:
  do {
    puVar9 = (undefined4 *)&stack0x000001a4;
    for (iVar11 = 0x54; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    iVar11 = *(int *)(in_stack_00000048 + 0x1e14);
    if (iVar11 == 0) {
      pdVar12 = (double *)(in_stack_00000048 + 0x368);
      iVar11 = 0;
      pdVar13 = (double *)&stack0x000001d4;
      puVar9 = (undefined4 *)&stack0x000001a4;
      do {
        iVar14 = *(int *)(&stack0x0000011c + iVar11 * 4);
        *puVar9 = 0;
        puVar9[1] = 0x3ff00000;
        if (iVar14 == 0) {
          dVar17 = (&stack0x000000cc)[iVar11];
LAB_00440574:
          dVar17 = -dVar17;
        }
        else {
          dVar17 = *pdVar12;
          if (iVar14 == -1) goto LAB_00440574;
        }
        *pdVar13 = dVar17;
        iVar11 = iVar11 + 1;
        puVar9 = puVar9 + 0x10;
        pdVar12 = (double *)((int)pdVar12 + 0x464);
        pdVar13 = pdVar13 + 7;
      } while (iVar11 < 2);
      iVar11 = 2;
      pdVar12 = (double *)&stack0x00000244;
      puVar9 = (undefined4 *)&stack0x00000224;
      pdVar13 = (double *)(in_stack_00000048 + 0xc28);
      do {
        iVar14 = *(int *)(&stack0x0000011c + iVar11 * 4);
        if (iVar14 == 0) {
          *puVar9 = *(undefined4 *)pdVar13;
          puVar9[1] = *(undefined4 *)((int)pdVar13 + 4);
          pdVar12[-2] = dStack0000001c * *pdVar13;
          dVar17 = (&stack0x000000cc)[iVar11] * *pdVar13;
LAB_004405ee:
          dVar17 = -dVar17;
        }
        else {
          *puVar9 = 0;
          puVar9[1] = 0x3ff00000;
          dVar17 = pdVar13[1];
          if (iVar14 == -1) goto LAB_004405ee;
        }
        *pdVar12 = dVar17;
        iVar11 = iVar11 + 1;
        puVar9 = puVar9 + 0x10;
        pdVar13 = (double *)((int)pdVar13 + 0x464);
        pdVar12 = pdVar12 + 7;
      } while (iVar11 < 4);
      if (unaff_EBX == 0) {
        dVar17 = *(double *)(in_stack_00000048 + 0x1e50);
        dVar1 = in_stack_000000dc * *(double *)(in_stack_00000048 + 0xc28) +
                in_stack_000000e4 * *(double *)(in_stack_00000048 + 0x108c);
LAB_004404d3:
        in_stack_000002b4 = in_stack_000000ec * dVar17 - dVar1 * dStack0000001c;
      }
      else {
LAB_004403a2:
        if (unaff_EBX == -1) {
          in_stack_000002b4 = -(double)CONCAT44(in_stack_00000040,in_stack_0000003c);
        }
        else {
          in_stack_000002b4 = (double)CONCAT44(in_stack_00000040,in_stack_0000003c);
        }
      }
    }
    else if (iVar11 == 1) {
      pdVar12 = (double *)(in_stack_00000048 + 0x360);
      iVar11 = 0;
      pdVar13 = (double *)&stack0x000001d4;
      puVar9 = (undefined4 *)&stack0x000001a4;
      do {
        iVar14 = *(int *)(&stack0x0000011c + iVar11 * 4);
        if (iVar14 == 0) {
          dVar17 = *pdVar12;
          *puVar9 = *(undefined4 *)pdVar12;
          puVar9[1] = *(undefined4 *)((int)pdVar12 + 4);
          pdVar13[-2] = dStack0000001c * dVar17;
          dVar17 = (&stack0x000000cc)[iVar11] * *pdVar12;
LAB_0044042a:
          dVar17 = -dVar17;
        }
        else {
          dVar17 = pdVar12[1];
          *puVar9 = 0;
          puVar9[1] = 0x3ff00000;
          if (iVar14 == -1) goto LAB_0044042a;
        }
        *pdVar13 = dVar17;
        iVar11 = iVar11 + 1;
        puVar9 = puVar9 + 0x10;
        pdVar12 = (double *)((int)pdVar12 + 0x464);
        pdVar13 = pdVar13 + 7;
      } while (iVar11 < 5);
      if (unaff_EBX == 0) {
        pdVar12 = (double *)(in_stack_00000048 + 0x360);
        iVar11 = 0;
        dVar1 = _DAT_0059e430;
        do {
          iVar14 = iVar11 + 8;
          *(double *)(&stack0x00000284 + iVar11) = dStack0000001c * *pdVar12;
          dVar1 = *(double *)((int)&stack0x000000cc + iVar11) * *pdVar12 + dVar1;
          pdVar12 = (double *)((int)pdVar12 + 0x464);
          iVar11 = iVar14;
        } while (iVar14 < 0x20);
        dVar17 = *(double *)(in_stack_00000048 + 0x1e50);
        goto LAB_004404d3;
      }
      if (unaff_EBX == -1) {
        in_stack_000002b4 = -(double)CONCAT44(in_stack_00000040,in_stack_0000003c);
      }
      else {
        in_stack_000002b4 = (double)CONCAT44(in_stack_00000040,in_stack_0000003c);
      }
    }
    else if (iVar11 == 2) {
      iVar11 = 0;
      pdVar13 = (double *)&stack0x000001d4;
      puVar9 = (undefined4 *)&stack0x000001a4;
      pdVar12 = (double *)(in_stack_00000048 + 0x360);
      do {
        iVar14 = *(int *)(&stack0x0000011c + iVar11 * 4);
        if (iVar14 == 0) {
          dVar17 = *pdVar12;
          *puVar9 = *(undefined4 *)pdVar12;
          puVar9[1] = *(undefined4 *)((int)pdVar12 + 4);
          pdVar13[-2] = dStack0000001c * dVar17;
          dVar17 = (&stack0x000000cc)[iVar11] * *pdVar12;
LAB_00440295:
          dVar17 = -dVar17;
        }
        else {
          dVar17 = pdVar12[1];
          *puVar9 = 0;
          puVar9[1] = 0x3ff00000;
          if (iVar14 == -1) goto LAB_00440295;
        }
        *pdVar13 = dVar17;
        iVar11 = iVar11 + 1;
        puVar9 = puVar9 + 0x10;
        pdVar12 = (double *)((int)pdVar12 + 0x464);
        pdVar13 = pdVar13 + 7;
      } while (iVar11 < 2);
      iVar11 = 2;
      pdVar13 = (double *)&stack0x00000244;
      puVar9 = (undefined4 *)&stack0x00000224;
      pdVar12 = (double *)(in_stack_00000048 + 0xc30);
      do {
        iVar14 = *(int *)(&stack0x0000011c + iVar11 * 4);
        *puVar9 = 0;
        puVar9[1] = 0x3ff00000;
        if (iVar14 == 0) {
          dVar17 = (&stack0x000000cc)[iVar11];
LAB_004402ec:
          dVar17 = -dVar17;
        }
        else {
          dVar17 = *pdVar12;
          if (iVar14 == -1) goto LAB_004402ec;
        }
        *pdVar13 = dVar17;
        iVar11 = iVar11 + 1;
        puVar9 = puVar9 + 0x10;
        pdVar12 = (double *)((int)pdVar12 + 0x464);
        pdVar13 = pdVar13 + 7;
      } while (iVar11 < 4);
      if (unaff_EBX != 0) goto LAB_004403a2;
      in_stack_000002b4 =
           in_stack_000000ec * *(double *)(in_stack_00000048 + 0x1e50) -
           (in_stack_000000cc * *(double *)(in_stack_00000048 + 0x360) +
           in_stack_000000d4 * *(double *)(in_stack_00000048 + 0x7c4)) * dStack0000001c;
    }
    if (in_stack_00000028 == 0) {
      dVar17 = in_stack_000000ec * *(double *)(in_stack_00000048 + 0x1e50) -
               in_stack_000000f4 * *(double *)(in_stack_00000048 + 0x1c74);
    }
    else if (in_stack_00000028 == -1) {
      dVar17 = -(double)CONCAT44(in_stack_00000090,in_stack_0000008c);
    }
    else {
      dVar17 = (double)CONCAT44(in_stack_00000090,in_stack_0000008c);
    }
    FUN_005677b0();
    bVar7 = true;
    iVar11 = 0;
    pdVar13 = (double *)&stack0x000001d4;
    pdVar12 = (double *)(in_stack_00000048 + 0x368);
    do {
      if ((*(int *)(&stack0x0000011c + iVar11 * 4) == 0) && (*pdVar12 < ABS(*pdVar13))) {
        bVar7 = false;
        if (*pdVar13 <= _DAT_0059e430) {
          uVar10 = 0xffffffff;
        }
        else {
          uVar10 = 1;
        }
        *(undefined4 *)(&stack0x0000011c + iVar11 * 4) = uVar10;
      }
      iVar11 = iVar11 + 1;
      pdVar12 = (double *)((int)pdVar12 + 0x464);
      pdVar13 = pdVar13 + 7;
    } while (iVar11 < 4);
    if ((in_stack_00000028 != 0) ||
       (ABS(dVar17) <= (double)CONCAT44(in_stack_00000090,in_stack_0000008c))) {
      if (bVar7) {
        pdVar13 = (double *)&stack0x000001d4;
        pdVar12 = (double *)(in_stack_00000048 + 0x660);
        iVar11 = 0;
        do {
          dVar1 = *pdVar13;
          *(double *)(&stack0x0000030c + iVar11) = dVar1;
          *pdVar12 = ABS(dVar1) - pdVar12[1];
          if (ABS(dVar1) - pdVar12[1] < _DAT_0059e430) {
            *(undefined4 *)pdVar12 = 0;
            *(undefined4 *)((int)pdVar12 + 4) = 0;
          }
          iVar14 = iVar11 + 8;
          pdVar13 = pdVar13 + 7;
          pdVar12 = (double *)((int)pdVar12 + 0x464);
          *(double *)((int)&stack0x00000174 + iVar11) =
               dVar1 + *(double *)((int)&stack0x000000cc + iVar11);
          iVar11 = iVar14;
        } while (iVar14 < 0x20);
        iVar11 = *(int *)(in_stack_00000048 + 0x1e14);
        dStack00000014 = in_stack_000002b4 * dStack0000001c;
        if (iVar11 == 0) {
          in_stack_00000184 = in_stack_00000184 + dStack00000014;
          in_stack_0000018c = in_stack_0000018c + dStack00000014;
        }
        else if (iVar11 == 1) {
          iVar11 = 0;
          do {
            iVar11 = iVar11 + 1;
            (&stack0x0000016c)[iVar11] = dStack00000014 + (&stack0x0000016c)[iVar11];
          } while (iVar11 < 4);
        }
        else if (iVar11 == 2) {
          in_stack_00000174 = in_stack_00000174 + dStack00000014;
          in_stack_0000017c = in_stack_0000017c + dStack00000014;
        }
        pdVar12 = (double *)(in_stack_00000048 + 0x360);
        in_stack_00000194 = (in_stack_000000ec - in_stack_000002b4) - dVar17;
        in_stack_0000019c = dVar17 + in_stack_000000f4;
        iVar11 = 0;
        do {
          iVar14 = iVar11 + 8;
          dVar1 = *pdVar12;
          pdVar12 = (double *)((int)pdVar12 + 0x464);
          *(double *)((int)&stack0x00000144 + iVar11) =
               *(double *)((int)&stack0x00000174 + iVar11) * dVar1;
          iVar11 = iVar14;
        } while (iVar14 < 0x20);
        in_stack_00000164 = in_stack_00000194 * *(double *)(in_stack_00000048 + 0x1e50);
        pdVar12 = (double *)(in_stack_00000048 + 0x348);
        in_stack_0000016c = (dVar17 + in_stack_000000f4) * *(double *)(in_stack_00000048 + 0x1c74);
        iVar11 = 0;
        do {
          if (*(double *)((int)&stack0x00000144 + iVar11) == _DAT_0059e430) {
LAB_004409b0:
            *(undefined4 *)((int)&stack0x00000054 + iVar11) = 0xffffffff;
            *(undefined4 *)((int)&stack0x00000054 + iVar11 + 4) = 0x7fefffff;
          }
          else {
            dVar17 = -(*pdVar12 / *(double *)((int)&stack0x00000144 + iVar11));
            *(double *)((int)&stack0x00000054 + iVar11) = dVar17;
            if (dVar17 < _DAT_0059e430 != (dVar17 == _DAT_0059e430)) goto LAB_004409b0;
          }
          iVar11 = iVar11 + 8;
          pdVar12 = (double *)((int)pdVar12 + 0x464);
        } while (iVar11 < 0x20);
        iVar11 = *(int *)(in_stack_00000048 + 0x1e14);
        if (iVar11 == 0) {
          _uStack00000034 =
               *(double *)(in_stack_00000048 + 0x1074) + *(double *)(in_stack_00000048 + 0xc10);
          in_stack_000000fc = in_stack_0000015c;
LAB_00440a52:
          in_stack_000000fc = in_stack_000000fc + in_stack_00000154;
LAB_00440a59:
          _uStack00000034 = _uStack00000034 * dStack0000001c;
          in_stack_000000fc = in_stack_000000fc * dStack0000001c;
        }
        else {
          if (iVar11 == 1) {
            _uStack00000034 =
                 *(double *)(in_stack_00000048 + 0x1074) + *(double *)(in_stack_00000048 + 0xc10) +
                 *(double *)(in_stack_00000048 + 0x7ac) + *(double *)(in_stack_00000048 + 0x348);
            in_stack_000000fc = in_stack_0000014c + in_stack_00000144 + in_stack_0000015c;
            goto LAB_00440a52;
          }
          if (iVar11 == 2) {
            _uStack00000034 =
                 *(double *)(in_stack_00000048 + 0x7ac) + *(double *)(in_stack_00000048 + 0x348);
            in_stack_000000fc = in_stack_0000014c + in_stack_00000144;
            goto LAB_00440a59;
          }
        }
        if ((((in_stack_00000164 - in_stack_000000fc == _DAT_0059e430) ||
             (dStack0000001c == _DAT_0059e430)) ||
            ((double)CONCAT44(in_stack_00000040,in_stack_0000003c) == _DAT_0059e430)) ||
           (in_stack_00000074 =
                 (_uStack00000034 - *(double *)(in_stack_00000048 + 0x1e38)) /
                 (in_stack_00000164 - in_stack_000000fc),
           in_stack_00000074 < _DAT_0059e430 != (in_stack_00000074 == _DAT_0059e430))) {
          in_stack_00000074 = 1.7976931348623157e+308;
        }
        in_stack_00000084 = in_stack_00000164 - in_stack_0000016c;
        if (((in_stack_00000084 == _DAT_0059e430) ||
            ((double)CONCAT44(in_stack_00000090,in_stack_0000008c) == _DAT_0059e430)) ||
           (in_stack_0000007c =
                 (*(double *)(in_stack_00000048 + 0x1c5c) - *(double *)(in_stack_00000048 + 0x1e38))
                 / in_stack_00000084,
           in_stack_0000007c < _DAT_0059e430 != (in_stack_0000007c == _DAT_0059e430))) {
          in_stack_0000007c = 1.7976931348623157e+308;
        }
        if (in_stack_0000007c <= in_stack_00000074) {
          dStack0000002c = in_stack_0000007c;
        }
        else {
          dStack0000002c = in_stack_00000074;
        }
        dVar17 = *(double *)(unaff_EBP + 8);
        dVar1 = dVar17;
        if ((dStack0000002c <= dVar17) &&
           (dVar1 = in_stack_0000007c, in_stack_00000074 < in_stack_0000007c)) {
          dVar1 = in_stack_00000074;
        }
        dVar2 = in_stack_0000005c;
        if (in_stack_00000054 < in_stack_0000005c) {
          dVar2 = in_stack_00000054;
        }
        dVar3 = in_stack_0000006c;
        if (in_stack_00000064 < in_stack_0000006c) {
          dVar3 = in_stack_00000064;
        }
        if (dVar3 <= dVar2) {
          dVar2 = in_stack_0000006c;
          if (in_stack_00000064 < in_stack_0000006c) {
            dVar2 = in_stack_00000064;
          }
        }
        else {
          dVar2 = in_stack_0000005c;
          if (in_stack_00000054 < in_stack_0000005c) {
            dVar2 = in_stack_00000054;
          }
        }
        if (dVar2 <= dVar1) {
          dVar1 = in_stack_0000005c;
          if (in_stack_00000054 < in_stack_0000005c) {
            dVar1 = in_stack_00000054;
          }
          dVar2 = in_stack_0000006c;
          if (in_stack_00000064 < in_stack_0000006c) {
            dVar2 = in_stack_00000064;
          }
          if (dVar2 <= dVar1) {
            dVar1 = in_stack_0000006c;
            if (in_stack_00000064 < in_stack_0000006c) {
              dVar1 = in_stack_00000064;
            }
          }
          else {
            dVar1 = in_stack_0000005c;
            if (in_stack_00000054 < in_stack_0000005c) {
              dVar1 = in_stack_00000054;
            }
          }
        }
        else {
          dVar2 = in_stack_0000007c;
          if (in_stack_00000074 < in_stack_0000007c) {
            dVar2 = in_stack_00000074;
          }
          dVar1 = dVar17;
          if ((dVar2 <= dVar17) &&
             (dVar1 = in_stack_0000007c, in_stack_00000074 < in_stack_0000007c)) {
            dVar1 = in_stack_00000074;
          }
        }
        piVar16 = (int *)&stack0x0000011c;
        pdVar12 = (double *)(in_stack_00000048 + 0x348);
        iVar11 = 0;
        do {
          iVar14 = *piVar16;
          pdVar12[-2] = dVar1 * *pdVar12 + pdVar12[-2];
          if ((iVar14 == 0) || (dVar1 == *(double *)((int)&stack0x00000054 + iVar11))) {
            *(undefined4 *)pdVar12 = 0;
            *(undefined4 *)((int)pdVar12 + 4) = 0;
            *piVar16 = 0;
          }
          else {
            *pdVar12 = dVar1 * *(double *)((int)&stack0x00000144 + iVar11) + *pdVar12;
          }
          iVar11 = iVar11 + 8;
          pdVar12 = (double *)((int)pdVar12 + 0x464);
          piVar16 = piVar16 + 1;
        } while (iVar11 < 0x20);
        if ((unaff_EBX == 0) || (dVar1 == in_stack_00000074)) {
          iVar11 = *(int *)(in_stack_00000048 + 0x1e14);
          if (iVar11 == 0) {
            _uStack00000034 =
                 *(double *)(in_stack_00000048 + 0x1074) + *(double *)(in_stack_00000048 + 0xc10);
LAB_00440d9e:
            _uStack00000034 = _uStack00000034 * dStack0000001c;
          }
          else {
            if (iVar11 == 1) {
              _uStack00000034 =
                   *(double *)(in_stack_00000048 + 0x1074) + *(double *)(in_stack_00000048 + 0xc10)
                   + *(double *)(in_stack_00000048 + 0x7ac) + *(double *)(in_stack_00000048 + 0x348)
              ;
              goto LAB_00440d9e;
            }
            if (iVar11 == 2) {
              _uStack00000034 =
                   *(double *)(in_stack_00000048 + 0x7ac) + *(double *)(in_stack_00000048 + 0x348);
              goto LAB_00440d9e;
            }
          }
          *(undefined4 *)(in_stack_00000048 + 0x1e38) = uStack00000034;
          *(undefined4 *)(in_stack_00000048 + 0x1e3c) = uStack00000038;
          unaff_EBX = 0;
        }
        else {
          *(double *)(in_stack_00000048 + 0x1e38) =
               in_stack_00000164 * dVar1 + *(double *)(in_stack_00000048 + 0x1e38);
        }
        if ((in_stack_00000028 == 0) || (dVar1 == in_stack_0000007c)) {
          *(undefined4 *)(in_stack_00000048 + 0x1c5c) = *(undefined4 *)(in_stack_00000048 + 0x1e38);
          *(undefined4 *)(in_stack_00000048 + 0x1c60) = *(undefined4 *)(in_stack_00000048 + 0x1e3c);
          in_stack_00000028 = 0;
        }
        else {
          *(double *)(in_stack_00000048 + 0x1c5c) =
               in_stack_0000016c * dVar1 + *(double *)(in_stack_00000048 + 0x1c5c);
        }
        if (dVar1 != dVar17) {
          dVar2 = dVar1 / dVar17;
          dStack00000014 = dStack00000014 * dVar2;
          in_stack_000002b4 = in_stack_000002b4 * dVar2;
          iVar11 = 0;
          do {
            iVar14 = iVar11 + 8;
            *(double *)(&stack0x0000030c + iVar11) = dVar2 * *(double *)(&stack0x0000030c + iVar11);
            *(double *)((int)&stack0x00000174 + iVar11) =
                 dVar2 * *(double *)((int)&stack0x00000174 + iVar11);
            iVar11 = iVar14;
          } while (iVar14 < 0x20);
        }
        iVar11 = *(int *)(in_stack_00000048 + 0x1e14);
        if (iVar11 == 0) {
          iVar14 = *(int *)(in_stack_00000048 + 0xcb0);
          in_stack_000000ac = dStack00000014 * _DAT_0059ed20;
          iVar5 = *(int *)(in_stack_00000048 + 0x1114);
          in_stack_0000010c = dStack00000014 * *(double *)(iVar5 + 0x34);
          in_stack_00000114 = dStack00000014 * *(double *)(iVar5 + 0x4c);
          in_stack_00000094 =
               dStack00000014 * *(double *)(iVar5 + 0x1c) +
               dStack00000014 * *(double *)(iVar14 + 0x1c);
          in_stack_0000009c = in_stack_0000010c + dStack00000014 * *(double *)(iVar14 + 0x34);
          in_stack_000000a4 = in_stack_00000114 + dStack00000014 * *(double *)(iVar14 + 0x4c);
        }
        else if (iVar11 == 1) {
          iVar14 = *(int *)(in_stack_00000048 + 1000);
          in_stack_000000ac = dStack00000014 * _DAT_0059ed08;
          iVar5 = *(int *)(in_stack_00000048 + 0x84c);
          in_stack_0000010c = dStack00000014 * *(double *)(iVar5 + 0x34);
          iVar15 = *(int *)(in_stack_00000048 + 0xcb0);
          iVar6 = *(int *)(in_stack_00000048 + 0x1114);
          in_stack_00000114 = dStack00000014 * *(double *)(iVar6 + 0x4c);
          in_stack_00000094 =
               dStack00000014 * *(double *)(iVar6 + 0x1c) +
               dStack00000014 * *(double *)(iVar15 + 0x1c) +
               dStack00000014 * *(double *)(iVar5 + 0x1c) +
               dStack00000014 * *(double *)(iVar14 + 0x1c);
          in_stack_0000009c =
               dStack00000014 * *(double *)(iVar6 + 0x34) +
               dStack00000014 * *(double *)(iVar15 + 0x34) +
               in_stack_0000010c + dStack00000014 * *(double *)(iVar14 + 0x34);
          in_stack_000000a4 =
               in_stack_00000114 +
               dStack00000014 * *(double *)(iVar15 + 0x4c) +
               dStack00000014 * *(double *)(iVar5 + 0x4c) +
               dStack00000014 * *(double *)(iVar14 + 0x4c);
        }
        else if (iVar11 == 2) {
          iVar14 = *(int *)(in_stack_00000048 + 1000);
          in_stack_000000ac = dStack00000014 * _DAT_0059ed20;
          iVar5 = *(int *)(in_stack_00000048 + 0x84c);
          in_stack_0000010c = dStack00000014 * *(double *)(iVar5 + 0x34);
          in_stack_00000114 = dStack00000014 * *(double *)(iVar5 + 0x4c);
          in_stack_00000094 =
               dStack00000014 * *(double *)(iVar5 + 0x1c) +
               dStack00000014 * *(double *)(iVar14 + 0x1c);
          in_stack_0000009c = in_stack_0000010c + dStack00000014 * *(double *)(iVar14 + 0x34);
          in_stack_000000a4 = in_stack_00000114 + dStack00000014 * *(double *)(iVar14 + 0x4c);
        }
        in_stack_000000ac = in_stack_000000ac * *(double *)(in_stack_00000048 + 0x1ea4);
        if ((iVar11 != 0) || (iVar11 = *(int *)(in_stack_00000048 + 0x141c), iVar11 == 0)) {
          iVar11 = *(int *)(in_stack_00000048 + 0x15f0);
        }
        in_stack_000000b4 = in_stack_000000ac * *(double *)(iVar11 + 0x2c);
        dVar2 = in_stack_000000ac * *(double *)(iVar11 + 0x44);
        dVar3 = in_stack_000000ac * *(double *)(iVar11 + 0x5c);
        *(double *)(iVar11 + 0x14c) =
             *(double *)(iVar11 + 0x14c) - (in_stack_000000b4 + in_stack_00000094);
        *(double *)(iVar11 + 0x154) = *(double *)(iVar11 + 0x154) - (in_stack_0000009c + dVar2);
        *(double *)(iVar11 + 0x15c) = *(double *)(iVar11 + 0x15c) - (in_stack_000000a4 + dVar3);
        iVar11 = *(int *)(in_stack_00000048 + 0x15f0);
        in_stack_000000b4 = in_stack_000002b4 * *(double *)(iVar11 + 0x2c) - in_stack_000000b4;
        *(double *)(iVar11 + 0x14c) = *(double *)(iVar11 + 0x14c) - in_stack_000000b4;
        *(double *)(iVar11 + 0x154) =
             *(double *)(iVar11 + 0x154) - (in_stack_000002b4 * *(double *)(iVar11 + 0x44) - dVar2);
        *(double *)(iVar11 + 0x15c) =
             *(double *)(iVar11 + 0x15c) - (in_stack_000002b4 * *(double *)(iVar11 + 0x5c) - dVar3);
        iVar11 = 0;
        piVar16 = (int *)(in_stack_00000048 + 1000);
        do {
          iVar14 = piVar16[1];
          if (iVar14 == 0) {
            iVar14 = *(int *)(in_stack_00000048 + 0x141c);
          }
          iVar5 = *piVar16;
          dVar2 = *(double *)(&stack0x0000030c + iVar11);
          iVar15 = iVar11 + 8;
          dVar3 = *(double *)(iVar5 + 0x34);
          dVar4 = *(double *)(iVar5 + 0x4c);
          *(double *)(iVar14 + 0x14c) =
               *(double *)(iVar14 + 0x14c) - dVar2 * *(double *)(iVar5 + 0x1c);
          *(double *)(iVar14 + 0x154) = *(double *)(iVar14 + 0x154) - dVar2 * dVar3;
          *(double *)(iVar14 + 0x15c) = *(double *)(iVar14 + 0x15c) - dVar2 * dVar4;
          iVar14 = *piVar16;
          dVar2 = *(double *)((int)&stack0x00000174 + iVar11);
          in_stack_000000bc = dVar2 * *(double *)(iVar14 + 0x34);
          in_stack_000000c4 = dVar2 * *(double *)(iVar14 + 0x4c);
          *(double *)(iVar14 + 0x14c) =
               dVar2 * *(double *)(iVar14 + 0x1c) + *(double *)(iVar14 + 0x14c);
          *(double *)(iVar14 + 0x154) = in_stack_000000bc + *(double *)(iVar14 + 0x154);
          *(double *)(iVar14 + 0x15c) = in_stack_000000c4 + *(double *)(iVar14 + 0x15c);
          iVar11 = iVar15;
          piVar16 = piVar16 + 0x119;
        } while (iVar15 < 0x20);
        if (dVar1 == dVar17) {
          return;
        }
        *(double *)(unaff_EBP + 8) = dVar17 - dVar1;
      }
      goto LAB_00440210;
    }
    if (dVar17 <= _DAT_0059e430) {
      in_stack_00000028 = -1;
    }
    else {
      in_stack_00000028 = 1;
    }
  } while( true );
}


