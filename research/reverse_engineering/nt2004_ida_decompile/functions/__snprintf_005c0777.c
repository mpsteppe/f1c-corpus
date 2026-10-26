int _snprintf(char *const Buffer, const size_t BufferCount, const char *const Format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  FILE File; // [esp+4h] [ebp-20h] BYREF
  va_list va; // [esp+38h] [ebp+14h] BYREF

  va_start(va, Format);
  File._base = Buffer;
  File._ptr = Buffer;
  File._flag = 66;
  File._cnt = BufferCount;
  v3 = _output(&File, (int)Format, (int)va);
  v4 = --File._cnt < 0;
  v5 = v3;
  if ( v4 )
    _flsbuf(0, &File);
  else
    *File._ptr = 0;
  return v5;
}
