int __cdecl sub_58B92A(int FileName, int a2, int a3)
{
  char v3; // bl
  DWORD FullPathNameA; // eax
  int v6; // eax
  int v7; // ecx
  CHAR Buffer[260]; // [esp+4h] [ebp-108h] BYREF
  LPSTR FilePart; // [esp+108h] [ebp-4h] BYREF

  v3 = FileName;
  if ( FileName )
  {
    if ( !sub_58B9FF(FileName) )
    {
      *(_DWORD *)TLSOffsetGetter_afd8() = 15;
      *(_DWORD *)TLSOffsetGetter() = 13;
      return 0;
    }
    LOBYTE(FileName) = v3 + 64;
    strcpy((char *)&FileName + 1, ":.");
    FullPathNameA = GetFullPathNameA((LPCSTR)&FileName, 0x104u, Buffer, &FilePart);
  }
  else
  {
    FullPathNameA = GetCurrentDirectoryA(0x104u, Buffer);
  }
  if ( !FullPathNameA )
    return 0;
  v6 = FullPathNameA + 1;
  if ( (unsigned int)v6 > 0x104 )
    return 0;
  v7 = a2;
  if ( a2 )
  {
    if ( v6 > a3 )
    {
      *(_DWORD *)TLSOffsetGetter() = 34;
      return 0;
    }
  }
  else
  {
    if ( v6 <= a3 )
      v6 = a3;
    v7 = MallocWrapperForNhMalloc(v6);
    if ( !v7 )
    {
      *(_DWORD *)TLSOffsetGetter() = 12;
      return 0;
    }
  }
  return sub_58FCA0(v7);
}
