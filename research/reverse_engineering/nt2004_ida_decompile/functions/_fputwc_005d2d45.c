wint_t __cdecl fputwc(wchar_t Character, FILE *Stream)
{
  wint_t v2; // si

  _lock_file(Stream);
  v2 = _putwc_lk(Character, Stream);
  _unlock_file(Stream);
  return v2;
}
