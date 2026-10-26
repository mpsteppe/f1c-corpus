// Function: FUN_004fcc30 @ 004fcc30
// Strings:  [Weather, %sweather.txt]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fcc30(undefined4 *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  void *pvVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  uint uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined4 local_11c;
  undefined4 local_118 [6];
  undefined1 local_100 [256];
  
  FUN_004fd840();
  param_1[7] = 0;
  if (((DAT_007c56a0 & 1) == 0) || (DAT_008ab6e4 == 2)) {
    FUN_00543960(0x20000);
    param_1[5] = 0;
    return;
  }
  if (DAT_007cf17c == '\0') {
    *param_1 = 0x3f800000;
  }
  else {
    *param_1 = _DAT_008acf9c;
  }
  if (DAT_007cf080 == 0) {
    puVar4 = DAT_005ec438;
    if (DAT_005ec438 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0058815f(local_100,s__sweather_txt_005d6f68,puVar4);
    iVar3 = FUN_004fe7c0(local_100);
LAB_004fccdd:
    if (iVar3 == 0) goto LAB_004fcd7f;
  }
  else if (((DAT_007cf080 == 1) && (iVar3 = FUN_004c5840(0), iVar3 != 0)) &&
          (iVar3 = FUN_005679c0(s_Weather_005d173c), iVar3 != 0)) {
    iVar3 = FUN_004fe350(iVar3);
    goto LAB_004fccdd;
  }
  if (DAT_007cf080 == 3) {
    local_11c = 0x3f266666;
  }
  else if (DAT_007cf080 == 4) {
    local_11c = 0x3f51eb85;
  }
  else if (DAT_007cf080 == 5) {
    local_11c = 0x3f70a3d7;
  }
  else {
    local_11c = 0x3e99999a;
  }
  FUN_004fd840();
  pvVar5 = operator_new(0x10);
  if (pvVar5 == (void *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = (undefined4 *)FUN_004fc9a0();
  }
  param_1[0xf] = puVar6;
  *puVar6 = 0;
  *(undefined4 *)(param_1[0xf] + 4) = 0x41a00000;
  *(undefined4 *)(param_1[0xf] + 8) = local_11c;
  *(undefined4 *)(param_1[0xf] + 0xc) = 0;
  FUN_004fde00(*(undefined4 *)(param_1[0xf] + 8));
  param_1[10] = param_1[9];
  param_1[0xb] = param_1[9];
  uVar1 = *(undefined4 *)(param_1[0xf] + 4);
  param_1[0xc] = uVar1;
  param_1[0xd] = uVar1;
LAB_004fcd7f:
  puVar6 = param_1 + 8;
  puVar9 = puVar6;
  puVar11 = local_118;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  FUN_004feaf0();
  uVar1 = param_1[0xf];
  puVar9 = local_118;
  puVar11 = puVar6;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  param_1[2] = *puVar6;
  param_1[0xe] = uVar1;
  *(undefined1 *)(param_1 + 0x10) = 1;
  param_1[0x11] = 0xff7fffff;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)((int)param_1 + 0x4a) = 0xffff;
  *(undefined2 *)(param_1 + 0x13) = 0xffff;
  *(undefined2 *)((int)param_1 + 0x4e) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0x7fff;
  *(undefined2 *)((int)param_1 + 0x52) = 0x8000;
  FUN_00543960(0x20000);
  param_1[5] = (uint)(DAT_0059e440 < (float)param_1[0xb]);
  uVar8 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  param_1[0x41] = *(float *)(&DAT_008ab274 + uVar8 * 4) * _DAT_0059e448;
  FUN_004fd6f0();
  if (((DAT_007c56a0 & 1) != 0) && (DAT_008ab6e4 != 2)) {
    pbVar10 = &DAT_008acfa3;
    pbVar7 = (byte *)(param_1 + 0x71);
    do {
      bVar2 = *pbVar7;
      bVar12 = bVar2 < *pbVar10;
      if (bVar2 != *pbVar10) {
LAB_004fce88:
        iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_004fce8d;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar7[1];
      bVar12 = bVar2 < pbVar10[1];
      if (bVar2 != pbVar10[1]) goto LAB_004fce88;
      pbVar7 = pbVar7 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar2 != 0);
    iVar3 = 0;
LAB_004fce8d:
    if (iVar3 != 0) {
      _strncpy((char *)(param_1 + 0x71),&DAT_008acfa3,0xb);
      *(undefined1 *)((int)param_1 + 0x1cf) = 0;
      FUN_004fc550(1);
      return;
    }
  }
  return;
}


