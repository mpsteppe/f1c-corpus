int __fastcall sub_566EE0(float *a1, int a2)
{
  __int16 v2; // fps
  int result; // eax
  long double v4; // st7

  *(float *)a2 = atan2(-a1[5], sqrt(a1[3] * a1[3] + a1[4] * a1[4]));
  result = v2 & 0x4100;
  if ( (v2 & 0x4100) != 0 )
  {
    v4 = atan2(-a1[6], *a1);
    *(_DWORD *)(a2 + 8) = 0;
    *(float *)(a2 + 4) = v4;
  }
  else
  {
    *(float *)(a2 + 4) = atan2(a1[2], a1[8]);
    *(float *)(a2 + 8) = atan2(a1[3], a1[4]);
  }
  return result;
}

