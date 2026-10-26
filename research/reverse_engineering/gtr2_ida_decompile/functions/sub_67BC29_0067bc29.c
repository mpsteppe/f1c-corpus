unsigned __int8 *__stdcall sub_67BC29(int *a1, _BYTE *a2, unsigned __int8 *a3, int a4, char a5)
{
  unsigned __int8 *result; // eax
  int *v7; // edi
  unsigned __int8 v8; // cl
  int v9; // edx
  _BYTE *v10; // ecx
  int v11; // esi
  _BYTE *v12; // ecx
  __int16 v13; // cx
  unsigned __int8 *v14; // eax
  __int16 v15; // cx
  __int16 v16; // cx
  _BYTE *v17; // ecx
  int v18; // esi
  __int16 v19; // cx
  _BYTE *v20; // ecx
  int v21; // esi
  _BYTE *v22; // ecx
  __int16 v23; // cx
  unsigned __int8 *v24; // eax
  __int16 v25; // cx
  __int16 v26; // cx
  char v27; // cl
  int v28; // edx
  int v29; // edi
  char *v30; // ecx
  bool v31; // zf
  char v32; // cl
  _BYTE *v33; // esi
  unsigned int v34; // edi
  _BYTE *v35; // ecx
  int v36; // esi
  __int16 v37; // cx
  int v38; // [esp+8h] [ebp-Ch]
  int v39; // [esp+20h] [ebp+Ch]
  int v40; // [esp+20h] [ebp+Ch]
  unsigned int v41; // [esp+24h] [ebp+10h]
  char *v42; // [esp+28h] [ebp+14h]

  result = a3;
  v7 = a1;
  v8 = *((_BYTE *)a1 + 9);
  v9 = *a1;
  v38 = *a1;
  if ( v8 <= 8u && a3 || v8 == 16 && a4 )
  {
    if ( *((_BYTE *)a1 + 8) )
    {
      switch ( *((_BYTE *)a1 + 8) )
      {
        case 2:
          if ( v8 == 8 )
          {
            v20 = a2;
            if ( v9 )
            {
              v21 = *a1;
              do
              {
                *v20 = a3[(unsigned __int8)*v20];
                v22 = v20 + 1;
                *v22 = a3[(unsigned __int8)*v22];
                ++v22;
                *v22 = a3[(unsigned __int8)*v22];
                v20 = v22 + 1;
                --v21;
              }
              while ( v21 );
            }
          }
          else
          {
            result = a2;
            if ( v9 )
            {
              v40 = *a1;
              do
              {
                v23 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (result[1] >> a5)) + 2 * *result);
                result[1] = v23;
                *result = HIBYTE(v23);
                v24 = result + 2;
                v25 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v24[1] >> a5)) + 2 * *v24);
                v24[1] = v25;
                *v24 = HIBYTE(v25);
                v24 += 2;
                v26 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v24[1] >> a5)) + 2 * *v24);
                *v24 = HIBYTE(v26);
                v24[1] = v26;
                result = v24 + 2;
                --v40;
              }
              while ( v40 );
            }
          }
          break;
        case 4:
          if ( v8 == 8 )
          {
            v17 = a2;
            if ( v9 )
            {
              v18 = *a1;
              do
              {
                *v17 = a3[(unsigned __int8)*v17];
                v17 += 2;
                --v18;
              }
              while ( v18 );
            }
          }
          else
          {
            for ( result = a2; v9; --v9 )
            {
              v19 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (result[1] >> a5)) + 2 * *result);
              *result = HIBYTE(v19);
              result[1] = v19;
              result += 4;
            }
          }
          break;
        case 6:
          if ( v8 == 8 )
          {
            v10 = a2;
            if ( v9 )
            {
              v11 = *a1;
              do
              {
                *v10 = a3[(unsigned __int8)*v10];
                v12 = v10 + 1;
                *v12 = a3[(unsigned __int8)*v12];
                ++v12;
                *v12 = a3[(unsigned __int8)*v12];
                v10 = v12 + 2;
                --v11;
              }
              while ( v11 );
            }
          }
          else
          {
            result = a2;
            if ( v9 )
            {
              v39 = *a1;
              do
              {
                v13 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (result[1] >> a5)) + 2 * *result);
                result[1] = v13;
                *result = HIBYTE(v13);
                v14 = result + 2;
                v15 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v14[1] >> a5)) + 2 * *v14);
                v14[1] = v15;
                *v14 = HIBYTE(v15);
                v14 += 2;
                v16 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v14[1] >> a5)) + 2 * *v14);
                *v14 = HIBYTE(v16);
                v14[1] = v16;
                result = v14 + 4;
                --v39;
              }
              while ( v39 );
            }
          }
          break;
      }
    }
    else
    {
      if ( v8 == 2 )
      {
        v42 = a2;
        if ( v9 )
        {
          v41 = ((unsigned int)(v9 - 1) >> 2) + 1;
          do
          {
            v27 = *v42;
            v28 = *v42 & 0xC;
            v29 = *v42 & 0x30;
            LOBYTE(v28) = result[*v42 & 0xC0 | ((*v42 & 0xC0 | ((*v42 & 0xC0 | ((*v42 & 0xC0) >> 2)) >> 2)) >> 2)]
                        & 0xC0
                        | ((unsigned __int8)(result[v29 | (4 * v29) | ((v29 | (v29 >> 2)) >> 2)] & 0xC3
                                           | ((unsigned __int8)((result[v27 & 3
                                                                      | (4
                                                                       * (v27 & 3 | (4 * (v27 & 3 | (4 * (v27 & 3))))))] >> 2)
                                                              | result[v28
                                                                     | (v28 >> 2)
                                                                     | (4 * (v28 | (4 * (v27 & 0xC))))]
                                                              & 0xCF) >> 2)) >> 2);
            v30 = v42++;
            v31 = v41-- == 1;
            *v30 = v28;
          }
          while ( !v31 );
          v9 = v38;
          v7 = a1;
        }
      }
      v32 = *((_BYTE *)v7 + 9);
      switch ( v32 )
      {
        case 4:
          v33 = a2;
          if ( v9 )
          {
            v34 = ((unsigned int)(v9 - 1) >> 1) + 1;
            do
            {
              *v33 = (result[*v33 & 0xF | (16 * (*v33 & 0xF))] >> 4) | result[*v33 & 0xF0 | ((*v33 & 0xF0) >> 4)] & 0xF0;
              ++v33;
              --v34;
            }
            while ( v34 );
          }
          break;
        case 8:
          v35 = a2;
          if ( v9 )
          {
            v36 = v9;
            do
            {
              *v35 = result[(unsigned __int8)*v35];
              ++v35;
              --v36;
            }
            while ( v36 );
          }
          break;
        case 16:
          for ( result = a2; v9; --v9 )
          {
            v37 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (result[1] >> a5)) + 2 * *result);
            *result = HIBYTE(v37);
            result[1] = v37;
            result += 2;
          }
          break;
      }
    }
  }
  return result;
}
