int __thiscall sub_59D540(_DWORD *this, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)*this;
  if ( !*this )
    return 0;
  while ( !*v2 || *v2 != a2 )
  {
    v2 = (_DWORD *)v2[1];
    if ( !v2 )
      return 0;
  }
  return *v2;
}
