int __fastcall sub_535390(int a1, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  void *v6; // edi
  int v7; // eax
  int v8; // eax
  int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // [esp-Ch] [ebp-14h]

  v4 = a2;
  if ( a1 )
  {
    if ( a3 != 2 )
    {
      v5 = *(_DWORD *)(a1 + 56);
      if ( v5 != -1 && v5 != -3 )
      {
        if ( *(_BYTE *)(a1 + 92) == 119 )
        {
          if ( !a3 )
            v4 = a2 - *(_DWORD *)(a1 + 8);
          if ( v4 >= 0 )
          {
            if ( !*(_DWORD *)(a1 + 68) )
            {
              v6 = (void *)sub_58A935(0x4000);
              *(_DWORD *)(a1 + 68) = v6;
              memset(v6, 0, 0x4000u);
            }
            if ( v4 <= 0 )
              return *(_DWORD *)(a1 + 8);
            while ( 1 )
            {
              v7 = 0x4000;
              if ( v4 < 0x4000 )
                v7 = v4;
              v8 = sub_535220(a1, *(_DWORD *)(a1 + 68), v7);
              if ( !v8 )
                break;
              v4 -= v8;
              if ( v4 <= 0 )
                return *(_DWORD *)(a1 + 8);
            }
          }
          return -1;
        }
        if ( a3 == 1 )
          v4 = *(_DWORD *)(a1 + 20) + a2;
        if ( v4 >= 0 )
        {
          if ( *(_DWORD *)(a1 + 88) )
          {
            v10 = *(_DWORD *)(a1 + 68);
            v14 = *(_DWORD *)(a1 + 64);
            *(_DWORD *)(a1 + 4) = 0;
            *(_DWORD *)a1 = v10;
            if ( (int)sub_587F64(v14, v4, 0) >= 0 )
            {
              *(_DWORD *)(a1 + 20) = v4;
              *(_DWORD *)(a1 + 8) = v4;
              return v4;
            }
            return -1;
          }
          v11 = *(_DWORD *)(a1 + 20);
          if ( v4 < v11 )
          {
            if ( sub_5354E0(a1) < 0 )
              return -1;
          }
          else
          {
            v4 -= v11;
          }
          if ( !v4 )
            return *(_DWORD *)(a1 + 20);
          if ( !*(_DWORD *)(a1 + 72) )
            *(_DWORD *)(a1 + 72) = sub_58A935(0x4000);
          if ( v4 <= 0 )
            return *(_DWORD *)(a1 + 20);
          while ( 1 )
          {
            v12 = 0x4000;
            if ( v4 < 0x4000 )
              v12 = v4;
            v13 = sub_534F90(a1, *(_DWORD *)(a1 + 72), v12);
            if ( v13 <= 0 )
              break;
            v4 -= v13;
            if ( v4 <= 0 )
              return *(_DWORD *)(a1 + 20);
          }
        }
      }
    }
  }
  return -1;
}
