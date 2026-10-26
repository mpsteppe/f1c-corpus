int __thiscall sub_44A070(double *this, int a2)
{
  int v3; // edx
  float *v4; // esi
  double v5; // st5
  long double v6; // st6
  int result; // eax
  long double v8; // st6
  float v9; // [esp+8h] [ebp-4h]
  float v10; // [esp+10h] [ebp+4h]

  v3 = 0;
  v10 = *(double *)a2;
  v4 = (float *)this + 13;
  do
  {
    v9 = *(double *)(a2 + 16);
    if ( v10 * *(v4 - 1) + v9 * *v4 < v4[1] )
      return 0;
    ++v3;
    v4 += 3;
  }
  while ( v3 < 3 );
  v5 = (*(double *)(a2 + 16) * this[2] + *(double *)a2 * *this + this[3]) * *(double *)a2
     + (*(double *)(a2 + 16) * this[1] + this[4]) * *(double *)(a2 + 16)
     + this[5];
  v6 = v5 - *(double *)(a2 + 8);
  if ( v6 > *(double *)(a2 + 24) )
    return 0;
  v8 = fabs(v6);
  if ( v8 >= *(double *)(a2 + 32) )
    return 0;
  *(long double *)(a2 + 32) = v8;
  *(_DWORD *)(a2 + 48) = this;
  result = 1;
  *(double *)(a2 + 40) = v5;
  return result;
}
