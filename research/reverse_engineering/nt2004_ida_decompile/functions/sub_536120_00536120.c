_DWORD *__fastcall sub_536120(const char *a1, char *a2, int FileHandle)
{
  char *v4; // ebp
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  char *v7; // eax
  char v8; // al
  char v9; // al
  int v10; // edi
  void *v11; // eax
  void *v13; // eax
  FILE *v14; // eax
  char *v15; // [esp+10h] [ebp-60h]
  int v16; // [esp+14h] [ebp-5Ch]
  char Mode[80]; // [esp+20h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h] BYREF

  v16 = 0;
  v4 = a2;
  v15 = Mode;
  if ( !a1 )
    return 0;
  if ( !a2 )
    return 0;
  v5 = malloc(0x61u);
  v6 = v5;
  if ( !v5 )
    return 0;
  v5[8] = 0;
  v5[9] = 0;
  v5[10] = 0;
  v5[17] = 0;
  *v5 = 0;
  v5[18] = 0;
  v5[3] = 0;
  v5[4] = 0;
  v5[1] = 0;
  v5[16] = 0;
  v5[14] = 0;
  v5[15] = 0;
  v5[19] = sub_5384D0(0);
  v6[20] = 0;
  v6[22] = 0;
  v7 = (char *)malloc(strlen(a1) + 1);
  v6[21] = v7;
  if ( !v7 )
    goto LABEL_24;
  strcpy(v7, a1);
  *((_BYTE *)v6 + 92) = 0;
  do
  {
    if ( *v4 == 114 )
      *((_BYTE *)v6 + 92) = 114;
    if ( *v4 == 119 || *v4 == 97 )
      *((_BYTE *)v6 + 92) = 119;
    v8 = *v4;
    if ( *v4 < 48 || v8 > 57 )
    {
      if ( v8 == 102 )
      {
        v16 = 1;
      }
      else if ( v8 == 104 )
      {
        v16 = 2;
      }
      else
      {
        *v15++ = v8;
      }
    }
    ++v4;
  }
  while ( v8 && v15 != (char *)&retaddr );
  v9 = *((_BYTE *)v6 + 92);
  if ( !v9 )
  {
LABEL_24:
    sub_5364F0(v6);
    return 0;
  }
  if ( v9 == 119 )
  {
    v10 = sub_537250(8, -15, 8, v16, a113, 56);
    v11 = malloc(0x4000u);
    v6[18] = v11;
    v6[3] = v11;
    if ( v10 || !v11 )
      goto LABEL_24;
  }
  else
  {
    v13 = malloc(0x4000u);
    v6[17] = v13;
    *v6 = v13;
    if ( sub_536CE0(a113, 56) || !v6[17] )
      goto LABEL_24;
  }
  v6[4] = 0x4000;
  *_errno() = 0;
  if ( FileHandle >= 0 )
    v14 = _fdopen(FileHandle, Mode);
  else
    v14 = fopen(a1, Mode);
  v6[16] = v14;
  if ( !v14 )
    goto LABEL_24;
  if ( *((_BYTE *)v6 + 92) == 119 )
  {
    fprintf(v14, "%c%c%c%c%c%c%c%c%c%c", dword_615980, dword_615984, 8, 0, 0, 0, 0, 0, 0, 11);
    *(_DWORD *)((char *)v6 + 93) = 10;
  }
  else
  {
    sub_536360(v6);
    *(_DWORD *)((char *)v6 + 93) = ftell((FILE *)v6[16]) - v6[1];
  }
  return v6;
}
