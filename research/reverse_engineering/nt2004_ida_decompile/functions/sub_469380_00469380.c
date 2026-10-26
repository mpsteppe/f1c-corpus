char __thiscall sub_469380(float *this)
{
  size_t v1; // edi
  int v3; // eax
  double v4; // st7
  int v5; // ecx
  double v6; // st6

  v1 = NumOfElements;
  sub_42FA50(&dword_75CBA8, (int)NumOfElements <= 0);
  if ( !(unsigned __int8)sub_469460(this) )
  {
    v3 = *((_DWORD *)this + 147);
    if ( v3 <= 0 || v1 )
    {
      *((_DWORD *)this + 147) = v1;
      this[146] = 0.0;
      return v3;
    }
  }
  v4 = dbl_7DA9C0 + this[146];
  this[146] = v4;
  v5 = dword_75CBB0;
  if ( dword_75CBB0 == 7 )
    v6 = 120.0;
  else
    v6 = 60.0;
  LOBYTE(v3) = v6 < v4;
  if ( v1 )
  {
    if ( v6 >= v4 )
    {
LABEL_16:
      *((_DWORD *)this + 147) = v1;
      return v3;
    }
  }
  else
  {
    v5 = 7;
  }
  this[146] = 0.0;
  if ( v5 <= 0 )
    goto LABEL_16;
  if ( v5 <= 6 )
  {
    *((_DWORD *)this + 105) = 3;
    goto LABEL_16;
  }
  *((_DWORD *)this + 147) = v1;
  if ( v5 == 7 )
    *((_DWORD *)this + 105) = 2;
  return v3;
}
