void __thiscall sub_4EEA90(int this, int a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // st7

  if ( flt_B70A44 != 0.0
    && *(_DWORD *)(this + 384) == 2139095039
    && *(_DWORD *)(this + 388) == 2139095039
    && *(_DWORD *)(this + 392) == 2139095039
    && *(_DWORD *)(this + 396) == 2139095039
    && *(_DWORD *)(this + 424) == 2139095039 )
  {
    switch ( a2 )
    {
      case '?':
        v2 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        *(float *)(this + 408) = v2 + dbl_FB1D18;
        break;
      case '@':
        v3 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        *(float *)(this + 416) = v3 + dbl_FB1D18;
        break;
      case 'A':
        v4 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        *(float *)(this + 412) = v4 + dbl_FB1D18;
        break;
      case 'B':
        v5 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
        *(float *)(this + 420) = v5 + dbl_FB1D18;
        break;
      default:
        return;
    }
  }
}
