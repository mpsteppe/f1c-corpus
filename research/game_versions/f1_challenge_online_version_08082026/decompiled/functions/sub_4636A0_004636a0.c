BOOL __thiscall sub_4636A0(void *this)
{
  double v2; // st7
  bool v3; // c0
  bool v4; // c3
  double v5; // st7

  if ( sub_461DC0(this) )
  {
    v2 = *(float *)(*(_DWORD *)this + 904);
    v3 = v2 < 20.0;
    v4 = v2 == 20.0;
  }
  else
  {
    v5 = *(float *)(*(_DWORD *)this + 904);
    v3 = v5 < 1.25;
    v4 = v5 == 1.25;
  }
  return !v3 && !v4;
}
