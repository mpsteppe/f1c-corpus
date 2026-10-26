// f1c  0x00594f3e  size=169
int __cdecl sub_594F3E(int a1, _DWORD *a2, _BYTE *a3, unsigned int a4)
{
  unsigned int v4; // ecx
  _DWORD *v5; // edi
  _BYTE *v6; // esi
  _BYTE *i; // eax
  bool v8; // zf
  int v9; // eax
  int v11; // [esp+Ch] [ebp-4h]

  v4 = (unsigned __int8)*a3;
  v11 = 0;
  v5 = (_DWORD *)(a1 + 8 * (((int)a2 - *(_DWORD *)(a1 + 16)) >> 12) + 24);
  if ( v4 > a4 )
  {
    *a3 = a4;
    *v5 += v4 - a4;
    v5[1] = 241;
    return 1;
  }
  if ( v4 < a4 )
  {
    v6 = &a3[a4];
    if ( a2 + 62 >= (_DWORD *)&a3[a4] )
    {
      for ( i = &a3[v4]; ; ++i )
      {
        v8 = i == v6;
        if ( i >= v6 )
          break;
        if ( *i )
        {
          v8 = i == v6;
          break;
        }
      }
      if ( v8 )
      {
        *a3 = a4;
        if ( (unsigned int)a3 <= *a2 && (unsigned int)v6 > *a2 )
        {
          if ( v6 >= (_BYTE *)a2 + 248 )
          {
            a2[1] = 0;
            *a2 = a2 + 2;
          }
          else
          {
            v9 = 0;
            *a2 = v6;
            if ( !*v6 )
            {
              do
                ++v9;
              while ( !v6[v9] );
            }
            a2[1] = v9;
          }
        }
        *v5 += v4 - a4;
        return 1;
      }
    }
  }
  return v11;
}
