int __thiscall sub_4D3ED0(_DWORD *this)
{
  int v2; // esi
  int v3; // edi
  int v4; // ecx
  int v5; // edi
  int v6; // ecx
  int result; // eax

  sub_52E5C0(this + 37);
  v2 = this[35];
  *(_BYTE *)this = 0;
  *((_BYTE *)this + 1) = 0;
  *((_BYTE *)this + 65) = 0;
  *((_BYTE *)this + 97) = 0;
  this[33] = -190986834;
  this[34] = -190986834;
  if ( v2 )
  {
    sub_4667A0((_DWORD *)(v2 + 72));
    v3 = *(_DWORD *)(v2 + 56);
    while ( v3 )
    {
      v4 = v3;
      v3 = *(_DWORD *)(v3 + 4);
      sub_466750(v4, 1);
    }
    *(_DWORD *)(v2 + 56) = 0;
    *(_DWORD *)(v2 + 60) = 0;
    *(_DWORD *)(v2 + 64) = 0;
    *(_DWORD *)(v2 + 68) = 0;
    v5 = *(_DWORD *)(v2 + 40);
    while ( v5 )
    {
      v6 = v5;
      v5 = *(_DWORD *)(v5 + 4);
      sub_466750(v6, 1);
    }
    *(_DWORD *)(v2 + 40) = 0;
    *(_DWORD *)(v2 + 44) = 0;
    *(_DWORD *)(v2 + 48) = 0;
    *(_DWORD *)(v2 + 52) = 0;
    if ( *(_DWORD *)(v2 + 32) )
      sub_5BE8AE(*(LPVOID *)(v2 + 32));
    if ( *(_DWORD *)(v2 + 24) )
      sub_5BE8AE(*(LPVOID *)(v2 + 24));
    if ( *(_DWORD *)(v2 + 16) )
      sub_5BE8AE(*(LPVOID *)(v2 + 16));
    if ( *(_DWORD *)(v2 + 8) )
      sub_5BE8AE(*(LPVOID *)(v2 + 8));
    if ( *(_DWORD *)v2 )
      sub_5BE8AE(*(LPVOID *)v2);
    result = sub_5BE8AE((LPVOID)v2);
    this[35] = 0;
    this[36] = -190986834;
  }
  else
  {
    result = -190986834;
    this[36] = -190986834;
  }
  return result;
}
