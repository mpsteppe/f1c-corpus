int __thiscall sub_4A2690(_DWORD *this, char *Source, int *a3, int *a4, int *a5)
{
  _DWORD *v6; // eax
  int v7; // ebx
  int v8; // ecx
  int v9; // ecx
  char *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // eax
  const char *v20; // eax
  int v21; // eax
  int v22; // edi
  char *v23; // eax
  const char *v24; // ebp
  int v25; // ebp
  int v26; // eax
  int v27; // eax
  int v29; // edi
  int v30; // edi
  int v31; // eax
  int v32; // eax
  char *v33; // eax
  int v34; // edi
  int v35; // edi
  const char *v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // [esp-Ch] [ebp-24h]
  int v42; // [esp-Ch] [ebp-24h]
  int v43; // [esp-Ch] [ebp-24h]
  int v44; // [esp-Ch] [ebp-24h]
  int v45; // [esp-Ch] [ebp-24h]
  int v46; // [esp-8h] [ebp-20h]
  int v47; // [esp-8h] [ebp-20h]
  int v48; // [esp-8h] [ebp-20h]
  int v49; // [esp-8h] [ebp-20h]
  int v50; // [esp-8h] [ebp-20h]
  int v51; // [esp-4h] [ebp-1Ch]
  int v52; // [esp-4h] [ebp-1Ch]
  int v53; // [esp-4h] [ebp-1Ch]
  int v54; // [esp-4h] [ebp-1Ch]
  int v55; // [esp-4h] [ebp-1Ch]
  int v56; // [esp+10h] [ebp-8h] BYREF
  int v57; // [esp+14h] [ebp-4h] BYREF
  CHAR *Sourcea; // [esp+1Ch] [ebp+4h]
  int v59; // [esp+20h] [ebp+8h]

  v6 = (_DWORD *)this[61];
  v7 = 0;
  if ( v6 )
  {
    v8 = this[207];
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 != 1 )
          goto LABEL_11;
        v10 = (char *)v6[20];
      }
      else
      {
        v10 = (char *)v6[18];
      }
    }
    else
    {
      v10 = (char *)v6[16];
    }
    if ( !v10 )
      v10 = &byte_629120;
    sub_4AE350(v10);
  }
