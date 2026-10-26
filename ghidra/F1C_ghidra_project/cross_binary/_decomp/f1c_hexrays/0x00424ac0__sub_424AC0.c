// f1c  0x00424ac0  size=95
double sub_424AC0()
{
  double v0; // st7

  v0 = flt_5EA3E0;
  if ( dword_7D01A0 > 100 )
    return v0 + (flt_5EA3E4 - v0) * ((double)(dword_7D01A0 - 100) * 0.050000001);
  else
    return (double)(dword_7D01A0 - 70) * 0.033333335 * (v0 - flt_5EA3DC) + flt_5EA3DC;
}
