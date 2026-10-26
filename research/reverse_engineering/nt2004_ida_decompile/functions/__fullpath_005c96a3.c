char *__cdecl _fullpath(char *Buffer, const char *Path, size_t BufferCount)
{
  const char *v3; // ebx
  CHAR *v4; // edi
  size_t FullPathNameA; // eax
  DWORD LastError; // eax

  v3 = Path;
  if ( !Path || !*Path )
    return _getcwd(Buffer, BufferCount);
  v4 = Buffer;
  if ( !Buffer )
  {
    v4 = (CHAR *)malloc(0x104u);
    if ( !v4 )
    {
      *_errno() = 12;
      return 0;
    }
    BufferCount = 260;
  }
  FullPathNameA = GetFullPathNameA(v3, BufferCount, v4, (LPSTR *)&Path);
  if ( FullPathNameA >= BufferCount )
  {
    if ( !Buffer )
      sub_5C1B88(v4);
    *_errno() = 34;
    return 0;
  }
  if ( !FullPathNameA )
  {
    if ( !Buffer )
      sub_5C1B88(v4);
    LastError = GetLastError();
    _dosmaperr(LastError);
    return 0;
  }
  return v4;
}
