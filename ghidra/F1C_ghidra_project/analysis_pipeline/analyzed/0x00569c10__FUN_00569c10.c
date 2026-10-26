// Function: FUN_00569c10 @ 00569c10
// Size (bytes): 461


void __thiscall FUN_00569c10(int param_1,double param_2)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  double *pdVar6;
  double *pdVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  double local_20;
  double local_18;
  double local_10;
  
  dVar2 = *(double *)(param_1 + 100);
  pdVar1 = (double *)(param_1 + 100);
  pdVar7 = (double *)(param_1 + 4);
  dVar3 = *pdVar7;
  pdVar6 = pdVar7;
  puVar8 = (undefined4 *)(param_1 + 0x164);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *(undefined4 *)pdVar6;
    pdVar6 = (double *)((int)pdVar6 + 4);
    puVar8 = puVar8 + 1;
  }
  *pdVar7 = param_2 * dVar2 + dVar3;
  dVar2 = *(double *)(param_1 + 0x6c);
  dVar3 = *(double *)(param_1 + 0xc);
  puVar8 = (undefined4 *)(param_1 + 0x1c);
  puVar9 = (undefined4 *)(param_1 + 0x17c);
  for (iVar5 = 0x12; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  *(double *)(param_1 + 0xc) = param_2 * dVar2 + dVar3;
  dVar2 = *(double *)(param_1 + 0x74);
  dVar3 = *(double *)(param_1 + 0x14);
  pdVar7 = pdVar1;
  puVar8 = (undefined4 *)(param_1 + 0x1c4);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *(undefined4 *)pdVar7;
    pdVar7 = (double *)((int)pdVar7 + 4);
    puVar8 = puVar8 + 1;
  }
  *(double *)(param_1 + 0x14) = param_2 * dVar2 + dVar3;
  dVar4 = param_2 * *(double *)(param_1 + 0xb4);
  dVar2 = *(double *)(param_1 + 0x134);
  dVar3 = *pdVar1;
  puVar8 = (undefined4 *)(param_1 + 0x94);
  puVar9 = (undefined4 *)(param_1 + 0x1dc);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  *pdVar1 = dVar4 * dVar2 + dVar3;
  dVar2 = *(double *)(param_1 + 0x13c);
  dVar3 = *(double *)(param_1 + 0x6c);
  puVar8 = (undefined4 *)(param_1 + 0x134);
  puVar9 = (undefined4 *)(param_1 + 500);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  *(double *)(param_1 + 0x6c) = dVar4 * dVar2 + dVar3;
  dVar2 = *(double *)(param_1 + 0x144);
  dVar3 = *(double *)(param_1 + 0x74);
  puVar8 = (undefined4 *)(param_1 + 0x14c);
  puVar9 = (undefined4 *)(param_1 + 0x20c);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  *(double *)(param_1 + 0x74) = dVar4 * dVar2 + dVar3;
  local_20 = param_2 * *(double *)(param_1 + 0x7c);
  local_18 = param_2 * *(double *)(param_1 + 0x84);
  local_10 = param_2 * *(double *)(param_1 + 0x8c);
  FUN_0056c020(&local_20);
  *(double *)(param_1 + 0x94) = param_2 * *(double *)(param_1 + 0x14c) + *(double *)(param_1 + 0x94)
  ;
  *(double *)(param_1 + 0x9c) = param_2 * *(double *)(param_1 + 0x154) + *(double *)(param_1 + 0x9c)
  ;
  *(double *)(param_1 + 0xa4) = param_2 * *(double *)(param_1 + 0x15c) + *(double *)(param_1 + 0xa4)
  ;
  FUN_005692a0();
  *(double *)(param_1 + 0x7c) =
       *(double *)(param_1 + 0xec) * *(double *)(param_1 + 0x94) +
       *(double *)(param_1 + 0xf4) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 0xfc) * *(double *)(param_1 + 0xa4);
  *(double *)(param_1 + 0x84) =
       *(double *)(param_1 + 0x104) * *(double *)(param_1 + 0x94) +
       *(double *)(param_1 + 0x10c) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 0x114) * *(double *)(param_1 + 0xa4);
  *(double *)(param_1 + 0x8c) =
       *(double *)(param_1 + 0x11c) * *(double *)(param_1 + 0x94) +
       *(double *)(param_1 + 0x124) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 300) * *(double *)(param_1 + 0xa4);
  return;
}


