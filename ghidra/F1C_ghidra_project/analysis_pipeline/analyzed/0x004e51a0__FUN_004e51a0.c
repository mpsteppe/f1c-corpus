// Function: FUN_004e51a0 @ 004e51a0
// Size (bytes): 716


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e51a0(int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  float10 fVar8;
  
  bVar4 = *(float *)(param_1 + 0x3994) == DAT_0059e440;
  pfVar6 = (float *)(param_1 + 0x35d4);
  *pfVar6 = 0.0;
  *(undefined4 *)(param_1 + 0x36cc) = 0;
  *(undefined4 *)(param_1 + 0x37c4) = 0;
  *(undefined4 *)(param_1 + 0x38bc) = 0;
  if ((bVar4) &&
     (*(undefined4 *)(param_1 + 0x3578) = 0x3f800000, DAT_0059e440 < *(float *)(param_1 + 0x39b8)))
  {
    fVar2 = *(float *)(param_1 + 0x39b8);
    fVar5 = *(float *)(param_1 + 0x39b8) - *(float *)(param_1 + 0x34a8);
    *(float *)(param_1 + 0x39b8) = fVar5;
    if ((fVar5 < *(float *)(param_1 + 0x39c4) != (fVar5 == *(float *)(param_1 + 0x39c4))) &&
       ((*(float *)(param_1 + 0x39c4) < fVar2 &&
        (*(float *)(param_1 + 0x3994) < *(float *)(param_1 + 0x399c))))) {
      FUN_004f87c0(0x27,2,0x3f800000,0x3f800000);
    }
    if ((*(float *)(param_1 + 0x39b8) < DAT_0059e440 !=
         (*(float *)(param_1 + 0x39b8) == DAT_0059e440)) &&
       (*(float *)(param_1 + 0x3994) < *(float *)(param_1 + 0x399c))) {
      *(undefined4 *)(param_1 + 0x3994) = *(undefined4 *)(param_1 + 0x399c);
    }
  }
  fVar2 = *(float *)(param_1 + 0x3a30) * *(float *)(param_1 + 0x3578) + *(float *)(param_1 + 0x3a34)
  ;
  *(float *)(param_1 + 0x35d8) = fVar2;
  *(float *)(param_1 + 0x36d0) = fVar2;
  fVar2 = *(float *)(param_1 + 0x3a44) * *(float *)(param_1 + 0x3578) + *(float *)(param_1 + 0x3a48)
  ;
  *(float *)(param_1 + 0x37c8) = fVar2;
  *(float *)(param_1 + 0x38c0) = fVar2;
  if (*(float *)(param_1 + 0x3978) < DAT_0059e440 != (*(float *)(param_1 + 0x3978) == DAT_0059e440))
  {
    *(undefined4 *)(param_1 + 0x3570) = 0;
  }
  fVar2 = *(float *)(param_1 + 0x3570);
  fVar5 = *(float *)(param_1 + 0x3994) * _DAT_0059ed18;
  fVar8 = (float10)FUN_005895a2((double)fVar5);
  iVar7 = (int)ROUND((float)fVar8);
  fVar5 = fVar5 - (float)fVar8;
  iVar3 = *(int *)(param_1 + 0x39a4);
  pfVar1 = (float *)(iVar3 + 4 + iVar7 * 8);
  *(float *)(param_1 + 0x39a8) =
       (*(float *)(iVar3 + 8 + iVar7 * 8) - *(float *)(iVar3 + iVar7 * 8)) * fVar5 +
       *(float *)(iVar3 + iVar7 * 8);
  fVar5 = (*(float *)(iVar3 + 0xc + iVar7 * 8) - *pfVar1) * fVar5 + *pfVar1;
  *(float *)(param_1 + 0x39ac) = fVar5;
  fVar5 = fVar5 * fVar2 + *(float *)(param_1 + 0x39a8);
  *(float *)(param_1 + 0x39a0) = fVar5;
  if (*(int *)(param_1 + 0x39f0) == 0) {
    return;
  }
  if (*(float *)(param_1 + 0x3994) <= DAT_0059e440) {
    return;
  }
  if (*(float *)(param_1 + 0x3964) != *(float *)(param_1 + 0x3994)) {
    if (*(float *)(param_1 + 0x3964) == *(float *)(param_1 + 0x3994)) goto LAB_004e540c;
    if (*(float *)(param_1 + 0x3994) <= *(float *)(param_1 + 0x3964)) {
      if (DAT_0059e440 < fVar5) {
        fVar2 = -(DAT_0059e440 * *(float *)(param_1 + 0x39c8));
        goto LAB_004e540c;
      }
    }
    else if (fVar5 < DAT_0059e440) {
      fVar2 = -(DAT_0059e440 * *(float *)(param_1 + 0x39c8));
      goto LAB_004e540c;
    }
  }
  fVar2 = -(fVar5 * *(float *)(param_1 + 0x39c8));
LAB_004e540c:
  iVar7 = *(int *)(param_1 + 0x39b4);
  if (iVar7 == 0) {
    fVar2 = fVar2 * _DAT_0059e450;
    *(float *)(param_1 + 0x37c4) = fVar2;
    *(float *)(param_1 + 0x38bc) = fVar2;
    return;
  }
  if (iVar7 == 1) {
    fVar2 = fVar2 * _DAT_0059e7f8;
    iVar7 = 4;
    do {
      *pfVar6 = fVar2;
      pfVar6 = pfVar6 + 0x3e;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  else if (iVar7 == 2) {
    fVar2 = fVar2 * _DAT_0059e450;
    *pfVar6 = fVar2;
    *(float *)(param_1 + 0x36cc) = fVar2;
    return;
  }
  return;
}


