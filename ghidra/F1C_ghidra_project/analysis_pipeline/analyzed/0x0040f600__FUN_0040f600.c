// Function: FUN_0040f600 @ 0040f600
// Size (bytes): 1252


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040f600(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined2 local_28;
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  cVar4 = *(char *)(param_1 + 10);
  *(undefined1 *)(param_1 + 10) = 0;
  iVar5 = DAT_008aae64;
  if (DAT_0083ee60 < 0x3ff) {
    DAT_0083ee60 = DAT_0083ee60 + 1;
    DAT_008aae64 = DAT_008aae64 + 0x1b0;
  }
  iVar6 = local_24;
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
    uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24);
    uVar11 = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894);
    uVar10 = 1;
    break;
  case 1:
    uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24);
    uVar11 = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894);
    uVar10 = 2;
    break;
  case 2:
    uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24);
    uVar11 = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894);
    uVar10 = 3;
    break;
  case 3:
    uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24);
    uVar11 = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894);
    uVar10 = 4;
    break;
  case 4:
    uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24);
    uVar11 = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894);
    uVar10 = 5;
    break;
  case 5:
    uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24);
    uVar11 = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894);
    uVar10 = 6;
    break;
  default:
    goto switchD_0040f65f_default;
  }
  FUN_004b33b0(1,uVar10,0x1d,uVar11,uVar12,(cVar4 != '\0') - 1U & 2);
  iVar6 = *(int *)(param_1 + 0x20) + 0xd4;
switchD_0040f65f_default:
  *(undefined2 *)(iVar5 + 8) = *(undefined2 *)(param_1 + 8);
  local_20 = (float)*(double *)(iVar6 + 4);
  local_1c = (float)*(double *)(iVar6 + 0xc);
  local_18 = (float)*(double *)(iVar6 + 0x14);
  FUN_004b21f0(&local_20);
  fVar7 = (float10)FUN_00588570();
  if (ABS(*(double *)(iVar6 + 0x44)) == _DAT_0059e420) {
    fVar8 = (float10)fpatan(-(float10)*(double *)(iVar6 + 0x4c),(float10)*(double *)(iVar6 + 0x1c));
    fVar9 = (float10)_DAT_0059e430;
  }
  else {
    fVar8 = (float10)fpatan((float10)*(double *)(iVar6 + 0x2c),(float10)*(double *)(iVar6 + 0x5c));
    fVar9 = (float10)fpatan((float10)*(double *)(iVar6 + 0x34),(float10)*(double *)(iVar6 + 0x3c));
  }
  fVar1 = (float)-fVar7;
  fVar2 = (float)fVar8;
  fVar3 = (float)fVar9;
  if (fVar1 <= _DAT_0059e71c) {
    if (_DAT_0059e718 <= fVar1) {
      local_24._0_2_ = (undefined2)(int)ROUND(fVar1 * _DAT_0059e714);
    }
    else {
      local_24._0_2_ = 0x8001;
    }
  }
  else {
    local_24._0_2_ = 0x7fff;
  }
  *(undefined2 *)(iVar5 + 0x13) = (undefined2)local_24;
  if (fVar2 <= _DAT_0059e71c) {
    if (_DAT_0059e718 <= fVar2) {
      local_28 = (undefined2)(int)ROUND(fVar2 * _DAT_0059e714);
    }
    else {
      local_28 = 0x8001;
    }
  }
  else {
    local_28 = 0x7fff;
  }
  *(undefined2 *)(iVar5 + 0x15) = local_28;
  if (fVar3 <= _DAT_0059e71c) {
    if (_DAT_0059e718 <= fVar3) {
      local_28 = (undefined2)(int)ROUND(fVar3 * _DAT_0059e714);
    }
    else {
      local_28 = 0x8001;
    }
  }
  else {
    local_28 = 0x7fff;
  }
  *(undefined2 *)(iVar5 + 0x17) = local_28;
  fVar1 = (float)*(double *)(iVar6 + 100);
  fVar2 = (float)*(double *)(iVar6 + 0x6c);
  fVar3 = (float)*(double *)(iVar6 + 0x74);
  if (fVar1 <= _DAT_0059e710) {
    if (_DAT_0059e70c <= fVar1) {
      local_28 = (undefined2)(int)ROUND(fVar1 * _DAT_0059e708);
    }
    else {
      local_28 = 0x8001;
    }
  }
  else {
    local_28 = 0x7fff;
  }
  *(undefined2 *)(iVar5 + 0x19) = local_28;
  if (fVar2 <= _DAT_0059e710) {
    if (_DAT_0059e70c <= fVar2) {
      local_28 = (undefined2)(int)ROUND(fVar2 * _DAT_0059e708);
    }
    else {
      local_28 = 0x8001;
    }
  }
  else {
    local_28 = 0x7fff;
  }
  *(undefined2 *)(iVar5 + 0x1b) = local_28;
  if (fVar3 <= _DAT_0059e710) {
    if (_DAT_0059e70c <= fVar3) {
      local_28 = (undefined2)(int)ROUND(fVar3 * _DAT_0059e708);
    }
    else {
      local_28 = 0x8001;
    }
  }
  else {
    local_28 = 0x7fff;
  }
  *(undefined2 *)(iVar5 + 0x1d) = local_28;
  fVar1 = (float)*(double *)(iVar6 + 0x7c);
  fVar2 = (float)*(double *)(iVar6 + 0x84);
  fVar3 = (float)*(double *)(iVar6 + 0x8c);
  if (fVar1 <= _DAT_0059e704) {
    if (_DAT_0059e700 <= fVar1) {
      local_28 = (undefined2)(int)ROUND(fVar1 * _DAT_0059e6fc);
    }
    else {
      local_28 = 0x8001;
    }
  }
  else {
    local_28 = 0x7fff;
  }
  *(undefined2 *)(iVar5 + 0x1f) = local_28;
  if (fVar2 <= _DAT_0059e704) {
    if (_DAT_0059e700 <= fVar2) {
      local_28 = (undefined2)(int)ROUND(fVar2 * _DAT_0059e6fc);
    }
    else {
      local_28 = 0x8001;
    }
  }
  else {
    local_28 = 0x7fff;
  }
  *(undefined2 *)(iVar5 + 0x21) = local_28;
  if (fVar3 <= _DAT_0059e704) {
    if (_DAT_0059e700 <= fVar3) {
      local_28 = (undefined2)(int)ROUND(fVar3 * _DAT_0059e6fc);
      *(undefined2 *)(iVar5 + 0x23) = local_28;
      return;
    }
    *(undefined2 *)(iVar5 + 0x23) = 0x8001;
    return;
  }
  *(undefined2 *)(iVar5 + 0x23) = 0x7fff;
  return;
}


