int __cdecl ftell(FILE *Stream)
{
  int v1; // edi

  _lock_file(Stream);
  v1 = _ftell_lk(Stream);
  _unlock_file(Stream);
  return v1;
}
