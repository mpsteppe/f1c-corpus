wint_t __cdecl fgetwc(FILE *Stream)
{
  wint_t v1; // di

  _lock_file(Stream);
  v1 = _getwc_lk(Stream);
  _unlock_file(Stream);
  return v1;
}