LABEL_11:
  v11 = this[205];
  if ( !v11 )
  {
    v29 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
    v30 = v29 - (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    strncpy(byte_7655D8, (const char *)this[199], 0xFFu);
    byte_7656D7 = 0;
    sub_4AE4C0(v30, byte_7655D8);
    if ( strlen(byte_7655D8) )
    {
      v52 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
      v47 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
      v42 = (*(int (__thiscall **)(_DWORD *))(*this + 16))(this);
      v31 = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
      sub_4ADFB0(byte_7655D8, v31, v42, v47, v52);
      *(_DWORD *)Source = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
      *a3 = (*(int (__thiscall **)(_DWORD *))(*this + 16))(this);
      *a4 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
      *a5 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
    }
    v32 = this[61];
    if ( v32 )
    {
      v33 = *(char **)(v32 + 72);
      if ( !v33 )
        v33 = &byte_629120;
      sub_4AE350(v33);
    }
    v34 = sub_49D770(this, 3);
    v35 = v34 - sub_49D770(this, 2);
    v36 = (const char *)this[40];
    if ( !v36 )
      v36 = &byte_629120;
    strncpy(byte_7655D8, v36, 0xFFu);
    byte_7656D7 = 0;
    sub_4AE4C0(v35, byte_7655D8);
    if ( strlen(byte_7655D8) )
    {
      v37 = this[206];
      if ( v37 )
      {
        if ( v37 == 1 )
        {
          v54 = sub_49D770(this, 3);
          v49 = sub_49D770(this, 2);
          v44 = sub_49D7F0(this, 3);
          v39 = sub_49D7F0(this, 2);
          sub_4AE150(byte_7655D8, v39, v44, v49, v54);
        }
        else
        {
          v53 = sub_49D770(this, 3);
          v48 = sub_49D770(this, 2);
          v43 = sub_49D7F0(this, 3);
          v38 = sub_49D7F0(this, 2);
          sub_4ADFB0(byte_7655D8, v38, v43, v48, v53);
        }
        return 0;
      }
      v55 = sub_49D770(this, 3);
      v50 = sub_49D770(this, 2);
      v45 = sub_49D7F0(this, 3);
      v40 = sub_49D7F0(this, 2);
      sub_4AE080(byte_7655D8, v40, v45, v50, v55);
    }
    return 0;
  }
  if ( v11 <= 0 || v11 > 2 )
    return 0;
  strncpy(byte_7655D8, (const char *)this[199], 0xFFu);
  byte_7656D7 = 0;
  if ( sub_41F230(dword_62A170, byte_7655D8, Destination) )
  {
    strncpy(Destination, byte_7655D8, 0x1FFu);
    byte_62A37B = 0;
  }
  sub_4AE230(Destination, (int)&v57, (int)&v56);
  v12 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
  v51 = v57 + v12;
  v46 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
  v13 = (*(int (__thiscall **)(_DWORD *))(*this + 16))(this);
  v41 = v56 + v13;
  v14 = (*(int (__thiscall **)(_DWORD *))(*this + 16))(this);
  sub_4AE080(byte_7655D8, v14, v41, v46, v51);
  *(_DWORD *)Source = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
  v15 = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
  v16 = v15 + v56;
  if ( v16 <= (*(int (__thiscall **)(_DWORD *))(*this + 16))(this) )
  {
    v18 = (*(int (__thiscall **)(_DWORD *))(*this + 16))(this);
  }
  else
  {
    v17 = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
    v18 = v56 + v17;
  }
  *a3 = v18;
  *a4 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
  v19 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
  *a5 = v57 + v19;
  v20 = (const char *)this[40];
  if ( !v20 )
    v20 = &byte_629120;
  if ( !strlen(v20) )
    return 0;
  v21 = this[61];
  v22 = 0;
  if ( v21 )
  {
    v23 = *(char **)(v21 + 72);
    if ( !v23 )
      v23 = &byte_629120;
    sub_4AE350(v23);
  }
  v24 = (const char *)this[40];
  if ( v24 )
  {
    Sourcea = (CHAR *)this[40];
  }
  else
  {
    Sourcea = &byte_629120;
    v24 = &byte_629120;
  }
  if ( sub_41F230(dword_62A170, v24, Destination) )
  {
    if ( v24 )
    {
      strncpy(Destination, v24, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      Destination[0] = 0;
    }
  }
  sub_4AE230(Destination, (int)&v57, (int)&v56);
  v25 = sub_49D7F0(this, 2);
  v26 = this[206];
  v59 = v56 + v25;
  if ( v26 )
  {
    v27 = v26 - 1;
    if ( v27 )
    {
      if ( v27 == 1 )
      {
        v22 = sub_49D770(this, 2);
        v7 = sub_49D770(this, 3);
        sub_4ADFB0(Sourcea, v25, v59, v22, v7);
      }
    }
    else
    {
      v7 = sub_49D770(this, 3);
      v22 = v7 - v57;
      sub_4AE150(Sourcea, v25, v59, v7 - v57, v7);
    }
  }
  else
  {
    v22 = sub_49D770(this, 2);
    if ( sub_49D770(this, 3) >= 0 )
    {
      v7 = sub_49D770(this, 3);
      sub_4AE150(Sourcea, v25, v59, v22, v7);
    }
    else
    {
      v7 = v22 + v57;
      sub_4AE080(Sourcea, v25, v59, v22, v22 + v57);
    }
  }
  if ( *a4 < v22 )
    v22 = *a4;
  *a4 = v22;
  if ( *a5 > v7 )
    v7 = *a5;
  *a5 = v7;
  return 0;
}
