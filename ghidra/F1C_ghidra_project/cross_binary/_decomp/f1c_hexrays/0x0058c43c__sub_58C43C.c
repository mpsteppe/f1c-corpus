// f1c  0x0058c43c  size=368
_DWORD *__cdecl sub_58C43C(LPCSTR lpFileName, _BYTE *a2, int Buffer, _DWORD *a4)
{
  _BYTE *v4; // edi
  char v5; // al
  unsigned int v6; // ecx
  unsigned int v7; // esi
  int v8; // edx
  char v9; // al
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  _DWORD *result; // eax
  int v18; // [esp+Ch] [ebp-8h]
  int v19; // [esp+10h] [ebp-4h]

  v4 = a2;
  v18 = 0;
  v19 = 0;
  v5 = *a2;
  if ( *a2 == 97 )
  {
    v6 = 265;
LABEL_7:
    v7 = dword_8D41BC | 2;
    goto LABEL_8;
  }
  if ( v5 != 114 )
  {
    if ( v5 != 119 )
      return 0;
    v6 = 769;
    goto LABEL_7;
  }
  v6 = 0;
  v7 = dword_8D41BC | 1;
LABEL_8:
  v8 = 1;
  while ( 1 )
  {
    v9 = *++v4;
    if ( !v9 || !v8 )
      break;
    if ( v9 > 84 )
    {
      v13 = v9 - 98;
      if ( v13 )
      {
        v14 = v13 - 1;
        if ( v14 )
        {
          v15 = v14 - 11;
          if ( v15 )
          {
            if ( v15 != 6 || (v6 & 0xC000) != 0 )
LABEL_38:
              v8 = 0;
            else
              BYTE1(v6) |= 0x40u;
          }
          else
          {
            if ( v18 )
              goto LABEL_38;
            v18 = 1;
            v7 &= ~0x4000u;
          }
        }
        else
        {
          if ( v18 )
            goto LABEL_38;
          v18 = 1;
          v7 |= 0x4000u;
        }
      }
      else
      {
        if ( (v6 & 0xC000) != 0 )
          goto LABEL_38;
        BYTE1(v6) |= 0x80u;
      }
    }
    else if ( v9 == 84 )
    {
      if ( (v6 & 0x1000) != 0 )
        goto LABEL_38;
      v6 |= 0x1000u;
    }
    else
    {
      v10 = v9 - 43;
      if ( v10 )
      {
        v11 = v10 - 25;
        if ( v11 )
        {
          v12 = v11 - 14;
          if ( v12 )
          {
            if ( v12 != 1 || v19 )
              goto LABEL_38;
            v19 = 1;
            v6 |= 0x20u;
          }
          else
          {
            if ( v19 )
              goto LABEL_38;
            v19 = 1;
            v6 |= 0x10u;
          }
        }
        else
        {
          if ( (v6 & 0x40) != 0 )
            goto LABEL_38;
          v6 |= 0x40u;
        }
      }
      else
      {
        if ( (v6 & 2) != 0 )
          goto LABEL_38;
        v6 = v6 & 0xFFFFFFFC | 2;
        v7 = v7 & 0xFFFFFF7C | 0x80;
      }
    }
  }
  v16 = sub_595AF9(lpFileName, v6, Buffer, 420);
  if ( v16 < 0 )
    return 0;
  result = a4;
  ++dword_8D3EC8;
  a4[3] = v7;
  a4[1] = 0;
  *a4 = 0;
  a4[2] = 0;
  a4[7] = 0;
  a4[4] = v16;
  return result;
}
