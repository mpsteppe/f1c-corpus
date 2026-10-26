int __thiscall sub_52D380(int this)
{
  int v1; // edx
  double v2; // st7
  double v3; // st7
  double v4; // st7
  int result; // eax
  float v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+0h] [ebp-8h]
  float v8; // [esp+4h] [ebp-4h]

  v1 = *(_DWORD *)(this + 52);
  if ( v1 )
  {
    if ( dword_75CBB0 == 7 )
      v2 = dbl_7DA9D0 + 5400.0;
    else
      v2 = dbl_7DA9D0 + 3000.0;
    v8 = v2;
    v3 = *(float *)(v1 + 8);
    v6 = *(float *)(v1 + 8);
    do
    {
      if ( v6 < (double)*(float *)(v1 + 8) )
        v6 = *(float *)(v1 + 8);
      if ( v3 > *(float *)(v1 + 8) )
        v3 = *(float *)(v1 + 8);
      if ( *(float *)v1 > (double)v8 )
        break;
      v1 = *(_DWORD *)(v1 + 12);
    }
    while ( v1 );
    v4 = (v3 + v6) * 0.5 + *(float *)(this + 188);
    v7 = v4;
    if ( v4 >= 0.0 )
    {
      if ( v7 > 1.0 )
        v7 = 1.0;
      return sub_52CD70(v7);
    }
    else
    {
      return sub_52CD70(0.0);
    }
  }
  else if ( *(float *)(this + 28) == 0.0 )
  {
    return 2;
  }
  else if ( *(float *)(this + 32) == 0.0 )
  {
    return 3;
  }
  else
  {
    result = 4;
    if ( *(float *)(this + 32) >= 0.60000002 )
      return 5;
  }
  return result;
}
