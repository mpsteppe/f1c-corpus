// Function: FUN_004f12e0 @ 004f12e0
// Size (bytes): 550


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f12e0(int param_1,char param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int aiStack_2c [5];
  int aiStack_18 [6];
  
  if (param_2 != '\0') {
    iVar9 = 0;
    iVar6 = 0;
    piVar7 = (int *)(param_1 + 0x3668);
    _param_2 = 5.60519e-45;
    do {
      if (*piVar7 != 0) {
        iVar8 = *(int *)(*piVar7 + 0x54);
        iVar5 = 0;
        if (0 < iVar9) {
          do {
            if (aiStack_18[iVar5] == *(int *)(iVar8 + 0x34)) break;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar9);
        }
        if (iVar5 == iVar9) {
          aiStack_18[iVar9] = *(int *)(iVar8 + 0x34);
          iVar9 = iVar9 + 1;
        }
        iVar5 = 0;
        if (0 < iVar6) {
          do {
            if (aiStack_2c[iVar5] == *(int *)(iVar8 + 0x30)) break;
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar6);
        }
        if (iVar5 == iVar6) {
          aiStack_2c[iVar6] = *(int *)(iVar8 + 0x30);
          iVar6 = iVar6 + 1;
        }
      }
      piVar7 = piVar7 + 0x3e;
      _param_2 = (float)((int)_param_2 + -1);
    } while (_param_2 != 0.0);
    iVar8 = 0;
    fVar1 = SQRT(*(float *)(param_1 + 0x34f4) * *(float *)(param_1 + 0x34f4) +
                 *(float *)(param_1 + 0x34f0) * *(float *)(param_1 + 0x34f0) +
                 *(float *)(param_1 + 0x34ec) * *(float *)(param_1 + 0x34ec));
    if (0 < iVar9) {
      do {
        FUN_004f0f40(aiStack_18[iVar8]);
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar9);
    }
    iVar9 = 0;
    if (0 < iVar6) {
      do {
        FUN_004f1120(aiStack_2c[iVar9],fVar1);
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar6);
    }
    fVar2 = *(float *)(param_1 + 0x3a58) - *(float *)(param_1 + 0x34ec);
    fVar4 = *(float *)(param_1 + 0x3a5c) - *(float *)(param_1 + 0x34f0);
    fVar3 = *(float *)(param_1 + 0x3a60) - *(float *)(param_1 + 0x34f4);
    _param_2 = (SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) - _DAT_0059e800) * _DAT_005ad238
    ;
    if (DAT_0059e440 < _param_2) {
      if (_param_2 <= _DAT_0059e43c) {
        _param_2 = _param_2 * _param_2;
      }
      else {
        _param_2 = 1.0;
      }
      FUN_004f87c0(5,1,_param_2,fVar1 * _DAT_005ac988 + _DAT_0059e824);
    }
  }
  if (*(float *)(param_1 + 0x7a4) <= (float)_DAT_0059e430) {
    *(undefined1 *)(param_1 + 0x5fc) = 0;
  }
  else {
    FUN_004f87c0(0x2a,2,*(undefined4 *)(param_1 + 0x7a4),0x3f800000);
  }
  if (*(int *)(param_1 + 0x32bc) == 0) {
    if (_DAT_007c9138 <= _DAT_007c9150) {
      return;
    }
  }
  else {
    if (*(int *)(param_1 + 0x32bc) != 1) {
      return;
    }
    if (*(float *)(param_1 + 0x39b8) <= *(float *)(param_1 + 0x39c4)) {
      return;
    }
  }
  FUN_004f87c0(0x26,2,0x3f800000,0x3f800000);
  return;
}


