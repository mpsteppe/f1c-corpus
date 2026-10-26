char sub_551D70()
{
  int v0; // ecx
  char result; // al

  v0 = 0;
  result = 1;
  if ( dword_757C10 > 0 )
  {
    while ( *(_DWORD *)(*(&dword_91E088 + v0) + 19380) )
    {
      if ( ++v0 >= dword_757C10 )
        return result;
    }
    return 0;
  }
  return result;
}
