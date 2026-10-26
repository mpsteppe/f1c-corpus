_DWORD *__thiscall sub_4EB6C0(_DWORD *this, char *Source)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // eax
  _DWORD *v11; // eax
  int *v12; // eax
  int v13; // edi
  const char *v14; // eax
  const char *v15; // ecx
  const char *v16; // eax
  _DWORD *v17; // ecx
  int v18; // eax
  int *v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // esi
  CHAR *v22; // eax
  CHAR *v23; // eax
  CHAR *v24; // eax
  _DWORD *v25; // eax
  _DWORD *v26; // eax
  _DWORD *v27; // esi
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  _DWORD *v30; // esi
  int v31; // eax
  _DWORD *v32; // eax
  _DWORD *v34; // [esp+4h] [ebp-450h]
  int v35; // [esp+8h] [ebp-44Ch]
  int v36; // [esp+Ch] [ebp-448h] BYREF
  int v37; // [esp+10h] [ebp-444h] BYREF
  int v38; // [esp+14h] [ebp-440h] BYREF
  _DWORD *v39; // [esp+18h] [ebp-43Ch]
  int v40; // [esp+1Ch] [ebp-438h]
  char v41[28]; // [esp+20h] [ebp-434h] BYREF
  char String1[253]; // [esp+3Ch] [ebp-418h] BYREF
  __int16 v43; // [esp+139h] [ebp-31Bh]
  char v44; // [esp+13Bh] [ebp-319h]
  char String[384]; // [esp+13Ch] [ebp-318h] BYREF
  int v46; // [esp+2BCh] [ebp-198h]
  char v47; // [esp+2C0h] [ebp-194h]
  int v48; // [esp+2C8h] [ebp-18Ch]
  int v49; // [esp+2CCh] [ebp-188h]
  int v50; // [esp+2D0h] [ebp-184h]
  char Buffer[384]; // [esp+2D4h] [ebp-180h] BYREF

  v39 = this;
  sub_57A080(v41);
  if ( (unsigned __int8)sub_57A2F0(Source, 1) )
  {
    memset(Buffer, 0, sizeof(Buffer));
    String1[0] = byte_629120;
    memset(&String1[1], 0, 0xFCu);
    v43 = 0;
    v46 = 0;
    v50 = 0;
    v48 = 0;
    v49 = 0;
    v47 = 1;
    v44 = 0;
    v40 = 0;
    v35 = 11;
    v2 = operator new(0x90u);
    v3 = v2;
    if ( v2 )
    {
      *(_BYTE *)v2 = 0;
      v2[1] = 0;
      v2[2] = -1;
      v2[3] = 0;
      v2[4] = -1;
      v2[5] = 0;
      v2[6] = -1;
      v2[7] = 0;
      v2[8] = -1;
      v2[9] = 0;
      v2[10] = 0;
      v2[11] = 0;
      v2[12] = 0;
      v2[13] = 0;
      v2[14] = 0;
      v2[15] = 0;
      v2[16] = 0;
      v2[17] = 0;
      v2[18] = 0;
      v2[19] = 0;
      v2[20] = 0;
      sub_414400(v2 + 21);
      sub_4EBFE0(v3 + 25);
      v34 = v3;
    }
    else
    {
      v34 = 0;
      v3 = 0;
    }
    sub_578600(Source);
    while ( sub_57A490(Buffer, 383) )
    {
      v4 = sub_577B60(String);
      if ( v4 )
      {
        if ( v4 == 2 || v4 == 4 )
          break;
      }
      else
      {
        if ( sub_577E50(String, aStyle, (int)String1)
          || sub_577E50(String, aSkin, (int)String1)
          || sub_577E50(String, aModel, (int)String1) )
        {
          goto LABEL_117;
        }
        if ( sub_577E50(String, aMasfile, (int)String1) )
        {
          v5 = operator new(8u);
          if ( v5 )
          {
            *v5 = 0;
            v5[1] = -1;
            sub_578600(String1);
          }
          else
          {
            v5 = 0;
          }
          if ( v5 )
          {
            v6 = operator new(0xCu);
            if ( v6 )
            {
              *v6 = v5;
              v6[1] = 0;
              *((_BYTE *)v6 + 8) = 1;
            }
            else
            {
              v6 = 0;
            }
            if ( v34[9] )
            {
              *(_DWORD *)(v34[10] + 4) = v6;
            }
            else
            {
              v34[9] = v6;
              v34[11] = v6;
            }
            v34[10] = v6;
            ++v34[12];
          }
          goto LABEL_120;
        }
        if ( sub_577E50(String, aLayer, (int)String1) )
        {
          v7 = operator new(0x2Cu);
          if ( v7 )
          {
            *v7 = 0;
            v7[1] = -1;
            v7[2] = 0;
            v7[3] = 0;
            v7[4] = -1;
            v7[5] = -1;
            *((_WORD *)v7 + 12) = 0;
            v7[7] = 0;
            v7[8] = -1;
            *((_WORD *)v7 + 18) = -1;
            v7[10] = 0;
            v8 = v7;
          }
          else
          {
            v8 = 0;
          }
          sub_578600(String1);
          v9 = v40;
          *((_WORD *)v8 + 12) = v40;
          v40 = v9 + 1;
          while ( sub_57A490(Buffer, 383) )
          {
            v10 = sub_577B60(String);
            if ( v10 )
            {
              if ( v10 == 2 || v10 == 4 )
                break;
            }
            else if ( sub_578110(EndPtr, (int)&v38, (int)&v37, (int)&v36, 0) )
            {
              v8[5] = v36 | ((v37 | ((v38 | 0xFFFFFF00) << 8)) << 8);
            }
            else if ( sub_577E50(String, aName_0, (int)String1) )
            {
              sub_578600(String1);
            }
            else if ( sub_577E50(String, aType, (int)String1) )
            {
              if ( _strcmpi(String1, aDecal) )
              {
                if ( _strcmpi(String1, aDetail) )
                {
                  if ( _strcmpi(String1, aSponsor) )
                    v8[2] = 0;
                  else
                    v8[2] = 3;
                }
                else
                {
                  v8[2] = 2;
                }
              }
              else
              {
                v8[2] = 1;
                *((_WORD *)v8 + 12) = 10;
              }
            }
          }
          v11 = operator new(0xCu);
          if ( v11 )
          {
            *v11 = v8;
            v11[1] = 0;
            *((_BYTE *)v11 + 8) = 1;
          }
          else
          {
            v11 = 0;
          }
          if ( v34[13] )
          {
            *(_DWORD *)(v34[14] + 4) = v11;
          }
          else
          {
            v34[13] = v11;
            v34[15] = v11;
          }
          v34[14] = v11;
          ++v34[16];
          goto LABEL_120;
        }
        if ( sub_577E50(String, aDecal, (int)String1) )
        {
          v12 = (int *)v39[8];
          v39[10] = v12;
          if ( v12 )
          {
            v13 = *v12;
            if ( *v12 )
            {
              while ( 1 )
              {
                v14 = *(const char **)v13;
                if ( !*(_DWORD *)v13 )
                  v14 = &byte_629120;
                if ( !_strcmpi(String1, v14) )
                {
                  v15 = *(const char **)(v13 + 28);
                  if ( !v15 )
                    v15 = &byte_629120;
                  v16 = (const char *)v34[5];
                  if ( !v16 )
                    v16 = &byte_629120;
                  if ( !_strcmpi(v16, v15) )
                    break;
                }
                v17 = v39;
                v18 = v39[10];
                if ( v18 )
                  v39[10] = *(_DWORD *)(v18 + 4);
                v19 = (int *)v17[10];
                if ( v19 )
                {
                  v13 = *v19;
                  if ( *v19 )
                    continue;
                }
                goto LABEL_120;
              }
              v20 = operator new(0x2Cu);
              if ( v20 )
              {
                *v20 = 0;
                v20[1] = -1;
                v20[2] = 0;
                v20[3] = 0;
                v20[4] = -1;
                v20[5] = -1;
                *((_WORD *)v20 + 12) = 0;
                v20[7] = 0;
                v20[8] = -1;
                *((_WORD *)v20 + 18) = -1;
                v20[10] = 0;
                v21 = v20;
              }
              else
              {
                v21 = 0;
              }
              v22 = *(CHAR **)v13;
              if ( !*(_DWORD *)v13 )
                v22 = &byte_629120;
              sub_578600(v22);
              v21[2] = *(_DWORD *)(v13 + 8);
              v23 = *(CHAR **)(v13 + 12);
              if ( !v23 )
                v23 = &byte_629120;
              sub_578600(v23);
              v21[5] = *(_DWORD *)(v13 + 20);
              *((_WORD *)v21 + 12) = *(_WORD *)(v13 + 24);
              v24 = *(CHAR **)(v13 + 28);
              if ( !v24 )
                v24 = &byte_629120;
              sub_578600(v24);
              *((_WORD *)v21 + 18) = *(_WORD *)(v13 + 36);
              if ( v21[10] )
                sub_592310(v21[10]);
              v21[10] = *(_DWORD *)(v13 + 40);
              *(_DWORD *)(v13 + 40) = 0;
              v25 = operator new(0xCu);
              if ( v25 )
              {
                *v25 = v21;
                v25[1] = 0;
                *((_BYTE *)v25 + 8) = 1;
              }
              else
              {
                v25 = 0;
              }
              if ( v34[17] )
              {
                *(_DWORD *)(v34[18] + 4) = v25;
              }
              else
              {
                v34[17] = v25;
                v34[19] = v25;
              }
              v34[18] = v25;
              ++v34[20];
            }
          }
          goto LABEL_120;
        }
        if ( sub_577E50(String, aStamp, (int)String1) )
        {
          v26 = operator new(0x2Cu);
          if ( v26 )
          {
            *v26 = 0;
            v26[1] = -1;
            v26[2] = 0;
            v26[3] = 0;
            v26[4] = -1;
            v26[5] = -1;
            *((_WORD *)v26 + 12) = 0;
            v26[7] = 0;
            v26[8] = -1;
            *((_WORD *)v26 + 18) = -1;
            v26[10] = 0;
            v27 = v26;
          }
          else
          {
            v27 = 0;
          }
          sub_578600(String1);
          *((_WORD *)v27 + 12) = v35;
          v27[2] = 2;
          ++v35;
          v28 = operator new(0xCu);
          if ( v28 )
          {
            *v28 = v27;
            v28[1] = 0;
            *((_BYTE *)v28 + 8) = 1;
          }
          else
          {
            v28 = 0;
          }
          if ( v34[17] )
          {
            *(_DWORD *)(v34[18] + 4) = v28;
          }
          else
          {
            v34[17] = v28;
            v34[19] = v28;
          }
          v34[18] = v28;
          ++v34[20];
          goto LABEL_120;
        }
        if ( sub_577E50(String, aWord, (int)String1) )
        {
          v29 = operator new(0x2Cu);
          if ( v29 )
          {
            *v29 = 0;
            v29[1] = -1;
            v29[2] = 0;
            v29[3] = 0;
            v29[4] = 0;
            v29[5] = 0;
            v29[6] = -1;
            v29[7] = -1;
            v29[8] = 0;
            v29[9] = 0;
            *((_WORD *)v29 + 20) = 0;
            v30 = v29;
          }
          else
          {
            v30 = 0;
          }
          sub_578600(String1);
          *((_WORD *)v30 + 20) = v35++;
          while ( sub_57A490(Buffer, 383) )
          {
            v31 = sub_577B60(String);
            if ( v31 )
            {
              if ( v31 == 2 || v31 == 4 )
                break;
            }
            else
            {
              sub_578220(off_6110A4, (int)(v30 + 2), (int)(v30 + 3), 0, 0, 0, 0, 0, 0);
              sub_578220(off_6110A0, (int)(v30 + 4), 0, 0, 0, 0, 0, 0, 0);
              sub_578220(aSize, (int)(v30 + 8), (int)(v30 + 9), 0, 0, 0, 0, 0, 0);
              if ( sub_577E50(String, aFont, (int)String1) )
              {
                sub_578600(String1);
              }
              else if ( sub_578110(EndPtr, (int)&v38, (int)&v37, (int)&v36, 0) )
              {
                v30[7] = v36 | ((v37 | ((v38 | 0xFFFFFF00) << 8)) << 8);
              }
            }
          }
          v32 = operator new(0xCu);
          if ( v32 )
          {
            *v32 = v30;
            v32[1] = 0;
            *((_BYTE *)v32 + 8) = 1;
          }
          else
          {
            v32 = 0;
          }
          if ( v34[21] )
          {
            *(_DWORD *)(v34[22] + 4) = v32;
          }
          else
          {
            v34[21] = v32;
            v34[23] = v32;
          }
          v34[22] = v32;
          ++v34[24];
          goto LABEL_120;
        }
        if ( sub_577E50(String, aAlphastamp, (int)String1) )
LABEL_117:
          sub_578600(String1);
      }
LABEL_120:
      v3 = v34;
    }
    sub_4E9BB0(v3);
    sub_57A360(v41);
    sub_57A0A0(v41);
    return v3;
  }
  else
  {
    sub_57A0A0(v41);
    return 0;
  }
}
