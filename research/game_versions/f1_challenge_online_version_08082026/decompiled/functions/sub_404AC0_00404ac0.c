int __thiscall sub_404AC0(int *this)
{
  int v1; // ebp
  int v2; // esi
  _DWORD *v3; // edi
  bool v4; // zf
  int result; // eax

  v1 = *this;
  if ( *this )
  {
    v2 = *(_DWORD *)(v1 + 64);
    while ( v2 )
    {
      v3 = (_DWORD *)v2;
      v4 = *(_BYTE *)(v2 + 8) == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && *v3 )
        sub_404F70(1);
      sub_587BCF(v3);
    }
    *(_DWORD *)(v1 + 64) = 0;
    *(_DWORD *)(v1 + 68) = 0;
    *(_DWORD *)(v1 + 72) = 0;
    *(_DWORD *)(v1 + 76) = 0;
    if ( *(_DWORD *)(v1 + 56) )
      sub_587BCF(*(LPVOID *)(v1 + 56));
    if ( *(_DWORD *)(v1 + 48) )
      sub_587BCF(*(LPVOID *)(v1 + 48));
    if ( *(_DWORD *)(v1 + 40) )
      sub_587BCF(*(LPVOID *)(v1 + 40));
    return sub_587BCF((LPVOID)v1);
  }
  return result;
}
