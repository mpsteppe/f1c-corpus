char __thiscall sub_57B050(_DWORD *this, int a2)
{
  char result; // al
  int v3; // esi
  int v4; // edx
  int v5; // eax

  result = 0;
  if ( a2 )
  {
    v3 = this[2];
    v4 = 0;
    if ( v3 )
    {
      while ( *(_DWORD *)v3 != a2 )
      {
        v4 = v3;
        v3 = *(_DWORD *)(v3 + 4);
        if ( !v3 )
          return result;
      }
      if ( v3 == this[4] )
        this[4] = *(_DWORD *)(v3 + 4);
      v5 = *(_DWORD *)(v3 + 4);
      if ( v4 )
        *(_DWORD *)(v4 + 4) = v5;
      else
        this[2] = v5;
      if ( this[3] == v3 )
        this[3] = v4;
      --this[5];
      if ( *(_BYTE *)(v3 + 8) )
        FreeWrapper_7bcf(*(LPVOID *)v3);
      FreeWrapper_7bcf((LPVOID)v3);
      return 1;
    }
  }
  return result;
}
