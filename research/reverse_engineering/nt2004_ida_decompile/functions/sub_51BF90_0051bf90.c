float *__fastcall sub_51BF90(int a1, int a2, float a3, int a4)
{
  float *result; // eax
  int v5; // ecx

  if ( a4 >= 0 )
  {
    result = (float *)(248 * a4);
    *(float *)(248 * a4 + a1 + 17848) = a3;
  }
  else
  {
    result = (float *)(a1 + 17848);
    v5 = 4;
    do
    {
      *result = a3;
      result += 62;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
