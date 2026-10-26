int __cdecl sub_5158AF(_DWORD *a1, float *a2)
{
  int result; // eax
  float v3[64]; // [esp+0h] [ebp-100h] BYREF

  result = MatrixScaleByW(a2, v3);
  if ( result >= 0 )
  {
    result = QuantizationColorSpaceConversion(a1, v3);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

