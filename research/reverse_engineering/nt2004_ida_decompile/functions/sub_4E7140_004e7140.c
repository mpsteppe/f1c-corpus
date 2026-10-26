char __thiscall sub_4E7140(const char **this, int a2, char *Destination, int a4)
{
  int v4; // ecx
  int v5; // ebp
  int v6; // eax
  const char **v7; // eax
  const char *v8; // eax
  LPVOID **v9; // edi
  bool v10; // zf
  LPVOID *v11; // esi
  char v13; // [esp+13h] [ebp-11h]
  _DWORD v14[3]; // [esp+14h] [ebp-10h] BYREF
  int v15; // [esp+20h] [ebp-4h]

  v13 = 0;
  memset(v14, 0, sizeof(v14));
  v15 = 0;
  sub_4E6E00(this, v14);
  v4 = a2;
  v5 = v14[0];
  if ( v15 >= a2 )
  {
    v6 = v14[0];
    if ( a2 > 0 )
    {
      do
      {
        if ( v6 )
          v6 = *(_DWORD *)(v6 + 4);
        --v4;
      }
      while ( v4 );
    }
    if ( v6 )
    {
      v7 = *(const char ***)v6;
      if ( v7 )
      {
        v8 = *v7;
        if ( !v8 )
          v8 = &byte_629120;
        strncpy(Destination, v8, a4 - 1);
        Destination[a4 - 1] = 0;
        v13 = 1;
      }
    }
  }
  while ( v5 )
  {
    v9 = (LPVOID **)v5;
    v10 = *(_BYTE *)(v5 + 8) == 0;
    v5 = *(_DWORD *)(v5 + 4);
    if ( !v10 )
    {
      v11 = *v9;
      if ( *v9 )
      {
        if ( *v11 )
          sub_5BE8AE(*v11);
        sub_5BE8AE(v11);
      }
    }
    sub_5BE8AE(v9);
  }
  return v13;
}
