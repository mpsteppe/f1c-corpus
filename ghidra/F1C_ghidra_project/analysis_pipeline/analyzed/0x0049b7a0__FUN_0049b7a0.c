// Function: FUN_0049b7a0 @ 0049b7a0
// Size (bytes): 270


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte __fastcall FUN_0049b7a0(undefined4 param_1)

{
  float fVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
  cVar2 = FUN_004f1aa0(param_1);
  if (cVar2 != '\0') {
    bVar3 = __ftol();
    return -((bVar3 & 1) != 0) & 0xf;
  }
  if ((*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) ==
       *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) && (DAT_007c9158 != 0)) {
    iVar4 = __ftol();
    switch(iVar4 % 6) {
    case 0:
      return 1;
    case 1:
    case 5:
      return 2;
    case 2:
    case 4:
      return 4;
    case 3:
      return 8;
    }
  }
  else {
    fVar1 = *(float *)(DAT_007c54e0 + 0x39a0) / *(float *)(DAT_007c54e0 + 0x39a4);
    if (_DAT_0059e824 <= fVar1) {
      if (fVar1 < _DAT_005acaf0) {
        return 1;
      }
      if (_DAT_005acaec <= fVar1) {
        bVar3 = 7;
        if (_DAT_005acae8 <= fVar1) {
          bVar3 = 0xf;
        }
        return bVar3;
      }
      return 3;
    }
  }
  return 0;
}


