char *__thiscall sub_4FC9C0(char *this)
{
  _DWORD *v2; // edi

  v2 = this + 32;
  sub_4FC850((_DWORD *)this + 8);
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  MultiFieldReset(this + 264);
  *(_DWORD *)this = 1065353216;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *v2 = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  this[64] = 0;
  *((_DWORD *)this + 17) = 0;
  *((_WORD *)this + 36) = 0;
  *((_WORD *)this + 37) = -1;
  *((_WORD *)this + 38) = -1;
  *((_WORD *)this + 39) = 0;
  *((_WORD *)this + 40) = 0x7FFF;
  *((_WORD *)this + 41) = 0x8000;
  RangeInterpolationTable(this);
  return this;
}
