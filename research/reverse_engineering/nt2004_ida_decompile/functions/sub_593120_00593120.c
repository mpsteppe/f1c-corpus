int __thiscall sub_593120(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int result; // eax

  v2 = a2[157];
  v3 = 0;
  if ( v2 )
    *(_DWORD *)(v2 + 632) = a2[158];
  v4 = a2[158];
  if ( v4 )
    *(_DWORD *)(v4 + 628) = a2[157];
  if ( a2 == *(_DWORD **)(dword_7E8E5C + 252) )
    *(_DWORD *)(dword_7E8E5C + 252) = a2[158];
  result = this[156];
  if ( result )
  {
    v3 = this[156];
    for ( result = *(_DWORD *)(result + 632); result; result = *(_DWORD *)(result + 632) )
      v3 = result;
    *(_DWORD *)(v3 + 632) = a2;
  }
  else
  {
    this[156] = a2;
  }
  a2[157] = v3;
  a2[158] = 0;
  a2[155] = this;
  return result;
}
