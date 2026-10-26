unsigned __int8 *__cdecl sub_54FA5F(int *a1, _BYTE *a2, unsigned __int8 *a3, int a4, char a5)
{
  unsigned __int8 *result; // eax
  int *v6; // edi
  unsigned __int8 v7; // cl
  int v8; // edx
  _BYTE *v9; // ecx
  int v10; // esi
  _BYTE *v11; // ecx
  __int16 v12; // cx
  unsigned __int8 *v13; // eax
  __int16 v14; // cx
  __int16 v15; // cx
  _BYTE *v16; // ecx
  int v17; // esi
  __int16 v18; // cx
  _BYTE *v19; // ecx
  int v20; // esi
  _BYTE *v21; // ecx
  __int16 v22; // cx
  unsigned __int8 *v23; // eax
  __int16 v24; // cx
  __int16 v25; // cx
  char v26; // cl
  int v27; // edx
  int v28; // edi
  char *v29; // ecx
  bool v30; // zf
  char v31; // cl
  _BYTE *v32; // esi
  unsigned int v33; // edi
  _BYTE *v34; // ecx
  int v35; // esi
  __int16 v36; // cx
  int v37; // [esp+8h] [ebp-14h]
  unsigned int v38; // [esp+14h] [ebp-8h]
  char *v39; // [esp+18h] [ebp-4h]
  int v40; // [esp+24h] [ebp+8h]
  int v41; // [esp+24h] [ebp+8h]

  result = a3;
  v6 = a1;
  v7 = *((_BYTE *)a1 + 9);
  v8 = *a1;
  v37 = *a1;
  if ( v7 <= 8u && a3 || v7 == 16 && a4 )
  {
    if ( *((_BYTE *)a1 + 8) )
    {
      switch ( *((_BYTE *)a1 + 8) )
      {
        case 2:
          if ( v7 == 8 )
          {
            v19 = a2;
            if ( v8 )
            {
              v20 = *a1;
              do
              {
                *v19 = a3[(unsigned __int8)*v19];
                v21 = v19 + 1;
                *v21 = a3[(unsigned __int8)*v21];
                ++v21;
                *v21 = a3[(unsigned __int8)*v21];
                v19 = v21 + 1;
                --v20;
              }
              while ( v20 );
            }
          }
          else
          {
            result = a2;
            if ( v8 )
            {
              v41 = *a1;
              do
              {
                v22 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (result[1] >> a5)) + 2 * *result);
                result[1] = v22;
                *result = HIBYTE(v22);
                v23 = result + 2;
                v24 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v23[1] >> a5)) + 2 * *v23);
                v23[1] = v24;
                *v23 = HIBYTE(v24);
                v23 += 2;
                v25 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v23[1] >> a5)) + 2 * *v23);
                *v23 = HIBYTE(v25);
                v23[1] = v25;
                result = v23 + 2;
                --v41;
              }
              while ( v41 );
            }
          }
          break;
        case 4:
          if ( v7 == 8 )
          {
            v16 = a2;
            if ( v8 )
            {
              v17 = *a1;
              do
              {
                *v16 = a3[(unsigned __int8)*v16];
                v16 += 2;
                --v17;
              }
              while ( v17 );
            }
          }
          else
          {
            for ( result = a2; v8; --v8 )
            {
              v18 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (result[1] >> a5)) + 2 * *result);
              *result = HIBYTE(v18);
              result[1] = v18;
              result += 4;
            }
          }
          break;
        case 6:
          if ( v7 == 8 )
          {
            v9 = a2;
            if ( v8 )
            {
              v10 = *a1;
              do
              {
                *v9 = a3[(unsigned __int8)*v9];
                v11 = v9 + 1;
                *v11 = a3[(unsigned __int8)*v11];
                ++v11;
                *v11 = a3[(unsigned __int8)*v11];
                v9 = v11 + 2;
                --v10;
              }
              while ( v10 );
            }
          }
          else
          {
            result = a2;
            if ( v8 )
            {
              v40 = *a1;
              do
              {
                v12 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (result[1] >> a5)) + 2 * *result);
                result[1] = v12;
                *result = HIBYTE(v12);
                v13 = result + 2;
                v14 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v13[1] >> a5)) + 2 * *v13);
                v13[1] = v14;
                *v13 = HIBYTE(v14);
                v13 += 2;
                v15 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v13[1] >> a5)) + 2 * *v13);
                *v13 = HIBYTE(v15);
                v13[1] = v15;
                result = v13 + 4;
                --v40;
              }
              while ( v40 );
            }
          }
          break;
      }
    }
    else
    {
      if ( v7 == 2 )
      {
        v39 = a2;
        if ( v8 )
        {
          v38 = ((unsigned int)(v8 - 1) >> 2) + 1;
          do
          {
            v26 = *v39;
            v27 = *v39 & 0xC;
            v28 = *v39 & 0x30;
            LOBYTE(v27) = a3[*v39 & 0xC0 | ((*v39 & 0xC0 | ((*v39 & 0xC0 | ((*v39 & 0xC0) >> 2)) >> 2)) >> 2)] & 0xC0
                        | ((unsigned __int8)(a3[v28 | (4 * v28) | ((v28 | (v28 >> 2)) >> 2)] & 0xC3
                                           | ((unsigned __int8)((a3[v26 & 3
                                                                  | (4 * (v26 & 3 | (4 * (v26 & 3 | (4 * (v26 & 3))))))] >> 2)
                                                              | a3[v27 | (v27 >> 2) | (4 * (v27 | (4 * (v26 & 0xC))))]
                                                              & 0xCF) >> 2)) >> 2);
            v29 = v39++;
            v30 = v38-- == 1;
            *v29 = v27;
          }
          while ( !v30 );
          v8 = v37;
          v6 = a1;
        }
      }
      v31 = *((_BYTE *)v6 + 9);
      switch ( v31 )
      {
        case 4:
          v32 = a2;
          if ( v8 )
          {
            v33 = ((unsigned int)(v8 - 1) >> 1) + 1;
            do
            {
              *v32 = (a3[*v32 & 0xF | (16 * (*v32 & 0xF))] >> 4) | a3[*v32 & 0xF0 | ((*v32 & 0xF0) >> 4)] & 0xF0;
              ++v32;
              --v33;
            }
            while ( v33 );
          }
          break;
        case 8:
          v34 = a2;
          if ( v8 )
          {
            v35 = v8;
            do
            {
              *v34 = a3[(unsigned __int8)*v34];
              ++v34;
              --v35;
            }
            while ( v35 );
          }
          break;
        case 16:
          for ( result = a2; v8; --v8 )
          {
            v36 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (result[1] >> a5)) + 2 * *result);
            *result = HIBYTE(v36);
            result[1] = v36;
            result += 2;
          }
          break;
      }
    }
  }
  return result;
}
