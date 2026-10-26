BOOL __thiscall sub_6BC1E5(void *this, int a2, int a3, unsigned __int16 a4, _DWORD *a5)
{
  int v6; // eax
  const char *v7; // edi
  char *v8; // eax
  char *v9; // edi
  char v10; // al
  const char *v11; // eax
  int v12; // edi
  int v13; // ebx
  bool v14; // zf
  const char *v15; // ecx
  const char *v17; // [esp-4h] [ebp-5Ch]
  char String[64]; // [esp+Ch] [ebp-4Ch] BYREF
  char ArgList[4]; // [esp+4Ch] [ebp-Ch]
  int v20; // [esp+50h] [ebp-8h]
  int v21; // [esp+54h] [ebp-4h]
  int v22; // [esp+60h] [ebp+8h]
  unsigned int v23; // [esp+60h] [ebp+8h]

  v20 = 0;
  *a5 = 0;
  v6 = *(_DWORD *)(a2 + 104);
  *(_BYTE *)(a2 + 3) &= ~0x40u;
  v7 = *(const char **)(v6 + 24);
  v21 = (int)this;
  sub_630FE0((int)String, (int)v7, 63);
  String[63] = 0;
  v8 = String;
  if ( String[0] )
  {
    while ( *v8 != 95 )
    {
      if ( !*++v8 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    if ( *v8 != 95 )
      goto LABEL_7;
  }
  *v8 = 0;
  if ( _stricmp(v8 + 1, "centroid") )
  {
    *a5 = 1;
    *(_DWORD *)(a2 + 108) = 0;
    sub_686791(v21, *(_DWORD *)(a2 + 104), 4502, "invalid input semantic '%s', only _centroid allowed", v7);
    return *a5 != 0;
  }
  v20 = 1;
LABEL_7:
  v9 = String;
  if ( !String[0] )
    goto LABEL_13;
  do
  {
    if ( !sub_633848() )
      break;
    ++v9;
  }
  while ( *v9 );
  if ( *v9 )
    v22 = j__atol(v9);
  else
LABEL_13:
    v22 = 0;
  if ( *v9 )
    *v9++ = 0;
  v10 = *v9;
  if ( !*v9 )
    goto LABEL_21;
  do
  {
    if ( !isdigit(v10) )
      break;
    v10 = *++v9;
  }
  while ( *v9 );
  if ( *v9 )
    v23 = -1;
  else
LABEL_21:
    v23 = (*(_DWORD *)(a2 + 112) >> 2) + v22;
  v11 = sub_681C52((_DWORD *)v21, a2);
  v12 = a3;
  v13 = 0;
  v14 = *(_DWORD *)(a3 + 16) == -1;
  *(_DWORD *)ArgList = v11;
  if ( v14 )
    goto LABEL_42;
  do
  {
    if ( !_stricmp(*(const char **)v12, String) )
    {
      v13 = v12;
      if ( (a4 & *(_WORD *)(v12 + 4)) != 0 )
        break;
    }
    v12 += 36;
  }
  while ( *(_DWORD *)(v12 + 16) != -1 );
  if ( !v13 || *(_DWORD *)(v12 + 16) == -1 )
  {
LABEL_42:
    *(_BYTE *)(a2 + 3) |= 0x40u;
    *(_DWORD *)(a2 + 108) = 0;
  }
  else
  {
    if ( v20 && (*(_BYTE *)(v13 + 8) & 1) == 0 )
      *(_DWORD *)a2 |= 0x40000000u;
    v15 = *(const char **)(v13 + 12);
    if ( v15 )
      sub_686816(
        v21,
        *(_DWORD *)(a2 + 104),
        (const char *)0x1261,
        "%s semantics '%s' has been deprecated; use '%s%d' instead",
        *(const char **)ArgList,
        String,
        v15,
        v23);
    if ( v23 < *(_DWORD *)(v12 + 20) || v23 >= *(_DWORD *)(v12 + 24) )
      *(_DWORD *)a2 |= 0x40000000u;
    if ( *(_DWORD *)(a2 + 16) < *(_DWORD *)(v12 + 32) )
    {
      if ( (a4 & *(_WORD *)(v13 + 4)) == 0 )
        *(_DWORD *)a2 |= 0x40000000u;
      v14 = v20 == 0;
      *(_DWORD *)(a2 + 108) = (unsigned __int16)*(_DWORD *)(v13 + 16) | ((v23 + *(_DWORD *)(v13 + 28)) << 16);
      if ( !v14 )
        *(_BYTE *)(a2 + 3) |= 1u;
    }
    else
    {
      *(_DWORD *)a2 |= 0x40000000u;
      v17 = *(const char **)ArgList;
      *a5 = 1;
      sub_686791(v21, *(_DWORD *)(a2 + 104), 4555, "invalid type used for '%s' %s semantics", String, v17);
    }
  }
  return *a5 != 0;
}
