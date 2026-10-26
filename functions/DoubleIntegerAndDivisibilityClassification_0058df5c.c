int __cdecl sub_58DF5C(double a1)
{
  if ( (FloatClassify(a1) & 0x90) != 0 )
    return 0;
  FrndMSVCCRTRounding(a1);
  FrndMSVCCRTRounding(a1 / 2.0);
  return 2;
}
