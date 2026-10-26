char sub_4196A0()
{
  char result; // al
  int i; // esi

  result = byte_6292D8;
  if ( byte_6292D8 )
  {
    sub_4191D0((int)byte_6292D0);
    for ( i = 0; i <= 99; ++i )
    {
      sub_419530(i, i);
      result = sub_418DB0((int)byte_6292D0);
    }
  }
  return result;
}
