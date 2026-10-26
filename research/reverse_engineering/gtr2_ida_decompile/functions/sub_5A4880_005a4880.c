_BYTE *__thiscall sub_5A4880(_BYTE *this)
{
  char *v2; // ecx

  v2 = this + 8;
  *v2 = 0;
  *((_DWORD *)v2 + 1) = 0;
  v2[12] = 0;
  *((_DWORD *)v2 + 2) = -1;
  sub_5A4540();
  this[24] = 0;
  *((_DWORD *)this + 7) = 0;
  this[36] = 0;
  *((_DWORD *)this + 8) = -1;
  sub_5A4540();
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  return this;
}
