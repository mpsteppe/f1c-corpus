void __thiscall sub_4EE910(_DWORD *this, int a2)
{
  float *v2; // ecx
  int v3; // edx
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7

  if ( flt_B70A44 != 0.0 && this[106] == 2139095039 )
  {
    sub_4EE080();
    switch ( v3 )
    {
      case 0:
        v4 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        v2[96] = v4 + dbl_FB1D18;
        break;
      case 1:
        v5 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        v2[98] = v5 + dbl_FB1D18;
        break;
      case 2:
        v6 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        v2[97] = v6 + dbl_FB1D18;
        break;
      case 3:
        v7 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        v2[99] = v7 + dbl_FB1D18;
        break;
      case 4:
        v8 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        v2[100] = v8 + dbl_FB1D18;
        break;
      case 5:
        v9 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        v2[101] = v9 + dbl_FB1D18;
        break;
      default:
        return;
    }
  }
}
