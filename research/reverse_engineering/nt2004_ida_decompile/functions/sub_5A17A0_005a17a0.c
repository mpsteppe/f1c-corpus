int __thiscall sub_5A17A0(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, _DWORD *a8)
{
  if ( a2 <= 15 )
  {
    if ( (*(_BYTE *)this & 2) != 0 )
    {
      if ( a3 )
        *a3 = *(_DWORD *)(28 * a2 + this[6]);
      if ( a4 )
        *a4 = *(_DWORD *)(28 * a2 + this[6] + 4);
      if ( a5 )
        *a5 = *(_DWORD *)(28 * a2 + this[6] + 8);
      if ( a6 )
        *a6 = *(_DWORD *)(28 * a2 + this[6] + 20);
      if ( a7 )
        *a7 = *(_DWORD *)(28 * a2 + this[6] + 24);
      if ( a8 )
        *a8 = *(_DWORD *)(28 * a2 + this[6] + 16);
      return 0;
    }
    else
    {
      sub_591C60((int)this, -1, aWrongVertexFor);
      return -1;
    }
  }
  else
  {
    sub_591C60((int)this, -1, aTooManyVertice);
    return -1;
  }
}
