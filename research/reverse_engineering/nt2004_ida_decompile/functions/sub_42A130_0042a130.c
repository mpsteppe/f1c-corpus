void __thiscall sub_42A130(int this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st6
  double v4; // st6
  double v5; // st7
  float v6; // [esp+0h] [ebp-4h]

  v1 = *(float *)(this + 24712);
  *(_DWORD *)(this + 23864) = 1065353216;
  if ( v1 > 0.0 )
    goto LABEL_10;
  v2 = *(float *)(this + 23684);
  v3 = -*(float *)(this + 23688);
  v6 = (v2 - *(float *)(this + 23688)) * 0.5;
  *(float *)(this + 23860) = v6;
  v4 = v3 + *(float *)(this + 23716);
  if ( v4 < v6 )
  {
    if ( v4 < 0.0 )
      v4 = 0.0;
    *(float *)(this + 23864) = v4 / v6;
  }
  v5 = v2 - *(float *)(this + 23716);
  if ( v5 >= v6 )
  {
LABEL_10:
    *(_DWORD *)(this + 23860) = 1065353216;
  }
  else
  {
    if ( v5 < 0.0 )
      v5 = 0.0;
    *(float *)(this + 23860) = v5 / v6;
  }
}
