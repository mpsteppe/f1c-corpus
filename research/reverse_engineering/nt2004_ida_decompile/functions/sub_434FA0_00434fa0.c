char __thiscall sub_434FA0(CHAR ***this)
{
  CHAR *v1; // eax
  char v2; // bl
  unsigned int v3; // kr04_4
  int v4; // esi
  int v5; // eax
  char *v6; // edx
  char v7; // cl
  int v8; // ebx
  int v9; // edi
  int v10; // ebp
  int v11; // esi
  int v12; // eax
  int v13; // ecx
  const char *v14; // eax
  const char *v15; // eax
  CHAR *v16; // eax
  int v17; // eax
  int v18; // eax
  _BYTE *v19; // eax
  const char *v20; // edi
  unsigned int v21; // kr08_4
  CHAR *v22; // eax
  char *v23; // ecx
  char *v24; // eax
  const char *v25; // eax
  bool v26; // zf
  const char *v28; // [esp-Ch] [ebp-354h]
  const char *v29; // [esp-Ch] [ebp-354h]
  const char *v30; // [esp-Ch] [ebp-354h]
  char v31; // [esp+Bh] [ebp-33Dh]
  int v32; // [esp+Ch] [ebp-33Ch]
  char *v33; // [esp+18h] [ebp-330h]
  int v34; // [esp+20h] [ebp-328h]
  int v35; // [esp+24h] [ebp-324h]
  int v36; // [esp+28h] [ebp-320h]
  char *FileName; // [esp+2Ch] [ebp-31Ch]
  int v38; // [esp+40h] [ebp-308h]
  char *String1; // [esp+44h] [ebp-304h]
  char Source[256]; // [esp+48h] [ebp-300h] BYREF
  char v41[256]; // [esp+148h] [ebp-200h] BYREF
  char v42[256]; // [esp+248h] [ebp-100h] BYREF

  v1 = **this;
  v2 = 0;
  v31 = 0;
  if ( !v1 )
    v1 = &byte_629120;
  sub_578600(v1);
  v3 = strlen(&byte_629120) + 1;
  v4 = sub_57AE50(off_5FE080);
  v38 = v4;
  _mkdir(&byte_629120);
  if ( dword_7D6B50 > 0 )
  {
    v35 = 0;
    v36 = dword_7D6B50;
    do
    {
      v5 = sub_435430((char *)(v35 + dword_7D6B58 + 260));
      String1 = (char *)v5;
      v6 = &Source[-v5];
      do
      {
        v7 = *(_BYTE *)v5;
        v6[v5] = *(_BYTE *)v5;
        ++v5;
      }
      while ( v7 );
      sub_4353E0(Source);
      v32 = 0;
      if ( v4 )
        v32 = sub_57A720(Source);
      if ( sub_41F230(dword_62A170, Source, Destination) )
      {
        strncpy(Destination, Source, 0x1FFu);
        byte_62A37B = 0;
      }
      sub_578560(Destination);
      sub_57B040(&byte_629120, 255);
      if ( !_mkdir(v42) )
      {
        v31 = 1;
        if ( v32 )
        {
          v34 = 0;
          while ( 1 )
          {
            v8 = 0;
            v9 = 0;
            v10 = sub_57A6E0(v32);
            v11 = 0;
            if ( v10 > 0 )
            {
              while ( 1 )
              {
                v12 = sub_57A700(v11);
                v13 = v9++;
                if ( v13 == v34 )
                  break;
                if ( ++v11 >= v10 )
                  goto LABEL_19;
              }
              v8 = v12;
            }
LABEL_19:
            ++v34;
            if ( !v8 )
              break;
            v28 = off_5FE088;
            v14 = (const char *)sub_57A6C0(v8);
            if ( _strcmpi(v14, v28) )
            {
              v29 = off_5FE08C;
              v15 = (const char *)sub_57A6C0(v8);
              if ( _strcmpi(v15, v29) )
                continue;
            }
            FileName = (char *)operator new(0x80u);
            *FileName = 0;
            v16 = *(CHAR **)dword_62A0D0;
            if ( !*(_DWORD *)dword_62A0D0 )
              v16 = &byte_629120;
            sub_578560(v16);
            v17 = sub_57A6D0(v8);
            sub_578560(v17);
            v18 = sub_57A6D0(v8);
            sub_578600(v18);
            v19 = (_BYTE *)sub_579060(&byte_629120, aSvm);
            if ( v19 )
              *v19 = 0;
            v33 = (char *)operator new(0x80u);
            *v33 = 0;
            sub_578560(&byte_629120);
            v20 = v33;
            if ( !v33 )
              v20 = &byte_629120;
            v21 = strlen(v20) + 1;
            if ( (int)(v21 - 1) > 0 )
            {
              v22 = v33;
              if ( !v33 )
                v22 = &byte_629120;
              if ( v22[v21 - 2] != 92 )
                sub_578560(word_5FB9F4);
            }
            if ( sub_41F230(dword_62A170, &byte_629120, Destination) )
            {
              if ( &byte_629120 )
              {
                strncpy(Destination, &byte_629120, 0x1FFu);
                byte_62A37B = 0;
              }
              else
              {
                Destination[0] = 0;
              }
            }
            sub_578560(Destination);
            sub_578560(aSvm);
            v23 = v33;
            if ( !v33 )
              v23 = &byte_629120;
            sub_57B040(v23, 255);
            v24 = FileName;
            if ( !FileName )
              v24 = &byte_629120;
            if ( (unsigned __int8)sub_57B530(v24, v41) )
            {
              v30 = off_5FE08C;
              v25 = (const char *)sub_57A6C0(v8);
              if ( !_strcmpi(v25, v30) )
                sub_4368C0((int)v41, String1);
            }
            if ( v33 )
              sub_5BE8AE(v33);
            if ( FileName )
              sub_5BE8AE(FileName);
          }
          v4 = v38;
        }
      }
      *(&byte_629120 + v3 - 1) = 0;
      v26 = v36 == 1;
      v35 += 400;
      --v36;
    }
    while ( !v26 );
    return v31;
  }
  return v2;
}
