char __thiscall sub_4556B0(float *this)
{
  int v2; // eax
  long double v3; // st7

  LOBYTE(v2) = sub_405BF0(&dword_629124);
  if ( (_BYTE)v2 && dword_75CBA8 == 5 )
  {
    this[9] = 0.0;
    this[10] = 0.0;
    return v2;
  }
  if ( !*(_DWORD *)this )
  {
    v2 = (dword_761FF8 & 1) != 0 && (byte_7620FC[*((_DWORD *)this + 1)] & 2) != 0;
    goto LABEL_11;
  }
  if ( *(_DWORD *)this == 1 )
  {
    v2 = *(_DWORD *)(*((_DWORD *)this + 7) + 16);
LABEL_11:
    *((_DWORD *)this + 9) = v2;
    if ( v2 )
      this[10] = 1.0;
    else
      this[10] = 0.0;
    return v2;
  }
  v2 = *(_DWORD *)this - 2;
  if ( *(_DWORD *)this == 2 )
  {
    v3 = fabs(*(float *)(*((_DWORD *)this + 8) + 4));
    this[10] = v3;
    if ( v3 <= 0.5 )
    {
      LOBYTE(v2) = 0;
      this[9] = 0.0;
    }
    else
    {
      LOBYTE(v2) = 1;
      *((_DWORD *)this + 9) = 1;
    }
  }
  return v2;
}
