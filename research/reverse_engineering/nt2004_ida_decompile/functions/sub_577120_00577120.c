_DWORD *__thiscall sub_577120(_DWORD *this, int a2)
{
  sub_577520(a2 + 4);
  this[4] = *(_DWORD *)(a2 + 16);
  this[5] = *(_DWORD *)(a2 + 20);
  *((_BYTE *)this + 24) = *(_BYTE *)(a2 + 24);
  *((_BYTE *)this + 25) = 0;
  *this = &off_5F6468;
  return this;
}
