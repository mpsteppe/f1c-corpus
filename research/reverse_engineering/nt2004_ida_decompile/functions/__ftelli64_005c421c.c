__int64 __cdecl _ftelli64(FILE *Stream)
{
  __int64 v1; // kr00_8

  _lock_file(Stream);
  v1 = _ftelli64_lk(Stream);
  _unlock_file(Stream);
  return v1;
}
