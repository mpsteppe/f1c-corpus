// Function: FUN_00469900 @ 00469900
// Strings:  [Ph<i\, Ph<i\, %s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00469900(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  int *piVar9;
  bool bVar10;
  float10 extraout_ST0;
  float10 fVar11;
  float10 extraout_ST0_00;
  undefined8 uVar12;
  undefined1 local_190;
  undefined2 local_18f;
  undefined1 local_18d;
  int local_18c;
  ushort local_188;
  undefined4 local_186 [7];
  ushort local_168;
  undefined4 local_166 [7];
  ushort local_148;
  undefined4 local_146 [15];
  undefined1 local_109;
  undefined1 local_108 [260];
  
  local_18f = 0;
  local_190 = DAT_005ea438;
  local_18d = 0;
  local_148 = _DAT_005c694c;
  puVar7 = local_146;
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  local_168 = _DAT_005c694c;
  puVar7 = local_166;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  local_188 = _DAT_005c694c;
  puVar7 = local_186;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  pbVar8 = *(byte **)(param_1 + 0x180);
  if (pbVar8 == (byte *)0x0) {
    pbVar8 = &DAT_005ea438;
  }
  pbVar2 = DAT_007ce668;
  if (DAT_007ce668 == (byte *)0x0) {
    pbVar2 = &DAT_005ea438;
  }
  do {
    bVar1 = *pbVar2;
    bVar10 = bVar1 < *pbVar8;
    if (bVar1 != *pbVar8) {
LAB_004699b5:
      iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      goto LAB_004699ba;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar10 = bVar1 < pbVar8[1];
    if (bVar1 != pbVar8[1]) goto LAB_004699b5;
    pbVar2 = pbVar2 + 2;
    pbVar8 = pbVar8 + 2;
  } while (bVar1 != 0);
  iVar6 = 0;
LAB_004699ba:
  if (iVar6 != 0) {
    FUN_00566650();
  }
  DAT_007d2dc8 = DAT_007d2dc0;
  if ((DAT_007d2dc0 != (undefined4 *)0x0) && (piVar9 = (int *)*DAT_007d2dc0, piVar9 != (int *)0x0))
  {
    puVar3 = (undefined1 *)*piVar9;
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    iVar6 = FUN_004c58a0(&local_148,0x40,s_GrandPrixName_005c693c,puVar3);
    if (iVar6 != 0) {
      pcVar4 = (char *)*piVar9;
      if (pcVar4 == (char *)0x0) {
        pcVar4 = &DAT_005ea438;
      }
      _strncpy((char *)&local_148,pcVar4,0x3f);
      local_109 = 0;
    }
    FUN_0058815f(&local_188,&DAT_005c3280,piVar9[4]);
    iVar6 = __ftol();
    iVar6 = iVar6 / 0x3c;
    fVar11 = extraout_ST0;
    if (0 < iVar6) {
      local_18c = iVar6 * 0x3c;
      fVar11 = extraout_ST0 - (float10)local_18c;
    }
    FUN_0058815f(&local_168,s__i__06_3f_005c6930,iVar6,(double)fVar11);
  }
  FUN_004894d0();
  uVar12 = CONCAT44(&local_148,&local_190);
  uVar5 = FUN_00487010(0);
  FUN_0058815f(local_108,s__s_s_s_005c6784,uVar5,uVar12);
  FUN_00489600(local_108,0,0,0,0);
  uVar12 = CONCAT44(&local_188,&local_190);
  uVar5 = FUN_00487010(1);
  FUN_0058815f(local_108,s__s_s_s_005c6784,uVar5,uVar12);
  FUN_00489600(local_108,0,0,0,0);
  uVar12 = CONCAT44(&local_168,&local_190);
  uVar5 = FUN_00487010(2);
  FUN_0058815f(local_108,s__s_s_s_005c6784,uVar5,uVar12);
  FUN_00489600(local_108,0,0,0,0);
  if ((DAT_007d2dc8 == (undefined4 *)0x0) ||
     (DAT_007d2dc8 = (undefined4 *)DAT_007d2dc8[1], DAT_007d2dc8 == (undefined4 *)0x0)) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)*DAT_007d2dc8;
  }
  while (piVar9 != (int *)0x0) {
    local_148 = local_148 & 0xff00;
    puVar3 = (undefined1 *)*piVar9;
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    iVar6 = FUN_004c58a0(&local_148,0x40,s_GrandPrixName_005c693c,puVar3);
    if (iVar6 != 0) {
      pcVar4 = (char *)*piVar9;
      if (pcVar4 == (char *)0x0) {
        pcVar4 = &DAT_005ea438;
      }
      _strncpy((char *)&local_148,pcVar4,0x3f);
      local_109 = 0;
    }
    FUN_0058815f(&local_188,&DAT_005c3280,piVar9[4]);
    iVar6 = __ftol();
    iVar6 = iVar6 / 0x3c;
    fVar11 = extraout_ST0_00;
    if (0 < iVar6) {
      local_18c = iVar6 * 0x3c;
      fVar11 = extraout_ST0_00 - (float10)local_18c;
    }
    FUN_0058815f(&local_168,s__i__06_3f_005c6930,iVar6,(double)fVar11);
    FUN_0058815f(local_108);
    FUN_00489600(local_108,0,0,0,0);
    uVar12 = CONCAT44(&local_148,&local_190);
    uVar5 = FUN_00487010(0);
    FUN_0058815f(local_108,s__s_s_s_005c6784,uVar5,uVar12);
    FUN_00489600(local_108,0,0,0,0);
    uVar12 = CONCAT44(&local_188,&local_190);
    uVar5 = FUN_00487010(1);
    FUN_0058815f(local_108,s__s_s_s_005c6784,uVar5,uVar12);
    FUN_00489600(local_108,0,0,0,0);
    uVar12 = CONCAT44(&local_168,&local_190);
    uVar5 = FUN_00487010(2);
    FUN_0058815f(local_108,s__s_s_s_005c6784,uVar5,uVar12);
    FUN_00489600(local_108,0,0,0,0);
    if ((DAT_007d2dc8 == (undefined4 *)0x0) ||
       (DAT_007d2dc8 = (undefined4 *)DAT_007d2dc8[1], DAT_007d2dc8 == (undefined4 *)0x0)) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)*DAT_007d2dc8;
    }
  }
  return;
}


