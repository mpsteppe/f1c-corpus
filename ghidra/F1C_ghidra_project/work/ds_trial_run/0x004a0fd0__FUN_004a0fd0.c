// Function: FUN_004a0fd0 @ 004a0fd0
// Size (bytes): 474


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a0fd0(void)

{
  char cVar1;
  int iVar2;
  short *psVar3;
  
  if (DAT_007ce25d != '\0') {
    DAT_007ce25d = 0;
    if ((DAT_007c56a4 == 7) && (iVar2 = 0, 0 < DAT_005c329c)) {
      do {
        FUN_004bc330();
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_005c329c);
    }
    cVar1 = FUN_0042bc10();
    if ((cVar1 != '\0') && (*(int *)(DAT_007c54e8 + 13000) == 1)) {
      FUN_004ef5a0(0,0);
    }
    return 4;
  }
  if ((DAT_007ce25e != '\0') || (DAT_007ce260 != '\0')) {
    DAT_007ce25e = 0;
    return 6;
  }
  if (DAT_007ce264 == 1) {
    if (DAT_007ce258 == 1) {
      return 6;
    }
  }
  else {
    FUN_00404b60();
    if (DAT_007ce254 != '\0') {
      DAT_007ce250 = DAT_007ce250 + 1;
      iVar2 = FUN_00485b90();
      if (iVar2 == -1) {
        return 6;
      }
      if (iVar2 == 3) {
        return 6;
      }
      if (iVar2 == 4) {
        return 4;
      }
    }
  }
  if ((DAT_007ce269 == '\0') ||
     (_DAT_007ce26c = _DAT_007ce26c - (float)_DAT_008afe98,
     _DAT_007ce26c < DAT_0059e440 == (_DAT_007ce26c == DAT_0059e440))) {
    if (DAT_007ce258 != 1) {
      if (DAT_007ce258 == 2) {
        DAT_007ce258 = 1;
      }
      goto LAB_004a112f;
    }
  }
  else {
    DAT_007ce269 = '\0';
    _DAT_007ce26c = 0.0;
    DAT_007ce258 = 1;
  }
  if (DAT_007ce264 == 1) {
    DAT_007c569c = 6;
  }
  else {
    FUN_004a0cf0();
  }
LAB_004a112f:
  if ((DAT_007ce254 == '\0') && (iVar2 = 0, 0 < DAT_007cb218)) {
    psVar3 = &DAT_007cb21c;
    do {
      if (*psVar3 == 1) {
        cVar1 = FUN_00404f00();
        if (cVar1 == '\0') {
          DAT_007ce258 = 1;
        }
        else {
          DAT_007c569c = 6;
          FUN_00404f30();
        }
      }
      iVar2 = iVar2 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar2 < DAT_007cb218);
  }
  FUN_004a0cb0();
  return DAT_007c569c;
}


