// Function: FUN_00447780 @ 00447780
// Size (bytes): 801


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00447780(int param_1,double *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double *pdVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  double *pdVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int local_90;
  int local_8c;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68 [6];
  undefined4 local_50 [19];
  
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_8c = 0;
  if (0 < *(int *)(param_1 + 0x15ac)) {
    local_90 = 0;
    do {
      pdVar10 = param_2;
      puVar11 = (undefined4 *)(*(int *)(param_1 + 0x15b0) + local_90 + 100);
      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar11 = *(undefined4 *)pdVar10;
        pdVar10 = (double *)((int)pdVar10 + 4);
        puVar11 = puVar11 + 1;
      }
      FUN_00569280(&local_80);
      local_8c = local_8c + 1;
      local_90 = local_90 + 0x244;
    } while (local_8c < *(int *)(param_1 + 0x15ac));
  }
  iVar7 = *(int *)(param_1 + 0x15f0);
  iVar9 = 4;
  pdVar10 = (double *)(param_1 + 0x348);
  dVar3 = -(*(double *)(iVar7 + 0x2c) * *param_2 +
           *(double *)(iVar7 + 0x44) * param_2[1] + *(double *)(iVar7 + 0x5c) * param_2[2]);
  pdVar6 = pdVar10;
  do {
    iVar9 = iVar9 + -1;
    *pdVar6 = -(dVar3 / pdVar6[0x2a]);
    pdVar6[1] = -(dVar3 / pdVar6[0x2a]);
    pdVar6 = (double *)((int)pdVar6 + 0x464);
  } while (iVar9 != 0);
  iVar7 = *(int *)(param_1 + 0x1e14);
  if (iVar7 == 0) {
    dVar4 = (*(double *)(param_1 + 0x1074) + *(double *)(param_1 + 0xc10)) * _DAT_0059e880;
  }
  else if (iVar7 == 1) {
    dVar4 = (*(double *)(param_1 + 0x1074) + *(double *)(param_1 + 0xc10) +
             *(double *)(param_1 + 0x7ac) + *pdVar10) * _DAT_0059eb50;
  }
  else {
    dVar4 = dVar3;
    if (iVar7 == 2) {
      dVar4 = (*(double *)(param_1 + 0x7ac) + *pdVar10) * _DAT_0059e880;
    }
  }
  dVar5 = ABS(dVar3) * _DAT_0059eef0 + _DAT_0059eb28;
  dVar3 = _DAT_0059e430;
  if ((_DAT_0059e430 <= dVar5) && (dVar3 = dVar5, _DAT_0059ec70 < dVar5)) {
    dVar3 = _DAT_0059ec70;
  }
  iVar7 = *(int *)(param_1 + 0x1eac);
  pdVar10 = (double *)(param_1 + 0x1eb0 + iVar7 * 8);
  *(double *)(param_1 + 0x1c5c) = -(dVar4 * *(double *)(param_1 + 0x1eb0 + iVar7 * 8));
  iVar9 = iVar7;
  if (0 < iVar7) {
    do {
      if (-(dVar4 * *pdVar10) < dVar3 * *(double *)(param_1 + 0x1cdc)) {
        *(double *)(param_1 + 0x1c5c) = -(dVar4 * *pdVar10);
        iVar9 = iVar7;
      }
      iVar7 = iVar7 + -1;
      pdVar10 = pdVar10 + -1;
    } while (0 < iVar7);
  }
  if (*(double *)(param_1 + 0x1c5c) < *(double *)(param_1 + 0x1c84)) {
    FUN_00447e00(0,4);
    *(undefined4 *)(param_1 + 0x1c5c) = *(undefined4 *)(param_1 + 0x1c84);
    *(undefined4 *)(param_1 + 0x1c60) = *(undefined4 *)(param_1 + 0x1c88);
  }
  else {
    FUN_00447e00(iVar9,4);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x1c5c);
  uVar2 = *(undefined4 *)(param_1 + 0x1c60);
  *(undefined4 *)(param_1 + 0x1c64) = uVar1;
  *(undefined4 *)(param_1 + 0x1c68) = uVar2;
  *(undefined4 *)(param_1 + 0x1e38) = uVar1;
  *(undefined4 *)(param_1 + 0x1e3c) = uVar2;
  *(undefined4 *)(param_1 + 0x1e40) = uVar1;
  *(undefined4 *)(param_1 + 0x1e44) = uVar2;
  FUN_004471f0(1);
  piVar8 = (int *)(param_1 + 0x3ec);
  *(undefined4 *)(param_1 + 0xd0) = 0;
  local_8c = 2;
  do {
    if ((*piVar8 != 0) && ((char)piVar8[0x19] == '\0')) {
      puVar11 = (undefined4 *)(*(int *)(param_1 + 0x15f0) + 0x1c);
      puVar12 = local_50;
      for (iVar7 = 0x12; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
      }
      FUN_0056bde0(piVar8 + -0x33,0);
      puVar11 = (undefined4 *)(*(int *)(param_1 + 0x15f0) + 0x7c);
      puVar12 = local_68;
      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
      }
      iVar7 = *piVar8;
      puVar11 = local_50;
      puVar12 = (undefined4 *)(iVar7 + 0x1c);
      for (iVar9 = 0x12; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
      }
      FUN_005692a0();
      puVar11 = local_68;
      puVar12 = (undefined4 *)(iVar7 + 0x7c);
      for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
      }
      FUN_00569410();
      FUN_00441450();
    }
    piVar8 = piVar8 + 0x119;
    local_8c = local_8c + -1;
  } while (local_8c != 0);
  return;
}


