char __thiscall sub_565F80(LPVOID ****this, LPCSTR lpFileName, int a3, const char *lpPathName, char a5)
{
  LPVOID ****v5; // esi
  const CHAR *v6; // edi
  const CHAR *v7; // eax
  int v8; // eax
  HANDLE FirstFileA; // ebp
  HANDLE v10; // ebp
  unsigned int v11; // kr04_4
  char v13; // [esp+Bh] [ebp-645h]
  struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-640h] BYREF
  CHAR PathName[253]; // [esp+150h] [ebp-500h] BYREF
  __int16 v17; // [esp+24Dh] [ebp-403h]
  char v18; // [esp+24Fh] [ebp-401h]
  CHAR FileName[253]; // [esp+250h] [ebp-400h] BYREF
  __int16 v20; // [esp+34Dh] [ebp-303h]
  char v21; // [esp+34Fh] [ebp-301h]
  char v22[765]; // [esp+350h] [ebp-300h] BYREF
  __int16 v23; // [esp+64Dh] [ebp-3h]
  char v24; // [esp+64Fh] [ebp-1h]

  v5 = this;
  PathName[0] = byte_5EA438[0];
  memset(&PathName[1], 0, 0xFCu);
  v17 = 0;
  v18 = 0;
  FileName[0] = byte_5EA438[0];
  memset(&FileName[1], 0, 0xFCu);
  v20 = 0;
  v21 = 0;
  v6 = lpPathName;
  if ( !lpPathName )
  {
    lpPathName = (const char *)&word_5BEB48;
    v6 = (const CHAR *)&word_5BEB48;
  }
  v13 = 0;
  if ( !sub_588640(v6, asc_5E5160, 2) || sub_587C20(v6, byte_5C3F6C) )
    v13 = 1;
  if ( !(*v5)[135] )
  {
    sub_565EB0(v5);
    *((_BYTE *)*v5 + 536) = a5;
    if ( *((_BYTE *)*v5 + 536) )
    {
      if ( v6 )
      {
        sub_566650(v6);
        v7 = (const CHAR *)(*v5)[132];
        if ( !v7 )
          v7 = byte_5EA438;
        sub_589901(v7);
      }
    }
  }
  (*v5)[135] = (LPVOID **)((char *)(*v5)[135] + 1);
  v8 = sub_58B903(PathName, 255);
  if ( v8 )
  {
    v8 = sub_59BA1D(v6);
    if ( v8 != -1 )
    {
      if ( (_BYTE)a3 )
      {
        sub_58815F(FileName, dword_5C2AB8);
        FirstFileA = FindFirstFileA(FileName, &FindFileData);
        if ( FirstFileA != (HANDLE)-1 )
        {
          do
          {
            if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
            {
              if ( strcmp(FindFileData.cFileName, (const char *)&word_5BEB48) && strcmp(FindFileData.cFileName, "..") )
                sub_565F80(lpFileName, a3, (int)FindFileData.cFileName, 0);
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
            v22[0] = byte_5EA438[0];
            memset(&v22[1], 0, 0x2FCu);
            v23 = 0;
            v24 = 0;
            if ( v13 )
            {
              sub_58815F(v22, "%s", lpPathName);
            }
            else
            {
              if ( !strcmp(lpPathName, (const char *)&word_5BEB48) )
                sub_58815F(v22, "%s", PathName);
              else
                sub_58815F(v22, "%s\\%s", PathName, lpPathName);
              v5 = this;
            }
            v11 = strlen(v22) + 1;
            if ( (int)(v11 - 1) > 0 && *(&v21 + v11 - 1) != 92 )
              *(_WORD *)&v22[strlen(v22)] = word_5C2AAC;
            sub_565CA0(*v5, &FindFileData, (int)v22);
          }
        }
        while ( FindNextFileA(v10, &FindFileData) );
        FindClose(v10);
      }
      sub_59BA1D(PathName);
      (*v5)[135] = (LPVOID **)((char *)(*v5)[135] - 1);
      v8 = (int)(*v5)[135];
      if ( !v8 )
        LOBYTE(v8) = sub_565F50((int *)v5);
    }
  }
  return v8;
}
