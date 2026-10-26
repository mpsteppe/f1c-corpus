int __thiscall sub_6C5456(_DWORD *this, int a2, unsigned int a3, unsigned int a4)
{
  _DWORD *v5; // eax
  int v6; // edi
  unsigned int v7; // edx
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  int j; // [esp+Ch] [ebp-10h]
  unsigned int i; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  char *v15; // [esp+18h] [ebp-4h]

  v5 = (_DWORD *)sub_681186(116);
  if ( v5 )
    v15 = (char *)sub_680CEC(v5);
  else
    v15 = 0;
  if ( !v15 )
    return -2147024882;
  v7 = a4;
  v14 = 0;
  if ( a4 )
  {
    v8 = *(_DWORD **)(this[64] + 16);
    do
    {
      if ( *(_DWORD *)(a2 + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v8) + 16)) != -1 )
        ++v14;
      ++v8;
      --v7;
    }
    while ( v7 );
  }
  v6 = sub_6811D1(v15, v14 | *(_DWORD *)this[64] & 0xFFF00000, a3 * v14, v14, 0);
  if ( v6 >= 0 )
  {
    v6 = sub_680D22(v15, this[64]);
    if ( v6 >= 0 )
    {
      for ( i = 0; i < a3; ++i )
      {
        v9 = 0;
        for ( j = 0; v9 < a4; ++v9 )
        {
          v10 = this[64];
          if ( *(_DWORD *)(a2
                         + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v10 + 16) + 4 * v9)) + 16)) != -1 )
          {
            *(_DWORD *)(*((_DWORD *)v15 + 2) + 4 * (j + v14 * i)) = *(_DWORD *)(*(_DWORD *)(v10 + 8) + 4 * (v9 + a4 * i));
            if ( !i )
              *(_DWORD *)(*((_DWORD *)v15 + 4) + 4 * j) = *(_DWORD *)(*(_DWORD *)(this[64] + 16) + 4 * v9);
            ++j;
          }
        }
      }
      v6 = sub_681997((int)this, v15);
      if ( v6 >= 0 )
      {
        v15 = 0;
        v6 = 0;
      }
    }
  }
  if ( v15 )
    sub_66238F(v15, 1);
  return v6;
}
