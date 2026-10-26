int __cdecl _strcmpi(const char *String1, const char *String2)
{
  int result; // eax
  char v5; // t0
  int v6; // eax
  int v7; // ebx
  int v8; // ebx
  int v9; // [esp-4h] [ebp-14h]
  int v10; // [esp+0h] [ebp-10h]

  if ( dword_7FF1E8 )
  {
    _InterlockedIncrement(&dword_80151C);
    if ( dword_801518 > 0 )
    {
      _InterlockedDecrement(&dword_80151C);
      _lock(19);
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
    v6 = 255;
    v7 = 0;
    while ( (_BYTE)v6 )
    {
      LOBYTE(v6) = *String2++;
      LOBYTE(v7) = *String1++;
      if ( (_BYTE)v6 != (_BYTE)v7 )
      {
        v9 = v6;
        v7 = tolower_0(v7);
        v6 = tolower_0(v9);
        if ( (_BYTE)v7 != (_BYTE)v6 )
        {
          v6 = -((unsigned __int8)v7 < (unsigned __int8)v6) - (((unsigned __int8)v7 < (unsigned __int8)v6) - 1);
          break;
        }
      }
    }
    v8 = v6;
    if ( v10 )
      _unlock(19);
    else
      _InterlockedDecrement(&dword_80151C);
    return v8;
  }
  else
  {
    LOBYTE(result) = -1;
    while ( (_BYTE)result )
    {
      LOBYTE(result) = *String2++;
      BYTE1(result) = *String1++;
      if ( BYTE1(result) != (_BYTE)result )
      {
        v5 = BYTE1(result);
        BYTE1(result) = ((unsigned __int8)(result - 65) < 0x1Au ? 0x20 : 0) + result;
        LOBYTE(result) = ((unsigned __int8)(v5 - 65) < 0x1Au ? 0x20 : 0) + v5;
        if ( (_BYTE)result != BYTE1(result) )
        {
          LOBYTE(result) = -((unsigned __int8)result < BYTE1(result)) - (((unsigned __int8)result < BYTE1(result)) - 1);
          return (char)result;
        }
      }
    }
    return (char)result;
  }
}
