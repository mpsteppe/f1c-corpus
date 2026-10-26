// Function: FUN_004f88a0 @ 004f88a0
// Size (bytes): 248


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f88a0(int *param_1)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  char cVar9;
  uint uVar10;
  float10 fVar11;
  
  fVar1 = *(float *)(*param_1 + 0x39a0) / *(float *)(*param_1 + 0x39a4);
  fVar6 = DAT_0059e440;
  if ((DAT_0059e440 <= fVar1) && (fVar6 = fVar1, _DAT_0059e43c < fVar1)) {
    fVar6 = _DAT_0059e43c;
  }
  uVar10 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  fVar6 = fVar6 * _DAT_0059e908 + _DAT_0059e868;
  fVar7 = *(float *)(&DAT_008ab274 + uVar10 * 4) * _DAT_0059e448;
  fVar11 = (float10)FUN_004f1b10();
  fVar5 = (float10)_DAT_0059e7f8;
  uVar10 = DAT_008aae70 & 0xff;
  fVar3 = (float10)_DAT_0059e450;
  DAT_008aae70 = DAT_008aae70 + 1;
  fVar2 = (float10)_DAT_0059e43c;
  fVar1 = *(float *)(&DAT_008ab274 + uVar10 * 4);
  fVar4 = (float10)_DAT_0059e448;
  iVar8 = _rand();
  if (iVar8 < 0x2aaa) {
    cVar9 = '\x0e';
  }
  else {
    cVar9 = (iVar8 < 0x5554) + '\f';
  }
  FUN_004f87c0(cVar9,1,fVar7 + fVar6,
               (float)((float10)fVar1 * fVar4 + (fVar11 - fVar5) * fVar3 + fVar2));
  return;
}


