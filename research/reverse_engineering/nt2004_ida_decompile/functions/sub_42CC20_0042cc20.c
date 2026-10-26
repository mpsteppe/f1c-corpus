int __thiscall sub_42CC20(void *this, char a2, float a3, int a4)
{
  int result; // eax
  double v5; // st7

  if ( a2 )
  {
    if ( a3 - 3.0 >= sub_42B090((int)this, 7u, a4) )
      return 7;
  }
  else
  {
    v5 = sub_42B090((int)this, 8u, a4);
    result = 8;
    if ( a3 + 3.0 <= v5 )
      return result;
  }
  return 18;
}
