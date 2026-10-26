int __cdecl vfprintf(FILE *const Stream, const char *const Format, va_list ArgList)
{
  int v3; // edi
  int v4; // ebx

  _lock_file(Stream);
  v3 = _stbuf(Stream);
  v4 = _output(Stream, (int)Format, (int)ArgList);
  _ftbuf(v3, Stream);
  _unlock_file(Stream);
  return v4;
}
