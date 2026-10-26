// Function: FUN_0056b5d0 @ 0056b5d0
// Size (bytes): 1309


void __fastcall FUN_0056b5d0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
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
  int iVar16;
  int iVar17;
  double *pdVar18;
  int iVar19;
  undefined4 local_60;
  undefined4 local_5c;
  
  if (0 < *(int *)(param_1 + 0x234)) {
    local_60 = 1;
    local_5c = 0;
    do {
      iVar16 = *(int *)(param_1 + 0x238) + local_5c;
      iVar2 = *(int *)(iVar16 + 0x7c);
      cVar1 = *(char *)(iVar16 + 0x80);
      pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4) + iVar2 * 8);
      dVar6 = *(double *)(param_1 + 0xec) * *(double *)(iVar16 + 0x48) +
              *(double *)(param_1 + 0xf4) * *(double *)(iVar16 + 0x50) +
              *(double *)(param_1 + 0xfc) * *(double *)(*(int *)(param_1 + 0x238) + 0x58 + local_5c)
      ;
      dVar7 = *(double *)(param_1 + 0x104) * *(double *)(iVar16 + 0x48) +
              *(double *)(param_1 + 0x10c) * *(double *)(iVar16 + 0x50) +
              *(double *)(param_1 + 0x114) * *(double *)(iVar16 + 0x58);
      dVar8 = *(double *)(param_1 + 0x11c) * *(double *)(iVar16 + 0x48) +
              *(double *)(param_1 + 0x124) * *(double *)(iVar16 + 0x50) +
              *(double *)(param_1 + 300) * *(double *)(iVar16 + 0x58);
      dVar9 = *(double *)(iVar16 + 0x68) * *(double *)(param_1 + 0xf4) +
              *(double *)(iVar16 + 0x70) * *(double *)(param_1 + 0xfc) +
              *(double *)(param_1 + 0xec) * *(double *)(iVar16 + 0x60);
      dVar10 = *(double *)(param_1 + 0x104) * *(double *)(iVar16 + 0x60) +
               *(double *)(iVar16 + 0x70) * *(double *)(param_1 + 0x114) +
               *(double *)(param_1 + 0x10c) * *(double *)(iVar16 + 0x68);
      dVar11 = *(double *)(param_1 + 0x124) * *(double *)(iVar16 + 0x68) +
               *(double *)(iVar16 + 0x60) * *(double *)(param_1 + 0x11c) +
               *(double *)(param_1 + 300) * *(double *)(iVar16 + 0x70);
      *pdVar18 = dVar6 * *(double *)(iVar16 + 0x48) +
                 dVar7 * *(double *)(iVar16 + 0x50) + dVar8 * *(double *)(iVar16 + 0x58) + *pdVar18;
      pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + iVar2 * 8);
      *pdVar18 = dVar9 * *(double *)(iVar16 + 0x48) +
                 dVar10 * *(double *)(iVar16 + 0x50) + dVar11 * *(double *)(iVar16 + 0x58) +
                 *pdVar18;
      pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + 8 + iVar2 * 8);
      *pdVar18 = dVar9 * *(double *)(iVar16 + 0x60) +
                 dVar10 * *(double *)(iVar16 + 0x68) + dVar11 * *(double *)(iVar16 + 0x70) +
                 *pdVar18;
      iVar19 = local_60;
      iVar16 = local_5c;
      if (local_60 < *(int *)(param_1 + 0x234)) {
        do {
          iVar16 = iVar16 + 0x84;
          iVar17 = *(int *)(param_1 + 0x238) + iVar16;
          iVar3 = *(int *)(iVar17 + 0x7c);
          dVar12 = dVar7 * *(double *)(iVar17 + 0x50) +
                   dVar6 * *(double *)(iVar17 + 0x48) +
                   dVar8 * *(double *)(*(int *)(param_1 + 0x238) + 0x58 + iVar16);
          dVar13 = dVar10 * *(double *)(iVar17 + 0x50) +
                   dVar9 * *(double *)(iVar17 + 0x48) + dVar11 * *(double *)(iVar17 + 0x58);
          dVar14 = dVar10 * *(double *)(iVar17 + 0x68) +
                   dVar9 * *(double *)(iVar17 + 0x60) + dVar11 * *(double *)(iVar17 + 0x70);
          iVar4 = *(int *)(param_1 + 0x228);
          dVar15 = dVar7 * *(double *)(iVar17 + 0x68) +
                   dVar6 * *(double *)(iVar17 + 0x60) + dVar8 * *(double *)(iVar17 + 0x70);
          if (*(char *)(iVar17 + 0x80) == cVar1) {
            if (iVar3 < iVar2) {
              iVar4 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar12 + *(double *)(iVar4 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar4 + 8 + iVar3 * 8) = dVar15 + *(double *)(iVar4 + 8 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar13 + *(double *)(iVar4 + iVar3 * 8);
              pdVar18 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + 8 + iVar3 * 8);
            }
            else {
              iVar4 = *(int *)(iVar4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar12 + *(double *)(iVar4 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar4 + 8 + iVar2 * 8) = dVar13 + *(double *)(iVar4 + 8 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar15 + *(double *)(iVar4 + iVar2 * 8);
              pdVar18 = (double *)
                        (*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4) + 8 + iVar2 * 8);
            }
            dVar14 = dVar14 + *pdVar18;
          }
          else if (iVar3 < iVar2) {
            iVar4 = *(int *)(iVar4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar12;
            pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4) + 8 + iVar3 * 8);
            *pdVar18 = *pdVar18 - dVar15;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar13;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            pdVar18 = (double *)(iVar4 + 8 + iVar3 * 8);
            dVar14 = *(double *)(iVar4 + 8 + iVar3 * 8) - dVar14;
          }
          else {
            iVar4 = *(int *)(iVar4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar12;
            pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 8 + iVar2 * 8);
            *pdVar18 = *pdVar18 - dVar13;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar15;
            iVar3 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
            pdVar18 = (double *)(iVar3 + 8 + iVar2 * 8);
            dVar14 = *(double *)(iVar3 + 8 + iVar2 * 8) - dVar14;
          }
          *pdVar18 = dVar14;
          iVar19 = iVar19 + 1;
        } while (iVar19 < *(int *)(param_1 + 0x234));
      }
      iVar16 = 0;
      if (0 < *(int *)(param_1 + 0x23c)) {
        iVar19 = 0;
        do {
          iVar17 = *(int *)(param_1 + 0x240) + iVar19;
          iVar3 = *(int *)(iVar17 + 0x30);
          dVar12 = (dVar7 * *(double *)(*(int *)(param_1 + 0x240) + 0x28 + iVar19) -
                   dVar8 * *(double *)(iVar17 + 0x20)) * *(double *)(iVar17 + 0x40) +
                   (dVar8 * *(double *)(iVar17 + 0x18) - dVar6 * *(double *)(iVar17 + 0x28)) *
                   *(double *)(iVar17 + 0x48) +
                   (dVar6 * *(double *)(iVar17 + 0x20) - dVar7 * *(double *)(iVar17 + 0x18)) *
                   *(double *)(iVar17 + 0x50);
          iVar4 = *(int *)(param_1 + 0x228);
          dVar13 = (dVar10 * *(double *)(iVar17 + 0x28) - dVar11 * *(double *)(iVar17 + 0x20)) *
                   *(double *)(iVar17 + 0x40) +
                   (dVar9 * *(double *)(iVar17 + 0x20) - dVar10 * *(double *)(iVar17 + 0x18)) *
                   *(double *)(iVar17 + 0x50) +
                   (dVar11 * *(double *)(iVar17 + 0x18) - dVar9 * *(double *)(iVar17 + 0x28)) *
                   *(double *)(iVar17 + 0x48);
          if (*(char *)(iVar17 + 0x34) == cVar1) {
            if (iVar3 < iVar2) {
              iVar4 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar12 + *(double *)(iVar4 + iVar3 * 8);
              pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + iVar3 * 8);
            }
            else {
              iVar4 = *(int *)(iVar4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar12 + *(double *)(iVar4 + iVar2 * 8);
              pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 8 + iVar2 * 8);
            }
            dVar13 = dVar13 + *pdVar18;
          }
          else if (iVar3 < iVar2) {
            iVar4 = *(int *)(iVar4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar12;
            pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + iVar3 * 8);
            dVar13 = *pdVar18 - dVar13;
          }
          else {
            iVar4 = *(int *)(iVar4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar12;
            pdVar18 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 8 + iVar2 * 8);
            dVar13 = *pdVar18 - dVar13;
          }
          *pdVar18 = dVar13;
          iVar16 = iVar16 + 1;
          iVar19 = iVar19 + 0x58;
        } while (iVar16 < *(int *)(param_1 + 0x23c));
      }
      local_5c = local_5c + 0x84;
      bVar5 = local_60 < *(int *)(param_1 + 0x234);
      local_60 = local_60 + 1;
    } while (bVar5);
  }
  return;
}


