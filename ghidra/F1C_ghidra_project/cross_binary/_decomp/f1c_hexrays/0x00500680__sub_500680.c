// f1c  0x00500680  size=36
float *__cdecl sub_500680(int a1)
{
  float *result; // eax

  result = flt_5AD508;
  if ( off_5D7150 <= flt_5AD508 )
    return (float *)&unk_5AD4E0;
  while ( a1 != *(_DWORD *)result )
  {
    result += 9;
    if ( result >= off_5D7150 )
      return (float *)&unk_5AD4E0;
  }
  return result;
}
