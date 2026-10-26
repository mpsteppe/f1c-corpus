char *__cdecl _strnset(char *Destination, int Value, size_t Count)
{
  char *v3; // edi
  bool v4; // zf
  size_t v5; // ecx

  v3 = Destination;
  v4 = 1;
  v5 = Count;
  if ( Count )
  {
    do
    {
      if ( !v5 )
        break;
      v4 = *v3++ == 0;
      --v5;
    }
    while ( !v4 );
    if ( v4 )
      ++v5;
    memset(Destination, Value, Count - v5);
  }
  return Destination;
}
