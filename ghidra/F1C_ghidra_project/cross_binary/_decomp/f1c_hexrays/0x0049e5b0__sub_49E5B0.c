// f1c  0x0049e5b0  size=179
unsigned int __stdcall sub_49E5B0(float a1)
{
  double v1; // st7

  v1 = a1;
  if ( a1 < 30.0 )
  {
    v1 = 30.0;
    return (sub_587BDC((v1 - 30.0) * 0.025 * 255.0) << 16) | 0xFF0000FF;
  }
  if ( v1 > 150.0 )
  {
    v1 = 150.0;
    return (sub_587BDC((v1 - 110.0) * 0.025 * 255.0) | 0xFFFFFF00) << 8;
  }
  if ( v1 < 70.0 )
    return (sub_587BDC((v1 - 30.0) * 0.025 * 255.0) << 16) | 0xFF0000FF;
  if ( v1 >= 110.0 )
    return (sub_587BDC((v1 - 110.0) * 0.025 * 255.0) | 0xFFFFFF00) << 8;
  return sub_587BDC((1.0 - (v1 - 70.0) * 0.025) * 255.0) | 0xFFFF0000;
}
