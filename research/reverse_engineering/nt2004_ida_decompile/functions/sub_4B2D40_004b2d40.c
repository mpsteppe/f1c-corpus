int sub_4B2D40()
{
  double v0; // st7
  int result; // eax
  float v2; // [esp+0h] [ebp-4h]

  v0 = *(float *)(dword_75AAC4 + 18820) / *(float *)(dword_75AAC4 + 18824);
  v2 = v0;
  if ( v0 < 0.89999998 )
    return -1;
  if ( v2 < 0.93000001 )
    return 0;
  if ( v2 < 0.95999998 )
    return 1;
  result = 2;
  if ( v2 >= 0.977 )
    return 3;
  return result;
}
