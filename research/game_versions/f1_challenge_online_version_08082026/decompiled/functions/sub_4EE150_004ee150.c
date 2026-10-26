int __thiscall sub_4EE150(float *this, int a2)
{
  float *v2; // esi
  _DWORD *v3; // ecx
  int result; // eax
  int v5; // edi
  double v6; // st7
  double v7; // [esp+10h] [ebp-10h]
  double v8; // [esp+18h] [ebp-8h]

  v2 = this + 3929;
  v3 = this + 3929;
  *v3 = 2139095039;
  v3[1] = 2139095039;
  v3[2] = 2139095039;
  v3[3] = 2139095039;
  result = dword_7CEA5C;
  if ( dword_7CEA5C > 0 && dword_7CEA5C <= 2 )
  {
    sub_53AC70(2, 0);
    v5 = 4;
    do
    {
      v8 = *(double *)(a2 + 4912) * 3.0;
      v7 = *(double *)(a2 + 4920) * 3.0;
      v6 = sub_4B3CE0(&dword_8AAE70) * v7 + v8;
      if ( dword_7C56A4 == 7 && dword_7CEA5C == 2 )
        v6 = v6 / flt_8ACF9C;
      if ( v6 <= 3.402823466385289e38 )
        *v2 = v6;
      else
        *v2 = 3.4028235e38;
      ++v2;
      --v5;
    }
    while ( v5 );
    return sub_53AC70(1, 0);
  }
  return result;
}
