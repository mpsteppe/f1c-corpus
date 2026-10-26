void __thiscall sub_58C900(float *this, float a2)
{
  int v3; // edi
  double v4; // st7
  int v5; // ecx
  double v6; // st7
  double v7; // st7
  double v8; // st7

  v3 = *(_DWORD *)this + 16;
  if ( *(float *)(*(_DWORD *)this + 16148) <= (double)flt_903E98
    || *(float *)(*(_DWORD *)this + 16148) >= (double)flt_903E9C
    || *(float *)(*(_DWORD *)this + 17228) <= (double)flt_903EA8
    || *(float *)(*(_DWORD *)this + 17228) >= (double)flt_903EAC )
  {
    if ( this[49] > 0.0 )
      this[49] = 0.0;
  }
  else
  {
    this[49] = a2 + this[49];
  }
  if ( this[47] != 0.0 && this[49] > 0.30000001 )
  {
    this[49] = -0.5;
    v4 = flt_BE08A4[(unsigned __int8)dword_BE08A0];
    v5 = ++dword_BE08A0;
    if ( v4 < flt_903EB4 * this[47] )
    {
      v6 = flt_BE0CA4[(unsigned __int8)v5];
      dword_BE08A0 = v5 + 1;
      flt_FB1CDC = v6 * 0.1 + 1.0;
      v7 = flt_BE0CA4[(unsigned __int8)(v5 + 1)];
      dword_BE08A0 = v5 + 2;
      this[50] = v7 * 0.2 + 0.5;
    }
  }
  if ( *(float *)(v3 + 16132) > 0.5 )
    this[50] = 0.0;
  if ( this[50] <= 0.0 )
  {
    *((_BYTE *)this + 1368) = 0;
    *((_BYTE *)this + 286) = 1;
  }
  else
  {
    sub_58C630(this, 33);
    this[50] = this[50] - a2;
  }
  if ( this[48] != 0.0 && this[49] > 0.0 )
  {
    v8 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
    if ( v8 < flt_903EB0 * a2 * this[48] )
      sub_577380(v3);
  }
}
