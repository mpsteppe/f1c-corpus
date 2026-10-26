int __cdecl ungetc(int Character, FILE *Stream)
{
  int v2; // esi

  _lock_file(Stream);
  v2 = ungetc_0(Character, Stream);
  _unlock_file(Stream);
  return v2;
}
