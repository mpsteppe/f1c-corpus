int __cdecl _un_inc(int Character, FILE *Stream)
{
  int result; // eax

  if ( Character != -1 )
    return ungetc_0(Character, Stream);
  return result;
}
