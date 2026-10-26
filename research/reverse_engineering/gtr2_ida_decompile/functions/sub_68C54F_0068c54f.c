BOOL __thiscall sub_68C54F(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // ecx
  _DWORD *v7; // ebx
  unsigned int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  int v13; // eax
  unsigned int k; // ecx
  int v15; // eax
  int v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  int v23; // edx
  unsigned int j; // [esp+Ch] [ebp-24h]
  int v26; // [esp+10h] [ebp-20h]
  _DWORD *v27; // [esp+14h] [ebp-1Ch]
  _DWORD *v28; // [esp+18h] [ebp-18h] BYREF
  unsigned int i; // [esp+1Ch] [ebp-14h]
  unsigned int m; // [esp+20h] [ebp-10h]
  unsigned int v31; // [esp+24h] [ebp-Ch]
  unsigned int v32; // [esp+28h] [ebp-8h]
  unsigned int v33; // [esp+2Ch] [ebp-4h]

  v26 = 0;
  v33 = 0;
  v3 = this[2];
  if ( v3 )
  {
    v4 = this[34];
    v5 = this[5];
    do
    {
      if ( v4 == *(_DWORD *)(*(_DWORD *)v5 + 4) )
      {
        v6 = *(_DWORD *)(*(_DWORD *)v5 + 12);
        if ( v33 <= v6 )
          v33 = v6 + 1;
      }
      v5 += 4;
      --v3;
    }
    while ( v3 );
  }
  sub_686074((int)this);
  for ( i = 0; i < this[3]; ++i )
  {
    v7 = *(_DWORD **)(this[6] + 4 * i);
    v27 = v7;
    if ( (*v7 & 0xFFF00000) != 0 )
    {
      v8 = v7[1] / (*v7 & 0xFFFFFu);
      v7[9] = 0;
      m = 0;
      for ( j = v8; m < j; ++m )
      {
        v9 = sub_680D41(v7, m, &v28);
        v10 = this[5];
        v11 = this[34];
        v31 = v9;
        v12 = *(_DWORD *)(v10 + 4 * *v28);
        if ( v11 == *(_DWORD *)(v12 + 4) )
        {
          v32 = 1;
          if ( v31 > 1 )
          {
            do
            {
              v13 = *(_DWORD *)(v10 + 4 * v28[v32]);
              if ( v11 == *(_DWORD *)(v13 + 4) && *(_DWORD *)(v13 + 72) != *(_DWORD *)(v12 + 72) )
                break;
              ++v32;
            }
            while ( v32 < v31 );
            v7 = v27;
          }
          if ( v32 != v31 )
          {
            for ( k = 0; k < v31; ++k )
            {
              v15 = *(_DWORD *)(this[5] + 4 * v28[k]);
              if ( this[34] == *(_DWORD *)(v15 + 4) )
                *(_DWORD *)(*(_DWORD *)(this[6] + 4 * *(_DWORD *)(v15 + 72)) + 36) = 1;
            }
          }
        }
      }
    }
  }
  for ( m = 0; m < this[3]; ++m )
  {
    v16 = *(_DWORD *)(this[6] + 4 * m);
    if ( (*(_WORD *)(v16 + 2) & 0xFFF0) != 0 && !*(_DWORD *)(v16 + 36) )
    {
      v17 = *(_DWORD **)(v16 + 16);
      v18 = this[5];
      if ( this[34] == *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v17) + 4) )
      {
        v19 = *(_DWORD *)(v16 + 12);
        v20 = 0;
        if ( a2 )
        {
          if ( v19 )
          {
            v28 = *(_DWORD **)(v16 + 16);
            do
            {
              if ( v20 != *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v28) + 16) )
                break;
              ++v28;
              ++v20;
            }
            while ( v20 < v19 );
          }
          if ( v20 == v19 )
            continue;
          v21 = 0;
          if ( v19 )
          {
            do
            {
              *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v16 + 16) + 4 * v21)) + 12) = v33;
              *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v16 + 16) + 4 * v21)) + 16) = v21;
              ++v21;
            }
            while ( v21 < *(_DWORD *)(v16 + 12) );
          }
        }
        else
        {
          for ( i = 0; i < v19; ++v17 )
          {
            if ( !*(_DWORD *)(*(_DWORD *)(v18 + 4 * *v17) + 16) )
              break;
            ++i;
          }
          if ( i < v19 )
            continue;
          v22 = 0;
          if ( v19 )
          {
            do
            {
              v23 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v16 + 16) + 4 * v22++));
              *(_DWORD *)(v23 + 12) = v33;
            }
            while ( v22 < *(_DWORD *)(v16 + 12) );
          }
        }
        ++v33;
        v26 = 1;
      }
    }
  }
  return v26 == 0;
}
