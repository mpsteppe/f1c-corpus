
void FUN_0050d0c2(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  int iVar32;
  
  fVar3 = param_3[4];
  fVar1 = *param_3;
  fVar2 = param_3[1];
  fVar4 = param_3[5];
  fVar5 = param_3[8];
  fVar6 = param_3[9];
  fVar7 = param_3[0xc];
  fVar19 = fVar4 * fVar1 - fVar3 * fVar2;
  fVar8 = param_3[0xd];
  fVar9 = param_3[0xe];
  fVar10 = param_3[0xf];
  fVar18 = fVar6 * fVar1 - fVar5 * fVar2;
  fVar17 = fVar8 * fVar1 - fVar7 * fVar2;
  fVar20 = fVar6 * fVar3 - fVar5 * fVar4;
  fVar21 = fVar8 * fVar3 - fVar7 * fVar4;
  fVar22 = fVar8 * fVar5 - fVar7 * fVar6;
  fVar1 = param_3[2];
  fVar2 = param_3[3];
  fVar3 = param_3[6];
  fVar4 = param_3[7];
  fVar5 = param_3[10];
  fVar6 = param_3[0xb];
  fVar31 = fVar1 * fVar4 - fVar3 * fVar2;
  fVar30 = fVar1 * fVar6 - fVar5 * fVar2;
  fVar23 = fVar1 * fVar10 - fVar9 * fVar2;
  fVar11 = *param_3;
  fVar12 = param_3[4];
  fVar13 = param_3[8];
  fVar28 = fVar3 * fVar6 - fVar5 * fVar4;
  fVar14 = param_3[9];
  fVar29 = fVar3 * fVar10 - fVar9 * fVar4;
  fVar15 = param_3[0xc];
  fVar26 = fVar5 * fVar10 - fVar9 * fVar6;
  fVar7 = param_3[1];
  fVar8 = param_3[5];
  fVar16 = param_3[0xd];
  fVar27 = (fVar30 * fVar8 - fVar31 * fVar14) - fVar28 * fVar7;
  fVar24 = fVar31 * fVar16 + (fVar29 * fVar7 - fVar23 * fVar8);
  fVar25 = (fVar23 * fVar14 - fVar30 * fVar16) - fVar26 * fVar7;
  fVar7 = fVar28 * fVar16 + (fVar26 * fVar8 - fVar29 * fVar14);
  fVar8 = fVar7 * fVar11 + fVar25 * fVar12 + fVar24 * fVar13 + fVar27 * fVar15;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar8;
  }
  fVar8 = 1.0 / fVar8;
  iVar32 = FUN_0058a88f((double)fVar8);
  if (iVar32 != 0) {
    *param_1 = fVar7 * fVar8;
    param_1[1] = fVar25 * fVar8;
    param_1[2] = fVar24 * fVar8;
    param_1[3] = fVar27 * fVar8;
    param_1[4] = ((fVar29 * fVar13 - fVar28 * fVar15) - fVar26 * fVar12) * fVar8;
    param_1[5] = (fVar30 * fVar15 + (fVar11 * fVar26 - fVar23 * fVar13)) * fVar8;
    param_1[6] = ((fVar23 * fVar12 - fVar31 * fVar15) - fVar29 * fVar11) * fVar8;
    param_1[7] = (fVar31 * fVar13 + (fVar28 * fVar11 - fVar30 * fVar12)) * fVar8;
    param_1[8] = (fVar20 * fVar10 + (fVar22 * fVar4 - fVar21 * fVar6)) * fVar8;
    param_1[9] = ((fVar17 * fVar6 - fVar18 * fVar10) - fVar22 * fVar2) * fVar8;
    param_1[10] = (fVar19 * fVar10 + (fVar21 * fVar2 - fVar17 * fVar4)) * fVar8;
    param_1[0xb] = ((fVar18 * fVar4 - fVar19 * fVar6) - fVar20 * fVar2) * fVar8;
    param_1[0xc] = ((fVar5 * fVar21 - fVar9 * fVar20) - fVar3 * fVar22) * fVar8;
    param_1[0xd] = (fVar9 * fVar18 + (fVar1 * fVar22 - fVar5 * fVar17)) * fVar8;
    param_1[0xe] = ((fVar3 * fVar17 - fVar9 * fVar19) - fVar1 * fVar21) * fVar8;
    param_1[0xf] = (fVar5 * fVar19 + (fVar1 * fVar20 - fVar3 * fVar18)) * fVar8;
  }
  return;
}

