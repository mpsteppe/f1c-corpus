char __thiscall sub_432220(char ***this)
{
  char **v1; // ecx
  char *v2; // eax
  int v3; // esi
  int v4; // edi
  int v5; // eax
  char *v6; // edx
  char v7; // cl
  int v8; // eax
  char v9; // cl
  char *v10; // eax
  int i; // ebp
  char *v12; // eax
  int v13; // eax
  int v14; // eax
  char *v15; // ecx
  _BYTE *v16; // eax
  LPCSTR v17; // eax
  const char *v18; // edi
  unsigned int v19; // kr08_4
  const char *v20; // esi
  LPCSTR v21; // eax
  bool v22; // zf
  char v24; // [esp+8h] [ebp-334h]
  char v25; // [esp+9h] [ebp-333h]
  bool v26; // [esp+Ah] [ebp-332h]
  char v27; // [esp+Bh] [ebp-331h]
  char *v28[2]; // [esp+Ch] [ebp-330h] BYREF
  LPCSTR lpPathName; // [esp+14h] [ebp-328h]
  int v30; // [esp+18h] [ebp-324h]
  int v31; // [esp+1Ch] [ebp-320h]
  _BYTE *v32; // [esp+20h] [ebp-31Ch]
  int v33; // [esp+24h] [ebp-318h]
  char *v34; // [esp+28h] [ebp-314h]
  int v35; // [esp+2Ch] [ebp-310h]
  int v36; // [esp+30h] [ebp-30Ch]
  unsigned int v37; // [esp+34h] [ebp-308h]
  int v38; // [esp+38h] [ebp-304h]
  char v39[256]; // [esp+3Ch] [ebp-300h] BYREF
  _BYTE v40[256]; // [esp+13Ch] [ebp-200h] BYREF
  CHAR PathName[256]; // [esp+23Ch] [ebp-100h] BYREF

  v1 = *this;
  lpPathName = 0;
  v30 = -1;
  v2 = *v1;
  v25 = 0;
  if ( !*v1 )
    v2 = &byte_5EA438;
  sub_566650(v2);
  v37 = strlen(&byte_5EA438);
  v26 = sub_589671(&byte_5EA438) == 0;
  if ( dword_8AC488 > 0 )
  {
    v31 = 0;
    v36 = dword_8AC488;
    do
    {
      v3 = v31 + dword_8AC490 + 260;
      v4 = sub_4C5840(v3);
      v5 = sub_4326A0(v3);
      v38 = v5;
      v6 = &v39[-v5];
      do
      {
        v7 = *(_BYTE *)v5;
        v6[v5] = *(_BYTE *)v5;
        ++v5;
      }
      while ( v7 );
      sub_432650(v39);
      if ( sub_423A00(byte_5EC4C0, v39, byte_5EC4CC) )
      {
        v8 = 0;
        do
        {
          v9 = v39[v8];
          byte_5EC4CC[v8++] = v9;
        }
        while ( v9 );
      }
      sub_5665B0(byte_5EC4CC);
      sub_568620(255);
      sub_589671(PathName);
      v24 = 0;
      if ( byte_7D03F8 )
      {
        v10 = (char *)dword_7CE5EC;
        if ( !dword_7CE5EC )
          v10 = &byte_5EA438;
        if ( !sub_588410(v3, v10) )
          v24 = 1;
      }
      if ( v26 || v24 )
      {
        v25 = 1;
        if ( v4 )
        {
          v27 = 1;
          for ( i = sub_5679C0(off_5C3FA8[0]); i; i = sub_49ADB0(i) )
          {
            v32 = (_BYTE *)sub_587C03(128);
            *v32 = 0;
            v12 = (char *)dword_5EC440;
            v33 = 128;
            if ( !dword_5EC440 )
              v12 = &byte_5EA438;
            sub_5665B0(v12);
            v13 = sub_567970(i);
            sub_5665B0(v13);
            v34 = 0;
            v35 = -1;
            v14 = sub_567970(i);
            sub_566650(v14);
            v15 = v34;
            if ( !v34 )
              v15 = &byte_5EA438;
            v16 = (_BYTE *)sub_566810(v15, aSvm);
            if ( v16 )
              *v16 = 0;
            v28[0] = (char *)sub_587C03(128);
            *v28[0] = 0;
            v17 = lpPathName;
            v28[1] = (char *)128;
            if ( !lpPathName )
              v17 = &byte_5EA438;
            sub_5665B0(v17);
            v18 = v28[0];
            if ( !v28[0] )
              v18 = &byte_5EA438;
            v19 = strlen(v18) + 1;
            if ( (int)(v19 - 1) > 0 && sub_415C30(v28)[v19 - 2] != 92 )
              sub_5665B0(&word_5C2AAC);
            v20 = v34;
            if ( !v34 )
              v20 = &byte_5EA438;
            if ( sub_423A00(byte_5EC4C0, v20, byte_5EC4CC) )
            {
              if ( v20 )
                strcpy(byte_5EC4CC, v20);
              else
                byte_5EC4CC[0] = 0;
            }
            sub_5665B0(byte_5EC4CC);
            sub_5665B0(aSvm);
            sub_568620(255);
            if ( v24 && v27 )
            {
              if ( !sub_433B60(v40, v38, 0) )
                sub_568B00();
              if ( !v26 )
              {
                if ( v28[0] )
                  sub_587BCF(v28[0]);
                if ( v34 )
                  sub_587BCF(v34);
                if ( v32 )
                  sub_587BCF(v32);
                break;
              }
            }
            else
            {
              sub_568B00();
            }
            v27 = 0;
            if ( v28[0] )
              sub_587BCF(v28[0]);
            if ( v34 )
              sub_587BCF(v34);
            if ( v32 )
              sub_587BCF(v32);
          }
        }
      }
      v21 = lpPathName;
      if ( !lpPathName )
        v21 = &byte_5EA438;
      v21[v37] = 0;
      v22 = v36 == 1;
      v31 += 396;
      --v36;
    }
    while ( !v22 );
  }
  if ( lpPathName )
    sub_587BCF((LPVOID)lpPathName);
  return v25;
}
