// Function: FUN_004d4580 @ 004d4580
// Size (bytes): 125


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d4580(int param_1)

{
  bool bVar1;
  bool bVar2;
  double dVar3;
  char cVar4;
  int iVar5;
  undefined4 unaff_ESI;
  float10 fVar6;
  
  if (*(int *)(param_1 + 0xa4) != 0) {
    FUN_004d0b20((float)_DAT_008afe98);
  }
  if (*(int *)(param_1 + 0xa8) != 0) {
    if (DAT_008ab6e4 == 2) {
      fVar6 = (float10)FUN_004b9ce0();
    }
    else {
      fVar6 = (float10)_DAT_008afea0;
    }
    FUN_00448330((float)fVar6);
  }
  if ((DAT_007c56ac != '\0') || (FUN_004d2e50(), (DAT_007c56a0 & 1) == 0)) {
    return;
  }
  if (DAT_007c56a4 < 0) {
    return;
  }
  if (DAT_007c56a4 < 7) {
    dVar3 = ((double)*(float *)(param_1 + 0xb4) + (double)*(float *)(param_1 + 0xb0)) *
            (double)_DAT_0059e450;
    if (dVar3 < _DAT_008afea0 != (dVar3 == _DAT_008afea0)) {
      *(undefined1 *)(param_1 + 0xc0) = 1;
    }
    FUN_004d1d80();
    return;
  }
  if (DAT_007c56a4 != 7) {
    return;
  }
  cVar4 = FUN_0044f460(0x39);
  if ((cVar4 != '\0') && (DAT_007ce254 == '\0')) {
    *(undefined1 *)(param_1 + 0xc1) = 1;
  }
  switch(DAT_007c56a8) {
  case 0:
  case 1:
    if (*(char *)(param_1 + 0xc1) == '\0') {
      return;
    }
    FUN_0044f0e0(0x39,0x3f800000);
    FUN_0045bde0(s_00_01_005d41b4,0);
    if (DAT_007ced8c != 0) {
      FUN_004d2260(2,(float)_DAT_008afea0 + _DAT_0059e80c);
      return;
    }
    break;
  case 2:
    if ((*(char *)(param_1 + 0xc1) == '\0') || (*(float *)(param_1 + 0x98) <= _DAT_0059e8a4)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    cVar4 = FUN_0040dbc0();
    if ((cVar4 != '\0') ||
       (_DAT_008afea0 <=
        ((double)*(float *)(param_1 + 0xb4) - (double)_DAT_0059e80c) + (double)_DAT_0059e8a4)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((!bVar1) && (!bVar2)) {
      return;
    }
    FUN_0044f0e0(0x39,0x3f800000);
    FUN_0040e170();
    break;
  case 3:
    cVar4 = FUN_004d2170();
    if (cVar4 == '\0') {
      return;
    }
    FUN_004d2300();
    return;
  case 4:
    if (*(int *)(param_1 + 0xd8) != 0x7f7fffff) {
      return;
    }
    goto LAB_004d3618;
  case 5:
  case 6:
  case 7:
  case 8:
    dVar3 = ((double)*(float *)(param_1 + 0xb4) + (double)*(float *)(param_1 + 0xb0)) *
            (double)_DAT_0059e450;
    if (dVar3 < _DAT_008afea0 != (dVar3 == _DAT_008afea0)) {
      *(undefined1 *)(param_1 + 0xc0) = 1;
    }
    iVar5 = FUN_00461cd0(unaff_ESI);
    if (((iVar5 == 0) && (DAT_008ab6e4 != 2)) && (DAT_007cc520 != 0)) {
      FUN_004a0da0();
    }
    FUN_004d1d80();
    return;
  default:
    return;
  }
  if (DAT_007cee88 != 0) {
    FUN_004d2260(3,(float)_DAT_008afea0);
    return;
  }
LAB_004d3618:
  FUN_004d2300();
  return;
}


