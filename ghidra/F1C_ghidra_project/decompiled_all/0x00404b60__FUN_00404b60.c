// Function: FUN_00404b60 @ 00404b60
// Strings:  [MAIN MENU]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00404b60(int *param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_14 [5];
  
  puVar4 = (undefined4 *)&stack0xffffffe8;
  if (*(int *)(*param_1 + 0x20) == 0) {
    return;
  }
  if ((DAT_007cd8c0 == 0) ||
     ((iVar3 = FUN_00497980(), iVar3 != 0 &&
      (iVar3 = FUN_00588410(iVar3,s_MAIN_MENU_005be708), iVar3 == 0)))) {
    if (DAT_007c569c != 2) {
      if (DAT_007c569c != 5) {
        return;
      }
      if (*(char *)(*param_1 + 0x14) == '\0') {
        return;
      }
      FUN_004c8650(0xbf800000);
      if (*(char *)(*param_1 + 0x15) != '\0') {
        return;
      }
      FUN_00404970();
      *(undefined1 *)(*param_1 + 0x15) = 1;
      return;
    }
    piVar1 = (int *)*param_1;
    if ((((DAT_007cb25c == *piVar1) && (DAT_007cb260 == piVar1[1])) && (DAT_007cb2fc == piVar1[2]))
       && ((DAT_007cb300 == piVar1[3] && (DAT_007cb304 == piVar1[4])))) {
      fVar2 = (float)_DAT_008afe90;
      if (DAT_0059e440 <= fVar2) {
        if (_DAT_0059e450 < fVar2) {
          fVar2 = _DAT_0059e450;
        }
        piVar1[7] = (int)(fVar2 + (float)piVar1[7]);
      }
      else {
        piVar1[7] = (int)(DAT_0059e440 + (float)piVar1[7]);
      }
    }
    else {
      piVar1[7] = 0;
    }
    puVar5 = (undefined4 *)*param_1;
    for (iVar3 = 5; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar5 = puVar5 + 1;
    }
    if (*(float *)(*param_1 + 0x1c) < *(float *)(*param_1 + 0x18)) {
      return;
    }
    FUN_00404890();
  }
  *(undefined4 *)(*param_1 + 0x1c) = 0;
  return;
}


