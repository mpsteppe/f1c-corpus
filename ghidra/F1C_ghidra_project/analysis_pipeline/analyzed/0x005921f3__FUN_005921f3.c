// Function: FUN_005921f3 @ 005921f3
// Size (bytes): 647


void FUN_005921f3(void)

{
  char cVar1;
  char cVar2;
  char *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  char *_Source;
  int local_8;
  
  FUN_0058dfea(0xc);
  DAT_005e7800 = 0xffffffff;
  DAT_005e77f0 = 0xffffffff;
  DAT_008d3fc0 = 0;
  _Str1 = (char *)FUN_00596d81(&DAT_005b9620);
  if (_Str1 == (char *)0x0) {
    FUN_0058e04b(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_008d3fc8);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_005e7758 = DAT_008d3fc8 * 0x3c;
    DAT_008d3fc0 = 1;
    if (DAT_008d400e != 0) {
      DAT_005e7758 = DAT_005e7758 + DAT_008d401c * 0x3c;
    }
    if ((DAT_008d4062 == 0) || (DAT_008d4070 == 0)) {
      DAT_005e775c = 0;
      DAT_005e7760 = 0;
    }
    else {
      DAT_005e775c = 1;
      DAT_005e7760 = (DAT_008d4070 - DAT_008d401c) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_008d3f48,0x220,(LPCWSTR)&DAT_008d3fcc,-1,PTR_DAT_005e77e4,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_005e77e4 = 0;
    }
    else {
      PTR_DAT_005e77e4[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_008d3f48,0x220,(LPCWSTR)&DAT_008d4020,-1,PTR_DAT_005e77e8,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_005e77e8[0x3f] = 0;
      return;
    }
LAB_00592464:
    *PTR_DAT_005e77e8 = 0;
  }
  else {
    if ((*_Str1 != '\0') &&
       ((DAT_008d4074 == (char *)0x0 || (iVar4 = _strcmp(_Str1,DAT_008d4074), iVar4 != 0)))) {
      FUN_0058aa6f(DAT_008d4074);
      sVar5 = _strlen(_Str1);
      DAT_008d4074 = _malloc(sVar5 + 1);
      if (DAT_008d4074 != (char *)0x0) {
        FUN_0058fca0(DAT_008d4074,_Str1);
        FUN_0058e04b(0xc);
        _strncpy(PTR_DAT_005e77e4,_Str1,3);
        _Source = _Str1 + 3;
        PTR_DAT_005e77e4[3] = 0;
        cVar1 = *_Source;
        if (cVar1 == '-') {
          _Source = _Str1 + 4;
        }
        iVar4 = FUN_00587ece(_Source);
        DAT_005e7758 = iVar4 * 0xe10;
        for (; (cVar2 = *_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
            _Source = _Source + 1) {
        }
        if (*_Source == ':') {
          _Source = _Source + 1;
          iVar4 = FUN_00587ece(_Source);
          DAT_005e7758 = DAT_005e7758 + iVar4 * 0x3c;
          for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {
          }
          if (*_Source == ':') {
            _Source = _Source + 1;
            iVar4 = FUN_00587ece(_Source);
            DAT_005e7758 = DAT_005e7758 + iVar4;
            for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_005e7758 = -DAT_005e7758;
        }
        DAT_005e775c = (int)*_Source;
        if (DAT_005e775c != 0) {
          _strncpy(PTR_DAT_005e77e8,_Source,3);
          PTR_DAT_005e77e8[3] = 0;
          return;
        }
        goto LAB_00592464;
      }
    }
    FUN_0058e04b(0xc);
  }
  return;
}


