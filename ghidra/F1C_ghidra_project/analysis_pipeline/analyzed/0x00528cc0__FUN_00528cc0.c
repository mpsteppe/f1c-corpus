// Function: FUN_00528cc0 @ 00528cc0
// Size (bytes): 329


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00528cc0(uint *param_1,uint *param_2,uint *param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  float fVar25;
  float fVar26;
  uint uVar27;
  uint uVar28;
  
  fVar16 = (float)(*param_1 & _DAT_005d9280);
  fVar17 = (float)(param_1[1] & uRam005d9284);
  fVar25 = (float)(param_1[2] & uRam005d9288);
  fVar26 = (float)(param_1[3] & uRam005d928c);
  uVar13 = param_1[1] & uRam005d9274;
  uVar14 = param_1[2] & uRam005d9278;
  uVar15 = param_1[3] & uRam005d927c;
  fVar1 = fVar16 * _DAT_005d9260 + _DAT_005d9210;
  fVar4 = fVar17 * fRam005d9264 + fRam005d9214;
  fVar7 = fVar25 * fRam005d9268 + fRam005d9218;
  fVar10 = fVar26 * fRam005d926c + fRam005d921c;
  fVar2 = fVar1 - _DAT_005d9210;
  fVar5 = fVar4 - fRam005d9214;
  fVar8 = fVar7 - fRam005d9218;
  fVar11 = fVar10 - fRam005d921c;
  fVar16 = (((fVar16 - _DAT_005d9250 * fVar2) - _DAT_005d9240 * fVar2) - _DAT_005d9230 * fVar2) -
           _DAT_005d9220 * fVar2;
  fVar2 = (((fVar17 - fRam005d9254 * fVar5) - fRam005d9244 * fVar5) - fRam005d9234 * fVar5) -
          fRam005d9224 * fVar5;
  fVar17 = (((fVar25 - fRam005d9258 * fVar8) - fRam005d9248 * fVar8) - fRam005d9238 * fVar8) -
           fRam005d9228 * fVar8;
  fVar5 = (((fVar26 - fRam005d925c * fVar11) - fRam005d924c * fVar11) - fRam005d923c * fVar11) -
          fRam005d922c * fVar11;
  fVar25 = fVar16 * fVar16;
  fVar8 = fVar2 * fVar2;
  fVar26 = fVar17 * fVar17;
  fVar11 = fVar5 * fVar5;
  uVar18 = (uint)fVar1 & (uint)PTR_DAT_005d91e0;
  uVar19 = (uint)fVar4 & (uint)PTR_DAT_005d91e4;
  uVar21 = (uint)fVar7 & (uint)PTR_DAT_005d91e8;
  uVar23 = (uint)fVar10 & (uint)PTR_DAT_005d91ec;
  uVar3 = uVar18 & _DAT_005d91d0;
  uVar6 = uVar19 & uRam005d91d4;
  uVar9 = uVar21 & uRam005d91d8;
  uVar12 = uVar23 & uRam005d91dc;
  uVar20 = uVar19 - uVar6 & uRam005d91c4;
  uVar22 = uVar21 - uVar9 & uRam005d91c8;
  uVar24 = uVar23 - uVar12 & uRam005d91cc;
  uVar27 = uVar18 + uVar3 & _DAT_005d91c0;
  uVar28 = uVar19 + uVar6 & uRam005d91c4;
  uVar21 = uVar21 + uVar9 & uRam005d91c8;
  uVar23 = uVar23 + uVar12 & uRam005d91cc;
  uVar19 = -(uint)((float)(uVar3 << 0x1e) != 0.0);
  uVar6 = -(uint)((float)(uVar6 << 0x1e) != 0.0);
  uVar9 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar12 = -(uint)((float)(uVar12 << 0x1e) != 0.0);
  fVar16 = (((_DAT_005d9200 * fVar25 + _DAT_005d91b0) * fVar25 + _DAT_005d9190) * fVar25 +
           _DAT_005d9170) * fVar16;
  fVar2 = (((fRam005d9204 * fVar8 + fRam005d91b4) * fVar8 + fRam005d9194) * fVar8 + fRam005d9174) *
          fVar2;
  fVar17 = (((fRam005d9208 * fVar26 + fRam005d91b8) * fVar26 + fRam005d9198) * fVar26 + fRam005d9178
           ) * fVar17;
  fVar5 = (((fRam005d920c * fVar11 + fRam005d91bc) * fVar11 + fRam005d919c) * fVar11 + fRam005d917c)
          * fVar5;
  fVar1 = (((_DAT_005d91f0 * fVar25 + _DAT_005d91a0) * fVar25 + _DAT_005d9180) * fVar25 +
          _DAT_005d9160) * fVar25 + _DAT_005d9150;
  fVar4 = (((fRam005d91f4 * fVar8 + fRam005d91a4) * fVar8 + fRam005d9184) * fVar8 + fRam005d9164) *
          fVar8 + fRam005d9154;
  fVar25 = (((fRam005d91f8 * fVar26 + fRam005d91a8) * fVar26 + fRam005d9188) * fVar26 + fRam005d9168
           ) * fVar26 + fRam005d9158;
  fVar7 = (((fRam005d91fc * fVar11 + fRam005d91ac) * fVar11 + fRam005d918c) * fVar11 + fRam005d916c)
          * fVar11 + fRam005d915c;
  *param_2 = (~uVar19 & (uint)fVar16 | uVar19 & (uint)fVar1) ^
             (uVar18 - uVar3 & _DAT_005d91c0) << 0x1e ^ *param_1 & _DAT_005d9270;
  param_2[1] = (~uVar6 & (uint)fVar2 | uVar6 & (uint)fVar4) ^ uVar20 << 0x1e ^ uVar13;
  param_2[2] = (~uVar9 & (uint)fVar17 | uVar9 & (uint)fVar25) ^ uVar22 << 0x1e ^ uVar14;
  param_2[3] = (~uVar12 & (uint)fVar5 | uVar12 & (uint)fVar7) ^ uVar24 << 0x1e ^ uVar15;
  *param_3 = (uVar19 & (uint)fVar16 | ~uVar19 & (uint)fVar1) ^ uVar27 << 0x1e;
  param_3[1] = (uVar6 & (uint)fVar2 | ~uVar6 & (uint)fVar4) ^ uVar28 << 0x1e;
  param_3[2] = (uVar9 & (uint)fVar17 | ~uVar9 & (uint)fVar25) ^ uVar21 << 0x1e;
  param_3[3] = (uVar12 & (uint)fVar5 | ~uVar12 & (uint)fVar7) ^ uVar23 << 0x1e;
  return;
}


