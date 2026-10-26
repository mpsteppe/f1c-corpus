char __thiscall sub_4A8310(_BYTE *this)
{
  char result; // al
  int v2; // edi
  _DWORD *v3; // esi
  void *v4; // ebp

  result = this[8];
  if ( result )
  {
    v2 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
    {
      sub_506C70(v2 + 48);
      if ( *(_DWORD *)(v2 + 96) )
        sub_5BE8AE(*(LPVOID *)(v2 + 96));
      if ( *(_DWORD *)(v2 + 88) )
        sub_5BE8AE(*(LPVOID *)(v2 + 88));
      sub_506920(v2 + 48);
      v3 = *(_DWORD **)(v2 + 28);
      while ( v3 )
      {
        v4 = v3;
        v3 = (_DWORD *)v3[1];
        sub_4A8310(v4);
        sub_5BE8AE(v4);
      }
      *(_DWORD *)(v2 + 28) = 0;
      *(_DWORD *)(v2 + 32) = 0;
      *(_DWORD *)(v2 + 36) = 0;
      *(_DWORD *)(v2 + 40) = 0;
      if ( *(_DWORD *)(v2 + 16) )
        sub_5BE8AE(*(LPVOID *)(v2 + 16));
      if ( *(_DWORD *)(v2 + 8) )
        sub_5BE8AE(*(LPVOID *)(v2 + 8));
      if ( *(_DWORD *)v2 )
        sub_5BE8AE(*(LPVOID *)v2);
      return sub_5BE8AE((LPVOID)v2);
    }
  }
  return result;
}
