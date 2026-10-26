void __thiscall sub_56B6A0(float *this, float a2)
{
  bool v2; // c0
  bool v3; // c3

  v2 = a2 > -1.0;
  v3 = -1.0 == a2;
  if ( *(_DWORD *)(*(_DWORD *)this + 14820) == 1 )
  {
    if ( v2 || v3 )
    {
      if ( a2 > 1.0 )
      {
        a2 = 1.0;
LABEL_7:
        sub_42F560((_DWORD *)this + 639, a2, 0);
        this[746] = sub_42F5C0((_DWORD *)this + 639);
        return;
      }
      if ( a2 >= -1.0 )
        goto LABEL_7;
    }
    a2 = -1.0;
    goto LABEL_7;
  }
  if ( !v2 && !v3 )
    goto LABEL_12;
  if ( a2 > 1.0 )
  {
    this[746] = 1.0;
    return;
  }
  if ( a2 >= -1.0 )
    this[746] = a2;
  else
LABEL_12:
    this[746] = -1.0;
}
