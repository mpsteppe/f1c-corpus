int __thiscall sub_42B320(int this, float a2)
{
  int v4; // edi
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  float v8; // [esp+10h] [ebp+4h]

  if ( *(_DWORD *)(this + 16584) && !LOBYTE(a2) )
    return *(_DWORD *)(this + 24020);
  v4 = 8;
  v8 = fabs(*(float *)(this + 23728) - sub_529A00(1));
  v5 = fabs(*(float *)(this + 23728) - sub_529A00(0));
  if ( v5 < v8 )
  {
    v8 = v5;
    v4 = 7;
  }
  v6 = fabs(*(float *)(this + 23728) - sub_529A00(2));
  if ( v6 < v8 )
  {
    v8 = v6;
    v4 = 11;
  }
  v7 = fabs(*(float *)(this + 23728) - (sub_529A00(1) + 3.5));
  if ( v7 < v8 )
  {
    v8 = v7;
    v4 = 9;
  }
  if ( fabs(*(float *)(this + 23728) - (sub_529A00(0) - 3.5)) < v8 )
    return 6;
  return v4;
}
