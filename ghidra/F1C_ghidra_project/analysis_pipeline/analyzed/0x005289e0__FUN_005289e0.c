// Function: FUN_005289e0 @ 005289e0
// Size (bytes): 492


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005289e0(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  
  fVar6 = (float)(*param_1 & _DAT_005d9060);
  fVar10 = (float)(param_1[1] & uRam005d9064);
  fVar14 = (float)(param_1[2] & uRam005d9068);
  fVar18 = (float)(param_1[3] & uRam005d906c);
  uVar22 = param_1[1] & uRam005d9054;
  uVar23 = param_1[2] & uRam005d9058;
  uVar24 = param_1[3] & uRam005d905c;
  fVar7 = fVar6 * _DAT_005d9040 + _DAT_005d8ff0;
  fVar11 = fVar10 * fRam005d9044 + fRam005d8ff4;
  fVar15 = fVar14 * fRam005d9048 + fRam005d8ff8;
  fVar19 = fVar18 * fRam005d904c + fRam005d8ffc;
  fVar8 = fVar7 - _DAT_005d8ff0;
  fVar12 = fVar11 - fRam005d8ff4;
  fVar16 = fVar15 - fRam005d8ff8;
  fVar20 = fVar19 - fRam005d8ffc;
  fVar6 = (((fVar6 - _DAT_005d9030 * fVar8) - _DAT_005d9020 * fVar8) - _DAT_005d9010 * fVar8) -
          _DAT_005d9000 * fVar8;
  fVar8 = (((fVar10 - fRam005d9034 * fVar12) - fRam005d9024 * fVar12) - fRam005d9014 * fVar12) -
          fRam005d9004 * fVar12;
  fVar10 = (((fVar14 - fRam005d9038 * fVar16) - fRam005d9028 * fVar16) - fRam005d9018 * fVar16) -
           fRam005d9008 * fVar16;
  fVar12 = (((fVar18 - fRam005d903c * fVar20) - fRam005d902c * fVar20) - fRam005d901c * fVar20) -
           fRam005d900c * fVar20;
  fVar14 = fVar6 * fVar6;
  fVar16 = fVar8 * fVar8;
  fVar18 = fVar10 * fVar10;
  fVar20 = fVar12 * fVar12;
  uVar25 = (uint)fVar7 & (uint)PTR_DAT_005d8fc0;
  uVar26 = (uint)fVar11 & (uint)PTR_DAT_005d8fc4;
  uVar27 = (uint)fVar15 & (uint)PTR_DAT_005d8fc8;
  uVar28 = (uint)fVar19 & (uint)PTR_DAT_005d8fcc;
  uVar9 = uVar25 & _DAT_005d8fb0;
  uVar13 = uVar26 & uRam005d8fb4;
  uVar17 = uVar27 & uRam005d8fb8;
  uVar21 = uVar28 & uRam005d8fbc;
  uVar1 = uVar26 - uVar13 & _DAT_005d8fa0;
  uVar2 = uVar27 - uVar17 & _DAT_005d8fa0;
  uVar3 = uVar28 - uVar21 & _DAT_005d8fa0;
  uVar4 = uVar25 + uVar9 & _DAT_005d8fa0;
  uVar26 = uVar26 + uVar13 & _DAT_005d8fa0;
  uVar27 = uVar27 + uVar17 & _DAT_005d8fa0;
  uVar28 = uVar28 + uVar21 & _DAT_005d8fa0;
  uVar5 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar13 = -(uint)((float)(uVar13 << 0x1e) != 0.0);
  uVar17 = -(uint)((float)(uVar17 << 0x1e) != 0.0);
  uVar21 = -(uint)((float)(uVar21 << 0x1e) != 0.0);
  fVar6 = (((_DAT_005d8fe0 * fVar14 + _DAT_005d8f90) * fVar14 + _DAT_005d8f70) * fVar14 +
          _DAT_005d8f50) * fVar6;
  fVar8 = (((fRam005d8fe4 * fVar16 + fRam005d8f94) * fVar16 + fRam005d8f74) * fVar16 + fRam005d8f54)
          * fVar8;
  fVar10 = (((fRam005d8fe8 * fVar18 + fRam005d8f98) * fVar18 + fRam005d8f78) * fVar18 + fRam005d8f58
           ) * fVar10;
  fVar12 = (((fRam005d8fec * fVar20 + fRam005d8f9c) * fVar20 + fRam005d8f7c) * fVar20 + fRam005d8f5c
           ) * fVar12;
  fVar7 = (((_DAT_005d8fd0 * fVar14 + _DAT_005d8f80) * fVar14 + _DAT_005d8f60) * fVar14 +
          _DAT_005d8f40) * fVar14 + _DAT_005d8f30;
  fVar11 = (((fRam005d8fd4 * fVar16 + fRam005d8f84) * fVar16 + fRam005d8f64) * fVar16 + fRam005d8f44
           ) * fVar16 + fRam005d8f34;
  fVar14 = (((fRam005d8fd8 * fVar18 + fRam005d8f88) * fVar18 + fRam005d8f68) * fVar18 + fRam005d8f48
           ) * fVar18 + fRam005d8f38;
  fVar15 = (((fRam005d8fdc * fVar20 + fRam005d8f8c) * fVar20 + fRam005d8f6c) * fVar20 + fRam005d8f4c
           ) * fVar20 + fRam005d8f3c;
  *param_2 = (~uVar5 & (uint)fVar6 | uVar5 & (uint)fVar7) ^
             (uVar25 - uVar9 & _DAT_005d8fa0) << 0x1e ^ *param_1 & _DAT_005d9050;
  param_2[1] = (~uVar13 & (uint)fVar8 | uVar13 & (uint)fVar11) ^ uVar1 << 0x1e ^ uVar22;
  param_2[2] = (~uVar17 & (uint)fVar10 | uVar17 & (uint)fVar14) ^ uVar2 << 0x1e ^ uVar23;
  param_2[3] = (~uVar21 & (uint)fVar12 | uVar21 & (uint)fVar15) ^ uVar3 << 0x1e ^ uVar24;
  *param_3 = (uVar5 & (uint)fVar6 | ~uVar5 & (uint)fVar7) ^ uVar4 << 0x1e;
  param_3[1] = (uVar13 & (uint)fVar8 | ~uVar13 & (uint)fVar11) ^ uVar26 << 0x1e;
  param_3[2] = (uVar17 & (uint)fVar10 | ~uVar17 & (uint)fVar14) ^ uVar27 << 0x1e;
  param_3[3] = (uVar21 & (uint)fVar12 | ~uVar21 & (uint)fVar15) ^ uVar28 << 0x1e;
  return;
}


