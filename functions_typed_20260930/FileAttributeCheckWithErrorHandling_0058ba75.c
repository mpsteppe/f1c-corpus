int __cdecl sub_58BA75(LPCSTR lpFileName, char a2)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  FileAttributesA = GetFileAttributesA(lpFileName);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    ErrorIDLookupTable(LastError);
    return -1;
  }
  if ( (FileAttributesA & 1) != 0 && (a2 & 2) != 0 )
  {
    *(_DWORD *)TLSOffsetGetter() = 13;
    *(_DWORD *)TLSOffsetGetter_afd8() = 5;
    return -1;
  }
  return 0;
}

