void __thiscall sub_426100(int this)
{
  int v2; // edi
  long double v3; // st5
  long double v4; // st7
  double v5; // st7
  double v6; // st7
  float v7; // [esp+8h] [ebp-18h]
  float v8; // [esp+Ch] [ebp-14h]
  float v9; // [esp+10h] [ebp-10h]
  float v10; // [esp+14h] [ebp-Ch]
  float v11; // [esp+1Ch] [ebp-4h]

  v2 = this + 4 * *(_DWORD *)(this + 17512) + 17236;
  v7 = *(float *)(this + 13536) - *(float *)(this + 17560);
  v8 = *(float *)(this + 13544) - *(float *)(this + 17568);
  while ( 1 )
  {
    v3 = sqrt(v8 * v8 + v7 * v7);
    *(float *)(this + 17572) = v3;
    v10 = *(float *)(*(_DWORD *)v2 + 32) * *(float *)(this + 17416)
        + *(float *)(*(_DWORD *)v2 + 148)
        + v3 * *(float *)(*(_DWORD *)v2 + 164)
        - *(float *)(this + 13536);
    v11 = *(float *)(*(_DWORD *)v2 + 40) * *(float *)(this + 17416)
        + *(float *)(*(_DWORD *)v2 + 156)
        + *(float *)(*(_DWORD *)v2 + 172) * *(float *)(this + 17572)
        - *(float *)(this + 13544);
    v4 = (v11 * *(float *)(this + 17556) + v10 * *(float *)(this + 17548)) / sqrt(v11 * v11 + v10 * v10);
    if ( v4 < 1.0 )
    {
      v9 = v4;
      v6 = v9;
      FloatFunctionPassThrough();
      if ( v11 * *(float *)(this + 17548) - v10 * *(float *)(this + 17556) > 0.0 )
        v6 = -v6;
      v5 = v6 / *(float *)(this + 17588);
      if ( *(_DWORD *)(this + 17680) == 6 )
        v5 = -v5;
    }
    else
    {
      v5 = 0.0;
    }
    if ( v5 - *(float *)(this + 17452) <= 0.1 )
    {
      if ( *(float *)(this + 17452) - v5 > 0.1 )
        v5 = *(float *)(this + 17452) - 0.1;
    }
    else
    {
      v5 = *(float *)(this + 17452) + 0.1;
    }
    *(float *)(this + 17452) = v5;
    if ( *(float *)(this + 17452) > 1.0 )
    {
      *(_DWORD *)(this + 17452) = 1065353216;
      return;
    }
    if ( *(float *)(this + 17452) < -1.0 )
    {
      *(_DWORD *)(this + 17452) = -1082130432;
      return;
    }
    if ( *(float *)(this + 17452) > 1.0 || *(float *)(this + 17452) < -1.0 )
      break;
    if ( *(float *)(this + 17452) <= 1.0 && *(float *)(this + 17452) >= -1.0 )
      return;
  }
  *(_DWORD *)(this + 17452) = 0;
}
