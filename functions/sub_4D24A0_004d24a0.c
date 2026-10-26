char sub_4D24A0()
{
  int v0; // ecx
  char result; // al

  v0 = 0;
  result = 1;
  if ( dword_5C329C > 0 )
  {
    while ( *(_DWORD *)(dword_7C54F0[v0] + 16484) )
    {
      if ( ++v0 >= dword_5C329C )
        return result;
    }
    return 0;
  }
  return result;
}
