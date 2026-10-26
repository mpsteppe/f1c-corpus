// Function: FUN_004f0430 @ 004f0430
// Size (bytes): 2270


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f0430(int *param_1,float param_2)

{
  double *pdVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  undefined1 uVar5;
  char cVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int *piVar12;
  bool bVar13;
  float10 fVar14;
  int *local_324;
  float *local_310;
  float local_308;
  float local_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8;
  undefined1 local_2e4 [12];
  double local_2d8;
  float local_2d0;
  undefined4 uStack_2cc;
  double local_2c8;
  int local_2c0;
  int local_2bc;
  int local_2b8;
  int local_2b4 [8];
  float afStack_294 [10];
  float local_26c [9];
  double local_248 [9];
  double local_200 [9];
  undefined1 local_1b8 [436];
  
  FUN_004a55a0((float)_DAT_008afe98,param_2);
  bVar4 = true;
  switch(param_1[0xcaf]) {
  case 0:
    param_2 = param_2 - (float)param_1[0xd2b];
    local_2d0 = param_2 * (float)param_1[0xd3d];
    local_308 = param_2 * (float)param_1[0xd3b] + (float)param_1[0xd35];
    local_304 = param_2 * (float)param_1[0xd3c] + (float)param_1[0xd36];
    local_300 = local_2d0 + (float)param_1[0xd37];
    local_2f0 = param_2 * (float)param_1[0xd41];
    piVar7 = param_1 + 0xd2c;
    piVar12 = local_2b4;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *piVar12 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar12 = piVar12 + 1;
    }
    local_2ec = param_2 * (float)param_1[0xd42];
    local_2e8 = param_2 * (float)param_1[0xd43];
    FUN_00567120(&local_2f0,local_2e4);
    FUN_004e23d0(&local_308,local_2e4,local_2b4);
    fVar2 = DAT_0059e440;
    if (DAT_0059e440 < (float)param_1[0xe5e]) {
      fVar2 = (float)param_1[0xe65];
    }
    iVar8 = param_1[0xd5c];
    param_1[4] = (int)local_308;
    param_1[5] = (int)local_304;
    param_1[6] = (int)local_300;
    piVar7 = local_2b4;
    piVar12 = param_1 + 10;
    for (iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) {
      *piVar12 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar12 = piVar12 + 1;
    }
    param_1[0x13] = param_1[0xd3b];
    param_1[0x14] = param_1[0xd3c];
    param_1[0x15] = param_1[0xd3d];
    param_1[0x25] = (int)fVar2;
    param_1[0x26] = iVar8;
    bVar13 = DAT_007cc730 != 0;
    *(bool *)(param_1 + 0x1006) = bVar13;
    if (bVar13) {
      FUN_004f87c0(0x2b,1,0x3f800000,0x3f800000);
    }
    fVar3 = DAT_0059e440;
    fVar2 = (float)_DAT_007c7598 * _DAT_0059e46c;
    param_1[0x1007] = (int)fVar2;
    if (fVar3 < fVar2) {
      if (_DAT_0059e43c < fVar2) {
        param_1[0x1007] = 0x3f800000;
      }
      FUN_004f87c0(0x2c,1,param_1[0x1007],0x3f800000);
    }
    fVar2 = _DAT_0059e444;
    *(undefined1 *)((int)param_1 + 0x105d) = DAT_007c9080;
    *(bool *)((int)param_1 + 0x1059) = fVar2 < (float)param_1[0xd5e];
    if (DAT_007cc75c != 0) {
      *(bool *)((int)param_1 + 0x105b) = *(char *)((int)param_1 + 0x105b) == '\0';
    }
    fVar2 = (float)_DAT_007c7428;
    fVar3 = _DAT_0059e670;
    if (((_DAT_0059e670 <= fVar2) && (fVar3 = _DAT_0059e43c, fVar2 <= _DAT_0059e43c)) &&
       (fVar3 = _DAT_0059e670, _DAT_0059e670 <= fVar2)) {
      fVar3 = fVar2;
    }
    param_1[0x40d] = (int)fVar3;
    FUN_00447100(&local_2fc,&local_2c0);
    param_1[0x3f9] = (int)local_2fc;
    param_1[0x3fa] = (int)local_2f8;
    param_1[0x3fb] = (int)local_2f4;
    param_1[0x3fc] = local_2c0;
    param_1[0x3fd] = local_2bc;
    param_1[0x3fe] = local_2b8;
    local_310 = (float *)(param_1 + 0x16);
    local_324 = param_1 + 0xd6c;
    piVar7 = param_1 + 0x20a;
    iVar8 = 0;
    do {
      FUN_00446fd0(iVar8,&local_2d8,local_248,local_200);
      local_2fc = (float)local_2d8;
      local_2f8 = (float)(double)CONCAT44(uStack_2cc,local_2d0);
      local_2f4 = (float)local_2c8;
      iVar10 = 0;
      do {
        iVar9 = iVar10 + 1;
        afStack_294[iVar10 + 10] = (float)local_248[iVar10];
        iVar10 = iVar9;
      } while (iVar9 < 9);
      iVar10 = 0;
      do {
        pdVar1 = local_200 + iVar10;
        iVar10 = iVar10 + 1;
        afStack_294[iVar10] = (float)*pdVar1;
      } while (iVar10 < 9);
      if ((*piVar7 != 0) && ((char)piVar7[0x10] != '\0')) {
        FUN_004e2610(iVar8,&local_2fc,afStack_294 + 10,afStack_294 + 1);
        FUN_004e2230(iVar8,*local_324);
        *local_310 = local_2fc;
        local_310[1] = local_2f8;
        local_310[2] = local_2f4;
      }
      iVar8 = iVar8 + 1;
      piVar7 = piVar7 + 0x4a;
      local_324 = local_324 + 0x3e;
      local_310 = local_310 + 3;
    } while (iVar8 < 4);
    _DAT_007c8b44 = 0;
    _DAT_007c8b48 = 0;
    FUN_004f12e0(CONCAT31((int3)((uint)(&DAT_007c54f0)[DAT_007c54dc] >> 8),
                          *(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) ==
                          *(int *)(*param_1 + 0x4894)));
    break;
  case 1:
    uVar5 = FUN_004f1aa0();
    fVar2 = _DAT_0059e444;
    *(undefined1 *)((int)param_1 + 0x105d) = uVar5;
    *(bool *)((int)param_1 + 0x1059) = fVar2 < (float)param_1[0xd5e];
  case 2:
    param_2 = param_2 - (float)param_1[0xd2b];
    local_2d0 = param_2 * (float)param_1[0xd3d];
    local_308 = param_2 * (float)param_1[0xd3b] + (float)param_1[0xd35];
    local_304 = param_2 * (float)param_1[0xd3c] + (float)param_1[0xd36];
    piVar7 = param_1 + 0xd2c;
    piVar12 = local_2b4;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *piVar12 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar12 = piVar12 + 1;
    }
    local_300 = local_2d0 + (float)param_1[0xd37];
    local_2f0 = param_2 * (float)param_1[0xd41];
    local_2ec = param_2 * (float)param_1[0xd42];
    local_2e8 = param_2 * (float)param_1[0xd43];
    FUN_00567120(&local_2f0,local_2e4);
    FUN_004e23d0(&local_308,local_2e4,local_2b4);
    fVar2 = (float)param_1[0xd5d];
    fVar3 = _DAT_0059e670;
    if (((_DAT_0059e670 <= fVar2) && (fVar3 = _DAT_0059e43c, fVar2 <= _DAT_0059e43c)) &&
       (fVar3 = _DAT_0059e670, _DAT_0059e670 <= fVar2)) {
      fVar3 = fVar2;
    }
    param_1[0x40d] = (int)fVar3;
    iVar8 = param_1[0xd5c];
    iVar10 = param_1[0xe65];
    param_1[4] = (int)local_308;
    param_1[5] = (int)local_304;
    param_1[6] = (int)local_300;
    piVar7 = local_2b4;
    piVar12 = param_1 + 10;
    for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar12 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar12 = piVar12 + 1;
    }
    param_1[0x13] = param_1[0xd3b];
    param_1[0x14] = param_1[0xd3c];
    param_1[0x15] = param_1[0xd3d];
    param_1[0x25] = iVar10;
    param_1[0x26] = iVar8;
    if ((char)param_1[0x1006] != '\0') {
      FUN_004f87c0(0x2b,1,0x3f800000,0x3f800000);
    }
    if ((float)param_1[0x1007] != DAT_0059e440) {
      FUN_004f87c0(0x2c,1,param_1[0x1007],0x3f800000);
    }
    if (param_1[0xcaf] == 2) {
      pfVar11 = (float *)(param_1 + 0xd69);
      iVar8 = 4;
      param_1[0xd6a] = (int)((float)param_1[0xe58] * (float)param_1[0xd5d]);
      param_1[0xda8] = (int)((float)param_1[0xe58] * (float)param_1[0xd5d]);
      do {
        *pfVar11 = (float)_DAT_008afe98 * pfVar11[3] + *pfVar11;
        if (_DAT_005ad180 < ABS(*pfVar11)) {
          fVar14 = (float10)FUN_0058957a();
          *pfVar11 = (float)fVar14;
        }
        pfVar11 = pfVar11 + 0x3e;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    local_324 = param_1 + 0x16;
    piVar7 = param_1 + 0x20a;
    iVar8 = 0;
    piVar12 = param_1 + 0xd69;
    do {
      if ((*piVar7 != 0) && ((char)piVar7[0x10] != '\0')) {
        FUN_004e24a0(iVar8,piVar12[-5],*piVar12,piVar12[1]);
        FUN_004e2230(iVar8,piVar12[3]);
        *local_324 = piVar12[-6];
        local_324[1] = piVar12[-5];
        local_324[2] = piVar12[-4];
      }
      iVar8 = iVar8 + 1;
      piVar7 = piVar7 + 0x4a;
      local_324 = local_324 + 3;
      piVar12 = piVar12 + 0x3e;
    } while (iVar8 < 4);
    FUN_004f12e0(CONCAT31((int3)((uint)(&DAT_007c54f0)[DAT_007c54dc] >> 8),
                          *(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) ==
                          *(int *)(*param_1 + 0x4894)));
    break;
  case 3:
    cVar6 = FUN_004b9ac0(param_1[1],local_1b8,DAT_005ad164);
    if (cVar6 != '\0') {
      fVar14 = (float10)FUN_004b9ce0();
      FUN_004c73f0(local_1b8,(float)fVar14);
      if ((char)param_1[0x1006] != '\0') {
        FUN_004f87c0(0x2b,1,0x3f800000,0x3f800000);
      }
      if ((float)param_1[0x1007] != DAT_0059e440) {
        FUN_004f87c0(0x2c,1,param_1[0x1007],0x3f800000);
      }
    }
    break;
  default:
    bVar4 = false;
  }
  FUN_004f0dd0();
  if (bVar4) {
    FUN_004e19d0();
    iVar8 = param_1[0x1008];
    param_1[0x1008] = iVar8 + 1U;
    if ((iVar8 + 1U & 0xf) == 0) {
      FUN_004f0d20();
      fVar2 = _DAT_005acdc0 - (float)param_1[0x40c] * _DAT_0059e824;
      if ((_DAT_008afecc < fVar2) ||
         ((float)param_1[0x40c] < (_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450)) {
        *(undefined1 *)((int)param_1 + 0x105b) = 1;
      }
      else if ((fVar2 + _DAT_005acd48 < _DAT_008afecc) &&
              ((_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450 == DAT_0059e440)) {
        *(undefined1 *)((int)param_1 + 0x105b) = 0;
        return;
      }
    }
  }
  return;
}


