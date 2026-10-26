// Function: FUN_004a6340 @ 004a6340
// Size (bytes): 1392


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004a6340(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  float local_54;
  float local_50;
  float afStack_48 [4];
  float local_38;
  undefined1 local_34;
  float afStack_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  iVar3 = *param_1;
  local_54 = 0.0;
  if (param_1[0xb] == 0) {
    local_38 = DAT_0059e440;
    if (*(int *)(iVar3 + 13000) == 0) {
      fVar1 = (((float)param_1[99] + _DAT_0059e8a0) - (float)_DAT_008afea0) * _DAT_0059e450;
      if ((DAT_0059e440 <= fVar1) && (local_38 = fVar1, _DAT_005acb5c < fVar1)) {
        local_38 = _DAT_005acb5c;
      }
      iVar7 = *(int *)(iVar3 + 0x403c);
      if (*(int *)(iVar3 + 0x4040) == 2) {
        iVar7 = iVar7 + 1;
      }
      iVar3 = param_1[0x58];
      iVar5 = 0;
      if (0 < iVar3) {
        piVar4 = param_1 + 0x59;
LAB_004a6440:
        iVar2 = *piVar4;
        if (iVar2 < 0) goto code_r0x004a6446;
        if (((iVar7 <= iVar2 + 1) && (iVar7 < iVar2 + -1)) && (iVar7 = iVar5 + 1, iVar7 < iVar3)) {
          piVar4 = param_1 + iVar7 * 2 + 0x59;
          do {
            *piVar4 = -0x80000000;
            iVar7 = iVar7 + 1;
            piVar4 = piVar4 + 2;
          } while (iVar7 < param_1[0x58]);
        }
        param_1[iVar5 * 2 + 0x59] = -0x80000000;
      }
    }
LAB_004a648f:
    local_20 = 0x40b00000;
    local_1c = 0x3f800000;
    local_10 = 0x3f800000;
    local_8 = 0x3f000000;
    local_4 = 0.0;
    param_1[0x6c] = *(int *)(*param_1 + 0x3984);
    fVar1 = (float)param_1[0x1b] * (float)*(double *)(param_1 + 0x18) +
            (float)*(double *)(param_1 + 0x16);
    param_1[0x6e] = (int)fVar1;
    if (fVar1 <= (float)param_1[0x6c]) {
      if (DAT_007c56a4 != 7) {
        FUN_004f1890(fVar1);
      }
      local_18 = 0;
    }
    else {
      param_1[0x70] = 1;
      uVar6 = DAT_008aae70 & 0xff;
      local_c = ((float)param_1[0x6e] - (float)param_1[0x6c]) * _DAT_005acb58;
      DAT_008aae70 = DAT_008aae70 + 1;
      local_14 = *(float *)(&DAT_008aae74 + uVar6 * 4) + *(float *)(&DAT_008aae74 + uVar6 * 4);
      fVar1 = local_14 + local_c + local_38 + _DAT_0059e8a4;
      if (DAT_0059e440 < fVar1) {
        local_54 = fVar1;
      }
      local_18 = 1;
      param_1[0x6d] = (int)(local_14 + (float)param_1[0x68] + local_38 + _DAT_0059e43c);
    }
    if (param_1[0x2b] == 0) {
      local_34 = 0;
    }
    else {
      local_50 = 0.0;
      iVar3 = 0;
      do {
        fVar1 = *(float *)(&DAT_008aae74 + (DAT_008aae70 & 0xff) * 4);
        DAT_008aae70 = DAT_008aae70 + 1;
        fVar1 = fVar1 * fVar1 * fVar1;
        fVar1 = fVar1 + fVar1;
        *(float *)((int)afStack_48 + iVar3) = fVar1;
        if (local_50 < fVar1) {
          local_50 = fVar1;
        }
        *(float *)((int)afStack_30 + iVar3) = fVar1;
        iVar3 = iVar3 + 4;
      } while (iVar3 < 0x10);
      fVar1 = local_50 + local_38 + _DAT_0059e960;
      if (local_54 < fVar1) {
        local_54 = fVar1;
      }
      param_1[0x71] = 1;
      local_34 = 1;
      iVar3 = FUN_004a5820(param_1[0x2b]);
      iVar7 = 0;
      if (0 < *(int *)(param_1[0x56] + 0x10)) {
        do {
          iVar5 = FUN_004d7570(iVar7);
          if (iVar3 == iVar5) {
            FUN_004f1a60(iVar7,1);
            break;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(param_1[0x56] + 0x10));
      }
      param_1[0x74] = param_1[0x68];
      param_1[0x75] = (int)(local_50 + (float)param_1[0x68] + local_38 + _DAT_0059e918);
    }
    if (param_1[0x3b] != param_1[0x3c]) {
      param_1[0x72] = 1;
      if (local_54 < local_38 + _DAT_0059e4dc) {
        local_54 = local_38 + _DAT_0059e4dc;
      }
      if (local_4 < _DAT_0059e4dc) {
        local_4 = 8.0;
      }
      param_1[0x3c] = param_1[0x3b];
      FUN_004f1860(0x1b,(double)param_1[0x3b] * *(double *)(param_1 + 0x38) +
                        *(double *)(param_1 + 0x36));
    }
    if (param_1[0x4b] != 0) {
      param_1[0x73] = 1;
      if (DAT_0083ee60 < 0x3ff) {
        DAT_0083ee60 = DAT_0083ee60 + 1;
        DAT_008aae64 = DAT_008aae64 + 0x1b0;
      }
      FUN_004b33b0(6,0,0,param_1[1],(float)_DAT_008afea0,0);
      iVar3 = *param_1;
      fVar1 = local_38 + _DAT_0059e994;
      if (((*(int *)(iVar3 + 0xcd4) != 0) && (*(char *)(iVar3 + 0xd14) == '\0')) &&
         (fVar1 <= local_38 + _DAT_0059e4dc)) {
        fVar1 = local_38 + _DAT_0059e4dc;
      }
      if (((*(int *)(iVar3 + 0xd18) != 0) && (*(char *)(iVar3 + 0xd58) == '\0')) &&
         (fVar1 <= local_38 + _DAT_005acb54)) {
        fVar1 = local_38 + _DAT_005acb54;
      }
      uVar6 = DAT_008aae70 & 0xff;
      DAT_008aae70 = DAT_008aae70 + 1;
      fVar1 = *(float *)(&DAT_008aae74 + uVar6 * 4) + fVar1;
      if (local_54 < fVar1) {
        local_54 = fVar1;
      }
      if (local_4 < fVar1 - local_38) {
        local_4 = fVar1 - local_38;
      }
    }
    if (param_1[2] != 0) {
      FUN_004a35f0();
      FUN_004a3560();
      FUN_004a34a0();
      if ((0 < DAT_007cf884) && (*(char *)(*param_1 + 0x105c) != '\0')) {
        *(undefined1 *)(*param_1 + 0x105c) = 0;
        FUN_004e0ed0();
      }
    }
  }
  else {
    iVar3 = FUN_004bbf20();
    local_54 = (float)iVar3;
    param_1[0x6f] = 1;
    if (param_1[2] != 0) {
      FUN_004a3820();
      FUN_004a3560();
    }
  }
  if ((*(int *)(*param_1 + 13000) == 1) && (iVar3 = FUN_0042aee0(), iVar3 != 0)) {
    return (float10)DAT_0059e440;
  }
  return (float10)local_54;
code_r0x004a6446:
  iVar5 = iVar5 + 1;
  piVar4 = piVar4 + 2;
  if (iVar3 <= iVar5) goto LAB_004a648f;
  goto LAB_004a6440;
}


