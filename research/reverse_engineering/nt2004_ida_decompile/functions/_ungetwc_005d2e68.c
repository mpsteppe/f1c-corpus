wint_t __cdecl ungetwc(wint_t Character, FILE *Stream)
{
  wint_t v2; // si

  _lock_file(Stream);
  v2 = _ungetwc_lk(Character, (int)Stream);
  _unlock_file(Stream);
  return v2;
}
