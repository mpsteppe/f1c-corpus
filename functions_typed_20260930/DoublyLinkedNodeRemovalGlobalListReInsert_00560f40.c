int __thiscall sub_560F40(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int result; // eax
  int v4; // ecx
  int i; // ecx

  v2 = a2[12];
  if ( v2 )
    *(_DWORD *)(v2 + 52) = a2[13];
  result = a2[13];
  if ( result )
    *(_DWORD *)(result + 48) = a2[12];
  if ( (_DWORD *)this[11] == a2 )
  {
    result = a2[13];
    this[11] = result;
    if ( result )
      *(_DWORD *)(result + 48) = 0;
  }
  if ( dword_8B8F28 )
  {
    v4 = *(_DWORD *)(dword_8B8F28 + 348);
    result = 0;
    if ( v4 )
    {
      result = *(_DWORD *)(dword_8B8F28 + 348);
      for ( i = *(_DWORD *)(v4 + 52); i; i = *(_DWORD *)(i + 52) )
        result = i;
      *(_DWORD *)(result + 52) = a2;
    }
    else
    {
      *(_DWORD *)(dword_8B8F28 + 348) = a2;
    }
    a2[12] = result;
    a2[13] = 0;
  }
  a2[9] &= ~4u;
  return result;
}

