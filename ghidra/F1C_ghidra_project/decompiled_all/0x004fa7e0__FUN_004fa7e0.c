// Function: FUN_004fa7e0 @ 004fa7e0
// Strings:  [PAUSED, PAUSED]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fa7e0(void)

{
  char *pcVar1;
  char cVar2;
  char extraout_AL;
  undefined3 extraout_var;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  
  cVar2 = FUN_0044f460(0x1d);
  if ((cVar2 != '\0') && (cVar2 = FUN_0044f460(0x21), cVar2 != '\0')) {
    if (DAT_008afcac == 0) {
      uVar5 = 2;
    }
    else {
      uVar5 = 0;
    }
    FUN_004f8f10(uVar5);
  }
  FUN_004f8f50(DAT_008b8dc8);
  cVar2 = FUN_00461db0();
  if ((cVar2 == '\0') && (DAT_008ab6e4 != 2)) {
    cVar2 = FUN_0044f460(0x1d);
    if ((cVar2 != '\0') && (cVar2 = FUN_0044f460(0x22), cVar2 != '\0')) {
      if (_DAT_005d6d70 == _DAT_0059e420) {
        uVar5 = 2;
      }
      else {
        uVar5 = 0;
      }
      FUN_004f9f70(uVar5);
    }
    cVar2 = FUN_0044f460(0x1d);
    if ((cVar2 != '\0') && (cVar2 = FUN_0044f460(0x14), cVar2 != '\0')) {
      if (_DAT_005d6d70 != _DAT_0059e420) goto LAB_004fa8c2;
      uVar5 = 1;
      goto LAB_004fa8c4;
    }
  }
  else {
LAB_004fa8c2:
    uVar5 = 0;
LAB_004fa8c4:
    FUN_004f9f70(uVar5);
  }
  if (DAT_008afe70 != '\0') goto LAB_004fa9eb;
  DAT_008afe70 = '\x01';
  FUN_004f8d70(4,DAT_005d6d64 + -0x30);
  if (DAT_007ce264 == 1) {
    uVar5 = 2;
  }
  else {
    uVar5 = 0;
  }
  FUN_004f8f10(uVar5);
  if (DAT_007cfc68 == 0) {
    uVar5 = 0x1800;
LAB_004fa926:
    FUN_00545d00(0,uVar5);
  }
  else if (DAT_007cfc68 == 1) {
    uVar5 = 0x1000;
    goto LAB_004fa926;
  }
  if (DAT_007cf860 == 0) {
    FUN_00545d00(0,0x100);
LAB_004fa990:
    iVar3 = 0;
    if (0 < DAT_005c329c) {
      do {
        FUN_0054c1b0(0,1,0);
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_005c329c);
    }
LAB_004fa9c2:
    if (DAT_007cf860 < 1) goto LAB_004fa9eb;
  }
  else {
    if (DAT_007cf860 == 1) goto LAB_004fa990;
    if (DAT_007cf860 != 2) goto LAB_004fa9c2;
    iVar3 = 0;
    if (0 < DAT_005c329c) {
      do {
        if (*(int *)((&DAT_007c54f0)[iVar3] + 13000) != 0) {
          FUN_0054c1b0(0,1,0);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_005c329c);
      goto LAB_004fa9c2;
    }
  }
  if ((-1 < DAT_007cfb90) && (DAT_007cfb90 < 2)) {
    FUN_00545d00(0,0x100);
  }
LAB_004fa9eb:
  if (DAT_007ce254 == '\0') {
    FUN_004f9b30(0);
  }
  if ((((DAT_007cc4f4 != 0) && (FUN_00461db0(), extraout_AL == '\0')) && (DAT_008ab6e4 != 2)) &&
     ((DAT_007c56a4 != 7 || (DAT_007ce254 == '\0')))) {
    FUN_0042d210(CONCAT31(extraout_var,DAT_007c56ac == '\0'));
    if (DAT_007c56ac == '\0') {
      FUN_004c8d70();
    }
    else {
      FUN_004c8d60();
    }
  }
  if (DAT_007c56ac != '\0') {
    iVar3 = FUN_00423a00(s_PAUSED_005c35c8,&DAT_005ec4cc);
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = s_PAUSED_005c35c8 + iVar3;
        (&DAT_005ec4cc)[iVar3] = *pcVar1;
        iVar3 = iVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
  }
  DAT_008afe84 = DAT_008afe84 + 1;
  FUN_0053ac70(2,0);
  fVar4 = (float10)FUN_00556730(0);
  _DAT_008afe90 = (double)fVar4;
  _DAT_008afea8 = _DAT_008afea8 + _DAT_008afe90;
  if (DAT_007c56ac == '\0') {
    if (_DAT_005d6d70 == _DAT_0059e420) {
      _DAT_008afea0 = _DAT_008afea0 + _DAT_008afe90;
      _DAT_008afe98 = _DAT_008afe90;
      FUN_00568c60();
      if (_DAT_0059e880 < _DAT_008afe98) {
        _DAT_008afe98 = 0.5;
      }
    }
    else {
      _DAT_008afe98 = _DAT_005d6d70 * _DAT_008afe90;
      if (_DAT_0059e880 < _DAT_008afe98) {
        _DAT_008afe98 = 0.5;
      }
      _DAT_008afea0 = _DAT_008afea0 + _DAT_008afe98;
    }
  }
  else {
    _DAT_008afe98 = 0.0;
  }
  FUN_0053ac70(1,0);
  if (DAT_008afe72 == '\0') {
    return;
  }
  DAT_008afe72 = 0;
  FUN_004cf040();
  FUN_004024f0();
  return;
}


