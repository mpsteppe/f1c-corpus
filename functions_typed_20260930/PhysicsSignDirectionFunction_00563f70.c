int __usercall sub_563F70@<eax>(double a1@<st0>)
{
  __int16 v1; // fps
  double v2; // st7
  bool v3; // c0
  char v4; // c2
  bool v5; // c3

  AudioMixerSampleGetWithFallback(0.0);
  AudioMixerSampleGetWithFallback(0.0);
  v2 = a1 - a1;
  if ( !*(_DWORD *)(dword_8D46B4 + 132) )
    v2 = -v2;
  v3 = v2 < 0.0;
  v4 = 0;
  v5 = v2 == 0.0;
  if ( (v1 & 0x4100) == 0 )
    return 1;
  if ( v2 >= 0.0 )
    return 0;
  return -1;
}

