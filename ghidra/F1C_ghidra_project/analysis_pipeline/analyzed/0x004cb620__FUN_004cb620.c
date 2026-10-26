// Function: FUN_004cb620 @ 004cb620
// Size (bytes): 575


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004cb620(int param_1,float param_2,float *param_3,float *param_4,float param_5,
            undefined4 param_6,undefined4 param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  double local_34;
  double local_2c;
  double local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  double local_c;
  undefined4 local_4;
  
  fVar4 = SQRT(param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4);
  if ((_DAT_0059e43c <= fVar4) && (0 < *(int *)(param_1 + 0x58))) {
    puVar5 = (undefined4 *)FUN_004cb540();
    puVar5[2] = param_2;
    puVar5[3] = param_2 + (float)puVar5[7];
    uVar7 = DAT_008aae70 & 0xff;
    DAT_008aae70 = DAT_008aae70 + 1;
    param_5 = (*(float *)(&DAT_008aae74 + uVar7 * 4) * _DAT_0059e708 + _DAT_005acea8) * param_5;
    puVar5[10] = param_5;
    if (fVar4 < *(float *)(param_1 + 0x48)) {
      puVar5[10] = (fVar4 / *(float *)(param_1 + 0x48)) * param_5;
    }
    puVar5[0x11] = param_7;
    fVar1 = *(float *)(param_1 + 0x4c) / fVar4;
    local_1c = 0;
    local_18 = 0x3fd00000;
    local_14 = 0x40000000;
    local_10 = 0x479e17b8;
    local_4 = param_6;
    fVar2 = *param_4 * fVar1 + *param_3;
    fVar3 = param_4[1] * fVar1 + param_3[1];
    fVar1 = param_4[2] * fVar1 + param_3[2];
    local_34 = (double)fVar2;
    local_2c = (double)fVar3;
    local_24 = (double)fVar1;
    iVar6 = FUN_0044c550(&local_34,puVar5 + 0x15);
    if (iVar6 == 0) {
      puVar5[0x15] = 0;
      fVar3 = fVar3 - _DAT_0059e7f8;
      puVar5[0x16] = 0x3f800000;
      puVar5[0x17] = 0;
    }
    else {
      fVar3 = (float)local_c;
    }
    puVar5[0xb] = fVar2;
    puVar5[0xc] = fVar3;
    puVar5[0xd] = fVar1;
    fVar2 = param_4[1] * _DAT_0059e84c;
    fVar1 = param_4[2];
    puVar5[0xe] = *param_4 * _DAT_0059e84c;
    fVar1 = fVar1 * _DAT_0059e84c;
    puVar5[0xf] = fVar2;
    puVar5[0x1a] = fVar4;
    puVar5[0x10] = fVar1;
    FUN_00558c60(*puVar5,puVar5[0xb],puVar5[0xc],puVar5[0xd]);
    FUN_00558cb0(*puVar5,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
                 *(undefined4 *)(param_1 + 0x14));
    FUN_00558cf0(*puVar5,0xffffff);
  }
  return;
}


