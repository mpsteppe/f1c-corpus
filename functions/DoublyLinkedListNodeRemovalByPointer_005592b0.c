int __thiscall sub_5592B0(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax

  v3 = (_DWORD *)this[82];
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
    if ( v3 == (_DWORD *)this[82] )
      this[82] = v3[26];
    sub_5574B0((int)v3);
    EmptyStub_7470(v3);
    FreeWrapper_7bcf(v3);
  }
LABEL_12:
  if ( this[81]-- == 1 )
    this[82] = 0;
  return 0;
}
