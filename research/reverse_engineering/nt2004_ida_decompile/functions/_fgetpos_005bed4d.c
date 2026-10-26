int __cdecl fgetpos(FILE *Stream, fpos_t *Position)
{
  int result; // eax

  *Position = _ftelli64(Stream);
  result = -1;
  if ( (*((_DWORD *)Position + 1) & *(_DWORD *)Position) != -1 )
    return 0;
  return result;
}
