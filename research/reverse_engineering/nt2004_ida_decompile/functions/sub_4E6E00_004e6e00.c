int __thiscall sub_4E6E00(const char **this, _DWORD *a2)
{
  int v3; // eax
  char v4; // cl
  const char *v5; // ecx
  int v6; // ecx
  char *i; // eax
  const char *v8; // eax
  char *v9; // eax
  const char *v10; // eax
  int v11; // ecx
  char *j; // eax
  int v13; // edx
  signed int v14; // ecx
  char *v15; // eax
  int v16; // edx
  char v17; // cl
  _DWORD *v18; // esi
  int v19; // eax
  const char *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  char v24[4]; // [esp+Ch] [ebp-524h] BYREF
  CHAR FileName[32]; // [esp+10h] [ebp-520h] BYREF
  char Destination[127]; // [esp+30h] [ebp-500h] BYREF
  char v27; // [esp+AFh] [ebp-481h]
  char String2[128]; // [esp+B0h] [ebp-480h] BYREF
  char v29[511]; // [esp+130h] [ebp-400h] BYREF
  char v30; // [esp+32Fh] [ebp-201h] BYREF
  char Str[512]; // [esp+330h] [ebp-200h] BYREF

  sub_578870(v24);
  v3 = 0;
  do
  {
    v4 = byte_610E24[v3];
    FileName[v3++] = v4;
  }
  while ( v4 );
  v5 = *this;
  if ( !*this )
    v5 = &byte_629120;
  strcpy(Str, v5);
  v6 = strlen(Str);
  if ( v6 > 0 )
  {
    for ( i = &Str[v6 - 1]; i >= Str; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  sub_578960(v24);
  sub_578A30(FileName, 1, Str, 0);
  sub_578E30(0);
  sub_578A00(v24);
  while ( sub_578D80(v24) )
  {
    v8 = (const char *)sub_5789A0(v24);
    strncpy(Destination, v8, 0x7Fu);
    v27 = 0;
    v9 = &Destination[strlen(Destination)];
    if ( v9 > Destination )
    {
      while ( *v9 != 46 )
      {
        if ( --v9 <= Destination )
          goto LABEL_15;
      }
      *v9 = 0;
    }
LABEL_15:
    v10 = (const char *)sub_578D80(v24);
    strncpy(v29, v10, 0x1FFu);
    v30 = 0;
    v11 = strlen(v29);
    if ( v11 > 0 )
    {
      for ( j = &String2[v11 + 127]; j >= v29; *j-- = 0 )
      {
        if ( *j == 92 )
          break;
      }
    }
    if ( !strlen(v29) )
      goto LABEL_54;
    v13 = 0;
    v14 = strlen(v29) - 1;
    if ( v14 < 0 )
      goto LABEL_54;
    while ( 1 )
    {
      if ( v29[v14] == 92 )
        ++v13;
      if ( v13 == 2 || !v14 )
        break;
      if ( --v14 < 0 )
        goto LABEL_54;
    }
    v15 = &v29[v14 + 1];
    v16 = String2 - &v29[v14 + 1];
    do
    {
      v17 = *v15;
      v15[v16] = *v15;
      ++v15;
    }
    while ( v17 );
    if ( Destination[strlen(String2) + 127] == 92 )
      String2[strlen(String2) - 1] = 0;
    if ( _strcmpi(Destination, String2) )
      goto LABEL_54;
    v18 = operator new(8u);
    if ( v18 )
    {
      v19 = sub_578D80(v24);
      *v18 = 0;
      v18[1] = -1;
      sub_578600(v19);
    }
    else
    {
      v18 = 0;
    }
    v20 = (const char *)sub_579060(v29, Str);
    if ( !v20 || _strcmpi(v20, Str) )
    {
      if ( v18 )
      {
        v22 = operator new(0xCu);
        if ( v22 )
        {
          *v22 = v18;
          v22[1] = 0;
          *((_BYTE *)v22 + 8) = 1;
        }
        else
        {
          v22 = 0;
        }
        if ( *a2 )
        {
          *(_DWORD *)(a2[1] + 4) = v22;
        }
        else
        {
          *a2 = v22;
          a2[2] = v22;
        }
        a2[1] = v22;
        goto LABEL_53;
      }
    }
    else if ( v18 )
    {
      v21 = operator new(0xCu);
      if ( v21 )
      {
        *v21 = v18;
        v21[1] = 0;
        *((_BYTE *)v21 + 8) = 1;
      }
      else
      {
        v21 = 0;
      }
      if ( *a2 )
      {
        v21[1] = *a2;
      }
      else
      {
        a2[1] = v21;
        a2[2] = v21;
      }
      *a2 = v21;
LABEL_53:
      ++a2[3];
    }
LABEL_54:
    sub_5789D0(v24);
  }
  return sub_5788D0(v24);
}
