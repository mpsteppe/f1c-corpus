char __thiscall sub_578A30(int *this, LPCSTR lpFileName, int a3, char *Str, char a5)
{
  int *v5; // esi
  const char *v6; // edi
  char *v7; // eax
  char *v8; // eax
  HANDLE FirstFileA; // ebp
  HANDLE v10; // ebp
  unsigned int v11; // kr04_4
  char v13; // [esp+Bh] [ebp-645h]
  struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-640h] BYREF
  char Path[253]; // [esp+150h] [ebp-500h] BYREF
  __int16 v17; // [esp+24Dh] [ebp-403h]
  char v18; // [esp+24Fh] [ebp-401h]
  CHAR FileName[253]; // [esp+250h] [ebp-400h] BYREF
  __int16 v20; // [esp+34Dh] [ebp-303h]
  char v21; // [esp+34Fh] [ebp-301h]
  char Buffer[765]; // [esp+350h] [ebp-300h] BYREF
  __int16 v23; // [esp+64Dh] [ebp-3h]
  char v24; // [esp+64Fh] [ebp-1h]

  v5 = this;
  Path[0] = byte_629120;
  memset(&Path[1], 0, 0xFCu);
  v17 = 0;
  v18 = 0;
  FileName[0] = byte_629120;
  memset(&FileName[1], 0, 0xFCu);
  v20 = 0;
  v21 = 0;
  v6 = Str;
  if ( !Str )
  {
    Str = word_5FC804;
    v6 = word_5FC804;
  }
  v13 = 0;
  if ( !strncmp(v6, asc_61B354, 2u) || strstr(v6, asc_5FE040) )
    v13 = 1;
  if ( !*(_DWORD *)(*v5 + 540) )
  {
    sub_578960((_DWORD **)v5);
    *(_BYTE *)(*v5 + 536) = a5;
    if ( *(_BYTE *)(*v5 + 536) )
    {
      if ( v6 )
      {
        sub_578600(*v5 + 528, v6);
        v7 = *(char **)(*v5 + 528);
        if ( !v7 )
          v7 = &byte_629120;
        _strupr(v7);
      }
    }
  }
  ++*(_DWORD *)(*v5 + 540);
  v8 = _getcwd(Path, 255);
  if ( v8 )
  {
    v8 = (char *)_chdir(v6);
    if ( v8 != (char *)-1 )
    {
      if ( (_BYTE)a3 )
      {
        sprintf(FileName, asc_5FCA68);
        FirstFileA = FindFirstFileA(FileName, &FindFileData);
        if ( FirstFileA != (HANDLE)-1 )
        {
          do
          {
            if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
            {
              if ( strcmp(FindFileData.cFileName, word_5FC804) && strcmp(FindFileData.cFileName, asc_5FCA64) )
                sub_578A30(lpFileName, a3, FindFileData.cFileName, 0);
              v5 = this;
            }
          }
          while ( FindNextFileA(FirstFileA, &FindFileData) );
          FindClose(FirstFileA);
        }
      }
      v10 = FindFirstFileA(lpFileName, &FindFileData);
      if ( v10 != (HANDLE)-1 )
      {
        do
        {
          if ( (FindFileData.dwFileAttributes & 0x10) == 0 )
          {
            Buffer[0] = byte_629120;
            memset(&Buffer[1], 0, 0x2FCu);
            v23 = 0;
            v24 = 0;
            if ( v13 )
            {
              sprintf(Buffer, "%s", Str);
            }
            else
            {
              if ( !strcmp(Str, word_5FC804) )
                sprintf(Buffer, "%s", Path);
              else
                sprintf(Buffer, "%s\\%s", Path, Str);
              v5 = this;
            }
            v11 = strlen(Buffer) + 1;
            if ( (int)(v11 - 1) > 0 && *(&v21 + v11 - 1) != 92 )
              *(_WORD *)&Buffer[strlen(Buffer)] = *(_WORD *)word_5FB9F4;
            sub_578750((_DWORD *)*v5, &FindFileData, Buffer);
          }
        }
        while ( FindNextFileA(v10, &FindFileData) );
        FindClose(v10);
      }
      _chdir(Path);
      v8 = (char *)--*(_DWORD *)(*v5 + 540);
      if ( !v8 )
        LOBYTE(v8) = sub_578A00(v5);
    }
  }
  return (char)v8;
}
