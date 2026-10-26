// Function: FUN_004ed420 @ 004ed420
// Size (bytes): 743


void __thiscall
FUN_004ed420(int param_1,undefined4 param_2,float *param_3,float *param_4,float *param_5,int param_6
            )

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  pfVar3 = (float *)FUN_004ea930(&local_18);
  local_3c = *pfVar3;
  local_38 = pfVar3[1];
  local_34 = pfVar3[2];
  local_24 = local_3c * *(float *)(param_1 + 0x34b0) +
             local_38 * *(float *)(param_1 + 0x34bc) + local_34 * *(float *)(param_1 + 0x34c8);
  local_20 = local_3c * *(float *)(param_1 + 0x34b4) +
             local_38 * *(float *)(param_1 + 0x34c0) + local_34 * *(float *)(param_1 + 0x34cc);
  local_1c = local_3c * *(float *)(param_1 + 0x34b8) +
             local_38 * *(float *)(param_1 + 0x34c4) + local_34 * *(float *)(param_1 + 0x34d0);
  local_48 = *param_3 * *(float *)(param_1 + 0x34b0) +
             *(float *)(param_1 + 0x34bc) * param_3[1] + *(float *)(param_1 + 0x34c8) * param_3[2];
  local_44 = *(float *)(param_1 + 0x34b4) * *param_3 +
             *(float *)(param_1 + 0x34c0) * param_3[1] + *(float *)(param_1 + 0x34cc) * param_3[2];
  local_40 = *(float *)(param_1 + 0x34b8) * *param_3 +
             *(float *)(param_1 + 0x34c4) * param_3[1] + *(float *)(param_1 + 0x34d0) * param_3[2];
  puVar4 = (undefined4 *)FUN_004ed750(&local_18);
  local_30 = (float)*puVar4;
  local_2c = (float)puVar4[1];
  local_28 = (float)puVar4[2];
  pfVar3 = (float *)FUN_004ed710(local_c);
  local_3c = *pfVar3;
  local_38 = pfVar3[1];
  local_34 = pfVar3[2];
  iVar5 = 0;
  piVar6 = (int *)(param_1 + 0x828);
  pfVar3 = (float *)(param_1 + 0x3594);
  while( true ) {
    local_2c = local_20 - pfVar3[-1];
    local_28 = local_1c - *pfVar3;
    if ((((local_24 - pfVar3[-2]) * (local_24 - pfVar3[-2]) +
          local_2c * local_2c + local_28 * local_28 < pfVar3[0x1f] * pfVar3[0x1f]) && (*piVar6 != 0)
        ) && ((char)piVar6[0x10] != '\0')) break;
    iVar5 = iVar5 + 1;
    pfVar3 = pfVar3 + 0x3e;
    piVar6 = piVar6 + 0x4a;
    if (3 < iVar5) {
LAB_004ed656:
      *param_4 = local_3c * local_48 + local_38 * local_44 + local_34 * local_40;
      fVar7 = (float10)FUN_004ed380(&local_24,&local_48);
      *param_5 = (float)fVar7;
      if (param_6 != 0) {
        fVar1 = *param_4;
        local_30 = local_3c - local_48 * fVar1;
        local_2c = local_38 - local_44 * fVar1;
        local_28 = local_34 - local_40 * fVar1;
        local_18 = local_30;
        local_14 = local_2c;
        local_10 = local_28;
        FUN_004ed7b0(&local_18,param_6);
      }
      return;
    }
  }
  local_14 = -(local_28 * *(float *)(iVar5 * 0xf8 + 0x35b0 + param_1));
  fVar2 = local_2c * *(float *)(iVar5 * 0xf8 + 0x35b0 + param_1);
  fVar1 = local_48 * DAT_0059e440 + local_44 * local_14 + local_40 * fVar2;
  local_2c = local_44 * fVar1;
  local_28 = local_40 * fVar1;
  local_18 = -(local_48 * fVar1);
  local_14 = local_14 - local_2c;
  local_3c = local_3c + local_18;
  local_38 = local_38 + local_14;
  local_34 = local_34 + (fVar2 - local_28);
  goto LAB_004ed656;
}


