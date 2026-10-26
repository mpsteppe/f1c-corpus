// Function: FUN_004ce3e0 @ 004ce3e0
// Size (bytes): 1075


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004ce3e0(int param_1,int param_2,float param_3,float *param_4,float *param_5,undefined4 param_6,
            undefined4 param_7)

{
  int iVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *local_3c;
  int local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  cVar4 = FUN_004b9fb0();
  if ((cVar4 != '\0') && (local_38 = 0, 0 < *(int *)(param_1 + 0x3c))) {
    local_3c = (int *)(param_1 + 0x40);
    do {
      iVar1 = *(int *)(*local_3c + 4);
      uVar7 = param_7;
      if (iVar1 == 0) {
        if ((*(float *)(param_2 + 0x2c) != DAT_0059e440) &&
           (((2 < DAT_007cf8a8 || (DAT_008ab6e4 == 2)) || (DAT_007c5698 % 0x14 == 0)))) {
          fVar2 = *param_4 - *(float *)(param_2 + 0x38);
          fVar3 = param_4[2] - *(float *)(param_2 + 0x40);
          if ((_DAT_0059e868 < ABS(param_3 - *(float *)(param_2 + 0x44))) ||
             (_DAT_0059e43c < fVar2 * fVar2 + fVar3 * fVar3)) {
            *(float *)(param_2 + 0x38) = *param_4;
            *(float *)(param_2 + 0x3c) = param_4[1];
            fVar2 = param_4[2];
            *(float *)(param_2 + 0x44) = param_3;
            *(float *)(param_2 + 0x40) = fVar2;
            uVar5 = DAT_008aae70 + 1;
            local_2c = param_4[1];
            local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7f8 +
                       *param_4;
            DAT_008aae70 = DAT_008aae70 + 2;
            local_28 = *(float *)(&DAT_008ab274 + (uVar5 & 0xff) * 4) * _DAT_0059e7f8 + param_4[2];
            local_24 = *param_5 * _DAT_0059e84c;
            local_20 = param_5[1] * _DAT_0059e84c;
            local_1c = param_5[2] * _DAT_0059e84c;
            if (DAT_007cf9d4 == '\0') {
              if (DAT_007cf9ec == '\0') {
                uVar7 = 0xffffffff;
              }
            }
            else if (DAT_007cf9ec != '\0') {
              uVar7 = 0x68;
            }
            uVar6 = *(undefined4 *)(param_2 + 0x2c);
            local_c = local_24;
            local_8 = local_20;
            local_4 = local_1c;
            goto LAB_004ce7c4;
          }
        }
      }
      else if (iVar1 == 1) {
        if ((*(float *)(param_2 + 0x28) != DAT_0059e440) &&
           (((2 < DAT_007cf8a8 || (DAT_008ab6e4 == 2)) || (DAT_007c5698 % 0x14 == 0)))) {
          fVar2 = *param_4 - *(float *)(param_2 + 0x38);
          fVar3 = param_4[2] - *(float *)(param_2 + 0x40);
          if ((_DAT_0059e868 < ABS(param_3 - *(float *)(param_2 + 0x44))) ||
             (_DAT_0059e43c < fVar2 * fVar2 + fVar3 * fVar3)) {
            *(float *)(param_2 + 0x38) = *param_4;
            *(float *)(param_2 + 0x3c) = param_4[1];
            fVar2 = param_4[2];
            *(float *)(param_2 + 0x44) = param_3;
            *(float *)(param_2 + 0x40) = fVar2;
            uVar5 = DAT_008aae70 + 1;
            local_2c = param_4[1];
            local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7f8 +
                       *param_4;
            DAT_008aae70 = DAT_008aae70 + 2;
            local_28 = *(float *)(&DAT_008ab274 + (uVar5 & 0xff) * 4) * _DAT_0059e7f8 + param_4[2];
            local_24 = *param_5 * _DAT_0059e84c;
            local_20 = param_5[1] * _DAT_0059e84c;
            local_1c = param_5[2] * _DAT_0059e84c;
            local_18 = local_24;
            local_14 = local_20;
            local_10 = local_1c;
            if (DAT_007cf9d4 == '\0') {
              if (DAT_007cf9ec != '\0') goto LAB_004ce654;
              uVar7 = 0xffffffff;
              uVar6 = *(undefined4 *)(param_2 + 0x28);
            }
            else if (DAT_007cf9ec == '\0') {
LAB_004ce654:
              uVar6 = *(undefined4 *)(param_2 + 0x28);
            }
            else {
              uVar6 = *(undefined4 *)(param_2 + 0x28);
              uVar7 = 0x68;
            }
LAB_004ce7c4:
            FUN_004cbc50(param_3,&local_30,&local_24,uVar6,param_6,1,uVar7);
          }
        }
      }
      else if (((iVar1 == 5) && (*(float *)(param_2 + 0x30) != DAT_0059e440)) &&
              ((1 < DAT_007cf8a8 || ((DAT_008ab6e4 == 2 || (DAT_007c5698 % 0x14 == 0)))))) {
        uVar5 = DAT_008aae70 + 1;
        local_2c = param_4[1];
        local_30 = *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4) * _DAT_0059e7f8 + *param_4;
        DAT_008aae70 = DAT_008aae70 + 2;
        local_28 = *(float *)(&DAT_008ab274 + (uVar5 & 0xff) * 4) * _DAT_0059e7f8 + param_4[2];
        FUN_004cb620(param_3,&local_30,param_5,*(undefined4 *)(param_2 + 0x30),param_6,param_7);
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 1;
    } while (local_38 < *(int *)(param_1 + 0x3c));
  }
  return;
}


