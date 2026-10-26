void __cdecl sub_5551D6(int *a1, int a2, int a3)
{
  int v3; // eax
  int v4; // edx
  unsigned int v5; // esi
  unsigned int v6; // esi
  char *v7; // ebx
  char v8; // al
  unsigned int v9; // ecx
  _BYTE *v10; // edi
  char *v11; // esi
  int v12; // eax
  bool v13; // cc
  void *v14; // edi
  _BYTE *v15; // edi
  _BYTE *v16; // esi
  char v17; // al
  bool v18; // zf
  _BYTE *v19; // edi
  _BYTE *v20; // esi
  char v21; // al
  _BYTE *v22; // edi
  _BYTE *v23; // esi
  char v24; // al
  unsigned int v25; // ecx
  _BYTE v26[4]; // [esp+0h] [ebp-18h] BYREF
  int v27; // [esp+4h] [ebp-14h]
  unsigned int v28; // [esp+8h] [ebp-10h]
  int v29; // [esp+Ch] [ebp-Ch]
  unsigned int v30; // [esp+10h] [ebp-8h]
  unsigned int v31; // [esp+14h] [ebp-4h]
  char *v32; // [esp+24h] [ebp+Ch]
  char v33; // [esp+27h] [ebp+Fh]
  char v34; // [esp+27h] [ebp+Fh]
  char v35; // [esp+27h] [ebp+Fh]

  if ( a2 && a1 )
  {
    v3 = *a1;
    v4 = dword_5F505C[a3] * *a1;
    v29 = dword_5F505C[a3];
    v5 = *((unsigned __int8 *)a1 + 11);
    if ( v5 == 1 )
    {
      v28 = 0;
      v22 = (_BYTE *)(a2 + ((unsigned int)(v3 - 1) >> 3));
      v23 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 3));
      v30 = 7 - (((_BYTE)v3 - 1) & 7);
      v31 = 7 - (((_BYTE)v4 - 1) & 7);
      if ( v3 )
      {
        do
        {
          v24 = (*v22 >> v30) & 1;
          v35 = v24;
          if ( v29 > 0 )
          {
            v27 = v29;
            while ( 1 )
            {
              v18 = v31 == 7;
              *v23 = (v24 << v31) | *v23 & (32639 >> (7 - v31));
              if ( v18 )
              {
                v31 = 0;
                --v23;
              }
              else
              {
                ++v31;
              }
              if ( !--v27 )
                break;
              v24 = v35;
            }
          }
          if ( v30 == 7 )
          {
            v30 = 0;
            --v22;
          }
          else
          {
            ++v30;
          }
          ++v28;
        }
        while ( v28 < *a1 );
      }
    }
    else if ( *((_BYTE *)a1 + 11) == 2 )
    {
      v28 = 0;
      v19 = (_BYTE *)(a2 + ((unsigned int)(v3 - 1) >> 2));
      v20 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 2));
      v30 = 2 * (3 - (((_BYTE)v3 - 1) & 3));
      v31 = 2 * (3 - (((_BYTE)v4 - 1) & 3));
      if ( v3 )
      {
        do
        {
          v21 = (*v19 >> v30) & 3;
          v34 = v21;
          if ( v29 > 0 )
          {
            v27 = v29;
            while ( 1 )
            {
              v18 = v31 == 6;
              *v20 = (v21 << v31) | *v20 & (16191 >> (6 - v31));
              if ( v18 )
              {
                v31 = 0;
                --v20;
              }
              else
              {
                v31 += 2;
              }
              if ( !--v27 )
                break;
              v21 = v34;
            }
          }
          if ( v30 == 6 )
          {
            v30 = 0;
            --v19;
          }
          else
          {
            v30 += 2;
          }
          ++v28;
        }
        while ( v28 < *a1 );
      }
    }
    else if ( *((_BYTE *)a1 + 11) == 4 )
    {
      v28 = 0;
      v15 = (_BYTE *)(a2 + ((unsigned int)(v3 - 1) >> 1));
      v16 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 1));
      v30 = 4 - 4 * (((_BYTE)v3 - 1) & 1);
      v31 = 4 - 4 * (((_BYTE)v4 - 1) & 1);
      if ( v3 )
      {
        do
        {
          v17 = (*v15 >> v30) & 0xF;
          v33 = v17;
          if ( v29 > 0 )
          {
            v27 = v29;
            while ( 1 )
            {
              v18 = v31 == 4;
              *v16 = (v17 << v31) | *v16 & (3855 >> (4 - v31));
              if ( v18 )
              {
                v31 = 0;
                --v16;
              }
              else
              {
                v31 += 4;
              }
              if ( !--v27 )
                break;
              v17 = v33;
            }
          }
          if ( v30 == 4 )
          {
            v30 = 0;
            --v15;
          }
          else
          {
            v30 += 4;
          }
          ++v28;
        }
        while ( v28 < *a1 );
      }
    }
    else
    {
      v31 = 0;
      v6 = v5 >> 3;
      v7 = (char *)(a2 + v6 * (v3 - 1));
      v30 = v6;
      v32 = (char *)(a2 + v6 * (v4 - 1));
      if ( v3 )
      {
        do
        {
          v8 = v30;
          v9 = v30 >> 2;
          qmemcpy(v26, v7, 4 * (v30 >> 2));
          v11 = &v7[4 * v9];
          v10 = &v26[4 * v9];
          LOBYTE(v9) = v8;
          v12 = v29;
          v13 = v29 <= 0;
          qmemcpy(v10, v11, v9 & 3);
          if ( !v13 )
          {
            v28 = v12;
            do
            {
              v14 = v32;
              v32 -= v30;
              qmemcpy(v14, v26, v30);
              --v28;
            }
            while ( v28 );
          }
          v7 -= v30;
          ++v31;
        }
        while ( v31 < *a1 );
      }
    }
    v25 = (v4 * (unsigned int)*((unsigned __int8 *)a1 + 11) + 7) >> 3;
    *a1 = v4;
    a1[1] = v25;
  }
}
