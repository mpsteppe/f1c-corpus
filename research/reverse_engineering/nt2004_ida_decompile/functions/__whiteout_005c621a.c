int __cdecl _whiteout(_DWORD *a1, FILE *Stream)
{
  int v2; // edi

  do
  {
    ++*a1;
    v2 = fgetc_0(Stream);
  }
  while ( isspace(v2) );
  return v2;
}
