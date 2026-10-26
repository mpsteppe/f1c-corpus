int __thiscall sub_553C00(_DWORD *this, int a2)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // eax
  int v4; // edx

  v2 = (_DWORD *)this[84];
  v3 = (_DWORD *)*v2;
  v4 = 0;
  if ( (_DWORD *)*v2 == v2 )
    return 0;
  while ( v4 != a2 )
  {
    v3 = (_DWORD *)*v3;
    ++v4;
    if ( v3 == v2 )
      return 0;
  }
  return v3[2];
}
