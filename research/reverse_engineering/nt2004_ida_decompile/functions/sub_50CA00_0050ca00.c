void __thiscall sub_50CA00(int this, float a2)
{
  double v3; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  double v6; // st7
  double v7; // st7
  int v8; // [esp-8h] [ebp-8h]
  float v9; // [esp+4h] [ebp+4h]

  v3 = *(float *)(this + 2896);
  if ( v4 | v5 )
  {
    v7 = v3 - 0.30000001;
    if ( v7 >= 0.0 )
      v9 = v7;
    else
      v9 = 0.0;
  }
  else
  {
    v6 = v3 + 0.30000001;
    if ( v6 <= 0.89999998 )
      v9 = v6;
    else
      v9 = 0.89999998;
  }
  if ( v9 != *(float *)(this + 2896) )
  {
    v8 = *(_DWORD *)(this + 2868);
    *(float *)(this + 2896) = v9;
    sub_50B4E0((_DWORD *)this, v8, 1);
  }
}
