// Function: FUN_00426100 @ 00426100
// Size (bytes): 552


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00426100(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float10 fVar7;
  
  iVar1 = *(int *)(param_1 + 0x4468);
  fVar3 = *(float *)(param_1 + 0x34e0) - *(float *)(param_1 + 0x4498);
  fVar4 = *(float *)(param_1 + 0x34e8) - *(float *)(param_1 + 0x44a0);
  while( true ) {
    fVar5 = SQRT(fVar3 * fVar3 + fVar4 * fVar4);
    *(float *)(param_1 + 0x44a4) = fVar5;
    iVar2 = *(int *)(param_1 + 0x4354 + iVar1 * 4);
    fVar5 = (*(float *)(iVar2 + 0x20) * *(float *)(param_1 + 0x4408) + *(float *)(iVar2 + 0x94) +
            fVar5 * *(float *)(iVar2 + 0xa4)) - *(float *)(param_1 + 0x34e0);
    fVar6 = (*(float *)(iVar2 + 0x28) * *(float *)(param_1 + 0x4408) + *(float *)(iVar2 + 0x9c) +
            *(float *)(iVar2 + 0xac) * *(float *)(param_1 + 0x44a4)) - *(float *)(param_1 + 0x34e8);
    if ((fVar5 * *(float *)(param_1 + 0x448c) + fVar6 * *(float *)(param_1 + 0x4494)) /
        SQRT(fVar5 * fVar5 + fVar6 * fVar6) < _DAT_0059e43c) {
      fVar7 = (float10)FUN_005894a0();
      if (DAT_0059e440 < fVar6 * *(float *)(param_1 + 0x448c) - fVar5 * *(float *)(param_1 + 0x4494)
         ) {
        fVar7 = -fVar7;
      }
      fVar7 = fVar7 / (float10)*(float *)(param_1 + 0x44b4);
      if (*(int *)(param_1 + 0x4510) == 6) {
        fVar7 = -fVar7;
      }
    }
    else {
      fVar7 = (float10)DAT_0059e440;
    }
    if (fVar7 - (float10)*(float *)(param_1 + 0x442c) <= (float10)_DAT_0059e84c) {
      if ((float10)_DAT_0059e84c < (float10)*(float *)(param_1 + 0x442c) - fVar7) {
        fVar7 = (float10)*(float *)(param_1 + 0x442c) - (float10)_DAT_0059e84c;
      }
    }
    else {
      fVar7 = (float10)*(float *)(param_1 + 0x442c) + (float10)_DAT_0059e84c;
    }
    *(float *)(param_1 + 0x442c) = (float)fVar7;
    if (_DAT_0059e43c < *(float *)(param_1 + 0x442c)) {
      *(undefined4 *)(param_1 + 0x442c) = 0x3f800000;
      return;
    }
    if (*(float *)(param_1 + 0x442c) < _DAT_0059e670) {
      *(undefined4 *)(param_1 + 0x442c) = 0xbf800000;
      return;
    }
    if ((*(float *)(param_1 + 0x442c) < _DAT_0059e43c ==
         (*(float *)(param_1 + 0x442c) == _DAT_0059e43c)) ||
       (*(float *)(param_1 + 0x442c) < _DAT_0059e670)) break;
    if ((*(float *)(param_1 + 0x442c) < _DAT_0059e43c !=
         (*(float *)(param_1 + 0x442c) == _DAT_0059e43c)) &&
       (_DAT_0059e670 <= *(float *)(param_1 + 0x442c))) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x442c) = 0;
  return;
}


