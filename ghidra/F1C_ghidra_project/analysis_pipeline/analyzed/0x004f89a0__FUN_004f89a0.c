// Function: FUN_004f89a0 @ 004f89a0
// Size (bytes): 195


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f89a0(void)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  int iVar10;
  char cVar11;
  uint uVar12;
  float10 fVar13;
  float10 fVar14;
  
  fVar13 = (float10)FUN_004f1b10();
  fVar5 = (float10)_DAT_0059e908;
  fVar3 = (float10)_DAT_0059e868;
  fVar1 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4);
  DAT_008aae70 = DAT_008aae70 + 1;
  fVar6 = (float10)_DAT_0059e448;
  fVar14 = (float10)FUN_004f1b10();
  fVar9 = (float10)_DAT_0059e7f8;
  uVar12 = DAT_008aae70 & 0xff;
  fVar7 = (float10)_DAT_0059e450;
  DAT_008aae70 = DAT_008aae70 + 1;
  fVar4 = (float10)_DAT_0059e43c;
  fVar2 = *(float *)(&DAT_008ab274 + uVar12 * 4);
  fVar8 = (float10)_DAT_0059e448;
  iVar10 = _rand();
  if (iVar10 < 0x2aaa) {
    cVar11 = '\x11';
  }
  else {
    cVar11 = (iVar10 < 0x5554) + '\x0f';
  }
  FUN_004f87c0(cVar11,1,(float)((float10)fVar1 * fVar6 + fVar13 * fVar5 + fVar3),
               (float)((float10)fVar2 * fVar8 + (fVar14 - fVar9) * fVar7 + fVar4));
  return;
}


