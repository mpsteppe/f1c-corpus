int __thiscall sub_5419D0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int result; // eax

  v2 = a2[109];
  v3 = 0;
  if ( v2 )
    *(_DWORD *)(v2 + 440) = a2[110];
  v4 = a2[110];
  if ( v4 )
    *(_DWORD *)(v4 + 436) = a2[109];
  if ( a2 == *(_DWORD **)(dword_8B8F28 + 248) )
    *(_DWORD *)(dword_8B8F28 + 248) = a2[110];
  result = this[108];
  if ( result )
  {
    v3 = this[108];
    for ( result = *(_DWORD *)(result + 440); result; result = *(_DWORD *)(result + 440) )
      v3 = result;
    *(_DWORD *)(v3 + 440) = a2;
  }
  else
  {
    this[108] = a2;
  }
  a2[109] = v3;
  a2[110] = 0;
  a2[107] = this;
  return result;
}
