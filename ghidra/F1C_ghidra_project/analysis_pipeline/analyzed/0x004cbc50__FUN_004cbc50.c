// Function: FUN_004cbc50 @ 004cbc50
// Size (bytes): 378


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004cbc50(int param_1,float param_2,float *param_3,undefined4 *param_4,float param_5,
            undefined4 param_6,char param_7,undefined4 param_8)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  double local_34;
  double local_2c;
  double local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  double local_c;
  undefined4 local_4;
  
  if (0 < *(int *)(param_1 + 0x58)) {
    puVar2 = (undefined4 *)FUN_004cb540();
    puVar2[2] = param_2;
    puVar2[3] = param_2 + (float)puVar2[7];
    puVar2[0xb] = *param_3;
    puVar2[0xc] = param_3[1];
    puVar2[0xd] = param_3[2];
    puVar2[0xe] = *param_4;
    puVar2[0xf] = param_4[1];
    puVar2[0x10] = param_4[2];
    uVar4 = DAT_008aae70 & 0xff;
    DAT_008aae70 = DAT_008aae70 + 1;
    fVar1 = *(float *)(&DAT_008aae74 + uVar4 * 4) * _DAT_0059e708;
    puVar2[0x11] = param_8;
    puVar2[10] = (fVar1 + _DAT_005acea8) * param_5;
    local_1c = 0;
    local_34 = (double)*param_3;
    local_18 = 0x3fd00000;
    local_2c = (double)param_3[1];
    local_14 = 0x40000000;
    local_24 = (double)param_3[2];
    local_10 = 0x479e17b8;
    local_4 = param_6;
    iVar3 = FUN_0044c550(&local_34,puVar2 + 0x15);
    if (iVar3 == 0) {
      puVar2[0x15] = 0;
      puVar2[0x16] = 0x3f800000;
      puVar2[0x17] = 0;
      fVar1 = param_3[1] - _DAT_0059e7f8;
    }
    else {
      fVar1 = (float)local_c;
    }
    if (param_7 != '\0') {
      puVar2[0xc] = *(float *)(param_1 + 0x10) * _DAT_0059e450 + fVar1;
      puVar2[0xf] = (float)puVar2[0x1a] * *(float *)(param_1 + 0x1c) * _DAT_0059e450;
    }
    FUN_00558c60(*puVar2,puVar2[0xb],puVar2[0xc],puVar2[0xd]);
    FUN_00558cb0(*puVar2,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
                 *(undefined4 *)(param_1 + 0x14));
    FUN_00558cf0(*puVar2,0xffffff);
  }
  return;
}


