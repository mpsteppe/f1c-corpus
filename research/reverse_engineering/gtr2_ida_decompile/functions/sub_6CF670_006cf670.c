int __stdcall sub_6CF670(unsigned __int8 **a1, int a2, int a3, int a4)
{
  _DWORD *v4; // eax
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned __int8 **v8; // eax
  int v9; // eax
  unsigned __int8 **v10; // eax
  int v11; // eax
  bool v12; // cc
  int v14; // eax
  int v15; // eax

  v4 = a1;
  v5 = a1[4];
  v6 = *a1;
  v7 = a1[1];
  if ( *((_DWORD *)v5 + 105) )
    goto LABEL_17;
  if ( a3 < 25 )
  {
    while ( 1 )
    {
      if ( !v7 )
      {
        if ( !(*(int (__stdcall **)(unsigned __int8 *))(*((_DWORD *)v5 + 6) + 12))(v5) )
          return 0;
        v8 = (unsigned __int8 **)*((_DWORD *)v5 + 6);
        v6 = *v8;
        v7 = v8[1];
      }
      v9 = *v6;
      --v7;
      ++v6;
      if ( v9 == 255 )
      {
        do
        {
          if ( !v7 )
          {
            if ( !(*(int (__stdcall **)(unsigned __int8 *))(*((_DWORD *)v5 + 6) + 12))(v5) )
              return 0;
            v10 = (unsigned __int8 **)*((_DWORD *)v5 + 6);
            v6 = *v10;
            v7 = v10[1];
          }
          v11 = *v6;
          --v7;
          ++v6;
        }
        while ( v11 == 255 );
        if ( v11 )
        {
          *((_DWORD *)v5 + 105) = v11;
          v4 = a1;
LABEL_17:
          if ( a4 > a3 )
          {
            if ( !*(_DWORD *)(*((_DWORD *)v5 + 112) + 8) )
            {
              v14 = *(_DWORD *)v5;
              *(_DWORD *)(v14 + 20) = 117;
              (*(void (__stdcall **)(unsigned __int8 *, int))(v14 + 4))(v5, -1);
              *(_DWORD *)(*((_DWORD *)v5 + 112) + 8) = 1;
            }
            v15 = a2 << (25 - a3);
            a3 = 25;
            a2 = v15;
LABEL_21:
            v4 = a1;
          }
          break;
        }
        v9 = 255;
      }
      v12 = a3 + 8 < 25;
      a2 = v9 | (a2 << 8);
      a3 += 8;
      if ( !v12 )
        goto LABEL_21;
    }
  }
  v4[1] = v7;
  *v4 = v6;
  v4[2] = a2;
  v4[3] = a3;
  return 1;
}
