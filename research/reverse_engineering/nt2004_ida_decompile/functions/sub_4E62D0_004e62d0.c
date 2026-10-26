void __thiscall sub_4E62D0(int this, float a2)
{
  int v2; // eax
  double v3; // st7
  double v4; // st7
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  float v9; // [esp+Ch] [ebp+4h]

  v2 = *(_DWORD *)(this + 40);
  v9 = a2 * 100.0;
  if ( v2 <= 1 )
  {
    if ( v2 == 1 )
      v3 = *(float *)(this + 76);
    else
      v3 = v9;
  }
  else
  {
    v3 = (double)(v2 - 1) * *(float *)(this + 76);
  }
  v4 = v3 + v9;
  if ( v2 <= 0 )
    *(float *)(this + 76) = v9;
  v5 = v4 / (double)v2;
  *(float *)(this + 76) = v5;
  if ( v7 | v8 )
  {
    *(_DWORD *)(this + 76) = 1077936128;
  }
  else if ( v5 > 100.0 )
  {
    *(_DWORD *)(this + 76) = 1120403456;
  }
}
