float *__cdecl sub_53D446(int a1)
{
  float *result; // eax

  result = flt_5F2A98;
  if ( off_616DD4 <= flt_5F2A98 )
    return (float *)&unk_5F2A70;
  while ( a1 != *(_DWORD *)result )
  {
    result += 9;
    if ( result >= off_616DD4 )
      return (float *)&unk_5F2A70;
  }
  return result;
}
