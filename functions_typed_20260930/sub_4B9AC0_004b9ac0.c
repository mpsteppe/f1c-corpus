int __thiscall sub_4B9AC0(float **this, int a2, int a3, float a4)
{
  char **v4; // edx
  float *v5; // eax
  float *v6; // edi

  v4 = (char **)this;
  if ( a4 == -9.9999997e37 )
    a4 = FloatGetter(*this);
  v5 = LinkedListTraversalWithFilter(*v4, a2, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  if ( (unsigned __int8)FieldCompareConstant(v5 + 36) && !(unsigned __int8)FloatComparisonCheck(v6 + 36) )
    return PassthroughWrapper_00c0(a4, (int)(v6 + 146), a3);
  if ( (unsigned __int8)FieldCompareConstant(v6 + 36) || !(unsigned __int8)FloatComparisonCheck(v6 + 36) )
    return AudioSamplePlaybackWithPitchModulationAndStereoP(a4, a3);
  return PassthroughWrapper_00c0(a4, (int)(v6 + 38), a3);
}

