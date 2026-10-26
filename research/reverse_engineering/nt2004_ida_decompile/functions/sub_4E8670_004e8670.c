int __thiscall sub_4E8670(void *this, int a2, int a3, char *Str, int a5)
{
  char *v5; // ebx
  char *v6; // eax
  char *v7; // ecx
  char *v8; // eax
  int v9; // ebp
  const char *v10; // edi
  int v11; // edi
  char *v12; // eax
  char v13; // cl
  char *v14; // eax
  int v15; // edx
  char v16; // cl
  int v17; // esi
  int result; // eax
  int v19; // [esp+Ch] [ebp-204h]
  char v20[256]; // [esp+10h] [ebp-200h] BYREF
  char Buffer[256]; // [esp+110h] [ebp-100h] BYREF

  v5 = Str;
  HIWORD(v19) = HIWORD(this);
  v6 = strstr(Str, word_5FC804);
  if ( v6 )
    *v6 = 0;
  v7 = &Str[strlen(Str)];
  if ( v7 > Str )
  {
    while ( *v7 != 92 )
    {
      if ( --v7 <= Str )
        goto LABEL_8;
    }
    ++v7;
  }
LABEL_8:
  sprintf(Buffer, "%s", v7);
  v20[0] = 0;
  v8 = strtok(Buffer, word_5FBEBC);
  if ( v8 )
    strcat(v20, v8);
  if ( v20[strlen(v20) - 1] == 32 )
    v20[strlen(v20) - 1] = 0;
  v9 = 0;
  if ( dword_7D6B50 > 0 )
  {
    v10 = (const char *)(a5 + 260);
    do
    {
      if ( !strcmp(v20, v10) )
        break;
      ++v9;
      v10 += 400;
    }
    while ( v9 < dword_7D6B50 );
    v5 = Str;
  }
  if ( v9 == dword_7D6B50 )
  {
    v11 = 400 * v9 + a5;
    *(_BYTE *)(v11 + 260) = 0;
    strcpy((char *)(v11 + 260), v20);
    v12 = strstr((const char *)(v11 + 260), asc_6100B8);
    if ( v12 )
    {
      *v12 = 0;
      v13 = v12[1];
      v14 = v12 + 1;
      if ( v13 == 32 )
        ++v14;
      v15 = v11 + 324 - (_DWORD)v14;
      do
      {
        v16 = *v14;
        v14[v15] = *v14;
        ++v14;
      }
      while ( v16 );
    }
    ++dword_7D6B50;
  }
  v17 = a5 + 400 * v9;
  strcpy((char *)(v17 + 4), v5);
  sub_4E9480(v5);
  *(_BYTE *)(v17 + 392) = sub_4E8FC0((char *)(v17 + 260));
  result = sub_4E9550(v5, 115, 211);
  *(_DWORD *)(v17 + 396) = result;
  return result;
}
