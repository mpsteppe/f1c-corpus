int __cdecl fsetpos(FILE *Stream, const fpos_t *Position)
{
  return _fseeki64(Stream, *Position, 0);
}
