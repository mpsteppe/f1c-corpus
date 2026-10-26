void __stdcall sub_6BA0B6(int *a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // esi
  char *v8; // ebx
  char *v9; // edi
  _BYTE *v10; // edi
  _BYTE *v11; // esi
  char v12; // al
  _BYTE *v13; // edi
  _BYTE *v14; // esi
  char v15; // al
  _BYTE *v16; // edi
  _BYTE *v17; // esi
  char v18; // al
  unsigned int v19; // ecx
  char v20[4]; // [esp+0h] [ebp-14h] BYREF
  int v21; // [esp+4h] [ebp-10h]
  unsigned int v22; // [esp+8h] [ebp-Ch]
  int v23; // [esp+Ch] [ebp-8h]
  unsigned int v24; // [esp+10h] [ebp-4h]
  char *v25; // [esp+20h] [ebp+Ch]
  char v26; // [esp+23h] [ebp+Fh]
  char v27; // [esp+23h] [ebp+Fh]
  char v28; // [esp+23h] [ebp+Fh]
  int v29; // [esp+24h] [ebp+10h]
  int v30; // [esp+24h] [ebp+10h]
  int v31; // [esp+24h] [ebp+10h]

  if ( a2 && a1 )
  {
    v4 = *a1;
    v5 = dword_745298[a3] * *a1;
    v23 = dword_745298[a3];
    v6 = *((unsigned __int8 *)a1 + 11);
    if ( v6 == 1 )
    {
      v22 = 0;
      v16 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 3));
      v17 = (_BYTE *)(a2 + ((unsigned int)(v5 - 1) >> 3));
      v24 = 7 - (((_BYTE)v4 - 1) & 7);
      v31 = 7 - (((_BYTE)v5 - 1) & 7);
      if ( v4 )
      {
        do
        {
          v18 = (*v16 >> v24) & 1;
          v28 = v18;
          if ( v23 > 0 )
          {
            v21 = v23;
            while ( 1 )
            {
              *v17 = (v18 << v31) | *v17 & (32639 >> (7 - v31));
              if ( v31 == 7 )
              {
                v31 = 0;
                --v17;
              }
              else
              {
                ++v31;
              }
              if ( !--v21 )
                break;
              v18 = v28;
            }
          }
          if ( v24 == 7 )
          {
            v24 = 0;
            --v16;
          }
          else
          {
            ++v24;
          }
          ++v22;
        }
        while ( v22 < *a1 );
      }
    }
    else if ( *((_BYTE *)a1 + 11) == 2 )
    {
      v22 = 0;
      v13 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 2));
      v14 = (_BYTE *)(a2 + ((unsigned int)(v5 - 1) >> 2));
      v24 = 2 * (3 - (((_BYTE)v4 - 1) & 3));
      v30 = 2 * (3 - (((_BYTE)v5 - 1) & 3));
      if ( v4 )
      {
        do
        {
          v15 = (*v13 >> v24) & 3;
          v27 = v15;
          if ( v23 > 0 )
          {
            v21 = v23;
            while ( 1 )
            {
              *v14 = (v15 << v30) | *v14 & (16191 >> (6 - v30));
              if ( v30 == 6 )
              {
                v30 = 0;
                --v14;
              }
              else
              {
                v30 += 2;
              }
              if ( !--v21 )
                break;
              v15 = v27;
            }
          }
          if ( v24 == 6 )
          {
            v24 = 0;
            --v13;
          }
          else
          {
            v24 += 2;
          }
          ++v22;
        }
        while ( v22 < *a1 );
      }
    }
    else if ( *((_BYTE *)a1 + 11) == 4 )
    {
      v22 = 0;
      v10 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 1));
      v11 = (_BYTE *)(a2 + ((unsigned int)(v5 - 1) >> 1));
      v24 = 4 - 4 * (((_BYTE)v4 - 1) & 1);
      v29 = 4 - 4 * (((_BYTE)v5 - 1) & 1);
      if ( v4 )
      {
        do
        {
          v12 = (*v10 >> v24) & 0xF;
          v26 = v12;
          if ( v23 > 0 )
          {
            v21 = v23;
            while ( 1 )
            {
              *v11 = (v12 << v29) | *v11 & (3855 >> (4 - v29));
              if ( v29 == 4 )
              {
                v29 = 0;
                --v11;
              }
              else
              {
                v29 += 4;
              }
              if ( !--v21 )
                break;
              v12 = v26;
            }
          }
          if ( v24 == 4 )
          {
            v24 = 0;
            --v10;
          }
          else
          {
            v24 += 4;
          }
          ++v22;
        }
        while ( v22 < *a1 );
      }
    }
    else
    {
      v24 = 0;
      v7 = v6 >> 3;
      v8 = (char *)(a2 + v7 * (v4 - 1));
      v25 = (char *)(a2 + v7 * (v5 - 1));
      if ( v4 )
      {
        do
        {
          qmemcpy(v20, v8, v7);
          if ( v23 > 0 )
          {
            v22 = v23;
            do
            {
              v9 = v25;
              v25 -= v7;
              qmemcpy(v9, v20, v7);
              --v22;
            }
            while ( v22 );
          }
          v8 -= v7;
          ++v24;
        }
        while ( v24 < *a1 );
      }
    }
    v19 = (v5 * (unsigned int)*((unsigned __int8 *)a1 + 11) + 7) >> 3;
    *a1 = v5;
    a1[1] = v19;
  }
}
