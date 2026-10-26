// Function: FUN_004e7f39 @ 004e7f39
// Size (bytes): 204


void FUN_004e7f39(void)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  undefined4 *puVar6;
  double *pdVar7;
  undefined4 *puVar8;
  float *pfVar9;
  int iVar10;
  int unaff_EBX;
  float *pfVar11;
  int unaff_EBP;
  float10 in_ST0;
  int iStack00000058;
  
  puVar8 = (undefined4 *)(unaff_EBX + 0x1078);
  puVar6 = (undefined4 *)(unaff_EBX + 0x3ab8);
  iStack00000058 = 0xd;
  *(float *)(unaff_EBX + 0x3968) = (float)in_ST0;
  do {
    *puVar8 = *puVar6;
    uVar3 = puVar6[2];
    puVar8[1] = puVar6[1];
    puVar8[2] = uVar3;
    puVar6 = puVar6 + 3;
    puVar8 = puVar8 + 7;
    iStack00000058 = iStack00000058 + -1;
  } while (iStack00000058 != 0);
  iVar10 = 0;
  pdVar7 = (double *)(*(int *)(unaff_EBP + 0xc) + 0x1450);
  pfVar11 = (float *)(unaff_EBX + 0x11e4);
  do {
    if ((iVar10 == 0) || (iVar10 == 1)) {
      pfVar9 = (float *)&stack0x000000ac;
    }
    else {
      pfVar9 = (float *)&stack0x00000084;
    }
    fVar4 = pfVar9[1];
    fVar5 = pfVar9[2];
    dVar1 = *pdVar7;
    iVar10 = iVar10 + 1;
    dVar2 = pdVar7[1];
    *pfVar11 = (float)pdVar7[-1] + *pfVar9;
    pfVar11[1] = (float)dVar1 + fVar4;
    pfVar11[2] = (float)dVar2 + fVar5;
    pdVar7 = pdVar7 + 0x21;
    pfVar11 = pfVar11 + 7;
  } while (iVar10 < 4);
  return;
}


