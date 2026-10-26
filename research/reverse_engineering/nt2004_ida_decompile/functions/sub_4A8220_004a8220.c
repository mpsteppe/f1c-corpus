_BYTE *__thiscall sub_4A8220(_BYTE *this, char a2)
{
  int v3; // edi
  int v4; // esi

  if ( this[8] )
  {
    v3 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
    {
      sub_506C70(v3 + 48);
      if ( *(_DWORD *)(v3 + 96) )
        sub_5BE8AE(*(LPVOID *)(v3 + 96));
      if ( *(_DWORD *)(v3 + 88) )
        sub_5BE8AE(*(LPVOID *)(v3 + 88));
      sub_506920(v3 + 48);
      v4 = *(_DWORD *)(v3 + 28);
      while ( v4 )
      {
        v4 = *(_DWORD *)(v4 + 4);
        sub_4A8220(1);
      }
      *(_DWORD *)(v3 + 28) = 0;
      *(_DWORD *)(v3 + 32) = 0;
      *(_DWORD *)(v3 + 36) = 0;
      *(_DWORD *)(v3 + 40) = 0;
      if ( *(_DWORD *)(v3 + 16) )
        sub_5BE8AE(*(LPVOID *)(v3 + 16));
      if ( *(_DWORD *)(v3 + 8) )
        sub_5BE8AE(*(LPVOID *)(v3 + 8));
      if ( *(_DWORD *)v3 )
        sub_5BE8AE(*(LPVOID *)v3);
      sub_5BE8AE((LPVOID)v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
