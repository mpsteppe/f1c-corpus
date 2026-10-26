int __thiscall sub_54AD90(_DWORD *this, int a2)
{
  int result; // eax
  double v4; // st7
  double v5; // st7

  sub_4091C0();
  result = *(_DWORD *)(this[1] + 12);
  if ( result )
  {
    v4 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
    *(double *)result = v4 * *(float *)(*(_DWORD *)(result + 60) + 20);
    v5 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.1;
    *(float *)(result + 24) = v5 + 1.0;
  }
  return result;
}
