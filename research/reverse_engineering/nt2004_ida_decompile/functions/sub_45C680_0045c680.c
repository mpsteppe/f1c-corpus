int __thiscall sub_45C680(_DWORD *this)
{
  _DWORD *v1; // esi

  v1 = this + 1;
  *this = &off_5D640C;
  sub_506C70(this + 1);
  if ( v1[12] )
    sub_5BE8AE((LPVOID)v1[12]);
  if ( v1[10] )
    sub_5BE8AE((LPVOID)v1[10]);
  return sub_506920(v1);
}
