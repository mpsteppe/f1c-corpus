// Function: FUN_004f70c0 @ 004f70c0
// Strings:  [%s%s%s, f1sounds.sfx]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004f70c0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  float fVar5;
  void *pvVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  float fStack_928;
  undefined4 local_924;
  float fStack_920;
  undefined4 local_91c;
  undefined4 uStack_918;
  float fStack_914;
  undefined4 local_910;
  float fStack_90c;
  undefined4 local_908 [2];
  undefined4 auStack_900 [2];
  undefined1 auStack_8f8 [884];
  undefined4 local_584 [2];
  undefined4 auStack_57c [2];
  undefined1 auStack_574 [884];
  undefined1 local_200 [512];
  
  local_910 = 0;
  puVar12 = local_908;
  iVar9 = 0x2d;
  do {
    *puVar12 = 0;
    puVar12[1] = 0xffffffff;
    FUN_004f7440();
    puVar12 = puVar12 + 5;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  puVar12 = local_584;
  iVar9 = 0x2d;
  do {
    *puVar12 = 0;
    puVar12[1] = 0xffffffff;
    FUN_004f7440();
    puVar12 = puVar12 + 5;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if ((param_1[0x1a5] == 0) && (param_1[0x1b6] == 0)) {
    pvVar6 = operator_new(0xb4);
    param_1[0x1a5] = (int)pvVar6;
    pvVar6 = operator_new(0xb4);
    param_1[0x1b6] = (int)pvVar6;
    iVar9 = 0;
    do {
      *(undefined4 *)(iVar9 + param_1[0x1a5]) = 0;
      *(undefined4 *)(iVar9 + param_1[0x1b6]) = 0;
      iVar9 = iVar9 + 4;
    } while (iVar9 < 0xb4);
    if (DAT_008afc74 == '\0') {
      puVar8 = DAT_005ec428;
      if (DAT_005ec428 == (undefined1 *)0x0) {
        puVar8 = &DAT_005ea438;
      }
      puVar7 = DAT_005ec3d8;
      if (DAT_005ec3d8 == (undefined1 *)0x0) {
        puVar7 = &DAT_005ea438;
      }
      FUN_0058815f(local_200,s__s_s_s_005c6784,puVar7,puVar8,s_f1sounds_sfx_005d6788);
      iVar9 = FUN_004f7460(local_200,&DAT_008af8f0,&DAT_008af568);
      if (iVar9 == 0) {
        DAT_008afc74 = '\x01';
      }
    }
    iVar9 = 0;
    do {
      puVar8 = *(undefined1 **)((int)&DAT_008af8f0 + iVar9);
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = &DAT_005ea438;
      }
      FUN_00566650(puVar8);
      uVar10 = *(undefined4 *)((int)&DAT_008af8f8 + iVar9);
      uVar3 = (&DAT_008af900)[iVar9];
      *(undefined4 *)((int)auStack_900 + iVar9 + 4) = *(undefined4 *)((int)&DAT_008af8fc + iVar9);
      puVar8 = *(undefined1 **)((int)&DAT_008af568 + iVar9);
      *(undefined4 *)((int)auStack_900 + iVar9) = uVar10;
      auStack_8f8[iVar9] = uVar3;
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = &DAT_005ea438;
      }
      FUN_00566650(puVar8);
      uVar10 = *(undefined4 *)((int)&DAT_008af574 + iVar9);
      uVar3 = (&DAT_008af578)[iVar9];
      *(undefined4 *)((int)auStack_57c + iVar9) = *(undefined4 *)((int)&DAT_008af570 + iVar9);
      *(undefined4 *)((int)auStack_57c + iVar9 + 4) = uVar10;
      auStack_574[iVar9] = uVar3;
      iVar9 = iVar9 + 0x14;
    } while (iVar9 < 900);
    iVar9 = FUN_004c40b0(*param_1 + 0x4714);
    if (iVar9 != 0) {
      puVar8 = *(undefined1 **)(iVar9 + 0x18);
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = &DAT_005ea438;
      }
      FUN_004f7460(puVar8,local_908,local_584);
    }
    if (DAT_008ac4c4 != (int *)0x0) {
      puVar8 = DAT_005ec3e8;
      if (DAT_005ec3e8 == (undefined1 *)0x0) {
        puVar8 = &DAT_005ea438;
      }
      (**(code **)(*DAT_008ac4c4 + 0x44))(puVar8);
    }
    iVar9 = 0;
    iVar11 = 0;
    do {
      FUN_004f8030(iVar9,&local_924,&local_91c);
      FUN_004f8280(iVar9,&fStack_928,&uStack_918,&fStack_920);
      iVar2 = iVar9 * 4;
      FUN_004f81d0(param_1[0x1a5] + iVar2,(int)local_908 + iVar11,local_924,local_91c);
      iVar4 = *(int *)(iVar2 + param_1[0x1a5]);
      if (iVar4 != 0) {
        fStack_914 = fStack_920;
        fVar5 = _DAT_0059e43c;
        if (fStack_928 < DAT_0059e440 == (fStack_928 == DAT_0059e440)) {
          fVar5 = _DAT_0059e43c / fStack_928;
        }
        *(float *)(iVar4 + 0x1c) = fVar5;
        *(float *)(iVar4 + 0x20) = _DAT_0059e43c - fVar5 * fStack_920;
        *(undefined4 *)(iVar4 + 0x24) = uStack_918;
      }
      FUN_004f81d0(param_1[0x1b6] + iVar2,(int)local_584 + iVar11,local_924,local_91c);
      iVar2 = *(int *)(iVar2 + param_1[0x1b6]);
      if (iVar2 != 0) {
        fStack_90c = fStack_920;
        fVar5 = _DAT_0059e43c;
        if (fStack_928 < DAT_0059e440 == (fStack_928 == DAT_0059e440)) {
          fVar5 = _DAT_0059e43c / fStack_928;
        }
        *(float *)(iVar2 + 0x1c) = fVar5;
        *(float *)(iVar2 + 0x20) = _DAT_0059e43c - fVar5 * fStack_920;
        *(undefined4 *)(iVar2 + 0x24) = uStack_918;
      }
      iVar11 = iVar11 + 0x14;
      iVar9 = iVar9 + 1;
      uVar10 = local_910;
    } while (iVar11 < 900);
  }
  else {
    uVar10 = 1;
  }
  puVar8 = local_200;
  iVar9 = 0x2d;
  do {
    piVar1 = (int *)(puVar8 + -0x14);
    puVar8 = puVar8 + -0x14;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  puVar12 = local_584;
  iVar9 = 0x2d;
  do {
    piVar1 = puVar12 + -5;
    puVar12 = puVar12 + -5;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  return uVar10;
}


