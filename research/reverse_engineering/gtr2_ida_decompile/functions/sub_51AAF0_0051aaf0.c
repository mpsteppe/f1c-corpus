int __cdecl sub_51AAF0(float *a1)
{
  int v2; // eax
  float v3; // [esp+8h] [ebp-10h]
  float v4; // [esp+8h] [ebp-10h]

  if ( *a1 <= 63.96875 && *a1 >= -63.96875 )
  {
    v3 = *a1 * 32.0;
    sub_4015C0(v3);
  }
  if ( a1[2] > 63.96875 )
    return off_16C9284(2047);
  if ( a1[2] < -63.96875 )
    return off_16C9284(-2047);
  v4 = a1[2] * 32.0;
  v2 = sub_4015C0(v4);
  return off_16C9284(v2);
}
