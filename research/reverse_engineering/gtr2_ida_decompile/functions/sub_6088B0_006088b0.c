_DWORD *__thiscall sub_6088B0(_DWORD *this)
{
  _DWORD *v1; // esi
  int *v2; // eax
  int v3; // edi
  _DWORD **v4; // eax
  _DWORD *v5; // edx
  int v6; // ecx
  _DWORD *v7; // ebx
  int **v8; // eax
  int *v9; // ebp
  int v10; // eax
  int **v11; // eax
  int *v12; // eax
  int v13; // ecx
  int **v14; // eax
  int v15; // eax
  _DWORD *v16; // eax
  int v17; // eax
  int *v18; // eax
  _DWORD *result; // eax
  int v20; // eax
  int v21; // [esp+4h] [ebp-24h]
  _DWORD *v22; // [esp+8h] [ebp-20h]
  int v23; // [esp+Ch] [ebp-1Ch]
  int v25; // [esp+14h] [ebp-14h]

  v1 = this;
  v2 = (int *)this[67];
  this[69] = v2;
  if ( v2 )
  {
    v3 = *v2;
    v23 = *v2;
    if ( *v2 )
    {
      while ( 1 )
      {
        v4 = *(_DWORD ***)(v3 + 532);
        *(_DWORD *)(v3 + 540) = v4;
        if ( v4 )
        {
          v5 = *v4;
          v22 = *v4;
          if ( *v4 )
          {
            while ( 1 )
            {
              if ( (*v5 & 0x200) == 0 )
              {
                v6 = 0;
                v25 = 0;
                if ( (int)v5[90] > 0 )
                {
                  v21 = 0;
                  do
                  {
                    v7 = (_DWORD *)(v21 + v5[91]);
                    v8 = (int **)v1[63];
                    v1[65] = v8;
                    if ( v8 && (v9 = *v8) != 0 )
                    {
                      while ( v7[22] != v9[22] || v7[1] != v9[1] )
                      {
                        v10 = v1[65];
                        if ( v10 )
                          v1[65] = *(_DWORD *)(v10 + 4);
                        v11 = (int **)v1[65];
                        if ( v11 )
                        {
                          v9 = *v11;
                          if ( *v11 )
                            continue;
                        }
                        goto LABEL_20;
                      }
                    }
                    else
                    {
LABEL_20:
                      v12 = (int *)operator new(0x6Cu);
                      v9 = v12;
                      if ( v12 )
                      {
                        sub_5D9010(v12);
                        *v9 = 0;
                      }
                      else
                      {
                        v9 = 0;
                      }
                      qmemcpy(v9, v7, 0x6Cu);
                      v9[22] = v7[22];
                      v13 = *v9;
                      v9[1] = v7[1];
                      *v9 = *v7 | v13;
                      v9[26] = v7[26];
                      v9[2] = 0;
                      v9[9] = 0;
                      v9[21] = 0;
                      v14 = (int **)operator new(0xCu);
                      if ( v14 )
                      {
                        *v14 = v9;
                        v14[1] = 0;
                        *((_BYTE *)v14 + 8) = 1;
                      }
                      else
                      {
                        v14 = 0;
                      }
                      if ( this[63] )
                      {
                        *(_DWORD *)(this[64] + 4) = v14;
                      }
                      else
                      {
                        this[63] = v14;
                        this[65] = v14;
                      }
                      v1 = this;
                      v5 = v22;
                      v3 = v23;
                      this[64] = v14;
                      ++this[66];
                      v6 = v25;
                    }
                    v9[2] += v7[2];
                    v9[9] += v7[9];
                    v9[21] += v7[21];
                    v25 = ++v6;
                    v21 += 108;
                  }
                  while ( v6 < v5[90] );
                }
              }
              v15 = *(_DWORD *)(v3 + 540);
              if ( !v15 )
                break;
              v16 = *(_DWORD **)(v15 + 4);
              *(_DWORD *)(v3 + 540) = v16;
              if ( !v16 )
                break;
              v22 = (_DWORD *)*v16;
              if ( !*v16 )
                break;
              v5 = (_DWORD *)*v16;
            }
          }
        }
        v17 = v1[69];
        if ( !v17 )
          break;
        v18 = *(int **)(v17 + 4);
        v1[69] = v18;
        if ( !v18 )
          break;
        v23 = *v18;
        if ( !*v18 )
          break;
        v3 = *v18;
      }
    }
  }
  result = (_DWORD *)v1[63];
  v1[65] = result;
  if ( result )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      result = (_DWORD *)sub_608640(v1, result);
      if ( result )
        break;
      v20 = v1[65];
      if ( v20 )
        v1[65] = *(_DWORD *)(v20 + 4);
      result = (_DWORD *)v1[65];
      if ( !result )
        break;
    }
  }
  return result;
}
