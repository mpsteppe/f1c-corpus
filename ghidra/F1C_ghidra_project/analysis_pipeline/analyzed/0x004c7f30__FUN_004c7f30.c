// Function: FUN_004c7f30 @ 004c7f30
// Size (bytes): 531


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c7f30(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = _DAT_0059e7f8;
  switch(DAT_007c56a4) {
  case 3:
    fVar1 = _DAT_005ace10;
    break;
  case 4:
    fVar1 = _DAT_005ace0c;
    break;
  case 5:
    if (DAT_007c56a8 == 5) {
      fVar1 = ((float)_DAT_008afea0 - _DAT_008acf90) / (_DAT_008acf94 - _DAT_008acf90);
      fVar2 = fVar1 * fVar1 * _DAT_0059e4e8;
LAB_004c7fc6:
      fVar2 = fVar2 + _DAT_0059e450;
LAB_004c7fcc:
      if (fVar2 < _DAT_0059e450) goto switchD_004c8011_caseD_3;
    }
    else {
      fVar1 = _DAT_005ace08;
      if (DAT_007c56a8 != 8) break;
      fVar2 = ((float)_DAT_008afea0 - _DAT_008acf94) * _DAT_005acd40;
LAB_004c80b1:
      fVar2 = _DAT_0059e43c - fVar2;
      fVar1 = _DAT_0059e7f8;
      if (fVar2 < _DAT_0059e7f8) break;
    }
    fVar1 = fVar2;
    if (_DAT_0059e43c < fVar2) {
      fVar1 = _DAT_0059e43c;
    }
    break;
  case 6:
    fVar1 = _DAT_005ace04;
    break;
  case 7:
    fVar1 = _DAT_005ace00;
    switch(DAT_007c56a8) {
    case 1:
    case 2:
      fVar1 = _DAT_005acdfc;
      break;
    case 3:
switchD_004c8011_caseD_3:
      fVar1 = _DAT_0059e450;
      break;
    case 4:
      fVar2 = _DAT_0059e43c -
              ((_DAT_008acfb8 + _DAT_0059e7ec) - (float)_DAT_008afea0) * _DAT_005acd48;
      goto LAB_004c7fcc;
    case 5:
      iVar3 = FUN_004d1b50(0);
      if (DAT_008acf8c < 2) {
        fVar2 = (_DAT_0059e450 - _DAT_0059e43c) * (_DAT_0059e450 - _DAT_0059e43c);
        fVar2 = fVar2 + fVar2;
      }
      else {
        fVar2 = _DAT_0059e450 -
                (float)*(int *)(&DAT_005f0714 + iVar3 * 0x48c0) / (float)(DAT_008acf8c + -1);
        fVar2 = fVar2 * fVar2;
        fVar2 = fVar2 + fVar2;
      }
      goto LAB_004c7fc6;
    case 8:
      fVar2 = ((float)_DAT_008afea0 - _DAT_008acf94) * _DAT_0059e97c;
      goto LAB_004c80b1;
    }
  }
  fVar2 = param_2 * _DAT_0059e4e0;
  if (_DAT_0059e448 <= param_2 * _DAT_0059e4e0) {
    fVar2 = _DAT_0059e448;
  }
  if (fVar1 <= *(float *)(param_1 + 8)) {
    fVar2 = *(float *)(param_1 + 8) - fVar2;
    *(float *)(param_1 + 8) = fVar2;
    if (fVar2 < fVar1) {
      *(float *)(param_1 + 8) = fVar1;
      return;
    }
  }
  else {
    fVar2 = fVar2 + *(float *)(param_1 + 8);
    *(float *)(param_1 + 8) = fVar2;
    if (fVar1 < fVar2) {
      *(float *)(param_1 + 8) = fVar1;
      return;
    }
  }
  return;
}


