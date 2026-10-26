int printf(const char *const Format, ...)
{
  int v1; // edi
  int v2; // ebx
  va_list va; // [esp+14h] [ebp+8h] BYREF

  va_start(va, Format);
  _lock_file2(1, &File);
  v1 = _stbuf(&File);
  v2 = _output(&File, (int)Format, (int)va);
  _ftbuf(v1, &File);
  _unlock_file2(1, &File);
  return v2;
}
