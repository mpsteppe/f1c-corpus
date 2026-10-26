void __thiscall sub_5351B0(int this, float a2)
{
  int v3; // eax
  double v4; // st7
  double v5; // st7
  double v6; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  float v10; // [esp+10h] [ebp+4h]

  sub_533740((_DWORD *)(this + 156), a2);
  v3 = *(_DWORD *)(this + 40);
  v10 = a2 * 100.0;
  if ( v3 <= 1 )
  {
    if ( v3 == 1 )
      v4 = *(float *)(this + 76);
    else
      v4 = v10;
  }
  else
  {
    v4 = (double)(v3 - 1) * *(float *)(this + 76);
  }
  v5 = v4 + v10;
  if ( v3 <= 0 )
    *(float *)(this + 76) = v10;
  v6 = v5 / (double)v3;
  *(float *)(this + 76) = v6;
  if ( v8 | v9 )
  {
    *(_DWORD *)(this + 76) = 1084227584;
  }
  else if ( v6 > 100.0 )
  {
    *(_DWORD *)(this + 76) = 1120403456;
  }
}
