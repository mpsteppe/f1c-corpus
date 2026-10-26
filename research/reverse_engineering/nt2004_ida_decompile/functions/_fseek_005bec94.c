int __cdecl fseek(FILE *Stream, int Offset, int Origin)
{
  int v3; // esi

  _lock_file(Stream);
  v3 = _fseek_lk((int)Stream, Offset, Origin);
  _unlock_file(Stream);
  return v3;
}
