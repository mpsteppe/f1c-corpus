int __cdecl sub_58AE69(int a1, _BYTE *a2)
{
  int v2; // esi
  _BYTE *v3; // ecx
  char v4; // al
  int v5; // edi
  int v6; // edx
  char v7; // al
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v14; // [esp+14h] [ebp+Ch]

  if ( a1 >= uNumber )
    return 0;
  if ( (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) == 0 )
    return 0;
  v2 = sub_58C5AC();
  if ( !v2 )
    return 0;
  v3 = a2;
  v4 = *a2;
  if ( *a2 == 97 )
    goto LABEL_9;
  if ( v4 != 114 )
  {
    if ( v4 != 119 )
    {
      v2 = 0;
      goto LABEL_29;
    }
LABEL_9:
    *(_DWORD *)(v2 + 12) = 2;
    goto LABEL_10;
  }
  *(_DWORD *)(v2 + 12) = 1;
LABEL_10:
  v5 = 0;
  v6 = 1;
  v14 = 0;
  *(_DWORD *)(v2 + 12) |= dword_8D41BC;
  while ( 1 )
  {
    v7 = *++v3;
    if ( !v7 || !v6 )
      break;
    v8 = v7 - 43;
    if ( v8 )
    {
      v9 = v8 - 55;
      if ( !v9 )
        goto LABEL_23;
      v10 = v9 - 1;
      if ( v10 )
      {
        v11 = v10 - 11;
        if ( v11 )
        {
          if ( v11 == 6 )
          {
LABEL_23:
            if ( v14 )
              goto LABEL_26;
            v14 = 1;
          }
          else
          {
LABEL_26:
            v6 = 0;
          }
        }
        else
        {
          if ( v5 )
            goto LABEL_26;
          *(_BYTE *)(v2 + 13) &= ~0x40u;
          v5 = 1;
        }
      }
      else
      {
        if ( v5 )
          goto LABEL_26;
        *(_BYTE *)(v2 + 13) |= 0x40u;
        v5 = 1;
      }
    }
    else
    {
      v12 = *(_DWORD *)(v2 + 12);
      if ( (v12 & 0x80u) != 0 )
        goto LABEL_26;
      LOBYTE(v12) = v12 & 0x7C | 0x80;
      *(_DWORD *)(v2 + 12) = v12;
    }
  }
  ++dword_8D3EC8;
  *(_DWORD *)(v2 + 16) = a1;
LABEL_29:
  AddressRangeCriticalSectionLeave(v2);
  return v2;
}

