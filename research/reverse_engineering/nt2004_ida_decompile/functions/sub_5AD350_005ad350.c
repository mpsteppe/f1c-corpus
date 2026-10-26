int __thiscall sub_5AD350(_DWORD *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // edi
  bool v11; // cc
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  _DWORD *v16; // esi
  int v17; // edi
  int v19; // eax
  int v20; // esi
  int v21; // edi
  int v22; // ecx
  char *v23; // esi
  int v24; // edi
  int v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+10h] [ebp-8h]
  int v27; // [esp+14h] [ebp-4h]
  int v28; // [esp+14h] [ebp-4h]

  if ( (*this & 2) == 0 )
  {
    if ( (*this & 1) == 0 )
      return 0;
    v26 = 0;
    if ( (int)this[3] > 0 )
    {
      v28 = 0;
      do
      {
        v19 = *(_DWORD *)(v28 + this[4] + 40);
        if ( v19 )
        {
          v20 = v19 + 32 * *(_DWORD *)(v19 - 4);
          if ( *(_DWORD *)(v19 - 4) - 1 >= 0 )
          {
            v21 = *(_DWORD *)(v19 - 4);
            do
            {
              v20 -= 32;
              sub_5ACB60();
              --v21;
            }
            while ( v21 );
          }
          sub_5BE8AE();
        }
        v11 = ++v26 < this[3];
        v28 += 44;
      }
      while ( v11 );
    }
    v22 = this[4];
    if ( !v22 )
      return 0;
    v23 = (char *)(v22 + 44 * *(_DWORD *)(v22 - 4));
    if ( *(_DWORD *)(v22 - 4) - 1 >= 0 )
    {
      v24 = *(_DWORD *)(v22 - 4);
      do
      {
        v23 -= 44;
        j_nullsub_6(v23);
        --v24;
      }
      while ( v24 );
    }
    goto LABEL_30;
  }
  v25 = 0;
  if ( (int)this[5] > 0 )
  {
    v27 = 0;
    do
    {
      v2 = this[6];
      v3 = *(_DWORD *)(v2 + v27 + 4);
      v4 = v27 + v2;
      v5 = 0;
      if ( v3 > 0 )
      {
        do
        {
          sub_5BE8AE();
          ++v5;
        }
        while ( v5 < *(_DWORD *)(v4 + 4) );
      }
      v6 = *(_DWORD *)(v4 + 8);
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 - 4);
        v8 = v6 + 8 * v7;
        v9 = v7 - 1;
        if ( v9 >= 0 )
        {
          v10 = v9 + 1;
          do
          {
            v8 -= 8;
            sub_5ACBA0();
            --v10;
          }
          while ( v10 );
        }
        sub_5BE8AE();
      }
      v11 = ++v25 < this[5];
      v27 += 12;
    }
    while ( v11 );
  }
  v12 = this[6];
  if ( !v12 )
    return 0;
  v13 = *(_DWORD *)(v12 - 4);
  v14 = 3 * v13;
  v15 = v13 - 1;
  v16 = (_DWORD *)(v12 + 4 * v14);
  if ( v15 < 0 )
  {
LABEL_30:
    sub_5BE8AE();
    return 0;
  }
  v17 = v15 + 1;
  do
  {
    v16 -= 3;
    sub_5ACBB0(v16);
    --v17;
  }
  while ( v17 );
  sub_5BE8AE();
  return 0;
}
