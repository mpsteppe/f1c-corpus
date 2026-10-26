// Function: FUN_004f1fe0 @ 004f1fe0
// Size (bytes): 830


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f1fe0(int *param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  fVar3 = (float)param_1[0x1001];
  param_1[0x1001] = 0;
  iVar7 = *(int *)(*param_1 + 0x4064);
  if (iVar7 != 0) {
    if (iVar7 == 2) {
      return;
    }
    if (param_1[0xcaf] != 1) {
      return;
    }
    if (_DAT_0059e43c <
        ((float)param_1[0xd35] - (float)param_1[0xffe]) *
        ((float)param_1[0xd35] - (float)param_1[0xffe]) +
        ((float)param_1[0xd36] - (float)param_1[0xfff]) *
        ((float)param_1[0xd36] - (float)param_1[0xfff]) +
        ((float)param_1[0xd37] - (float)param_1[0x1000]) *
        ((float)param_1[0xd37] - (float)param_1[0x1000])) {
      param_1[0xffe] = param_1[0xd35];
      param_1[0xfff] = param_1[0xd36];
      param_1[0x1000] = param_1[0xd37];
      return;
    }
    fVar3 = fVar3 + param_2;
    param_1[0x1001] = (int)fVar3;
    if (fVar3 <= _DAT_0059e8d8) {
      return;
    }
    param_1[0x1001] = 0;
    param_1[0xf52] = 0;
    param_1[0xf53] = 0;
    param_1[0xf54] = 0;
    if (DAT_007c56a4 != 7) {
      return;
    }
    if (*(char *)((int)param_1 + 0x1051) == '\0') {
      return;
    }
    *(undefined1 *)((int)param_1 + 0x1051) = 0;
    FUN_004e0ed0(param_1[0x412]);
    return;
  }
  pfVar1 = (float *)(param_1 + 0xd35);
  if (_DAT_0059e43c <
      ((float)param_1[0xd35] - (float)param_1[0xffe]) *
      ((float)param_1[0xd35] - (float)param_1[0xffe]) +
      ((float)param_1[0xd36] - (float)param_1[0xfff]) *
      ((float)param_1[0xd36] - (float)param_1[0xfff]) +
      ((float)param_1[0xd37] - (float)param_1[0x1000]) *
      ((float)param_1[0xd37] - (float)param_1[0x1000])) {
    param_1[0xffe] = (int)*pfVar1;
    param_1[0xfff] = param_1[0xd36];
    param_1[0x1000] = param_1[0xd37];
    return;
  }
  if (param_1[0xcaf] == 0) {
    if (DAT_007ce814 != 0) {
      return;
    }
    iVar7 = 0;
    piVar5 = param_1 + 0x20a;
    do {
      if ((*piVar5 == 0) || ((char)piVar5[0x10] == '\0')) break;
      iVar7 = iVar7 + 1;
      piVar5 = piVar5 + 0x4a;
    } while (iVar7 < 4);
    if ((iVar7 == 4) && (_DAT_0059e84c < ABS((float)param_1[0xe65]))) {
      return;
    }
  }
  else if (*(float *)(*param_1 + 0x4170) < _DAT_0059eae0) {
    return;
  }
  cVar4 = FUN_004d21d0();
  if ((((cVar4 != '\0') && (*(int *)(*param_1 + 0x3450) != 3)) &&
      (cVar4 = FUN_004effd0(), cVar4 == '\0')) &&
     (fVar3 = fVar3 + param_2, param_1[0x1001] = (int)fVar3, _DAT_007d0a8c < fVar3)) {
    param_1[0xf52] = 0;
    param_1[0xf53] = 0;
    param_1[0xf54] = 0;
    pfVar6 = (float *)FUN_00403640(pfVar1,0);
    param_1[0xea7] = (int)pfVar6;
    param_2 = (*pfVar1 - *pfVar6) * pfVar6[8] +
              ((float)param_1[0xd36] - pfVar6[1]) * pfVar6[9] +
              ((float)param_1[0xd37] - pfVar6[2]) * pfVar6[10];
    if (DAT_0059e440 <= param_2) {
      param_2 = param_2 - pfVar6[0xc];
      fVar3 = pfVar6[0xc];
      fVar2 = pfVar6[0x17];
    }
    else {
      param_2 = -param_2 - pfVar6[0xb];
      fVar3 = pfVar6[0xb];
      fVar2 = pfVar6[0x16];
    }
    FUN_0041b250(*param_1);
    if (((param_2 < _DAT_0059e864) || (fVar2 < fVar3 != (fVar2 == fVar3))) &&
       (param_1[0xf58] = 2, DAT_007c56a4 == 7)) {
      FUN_004d1140(*param_1,local_c,local_18);
      FUN_004ef7c0(local_c,local_18);
      FUN_004a5c80(0);
    }
    FUN_004bc060(1);
    if (param_1[0xcaf] == 0) {
      DAT_007ce258 = 1;
      return;
    }
  }
  return;
}


