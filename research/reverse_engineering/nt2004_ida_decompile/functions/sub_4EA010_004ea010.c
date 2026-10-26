char __thiscall sub_4EA010(_DWORD *this)
{
  _DWORD *v1; // ebp
  const char *v3; // edx
  const char *v4; // ecx
  const char *v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  _DWORD *v9; // eax
  LPVOID *v10; // eax
  LPVOID *v11; // ebp
  int v12; // eax
  int v13; // eax
  char v14; // cl
  char *v15; // eax
  CHAR *v16; // eax
  LPVOID **v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // esi
  int v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  _DWORD *v23; // esi
  int v24; // edx
  int v25; // eax
  int v26; // ecx
  bool v27; // cc
  const char *v28; // edx
  const char *v29; // ecx
  const char *v30; // eax
  int i; // eax
  _DWORD *v32; // eax
  _DWORD *v33; // esi
  _DWORD *v34; // eax
  int v35; // edx
  int v36; // eax
  char *v37; // edi
  void *v38; // ecx
  _DWORD *v39; // esi
  _DWORD *v40; // eax
  const char *v41; // ecx
  const char *v42; // eax
  int j; // edi
  _DWORD *v44; // eax
  _DWORD *v45; // esi
  _DWORD *v46; // eax
  _DWORD *v47; // eax
  char **v48; // eax
  char *v49; // eax
  int v51; // [esp+14h] [ebp-578h] BYREF
  _BYTE v52[28]; // [esp+18h] [ebp-574h] BYREF
  char v53[61]; // [esp+34h] [ebp-558h] BYREF
  __int16 v54; // [esp+71h] [ebp-51Bh]
  char v55; // [esp+73h] [ebp-519h]
  char FileName[509]; // [esp+74h] [ebp-518h] BYREF
  __int16 v57; // [esp+271h] [ebp-31Bh]
  char v58; // [esp+273h] [ebp-319h]
  char String[384]; // [esp+274h] [ebp-318h] BYREF
  int v60; // [esp+3F4h] [ebp-198h]
  char v61; // [esp+3F8h] [ebp-194h]
  int v62; // [esp+400h] [ebp-18Ch]
  int v63; // [esp+404h] [ebp-188h]
  int v64; // [esp+408h] [ebp-184h]
  char Buffer[384]; // [esp+40Ch] [ebp-180h] BYREF

  v1 = this;
  if ( this[25] )
    return 1;
  if ( dword_75CBA8 != 5 )
    sub_4BA730(aLoading, -1082130432, 1);
  sub_4EA920(v1);
  FileName[0] = byte_629120;
  memset(&FileName[1], 0, 0x1FCu);
  v57 = 0;
  v51 = 512;
  v58 = 0;
  sub_57A080(v52);
  v3 = (const char *)dword_62A118;
  if ( !dword_62A118 )
    v3 = &byte_629120;
  v4 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v4 = &byte_629120;
  v5 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v5 = &byte_629120;
  sub_405480(FileName, 0x1FFu, "%s%s%s%s", v5, v4, v3, aCreateacarIni);
  if ( (unsigned __int8)sub_57A2F0(FileName, 1) )
  {
    memset(Buffer, 0, sizeof(Buffer));
    v60 = 0;
    v64 = 0;
    v62 = 0;
    v63 = 0;
    v61 = 1;
    while ( sub_57A490(Buffer, 383) )
    {
      v6 = sub_577B60(String);
      if ( v6 )
      {
        if ( v6 == 2 || v6 == 4 )
          break;
      }
      else
      {
        sub_578110(aCompositeimage, (int)&v51, 0, 0, 0);
        if ( sub_577E50(String, aMasfile, (int)FileName) )
        {
          v7 = operator new(8u);
          v8 = v7;
          if ( v7 )
          {
            *v7 = 0;
            v7[1] = -1;
            sub_578600(FileName);
          }
          else
          {
            v8 = 0;
          }
          if ( v8 )
          {
            v9 = operator new(0xCu);
            if ( v9 )
            {
              *v9 = v8;
              v9[1] = 0;
              *((_BYTE *)v9 + 8) = 1;
            }
            else
            {
              v9 = 0;
            }
            if ( v1[16] )
            {
              *(_DWORD *)(v1[17] + 4) = v9;
            }
            else
            {
              v1[16] = v9;
              v1[18] = v9;
            }
            v1[17] = v9;
            ++v1[19];
          }
        }
        else if ( sub_577E50(String, aFont, (int)FileName) )
        {
          sub_4EC010(v1);
          v10 = (LPVOID *)operator new(0x1Cu);
          if ( v10 )
          {
            *v10 = 0;
            v10[1] = (LPVOID)-1;
            v10[2] = 0;
            v10[3] = (LPVOID)-1;
            v10[4] = 0;
            v10[5] = (LPVOID)-1;
            v10[6] = 0;
            v11 = v10;
          }
          else
          {
            v11 = 0;
          }
          sub_578600(FileName);
          while ( sub_57A490(Buffer, 383) )
          {
            v12 = sub_577B60(String);
            if ( v12 )
            {
              if ( v12 == 2 || v12 == 4 )
                break;
            }
            else if ( sub_577E50(String, aFile, (int)FileName) )
            {
              sub_578600(FileName);
              v53[0] = byte_629120;
              memset(&v53[1], 0, 0x3Cu);
              v54 = 0;
              v55 = 0;
              v13 = 0;
              do
              {
                v14 = FileName[v13];
                v53[v13++] = v14;
              }
              while ( v14 );
              v15 = &v53[strlen(v53)];
              if ( v15 > v53 )
              {
                while ( *v15 != 46 )
                {
                  if ( --v15 <= v53 )
                    goto LABEL_38;
                }
                *v15 = 0;
              }
LABEL_38:
              sub_578600(v53);
            }
          }
          v16 = (CHAR *)v11[2];
          if ( !v16 )
            v16 = &byte_629120;
          if ( sub_592A60(v11 + 6, v16, 0x20000) )
          {
            v11[6] = 0;
            sub_40D5B0(v11 + 4);
            sub_40D5B0(v11 + 2);
            sub_40D5B0(v11);
            sub_5BE8AE(v11);
          }
          else if ( v11 )
          {
            v17 = (LPVOID **)operator new(0xCu);
            if ( v17 )
            {
              *v17 = v11;
              v17[1] = 0;
              *((_BYTE *)v17 + 8) = 1;
            }
            else
            {
              v17 = 0;
            }
            if ( this[4] )
            {
              *(_DWORD *)(this[5] + 4) = v17;
            }
            else
            {
              this[4] = v17;
              this[6] = v17;
            }
            this[5] = v17;
            ++this[7];
          }
        }
        else if ( sub_577E50(String, aDecal, (int)FileName) )
        {
          v18 = operator new(0x2Cu);
          if ( v18 )
          {
            *v18 = 0;
            v18[1] = -1;
            v18[2] = 0;
            v18[3] = 0;
            v18[4] = -1;
            v18[5] = -1;
            *((_WORD *)v18 + 12) = 0;
            v18[7] = 0;
            v18[8] = -1;
            *((_WORD *)v18 + 18) = -1;
            v18[10] = 0;
            v19 = v18;
          }
          else
          {
            v19 = 0;
          }
          sub_578600(FileName);
          v19[2] = 1;
          *((_WORD *)v19 + 12) = 10;
          while ( sub_57A490(Buffer, 383) )
          {
            v20 = sub_577B60(String);
            if ( v20 )
            {
              if ( v20 == 2 || v20 == 4 )
                break;
            }
            else if ( sub_577E50(String, aFile, (int)FileName) || sub_577E50(String, aModel, (int)FileName) )
            {
              sub_578600(FileName);
            }
          }
          v21 = operator new(0xCu);
          if ( v21 )
          {
            *v21 = v19;
            v21[1] = 0;
            *((_BYTE *)v21 + 8) = 1;
          }
          else
          {
            v21 = 0;
          }
          if ( v1[8] )
          {
            *(_DWORD *)(v1[9] + 4) = v21;
          }
          else
          {
            v1[8] = v21;
            v1[10] = v21;
          }
          v1[9] = v21;
          ++v1[11];
        }
      }
      v1 = this;
    }
    sub_57A360(v52);
  }
  sub_4EC230(v1);
  v22 = operator new(4u);
  if ( v22 )
  {
    *v22 = 0;
    v23 = v22;
  }
  else
  {
    v23 = 0;
  }
  v24 = v51;
  v25 = 1;
  v26 = 0;
  v27 = v51 <= 1;
  v1[25] = v23;
  if ( !v27 )
  {
    do
      v25 = 1 << ++v26;
    while ( v24 > 1 << v26 );
  }
  v51 = v25;
  if ( !sub_41C830(v23, v25, v25) )
    goto LABEL_141;
  v28 = (const char *)dword_62A118;
  if ( !dword_62A118 )
    v28 = &byte_629120;
  v29 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v29 = &byte_629120;
  v30 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v30 = &byte_629120;
  sub_405480(FileName, 0x1FFu, "%s%s%s", v30, v29, v28);
  sub_578A30(aSkn, 0, FileName, 0);
  sub_578E30(0);
  for ( i = sub_578D80(&unk_7D7A0C); i; i = sub_578D80(&unk_7D7A0C) )
  {
    sub_4EC7F0(i);
    sub_5789D0(&unk_7D7A0C);
  }
  if ( !(*(unsigned __int8 (__thiscall **)(int, char *, int))(*(_DWORD *)dword_76BB24 + 104))(
          dword_76BB24,
          FileName,
          511)
    || _access(FileName, 0) == -1 )
  {
    sub_4CD5B0(byte_7663E0, FileName, 511);
    v35 = dword_5FC048;
    v36 = dword_5FC04C;
    v37 = &FileName[strlen(FileName)];
    *(_DWORD *)v37 = dword_5FC044;
    v38 = off_5FC050;
    *((_DWORD *)v37 + 1) = v35;
    *((_DWORD *)v37 + 2) = v36;
    *((_DWORD *)v37 + 3) = v38;
    if ( _access(FileName, 0) == -1 )
    {
      v41 = (const char *)dword_62A120;
      if ( !dword_62A120 )
        v41 = &byte_629120;
      v42 = *(const char **)dword_62A0D0;
      if ( !*(_DWORD *)dword_62A0D0 )
        v42 = &byte_629120;
      sub_405480(FileName, 0x1FFu, "%s%s", v42, v41);
      sub_578A30(aSkn, 0, FileName, 0);
      for ( j = sub_578D80(&unk_7D7A0C); j; j = sub_578D80(&unk_7D7A0C) )
      {
        v44 = operator new(8u);
        v45 = v44;
        if ( v44 )
        {
          *v44 = 0;
          v44[1] = -1;
          sub_578600(j);
          v46 = operator new(0xCu);
          if ( v46 )
          {
            *v46 = v45;
            v46[1] = 0;
            *((_BYTE *)v46 + 8) = 1;
          }
          else
          {
            v46 = 0;
          }
          if ( v1[12] )
          {
            *(_DWORD *)(v1[13] + 4) = v46;
          }
          else
          {
            v1[12] = v46;
            v1[14] = v46;
          }
          v1[13] = v46;
          ++v1[15];
        }
        sub_5789D0(&unk_7D7A0C);
      }
    }
    else
    {
      v39 = operator new(8u);
      if ( v39 )
      {
        *v39 = 0;
        v39[1] = -1;
        sub_578600(FileName);
      }
      else
      {
        v39 = 0;
      }
      if ( v39 )
      {
        v40 = operator new(0xCu);
        if ( v40 )
        {
          *v40 = v39;
          v40[1] = 0;
          *((_BYTE *)v40 + 8) = 1;
        }
        else
        {
          v40 = 0;
        }
        if ( v1[12] )
        {
          *(_DWORD *)(v1[13] + 4) = v40;
        }
        else
        {
          v1[12] = v40;
          v1[14] = v40;
        }
        v1[13] = v40;
        ++v1[15];
      }
    }
  }
  else
  {
    v32 = operator new(8u);
    v33 = v32;
    if ( v32 )
    {
      *v32 = 0;
      v32[1] = -1;
      sub_578600(FileName);
    }
    else
    {
      v33 = 0;
    }
    if ( v33 )
    {
      v34 = operator new(0xCu);
      if ( v34 )
      {
        *v34 = v33;
        v34[1] = 0;
        *((_BYTE *)v34 + 8) = 1;
      }
      else
      {
        v34 = 0;
      }
      if ( v1[12] )
      {
        *(_DWORD *)(v1[13] + 4) = v34;
      }
      else
      {
        v1[12] = v34;
        v1[14] = v34;
      }
      v1[13] = v34;
      ++v1[15];
    }
  }
  if ( (int)v1[15] <= 0 )
    goto LABEL_141;
  v47 = (_DWORD *)v1[12];
  v48 = v47 ? (char **)*v47 : 0;
  v49 = *v48;
  if ( !v49 )
    v49 = &byte_629120;
  if ( (unsigned __int8)sub_4EABE0(v49) )
  {
    sub_57A0A0(v52);
    return 1;
  }
  else
  {
LABEL_141:
    sub_4EA920(v1);
    sub_57A0A0(v52);
    return 0;
  }
}
