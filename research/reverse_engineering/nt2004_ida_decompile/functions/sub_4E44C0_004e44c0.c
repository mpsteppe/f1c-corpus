char __thiscall sub_4E44C0(_BYTE *this)
{
  _BYTE *v1; // ebp
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // eax
  const char *v7; // eax
  const char *v8; // ecx
  _BYTE *v9; // esi
  int v10; // edi
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  int v17; // edx
  int v18; // edi
  int v19; // eax
  _DWORD *v20; // ecx
  int v21; // esi
  int v23; // [esp+8h] [ebp-24h]
  int v24; // [esp+Ch] [ebp-20h]
  int v25; // [esp+10h] [ebp-1Ch]
  int v27; // [esp+18h] [ebp-14h]
  int v28; // [esp+1Ch] [ebp-10h]
  int v29; // [esp+20h] [ebp-Ch]
  int v30; // [esp+24h] [ebp-8h]
  int v31; // [esp+28h] [ebp-4h]

  v1 = this;
  v2 = 0;
  if ( !this[30976] )
  {
    v3 = sub_57AE50(aRaceorder);
    v4 = v3;
    if ( v3 )
    {
      v5 = 0;
      if ( sub_57A6E0(v3) > 0 )
      {
        do
        {
          v6 = sub_57A700(v5);
          if ( v6 )
          {
            v7 = (const char *)sub_57A6C0(v6);
            v8 = dword_766594;
            if ( !dword_766594 )
              v8 = &byte_629120;
            if ( !_strcmpi(v7, v8) )
              v2 = v5;
          }
          ++v5;
        }
        while ( v5 < sub_57A6E0(v4) );
      }
    }
    sub_4E3BE0((_DWORD *)v1 + 7571, v2);
    v9 = v1 + 16;
    v10 = 47;
    do
    {
      if ( v9[640] )
        sub_4E3BE0(v9, v2);
      v9 += 644;
      --v10;
    }
    while ( v10 );
    if ( *((_DWORD *)v1 + 7743) == 7 )
    {
      v11 = 0;
      v27 = 0;
      do
      {
        v23 = 0;
        if ( v11 )
          v12 = (int)&v1[644 * v11 - 628];
        else
          v12 = (int)(v1 + 30284);
        v28 = v12;
        if ( *(_BYTE *)(v12 + 640) )
        {
          v13 = *(_DWORD *)(v12 + 608);
          v14 = 0;
          v30 = v13;
          v29 = 0;
          while ( 1 )
          {
            if ( v11 != v14 )
            {
              v15 = (int)(v14 ? &v1[644 * v14 - 628] : v1 + 30284);
              if ( *(_BYTE *)(v15 + 640) )
              {
                v16 = *(_DWORD *)(v15 + 608);
                if ( v16 == v13 )
                {
                  v17 = sub_4E4C30(v1) + 1;
                  v18 = 1;
                  v31 = v17;
                  if ( v17 <= 1 )
                    goto LABEL_43;
                  v19 = *((_DWORD *)v1 + 7742) + 1;
                  while ( 1 )
                  {
                    v25 = 0;
                    v24 = 0;
                    if ( v19 > 0 )
                    {
                      v20 = (_DWORD *)(v15 + 224);
                      v21 = v19;
                      do
                      {
                        if ( *(_DWORD *)((char *)v20 + v28 - v15) == v18 )
                          ++v24;
                        if ( *v20 == v18 )
                          ++v25;
                        ++v20;
                        --v21;
                      }
                      while ( v21 );
                      v1 = this;
                      if ( v25 > v24 )
                      {
                        ++v23;
                        goto LABEL_43;
                      }
                      if ( v25 < v24 )
                        goto LABEL_43;
                      v17 = v31;
                    }
                    if ( ++v18 >= v17 )
                      goto LABEL_43;
                  }
                }
                if ( v16 > v13 )
                  ++v23;
              }
            }
LABEL_43:
            v11 = v27;
            v14 = ++v29;
            if ( v29 >= 48 )
              break;
            v13 = v30;
          }
          if ( v27 )
            *(_DWORD *)&v1[644 * v27 - 16] = v23;
          else
            *((_DWORD *)v1 + 7724) = v23;
        }
        v27 = ++v11;
      }
      while ( v11 < 48 );
    }
    v1[30976] = 1;
  }
  return 0;
}
