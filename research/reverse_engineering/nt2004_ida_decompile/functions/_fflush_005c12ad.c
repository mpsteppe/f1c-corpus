int __cdecl fflush(FILE *Stream)
{
  int v2; // edi

  if ( !Stream )
    return flsall(0);
  _lock_file(Stream);
  v2 = _fflush_lk(Stream);
  _unlock_file(Stream);
  return v2;
}
