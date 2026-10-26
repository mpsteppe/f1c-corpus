double __thiscall sub_4DD0F0(_DWORD *this)
{
  double result; // st7

  result = sub_51C7A0(*this + 84) / flt_6290D0;
  if ( result >= 0.98000002 )
    return 0.0;
  return result;
}
