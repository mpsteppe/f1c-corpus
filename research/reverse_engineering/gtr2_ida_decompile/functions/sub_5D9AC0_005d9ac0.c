char __thiscall sub_5D9AC0(int *this, int a2, char a3)
{
  char result; // al
  int v4; // esi
  int v5; // edx
  int v6; // edi
  void *v7; // edi

  result = 0;
  if ( a2 )
  {
    v4 = *this;
    v5 = 0;
    if ( *this )
    {
      while ( *(_DWORD *)v4 != a2 )
      {
        v5 = v4;
        v4 = *(_DWORD *)(v4 + 4);
        if ( !v4 )
          return result;
      }
      if ( v4 == this[2] )
        this[2] = *(_DWORD *)(v4 + 4);
      v6 = *(_DWORD *)(v4 + 4);
      if ( v5 )
        *(_DWORD *)(v5 + 4) = v6;
      else
        *this = v6;
      if ( this[1] == v4 )
        this[1] = v5;
      --this[3];
      if ( !a3 )
        *(_BYTE *)(v4 + 8) = 0;
      if ( *(_BYTE *)(v4 + 8) )
      {
        v7 = *(void **)v4;
        if ( *(_DWORD *)v4 )
        {
          sub_5EE130(*(void **)v4);
          j__free(v7);
        }
      }
      j__free((void *)v4);
      return 1;
    }
  }
  return result;
}
