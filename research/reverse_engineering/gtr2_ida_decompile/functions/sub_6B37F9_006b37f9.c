unsigned int __thiscall sub_6B37F9(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // edi
  unsigned int v5; // ecx
  _DWORD *v6; // eax
  char *v8; // esi
  char v9; // al
  unsigned int v10; // edi
  int v11; // eax
  BOOL v12; // esi
  unsigned __int8 v13; // al
  char String[32]; // [esp+4h] [ebp-28h] BYREF
  int v15; // [esp+24h] [ebp-8h]
  int v16; // [esp+28h] [ebp-4h]

  v4 = 0;
  v5 = this[50] & 0xFFFF0000;
  v15 = (int)this;
  v16 = 0;
  if ( v5 == 1180172288 )
  {
    if ( a2[27] == -1 )
    {
      v6 = this + 126;
      a2[27] = (*v6)++;
    }
    return 0;
  }
  if ( a2[27] != -1 )
    return 0;
  sub_630FE0((int)String, *(_DWORD *)(a2[26] + 24), 32);
  String[31] = 0;
  v8 = String;
  if ( String[0] )
  {
    do
    {
      if ( !sub_633848() )
        break;
      ++v8;
    }
    while ( *v8 );
    if ( !*v8 )
      goto LABEL_14;
    v4 = j__atol(v8);
  }
  if ( *v8 )
    *v8++ = 0;
LABEL_14:
  v9 = *v8;
  if ( !*v8 )
    goto LABEL_19;
  do
  {
    if ( !isdigit(v9) )
      break;
    v9 = *++v8;
  }
  while ( *v8 );
  if ( *v8 )
    v10 = -1;
  else
LABEL_19:
    v10 = (a2[28] >> 2) + v4;
  v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v15 + 16) + 4 * a2[1]) + 4);
  if ( (v11 & 0x10) != 0 && (v11 & 0x200) == 0 )
  {
    if ( !_stricmp(String, "position") )
    {
      v16 = 2;
    }
    else
    {
      if ( _stricmp(String, "psize") )
      {
        v16 = 0;
        v12 = 1;
        goto LABEL_28;
      }
      v16 = 3;
    }
    v12 = v10 != 0;
LABEL_28:
    if ( v12 && !a2[4] )
      sub_686791(v15, a2[26], 4502, "invalid reference to input semantic '%s%d'", String, v10);
    goto LABEL_38;
  }
  if ( (v11 & 0x20) == 0 )
  {
LABEL_39:
    v13 = v16;
    v12 = 1;
    goto LABEL_40;
  }
  if ( !_stricmp(String, "color") )
  {
    v16 = 1;
    v12 = v10 != 0;
  }
  else
  {
    v16 = 0;
    v12 = 1;
  }
  if ( v12 && !a2[4] )
    sub_686791(v15, a2[26], 4502, "invalid reference to output semantic '%s%d'", String, v10);
LABEL_38:
  v13 = v16;
  if ( !v16 )
    goto LABEL_39;
LABEL_40:
  if ( v10 > 0xFFFF )
    v12 = 1;
  a2[27] = v13 | ((v10 | 0xFFFFFF00) << 8);
  return v12 ? 0x80004005 : 0;
}
