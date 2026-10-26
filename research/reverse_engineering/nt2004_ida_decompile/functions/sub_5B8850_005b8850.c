int __thiscall sub_5B8850(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // edi
  int i; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // ebx

  v2 = a2[13];
  if ( v2 )
    *(_DWORD *)(v2 + 56) = a2[14];
  v3 = a2[14];
  if ( v3 )
    *(_DWORD *)(v3 + 52) = a2[13];
  if ( (_DWORD *)this[12] == a2 )
  {
    v4 = a2[14];
    this[12] = v4;
    if ( v4 )
      *(_DWORD *)(v4 + 52) = 0;
  }
  a2[12] = 0;
  a2[13] = 0;
  a2[14] = 0;
  result = dword_7E8E5C;
  if ( dword_7E8E5C )
  {
    v6 = *(_DWORD *)(dword_7E8E5C + 360);
    for ( i = *(_DWORD *)(v6 + 4); i; i = *(_DWORD *)(i + 4) )
      v6 = i;
    v8 = operator new(8u);
    v9 = v8;
    if ( v8 )
    {
      sub_5918B0(v8);
      *v9 = 0;
      v9[1] = 0;
    }
    else
    {
      v9 = 0;
    }
    *(_DWORD *)(v6 + 4) = v9;
    *v9 = a2;
    result = dword_7E8E5C;
    ++*(_DWORD *)(dword_7E8E5C + 356);
  }
  a2[10] &= ~4u;
  return result;
}
