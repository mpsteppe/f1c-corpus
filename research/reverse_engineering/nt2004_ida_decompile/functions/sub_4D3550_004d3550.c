void __cdecl sub_4D3550()
{
  int v0; // esi
  LPVOID *v1; // edi
  bool v2; // zf
  int v3; // esi
  LPVOID **v4; // edi
  LPVOID *v5; // ebp

  if ( (byte_7D5DA0 & 1) == 0 )
  {
    v0 = dword_7D5DC0;
    byte_7D5DA0 |= 1u;
    while ( v0 )
    {
      v1 = (LPVOID *)v0;
      v2 = *(_BYTE *)(v0 + 8) == 0;
      v0 = *(_DWORD *)(v0 + 4);
      if ( !v2 )
        sub_5BE8AE(*v1);
      sub_5BE8AE(v1);
    }
    v3 = dword_7D5DB0;
    dword_7D5DC0 = 0;
    dword_7D5DC4 = 0;
    dword_7D5DC8 = 0;
    dword_7D5DCC = 0;
    while ( v3 )
    {
      v4 = (LPVOID **)v3;
      v2 = *(_BYTE *)(v3 + 8) == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v2 )
      {
        v5 = *v4;
        if ( *v4 )
        {
          sub_5BE8AE(*v5);
          sub_5BE8AE(v5);
        }
      }
      sub_5BE8AE(v4);
    }
    dword_7D5DB0 = 0;
    dword_7D5DB4 = 0;
    dword_7D5DB8 = 0;
    dword_7D5DBC = 0;
  }
}
