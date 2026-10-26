_DWORD *__thiscall sub_4B8090(_DWORD *this, char a2)
{
  _DWORD *v3; // esi

  v3 = this + 1;
  *this = &off_5EA3B4;
  sub_506C70(this + 1);
  if ( v3[12] )
    sub_5BE8AE((LPVOID)v3[12]);
  if ( v3[10] )
    sub_5BE8AE((LPVOID)v3[10]);
  sub_506920(v3);
  *this = &off_5EA3C8;
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
