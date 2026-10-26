int __thiscall sub_52D2E0(int this)
{
  int v1; // edx
  float *v2; // esi
  int result; // eax
  double v4; // st7
  double v5; // st7
  float v6; // [esp+0h] [ebp-4h]
  float v7; // [esp+0h] [ebp-4h]

  v1 = *(_DWORD *)(this + 52);
  if ( v1 )
  {
    v6 = dbl_7DA9D0;
    if ( dbl_7DA9D0 > *(float *)v1 && (v2 = *(float **)(v1 + 12)) != 0 )
    {
      if ( v6 < (double)*v2 )
      {
        v4 = *v2 - *(float *)v1;
        if ( v4 <= 0.0 )
          v5 = 0.0;
        else
          v5 = (v6 - *(float *)v1) / v4;
        v7 = (1.0 - v5) * *(float *)(v1 + 8) + v5 * v2[2];
        return sub_52CD70(v7);
      }
      else
      {
        return sub_52CD70(v2[2]);
      }
    }
    else
    {
      return sub_52CD70(*(float *)(v1 + 8));
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
