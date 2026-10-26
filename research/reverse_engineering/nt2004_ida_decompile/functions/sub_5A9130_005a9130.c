void __stdcall sub_5A9130(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v3; // eax
  int v4; // eax

  v1 = (_DWORD *)dword_7E5D58;
  if ( dword_7E5D58 )
  {
    while ( v1 != a1 || v1[2]-- != 1 )
    {
      v1 = (_DWORD *)v1[70];
      if ( !v1 )
        return;
    }
    v3 = v1[69];
    if ( v3 )
      *(_DWORD *)(v3 + 280) = v1[70];
    v4 = v1[70];
    if ( v4 )
      *(_DWORD *)(v4 + 276) = v1[69];
    if ( !v1[69] )
      dword_7E5D58 = v1[70];
    sub_5A88F0(v1);
    sub_5A84B0(v1);
    sub_5BE8AE();
    --dword_7E8D54;
  }
}
