// Function: FUN_00596e40 @ 00596e40
// Size (bytes): 429


undefined4 FUN_00596e40(undefined4 param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  FUN_0058dfea(0x19);
  CodePage = FUN_00596fed(param_1);
  if (CodePage != DAT_008d46bc) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_005e9b48;
LAB_00596e7d:
      if (*pUVar5 != CodePage) goto code_r0x00596e81;
      local_8 = 0;
      puVar15 = &DAT_008d47e0;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x5e9b58);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_005e9b40)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_008d47e0 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      DAT_008d46cc = 1;
      DAT_008d46bc = CodePage;
      DAT_008d48e4 = FUN_00597037(CodePage);
      DAT_008d46c0 = *(undefined4 *)(iVar12 + 0x5e9b4c);
      DAT_008d46c4 = *(undefined4 *)(iVar12 + 0x5e9b50);
      DAT_008d46c8 = *(undefined4 *)(iVar12 + 0x5e9b54);
      goto LAB_00596fd1;
    }
    goto LAB_00596fcc;
  }
  goto LAB_00596e67;
code_r0x00596e81:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x5e9c37 < (int)pUVar5) goto code_r0x00596e8c;
  goto LAB_00596e7d;
code_r0x00596e8c:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_008d48e4 = 0;
    puVar15 = &DAT_008d47e0;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_008d46cc = 0;
      DAT_008d46bc = CodePage;
    }
    else {
      DAT_008d46bc = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_008d47e0 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_008d47e0 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_008d48e4 = FUN_00597037(CodePage);
      DAT_008d46cc = 1;
    }
    DAT_008d46c0 = 0;
    DAT_008d46c4 = 0;
    DAT_008d46c8 = 0;
  }
  else {
    if (DAT_008d41d4 == 0) {
      uVar14 = 0xffffffff;
      goto LAB_00596fde;
    }
LAB_00596fcc:
    FUN_0059706a();
  }
LAB_00596fd1:
  FUN_00597093();
LAB_00596e67:
  uVar14 = 0;
LAB_00596fde:
  FUN_0058e04b(0x19);
  return uVar14;
}


