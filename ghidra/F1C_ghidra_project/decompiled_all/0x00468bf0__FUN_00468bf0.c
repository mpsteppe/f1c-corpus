// Function: FUN_00468bf0 @ 00468bf0
// Strings:  [%s%s%s, %s%s%s, %s%s%s, %i:%06.3f, GrandPrixName]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00468bf0(int param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  int *piVar10;
  bool bVar11;
  float10 extraout_ST0;
  float10 fVar12;
  undefined8 uVar13;
  undefined2 local_188;
  undefined4 local_186 [7];
  undefined2 local_168;
  undefined4 local_166 [7];
  undefined2 local_148;
  undefined4 local_146 [15];
  undefined1 local_109;
  undefined2 local_108;
  undefined4 local_106 [64];
  
  local_108 = DAT_007cd8bc;
  puVar8 = local_106;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  local_148 = _DAT_005c694c;
  puVar8 = local_146;
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  local_188 = _DAT_005c694c;
  puVar8 = local_186;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  local_168 = _DAT_005c694c;
  puVar8 = local_166;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  pbVar9 = *(byte **)(param_1 + 0x17c);
  if (pbVar9 == (byte *)0x0) {
    pbVar9 = &DAT_005ea438;
  }
  pbVar3 = DAT_007ce668;
  if (DAT_007ce668 == (byte *)0x0) {
    pbVar3 = &DAT_005ea438;
  }
  do {
    bVar1 = *pbVar3;
    bVar11 = bVar1 < *pbVar9;
    if (bVar1 != *pbVar9) {
LAB_00468cb4:
      iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_00468cb9;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar11 = bVar1 < pbVar9[1];
    if (bVar1 != pbVar9[1]) goto LAB_00468cb4;
    pbVar3 = pbVar3 + 2;
    pbVar9 = pbVar9 + 2;
  } while (bVar1 != 0);
  iVar6 = 0;
LAB_00468cb9:
  if (iVar6 != 0) {
    FUN_00566650();
  }
  DAT_007d2dc8 = DAT_007d2dc0;
  if (DAT_007d2dc0 == (undefined4 *)0x0) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = (int *)*DAT_007d2dc0;
  }
  bVar11 = true;
  while ((piVar10 != (int *)0x0 || (bVar11))) {
    bVar11 = false;
    if (piVar10 != (int *)0x0) {
      iVar6 = FUN_004c5840();
      if (iVar6 != 0) {
        iVar6 = FUN_005679c0();
        if (iVar6 == 0) {
          pcVar7 = (char *)*piVar10;
          if (pcVar7 == (char *)0x0) {
            pcVar7 = &DAT_005ea438;
          }
          _strncpy((char *)&local_148,pcVar7,0x3f);
          local_109 = 0;
        }
        else {
          pcVar4 = (char *)FUN_00567970();
          pcVar7 = (char *)&local_148;
          do {
            cVar2 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            *pcVar7 = cVar2;
            pcVar7 = pcVar7 + 1;
          } while (cVar2 != '\0');
        }
      }
      FUN_0058815f(&local_168,&DAT_005c3280,piVar10[4]);
      iVar6 = __ftol();
      iVar6 = iVar6 / 0x3c;
      fVar12 = extraout_ST0;
      if (0 < iVar6) {
        fVar12 = extraout_ST0 - (float10)(iVar6 * 0x3c);
      }
      FUN_0058815f(&local_188,s__i__06_3f_005c6930,iVar6,(double)fVar12);
    }
    uVar13 = CONCAT44(&local_148,&DAT_005c692c);
    uVar5 = FUN_00487010(10);
    FUN_0058815f(&local_108,s__s_s_s_005c6784,uVar5,uVar13);
    FUN_00489600(&local_108,0,0,0,0);
    uVar13 = CONCAT44(&local_168,&DAT_005c692c);
    uVar5 = FUN_00487010(0xb);
    FUN_0058815f(&local_108,s__s_s_s_005c6784,uVar5,uVar13);
    FUN_00489600(&local_108,0,0,0,0);
    uVar13 = CONCAT44(&local_188,&DAT_005c692c);
    uVar5 = FUN_00487010(0xc);
    FUN_0058815f(&local_108,s__s_s_s_005c6784,uVar5,uVar13);
    FUN_00489600(&local_108,0,0,0,0);
    FUN_0058815f(&local_108);
    FUN_00489600(&local_108,0,0,0,0);
    if ((DAT_007d2dc8 == (undefined4 *)0x0) ||
       (DAT_007d2dc8 = (undefined4 *)DAT_007d2dc8[1], DAT_007d2dc8 == (undefined4 *)0x0)) {
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = (int *)*DAT_007d2dc8;
    }
  }
  return;
}


