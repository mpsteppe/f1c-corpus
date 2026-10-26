int *__thiscall sub_615FE0(int **this, LPCSTR lpFileName, int a3, char *Str, char a5)
{
  int **v5; // esi
  const char *v6; // edi
  int *result; // eax
  int *v8; // eax
  char *v9; // eax
  HANDLE FirstFileA; // ebx
  int v11; // kr00_4
  char *v12; // edi
  char v14; // [esp+Fh] [ebp-649h]
  HANDLE hFindFile; // [esp+14h] [ebp-644h]
  _WIN32_FIND_DATAA FindFileData; // [esp+18h] [ebp-640h] BYREF
  char DstBuf[253]; // [esp+158h] [ebp-500h] BYREF
  __int16 v19; // [esp+255h] [ebp-403h]
  char v20; // [esp+257h] [ebp-401h]
  CHAR FileName[253]; // [esp+258h] [ebp-400h] BYREF
  __int16 v22; // [esp+355h] [ebp-303h]
  char v23; // [esp+357h] [ebp-301h] BYREF
  char Buffer[765]; // [esp+358h] [ebp-300h] BYREF
  __int16 v25; // [esp+655h] [ebp-3h]
  char v26; // [esp+657h] [ebp-1h]

  v5 = this;
  memset(DstBuf, 0, sizeof(DstBuf));
  v19 = 0;
  v20 = 0;
  memset(FileName, 0, sizeof(FileName));
  v22 = 0;
  v23 = 0;
  v6 = Str;
  if ( !Str )
  {
    Str = ".";
    v6 = ".";
  }
  v14 = 0;
  if ( !strncmp(v6, "\\\\", 2u) || strstr(v6, ":") )
    v14 = 1;
  result = (int *)_getcwd(DstBuf, 255);
  if ( result )
  {
    if ( !(*v5)[135] )
    {
      sub_615F60(*v5);
      (*v5)[135] = 0;
      *((_BYTE *)*v5 + 536) = a5;
      v8 = *v5;
      if ( *((_BYTE *)*v5 + 536) )
      {
        if ( v14 )
        {
          sub_615860((int)(v8 + 132), v6);
        }
        else
        {
          sub_615860((int)(v8 + 132), DstBuf);
          v5 = this;
          if ( strcmp(Str, ".") )
          {
            sub_615A50((int)(*this + 132), word_6F1F78);
            sub_615A50((int)(*this + 132), Str);
          }
          v6 = Str;
        }
        v9 = (char *)(*v5)[132];
        if ( !v9 )
          v9 = (char *)WindowName;
        _strupr(v9);
      }
    }
    ++(*v5)[135];
    if ( _chdir(v6) == -1 )
    {
      result = *v5;
      --(*v5)[135];
    }
    else
    {
      if ( (_BYTE)a3 )
      {
        sprintf(FileName, "*.*");
        hFindFile = FindFirstFileA(FileName, &FindFileData);
        if ( hFindFile != (HANDLE)-1 )
        {
          do
          {
            if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
            {
              if ( strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..") )
                sub_615FE0(lpFileName, a3, FindFileData.cFileName, 0);
              v5 = this;
            }
          }
          while ( FindNextFileA(hFindFile, &FindFileData) );
          FindClose(hFindFile);
        }
      }
      FirstFileA = FindFirstFileA(lpFileName, &FindFileData);
      if ( FirstFileA != (HANDLE)-1 )
      {
        do
        {
          if ( (FindFileData.dwFileAttributes & 0x10) == 0 )
          {
            memset(Buffer, 0, sizeof(Buffer));
            v25 = 0;
            v26 = 0;
            if ( v14 )
            {
              sprintf(Buffer, "%s", Str);
            }
            else
            {
              if ( !strcmp(Str, ".") )
                sprintf(Buffer, "%s", DstBuf);
              else
                sprintf(Buffer, "%s\\%s", DstBuf, Str);
              v5 = this;
            }
            v11 = strlen(Buffer);
            if ( v11 > 0 && Buffer[v11 - 1] != 92 )
            {
              v12 = &v23;
              while ( *++v12 )
                ;
              *(_WORD *)v12 = 92;
            }
            sub_615E60(*v5, &FindFileData, Buffer);
          }
        }
        while ( FindNextFileA(FirstFileA, &FindFileData) );
        FindClose(FirstFileA);
      }
      _chdir(DstBuf);
      --(*v5)[135];
      result = *v5;
      if ( !(*v5)[135] )
        result[2] = *result;
    }
  }
  return result;
}
