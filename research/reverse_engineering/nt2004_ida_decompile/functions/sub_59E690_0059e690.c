int __thiscall sub_59E690(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v4; // edi
  int v6; // eax
  _DWORD *v7; // ecx
  int result; // eax
  int v9; // esi

  v3 = a2[18];
  v4 = 0;
  if ( v3 )
    *(_DWORD *)(v3 + 76) = a2[19];
  v6 = a2[19];
  if ( v6 )
    *(_DWORD *)(v6 + 72) = a2[18];
  v7 = (_DWORD *)dword_7E8E5C;
  if ( a2 == *(_DWORD **)(dword_7E8E5C + 268) )
  {
    *(_DWORD *)(dword_7E8E5C + 268) = a2[19];
    v7 = (_DWORD *)dword_7E8E5C;
  }
  if ( a3 )
    sub_596EC0(v7, (int)a2);
  result = this[17];
  if ( result )
  {
    v4 = this[17];
    for ( result = *(_DWORD *)(result + 76); result; result = *(_DWORD *)(result + 76) )
      v4 = result;
    *(_DWORD *)(v4 + 76) = a2;
  }
  else
  {
    this[17] = a2;
  }
  a2[18] = v4;
  a2[19] = 0;
  a2[16] = this;
  v9 = a2[140];
  if ( v9 )
  {
    if ( this[140] )
      return sub_5B87A0(v9);
  }
  return result;
}
