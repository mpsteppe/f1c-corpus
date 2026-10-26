// Function: FUN_004389b0 @ 004389b0
// Size (bytes): 597


void __thiscall FUN_004389b0(int param_1,int param_2)

{
  double dVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  double local_b4;
  double local_ac;
  double local_a4;
  int local_9c;
  undefined4 local_98 [18];
  double local_50 [3];
  double local_38;
  double local_20;
  
  if (*(char *)(param_1 + 0x1c4) == '\0') {
    cVar2 = *(char *)(param_1 + 0x1c5);
    puVar7 = (undefined4 *)(param_2 + 0x1c);
    pdVar5 = local_50;
    for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined4 *)pdVar5 = *puVar7;
      puVar7 = puVar7 + 1;
      pdVar5 = (double *)((int)pdVar5 + 4);
    }
    if (cVar2 != '\0') {
      FUN_0056bde0(param_1 + 0x1c8,0);
    }
    FUN_0056c2d0(*(undefined4 *)(param_1 + 0xac),*(undefined4 *)(param_1 + 0xb0),0);
    dVar1 = *(double *)(param_1 + 0xbc);
    iVar3 = *(int *)(param_1 + 0x15c);
    local_b4 = local_50[0] * dVar1 + *(double *)(param_2 + 0x7c);
    local_ac = local_38 * dVar1 + *(double *)(param_2 + 0x84);
    local_a4 = local_20 * dVar1 + *(double *)(param_2 + 0x8c);
  }
  else {
    local_98[0] = 0;
    local_98[1] = 0;
    local_98[2] = 0;
    local_98[3] = 0;
    local_98[4] = 0;
    local_98[5] = 0;
    local_98[6] = 0;
    local_98[7] = 0;
    local_98[8] = 0;
    local_98[9] = 0;
    local_98[10] = 0;
    local_98[0xb] = 0;
    local_98[0xc] = 0;
    local_98[0xd] = 0;
    local_98[0xe] = 0;
    local_98[0xf] = 0;
    local_98[0x10] = 0;
    local_98[0x11] = 0;
    local_b4 = 0.0;
    local_ac = 0.0;
    local_a4 = 0.0;
    FUN_0056bd40(local_98 + 0xc);
    puVar7 = *(undefined4 **)(param_1 + 0x15c);
    puVar6 = local_98;
    for (iVar3 = 6; puVar7 = puVar7 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
    }
    puVar7 = local_98 + 6;
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x15c) + 100);
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar6 = puVar6 + 1;
    }
    local_9c = *(int *)(param_1 + 0x15c);
    pdVar5 = local_50;
    puVar7 = (undefined4 *)(local_9c + 0x1c);
    for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *(undefined4 *)pdVar5;
      pdVar5 = (double *)((int)pdVar5 + 4);
      puVar7 = puVar7 + 1;
    }
    FUN_005692a0();
    pdVar5 = &local_b4;
    puVar7 = (undefined4 *)(local_9c + 0x7c);
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *(undefined4 *)pdVar5;
      pdVar5 = (double *)((int)pdVar5 + 4);
      puVar7 = puVar7 + 1;
    }
    FUN_00569410();
    puVar7 = *(undefined4 **)(param_1 + 0x160);
    if (puVar7 == (undefined4 *)0x0) {
      return;
    }
    puVar6 = local_98;
    for (iVar3 = 6; puVar7 = puVar7 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
    }
    puVar7 = local_98 + 6;
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x160) + 100);
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar6 = puVar6 + 1;
    }
    iVar3 = *(int *)(param_1 + 0x160);
  }
  pdVar5 = local_50;
  puVar7 = (undefined4 *)(iVar3 + 0x1c);
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *(undefined4 *)pdVar5;
    pdVar5 = (double *)((int)pdVar5 + 4);
    puVar7 = puVar7 + 1;
  }
  FUN_005692a0();
  pdVar5 = &local_b4;
  puVar7 = (undefined4 *)(iVar3 + 0x7c);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *(undefined4 *)pdVar5;
    pdVar5 = (double *)((int)pdVar5 + 4);
    puVar7 = puVar7 + 1;
  }
  FUN_00569410();
  return;
}


