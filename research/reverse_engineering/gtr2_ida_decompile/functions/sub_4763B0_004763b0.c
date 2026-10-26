unsigned __int64 __thiscall sub_4763B0(_WORD *this, float a2)
{
  double v2; // st7
  unsigned __int64 result; // rax

  v2 = a2;
  if ( a2 >= -5.0 )
  {
    if ( v2 > 5.0 )
      v2 = 5.0;
  }
  else
  {
    v2 = -5.0;
  }
  result = (unsigned __int64)(v2 * 3999.9998 + 0.5);
  *this = result;
  return result;
}
