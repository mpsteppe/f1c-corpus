char __thiscall sub_4ED9A0(_BYTE *this)
{
  char result; // al
  int v2; // ebx
  int v3; // esi
  LPVOID **v4; // edi
  char v5; // al
  LPVOID *v6; // ebp
  int v7; // esi
  LPVOID **v8; // ebp
  char v9; // al
  LPVOID *v10; // edi

  result = this[8];
  if ( result )
  {
    v2 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
    {
      v3 = *(_DWORD *)(v2 + 24);
      while ( v3 )
      {
        v4 = (LPVOID **)v3;
        v5 = *(_BYTE *)(v3 + 8);
        v3 = *(_DWORD *)(v3 + 4);
        if ( v5 )
        {
          v6 = *v4;
          if ( *v4 )
          {
            sub_40D5B0(*v4);
            sub_5BE8AE(v6);
          }
        }
        sub_5BE8AE(v4);
      }
      *(_DWORD *)(v2 + 24) = 0;
      *(_DWORD *)(v2 + 28) = 0;
      *(_DWORD *)(v2 + 32) = 0;
      *(_DWORD *)(v2 + 36) = 0;
      v7 = *(_DWORD *)(v2 + 8);
      while ( v7 )
      {
        v8 = (LPVOID **)v7;
        v9 = *(_BYTE *)(v7 + 8);
        v7 = *(_DWORD *)(v7 + 4);
        if ( v9 )
        {
          v10 = *v8;
          if ( *v8 )
          {
            if ( *v10 )
              sub_5BE8AE(*v10);
            sub_5BE8AE(v10);
          }
        }
        sub_5BE8AE(v8);
      }
      *(_DWORD *)(v2 + 8) = 0;
      *(_DWORD *)(v2 + 12) = 0;
      *(_DWORD *)(v2 + 16) = 0;
      *(_DWORD *)(v2 + 20) = 0;
      if ( *(_DWORD *)v2 )
        sub_5BE8AE(*(LPVOID *)v2);
      return sub_5BE8AE((LPVOID)v2);
    }
  }
  return result;
}
