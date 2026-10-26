void __thiscall sub_535110(int this, int a2)
{
  int v3; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st7
  double v7; // st7
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c2
  float v11; // [esp+10h] [ebp+4h]

  sub_533680((_DWORD *)(this + 156), a2);
  v3 = *(_DWORD *)(this + 40);
  if ( v3 <= 1 )
  {
    if ( v3 == 1 )
      v4 = *(float *)(this + 72);
    else
      v4 = *(float *)&a2;
  }
  else
  {
    v4 = (double)(v3 - 1) * *(float *)(this + 72);
  }
  v5 = (double)a2;
  v6 = v4 + v5;
  if ( v3 <= 0 )
  {
    v11 = v5;
    *(float *)(this + 72) = v11;
  }
  v7 = v6 / (double)v3;
  *(float *)(this + 72) = v7;
  if ( v9 | v10 )
  {
    *(_DWORD *)(this + 72) = 1065353216;
  }
  else if ( v7 > 22.0 )
  {
    *(_DWORD *)(this + 72) = 1102053376;
  }
}
