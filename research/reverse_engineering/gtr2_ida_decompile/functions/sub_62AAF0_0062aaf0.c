int __userpurge sub_62AAF0@<eax>(char *a1@<eax>, char *FileName, int FileHandle)
{
  char *v3; // edi
  _DWORD *v4; // eax
  int v5; // esi
  char *v6; // eax
  char v7; // al
  char v8; // al
  int v9; // edi
  void *v10; // eax
  void *v12; // eax
  FILE *v13; // eax
  char *v14; // [esp+Ch] [ebp-58h]
  int v15; // [esp+10h] [ebp-54h]
  char Mode[80]; // [esp+14h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+64h] [ebp+0h] BYREF

  v14 = Mode;
  v15 = 0;
  v3 = a1;
  if ( !FileName || !a1 )
    return 0;
  v4 = malloc(0x61u);
  v5 = (int)v4;
  if ( !v4 )
    return 0;
  v4[8] = 0;
  v4[9] = 0;
  v4[10] = 0;
  v4[17] = 0;
  *v4 = 0;
  v4[18] = 0;
  v4[3] = 0;
  v4[4] = 0;
  v4[1] = 0;
  v4[16] = 0;
  v4[14] = 0;
  v4[15] = 0;
  v4[19] = sub_62CAA0(0);
  *(_DWORD *)(v5 + 80) = 0;
  *(_DWORD *)(v5 + 88) = 0;
  v6 = (char *)malloc(strlen(FileName) + 1);
  *(_DWORD *)(v5 + 84) = v6;
  if ( !v6 )
    goto LABEL_24;
  strcpy(v6, FileName);
  *(_BYTE *)(v5 + 92) = 0;
  do
  {
    if ( *v3 == 114 )
      *(_BYTE *)(v5 + 92) = 114;
    if ( *v3 == 119 || *v3 == 97 )
      *(_BYTE *)(v5 + 92) = 119;
    v7 = *v3;
    if ( *v3 < 48 || v7 > 57 )
    {
      if ( v7 == 102 )
      {
        v15 = 1;
      }
      else if ( v7 == 104 )
      {
        v15 = 2;
      }
      else
      {
        *v14++ = v7;
      }
    }
    ++v3;
  }
  while ( v7 && v14 != (char *)&retaddr );
  v8 = *(_BYTE *)(v5 + 92);
  if ( !v8 )
  {
LABEL_24:
    sub_62A7B0(v5);
    return 0;
  }
  if ( v8 == 119 )
  {
    v9 = sub_62C2F0(8, -15, 8, v15, "1.1.3", 56);
    v10 = malloc(0x4000u);
    *(_DWORD *)(v5 + 72) = v10;
    *(_DWORD *)(v5 + 12) = v10;
    if ( v9 || !v10 )
      goto LABEL_24;
  }
  else
  {
    v12 = malloc(0x4000u);
    *(_DWORD *)(v5 + 68) = v12;
    *(_DWORD *)v5 = v12;
    if ( sub_62C580("1.1.3", 56) || !*(_DWORD *)(v5 + 68) )
      goto LABEL_24;
  }
  *(_DWORD *)(v5 + 16) = 0x4000;
  *_errno() = 0;
  if ( FileHandle >= 0 )
    v13 = _fdopen(FileHandle, Mode);
  else
    v13 = fopen(FileName, Mode);
  *(_DWORD *)(v5 + 64) = v13;
  if ( !v13 )
    goto LABEL_24;
  if ( *(_BYTE *)(v5 + 92) == 119 )
  {
    fprintf(v13, "%c%c%c%c%c%c%c%c%c%c", dword_911678[0], dword_91167C, 8, 0, 0, 0, 0, 0, 0, 11);
    *(_DWORD *)(v5 + 93) = 10;
  }
  else
  {
    sub_62A3D0((int *)v5);
    *(_DWORD *)(v5 + 93) = sub_634320(*(_DWORD *)(v5 + 64)) - *(_DWORD *)(v5 + 4);
  }
  return v5;
}
