bool __thiscall sub_4AF900(const char *this)
{
  const char *v1; // esi
  unsigned int v2; // kr08_4
  int v3; // eax
  char v4; // cl
  HANDLE FirstFileA; // ebp
  bool v6; // zf
  struct _WIN32_FIND_DATAA FindFileData; // [esp+14h] [ebp-D40h] BYREF
  CHAR FileName[1024]; // [esp+154h] [ebp-C00h] BYREF
  char Buffer[1024]; // [esp+554h] [ebp-800h] BYREF
  char v12[1024]; // [esp+954h] [ebp-400h] BYREF

  v1 = this;
  if ( !this )
    return 0;
  if ( !strlen(this) )
    return 0;
  strcpy(FileName, v1);
  v2 = strlen(FileName) + 1;
  if ( (int)(v2 - 1) >= 1024 )
    return 0;
  if ( FindFileData.cAlternateFileName[v2 + 14] != 92 )
    *(_WORD *)&FileName[strlen(FileName)] = *(_WORD *)word_5FB9F4;
  v3 = 0;
  do
  {
    v4 = FileName[v3];
    v12[v3++] = v4;
  }
  while ( v4 );
  *(_DWORD *)&FileName[strlen(FileName)] = *(_DWORD *)asc_5FCA68;
  FirstFileA = FindFirstFileA(FileName, &FindFileData);
  if ( FirstFileA == (HANDLE)-1 )
    return 0;
  while ( 1 )
  {
    sprintf(Buffer, "%s%s", v12, FindFileData.cFileName);
    if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
      break;
    _chmod(Buffer, 384);
    if ( remove(Buffer) )
      goto LABEL_17;
LABEL_14:
    if ( !FindNextFileA(FirstFileA, &FindFileData) )
    {
      FindClose(FirstFileA);
      return sub_5D2B89(v1) == 0;
    }
  }
  v6 = strcmp(FindFileData.cFileName, word_5FC804) == 0;
  if ( !strcmp(FindFileData.cFileName, asc_5FCA64) || v6 || (unsigned __int8)sub_4AF900(Buffer) )
  {
    v1 = this;
    goto LABEL_14;
  }
LABEL_17:
  FindClose(FirstFileA);
  return 0;
}
