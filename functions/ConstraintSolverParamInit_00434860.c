int __thiscall sub_434860(_BYTE *this)
{
  int result; // eax

  VtableMethodShutdown();
  result = 0;
  *this = 0;
  this[1] = 1;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 6) = -1;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0x40000000;
  this[2] = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 1078984704;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 1119092736;
  *((_DWORD *)this + 5) = 1117126656;
  *((_DWORD *)this + 13) = 0;
  return result;
}
