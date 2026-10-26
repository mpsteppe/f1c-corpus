unsigned int __stdcall sub_4B5B70(float a1)
{
  double v1; // st7

  v1 = a1;
  if ( a1 < 30.0 )
  {
    v1 = 30.0;
    return ((unsigned int)(__int64)((v1 - 30.0) * 0.025 * 255.0) << 16) | 0xFF0000FF;
  }
  if ( v1 > 150.0 )
  {
    v1 = 150.0;
    return ((unsigned int)(__int64)((v1 - 110.0) * 0.025 * 255.0) | 0xFFFFFF00) << 8;
  }
  if ( v1 < 70.0 )
    return ((unsigned int)(__int64)((v1 - 30.0) * 0.025 * 255.0) << 16) | 0xFF0000FF;
  if ( v1 >= 110.0 )
    return ((unsigned int)(__int64)((v1 - 110.0) * 0.025 * 255.0) | 0xFFFFFF00) << 8;
  return (__int64)((1.0 - (v1 - 70.0) * 0.025) * 255.0) | 0xFFFF0000;
}
