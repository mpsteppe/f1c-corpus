int __thiscall sub_55BBA0(_DWORD *this)
{
  _DWORD *v2; // esi
  _DWORD *i; // eax
  void *v4; // ecx
  bool v5; // zf

  v2 = (_DWORD *)this[72];
  if ( v2 )
  {
    for ( i = (_DWORD *)v2[8]; i; i = (_DWORD *)v2[8] )
    {
      v4 = v2;
      v5 = v2 == 0;
      v2 = i;
      if ( !v5 )
        FreeWrapper_7bcf(v4);
    }
    FreeWrapper_7bcf(v2);
    this[72] = 0;
  }
  return 0;
}
