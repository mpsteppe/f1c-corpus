// Function: FUN_00469fb0 @ 00469fb0
// Strings:  [%s%s%s, %s%s%s, %i:%06.3f, TrackName]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00469fb0(void)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  float10 extraout_ST0;
  float10 fVar9;
  undefined8 uVar10;
  undefined1 local_190;
  undefined2 local_18f;
  undefined1 local_18d;
  int local_18c;
  undefined2 local_188;
  undefined4 local_186 [7];
  undefined2 local_168;
  undefined4 local_166 [7];
  undefined2 local_148;
  undefined4 local_146 [15];
  undefined1 local_109;
  undefined1 local_108 [260];
  
  local_18f = 0;
  local_18d = 0;
  local_190 = DAT_005ea438;
  local_148 = _DAT_005c694c;
  puVar8 = local_146;
  for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  local_168 = _DAT_005c694c;
  puVar8 = local_166;
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  local_188 = _DAT_005c694c;
  puVar8 = local_186;
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  FUN_00489cb0();
  puVar8 = DAT_007d2dc0;
  if (DAT_007d2dc0 == (undefined4 *)0x0) {
    piVar5 = (int *)0x0;
    DAT_007d2dc8 = DAT_007d2dc0;
  }
  else {
    piVar5 = (int *)*DAT_007d2dc0;
    DAT_007d2dc8 = DAT_007d2dc0;
  }
  while (piVar5 != (int *)0x0) {
    if (piVar5 != (int *)0x0) {
      puVar2 = (undefined1 *)*piVar5;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar7 = FUN_00588410(puVar2);
      puVar8 = DAT_007d2dc8;
      if (iVar7 == 0) {
        iVar7 = FUN_004c5840();
        if (iVar7 != 0) {
          pcVar3 = (char *)*piVar5;
          if (pcVar3 == (char *)0x0) {
            pcVar3 = &DAT_005ea438;
          }
          _strncpy((char *)&local_148,pcVar3,0x3f);
          local_109 = 0;
          iVar7 = FUN_005679c0();
          if (iVar7 != 0) {
            pcVar4 = (char *)FUN_00567970();
            pcVar3 = (char *)&local_148;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
              *pcVar3 = cVar1;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
          }
        }
        FUN_0058815f(&local_188,&DAT_005c3280,piVar5[4]);
        iVar7 = __ftol();
        iVar7 = iVar7 / 0x3c;
        fVar9 = extraout_ST0;
        if (0 < iVar7) {
          local_18c = iVar7 * 0x3c;
          fVar9 = extraout_ST0 - (float10)local_18c;
        }
        FUN_0058815f(&local_168,s__i__06_3f_005c6930,iVar7,(double)fVar9);
        puVar8 = DAT_007d2dc8;
      }
    }
    if ((puVar8 == (undefined4 *)0x0) ||
       (puVar8 = (undefined4 *)puVar8[1], DAT_007d2dc8 = puVar8, puVar8 == (undefined4 *)0x0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)*puVar8;
    }
  }
  FUN_004894d0();
  FUN_0058815f(local_108,&DAT_005ea438);
  FUN_00489600(local_108,0,0,0,0);
  uVar10 = CONCAT44(&local_188,&local_190);
  uVar6 = FUN_00487010(1);
  FUN_0058815f(local_108,s__s_s_s_005c6784,uVar6,uVar10);
  FUN_00489600(local_108,0,0,0,0);
  uVar10 = CONCAT44(&local_168,&local_190);
  uVar6 = FUN_00487010(2);
  FUN_0058815f(local_108,s__s_s_s_005c6784,uVar6,uVar10);
  FUN_00489600(local_108,0,0,0,0);
  return;
}


