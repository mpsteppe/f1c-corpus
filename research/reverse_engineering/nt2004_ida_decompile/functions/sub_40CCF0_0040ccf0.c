char __thiscall sub_40CCF0(_DWORD *this, int a2)
{
  int v3; // edx
  const char *v4; // eax
  const char *v5; // ebx
  const char *v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  unsigned __int8 v10; // bl
  _DWORD *v11; // esi
  CHAR **v12; // edi
  _DWORD *v13; // eax
  CHAR *v14; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // esi
  int v18; // eax
  const char **v19; // ebx
  const char *v20; // edx
  const char *v21; // ecx
  char *v22; // eax
  CHAR *v23; // eax
  int v24; // eax
  _DWORD *v25; // eax
  int v26; // ecx
  int v27; // ebx
  int v28; // edx
  int v29; // edx
  int v30; // eax
  char *v31; // edi
  void *v32; // ecx
  char *v33; // eax
  unsigned __int8 v35; // [esp+13h] [ebp-221h]
  int v36; // [esp+14h] [ebp-220h]
  int v37; // [esp+14h] [ebp-220h]
  unsigned __int16 v38; // [esp+18h] [ebp-21Ch]
  int v39; // [esp+1Ch] [ebp-218h]
  int v40; // [esp+20h] [ebp-214h]
  char v41[16]; // [esp+24h] [ebp-210h] BYREF
  char Destination[509]; // [esp+34h] [ebp-200h] BYREF
  __int16 v43; // [esp+231h] [ebp-3h]
  char v44; // [esp+233h] [ebp-1h]

  v3 = *this;
  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x1FCu);
  v43 = 0;
  v44 = 0;
  (*(void (__thiscall **)(_DWORD *))(v3 + 24))(this);
  v4 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v4 = &byte_629120;
  sub_405480(Destination, 0x1FFu, "%s%s", v4, aCareerGdb);
  sub_57AC50(Destination, 0);
  v5 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v5 = &byte_629120;
  v6 = (const char *)sub_40E4C0(a2);
  sub_405480(Destination, 0x1FFu, "%s%s", v5, v6);
  sub_57AC50(Destination, 0);
  this[9] = a2;
  v38 = 42;
  v7 = sub_57AE50(aNumberofoppone);
  if ( v7 )
  {
    v8 = (const char *)sub_57A6D0(v7);
    v38 = atoi(v8);
  }
  LOBYTE(v39) = 0;
  v9 = sub_57AE50(aSeasonraces);
  if ( v9 )
    LOBYTE(v39) = sub_57A6E0(v9);
  sub_504470(v41);
  v35 = sub_4E2570(v38, (int)&byte_629120, (char)aAndNascarClose);
  if ( v35 )
  {
    v10 = 0;
    v11 = 0;
    v36 = 0;
    do
    {
      v12 = (CHAR **)sub_4E28F0(v36);
      if ( v12 )
      {
        v13 = operator new(0x24u);
        if ( v13 )
        {
          *v13 = 0;
          v13[1] = -1;
          *((_BYTE *)v13 + 8) = 1;
          v13[3] = 0;
          v13[4] = 0;
          v13[5] = 0;
          v13[6] = 0;
          v13[7] = 0;
          *((_BYTE *)v13 + 32) = 0;
          v11 = v13;
        }
        v14 = *v12;
        if ( !*v12 )
          v14 = &byte_629120;
        sub_578600(v14);
        sub_40EFC0(*((unsigned __int16 *)this + 50), v39);
        *((_BYTE *)v11 + 8) = v10 + 1;
        v15 = operator new(0xCu);
        if ( v15 )
        {
          *v15 = v11;
          v15[1] = 0;
          *((_BYTE *)v15 + 8) = 1;
        }
        else
        {
          v15 = 0;
        }
        if ( this[1] )
        {
          *(_DWORD *)(this[2] + 4) = v15;
        }
        else
        {
          this[1] = v15;
          this[3] = v15;
        }
        this[2] = v15;
        ++this[4];
        v11 = 0;
      }
      ++v10;
      ++v36;
    }
    while ( v10 < v35 );
  }
  v16 = operator new(0x24u);
  if ( v16 )
  {
    *v16 = 0;
    v16[1] = -1;
    *((_BYTE *)v16 + 8) = 1;
    v16[3] = 0;
    v16[4] = 0;
    v16[5] = 0;
    v16[6] = 0;
    v16[7] = 0;
    *((_BYTE *)v16 + 32) = 0;
    v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  v40 = sub_4ED6E0(&dword_7D6B74);
  v37 = 0;
  if ( dword_7D6A58 <= 0 )
  {
LABEL_44:
    v23 = dword_7665D8;
    if ( !dword_7665D8 )
      v23 = &byte_629120;
  }
  else
  {
    v18 = 0;
    while ( 1 )
    {
      v19 = (const char **)(dword_7D6A5C + 1232 * v18);
      v20 = *v19;
      if ( !*v19 )
        v20 = &byte_629120;
      v21 = &v20[strlen(v20)];
      if ( v21 > v20 )
      {
        while ( *v21 != 92 )
        {
          if ( --v21 <= v20 )
            goto LABEL_36;
        }
        ++v21;
      }
LABEL_36:
      strncpy(Destination, v21, 0x1FFu);
      v44 = 0;
      v22 = &Destination[strlen(Destination)];
      if ( v22 > Destination )
      {
        while ( *v22 != 46 )
        {
          if ( --v22 <= Destination )
            goto LABEL_41;
        }
        *v22 = 0;
      }
LABEL_41:
      if ( !_strcmpi(Destination, aCareer_0) && sub_579060((char *)v19 + 630, v40) )
        break;
      v18 = (unsigned __int16)++v37;
      if ( (unsigned __int16)v37 >= dword_7D6A58 )
        goto LABEL_44;
    }
    v23 = (CHAR *)*v19;
    if ( !*v19 )
      v23 = &byte_629120;
  }
  sub_578600(v23);
  *((_BYTE *)v17 + 32) = 1;
  v24 = sub_413700(0);
  v17[7] = v24;
  (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 52))(v24);
  sub_40EFC0(*((unsigned __int16 *)this + 50), v39);
  *((_BYTE *)v17 + 8) = v38 + 1;
  v25 = operator new(0xCu);
  if ( v25 )
  {
    *v25 = v17;
    v25[1] = 0;
    *((_BYTE *)v25 + 8) = 1;
  }
  else
  {
    v25 = 0;
  }
  v26 = this[1];
  if ( v26 )
  {
    v25[1] = v26;
  }
  else
  {
    this[2] = v25;
    this[3] = v25;
  }
  v27 = this[4];
  this[1] = v25;
  this[4] = v27 + 1;
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v17[7] + 120))(v17[7]);
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v17[7] + 208))(v17[7]);
  v28 = *this;
  *((_BYTE *)this + 102) = 1;
  (*(void (__thiscall **)(_DWORD *))(v28 + 20))(this);
  sub_4CD5B0(Destination, 511);
  v29 = dword_5FC048;
  v30 = dword_5FC04C;
  v31 = &Destination[strlen(Destination)];
  *(_DWORD *)v31 = dword_5FC044;
  v32 = off_5FC050;
  *((_DWORD *)v31 + 1) = v29;
  *((_DWORD *)v31 + 2) = v30;
  *((_DWORD *)v31 + 3) = v32;
  v33 = (char *)sub_4ED6F0(&dword_7D6B74);
  sub_4ED7B0(v33);
  sub_4ED5C0(Destination);
  sub_4E2420(v41);
  return 1;
}
