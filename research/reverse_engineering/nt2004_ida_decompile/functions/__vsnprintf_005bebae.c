int __cdecl _vsnprintf(char *const Buffer, const size_t BufferCount, const char *const Format, va_list ArgList)
{
  int v4; // eax
  bool v5; // sf
  int v6; // esi
  FILE File; // [esp+4h] [ebp-20h] BYREF

  File._base = Buffer;
  File._ptr = Buffer;
  File._cnt = BufferCount;
  File._flag = 66;
  v4 = _output(&File, (int)Format, (int)ArgList);
  v5 = --File._cnt < 0;
  v6 = v4;
  if ( v5 )
    _flsbuf(0, &File);
  else
    *File._ptr = 0;
  return v6;
}
