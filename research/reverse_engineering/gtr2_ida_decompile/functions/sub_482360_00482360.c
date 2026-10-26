char __thiscall sub_482360(float *this)
{
  int v1; // edi
  int v3; // eax
  double v4; // st7
  int v5; // ecx
  double v6; // st6

  v1 = dword_757C10;
  sub_4304C0();
  if ( !sub_47FA40() )
  {
    v3 = *((_DWORD *)this + 262);
    if ( v3 <= 0 || v1 )
    {
      *((_DWORD *)this + 262) = v1;
      this[261] = 0.0;
      return v3;
    }
  }
  v4 = dbl_FB1D08 + this[261];
  this[261] = v4;
  v5 = *(_DWORD *)dword_B640C8;
  if ( *(_DWORD *)dword_B640C8 == 6 )
    v6 = 120.0;
  else
    v6 = 60.0;
  LOBYTE(v3) = v6 < v4;
  if ( v1 )
  {
    if ( v6 >= v4 )
    {
LABEL_16:
      *((_DWORD *)this + 262) = v1;
      return v3;
    }
  }
  else
  {
    v5 = 6;
  }
  this[261] = 0.0;
  if ( v5 <= 0 )
    goto LABEL_16;
  if ( v5 <= 5 )
  {
    *((_DWORD *)this + 217) = 4;
    goto LABEL_16;
  }
  *((_DWORD *)this + 262) = v1;
  if ( v5 == 6 )
    *((_DWORD *)this + 217) = 3;
  return v3;
}
