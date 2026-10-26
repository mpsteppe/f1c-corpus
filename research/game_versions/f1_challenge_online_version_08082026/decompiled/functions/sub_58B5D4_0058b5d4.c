LPVOID __cdecl sub_58B5D4(_DWORD *lpMem, SIZE_T dwBytes)
{
  void *v2; // ebx
  LPVOID result; // eax
  SIZE_T v4; // esi
  int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v12; // [esp+Ch] [ebp-38h] BYREF
  unsigned int v13; // [esp+10h] [ebp-34h]
  unsigned __int8 *v14; // [esp+14h] [ebp-30h]
  int v15; // [esp+18h] [ebp-2Ch] BYREF
  int v16; // [esp+1Ch] [ebp-28h]
  _DWORD *v17; // [esp+20h] [ebp-24h]
  unsigned int v18; // [esp+24h] [ebp-20h]
  CPPEH_RECORD ms_exc; // [esp+2Ch] [ebp-18h]

  v2 = lpMem;
  if ( !lpMem )
    return (LPVOID)sub_58A935(dwBytes);
  v4 = dwBytes;
  if ( dwBytes )
  {
    if ( dword_8D4908 == 3 )
    {
      while ( 1 )
      {
        v17 = 0;
        if ( v4 <= 0xFFFFFFE0 )
        {
          sub_58DFEA(9);
          ms_exc.registration.TryLevel = 0;
          v5 = sub_593E1B(lpMem);
          v16 = v5;
          if ( v5 )
          {
            if ( v4 <= dword_8D4900 )
            {
              if ( sub_594624(v5, lpMem, v4) )
              {
                v17 = lpMem;
              }
              else
              {
                v17 = (_DWORD *)sub_59416F(v4);
                if ( v17 )
                {
                  v6 = *(lpMem - 1) - 1;
                  v18 = v6;
                  if ( v6 >= v4 )
                    v6 = v4;
                  sub_58CC00(v17, lpMem, v6);
                  v16 = sub_593E1B(lpMem);
                  sub_593E46(v16, lpMem);
                }
              }
            }
            if ( !v17 )
            {
              if ( !v4 )
                v4 = 1;
              v4 = (v4 + 15) & 0xFFFFFFF0;
              v17 = HeapAlloc(hHeap, 0, v4);
              if ( v17 )
              {
                v7 = *(lpMem - 1) - 1;
                v18 = v7;
                if ( v7 >= v4 )
                  v7 = v4;
                sub_58CC00(v17, lpMem, v7);
                sub_593E46(v16, lpMem);
              }
            }
          }
          ms_exc.registration.TryLevel = -1;
          sub_58E04B(9);
          if ( !v16 )
          {
            if ( !v4 )
              v4 = 1;
            v4 = (v4 + 15) & 0xFFFFFFF0;
            v17 = HeapReAlloc(hHeap, 0, lpMem, v4);
          }
        }
        result = v17;
        if ( v17 || !dword_8D41B0 )
          break;
        if ( !sub_593DB8(v4) )
          return 0;
      }
    }
    else if ( dword_8D4908 == 2 )
    {
      if ( dwBytes <= 0xFFFFFFE0 )
        v4 = (dwBytes + 15) & 0xFFFFFFF0;
      while ( 1 )
      {
        v17 = 0;
        if ( v4 <= 0xFFFFFFE0 )
        {
          sub_58DFEA(9);
          ms_exc.registration.TryLevel = 1;
          v8 = (unsigned __int8 *)sub_594B76(v2, &v12, &v15);
          v9 = v8;
          v14 = v8;
          if ( v8 )
          {
            if ( v4 < dword_5E998C )
            {
              if ( sub_594F3E(v12, v15, v8, v4 >> 4) )
              {
                v17 = lpMem;
              }
              else
              {
                v17 = (_DWORD *)sub_594C12(v4 >> 4);
                if ( v17 )
                {
                  v10 = 16 * *v9;
                  v13 = v10;
                  if ( v10 >= v4 )
                    v10 = v4;
                  sub_58CC00(v17, lpMem, v10);
                  sub_594BCD(v12, v15, v9);
                }
              }
              v2 = lpMem;
            }
            if ( !v17 )
            {
              v17 = HeapAlloc(hHeap, 0, v4);
              if ( v17 )
              {
                v11 = 16 * *v9;
                v13 = v11;
                if ( v11 >= v4 )
                  v11 = v4;
                sub_58CC00(v17, v2, v11);
                sub_594BCD(v12, v15, v9);
              }
            }
          }
          else
          {
            v17 = HeapReAlloc(hHeap, 0, v2, v4);
          }
          ms_exc.registration.TryLevel = -1;
          sub_58E04B(9);
        }
        result = v17;
        if ( v17 || !dword_8D41B0 )
          break;
        if ( !sub_593DB8(v4) )
          return 0;
      }
    }
    else
    {
      while ( 1 )
      {
        result = 0;
        if ( v4 <= 0xFFFFFFE0 )
        {
          if ( !v4 )
            v4 = 1;
          v4 = (v4 + 15) & 0xFFFFFFF0;
          result = HeapReAlloc(hHeap, 0, lpMem, v4);
        }
        if ( result || !dword_8D41B0 )
          break;
        if ( !sub_593DB8(v4) )
          return 0;
      }
    }
  }
  else
  {
    sub_58AA6F(lpMem);
    return 0;
  }
  return result;
}
