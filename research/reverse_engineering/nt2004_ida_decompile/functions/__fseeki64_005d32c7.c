int __cdecl _fseeki64(FILE *Stream, __int64 Offset, int Origin)
{
  int v3; // esi

  _lock_file(Stream);
  v3 = _fseeki64_lk((int)Stream, Offset, Origin);
  _unlock_file(Stream);
  return v3;
}
