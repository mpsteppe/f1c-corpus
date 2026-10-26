int __thiscall sub_5B1240(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax

  v3 = (_DWORD *)this[85];
  if ( v3 )
  {
    while ( v3 != a2 )
    {
      v3 = (_DWORD *)v3[26];
      if ( !v3 )
        goto LABEL_12;
    }
    v4 = v3[25];
    if ( v4 )
      *(_DWORD *)(v4 + 104) = v3[26];
    v5 = v3[26];
    if ( v5 )
      *(_DWORD *)(v5 + 100) = v3[25];
    if ( v3 == (_DWORD *)this[85] )
      this[85] = v3[26];
    sub_5AF360((int)v3);
    j_nullsub_6(v3);
    sub_5BE8AE();
  }
LABEL_12:
  if ( this[84]-- == 1 )
    this[85] = 0;
  return 0;
}
