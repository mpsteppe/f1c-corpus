// f1c  0x00598569  size=151
char *__cdecl sub_598569(char *a1, int a2)
{
  char *i; // esi
  unsigned __int16 v4; // bx
  unsigned __int8 v5; // al

  if ( !dword_8D46CC )
    return sub_589DB0(a1, a2);
  sub_58DFEA(25);
  for ( i = a1; ; ++i )
  {
    v4 = (unsigned __int8)*i;
    if ( !*i )
      break;
    if ( (byte_8D47E1[(unsigned __int8)v4] & 4) != 0 )
    {
      v5 = *++i;
      if ( !v5 )
      {
        sub_58E04B(25);
        return 0;
      }
      if ( a2 == (v5 | (v4 << 8)) )
      {
        sub_58E04B(25);
        return i - 1;
      }
    }
    else if ( a2 == (unsigned __int8)*i )
    {
      break;
    }
  }
  sub_58E04B(25);
  return v4 == a2 ? i : 0;
}
