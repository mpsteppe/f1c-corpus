int __cdecl sub_588410(_BYTE *a1, _BYTE *a2)
{
  int result; // eax
  char v5; // t0
  int v6; // eax
  WORD v7; // bx
  int v8; // ebx
  WORD v9; // [esp-4h] [ebp-14h]
  int v10; // [esp+0h] [ebp-10h]

  if ( dword_8D3F38 )
  {
    _InterlockedIncrement(&dword_8D5A5C);
    if ( dword_8D5A58 > 0 )
    {
      _InterlockedDecrement(&dword_8D5A5C);
      CriticalSectionLazyInitEnter(19);
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
    v6 = 255;
    HIBYTE(v7) = 0;
    while ( (_BYTE)v6 )
    {
      LOBYTE(v6) = *a2++;
      LOBYTE(v7) = *a1++;
      if ( (_BYTE)v6 != (_BYTE)v7 )
      {
        v9 = v6;
        v7 = sub_58B4D4(v7);
        v6 = sub_58B4D4(v9);
        if ( (_BYTE)v7 != (_BYTE)v6 )
        {
          v6 = -((unsigned __int8)v7 < (unsigned __int8)v6) - (((unsigned __int8)v7 < (unsigned __int8)v6) - 1);
          break;
        }
      }
    }
    v8 = v6;
    if ( v10 )
      CritSectLeave(19);
    else
      _InterlockedDecrement(&dword_8D5A5C);
    return v8;
  }
  else
  {
    LOBYTE(result) = -1;
    while ( (_BYTE)result )
    {
      LOBYTE(result) = *a2++;
      BYTE1(result) = *a1++;
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
