void __thiscall sub_448F00(_DWORD *this, int a2)
{
  int i; // esi
  float *v3; // eax
  int v4; // edx
  float *v5; // ebx
  int v6; // edx
  float *v7; // edi
  double *v8; // edx
  double v9; // st7
  double v10; // st7

  for ( i = 0; i < 3; ++i )
  {
    v3 = (float *)this[2 * i];
    if ( i == 2 )
      v4 = 0;
    else
      v4 = i + 1;
    v5 = (float *)this[2 * v4];
    v6 = 2;
    if ( i )
      v6 = i - 1;
    v7 = (float *)this[2 * v6];
    v8 = (double *)(a2 + 24 * i);
    *v8 = v3[3] - v5[3];
    v9 = *v5 - *v3;
    v8[1] = v9;
    v10 = v9 * v3[3] + *v3 * *v8;
    v8[2] = v10;
    if ( v7[3] * v8[1] + *v7 * *v8 < v10 )
    {
      *v8 = -*v8;
      v8[1] = -v8[1];
      v8[2] = -v8[2];
    }
    v8[2] = sqrt(*v8 * *v8 + v8[1] * v8[1]) * 0.001 + v8[2];
  }
}
