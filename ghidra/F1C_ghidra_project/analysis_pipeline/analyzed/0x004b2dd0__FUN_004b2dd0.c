// Function: FUN_004b2dd0 @ 004b2dd0
// Size (bytes): 961


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2dd0(int *param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  double local_34;
  double local_2c;
  double local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_4;
  
  local_70 = (float)(int)*(short *)((int)param_1 + 9) * _DAT_0059e778;
  local_6c = (float)(int)*(short *)((int)param_1 + 0xb) * _DAT_0059e778;
  local_68 = (float)(int)*(short *)((int)param_1 + 0xd) * _DAT_0059e778;
  FUN_004b2480(&local_70);
  local_4c = 0;
  local_48 = 0;
  local_44 = 0.0;
  FUN_004b25d0(&local_4c);
  FUN_004b2750(&local_4c);
  if (((local_70 != DAT_0059e440) || (local_6c != DAT_0059e440)) || (local_68 != DAT_0059e440)) {
    local_1c = 0;
    local_18 = 0x40000000;
    local_14 = 0x40000000;
    local_10 = 0x479e17b8;
    local_4 = 0;
    fVar1 = _DAT_0059e43c / SQRT(local_70 * local_70 + local_68 * local_68 + local_6c * local_6c);
    local_70 = local_70 * fVar1 * _DAT_0059e670;
    local_6c = local_6c * fVar1 * _DAT_0059e670;
    local_68 = local_68 * fVar1 * _DAT_0059e670;
    local_34 = (double)((float)(*param_1 << 8) * _DAT_0059e780);
    local_2c = (double)((float)(int)((*(ushort *)((int)param_1 + 2) & 0xff00) + param_1[1] * 0x10000
                                    ) * _DAT_0059e780);
    local_24 = (double)((float)(int)(((uint)param_1[1] >> 8 & 0xffff00) +
                                    (uint)*(byte *)(param_1 + 2) * 0x1000000) * _DAT_0059e780);
    iVar4 = FUN_0044c550(&local_34,&local_64);
    if (iVar4 == 0) {
      local_60 = 1.0;
      local_64 = 0.0;
      local_5c = 0.0;
    }
    fVar1 = local_68 * local_60 - local_6c * local_5c;
    fVar2 = local_70 * local_5c - local_68 * local_64;
    fVar3 = local_6c * local_64 - local_70 * local_60;
    local_68 = _DAT_0059e43c / SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
    local_70 = fVar1 * local_68;
    local_6c = fVar2 * local_68;
    local_68 = local_68 * fVar3;
    local_58 = local_5c * local_6c - local_68 * local_60;
    local_54 = local_68 * local_64 - local_5c * local_70;
    local_50 = local_60 * local_70 - local_6c * local_64;
    fVar5 = (float10)FUN_00588570();
    local_40 = (float)-fVar5;
    if (ABS(local_54) == (float)_DAT_0059e420) {
      local_38 = 0.0;
      fVar5 = (float10)fpatan(-(float10)local_68,(float10)local_70);
    }
    else {
      fVar5 = (float10)fpatan((float10)local_58,(float10)local_50);
      fVar6 = (float10)fpatan((float10)local_6c,(float10)local_60);
      local_38 = (float)fVar6;
    }
    local_3c = (float)fVar5;
    FUN_004b31a0(&local_40);
  }
  fVar1 = (float)(int)((*(ushort *)((int)param_1 + 2) & 0xff00) + param_1[1] * 0x10000) *
          _DAT_0059e780;
  local_44 = (float)(int)(((uint)param_1[1] >> 8 & 0xffff00) +
                         (uint)*(byte *)(param_1 + 2) * 0x1000000) * _DAT_0059e780;
  *(float *)(param_2 + 8) = (float)(*param_1 << 8) * _DAT_0059e780;
  *(float *)(param_2 + 0x10) = local_44;
  *(float *)(param_2 + 0xc) = fVar1;
  fVar5 = (float10)FUN_004b2bf0();
  FUN_004b29b0((float)fVar5);
  fVar5 = (float10)FUN_004b2c50();
  FUN_004b2930((float)fVar5);
  *(undefined4 *)(param_2 + 4) = param_3;
  return;
}


