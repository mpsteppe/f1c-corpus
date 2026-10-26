int __cdecl _strnicmp(const char *String1, const char *String2, size_t MaxCount)
{
  size_t v3; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al
  bool v8; // cf
  unsigned int v9; // eax
  unsigned int v10; // ebx
  bool v11; // cf
  int v12; // ebx
  int v14; // [esp-8h] [ebp-18h]
  size_t v15; // [esp-4h] [ebp-14h]
  int v16; // [esp+0h] [ebp-10h]

  v3 = MaxCount;
  if ( MaxCount )
  {
    if ( dword_7FF1E8 )
    {
      _InterlockedIncrement(&dword_80151C);
      if ( dword_801518 > 0 )
      {
        _InterlockedDecrement(&dword_80151C);
        _lock(19);
        v16 = 1;
        v3 = MaxCount;
      }
      else
      {
        v16 = 0;
      }
      v9 = 0;
      v10 = 0;
      do
      {
        LOBYTE(v9) = *String1;
        LOBYTE(v10) = *String2;
        if ( !v9 || !v10 )
          break;
        ++String1;
        ++String2;
        v15 = v3;
        v14 = v9;
        v10 = tolower_0(v10);
        v9 = tolower_0(v14);
        v11 = v9 < v10;
        if ( v9 != v10 )
          goto differ2;
        v3 = v15 - 1;
      }
      while ( v15 != 1 );
      v3 = 0;
      v11 = v9 < v10;
      if ( v9 == v10 )
        goto toend2;
differ2:
      v3 = -1;
      if ( !v11 )
        v3 = 1;
toend2:
      if ( v16 )
      {
        v12 = v3;
        _unlock(19);
        return v12;
      }
      else
      {
        _InterlockedDecrement(&dword_80151C);
      }
    }
    else
    {
      do
      {
        v6 = *String1;
        v7 = *String2;
        if ( !*String1 || !v7 )
          break;
        ++String1;
        ++String2;
        if ( v6 >= 0x41u && v6 <= 0x5Au )
          v6 += 32;
        if ( v7 >= 0x41u && v7 <= 0x5Au )
          v7 += 32;
        v8 = v6 < v7;
        if ( v6 != v7 )
          goto differ;
        --v3;
      }
      while ( v3 );
      v3 = 0;
      v8 = v6 < v7;
      if ( v6 == v7 )
        return v3;
differ:
      v3 = -1;
      if ( !v8 )
        return 1;
    }
  }
  return v3;
}
