int __cdecl sub_552876(float a1, float *a2)
{
  int result; // eax
  float v3[64]; // [esp+0h] [ebp-100h] BYREF

  result = sub_550DC0(a2, v3);
  if ( result >= 0 )
  {
    result = sub_5523AA(a1, (int)v3);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
