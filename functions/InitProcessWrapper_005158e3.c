int __cdecl sub_5158E3(float a1, float *a2)
{
  int result; // eax
  float v3[64]; // [esp+0h] [ebp-100h] BYREF

  result = MatrixScaleByW(a2, v3);
  if ( result >= 0 )
  {
    result = sub_515417(a1, (int)v3);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
