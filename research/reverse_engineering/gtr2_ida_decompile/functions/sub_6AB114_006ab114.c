unsigned int __thiscall sub_6AB114(void *this, int a2, int a3)
{
  int v4; // esi
  char *v5; // ebx
  char v6; // al
  int v7; // eax
  unsigned int v8; // edx
  int v9; // ecx
  int v10; // esi
  int v11; // eax
  unsigned int v12; // eax
  bool v13; // cf
  int v14; // edx
  int *v15; // ebx
  int v16; // ebx
  int v18; // [esp-4h] [ebp-44h]
  const char *v19; // [esp-4h] [ebp-44h]
  int v20; // [esp-4h] [ebp-44h]
  char String[32]; // [esp+Ch] [ebp-34h] BYREF
  int v22; // [esp+2Ch] [ebp-14h]
  char ArgList[4]; // [esp+30h] [ebp-10h]
  const char *v24; // [esp+34h] [ebp-Ch]
  int v25; // [esp+38h] [ebp-8h]
  int v26; // [esp+3Ch] [ebp-4h]
  int v27; // [esp+48h] [ebp+8h]
  unsigned int v28; // [esp+48h] [ebp+8h]

  v24 = *(const char **)(*(_DWORD *)(a2 + 104) + 24);
  v4 = 0;
  v25 = (int)this;
  v22 = 0;
  v26 = 0;
  sub_630FE0((int)String, (int)v24, 31);
  String[31] = 0;
  v5 = String;
  if ( !String[0] )
    goto LABEL_6;
  do
  {
    if ( !sub_633848() )
      break;
    ++v5;
  }
  while ( *v5 );
  if ( *v5 )
    v27 = j__atol(v5);
  else
LABEL_6:
    v27 = 0;
  if ( *v5 )
    *v5++ = 0;
  v6 = *v5;
  if ( !*v5 )
    goto LABEL_14;
  do
  {
    if ( !isdigit(v6) )
      break;
    v6 = *++v5;
  }
  while ( *v5 );
  if ( *v5 )
    v28 = -1;
  else
LABEL_14:
    v28 = (*(_DWORD *)(a2 + 112) >> 2) + v27;
  v7 = *(_DWORD *)(a2 + 108);
  if ( v7 == -1 )
  {
    v10 = *(_DWORD *)(*(_DWORD *)(v25 + 16) + 4 * *(_DWORD *)(a2 + 4));
    *(_DWORD *)ArgList = sub_681C52((_DWORD *)v25, a2);
    v11 = *(_DWORD *)(v10 + 4);
    if ( (v11 & 0x10) != 0 && (v11 & 0x200) == 0 )
    {
      if ( !_stricmp(String, "color") )
      {
        v26 = 1;
        if ( !a3 )
        {
          v12 = *(_DWORD *)(v25 + 40);
LABEL_26:
          v13 = v28 < v12;
          goto LABEL_36;
        }
        v18 = 2;
      }
      else
      {
        if ( _stricmp(String, "texcoord") )
        {
          if ( _stricmp(String, "position") && _stricmp(String, off_739E58) && _stricmp(String, "psize") )
          {
            if ( !_stricmp(String, "diffuse") )
            {
              v26 = 1;
              v4 = v28 != 0;
              v22 = 1;
              if ( !v28 )
                v28 = 0;
            }
            else if ( !_stricmp(String, "specular") )
            {
              v26 = 1;
              v4 = v28 != 0;
              v22 = 1;
              if ( !v28 )
                v28 = 1;
            }
            else
            {
              v26 = 0;
              v4 = 1;
            }
            goto LABEL_44;
          }
          v13 = v28 == 0;
          v26 = 4;
LABEL_36:
          v4 = 1 - v13;
LABEL_44:
          if ( !a3 || !*(_DWORD *)(a2 + 16) )
          {
            if ( v4 )
            {
              sub_686791(v25, *(_DWORD *)(a2 + 104), 4502, "invalid %s semantic '%s'", *(const char **)ArgList, v24);
            }
            else if ( v22 )
            {
              sub_686816(
                v25,
                *(_DWORD *)(a2 + 104),
                (const char *)0x1261,
                "%s semantic '%s' has been deprecated; use '%s%d' instead",
                *(const char **)ArgList,
                v24,
                off_91A3C8[v26],
                v28);
            }
          }
          if ( (v26 == 4 || v4) && !*(_DWORD *)(v25 + 1096) && !a3 )
          {
            v19 = v24;
            *(_DWORD *)(v25 + 1096) = 1;
            sub_686791(
              v25,
              *(_DWORD *)(a2 + 104),
              4502,
              "invalid reference to %s semantic '%s'",
              *(const char **)ArgList,
              v19);
            v4 = 1;
          }
          goto LABEL_68;
        }
        v26 = 3;
        if ( !a3 )
        {
          v12 = *(_DWORD *)(v25 + 60);
          goto LABEL_26;
        }
        v18 = 8;
      }
      v12 = v18;
      goto LABEL_26;
    }
    if ( (v11 & 0x20) == 0 )
    {
LABEL_86:
      v4 = 1;
      goto LABEL_87;
    }
    if ( !_stricmp(String, "color") )
    {
      v13 = v28 < *(_DWORD *)(v25 + 72);
      v26 = 1;
      v4 = 1 - v13;
    }
    else
    {
      if ( !_stricmp(String, "depth") )
      {
        v26 = 4;
        v4 = 1;
LABEL_62:
        if ( !a3 || !*(_DWORD *)(a2 + 16) )
          sub_686791(v25, *(_DWORD *)(a2 + 104), 4502, "invalid %s semantic '%s'", *(const char **)ArgList, v24);
LABEL_65:
        if ( v26 == 4 )
        {
          if ( a3 )
            goto LABEL_87;
          sub_686791(
            v25,
            *(_DWORD *)(a2 + 104),
            4502,
            "%s semantic '%s' not yet implemented in ps_1_x",
            *(_DWORD *)ArgList,
            v24);
        }
        goto LABEL_68;
      }
      v26 = 0;
      v4 = 1;
    }
    if ( !v4 )
      goto LABEL_65;
    goto LABEL_62;
  }
  v8 = *(unsigned __int8 *)(a2 + 109);
  v26 = (unsigned __int8)*(_DWORD *)(a2 + 108);
  v28 = v8;
  if ( (unsigned __int8)v7 == 4 )
  {
    v9 = v25;
    if ( *(_DWORD *)(v25 + 1096) || a3 )
      goto LABEL_87;
    v4 = 1;
    *(_DWORD *)(v25 + 1096) = 1;
    sub_686791(v9, *(_DWORD *)(a2 + 104), 4502, "invalid reference to input semantic '%s%d'", String, v8);
  }
LABEL_68:
  if ( v26 != 3 )
  {
LABEL_83:
    if ( v26 == 1 )
    {
      *(_WORD *)a2 |= 0x114u;
      *(double *)(a2 + 32) = 0.0;
      *(double *)(a2 + 40) = 1.0;
    }
    if ( v26 )
      goto LABEL_87;
    goto LABEL_86;
  }
  if ( !v28 || v28 >= 4 || *(_DWORD *)(a2 + 16) != 3 )
  {
    v14 = v25;
LABEL_79:
    if ( v28 < *(_DWORD *)(v14 + 60) || a3 || *(_DWORD *)(v14 + 1096) )
      goto LABEL_87;
    v20 = *(_DWORD *)(v14 + 60);
    v4 = 1;
    *(_DWORD *)(v14 + 1096) = 1;
    sub_686791(
      v14,
      *(_DWORD *)(a2 + 104),
      4502,
      "'texcoord' reference exceeds valid range for this shader model (max: %i)",
      v20);
    goto LABEL_83;
  }
  v14 = v25;
  if ( (unsigned __int16)*(_DWORD *)(v25 + 200) >= 0x104u )
    goto LABEL_79;
  v15 = (int *)(v25 + 1084);
  if ( *(_DWORD *)(v25 + 1084) == -1 )
    *v15 = sub_681A51((void *)v25, (int)"spec", 81, -1, 4);
  v16 = *v15;
  if ( v16 == -1 )
    return -2147024882;
  *(_DWORD *)(a2 + 12) = 0;
  v26 = 5;
  *(_DWORD *)(a2 + 4) = v16;
  *(_DWORD *)(a2 + 16) = v28 - 1;
LABEL_87:
  if ( v28 > 0xFFFF )
    v4 = 1;
  *(_DWORD *)(a2 + 108) = (v28 << 8) | (unsigned __int8)v26;
  return v4 != 0 ? 0x80004005 : 0;
}
