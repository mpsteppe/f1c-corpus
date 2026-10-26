int fprintf(FILE *const Stream, const char *const Format, ...)
{
  int v2; // edi
  int v3; // ebx
  va_list va; // [esp+18h] [ebp+Ch] BYREF

  va_start(va, Format);
  _lock_file(Stream);
  v2 = _stbuf(Stream);
  v3 = _output(Stream, (int)Format, (int)va);
  _ftbuf(v2, Stream);
  _unlock_file(Stream);
  return v3;
}
