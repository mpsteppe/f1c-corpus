double __stdcall sub_5730E0(float a1, float a2, float a3, float a4)
{
  double v4; // st7
  double v5; // st6

  if ( a1 <= (double)a2 )
    v4 = a2;
  else
    v4 = a1;
  if ( a3 <= (double)a4 )
    v5 = a4;
  else
    v5 = a3;
  if ( v4 <= v5 )
  {
    if ( a3 <= (double)a4 )
      return a4;
    else
      return a3;
  }
  else if ( a1 <= (double)a2 )
  {
    return a2;
  }
  else
  {
    return a1;
  }
}
