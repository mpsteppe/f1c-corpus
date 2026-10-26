// Function: FUN_0056aa60 @ 0056aa60
// Size (bytes): 2922


void __fastcall FUN_0056aa60(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  int iVar23;
  int iVar24;
  double *pdVar25;
  int iVar26;
  undefined4 local_a4;
  undefined4 local_58;
  undefined4 local_54;
  
  iVar26 = *(int *)(param_1 + 0x22c);
  local_54 = 0;
  if (0 < iVar26) {
    local_a4 = 0;
    do {
      iVar23 = *(int *)(param_1 + 0x230) + local_a4;
      cVar1 = *(char *)(iVar23 + 0x34);
      iVar2 = *(int *)(iVar23 + 0x30);
      dVar5 = *(double *)(*(int *)(param_1 + 0x230) + 0x28 + local_a4) *
              *(double *)(param_1 + 0x104) -
              *(double *)(iVar23 + 0x20) * *(double *)(param_1 + 0x11c);
      dVar6 = *(double *)(param_1 + 0x10c) * *(double *)(iVar23 + 0x28) -
              *(double *)(param_1 + 0x124) * *(double *)(iVar23 + 0x20);
      dVar7 = *(double *)(param_1 + 0x114) * *(double *)(iVar23 + 0x28) -
              *(double *)(param_1 + 300) * *(double *)(iVar23 + 0x20);
      dVar8 = *(double *)(iVar23 + 0x18) * *(double *)(param_1 + 0x11c) -
              *(double *)(param_1 + 0xec) * *(double *)(iVar23 + 0x28);
      dVar9 = *(double *)(param_1 + 0x124) * *(double *)(iVar23 + 0x18) -
              *(double *)(param_1 + 0xf4) * *(double *)(iVar23 + 0x28);
      dVar10 = *(double *)(param_1 + 300) * *(double *)(iVar23 + 0x18) -
               *(double *)(param_1 + 0xfc) * *(double *)(iVar23 + 0x28);
      dVar11 = *(double *)(param_1 + 0xec) * *(double *)(iVar23 + 0x20) -
               *(double *)(iVar23 + 0x18) * *(double *)(param_1 + 0x104);
      dVar12 = *(double *)(param_1 + 0xf4) * *(double *)(iVar23 + 0x20) -
               *(double *)(iVar23 + 0x18) * *(double *)(param_1 + 0x10c);
      dVar13 = *(double *)(param_1 + 0xfc) * *(double *)(iVar23 + 0x20) -
               *(double *)(param_1 + 0x114) * *(double *)(iVar23 + 0x18);
      if (local_54 < iVar26) {
        local_58 = local_a4;
        iVar26 = local_54;
        do {
          iVar23 = *(int *)(param_1 + 0x230) + local_58;
          dVar14 = (dVar6 * *(double *)(*(int *)(param_1 + 0x230) + 0x28 + local_58) -
                   dVar7 * *(double *)(iVar23 + 0x20)) + *(double *)(param_1 + 0xb4);
          dVar15 = dVar9 * *(double *)(iVar23 + 0x28) - dVar10 * *(double *)(iVar23 + 0x20);
          dVar16 = (dVar10 * *(double *)(iVar23 + 0x18) - dVar8 * *(double *)(iVar23 + 0x28)) +
                   *(double *)(param_1 + 0xb4);
          dVar17 = dVar12 * *(double *)(iVar23 + 0x28) - dVar13 * *(double *)(iVar23 + 0x20);
          dVar18 = dVar13 * *(double *)(iVar23 + 0x18) - dVar11 * *(double *)(iVar23 + 0x28);
          dVar19 = (dVar11 * *(double *)(iVar23 + 0x20) - dVar12 * *(double *)(iVar23 + 0x18)) +
                   *(double *)(param_1 + 0xb4);
          if (local_54 == iVar26) {
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
            *(double *)(iVar23 + iVar2 * 8) = dVar14 + *(double *)(iVar23 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar23 + iVar2 * 8) = dVar15 + *(double *)(iVar23 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar23 + 8 + iVar2 * 8) = dVar16 + *(double *)(iVar23 + 8 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            *(double *)(iVar23 + iVar2 * 8) = dVar17 + *(double *)(iVar23 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            *(double *)(iVar23 + 8 + iVar2 * 8) = dVar18 + *(double *)(iVar23 + 8 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
LAB_0056b02e:
            pdVar25 = (double *)(iVar23 + 0x10 + iVar2 * 8);
LAB_0056b032:
            dVar19 = dVar19 + *pdVar25;
          }
          else {
            iVar3 = *(int *)(iVar23 + 0x30);
            dVar20 = dVar7 * *(double *)(iVar23 + 0x18) - dVar5 * *(double *)(iVar23 + 0x28);
            dVar21 = dVar5 * *(double *)(iVar23 + 0x20) - dVar6 * *(double *)(iVar23 + 0x18);
            iVar4 = *(int *)(param_1 + 0x228);
            dVar22 = dVar8 * *(double *)(iVar23 + 0x20) - dVar9 * *(double *)(iVar23 + 0x18);
            if (*(char *)(iVar23 + 0x34) == cVar1) {
              if (iVar2 <= iVar3) {
                iVar23 = *(int *)(iVar4 + iVar3 * 4);
                *(double *)(iVar23 + iVar2 * 8) = dVar14 + *(double *)(iVar23 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
                *(double *)(iVar23 + 8 + iVar2 * 8) = dVar15 + *(double *)(iVar23 + 8 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
                *(double *)(iVar23 + 0x10 + iVar2 * 8) =
                     dVar17 + *(double *)(iVar23 + 0x10 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
                *(double *)(iVar23 + iVar2 * 8) = dVar20 + *(double *)(iVar23 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
                *(double *)(iVar23 + 8 + iVar2 * 8) = dVar16 + *(double *)(iVar23 + 8 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
                *(double *)(iVar23 + 0x10 + iVar2 * 8) =
                     dVar18 + *(double *)(iVar23 + 0x10 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
                *(double *)(iVar23 + iVar2 * 8) = dVar21 + *(double *)(iVar23 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
                *(double *)(iVar23 + 8 + iVar2 * 8) = dVar22 + *(double *)(iVar23 + 8 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
                goto LAB_0056b02e;
              }
              iVar23 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = dVar14 + *(double *)(iVar23 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = dVar20 + *(double *)(iVar23 + 8 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar23 + 0x10 + iVar3 * 8) =
                   dVar21 + *(double *)(iVar23 + 0x10 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = dVar15 + *(double *)(iVar23 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = dVar16 + *(double *)(iVar23 + 8 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + 0x10 + iVar3 * 8) =
                   dVar22 + *(double *)(iVar23 + 0x10 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = dVar17 + *(double *)(iVar23 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = dVar18 + *(double *)(iVar23 + 8 + iVar3 * 8);
              pdVar25 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4) + 0x10 + iVar3 * 8);
              goto LAB_0056b032;
            }
            if (iVar3 < iVar2) {
              iVar23 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = *(double *)(iVar23 + iVar3 * 8) - dVar14;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = *(double *)(iVar23 + 8 + iVar3 * 8) - dVar20;
              pdVar25 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4) + 0x10 + iVar3 * 8);
              *pdVar25 = *pdVar25 - dVar21;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = *(double *)(iVar23 + iVar3 * 8) - dVar15;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = *(double *)(iVar23 + 8 + iVar3 * 8) - dVar16;
              pdVar25 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + 0x10 + iVar3 * 8);
              *pdVar25 = *pdVar25 - dVar22;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = *(double *)(iVar23 + iVar3 * 8) - dVar17;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = *(double *)(iVar23 + 8 + iVar3 * 8) - dVar18;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              pdVar25 = (double *)(iVar23 + 0x10 + iVar3 * 8);
              dVar19 = *(double *)(iVar23 + 0x10 + iVar3 * 8) - dVar19;
            }
            else {
              iVar23 = *(int *)(iVar4 + iVar3 * 4);
              *(double *)(iVar23 + iVar2 * 8) = *(double *)(iVar23 + iVar2 * 8) - dVar14;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar23 + 8 + iVar2 * 8) = *(double *)(iVar23 + 8 + iVar2 * 8) - dVar15;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar23 + 0x10 + iVar2 * 8) =
                   *(double *)(iVar23 + 0x10 + iVar2 * 8) - dVar17;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
              *(double *)(iVar23 + iVar2 * 8) = *(double *)(iVar23 + iVar2 * 8) - dVar20;
              pdVar25 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4) + 8 + iVar2 * 8);
              *pdVar25 = *pdVar25 - dVar16;
              pdVar25 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4) + 0x10 + iVar2 * 8);
              *pdVar25 = *pdVar25 - dVar18;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
              *(double *)(iVar23 + iVar2 * 8) = *(double *)(iVar23 + iVar2 * 8) - dVar21;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
              *(double *)(iVar23 + 8 + iVar2 * 8) = *(double *)(iVar23 + 8 + iVar2 * 8) - dVar22;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
              pdVar25 = (double *)(iVar23 + 0x10 + iVar2 * 8);
              dVar19 = *(double *)(iVar23 + 0x10 + iVar2 * 8) - dVar19;
            }
          }
          *pdVar25 = dVar19;
          iVar26 = iVar26 + 1;
          local_58 = local_58 + 0x38;
        } while (iVar26 < *(int *)(param_1 + 0x22c));
      }
      iVar26 = 0;
      if (0 < *(int *)(param_1 + 0x234)) {
        iVar23 = 0;
        do {
          iVar24 = *(int *)(param_1 + 0x238) + iVar23;
          iVar3 = *(int *)(iVar24 + 0x7c);
          dVar14 = dVar6 * *(double *)(iVar24 + 0x50) +
                   dVar7 * *(double *)(iVar24 + 0x58) +
                   dVar5 * *(double *)(*(int *)(param_1 + 0x238) + 0x48 + iVar23);
          dVar15 = dVar9 * *(double *)(iVar24 + 0x50) +
                   dVar10 * *(double *)(iVar24 + 0x58) + dVar8 * *(double *)(iVar24 + 0x48);
          dVar16 = dVar12 * *(double *)(iVar24 + 0x50) +
                   dVar13 * *(double *)(iVar24 + 0x58) + dVar11 * *(double *)(iVar24 + 0x48);
          dVar17 = dVar6 * *(double *)(iVar24 + 0x68) +
                   dVar7 * *(double *)(iVar24 + 0x70) + dVar5 * *(double *)(iVar24 + 0x60);
          dVar18 = dVar9 * *(double *)(iVar24 + 0x68) +
                   dVar10 * *(double *)(iVar24 + 0x70) + dVar8 * *(double *)(iVar24 + 0x60);
          dVar19 = dVar12 * *(double *)(iVar24 + 0x68) +
                   dVar13 * *(double *)(iVar24 + 0x70) + dVar11 * *(double *)(iVar24 + 0x60);
          iVar4 = *(int *)(param_1 + 0x228);
          if (*(char *)(iVar24 + 0x80) == cVar1) {
            if (iVar3 < iVar2) {
              iVar4 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar14 + *(double *)(iVar4 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar4 + 8 + iVar3 * 8) = dVar17 + *(double *)(iVar4 + 8 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar15 + *(double *)(iVar4 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar4 + 8 + iVar3 * 8) = dVar18 + *(double *)(iVar4 + 8 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar16 + *(double *)(iVar4 + iVar3 * 8);
              pdVar25 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4) + 8 + iVar3 * 8);
            }
            else {
              iVar4 = *(int *)(iVar4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar14 + *(double *)(iVar4 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar4 + 8 + iVar2 * 8) = dVar15 + *(double *)(iVar4 + 8 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar4 + 0x10 + iVar2 * 8) = dVar16 + *(double *)(iVar4 + 0x10 + iVar2 * 8)
              ;
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar17 + *(double *)(iVar4 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
              *(double *)(iVar4 + 8 + iVar2 * 8) = dVar18 + *(double *)(iVar4 + 8 + iVar2 * 8);
              pdVar25 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4) + 0x10 + iVar2 * 8);
            }
            dVar19 = dVar19 + *pdVar25;
          }
          else if (iVar3 < iVar2) {
            iVar4 = *(int *)(iVar4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar14;
            pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4) + 8 + iVar3 * 8);
            *pdVar25 = *pdVar25 - dVar17;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar15;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar4 + 8 + iVar3 * 8) = *(double *)(iVar4 + 8 + iVar3 * 8) - dVar18;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar16;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            pdVar25 = (double *)(iVar4 + 8 + iVar3 * 8);
            dVar19 = *(double *)(iVar4 + 8 + iVar3 * 8) - dVar19;
          }
          else {
            iVar4 = *(int *)(iVar4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar14;
            pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 8 + iVar2 * 8);
            *pdVar25 = *pdVar25 - dVar15;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
            *(double *)(iVar4 + 0x10 + iVar2 * 8) = *(double *)(iVar4 + 0x10 + iVar2 * 8) - dVar16;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar17;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
            *(double *)(iVar4 + 8 + iVar2 * 8) = *(double *)(iVar4 + 8 + iVar2 * 8) - dVar18;
            iVar3 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
            pdVar25 = (double *)(iVar3 + 0x10 + iVar2 * 8);
            dVar19 = *(double *)(iVar3 + 0x10 + iVar2 * 8) - dVar19;
          }
          *pdVar25 = dVar19;
          iVar26 = iVar26 + 1;
          iVar23 = iVar23 + 0x84;
        } while (iVar26 < *(int *)(param_1 + 0x234));
      }
      iVar26 = 0;
      if (0 < *(int *)(param_1 + 0x23c)) {
        iVar23 = 0;
        do {
          iVar24 = *(int *)(param_1 + 0x240) + iVar23;
          iVar3 = *(int *)(iVar24 + 0x30);
          dVar14 = (dVar7 * *(double *)(iVar24 + 0x18) - dVar5 * *(double *)(iVar24 + 0x28)) *
                   *(double *)(iVar24 + 0x48) +
                   ((dVar6 * *(double *)(*(int *)(param_1 + 0x240) + 0x28 + iVar23) -
                    dVar7 * *(double *)(iVar24 + 0x20)) + *(double *)(param_1 + 0xb4)) *
                   *(double *)(iVar24 + 0x40) +
                   (dVar5 * *(double *)(iVar24 + 0x20) - dVar6 * *(double *)(iVar24 + 0x18)) *
                   *(double *)(iVar24 + 0x50);
          dVar15 = ((dVar10 * *(double *)(iVar24 + 0x18) - dVar8 * *(double *)(iVar24 + 0x28)) +
                   *(double *)(param_1 + 0xb4)) * *(double *)(iVar24 + 0x48) +
                   (dVar9 * *(double *)(iVar24 + 0x28) - dVar10 * *(double *)(iVar24 + 0x20)) *
                   *(double *)(iVar24 + 0x40) +
                   (dVar8 * *(double *)(iVar24 + 0x20) - dVar9 * *(double *)(iVar24 + 0x18)) *
                   *(double *)(iVar24 + 0x50);
          iVar4 = *(int *)(param_1 + 0x228);
          dVar16 = (dVar13 * *(double *)(iVar24 + 0x18) - dVar11 * *(double *)(iVar24 + 0x28)) *
                   *(double *)(iVar24 + 0x48) +
                   (dVar12 * *(double *)(iVar24 + 0x28) - dVar13 * *(double *)(iVar24 + 0x20)) *
                   *(double *)(iVar24 + 0x40) +
                   ((dVar11 * *(double *)(iVar24 + 0x20) - dVar12 * *(double *)(iVar24 + 0x18)) +
                   *(double *)(param_1 + 0xb4)) * *(double *)(iVar24 + 0x50);
          if (*(char *)(iVar24 + 0x34) == cVar1) {
            if (iVar3 < iVar2) {
              iVar4 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar14 + *(double *)(iVar4 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar15 + *(double *)(iVar4 + iVar3 * 8);
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4) + iVar3 * 8);
            }
            else {
              iVar4 = *(int *)(iVar4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar14 + *(double *)(iVar4 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar4 + 8 + iVar2 * 8) = dVar15 + *(double *)(iVar4 + 8 + iVar2 * 8);
              pdVar25 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 0x10 + iVar2 * 8);
            }
            dVar16 = dVar16 + *pdVar25;
          }
          else if (iVar3 < iVar2) {
            iVar4 = *(int *)(iVar4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar14;
            pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + iVar3 * 8);
            *pdVar25 = *pdVar25 - dVar15;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            pdVar25 = (double *)(iVar4 + iVar3 * 8);
            dVar16 = *(double *)(iVar4 + iVar3 * 8) - dVar16;
          }
          else {
            iVar4 = *(int *)(iVar4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar14;
            pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 8 + iVar2 * 8);
            *pdVar25 = *pdVar25 - dVar15;
            iVar3 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
            pdVar25 = (double *)(iVar3 + 0x10 + iVar2 * 8);
            dVar16 = *(double *)(iVar3 + 0x10 + iVar2 * 8) - dVar16;
          }
          *pdVar25 = dVar16;
          iVar26 = iVar26 + 1;
          iVar23 = iVar23 + 0x58;
        } while (iVar26 < *(int *)(param_1 + 0x23c));
      }
      iVar26 = *(int *)(param_1 + 0x22c);
      local_54 = local_54 + 1;
      local_a4 = local_a4 + 0x38;
    } while (local_54 < iVar26);
  }
  return;
}


