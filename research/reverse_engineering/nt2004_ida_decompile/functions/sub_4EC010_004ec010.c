const char **__thiscall sub_4EC010(_DWORD *this)
{
  const char *v2; // edx
  const char *v3; // ecx
  const char *v4; // eax
  int v5; // eax
  const char ***v6; // ecx
  const char **i; // eax
  const char *v8; // eax
  int v9; // edi
  int *v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  const char ***v14; // eax
  const char **result; // eax
  const char *v16; // eax
  int v17; // edi
  int *v18; // eax
  int v19; // [esp+Ch] [ebp-204h] BYREF
  char v20[253]; // [esp+10h] [ebp-200h] BYREF
  __int16 v21; // [esp+10Dh] [ebp-103h]
  char v22; // [esp+10Fh] [ebp-101h]
  char Buffer[253]; // [esp+110h] [ebp-100h] BYREF
  __int16 v24; // [esp+20Dh] [ebp-3h]
  char v25; // [esp+20Fh] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v24 = 0;
  v25 = 0;
  v20[0] = byte_629120;
  memset(&v20[1], 0, 0xFCu);
  v21 = 0;
  v22 = 0;
  sub_4EC230(this);
  v2 = (const char *)dword_62A118;
  if ( !dword_62A118 )
    v2 = &byte_629120;
  v3 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v3 = &byte_629120;
  v4 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v4 = &byte_629120;
  sub_405480(Buffer, 0xFFu, "%s%s%s", v4, v3, v2);
  v5 = this[24];
  if ( v5 )
  {
    v6 = *(const char ****)(v5 + 36);
    *(_DWORD *)(v5 + 44) = v6;
    if ( v6 )
    {
      for ( i = *v6; i; i = *v14 )
      {
        v19 = 0;
        v8 = *i;
        if ( !v8 )
          v8 = &byte_629120;
        sub_405480(v20, 0xFFu, "%s%s", Buffer, v8);
        if ( !sub_5924D0(dword_7DA988, (int)&v19, (int)v20) )
        {
          v9 = v19;
          if ( v19 )
          {
            v10 = (int *)operator new(0xCu);
            if ( v10 )
            {
              *v10 = v9;
              v10[1] = 0;
              *((_BYTE *)v10 + 8) = 0;
            }
            else
            {
              v10 = 0;
            }
            if ( this[20] )
            {
              *(_DWORD *)(this[21] + 4) = v10;
            }
            else
            {
              this[20] = v10;
              this[22] = v10;
            }
            this[21] = v10;
            ++this[23];
          }
        }
        v11 = this[24];
        v12 = *(_DWORD *)(v11 + 44);
        v13 = v11 + 36;
        if ( v12 )
          *(_DWORD *)(v13 + 8) = *(_DWORD *)(v12 + 4);
        v14 = *(const char ****)(v13 + 8);
        if ( !v14 )
          break;
      }
    }
  }
  result = (const char **)this[16];
  this[18] = result;
  if ( result )
  {
    for ( result = (const char **)*result; result; result = (const char **)*result )
    {
      v19 = 0;
      v16 = *result;
      if ( !v16 )
        v16 = &byte_629120;
      sub_405480(v20, 0xFFu, "%s%s", Buffer, v16);
      if ( !sub_5924D0(dword_7DA988, (int)&v19, (int)v20) )
      {
        v17 = v19;
        if ( v19 )
        {
          v18 = (int *)operator new(0xCu);
          if ( v18 )
          {
            *v18 = v17;
            v18[1] = 0;
            *((_BYTE *)v18 + 8) = 0;
          }
          else
          {
            v18 = 0;
          }
          if ( this[20] )
          {
            *(_DWORD *)(this[21] + 4) = v18;
          }
          else
          {
            this[20] = v18;
            this[22] = v18;
          }
          this[21] = v18;
          ++this[23];
        }
      }
      result = (const char **)this[18];
      if ( !result )
        break;
      result = (const char **)result[1];
      this[18] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
