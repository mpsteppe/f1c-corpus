int __thiscall sub_4A33D0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // ecx
  int v12; // ecx
  int v13; // eax
  const char **v14; // eax
  const char *v15; // edi
  char *v16; // eax
  char *v17; // eax
  char v18; // al
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // edi
  int v23; // ebx
  int v24; // eax
  int v25; // ebp
  const char ***v26; // eax
  const char *v27; // edi
  char *v28; // eax
  char *v29; // eax
  int v30; // edx
  int i; // ecx
  int v32; // eax
  char *v33; // eax
  int v34; // eax
  int v36; // [esp-10h] [ebp-34h]
  int v37; // [esp-Ch] [ebp-30h]
  int v38; // [esp+8h] [ebp-1Ch] BYREF
  int v39; // [esp+Ch] [ebp-18h]
  int v40; // [esp+10h] [ebp-14h]
  int v41; // [esp+14h] [ebp-10h] BYREF
  int v42; // [esp+18h] [ebp-Ch] BYREF
  int v43; // [esp+1Ch] [ebp-8h] BYREF
  const char *v44; // [esp+20h] [ebp-4h]

  v6 = (_DWORD *)this[68];
  this[70] = v6;
  if ( !v6 || !*v6 )
    return 0;
  v7 = this[73];
  v8 = this[72] - 1;
  v40 = 0;
  if ( v7 > v8 )
    this[73] = v8;
  v9 = this[73];
  v10 = v9;
  if ( v9 < 0 || v9 >= this[71] )
    goto LABEL_22;
  v11 = (_DWORD *)this[68];
  if ( v9 > 0 )
  {
    while ( v11 )
    {
      v11 = (_DWORD *)v11[1];
      if ( --v10 <= 0 )
        goto LABEL_10;
    }
    goto LABEL_22;
  }
LABEL_10:
  if ( v11 && *v11 )
  {
    v12 = this[73];
    if ( v9 >= 0 && v9 < this[71] )
    {
      v13 = this[68];
      if ( v9 <= 0 )
      {
LABEL_17:
        if ( v13 )
        {
          v14 = *(const char ***)v13;
LABEL_20:
          v15 = *v14;
          if ( !*v14 )
            v15 = &byte_629120;
          goto LABEL_23;
        }
      }
      else
      {
        while ( v13 )
        {
          v13 = *(_DWORD *)(v13 + 4);
          if ( --v12 <= 0 )
            goto LABEL_17;
        }
      }
    }
    v14 = 0;
    goto LABEL_20;
  }
LABEL_22:
  v15 = v44;
LABEL_23:
  if ( sub_41F230(dword_62A170, v15, Destination) )
  {
    if ( v15 )
    {
      strncpy(Destination, v15, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      Destination[0] = 0;
    }
  }
  v16 = sub_49C9C0(this);
  sub_4AE370(v16, (int)Destination, (int)&v41, (int)&v38);
  if ( v15 )
  {
    v37 = this[77];
    v36 = this[76];
    v17 = sub_49C9C0(this);
    sub_4AE3F0(v17, (int)v15, v36, v37, 0);
  }
  sub_4AE870(&v43, &v42);
  v18 = sub_49D1E0(this);
  if ( v18 == 3 || v18 == 5 || v18 == 4 || v18 == 8 || v18 == 9 )
  {
    v19 = sub_4B15C0(this[61] + 108);
    v20 = this[74];
    v44 = (const char *)v19;
    if ( v20 < 0 || v20 >= this[71] )
    {
      this[70] = 0;
    }
    else
    {
      for ( this[70] = this[68]; v20 > 0; this[70] = *(_DWORD *)(v21 + 4) )
      {
        v21 = this[70];
        if ( !v21 )
          break;
        --v20;
      }
    }
    v22 = 12;
    this[75] = this[73];
    v39 = 12;
    if ( v19 > 12 )
    {
      do
      {
        v23 = sub_49D770(this, v22);
        v24 = sub_49D7F0(this, v22);
        v25 = v24;
        if ( v24 > v40 )
          v40 = v38 + v24;
        v26 = (const char ***)this[70];
        if ( v26 && *v26 )
        {
          v27 = **v26;
          if ( !v27 )
            v27 = &byte_629120;
          if ( sub_41F230(dword_62A170, v27, Destination) )
          {
            if ( v27 )
            {
              strncpy(Destination, v27, 0x1FFu);
              byte_62A37B = 0;
            }
            else
            {
              Destination[0] = 0;
            }
          }
          v28 = sub_49C9C0(this);
          sub_4AE370(v28, (int)Destination, (int)&v41, (int)&v38);
          if ( v42 <= v25 || v42 >= v38 + v25 || v43 <= v23 || v43 >= v23 + v41 )
          {
            v33 = sub_49C9C0(this);
            sub_4AE3F0(v33, (int)v27, v23, v25, 0);
          }
          else
          {
            v29 = sub_49C9E0(this);
            sub_4AE3F0(v29, (int)v27, v23, v25, 0);
            v30 = this[70];
            i = -1;
            if ( v30 )
            {
              v32 = this[68];
              for ( i = 0; v32; ++i )
              {
                if ( v32 == v30 )
                  break;
                v32 = *(_DWORD *)(v32 + 4);
              }
            }
            this[75] = i;
          }
          v34 = this[70];
          v22 = v39;
          if ( v34 )
            this[70] = *(_DWORD *)(v34 + 4);
        }
        v39 = ++v22;
      }
      while ( v22 < (int)v44 );
    }
  }
  return 0;
}
