// f1c  0x00491d30  size=128
char __thiscall sub_491D30(int *this, int a2, char a3)
{
  char result; // al
  int v4; // esi
  int v5; // edx
  int v6; // eax

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
        if ( *(_DWORD *)v4 )
          sub_587BCF(*(LPVOID *)v4);
      }
      sub_587BCF((LPVOID)v4);
      return 1;
    }
  }
  return result;
}
