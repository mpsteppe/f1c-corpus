char *__cdecl _getdcwd_lk(int FileName, char *a2, int a3)
{
  char v3; // bl
  DWORD FullPathNameA; // eax
  signed int v6; // eax
  char *v7; // ecx
  LPSTR FilePart; // [esp+4h] [ebp-10Ch] BYREF
  CHAR Buffer[260]; // [esp+8h] [ebp-108h] BYREF
  int v10; // [esp+10Ch] [ebp-4h]

  v3 = FileName;
  v10 = dword_912B08;
  if ( FileName )
  {
    if ( !_validdrive(FileName) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
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
      *_errno() = 34;
      return 0;
    }
  }
  else
  {
    if ( v6 <= a3 )
      v6 = a3;
    v7 = (char *)malloc(v6);
    if ( !v7 )
    {
      *_errno() = 12;
      return 0;
    }
  }
  return strcpy(v7, Buffer);
}
