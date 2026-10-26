// Function: FUN_004ce930 @ 004ce930
// Size (bytes): 1369


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_004ce930(int param_1,float *param_2,float param_3,float *param_4,float *param_5,
            undefined4 param_6)

{
  float fVar1;
  int iVar2;
  undefined4 in_EAX;
  undefined2 uVar5;
  uint uVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar4;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_4;
  
  if (DAT_007cf9bc == '\0') {
    if (DAT_007cf9ec == '\0') {
      param_6 = 0xffffffff;
    }
  }
  else if (DAT_007cf9ec != '\0') {
    param_6 = 0x68;
  }
  uVar5 = (undefined2)((uint)in_EAX >> 0x10);
  if (((*param_2 != DAT_0059e440) && (uVar5 = 0, *(int *)(param_1 + 0x20) != 0)) &&
     ((uVar5 = 0, 2 < DAT_007cf8a8 ||
      ((DAT_008ab6e4 == 2 ||
       (uVar5 = (undefined2)((uint)(DAT_007c5698 / 0x14) >> 0x10), DAT_007c5698 % 0x14 == 0)))))) {
    if ((_DAT_0059e868 < ABS(param_3 - param_2[1])) ||
       (_DAT_0059e43c <
        (*param_4 - param_2[2]) * (*param_4 - param_2[2]) +
        (param_4[2] - param_2[4]) * (param_4[2] - param_2[4]))) {
      param_2[2] = *param_4;
      param_2[3] = param_4[1];
      fVar1 = param_4[2];
      param_2[1] = param_3;
      param_2[4] = fVar1;
      uVar3 = DAT_008aae70 + 1;
      local_2c = param_4[1];
      local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7f8 + *param_4;
      DAT_008aae70 = DAT_008aae70 + 2;
      local_28 = *(float *)(&DAT_008ab274 + (uVar3 & 0xff) * 4) * _DAT_0059e7f8 + param_4[2];
      local_24 = *param_5 * _DAT_0059e84c;
      local_14 = param_5[1] * _DAT_0059e84c;
      local_1c = param_5[2] * _DAT_0059e84c;
      local_20 = local_14 + _DAT_0059e7f8;
      local_18 = local_24;
      local_10 = local_1c;
      FUN_004cbc50(param_3,&local_30,&local_24,*param_2,0,0,param_6);
      uVar5 = extraout_var;
    }
  }
  if (((param_2[5] != DAT_0059e440) && (uVar5 = 0, *(int *)(param_1 + 0x24) != 0)) &&
     ((uVar5 = 0, 2 < DAT_007cf8a8 ||
      ((DAT_008ab6e4 == 2 ||
       (uVar5 = (undefined2)((uint)(DAT_007c5698 / 0x14) >> 0x10), DAT_007c5698 % 0x14 == 0)))))) {
    if ((_DAT_0059e868 < ABS(param_3 - param_2[6])) ||
       (_DAT_0059e43c <
        (*param_4 - param_2[7]) * (*param_4 - param_2[7]) +
        (param_4[2] - param_2[9]) * (param_4[2] - param_2[9]))) {
      param_2[7] = *param_4;
      param_2[8] = param_4[1];
      fVar1 = param_4[2];
      param_2[6] = param_3;
      param_2[9] = fVar1;
      uVar3 = DAT_008aae70 + 1;
      local_2c = param_4[1];
      local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7f8 + *param_4;
      DAT_008aae70 = DAT_008aae70 + 2;
      local_28 = *(float *)(&DAT_008ab274 + (uVar3 & 0xff) * 4) * _DAT_0059e7f8 + param_4[2];
      local_24 = *param_5 * _DAT_0059e84c;
      local_14 = param_5[1] * _DAT_0059e84c;
      local_1c = param_5[2] * _DAT_0059e84c;
      local_20 = local_14 + _DAT_0059e7f8;
      local_18 = local_24;
      local_10 = local_1c;
      FUN_004cbc50(param_3,&local_30,&local_24,param_2[5],0,0,param_6);
      uVar5 = extraout_var_00;
    }
  }
  fVar1 = param_2[10];
  iVar4 = CONCAT22(uVar5,(ushort)(fVar1 < DAT_0059e440) << 8 |
                         (ushort)(NAN(fVar1) || NAN(DAT_0059e440)) << 10 |
                         (ushort)(fVar1 == DAT_0059e440) << 0xe);
  if (fVar1 != DAT_0059e440) {
    iVar2 = *(int *)(param_1 + 0x28);
    iVar4 = 0;
    if ((iVar2 != 0) &&
       (((iVar4 = iVar2, 1 < DAT_007cf8a8 || (DAT_008ab6e4 == 2)) ||
        (iVar4 = DAT_007c5698 / 0x14, DAT_007c5698 % 0x14 == 0)))) {
      if (ABS(param_3 - param_2[0xb]) <= _DAT_0059e454) {
        fVar1 = (*param_4 - param_2[0xc]) * (*param_4 - param_2[0xc]) +
                (param_4[2] - param_2[0xe]) * (param_4[2] - param_2[0xe]);
        if (fVar1 < _DAT_005aced0 || (fVar1 == _DAT_005aced0) != 0) {
          return CONCAT22((short)((uint)iVar4 >> 0x10),
                          (ushort)(fVar1 < _DAT_005aced0) << 8 |
                          (ushort)(NAN(fVar1) || NAN(_DAT_005aced0)) << 10 |
                          (ushort)(fVar1 == _DAT_005aced0) << 0xe);
        }
      }
      param_2[0xc] = *param_4;
      param_2[0xd] = param_4[1];
      fVar1 = param_4[2];
      param_2[0xb] = param_3;
      param_2[0xe] = fVar1;
      uVar3 = DAT_008aae70 + 1;
      local_2c = param_4[1];
      local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e868 + *param_4;
      DAT_008aae70 = DAT_008aae70 + 2;
      local_28 = *(float *)(&DAT_008ab274 + (uVar3 & 0xff) * 4) * _DAT_0059e868 + param_4[2];
      local_24 = *param_5 * _DAT_0059e84c;
      local_14 = param_5[1] * _DAT_0059e84c;
      local_1c = param_5[2] * _DAT_0059e84c;
      local_20 = local_14 + _DAT_0059e7f8;
      local_18 = local_24;
      local_10 = local_1c;
      iVar4 = FUN_004cbc50(param_3,&local_30,&local_24,param_2[10],0,0,param_6);
      if (2 < DAT_007cf8a8) {
        local_4 = param_5[2] * _DAT_005acecc;
        local_18 = *param_4 - *param_5 * _DAT_005acecc;
        local_2c = param_4[1] - param_5[1] * _DAT_005acecc;
        local_10 = param_4[2] - local_4;
        uVar3 = DAT_008aae70 + 1;
        local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e868 + local_18;
        DAT_008aae70 = DAT_008aae70 + 2;
        local_28 = *(float *)(&DAT_008ab274 + (uVar3 & 0xff) * 4) * _DAT_0059e868 + local_10;
        local_14 = local_2c;
        iVar4 = FUN_004cbc50(param_3 - _DAT_005acecc,&local_30,&local_24,param_2[10],0,0,param_6);
      }
    }
  }
  return iVar4;
}


