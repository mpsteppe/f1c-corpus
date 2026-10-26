char __thiscall sub_587310(int this, _WORD *a2)
{
  _WORD *v3; // esi
  int v4; // eax
  int v5; // ebp
  int v6; // eax
  int v7; // esi
  char result; // al

  v3 = a2 + 1;
  if ( !*a2 )
    return 0;
  v4 = (unsigned __int16)*a2 - 11;
  v5 = v4;
  if ( v4 > 0 && !(unsigned __int8)MemcpyLikeWithRealloc(a2 + 1, v4) )
    return 0;
  v6 = *(_DWORD *)((char *)v3 + v5);
  v7 = (int)v3 + v5 + 4;
  *(_DWORD *)(this + 16) = v6;
  result = 1;
  *(_DWORD *)(this + 20) = *(_DWORD *)v7;
  *(_BYTE *)(this + 24) = *(_BYTE *)(v7 + 4);
  return result;
}
