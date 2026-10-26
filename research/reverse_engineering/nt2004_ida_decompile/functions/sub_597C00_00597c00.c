void __thiscall sub_597C00(_DWORD *this, int a2)
{
  _DWORD *v3; // esi
  _DWORD *v4; // eax

  v3 = (_DWORD *)this[90];
  if ( v3 )
  {
    v4 = 0;
    while ( *v3 != a2 )
    {
      v4 = v3;
      v3 = (_DWORD *)v3[1];
      if ( !v3 )
        return;
    }
    if ( v4 )
      v4[1] = v3[1];
    else
      this[90] = v3[1];
    nullsub_6(v3);
    sub_5BE8AE();
    --this[89];
  }
}
