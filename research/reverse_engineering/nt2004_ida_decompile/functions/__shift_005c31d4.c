void __cdecl _shift(const char *Src, int a2)
{
  size_t v2; // eax

  if ( a2 )
  {
    v2 = strlen(Src);
    memcpy((void *)&Src[a2], Src, v2 + 1);
  }
}
