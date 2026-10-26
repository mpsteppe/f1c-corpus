// Function: FUN_0055eba0 @ 0055eba0
// Size (bytes): 366


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0055eba0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_2c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float local_c;
  float fStack_8;
  float fStack_4;
  
  iVar5 = param_2;
  iVar8 = 0;
  if (param_2 != 0) {
    iVar7 = *(int *)(param_1 + 0xc);
    if ((*(uint *)(*(int *)(param_1 + 0x18) + 0x14) & 0x800000) == 0) {
      param_2 = iVar7 + 0xc;
      iVar6 = 0xc;
    }
    else {
      param_2 = iVar7 + 0x1c;
      iVar6 = 0x10;
    }
    local_2c = 0;
    if (0 < *(int *)(param_1 + 8)) {
      do {
        (**(code **)(*DAT_008b8f24 + 4))
                  (DAT_008b8f24,iVar7,&local_c,*(int *)(*(int *)(param_1 + 0x18) + 0x138) + 0x1a0);
        (**(code **)*DAT_008b8f24)
                  (DAT_008b8f24,param_2,&fStack_18,
                   *(int *)(*(int *)(param_1 + 0x18) + 0x138) + 0x114);
        fVar1 = local_c + *(float *)(iVar5 + 0x24);
        fVar4 = fStack_8 + *(float *)(iVar5 + 0x28);
        fVar3 = fStack_4 + *(float *)(iVar5 + 0x2c);
        fVar2 = _DAT_0059e43c / SQRT(fVar1 * fVar1 + fVar4 * fVar4 + fVar3 * fVar3);
        fVar3 = fStack_18 * fVar2 * fVar1 + fStack_14 * fVar2 * fVar4 + fVar2 * fVar3 * fStack_10;
        fVar3 = fVar3 + fVar3;
        *(float *)(*(int *)(param_1 + 0x20) + 0x28 + iVar8) =
             (fStack_18 * fVar3 - fVar2 * fVar1) * _DAT_0059e450 + _DAT_0059e450;
        param_2 = param_2 + iVar6 * 4;
        *(float *)(*(int *)(param_1 + 0x20) + 0x2c + iVar8) =
             (fStack_14 * fVar3 - fVar2 * fVar4) * _DAT_0059e450 + _DAT_0059e450;
        iVar7 = iVar7 + iVar6 * 4;
        local_2c = local_2c + 1;
        iVar8 = iVar8 + 0x40;
      } while (local_2c < *(int *)(param_1 + 8));
    }
  }
  return;
}


