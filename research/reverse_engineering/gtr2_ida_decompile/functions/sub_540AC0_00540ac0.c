void __thiscall sub_540AC0(int this, float a2)
{
  if ( *(_BYTE *)(this + 16) && dword_BE1D10 && *(float *)(dword_BE1D10 + 4) >= 0.0 )
  {
    *(_DWORD *)(this + 20) = 2;
    if ( a2 <= 0.0 )
      *(float *)(this + 24) = flt_B709FC;
    else
      *(float *)(this + 24) = *(float *)(dword_BE1D10 + 4) / a2;
  }
}
