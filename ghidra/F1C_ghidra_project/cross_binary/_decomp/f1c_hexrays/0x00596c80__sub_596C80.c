// f1c  0x00596c80  size=257
int __cdecl sub_596C80(unsigned __int8 *a1, unsigned __int8 *a2, int a3)
{
  int v3; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al
  bool v8; // cf
  unsigned int v9; // eax
  unsigned int v10; // ebx
  bool v11; // cf
  int v12; // ebx
  int v14; // [esp-8h] [ebp-18h]
  int v15; // [esp-4h] [ebp-14h]
  int v16; // [esp+0h] [ebp-10h]

  v3 = a3;
  if ( a3 )
  {
    if ( dword_8D3F38 )
    {
      _InterlockedIncrement(&dword_8D5A5C);
      if ( dword_8D5A58 > 0 )
      {
        _InterlockedDecrement(&dword_8D5A5C);
        sub_58DFEA(19);
        v16 = 1;
        v3 = a3;
      }
      else
      {
        v16 = 0;
      }
      v9 = 0;
      v10 = 0;
      do
      {
        LOBYTE(v9) = *a1;
        LOBYTE(v10) = *a2;
        if ( !v9 || !v10 )
          break;
        ++a1;
        ++a2;
        v15 = v3;
        v14 = v9;
        v10 = sub_58B4D4(v10);
        v9 = sub_58B4D4(v14);
        v11 = v9 < v10;
        if ( v9 != v10 )
          goto LABEL_25;
        v3 = v15 - 1;
      }
      while ( v15 != 1 );
      v3 = 0;
      v11 = v9 < v10;
      if ( v9 == v10 )
        goto LABEL_27;
LABEL_25:
      v3 = -1;
      if ( !v11 )
        v3 = 1;
LABEL_27:
      if ( v16 )
      {
        v12 = v3;
        sub_58E04B(19);
        return v12;
      }
      else
      {
        _InterlockedDecrement(&dword_8D5A5C);
      }
    }
    else
    {
      do
      {
        v6 = *a1;
        v7 = *a2;
        if ( !*a1 || !v7 )
          break;
        ++a1;
        ++a2;
        if ( v6 >= 0x41u && v6 <= 0x5Au )
          v6 += 32;
        if ( v7 >= 0x41u && v7 <= 0x5Au )
          v7 += 32;
        v8 = v6 < v7;
        if ( v6 != v7 )
          goto LABEL_14;
        --v3;
      }
      while ( v3 );
      v3 = 0;
      v8 = v6 < v7;
      if ( v6 == v7 )
        return v3;
LABEL_14:
      v3 = -1;
      if ( !v8 )
        return 1;
    }
  }
  return v3;
}
