int __thiscall sub_686DF9(_DWORD *this)
{
  unsigned int v2; // ecx
  int v3; // eax
  unsigned int j; // ecx
  int v5; // eax
  unsigned int k; // eax
  int v7; // ebx
  _DWORD *v8; // edi
  _DWORD *v9; // edx
  _DWORD *v10; // ecx
  int v11; // ecx
  _DWORD *m; // ecx
  int v13; // ecx
  _DWORD *v14; // edx
  _DWORD *v15; // ecx
  int v16; // ecx
  int v17; // edi
  _DWORD *v18; // edx
  _DWORD *v19; // edi
  _DWORD *v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  int v23; // eax
  unsigned int v24; // ecx
  _DWORD *v25; // edi
  int v26; // eax
  int v27; // eax
  int v28; // edi
  char *v30; // [esp-Ch] [ebp-24h]
  int v31; // [esp-8h] [ebp-20h]
  int v32; // [esp-4h] [ebp-1Ch]
  int v33; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  char ArgList[4]; // [esp+14h] [ebp-4h]
  char ArgLista[4]; // [esp+14h] [ebp-4h]
  char ArgListb[4]; // [esp+14h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this[1]; *(_DWORD *)(v3 + 36) = -1 )
  {
    v3 = *(_DWORD *)(this[4] + 4 * v2++);
    *(_DWORD *)(v3 + 40) = -1;
  }
  for ( j = 0; j < this[2]; *(_DWORD *)(v5 + 72) = -1 )
  {
    v5 = *(_DWORD *)(this[5] + 4 * j++);
    *(_DWORD *)(v5 + 84) = -1;
  }
  for ( k = 0; k < this[3]; ++k )
  {
    v7 = *(_DWORD *)(this[6] + 4 * k);
    v33 = v7;
    if ( (*(_WORD *)(v7 + 2) & 0xFFF0) != 0 )
    {
      for ( *(_DWORD *)ArgList = 0; *(_DWORD *)ArgList < *(_DWORD *)(v7 + 4); ++*(_DWORD *)ArgList )
      {
        v8 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 8) + 4 * *(_DWORD *)ArgList));
        if ( k < v8[21] )
          v8[21] = k;
        v9 = v8 + 2;
        v10 = v8;
        if ( v8[2] != -1 )
        {
          do
          {
            v11 = *(_DWORD *)(this[4] + 4 * v10[1]);
            if ( k < *(_DWORD *)(v11 + 40) )
              *(_DWORD *)(v11 + 40) = k;
            v10 = *(_DWORD **)(this[5] + 4 * *v9);
            if ( k < v10[21] )
              v10[21] = k;
            v9 = v10 + 2;
          }
          while ( v10[2] != -1 );
          v7 = v33;
        }
        for ( m = v8 + 5; *m != -1; m = (_DWORD *)(v13 + 20) )
        {
          v13 = *(_DWORD *)(this[5] + 4 * *m);
          if ( k < *(_DWORD *)(v13 + 84) )
            *(_DWORD *)(v13 + 84) = k;
        }
      }
      for ( *(_DWORD *)ArgLista = 0; *(_DWORD *)ArgLista < *(_DWORD *)(v7 + 12); ++*(_DWORD *)ArgLista )
      {
        v14 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 16) + 4 * *(_DWORD *)ArgLista));
        if ( k < v14[18] )
          v14[18] = k;
        v15 = v14;
        if ( v14[2] != -1 )
        {
          v16 = *(_DWORD *)(this[4] + 4 * v14[1]);
          if ( k < *(_DWORD *)(v16 + 36) )
            *(_DWORD *)(v16 + 36) = k;
          v15 = *(_DWORD **)(this[5] + 4 * v14[2]);
          if ( k < v15[21] )
            v15[21] = k;
        }
        if ( v15[2] != -1 )
        {
          do
          {
            v17 = *(_DWORD *)(this[4] + 4 * v15[1]);
            if ( k < *(_DWORD *)(v17 + 40) )
              *(_DWORD *)(v17 + 40) = k;
            v15 = *(_DWORD **)(this[5] + 4 * v15[2]);
            if ( k < v15[21] )
              v15[21] = k;
          }
          while ( v15[2] != -1 );
          v7 = v33;
        }
        while ( 1 )
        {
          v18 = v14 + 5;
          if ( *v18 == -1 )
            break;
          v14 = *(_DWORD **)(this[5] + 4 * *v18);
          if ( k < v14[21] )
            v14[21] = k;
        }
      }
    }
  }
  sub_685FA9(this);
  *(_DWORD *)ArgListb = 0;
  if ( !this[2] )
    return 0;
  do
  {
    v19 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)ArgListb);
    v20 = *(_DWORD **)(this[4] + 4 * v19[1]);
    v21 = v20[10];
    if ( v21 < v19[21] )
      v19[21] = v21;
    v22 = v20[9];
    if ( v22 < v19[18] )
      v19[18] = v22;
    v23 = v20[1];
    if ( (v23 & 0x10) == 0 )
    {
      v24 = v19[21];
      if ( v24 != -1 && v24 <= v19[18] )
      {
        v25 = (_DWORD *)v19[24];
        if ( v25 )
        {
          if ( v25[1] == 6 )
          {
            v26 = v25[5];
            if ( v26 )
            {
              if ( *(_DWORD *)(v26 + 4) == 3 )
              {
                if ( !v25[10] )
                {
                  sub_686791(
                    (int)this,
                    *(_DWORD *)(*(_DWORD *)(this[6] + 4 * v24) + 60),
                    4000,
                    "variable '%s' used without having been completely initialized",
                    *(const char **)(v26 + 24));
                  v25[10] = 1;
                }
                goto LABEL_78;
              }
            }
          }
        }
        v32 = v24;
        v31 = *(_DWORD *)ArgListb;
        v30 = "internal error: argument used without having been initialized (A%u, I%u)";
        goto LABEL_64;
      }
    }
    if ( (v23 & 0x20) != 0 && v19[18] == -1 )
    {
      sub_686791((int)this, 0, 0, "internal error: output argument was never initialized (A%u)", *(_DWORD *)ArgListb);
      goto LABEL_78;
    }
    if ( (v23 & 2) == 0 && v19[18] != -1 )
    {
      v32 = v19[18];
      v31 = *(_DWORD *)ArgListb;
      v30 = "internal error: cannot write to argument pool (A%u, I%u)";
      goto LABEL_64;
    }
    if ( (v23 & 0xD) == 0 && v19[21] != -1 )
    {
      sub_686791((int)this, 0, 0, "internal error: cannot read from argument pool (A%u)", *(_DWORD *)ArgListb);
      goto LABEL_78;
    }
    if ( this[54] )
    {
      if ( (v23 & 0x10120) == 0 && v19[21] == -1 )
      {
        if ( (v23 & 0x10) != 0
          || (v27 = v19[18], v27 != -1)
          && !sub_680D7E(*(_DWORD **)(this[6] + 4 * v27))
          && (**(_DWORD **)(this[6] + 4 * v19[18]) & 0xFFF00000) != 0x20900000 )
        {
          v28 = v19[18];
          if ( v28 == -1 )
          {
            sub_686791((int)this, 0, 0, "internal error: argument was never used (A%u)", *(_DWORD *)ArgListb);
            goto LABEL_78;
          }
          v32 = v28;
          v31 = *(_DWORD *)ArgListb;
          v30 = "internal error: argument was never used (A%u, I%u)";
LABEL_64:
          sub_686791((int)this, 0, 0, v30, v31, v32);
LABEL_78:
          i = 1;
        }
      }
    }
    ++*(_DWORD *)ArgListb;
  }
  while ( *(_DWORD *)ArgListb < this[2] );
  if ( i )
    return -2147467259;
  return 0;
}
