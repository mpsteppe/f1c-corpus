int __thiscall sub_58BAB0(int *this, int a2)
{
  int v2; // edx
  float *v3; // esi
  int result; // eax
  __int16 v5; // fps
  double v6; // st7
  bool v7; // c0
  char v8; // c2
  bool v9; // c3

  *this = 0;
  v2 = 0;
  v3 = (float *)(this + 3);
  do
  {
    if ( !*(_DWORD *)(a2 + 4 * v2) )
      break;
    result = *this + 1;
    *this = result;
    if ( v2 > 0 )
    {
      v6 = *(v3 - 5) - *(v3 - 2);
      v7 = v6 < 0.0;
      v8 = 0;
      v9 = v6 == 0.0;
      LOWORD(result) = v5;
      if ( v6 <= 0.0 )
        *v3 = 0.0;
      else
        *v3 = 1.0 / v6;
    }
    ++v2;
    v3 += 4;
  }
  while ( v2 < 5 );
  return result;
}
