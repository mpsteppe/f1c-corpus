int __cdecl sub_591400(int a1, int a2, int a3, int a4)
{
  float *v5; // ecx
  int v6; // ebx
  int result; // eax
  int v8; // esi
  double v9; // st7

  v5 = (float *)(a2 + 8);
  v6 = 4;
  do
  {
    result = a3 + 32;
    v8 = 4;
    do
    {
      v9 = *(float *)(result + 16);
      result += 4;
      a4 += 4;
      --v8;
      *(float *)(a4 - 4) = v9 * v5[1]
                         + *(float *)(result - 36) * *(v5 - 2)
                         + *(float *)(result - 20) * *(v5 - 1)
                         + *(float *)(result - 4) * *v5;
    }
    while ( v8 );
    v5 += 4;
    --v6;
  }
  while ( v6 );
  return result;
}
