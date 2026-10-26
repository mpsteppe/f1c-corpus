// Function: FUN_0042a180 @ 0042a180
// Size (bytes): 577


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042a180(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  if (*(int *)(*param_1 + 13000) != 1) {
    return;
  }
  if (DAT_007c56a4 != 7) {
    iVar2 = param_1[0x100f];
    local_4 = 10;
    if (iVar2 < 0xb) {
      local_4 = iVar2;
    }
    fVar1 = (float)param_1[0x113d] + (float)param_1[0x1136];
    if ((float)local_4 * _DAT_0059e97c + (float)param_1[0x114f] <= fVar1) {
      local_4 = 10;
      if (iVar2 < 0xb) {
        local_4 = iVar2;
      }
      fVar1 = (float)local_4 * _DAT_0059e97c + (float)param_1[0x114f];
    }
    param_1[0x114f] = (int)fVar1;
  }
  fVar1 = _DAT_0059e43c - _DAT_008afee8 * (float)param_1[0x1132];
  if (fVar1 < _DAT_0059e450) {
    fVar1 = _DAT_0059e450;
  }
  param_1[0x1160] = (int)fVar1;
  if (param_1[0x1153] == 1) {
    return;
  }
  if (param_1[(param_1[0x1178] + 0x459) * 4] <= *(int *)(*param_1 + 0x403c)) {
    FUN_0042a110();
  }
  FUN_004f1630();
  iVar2 = FUN_004a4830();
  if (_DAT_0059e444 <= _DAT_008afee8) {
    if (_DAT_008afee8 < _DAT_0059e978) {
      if ((iVar2 == 5) && (_DAT_0059e7e8 < _DAT_008afee8)) goto LAB_0042a29e;
      iVar3 = 4;
      if ((iVar2 == param_1[0x1163]) && (_DAT_008afee8 < _DAT_0059e7e8)) {
        iVar3 = param_1[0x1163];
      }
      goto LAB_0042a28f;
    }
    if (_DAT_0059e974 <= _DAT_008afee8) {
      iVar3 = 6;
      fVar1 = _DAT_0059e824;
      if (iVar2 == 5) goto joined_r0x0042a3b1;
      goto LAB_0042a28f;
    }
    iVar3 = 5;
    fVar1 = _DAT_0059e970;
    if (iVar2 == 4) {
joined_r0x0042a3b1:
      if (_DAT_008afee8 < fVar1) goto LAB_0042a29e;
    }
    else {
      if (iVar2 != 6) goto LAB_0042a28f;
      if (_DAT_0059e4e8 < _DAT_008afee8) goto LAB_0042a29e;
    }
  }
  else {
    iVar3 = param_1[0x1163];
LAB_0042a28f:
    if ((iVar2 == iVar3) || (iVar3 == 0)) goto LAB_0042a29e;
  }
  FUN_0042a110();
LAB_0042a29e:
  if (_DAT_0059e824 <=
      ((float)param_1[0xe49] + (float)param_1[0xe0b] + (float)param_1[0xdcd] + (float)param_1[0xd8f]
      ) * _DAT_0059e7f8) {
    return;
  }
  FUN_0042a110();
  return;
}


