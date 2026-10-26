// Function: FUN_004cce90 @ 004cce90
// Size (bytes): 912


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004cce90(int param_1,float *param_2,int param_3,float *param_4,int param_5,undefined4 param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_48;
  float local_44;
  double local_40;
  double local_38;
  double local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  double local_18;
  undefined4 local_10;
  float local_4;
  
  if (0 < *(int *)(param_1 + 0x58)) {
    fVar5 = _DAT_0059e774 * (float)param_5;
    fVar6 = (float)param_5 * _DAT_0059e778;
    fVar2 = *param_4 * _DAT_0059e450;
    fVar3 = param_4[1] * _DAT_0059e450;
    fVar4 = param_4[2] * _DAT_0059e450;
    if (DAT_008ab6e4 == 2) {
      iVar7 = FUN_004b9e30();
      if (iVar7 == 5) {
        fVar9 = (float10)DAT_0059e440;
      }
      else {
        fVar9 = (float10)FUN_004b9cf0();
      }
    }
    else {
      fVar9 = (float10)_DAT_008afe98;
    }
    local_70 = (float)((float10)fVar2 * fVar9);
    local_28 = 0;
    local_24 = 0x3fd00000;
    local_6c = (float)((float10)fVar3 * fVar9);
    local_20 = 0x40000000;
    local_1c = 0x479e17b8;
    local_10 = param_6;
    local_68 = (float)((float10)fVar4 * fVar9);
    local_40 = (double)*param_2;
    local_38 = (double)param_2[1];
    local_30 = (double)param_2[2];
    iVar7 = FUN_0044c550(&local_40,&local_80);
    if (iVar7 == 0) {
      local_80 = 0.0;
      local_7c = 1.0;
      local_78 = 0.0;
      local_74 = -3.4028235e+38;
    }
    else {
      local_74 = local_78 * param_2[2] + local_80 * *param_2 + (float)local_18 * local_7c;
    }
    iVar7 = FUN_0040c870();
    fVar2 = *(float *)(iVar7 + 0x24);
    fVar3 = *(float *)(iVar7 + 0x28);
    fVar4 = *(float *)(iVar7 + 0x2c);
    if (DAT_008ab6e4 == 2) {
      fVar9 = (float10)FUN_004b9ce0();
    }
    else {
      fVar9 = (float10)_DAT_008afea0;
    }
    param_3 = param_3 >> ((byte)*(undefined4 *)(param_1 + 8) & 0x1f);
    if (0 < param_3) {
      do {
        iVar7 = FUN_004cb540();
        *(float *)(iVar7 + 8) = (float)fVar9;
        *(float *)(iVar7 + 0xc) = (float)fVar9 + *(float *)(iVar7 + 0x10);
        fVar1 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4);
        uVar8 = DAT_008aae70 + 1;
        local_48 = fVar1 * local_6c;
        DAT_008aae70 = DAT_008aae70 + 2;
        local_44 = fVar1 * local_68;
        *(float *)(iVar7 + 0x2c) =
             *(float *)(&DAT_008ab274 + (uVar8 & 0xff) * 4) * fVar5 + *param_2 + local_70 * fVar1;
        uVar8 = DAT_008aae70 & 0xff;
        DAT_008aae70 = DAT_008aae70 + 1;
        *(float *)(iVar7 + 0x30) =
             *(float *)(&DAT_008ab274 + uVar8 * 4) * fVar5 + param_2[1] + local_48;
        uVar8 = DAT_008aae70 & 0xff;
        DAT_008aae70 = DAT_008aae70 + 1;
        *(float *)(iVar7 + 0x34) =
             *(float *)(&DAT_008ab274 + uVar8 * 4) * fVar5 + param_2[2] + local_44;
        uVar8 = DAT_008aae70 & 0xff;
        DAT_008aae70 = DAT_008aae70 + 1;
        *(float *)(iVar7 + 0x38) = *(float *)(&DAT_008ab274 + uVar8 * 4) * fVar6 + *param_4;
        uVar8 = DAT_008aae70 & 0xff;
        DAT_008aae70 = DAT_008aae70 + 1;
        *(float *)(iVar7 + 0x3c) = *(float *)(&DAT_008ab274 + uVar8 * 4) * fVar6 + param_4[1];
        uVar8 = DAT_008aae70 & 0xff;
        DAT_008aae70 = DAT_008aae70 + 1;
        *(float *)(iVar7 + 0x40) = *(float *)(&DAT_008ab274 + uVar8 * 4) * fVar6 + param_4[2];
        *(float *)(iVar7 + 0x54) = local_80;
        *(float *)(iVar7 + 0x58) = local_7c;
        *(float *)(iVar7 + 0x5c) = local_78;
        *(float *)(iVar7 + 100) = local_74;
        local_4 = *(float *)(iVar7 + 0x40) - fVar4;
        local_64 = (*(float *)(iVar7 + 0x38) - fVar2) * _DAT_0059ed18;
        local_60 = (*(float *)(iVar7 + 0x3c) - fVar3) * _DAT_0059ed18;
        local_5c = local_4 * _DAT_0059ed18;
        local_58 = local_64;
        local_54 = local_60;
        local_50 = local_5c;
        FUN_004cc500(iVar7,&local_58);
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  return;
}


