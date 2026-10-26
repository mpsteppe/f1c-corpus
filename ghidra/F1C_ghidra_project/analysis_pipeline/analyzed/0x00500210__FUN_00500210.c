// Function: FUN_00500210 @ 00500210
// Size (bytes): 844


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00500210(int param_1,float param_2,float param_3)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  float local_c;
  float local_8;
  float local_4;
  
  iVar5 = (int)param_3;
  uVar1 = *(uint *)(param_1 + 0x1b8);
  uVar8 = uVar1 >> 0x12 & 0x3f;
  if (uVar8 != 0) {
    FUN_004b33b0(uVar1 >> 0x1d,uVar8,uVar1 >> 8 & 0x3ff,uVar1 & 0xff,param_2,0);
    fVar2 = *(float *)(param_1 + 0xc) - *(float *)(param_1 + 0x1bc);
    if (fVar2 == DAT_0059e440) {
      param_2 = 0.0;
      param_3 = 1.0;
    }
    else {
      param_2 = (param_2 - *(float *)(param_1 + 0x1bc)) / fVar2;
      param_3 = _DAT_0059e43c - param_2;
    }
    local_c = (float)(*(int *)(param_1 + 0x1c2) << 8) * _DAT_0059e780 * param_3 +
              (float)(*(int *)(param_1 + 0x12) << 8) * _DAT_0059e780 * param_2;
    local_8 = (float)(int)((*(ushort *)(param_1 + 0x1c4) & 0xff00) +
                          *(int *)(param_1 + 0x1c6) * 0x10000) * _DAT_0059e780 * param_3 +
              (float)(int)((*(ushort *)(param_1 + 0x14) & 0xff00) +
                          *(int *)(param_1 + 0x16) * 0x10000) * _DAT_0059e780 * param_2;
    local_4 = (float)(int)((*(uint *)(param_1 + 0x1c6) >> 8 & 0xffff00) +
                          (uint)*(byte *)(param_1 + 0x1ca) * 0x1000000) * _DAT_0059e780 * param_3 +
              (float)(int)((*(uint *)(param_1 + 0x16) >> 8 & 0xffff00) +
                          (uint)*(byte *)(param_1 + 0x1a) * 0x1000000) * _DAT_0059e780 * param_2;
    FUN_004b21f0(&local_c);
    fVar2 = (float)(int)*(short *)(param_1 + 0x1b) * _DAT_0059e77c * param_2 +
            (float)(int)*(short *)(param_1 + 0x1cb) * _DAT_0059e77c * param_3;
    fVar3 = (float)(int)*(short *)(param_1 + 0x1d) * _DAT_0059e77c * param_2 +
            (float)(int)*(short *)(param_1 + 0x1cd) * _DAT_0059e77c * param_3;
    fVar4 = (float)(int)*(short *)(param_1 + 0x1f) * _DAT_0059e77c * param_2 +
            (float)(int)*(short *)(param_1 + 0x1cf) * _DAT_0059e77c * param_3;
    if (fVar2 <= _DAT_0059e71c) {
      if (_DAT_0059e718 <= fVar2) {
        param_3._0_2_ = (short)(int)ROUND(fVar2 * _DAT_0059e714);
      }
      else {
        param_3._0_2_ = 0x8001;
      }
    }
    else {
      param_3._0_2_ = 0x7fff;
    }
    *(short *)(iVar5 + 0x13) = param_3._0_2_;
    if (fVar3 <= _DAT_0059e71c) {
      if (_DAT_0059e718 <= fVar3) {
        param_3._0_2_ = (short)(int)ROUND(fVar3 * _DAT_0059e714);
      }
      else {
        param_3._0_2_ = 0x8001;
      }
    }
    else {
      param_3._0_2_ = 0x7fff;
    }
    *(short *)(iVar5 + 0x15) = param_3._0_2_;
    if (fVar4 <= _DAT_0059e71c) {
      if (_DAT_0059e718 <= fVar4) {
        param_3._0_2_ = (short)(int)ROUND(fVar4 * _DAT_0059e714);
        iVar6 = (int)param_3._0_2_;
      }
      else {
        iVar6 = -0x7fff;
      }
    }
    else {
      iVar6 = 0x7fff;
    }
    *(short *)(iVar5 + 0x17) = (short)iVar6;
    *(undefined2 *)(iVar5 + 8) = *(undefined2 *)(param_1 + 0x1c0);
    return CONCAT31((int3)((uint)iVar6 >> 8),1);
  }
  uVar7 = FUN_004ff8f0(param_2,param_1 + 0x1b8,param_1 + 8,param_3);
  return uVar7;
}


